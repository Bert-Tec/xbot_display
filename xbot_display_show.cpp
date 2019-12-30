#include "xbot_display_show.h"

xbot_display_show::xbot_display_show()
{
}
xbot_display_show::~xbot_display_show()
{

}
void xbot_display_show::init()
{
  actual_mode_ = 0;
  modeCount_ = 3;

  // (width, height, wire, resetPin)
  disp = new Adafruit_SSD1306(128, 64, &Wire, -1);

  disp->begin(SSD1306_SWITCHCAPVCC, 0x3C);
  disp->clearDisplay();
  disp->setCursor(30,30);
  disp->setTextColor(WHITE);
  disp->setTextSize(2);
  disp->print("boot");
  disp->display();
  delay(250);
  disp->print(".");
  disp->display();
  delay(250);
  disp->print(".");
  disp->display();
  delay(250);
  disp->print(".");
  disp->display();
  delay(250);
}
void xbot_display_show::update(xbot_display_data* data)
{
  bool modeChanged = false;
  if(data->speed_ == 0 && data->throttle_ == 100 && data->break_ == 100)
  {
    changeMode();
    modeChanged = true;
  }
  
  disp->clearDisplay();

  switch(actual_mode_)
  {
    // Home
    case 0: 
            disp->fillRect(0,0,128,16,WHITE);
            disp->setTextColor(BLACK);
            //label
            disp->setCursor(53,2);
            disp->setTextSize(1);
            disp->print("Home");
            //battery
            disp->setTextSize(2);
            disp->setCursor(80,1);
            disp->print(data->battery_percent_);
            disp->print("%");
            //throttle
            disp->setTextSize(1);
            disp->setCursor(3,1);
            disp->print("T: ");
            disp->print(data->throttle_);
            disp->print("%");
            //break
            disp->setTextSize(1);
            disp->setCursor(3,9);
            disp->print("B: ");
            disp->print(data->break_);
            disp->print("%");
          
            disp->setTextColor(WHITE);
          
            //light 
            if(!data->light_)
              disp->drawCircle(122,20,4,WHITE);
            if(data->light_)
              disp->fillCircle(122,20,4,WHITE);
            //eco 
            if(!data->eco_)
              disp->drawCircle(4,20,4,WHITE);
            if(data->eco_)
              disp->fillCircle(4,20,4,WHITE);
            //speed
            disp->setTextSize(5);
            if(data->speed_ > 9.999)
            {
              disp->setCursor(5,25);
              disp->print(data->speed_,1);
            }
            else if(data->speed_ > 99.999)
            {
              disp->setCursor(20,25);
              disp->print(data->speed_,0);
            }
            else
            {
              disp->setCursor(20,25);
              disp->print(data->speed_,1);
            }
            break;
    // throttle break graph
    case 1: 
            disp->fillRect(0,0,128,16,WHITE);
            disp->setTextColor(BLACK);
            //label
            disp->setCursor(42,2);
            disp->setTextSize(1);
            disp->print("Throttle");
               
            disp->setTextColor(WHITE);
            disp->setCursor(10,20);
            disp->print("Throttle");
            disp->fillRect(10,30,data->throttle_,5,WHITE);
            
            disp->setCursor(10,45);
            disp->print("Break");
            disp->fillRect(10,55,data->break_,5,WHITE);
            break;
    // off
    case 2:
            break;
    default: 
            disp->setTextColor(WHITE);
            disp->setTextSize(2);
            disp->setCursor(10,20);
            disp->print("Error!");
            break;
  }

  disp->display();
  
  if(modeChanged)
  {
    delay(700);
  }
}
void xbot_display_show::changeMode()
{
  if(actual_mode_ + 1 >= modeCount_)
  {
    actual_mode_ = 0;
  }
  else
  {
    actual_mode_ = actual_mode_ + 1;
  }
}
