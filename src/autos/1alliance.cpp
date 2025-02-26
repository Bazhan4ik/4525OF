#include "main.h"
#include "autos.hpp"
#include "config.hpp"
#include "intake.hpp"



void auto_left_main() {

  intake.setAlliance('b');

  chassis.setPose(0, 0, 0);

  lb.move(2);
  chassis.moveToPoint(0, -15.5, 1000, { .forwards=false });
  chassis.waitUntil(13);
  lb.move(0);

  chassis.moveToPoint(10, -35, 1000, { .forwards=false });

  chassis.moveToPoint(39, -35.5, 2000, { .forwards=false, .maxSpeed=50 });
  givetime = true;

  chassis.turnToHeading(-165, 1000);

  chassis.moveToPoint(39, -60, 1000);
  intake.run();
  chassis.waitUntilDone();
  pros::delay(400);

  // scored one ring

  // next options:
  //    touch the bar
  //    grab the ring in the middle
  //        touch the bar
  //        proceed with awp
  //    corner clear?

  return;

  chassis.turnToHeading(-30, 1000);
  chassis.waitUntilDone();


  mogo_ungrab();
  intake.stop();

  // middle ring here: 17, -17

  intake.stop();
}

