#include "main.h"
#include "autos.hpp"
#include "config.hpp"
#include "intake.hpp"



// 1  ->  4 rings + tower
// 2  ->  4 rings + corner
// 3  ->  4 rings + one ring + tower
// 4  ->  4 rings + one ring + corner
void neg_blue(int option) {

  intake.setAlliance('b');

  chassis.setPose(0, 0, -121.38);

  chassis.moveToPoint(31, 19.5, 2000, { .forwards=false, .maxSpeed=60 });

  chassis.turnToPoint(46, 3, 1000);
  chassis.moveToPoint(46, 3, 1000, { .maxSpeed=70 });
  intake.run();

  chassis.turnToPoint(45, -14, 1000);
  chassis.moveToPoint(45, -12, 1000);

  chassis.turnToPoint(32, -7, 1000);
  chassis.moveToPoint(32, -7, 1000);

  if(option == 1) {
    chassis.moveToPoint(29, 30, 2000, { .maxSpeed=50 });
    return;
  } else if(option == 2) {
    chassis.moveToPoint(0, -7, 1000, { .maxSpeed=50 });
    return;
  }

  // move to the alliance ring
  chassis.turnToPoint(11, 33, 2000, { });
  chassis.moveToPoint(11, 33, 2000, { .minSpeed=70, .earlyExitRange=8 });
  chassis.moveToPoint(1, 48, 2000, { .maxSpeed=40 });
  chassis.waitUntilDone();
  pros::delay(1000);


  if(option == 3) {
    // go to the tower
    chassis.turnToPoint(25, 39, 1000);
    chassis.moveToPoint(25, 39, 1500, { .maxSpeed=50, .minSpeed=25 });
  } else if(option == 4) {
    // go to the corner
    chassis.turnToHeading(180, 1500);
    chassis.moveToPoint(5, -5, 2000, { .maxSpeed=60 });

    pneumatic_robot_extension.set_value(true);
  }

}



void neg_red(int option) {

  intake.setAlliance('r');

  chassis.setPose(0, 0, -59.62);

  chassis.moveToPoint(31, -20.5, 2000, { .forwards=false, .maxSpeed=60 });

  chassis.turnToPoint(46, -3, 1000);
  chassis.moveToPoint(46, -3, 1000, { .maxSpeed=70 });
  intake.run();

  chassis.turnToPoint(45, 14, 1000);
  chassis.moveToPoint(45, 12, 1000);
  
  chassis.turnToPoint(32, 7, 1000);
  chassis.moveToPoint(32, 7, 1000);

  if(option == 1) {
    chassis.moveToPoint(29, -30, 2000, { .maxSpeed=70, .minSpeed=30 });
    return;
  } else if(option == 2) {
    chassis.moveToPoint(0, 15, 2000, { .maxSpeed=70, .minSpeed=30 });
    return;
  }

  // move to the alliance ring
  chassis.turnToPoint(11, -33, 2000, { });
  chassis.moveToPoint(11, -33, 2000, { .minSpeed=70, .earlyExitRange=10 });
  chassis.moveToPoint(1, -48, 2000, { .maxSpeed=40 });
  chassis.waitUntilDone();
  pros::delay(1000);


  if(option == 3) {
    // go to the tower
    chassis.turnToPoint(25, -39, 1000);
    chassis.moveToPoint(25, -39, 1500, { .maxSpeed=50, .minSpeed=25 });
  } else if(option == 4) {
    // go to the corner
    chassis.turnToHeading(180, 1500);
    chassis.moveToPoint(5, 5, 2000, { .maxSpeed=70, .minSpeed=35 });

    pneumatic_robot_extension.set_value(true);
  }

}