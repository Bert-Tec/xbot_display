#ifndef XBOT_DISPLAY_SHOW_H
#define XBOT_DISPLAY_SHOW_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "xbot_display_data.h"

class xbot_display_show 
{
  public:
    xbot_display_show();
    ~xbot_display_show();

    void init();
    void update(xbot_display_data*);
    void changeMode();

  private:
    int actual_mode_;
    int modeCount_;

    Adafruit_SSD1306 * disp;
};

#endif
