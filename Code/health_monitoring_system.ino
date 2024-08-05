#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MAX30105.h>
#include "spo2_algorithm.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


// Initialize the MLX90614 sensor
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

// Create an instance of the MAX30105 sensor
MAX30105 particleSensor;
// Buffer length for IR and Red readings
const int SENSOR_BUFFER_SIZE = 100;
uint32_t irBuffer[SENSOR_BUFFER_SIZE]; // Infrared LED sensor data
uint32_t redBuffer[SENSOR_BUFFER_SIZE]; // Red LED sensor data

void setup() {
  // Start serial communication
  Serial.begin(115200);

  // Initialize I2C communication
  Wire.begin(D2, D1);

  // Initialize the MLX90614 sensor
  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX90614 sensor. Check wiring.");
    while (1);
  }

  // Initialize the OLED display with address 0x3C for 128x64
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  
  // Clear the buffer
  display.clearDisplay();
  display.display();
  
  // Set text size and color
  display.setTextSize(1); // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text

  // Initialize the MAX30105 sensor
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) {
    Serial.println(F("MAX30105 was not found. Please check wiring/power."));
    while (1);
  }

  // Setup to sense a nice looking saw tooth on the plotter
  byte ledBrightness = 60; // Options: 0=Off to 255=50mA
  byte sampleAverage = 4; // Options: 1, 2, 4, 8, 16, 32
  byte ledMode = 2; // Options: 1 = Red only, 2 = Red + IR, 3 = Red + IR + Green
  int sampleRate = 400; // Options: 50, 100, 200, 400, 800, 1000, 1600, 3200
  int pulseWidth = 411; // Options: 69, 118, 215, 411
  int adcRange = 4096; // Options: 2048, 4096, 8192, 16384

  particleSensor.setup(ledBrightness, sampleAverage, ledMode, sampleRate, pulseWidth, adcRange);
}

void loop() {
  // Read object temperature (body temperature) in Celsius
  double bodyTempC = mlx.readObjectTempC();

  // Variables to store the sensor readings
  float heartRate = 0;
  float SpO2 = 0;
  int8_t validHeartRate = 0;
  int8_t validSpO2 = 0;
  


  // Convert body temperature to Fahrenheit
  double bodyTempF = (bodyTempC * 9.0 / 5.0) + 32.0;

   // Read data from the sensor into the buffer
  for (int i = 0; i < SENSOR_BUFFER_SIZE; i++) {
    while (!particleSensor.available()) {
      particleSensor.check(); // Check for new data
    }

    redBuffer[i] = particleSensor.getRed();
    irBuffer[i] = particleSensor.getIR();
    particleSensor.nextSample(); // Move to the next sample
  }

  // Calculate heart rate and SpO2
  calculateHeartRateAndOxygenSaturation(irBuffer, redBuffer, SENSOR_BUFFER_SIZE, &SpO2, &validSpO2, &heartRate, &validHeartRate);

  // Clear the display buffer
  display.clearDisplay();

  // Set the cursor position for the first line (Celsius)
  display.setCursor(0,0);
  display.print("Celsius: ");
  display.print(bodyTempC);
  display.println(" C");

  // Set the cursor position for the second line (Fahrenheit)
  display.print("Fahrenheit: ");
  display.print(bodyTempF);
  display.println(" F");

  // Display heart rate
  display.print(F("Heart Rate: "));
  if (validHeartRate == 1) {
    display.print(heartRate);
    display.println(F("bpm"));
  } 
  else {
    display.println(F("Invalid"));
  }

  // Display SpO2
  display.print(F("SpO2: "));
  if (validSpO2 == 1) {
    display.print(SpO2);
    display.println(F(" %"));
  } 
  else {
    display.println(F("Invalid"));
  }

  // Display the updated content
  display.display();

  // Wait for 1 second before taking another reading
  delay(1000);
}

void calculateHeartRateAndOxygenSaturation(uint32_t *irBuffer, uint32_t *redBuffer, int bufferLength, float *SpO2, int8_t *validSpO2, float *heartRate, int8_t *validHeartRate) {
  // This function calculates heart rate and SpO2 from the given IR and Red values
  // You can use the spo2_algorithm.h functions provided by SparkFun

  // Variables to store calculated HR and SpO2
  int32_t spo2;
  int8_t spo2_valid;
  int32_t heart_rate;
  int8_t hr_valid;

  // Call the SpO2 algorithm function
  maxim_heart_rate_and_oxygen_saturation(irBuffer, bufferLength, redBuffer, &spo2, &spo2_valid, &heart_rate, &hr_valid);

  // Update the provided pointers with the calculated values
  *SpO2 = (float)spo2;
  *validSpO2 = spo2_valid;
  *heartRate = (float)heart_rate;
  *validHeartRate = hr_valid;
}
