/***************************************************************************
  This is a library for the AMG88xx GridEYE 8x8 IR camera

  This sketch tries to read the pixels from the sensor

  Designed specifically to work with the Adafruit AMG88 breakout
  ----> http://www.adafruit.com/products/3538

  These sensors use I2C to communicate. The device's I2C address is 0x69

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Dean Miller for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Wire.h>
#include <Adafruit_AMG88xx.h>

Adafruit_AMG88xx amg;

float pixels[AMG88xx_PIXEL_ARRAY_SIZE];

void setup() {
    Serial.begin(115200);
    bool status;
    
    // default settings
    status = amg.begin();
}


void loop() { 
    //read all the pixels
    amg.readPixels(pixels);

    for(int i=0; i<AMG88xx_PIXEL_ARRAY_SIZE; i++){
      Serial.print(pixels[i]);
      Serial.print(",");
    }
    // End each frame with a linefeed
    Serial.println();
  
    // Give Processing time to chew
    delay(100);
}
