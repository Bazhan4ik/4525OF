#include "main.h"
#include "autos.hpp"
#include "pros/motors.h"



void auto_red_goalRush() {



  chassis.moveToPoint(0, 32.5, 1500, { .maxSpeed=110 });
  pneumatic_robot_extension.set_value(true);
  intake.run(1);
  chassis.waitUntil(29);
  pneumatic_robot_extension.set_value(false);
  chassis.moveToPoint(0, 20, 1000, { .forwards=false }); 
  chassis.waitUntilDone();
  pneumatic_robot_extension.set_value(true);
  pros::delay(1000);
  chassis.moveToPoint(0,13, 1000, {.forwards=false });
  chassis.waitUntilDone();
  pneumatic_robot_extension.set_value(false);

  chassis.turnToPoint(-20, 35, 2000, { .forwards=false, .maxSpeed=80 });
  chassis.moveToPoint(-20, 35, 2000, { .forwards=false, .maxSpeed=50 });

  chassis.waitUntilDone();

  intake.run();

  chassis.turnToPoint(-45, 30, 1000);
  chassis.moveToPoint(-45, 30, 3000, { .maxSpeed=60 });
  pros::delay(200);
  pneumatic_intake.set_value(false);
  intake.run(1);
  chassis.waitUntilDone();
  chassis.setPose(0,0,0);
  chassis.moveToPoint(0, 5, 1000, { .maxSpeed=50 });
  chassis.waitUntilDone();
  pneumatic_intake.set_value(true);
  pros::delay(500);
  intake.run();

  chassis.moveToPoint(0, -5, 1000, { .forwards=false, .maxSpeed=50 });

  return;

  chassis.moveToPoint(-30, 33, 2000, { .forwards=false, .maxSpeed=40 });

  chassis.turnToPoint(-31, 38, 2000);
  chassis.moveToPoint(-31, 38, 2000, { .maxSpeed=40 });
  lb.move(4);

  chassis.waitUntilDone();
  pros::delay(2000);
  intake.stop();

}

void auto_awp_goalRush() {
  chassis.moveToPoint(0, 32.5, 1000);
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
  pros::delay(100);

  pneumatic_intake.set_value(false);
  intake.run(1);

  chassis.waitUntilDone();
  pros::delay(300);
  pneumatic_intake.set_value(true);
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
  return;
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