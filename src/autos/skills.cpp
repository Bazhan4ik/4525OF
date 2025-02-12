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
  chassis.moveToPoint(60, -47, 1000, { .forwards=false });
  lb.move(0);

  return;

  // take first ring 
  chassis.turnToPoint(81, -47, 2000);
  chassis.moveToPoint(81, -47, 2000);
  intake.run(1);


  // take second ring
  chassis.turnToPoint(83, -22, 2000);
  chassis.moveToPoint(83, -22, 2000);
  intake.run();
  pros::delay(250);
  intake.run(1);


  // go to mogo
  
  chassis.turnToPoint(107.3, 3.5, 2000, { .forwards=false });
  // chassis.moveToPoint(97.5, -7.5, 1000, { .forwards=false, .minSpeed=80, .earlyExitRange=5 });
  chassis.moveToPoint(107.3, 0.5, 2000, { .forwards=false, .maxSpeed=60 });

  // take 3rd ring
  chassis.turnToPoint(85, 52, 3000);
  chassis.moveToPoint(85, 52, 3000, { .maxSpeed=80 });
  intake.run();

  chassis.turnToHeading(90, 1000);

  chassis.moveToPoint(108, 52, 2000, { .maxSpeed=70 });
  chassis.moveToPoint(110, 52, 2000, { .forwards=false });
  chassis.waitUntilDone();
  pros::delay(300);
  chassis.moveToPoint(120, 52, 4000, { .maxSpeed=35 });
  // chassis.moveToPoint(110, 52, 4000, { .forwards=false, .maxSpeed=70 });
  // chassis.moveToPoint(118, 52, 4000, { .maxSpeed=40 });
  chassis.moveToPoint(110, 52, 4000, { .forwards=false, .maxSpeed=70 });
  chassis.turnToHeading(0, 2000);

  // last ring in the corner
  chassis.moveToPoint(108, 61, 1000);
  chassis.moveToPoint(108, 52, 1000, { .forwards=false });
  // chassis.turnToHeading(-145, 1000);

  chassis.turnToPoint(118, 60, 1000, { .forwards=false });
  chassis.moveToPoint(118, 60, 1000, { .forwards=false });
  mogo_ungrab();
  grab = false;


  chassis.moveToPoint(105, 50, 1000);
  chassis.turnToHeading(180, 1000);

  // pick up the ring for alliance stake
  chassis.moveToPoint(105, -28, 3000, { .minSpeed=100, .earlyExitRange=10 });
  chassis.moveToPoint(105, -37, 3000, { .maxSpeed=40 });
  intake.run(1);
  chassis.moveToPoint(111, -7, 3000, { .forwards=false, .minSpeed=100, .earlyExitRange=6 });
  chassis.moveToPoint(111, 3.5, 1000, { .forwards=false, .maxSpeed=40 });

  // move closer to aliance stake
  chassis.turnToPoint(120, 4.6, 1000, { .forwards=false, });
  chassis.moveToPoint(120, 4.6, 1000, { .forwards=false, .maxSpeed=35 });
  chassis.waitUntilDone();
  align_bwd();
  intake.run();

  intake.waitUntilScored(1000);

  chassis.moveToPoint(118, 4.6, 1000, { .forwards=false });

  chassis.turnToPoint(127, -50, 1000);
  chassis.moveToPoint(127, -50, 2000);
  intake.setReverse(true);
  

  




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
  chassis.moveToPoint(12.5, 0, 1000, { .maxSpeed=90 });
  chassis.turnToHeading(180, 1000);


  // pick up mogo
  chassis.moveToPoint(14, 21.1, 1000, { .forwards=false, .maxSpeed=70 });
  chassis.turnToHeading(90, 1000);

  // pickup first ring
  chassis.moveToPoint(33, 21, 1000);
  intake.run();

  // turn to the ring in the middle
  chassis.turnToHeading(135, 1000, { .earlyExitRange=50 });
  intake.waitUntilScored(2000);

  intake.run(1);


  // go to the middle
  chassis.moveToPoint(59, 0, 1000, { .maxSpeed=80 });
  chassis.waitUntil(35);
  intake.run();
  // currently picking up ring in the middle
  chassis.turnToHeading(45, 1000);
  // intake.waitUntilScored(2000);
  // go to the ring that goes to lady brown
  chassis.moveToPoint(83, 22.5, 2000, { .maxSpeed=80 });
  intake.run(1);


  // if only one ring was scored, wait until second one is scored
  // only third ring goes to lady brown
  // if(intake.scored < 2) {
  //   intake.waitUntilScored(1000);
  // }
  // intake.stop();


  // turn to the high stake
  chassis.turnToPoint(63, 44.0, 1000, { .minSpeed=80, .earlyExitRange=30 });
  intake.run();

  // align with the high stake
  chassis.moveToPoint(66, 50.0, 2000, { .maxSpeed=70, .minSpeed=40, .earlyExitRange=12 });
  chassis.moveToPoint(63.5, 65,  2000, { .maxSpeed=55, .minSpeed=35 });


  // chassis.turnToHeading(0, 1000);
  lb.move(1);
  intake.run(1);

  // get close to highstake
  lb.waitUntilDone();
  intake.run();
  intake.waitUntilScored(3000);
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
  chassis.turnToHeading(-90, 1000);
  lb.waitUntilDone();
  intake.run();
  intake.scored = 0;
  // pick up 3 rings
  chassis.moveToPoint(5, 47, 5000, { .maxSpeed=65 });
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
  chassis.turnToPoint(5, 59, 1000, { .forwards=false });
  chassis.moveToPoint(5, 59, 1000, { .forwards=false });
  mogo_ungrab();
  grab = false;

  
  // mave away from the corner to not hit the wall
  chassis.moveToPoint(14, 55, 1000, { });
  intake.run();
  pros::delay(250);
  intake.stop();
  // turn to the second mogo
  chassis.turnToHeading(0, 1000, { .minSpeed=20, .earlyExitRange=10 });
  grab = true;


  // pickup mogo
  chassis.moveToPoint(8, -10.0 , 3000, { .forwards=false, .minSpeed=100, .earlyExitRange=10 });
  chassis.moveToPoint(7, -23.5, 3000, { .forwards=false, .maxSpeed=40 });


  // turn to the first ring
  // chassis.turnToPoint(29, -23, 1000, { .minSpeed=30, .earlyExitRange=30 });
  chassis.turnToPoint(29, -23, 1000);
  chassis.moveToPoint(29, -23, 1000);
  intake.run();


  // turn to the second ring
  // chassis.turnToPoint(33, -45.6, 1000, { .minSpeed=30, .earlyExitRange=30 });
  chassis.turnToPoint(33, -45.6, 1000);
  chassis.moveToPoint(33, -45.6, 1000);



  // pickup two rings
  chassis.turnToPoint(3, -49, 3000);
  chassis.moveToPoint(3, -49, 3000, { .maxSpeed=70 });

  // backup for the last ring
  chassis.moveToPoint(11, -49, 3000, { .forwards=false, });

  // pickup last ring
  chassis.turnToPoint(10.5, -56, 1000);
  chassis.moveToPoint(10.5, -56, 1000);
  chassis.waitUntilDone();

  // turn to corner
  chassis.turnToPoint(3, -60, 1000, { .forwards=false });
  // wait for last ring to score
  intake.waitUntilScored(2000);
  chassis.moveToPoint(3, -60, 1000, { .forwards=false });
  // drop the mogo of in the corner
  mogo_ungrab();
  grab = false;
  intake.scored = 0;


  // align with the high stake
  chassis.turnToPoint(56, -44.5, 3000);
  chassis.moveToPoint(35.9, -50.5, 2000, { .minSpeed=80, .earlyExitRange=6 });
  chassis.moveToPoint(56, -44.5, 3000, { .maxSpeed=40 });
  grab = true;

  chassis.turnToHeading(180, 1000, { .minSpeed=20, .earlyExitRange=20 });

  // close to high stake
  chassis.moveToPoint(56.8, -66, 2000, { .maxSpeed=40 });
  lb.move(1);
  lb.waitUntilDone();
  intake.run();
  intake.waitUntilScored(2000);
  intake.stop();
  chassis.waitUntilDone();
  lb.move(4);
  align();
  // reset position
  chassis.setPose(60, -60, chassis.getPose().theta);
  lb.waitUntilDone();


  skillsAfter2HighStake();

}


