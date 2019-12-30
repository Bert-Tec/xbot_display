#ifndef XBOT_DISPLAY_DATA_H
#define XBOT_DISPLAY_DATA_H

#include <stdint.h>
typedef uint8_t byte;

class xbot_display_data 
{
  public:
    xbot_display_data();
    ~xbot_display_data();
    
    void init();
    void newData(byte * data);

    float speed_;
    int battery_percent_;
    float battery_points_;
    int throttle_;
    int break_;
    bool eco_;
    bool light_;

  private:
};

#endif
