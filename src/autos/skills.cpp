#include "intake.hpp"
#include "config.hpp"
#include "autos.hpp"
#include "mogo-grabber.hpp"
#include "lady-brown.hpp"



void align() {
  right_motors.move(60);
  
  pros::delay(250);
  right_motors.brake();
  left_motors.move(60);

  pros::delay(250);
  left_motors.brake();
  right_motors.move(60);

  pros::delay(250);
  right_motors.brake();
  left_motors.move(60);

  // pros::delay(250);
  // left_motors.brake();
  // right_motors.move(60);

  pros::delay(150);
  right_motors.brake();
  left_motors.brake();
}

void align_bwd() {
  right_motors.move(-60);
  
  pros::delay(250);
  right_motors.brake();
  left_motors.move(-60);

  pros::delay(250);
  left_motors.brake();
  right_motors.move(-60);

  pros::delay(250);
  right_motors.brake();
  left_motors.move(-60);

  // pros::delay(250);
  // left_motors.brake();
  // right_motors.move(-60);

  pros::delay(150);
  right_motors.brake();
  left_motors.brake();
}

void skillsAfter2HighStake() {

  // move back
  chassis.moveToPoint(56, -47, 1000, { .forwards=false });
  lb.move(0);



  // take first ring 
  chassis.turnToPoint(81, -47, 2000);
  chassis.moveToPoint(81, -47, 2000);
  intake.run(1);


  // take second ring
  chassis.turnToPoint(83, -19, 2000);
  chassis.moveToPoint(83, -19, 2000);
  intake.run();
  pros::delay(250);
  intake.run(1);


  // go to mogo
  // chassis.turnToPoint(107.3, 3.5, 2000, { .forwards=false });
  givetime = true;
  chassis.turnToPoint(96.8, -5, 2000, { .forwards=false, });
  // chassis.moveToPoint(96.8, -5, 2000, { .forwards=false, .maxSpeed=50, .minSpeed=40, .earlyExitRange=8  });
  chassis.moveToPoint(108, 4, 2000, { .forwards=false, .maxSpeed=55,});
  chassis.waitUntilDone();



  
  // take 3rd ring
  chassis.turnToPoint(85, 52, 3000);
  chassis.moveToPoint(85, 52, 3000, { .maxSpeed=80 });
  intake.run();

  // chassis.turnToHeading(73, 1000);

  // first ring in the corner
  chassis.turnToPoint(98, 59.5, 1000);
  chassis.moveToPoint(98, 59.5, 1000, { .maxSpeed=70 });

  // backup a little
  chassis.moveToPoint(97, 60.5, 1000, { .forwards=false });

  // second ring in the corner
  chassis.turnToPoint(104, 54.5, 1000);
  chassis.moveToPoint(104, 54.5, 1000);

  // last ring
  chassis.turnToPoint(115.7, 53, 1000);
  chassis.moveToPoint(115.7, 53, 1000);

  intake.waitUntilScored(1000);

  // chassis.moveToPoint(110, 55, 1000, { .forwards=false });


  // closer to corner 
  chassis.turnToPoint(120, 59, 5000, { .forwards=false });
  chassis.moveToPoint(120, 59, 500, { .forwards=false });
  mogo_ungrab();
  grab = false;

  // move away from the corner
  chassis.turnToPoint(106, 36, 1000);
  chassis.moveToPoint(106, 36, 1000);
  chassis.turnToHeading(180, 1000);



  // pick up ring for alliance stake
  chassis.moveToPoint(108, -37.5, 2000, { .minSpeed=80, .earlyExitRange=10 });
  chassis.moveToPoint(108, -43.5, 2000, { .maxSpeed=50 });
  intake.run(1);

  // align with aliance stake
  chassis.moveToPoint(108, -5, 1000, { .forwards=false, .minSpeed=80, .earlyExitRange=8 });
  chassis.moveToPoint(108, 2, 500, { .maxSpeed=40 });
  chassis.turnToHeading(-90, 1000, { .minSpeed=20, .earlyExitRange=20 });

  // move closer to aliance stake
  chassis.moveToPoint(123.3, 4, 1200, { .forwards=false, .maxSpeed=60, .minSpeed=50 });
  chassis.waitUntilDone();
  align_bwd();

  intake.run();

  intake.waitUntilScored(2000);

  // move away from the aliance stake
  chassis.moveToPoint(117.3, 3.5, 1500, { .maxSpeed=50 });
  chassis.turnToHeading(-20, 1000);



  chassis.moveToPoint(128, -59, 2000, { .forwards=false });
  intake.setReverse(true);
  intake.run(1);
  chassis.waitUntilDone();
  

  chassis.setPose(0,0,0);

  chassis.moveToPoint(0, 20, 1000, { });


  chassis.waitUntilDone();
  pros::delay(2000);
  intake.stop();
  mogo_ungrab();
  grab = false;
}

void skills() {
  pneumatic_intake.set_value(false);


  // chassis.setPose(60,-60, 180);
  // skillsAfter2HighStake();



  // return;

  chassis.setPose(0,0, 90);


  intake.run();
  pros::delay(500);
  intake.stop();

  intake.scored = 0;



  // move back from alliance stake
  chassis.moveToPoint(12, 0, 1000, { .maxSpeed=90 });
  chassis.turnToHeading(180, 1000);


  // pick up mogo
  chassis.moveToPoint(13.5, 21.1, 1000, { .forwards=false, .maxSpeed=55 });
  chassis.turnToHeading(90, 1000, { .minSpeed=20, .earlyExitRange=20 });

  // pickup first ring
  chassis.moveToPoint(30, 22.5, 1000, { .minSpeed=40, .earlyExitRange=9 });
  intake.run();

  // turn to the ring in the middle
  chassis.turnToHeading(135, 1000, { .minSpeed=20, .earlyExitRange=40 });


  // intake.stop();
  // return;


  // go to the middle
  // chassis.moveToPoint(59, 0, 1000, { .maxSpeed=80, .earlyExitRange=13 });
  chassis.moveToPoint(49, 0, 1000, { .maxSpeed=80, .earlyExitRange=13 });
  intake.run(1);
  chassis.waitUntil(25);
  intake.run();
  // currently picking up ring in the middle
  // chassis.turnToHeading(45, 1000, { .minSpeed=20, .earlyExitRange=40 });
  // intake.waitUntilScored(2000);
  // go to the ring that goes to lady brown
  chassis.moveToPoint(79, 22.5, 2000, { .maxSpeed=80, .minSpeed=20, .earlyExitRange=8 });
  // chassis.waitUntil(30);

  // if only one ring was scored, wait until second one is scored
  // only third ring goes to lady brown
  // if(intake.scored < 2) {
  //   intake.waitUntilScored(1000);
  // }
  // intake.stop();


  // turn to the high stake
  chassis.turnToPoint(60, 40.0, 1000, { .minSpeed=80, .earlyExitRange=30 });
  intake.run();

  // align with the high stake
  chassis.moveToPoint(53, 45.0, 2000, { .maxSpeed=70, .minSpeed=40, .earlyExitRange=8 });
  // move closer to the high stake
  chassis.moveToPose(51, 65, 180, 1200, { .maxSpeed=35, .minSpeed=25 });


  // chassis.turnToHeading(0, 1000);
  lb.move(1);
  intake.run();

  // get close to highstake
  lb.waitUntilDone();
  intake.waitUntilScored(1500);
  intake.stop();
  // chassis.waitUntil(7);
  lb.move(4);

  chassis.waitUntilDone();
  align();
  lb.waitUntilDone();
  chassis.setPose(60, 60, chassis.getPose().theta);

  // move back from the high stake
  chassis.moveToPoint(60, 47, 2000, { .forwards=false, .maxSpeed=60 });
  lb.move(0);

  // turn to 3 ring line
  chassis.turnToHeading(-90, 1000, { .minSpeed=20, .earlyExitRange=30 });
  intake.setReverse(true);
  lb.waitUntilDone();
  intake.run();
  intake.scored = 0;
  // pick up 3 rings
  chassis.moveToPoint(5, 47, 5000, { .maxSpeed=65 });
  intake.setReverse(false);
  // backup to align with the last ring 
  chassis.moveToPoint(11, 47, 1000, { .forwards=false });

  chassis.turnToHeading(0, 1000);
  // pick up the last ring, save for later
  chassis.moveToPoint(11.5, 53, 1000);



  // =====>
  // CHANGE TO 4
  // because 3 rings have to be scored before grabbing the last one
  // if(intake.scored < 3) {
  //   intake.waitUntilScored(2000);
  // }
  // chassis.waitUntilDone();
  intake.run(1);
  

  // put the mogo in the corner
  chassis.turnToPoint(5, 57, 1000, { .forwards=false });
  chassis.moveToPoint(5, 57, 1000, { .forwards=false });
  mogo_ungrab();
  grab = false;

  
  // mave away from the corner to not hit the wall
  chassis.moveToPoint(10, 53, 1000, { });
  intake.run();
  pros::delay(250);
  intake.stop();
  // turn to the second mogo
  // chassis.turnToHeading(0, 1000, { .minSpeed=20, .earlyExitRange=3 });
  // chassis.turnToHeading(0, 1000, { .minSpeed=20, .earlyExitRange=60 });
  chassis.turnToHeading(0, 1000, { });
  grab = true;





  // ===>
  // ===> SECOND QUARDANT
  // ===>





  // pickup mogo
  chassis.moveToPoint(8, -10.0 , 3000, { .forwards=false, .minSpeed=100, .earlyExitRange=14 });
  chassis.moveToPoint(7, -23.5, 3000, { .forwards=false, .maxSpeed=40 });


  // turn to the first ring
  chassis.turnToPoint(29, -23, 1000);
  // chassis.turnToPoint(29, -23, 1000, { .minSpeed=20, .earlyExitRange=40 });
  chassis.moveToPoint(29, -23, 1000);
  intake.run();


  // turn to the second ring
  // chassis.turnToPoint(33, -45.6, 1000, { .minSpeed=20, .earlyExitRange=40 });
  chassis.turnToPoint(31, -45.6, 1000);
  chassis.moveToPoint(31, -45.6, 1000);



  // pickup two rings
  chassis.turnToPoint(1, -49, 3000, { .minSpeed=20, .earlyExitRange=40 });
  chassis.moveToPoint(1, -49, 3000, { .maxSpeed=70 });

  // backup for the last ring
  chassis.moveToPoint(10, -49, 3000, { .forwards=false, });

  // pickup last ring
  chassis.turnToPoint(11, -58, 1000);
  chassis.moveToPoint(11, -58, 1000);
  chassis.waitUntilDone();

  // turn to corner
  chassis.turnToPoint(3, -61, 1000, { .forwards=false });
  // wait for last ring to score
  // intake.waitUntilScored(1500);
  chassis.moveToPoint(3, -61, 1000, { .forwards=false });
  // drop the mogo of in the corner
  mogo_ungrab();
  grab = false;
  intake.scored = 0;


  // align with the high stake
  chassis.turnToPoint(56, -44.5, 3000);
  chassis.moveToPoint(35.9, -50.5, 2000, { .minSpeed=80, .earlyExitRange=6 });
  chassis.moveToPoint(54, -44.5, 3000, { .maxSpeed=30 });
  grab = true;

  chassis.turnToHeading(180, 1000, { .minSpeed=20, .earlyExitRange=20 });

  // close to high stake
  chassis.moveToPoint(54.5, -66, 1200, { .maxSpeed=35 });
  lb.move(1);
  intake.run();
  intake.waitUntilScored(3000);
  intake.stop();
  lb.move(4);
  align();
  // reset position
  chassis.setPose(60.5, -62, chassis.getPose().theta);
  lb.waitUntilDone();


  skillsAfter2HighStake();
}


