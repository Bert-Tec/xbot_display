#include "xbot_display_show.h"
#include "xbot_display_data.h"

xbot_display_show display;
xbot_display_data scooterData;

bool ESP_01 = true;

void setup() 
{
  if(ESP_01)
  {
     Wire.begin(0,2); 
  }
  Serial.begin(115200);
  display.init();
  scooterData.init();
}

void loop() 
{  
  // while more then two bytes are available
  while (Serial.available() >= 2)
  {
    if (Serial.read() == 0x55 && Serial.peek() == 0xAA) 
    {
      // remove 0xAA
      Serial.read();
      if(Serial.peek() == 0x07 || Serial.peek() == 0x09 || Serial.peek() == 0x0B)
      {
        int size =  Serial.read()+2;
        //int size = 20;
        byte readData[size];
        int counter = 0;
    
        while(Serial.peek() != 0xFF && Serial.peek() != 0xFE && counter < size)
        {
          readData[counter++] = Serial.read();        
        }
        scooterData.newData(readData);
        display.update(&scooterData);
      }
    }
  }
  display.update(&scooterData);
  //delay(2000);
}
