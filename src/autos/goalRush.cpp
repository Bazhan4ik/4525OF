#include "main.h"
#include "autos.hpp"
#include "pros/motors.h"



void auto_awp_goalRush() {
  chassis.moveToPoint(0, 32, 1000);
  pneumatic_robot_extension.set_value(true);
  intake.run(1);
  chassis.waitUntilDone();
  pneumatic_robot_extension.set_value(false);
  chassis.moveToPoint(0, 10, 1000, { .forwards=false });
  chassis.waitUntilDone();
  left_motors.move(127);
  right_motors.move(127);
  pros::delay(200);
  left_motors.move(-127);
  right_motors.move(-127);
  pros::delay(400);
  left_motors.brake();
  right_motors.brake();

  pros::delay(500);



  chassis.turnToPoint(14.5, 23, 3200, { .forwards=false, .maxSpeed=80 });
  chassis.moveToPoint(14.5, 23, 3000, { .forwards=false, .maxSpeed=50 });

  chassis.waitUntilDone();

  intake.run();
  chassis.turnToPoint(26, 0, 3000, {  });
  chassis.moveToPoint(26, 0, 1000, { .maxSpeed=55 });
  pros::delay(300);

  pneumatic_intake.set_value(true);
  intake.run(1);

  chassis.waitUntilDone();
  pros::delay(300);
  pneumatic_intake.set_value(false);
  pros::delay(300);

  chassis.moveToPoint(24, 5, 3000, { .forwards=false, });

  chassis.turnToHeading(-120, 1000);
  chassis.waitUntilDone();

  mogo_ungrab();

  pros::delay(200);

  chassis.turnToHeading(-200, 2000);

  chassis.moveToPoint(9, 40, 5000, { .forwards=false, .maxSpeed=40 });
  chassis.waitUntilDone();

  if(grabbed) {
    intake.run();
  }
  

  chassis.turnToPoint(17, 36, 2000);
  chassis.moveToPoint(17, 36, 2000, { .maxSpeed=50 });
  pros::delay(400);

  lb.move(4);

  lb.waitUntilDone();

  lb.setMode(pros::E_MOTOR_BRAKE_COAST);
}





void auto_goalRush() {
  chassis.moveToPoint(0, 32, 1000);
  pneumatic_robot_extension.set_value(true);
  intake.run(1);
  chassis.waitUntilDone();
  pneumatic_robot_extension.set_value(false);
  chassis.moveToPoint(0, 10, 1000, { .forwards=false });
  chassis.waitUntilDone();
  left_motors.move(127);
  right_motors.move(127);
  pros::delay(200);
  left_motors.move(-127);
  right_motors.move(-127);
  pros::delay(400);
  left_motors.brake();
  right_motors.brake();

  pros::delay(500);



  chassis.turnToPoint(14.5, 23, 3200, { .forwards=false, .maxSpeed=80 });
  chassis.moveToPoint(14.5, 23, 3000, { .forwards=false, .maxSpeed=50 });

  chassis.waitUntilDone();

  intake.run();
  chassis.turnToPoint(26, 0, 3000, {  });
  chassis.moveToPoint(26, 0, 1000, { .maxSpeed=55 });
  pros::delay(300);

  pneumatic_intake.set_value(true);
  intake.run(1);

  chassis.waitUntilDone();
  pros::delay(300);
  pneumatic_intake.set_value(false);
  pros::delay(300);

  chassis.moveToPoint(24, 5, 3000, { .forwards=false, });
  pros::delay(100);
  intake.run();
  pros::delay(500);

  chassis.turnToHeading(-120, 1000);
  chassis.waitUntilDone();

  mogo_ungrab();

  pros::delay(200);

  chassis.turnToHeading(-200, 2000);

  chassis.moveToPoint(9, 40, 5000, { .forwards=false, .maxSpeed=40 });
  chassis.waitUntilDone();
  intake.stop();

}