#include "xbot_display_data.h"

xbot_display_data::xbot_display_data()
{
}
xbot_display_data::~xbot_display_data()
{

}
void xbot_display_data::init()
{
    speed_ = 0.0;
    battery_percent_ = 0;
    battery_points_ = 0.0;
    throttle_ = 0;
    break_ = 0;
    eco_ = false;
    light_ = false;
}
void xbot_display_data::newData(byte * data)
{
  int t,b;
  switch(data[1])
  {
    case 0x60:  t = data[4]; //max: 0xC5=197 min: 0x2b=43
                t = (int) (t-42)/1.55;
                throttle_ = t;
                b = data[5]; //max: 0x??=181 min: 0x2b=43
                b = (int) (b-42)/1.39;
                break_ = b;
                break;
    case 0x63:
                break;
    case 0x6d:  if(data[3] == 2) // 0x00 = off 0x02 = on
                {
                  eco_ = true; 
                }
                else
                {
                  eco_ = false;
                }
                battery_points_ = data[4]; // max: 8
                light_ = data[5]; // 0x00 = off 0x01 = on
                speed_ = ((float)(data[7] + data[8] * 256) ) / 1000;
                battery_percent_ = data[11]; // 0x64 = 100%
                break;
    default:
              break;

  }
}
