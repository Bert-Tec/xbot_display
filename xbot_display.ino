#include "xbot_display_show.h"
#include "xbot_display_data.h"

xbot_display_show display;
xbot_display_data scooterData;

bool ESP_01 = true;
unsigned long unlockSpeedTime = 7000;
unsigned long resetSpeedTime = 2000;
unsigned long changeSpeedTimer = 0;
unsigned long changeSpeedTime = unlockSpeedTime;
unsigned long changeModeTimer = 0;
unsigned long changeModeTime = 1000;

bool maxSpeed = false;

void setup() 
{
  // delete the whole condition if not using esp
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
        int size = 0;
        switch (Serial.peek())
        {
          case 0x07: size = 0x07 + 4;break;
          case 0x09: size = 0x09 + 4;break;
          case 0x0B: size = 0x0B + 4;break;
          default: break;
        }

        byte readData[size];

        for(int i = 0; i < size; i++)
        {
          readData[i] = Serial.read();        
        }

        if(calculateChecksum(readData) == readData[size-2] + readData[size-1] * 256)
        {
          scooterData.newData(readData);
        }

        // check to set speed = 30
        if(scooterData.throttle_ == 100 && scooterData.break_ == 100 && scooterData.speed_ == 0)
        {
          if(changeSpeedTimer > 0)
          {
            if(millis()-changeSpeedTimer > changeSpeedTime)
            {
              if(maxSpeed)
              {
                maxSpeed = false;
                changeSpeedTime = unlockSpeedTime;
                byte buf[10]={0x55, 0xAA, 0x04, 0x22, 0x01, 0xF2 ,0xF8 ,0x01, 0xED, 0xFD};
                sendData(buf,10);
              }
              else
              {
                maxSpeed = true;
                // set time for reset
                changeSpeedTime = resetSpeedTime;
                byte buf[10]={0x55, 0xAA, 0x04, 0x22, 0x01, 0xF2, 0xF3, 0x02, 0xF1, 0xFD};
                sendData(buf,10);
              }
              scooterData.unlockedSpeed_ = maxSpeed;
            }
          }
          else
          {
            changeSpeedTimer = millis();
          }
        }
        else
        {
          changeSpeedTimer = 0;
        }
        // check to change display mode
        if(scooterData.throttle_ == 100 && scooterData.break_ < 10 && scooterData.speed_ == 0)
        {
          if(changeModeTimer > 0)
          {
            if(millis()-changeModeTimer > changeModeTime)
            {
              display.changeMode();
            }
          }
          else
          {
            changeModeTimer = millis();
          }
        }
        else
        {
          changeModeTimer = 0;
        }
      }
    }
    display.update(&scooterData);
  }
}

void sendData(byte * data, int len)
{
  Serial.write(data,len);
}

uint16_t calculateChecksum(byte *data)
{
	uint8_t len = data[0] + 2;
	uint16_t sum = 0;
	for(int i = 0; i < len; i++)
  {
		sum += data[i];
  }

	sum ^= 0xFFFF;
	return sum;
}
