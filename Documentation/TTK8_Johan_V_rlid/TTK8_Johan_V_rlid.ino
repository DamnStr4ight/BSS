
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DS18B20.h"
#include "MQ5.h"
#include "joystick.h"

#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET);



void setup() {
  // put your setup code here, to run once:
  sei();
  Serial.begin(9600);
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x64)
  // init done
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  //display.display();
  //delay(2000);
  //Setup gas sensor
  pinMode(GAS_SENSOR,INPUT);
  
  display.clearDisplay();
}

void loop() {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  float temp=getTemp();
  display.print("Temp: ");
  display.println(temp);
  display.print("Gas: ");
  display.println(getGasValue()); 
  Serial.print(getGasValue());
  display.print("Joystick Y: ");
  display.println(getJoyY()); 
    
  display.display();
  display.clearDisplay();
  delay(500);
  // put your main code here, to run repeatedly:

}

