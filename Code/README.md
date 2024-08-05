<h2>Working Principles of the Components:</h2>
<P>
   <b>1.NodeMCU ESP8266: </b> Acts as the central processing unit, coordinating data collection, processing, and display. It communicates with the sensors and the OLED display <br>via I2C protocol.<br>
  <b>2.GY-MAX30102 Sensor:</b> This sensor measures heart rate and oxygen saturation (SpO2). It uses LEDs to emit red and infrared light through a fingertip and a<br> photodetector to measure the amount of light absorbed by the blood. The absorption varies with the pulsing of blood and the level of oxygenation, which allows the<br> sensor to calculate heart rate and SpO2.<br>
  <b>3.MLX90614 Sensor:</b> This non-contact infrared sensor measures body temperature by detecting the infrared radiation emitted by the skin. It converts the<br> infrared energy into an electrical signal and uses a built-in processor to calculate the temperature, which is then sent to the NodeMCU ESP8266.<br>
  <b1><4.128x64 OLED Display:/b1> The processed data from the sensors is sent to the OLED display. The display provides a clear, real-time visualization of body<br> temperature, heart rate, and SpO2 levels.<br>
  <b>5.Power Supply:</b> The device is powered through the NodeMCU ESP8266's USB port or an external battery, making it portable and convenient to use.<br>
    <b>6.Data Processing and Display:</b> The NodeMCU ESP8266 collects raw data from the GY-MAX30102 and MLX90614 sensors. It processes this data to calculate<br> accurate readings of heart rate, SpO2, and body temperature. The processed data is then sent to the OLED display for real-time viewing by the user.<br>
</P>
<hr>
<h2>The Circuit Diagram:</h2>
<img src="Circuit Diagram.png" alt="The Circuit Diagram-image">
