#include "main.h"
#include "autos.hpp"
#include "config.hpp"
#include "pros/motors.h"



void auto_awp_safe() {

  lb.move(2);

  chassis.moveToPoint(0, -14.1, 2000, { .forwards=false, .maxSpeed=40 });
  chassis.waitUntilDone();

  lb.move(0);
  lb.waitUntilDone();

  chassis.moveToPoint(7, -25, 2000, { .forwards=false });


  chassis.turnToPoint(33.5, -35.8, 2000, { .forwards=false, .maxSpeed=80 });
  chassis.moveToPoint(33.5, -35.8, 2000, { .forwards=false, .maxSpeed=50 });

  chassis.turnToPoint(16, -19, 2000, { .maxSpeed=80 });
  pneumatic_intake.set_value(false);
  intake.run(1);
  chassis.moveToPoint(16, -19, 2000, { .maxSpeed=50 });
  chassis.waitUntilDone();
  pros::delay(300);
  pneumatic_intake.set_value(true);
  pros::delay(300);

  chassis.moveToPoint(22, -25.5, 2000, {.forwards=false});

  chassis.turnToPoint(35.5, -55, 2000);
  intake.run();
  chassis.moveToPoint(35.5, -55, 2000);


  chassis.turnToPoint(39, -43, 1000, { .maxSpeed=80 });
  lb.move(4);
  chassis.moveToPoint(39, -43, 3000, { .maxSpeed=60 });
   

  chassis.waitUntilDone();
  pros::delay(5000);

  intake.stop();

  // intake.run();



  
}


void auto_5Rings() {
  chassis.moveToPoint(0, -31, 2000, { .forwards=false, .maxSpeed=60 });
  chassis.turnToPoint(-21, -38, 2000, { .maxSpeed=80 });
  intake.run();
  chassis.moveToPoint(-21, -38, 1000, { .maxSpeed=60 });
  chassis.turnToPoint(-30, -36, 2000, { .maxSpeed=80 });
  chassis.moveToPoint(-30, -36, 2000, { .maxSpeed=50 });

  chassis.turnToPoint(-37, -34, 1000, { .maxSpeed=30 });
  

  chassis.waitUntilDone();
  intake.stop();

  return;


  chassis.turnToPoint(-26, -20, 1000, {}); 
  chassis.moveToPoint(-26, -20, 1000, {}); 


  chassis.turnToPoint(24.6, -18, 2000, { .maxSpeed=80 });
  chassis.waitUntilDone();
  pros::delay(500);
  chassis.moveToPoint(24.6, -18, 2000, { .maxSpeed=60 });
  pneumatic_intake.set_value(false);
  intake.run(1);
  chassis.waitUntilDone();
  pros::delay(100);
  pneumatic_intake.set_value(true);
  pros::delay(500);

  chassis.moveToPoint(12, -17, 2000, { .forwards=false });
  intake.run();

  chassis.moveToPoint(17, -17, 2000, { });


  chassis.waitUntilDone();
  pros::delay(2000);

  intake.stop();
}
void auto_red_5Rings() {
  chassis.moveToPoint(0, -31, 2000, { .forwards=false, .maxSpeed=60 });
  chassis.turnToPoint(22, -34.5, 2000, { .maxSpeed=80 });
  intake.run();
  chassis.moveToPoint(22, -34.5, 1000, { .maxSpeed=60 });
  chassis.turnToPoint(33, -28, 2000, { .maxSpeed=80 });
  chassis.moveToPoint(33, -28, 2000, { .maxSpeed=50 });


  chassis.turnToPoint(26, -20, 1000, {}); 
  chassis.moveToPoint(26, -20, 1000, {}); 


  chassis.turnToPoint(-24.6, -18, 2000, { .maxSpeed=80 });
  chassis.waitUntilDone();
  pros::delay(500);
  chassis.moveToPoint(-24.6, -18, 2000, { .maxSpeed=60 });
  pneumatic_intake.set_value(false);
  intake.run(1);
  chassis.waitUntilDone();
  pros::delay(100);
  pneumatic_intake.set_value(true);
  pros::delay(500);

  chassis.moveToPoint(-12, -17, 2000, { .forwards=false });
  intake.run();

  chassis.moveToPoint(-17, -17, 2000, { });


  chassis.waitUntilDone();
  pros::delay(2000);

  intake.stop();
}


void auto_awp_5Rings() {
  chassis.moveToPoint(0, -31, 2000, { .forwards=false, .maxSpeed=60 });
  chassis.turnToPoint(-22, -34.5, 2000, { .maxSpeed=80 });
  intake.run();
  chassis.moveToPoint(-22, -34.5, 1000, { .maxSpeed=60 });
  chassis.turnToPoint(-33, -28, 2000, { .maxSpeed=80 });
  chassis.moveToPoint(-33, -28, 2000, { .maxSpeed=50 });


  chassis.turnToPoint(-26, -20, 1000, {}); 
  chassis.moveToPoint(-26, -20, 1000, {}); 


  chassis.turnToPoint(24.6, -18, 2000, { .maxSpeed=80 });
  chassis.waitUntilDone();
  pros::delay(500);
  chassis.moveToPoint(24.6, -18, 2000, { .maxSpeed=60 });
  pneumatic_intake.set_value(true);
  intake.run(1);
  chassis.waitUntilDone();
  pros::delay(100);
  pneumatic_intake.set_value(false);
  pros::delay(500);

  chassis.moveToPoint(12, -17, 2000, { .forwards=false });
  intake.run();


  chassis.turnToPoint(7, -29, 1000);
  chassis.moveToPoint(7, -29, 2000, { .maxSpeed=50 });
  lb.move(4);

  lb.setMode(pros::E_MOTOR_BRAKE_COAST);


  return;

  chassis.waitUntilDone();
  pros::delay(2000);

  intake.stop();
}



void auto_red_awp_5Rings() {
  chassis.moveToPoint(0, -31, 2000, { .forwards=false, .maxSpeed=60 });
  chassis.turnToPoint(22, -34.5, 2000, { .maxSpeed=80 });
  intake.run();
  chassis.moveToPoint(22, -34.5, 1000, { .maxSpeed=60 });

  chassis.turnToPoint(30, -33, 700, { .maxSpeed=80 });
  chassis.moveToPoint(30, -33, 2000, { .maxSpeed=50 });

  chassis.turnToPoint(26, -27.5, 1000, {}); 
  chassis.moveToPoint(26, -27.5, 1000, {}); 

  chassis.waitUntilDone();
  pros::delay(1000);
  intake.stop();
  return;



  chassis.turnToPoint(-24.6, -18, 2000, { .maxSpeed=80 });
  intake.stop();
  return;
  chassis.waitUntilDone();
  pros::delay(500);
  chassis.moveToPoint(-24.6, -18, 2000, { .maxSpeed=60 });
  pneumatic_intake.set_value(true);
  intake.run(1);
  chassis.waitUntilDone();
  pros::delay(100);
  pneumatic_intake.set_value(false);
  pros::delay(500);

  chassis.moveToPoint(-12, -17, 2000, { .forwards=false });
  intake.run();


  chassis.turnToPoint(-7, -29, 1000);
  chassis.moveToPoint(-7, -29, 2000, { .maxSpeed=50 });
  lb.move(4);

  lb.setMode(pros::E_MOTOR_BRAKE_COAST);


  return;

  chassis.waitUntilDone();
  pros::delay(2000);

  intake.stop();
}