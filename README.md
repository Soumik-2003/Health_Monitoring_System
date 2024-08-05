<h1>Health_Monitoring_System</h1>
<p>
  Health monitoring system to measure heart rate, SpO2 and temperature<br>
  of human body using esp8266.<br>
  It is a simple NodeMCU ESP8266 based device with two sensors.<br>
  The device can measure some vital parameters of the human body.<br>
  The device will be like a Pulse Oximeter, a lot simpler and<br>
  made of cheap sensors not meant for actual medical use.<br>
</p>
<hr>
<h2>Components Required:</h2>
<p>
  <a href= "https://www.google.com/search?q=nodemcu+esp8266+&sca_esv=4411dbe1c3f361d6&rlz=1C1CHBF_enIN1119IN1119&sxsrf=ADLYWILk52kLCdIxdYdY0valtUhzS4yf6Q%3A1722861118996&ei=PsawZpXIPI_z4-EPqePRwQ0&ved=0ahUKEwiV3_rn7d2HAxWP-TgGHalxNNgQ4dUDCBA&uact=5&oq=nodemcu+esp8266+&gs_lp=Egxnd3Mtd2l6LXNlcnAiEG5vZGVtY3UgZXNwODI2NiAyChAjGIAEGCcYigUyChAjGIAEGCcYigUyChAAGIAEGEMYigUyBRAAGIAEMgoQABiABBhDGIoFMgUQABiABDIFEAAYgAQyBRAAGIAEMgUQABiABDIFEAAYgARImAxQ2QNY_ARwAXgBkAEAmAF7oAHqAaoBAzAuMrgBA8gBAPgBAZgCA6AC-gHCAgoQABiwAxjWBBhHwgINEAAYgAQYsAMYQxiKBcICFhAuGIAEGLADGEMY5QQYyAMYigXYAQHCAhkQLhiABBiwAxjRAxhDGMcBGMgDGIoF2AEBwgIKEAAYgAQYFBiHApgDAIgGAZAGC7oGBAgBGAiSBwMxLjKgB_cN&sclient=gws-wiz-serp">NodedeMCU ESP8266</a><br>
  <a href="https://www.google.com/search?q=gy-max30102+&sca_esv=4411dbe1c3f361d6&rlz=1C1CHBF_enIN1119IN1119&sxsrf=ADLYWIIr6HzbsWTbEZMEYVROONYNgMmi4g%3A1722861785367&ei=2ciwZpCSFuKF4-EPgbaxmQM&ved=0ahUKEwjQ4tql8N2HAxXiwjgGHQFbLDMQ4dUDCBA&uact=5&oq=gy-max30102+&gs_lp=Egxnd3Mtd2l6LXNlcnAiDGd5LW1heDMwMTAyIDIEECMYJzIFEAAYgAQyBRAAGIAEMgQQABgeMgQQABgeMgQQABgeMgsQABiABBiGAxiKBTILEAAYgAQYhgMYigUyCxAAGIAEGIYDGIoFMgsQABiABBiGAxiKBUihCFCVBFiVBHABeAGQAQCYAb8CoAG_AqoBAzMtMbgBA8gBAPgBAZgCAqACygLCAgoQABiwAxjWBBhHmAMAiAYBkAYIkgcFMS4zLTGgB7cG&sclient=gws-wiz-serp">Gy-MAX30102</a><br>
  <a href="https://www.google.com/search?q=mlx90614&sca_esv=4411dbe1c3f361d6&rlz=1C1CHBF_enIN1119IN1119&sxsrf=ADLYWILcd2UqcqjdTNtSabvimhn__bVfnQ%3A1722861787731&ei=28iwZuCiLMSO4-EPuaSGoQ0&oq=MLX&gs_lp=Egxnd3Mtd2l6LXNlcnAiA01MWCoCCAAyChAjGIAEGCcYigUyChAjGIAEGCcYigUyChAjGIAEGCcYigUyChAAGIAEGEMYigUyChAAGIAEGEMYigUyCBAAGIAEGLEDMgoQABiABBhDGIoFMgUQABiABDIFEAAYgAQyCBAuGIAEGOUESL8gUABYpg1wAXgBkAEAmAGCAqABogWqAQUwLjEuMrgBAcgBAPgBAZgCBKACuQWoAhLCAgcQIxgnGOoCwgINEC4Y0QMYxwEYJxjqAsICFBAAGIAEGOMEGLQCGOkEGOoC2AEBwgIEECMYJ8ICFBAuGIAEGLEDGIMBGMcBGIoFGK8BwgILEAAYgAQYsQMYgwHCAggQLhiABBixA5gDCroGBggBEAEYAZIHBTEuMS4yoAejIA&sclient=gws-wiz-serp">MLX90614</a><br>
  <a href="https://www.google.com/search?q=mn096-12864&rlz=1C1CHBF_enIN1119IN1119&oq=mn096-12864&gs_lcrp=EgZjaHJvbWUqBggAEEUYOzIGCAAQRRg7MggIARBFGCcYOzINCAIQABiLAxiABBiiBDINCAMQABiLAxiABBiiBDINCAQQABiLAxiABBiiBDIKCAUQABiLAxjvBTINCAYQABiLAxiABBiiBNIBCTE0MzA0ajFqN6gCALACAA&sourceid=chrome&ie=UTF-8">
  mn096-12864 (128x64 Oled Display)</a><br>
</p>




