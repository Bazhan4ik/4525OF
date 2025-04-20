#include "mogo-grabber.hpp"
#include "pros/llemu.hpp"
#include "pros/rtos.hpp"

#include "config.hpp"


bool grab = true;
bool givetime = false;
bool grabbed = false;
bool ungrabbed = false;

void mogo_disable() {
  grab = false;
}
void mogo_enable() {
  grab = true;
}

void mogo_grabber() {
  while(true) {
    pros::delay(20);

    pros::lcd::print(4, "%d", distance_sensor.get_distance());

    if(grabbed) {
      continue;
    }

    // if(ungrabbed) {
    //   pros::delay(500);
    //   ungrabbed = false;
    // }

    if(grab) {

      if(distance_sensor.get_distance() > 30 && distance_sensor.get_distance() < 40) {
        if(givetime) {
          givetime = false;
          pros::delay(250);
        }
        pneumatic_mogo_grabber.set_value(true);
        grabbed = true;
        master.rumble(".");
      }

      
    }
    
  }
}
void mogo_ungrab() {
  pneumatic_mogo_grabber.set_value(false);
  givetime = false;
  grab = true;
  grabbed = false;
  ungrabbed = true;
}