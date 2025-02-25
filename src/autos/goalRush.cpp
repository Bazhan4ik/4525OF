#include "config.hpp"
#include "main.h"
#include "autos.hpp"
#include "pros/motors.h"




void auto_goalRush() {
  intake.setAlliance('b');

  chassis.moveToPoint(0, 34, 1000);
  intake.run(1);
  pneumatic_robot_extension.set_value(true);
  chassis.waitUntil(29);
  pneumatic_robot_extension.set_value(false);
  chassis.moveToPoint(0, 20, 2000, { .forwards=false, });
  // chassis.waitUntil(10);

  chassis.turnToHeading(-105, 1000);
  chassis.waitUntilDone();
  pneumatic_robot_extension.set_value(true);

  chassis.moveToPoint(17, 24, 2000, { .forwards=false, .maxSpeed=40,  });

  chassis.turnToHeading(-193, 1000);
  chassis.moveToPoint(24, -5.3, 2000, { .maxSpeed=50 });
  intake.run();
  // chassis.waitUntil(12);
  pros::delay(300);

  pneumatic_intake.set_value(false);

  chassis.waitUntilDone();

  pneumatic_intake.set_value(true);
  pros::delay(500);

  chassis.turnToHeading(-70, 2000);

  chassis.moveToPoint(-22, 6, 2000);

  chassis.turnToHeading(-110, 1200);

  chassis.moveToPoint(-31, 5.6, 3000, { .maxSpeed=60 });
  





}