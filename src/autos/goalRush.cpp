#include "config.hpp"
#include "main.h"
#include "autos.hpp"
#include "pros/motors.h"












void finish_with_alliance() {
  // if scoring on the alliance stake, get rid of the mogo
  chassis.turnToPoint(28, -4.5, 1000);
  chassis.waitUntilDone();
  mogo_ungrab();
  // if scoring on alliance stake move a little closer
  // to the wall to push the red ring away 
  chassis.moveToPoint(27, -4, 1000);
  chassis.turnToHeading(0, 1000);

  // align with the alliance stake
  chassis.moveToPoint(27.1, -10, 1000, {.forwards=false, .minSpeed=40});
  chassis.waitUntilDone();
  align_bwd();

  intake.run();
  intake.waitUntilScored(1000);
  intake.stop();

  chassis.moveToPoint(30, -6, 1000);

  chassis.turnToPoint(49, -1, 2000, { });
  chassis.moveToPoint(49, -1, 2000, { .maxSpeed=60 });
  intake.run();
  chassis.moveToPoint(30, -1, 2000, { .forwards=false });
  // pick up mogo
  chassis.turnToPoint(-13, 36.5, 3000, { .forwards=false, });
  chassis.moveToPoint(-13, 36.5, 3000, { .forwards=false, .maxSpeed=60 });


  return;
}
void go_to_corner() {

  // if not grabbed remain there to grab it after autos
  if(!grabbed) {
    intake.stop();
    return;
  }


  // go to the corner
  chassis.turnToPoint(-27.7, -4.7, 1000);
  chassis.moveToPoint(-27.7, -4.7, 2000, { });
  intake.run();
}
void go_to_tower() {
  if(grabbed) {
    intake.run();
  }
  chassis.moveToPoint(11, 28, 2000, { .maxSpeed=40 });
  pros::delay(3000);
  intake.stop();
}


// 1  ->  2 ring mogo + 1 ring mogo + corner
// 2  ->  2 ring mogo + 1 ring mogo + tower
// 3  ->  1 ring mogo + 1 ring mogo + alliance + tower

void auto_goalRush(int opt1) {
  intake.setAlliance('b');

  // Y LOOKS TO THE MIDDLE OF THE FIELD
  // SO X IS SIDEWAYS, NOT LIKE SKILLS
  chassis.setPose(0,0, -24.7);


  // grab the mogo + move back
  chassis.moveToPoint(-13.7, 31, 2000);
  pneumatic_robot_extension.set_value(true);
  intake.run(1);
  chassis.waitUntil(30.5);
  pneumatic_robot_extension.set_value(false);
  chassis.moveToPoint(-8, 19, 1000, { .forwards=false, .maxSpeed=60 });
  chassis.waitUntilDone();
  // let go of the mogo
  pneumatic_robot_extension.set_value(true);





  // move back a little so that extension doesnt lift mogo up
  chassis.moveToPoint(-3.7, 13, 1000, { .forwards=false });
  chassis.waitUntilDone();
  pneumatic_robot_extension.set_value(false);


  // grab first mogo
  chassis.turnToPoint(6, 26, 2000, { .forwards=false });
  chassis.moveToPoint(6, 26, 2000, { .forwards=false, .maxSpeed=45 });

  while(true) {
    if(grabbed || !chassis.isInMotion()) {
      pros::delay(300);
      break;
    }
    pros::delay(25);
  }
  chassis.cancelMotion();


  // pickup preload
  chassis.turnToPoint(9, 6.2, 1000);
  chassis.moveToPoint(9, 6.2, 1000);
  intake.run();
  if(opt1 == 3) {
    intake.waitUntilScored(1000);
    intake.run(1);

    chassis.turnToHeading(0, 1000);
    chassis.waitUntilDone();
    mogo_ungrab();

    chassis.moveToPoint(9, 9.7, 1000);
    chassis.turnToPoint(-11, 33.7, 2000, { .forwards=false });
    chassis.moveToPoint(-8, 30, 2000, { .forwards=false, .maxSpeed=40 });
    grab = true;
    chassis.waitUntilDone();

    chassis.moveToPoint(7, 26, 2000, { .maxSpeed=50, .minSpeed=20 });

    intake.run();
    pros::delay(1000);

    lb.move(3);
  }

  if(opt1 == 3) {
    return;
  }


  // pick up the ring in front of alliance stake
  chassis.turnToPoint(25, 2.5, 1000);
  chassis.moveToPoint(25, 2.5, 1000);


  // pickup the ring in front of alliance stake
  chassis.moveToPoint(37, 2.5, 1000);
  intake.waitUntilScored(1000);
  intake.run(1);
  chassis.turnToHeading(20, 1000);
  chassis.waitUntilDone();
  mogo_ungrab();
  grab = false;
  pros::delay(200);

  // pickup second mogo that was rushed for
  chassis.turnToPoint(-12, 30, 1000, { .forwards=false, });
  grab = true;
  givetime = true;
  chassis.moveToPoint(-12, 30, 5000, { .forwards=false, .maxSpeed=55, .minSpeed=25 });

  while(true) {
    if(grabbed || !chassis.isInMotion()) {
      pros::delay(200);
      break;
    }
    pros::delay(25);
  }
  chassis.cancelMotion();

  if(opt1 == 1) {
    go_to_corner();
  } else if(opt1 == 2) {
    go_to_tower();
  } else if(opt1 == 3) {

  }
  
  
}


void auto_goalRush_red(int opt1, int opt2) {
  intake.setAlliance('r');
  chassis.setPose(0, 0, 67);

  // rush for mogo
  chassis.moveToPoint(36.64, 12.63, 2000, {});
  pneumatic_robot_extension.set_value(true);
  intake.run(1);
  chassis.waitUntil(29);
  pneumatic_robot_extension.set_value(false);

  // move back from mogo
  chassis.moveToPoint(17, 7, 10000, { .forwards=false, .maxSpeed=70 });
  chassis.waitUntilDone();

  pneumatic_robot_extension.set_value(true);
  pros::delay(300);

  // turn to pick up mogo
  chassis.turnToPoint(27.5, 38, 2000, { .forwards=false, });

  pros::delay(300);
  pneumatic_robot_extension.set_value(false);

  // grabbing mogo
  chassis.moveToPoint(24, 40, 2000, { .forwards=false, .maxSpeed=50 });
  chassis.waitUntilDone();

  if(grabbed) {
    chassis.moveToPoint(26, 35, 1000);

    intake.run();
    pros::delay(400);
    // intake.waitUntilScored(600);
    if(opt1 == 1) {
      // if we are going for third ring, put two on this mogo
      intake.waitUntilScored(1000);
    } else {
      // if we are not picking up a third ring, separate them 3 + 3 points
      intake.stop();
    }

    mogo_ungrab();
    pros::delay(200);
    grab = false;
  }

  // grabbing second mogo
  chassis.moveToPoint(14.5, 6, 1500, { .maxSpeed=60 });
  chassis.turnToPoint(36, 7.6, 1000, { .forwards=false });
  chassis.moveToPoint(35, 7.6, 1000, { .forwards=false, .maxSpeed=45 });
  grab = true;
  givetime = true;
  while(true) {
    if(grabbed || !chassis.isInMotion()) {
      chassis.cancelMotion();
      left_motors.brake();
      right_motors.brake();
      pros::delay(400);
      break;
    }
    pros::delay(20);
  }

  if(!grabbed) {
    chassis.moveToPoint(26, 7.6, 1000, { .forwards=false, .maxSpeed=45 });
  }


  if(opt1 == 1) {
    // pickup third ring
    chassis.turnToHeading(-39, 1000);

    chassis.moveToPoint(3, 49, 2000, { .minSpeed=70, .earlyExitRange=13 });
    intake.run();
    chassis.moveToPoint(-8, 64, 2000, { .maxSpeed=50, });
    chassis.waitUntilDone();
    if(opt2 == 1) {
      // touch tower
      intake.waitUntilScored(1000);
      chassis.turnToHeading(90, 1000);
      chassis.moveToPoint(10, 65, 2000, { .maxSpeed=60, .minSpeed=25 });
    }
  } else if (opt1 == 2) {
    // if two mogos one ring, score now
    intake.run();

    //proceed to tower 
    if(opt2 == 1) {
      chassis.turnToPoint(40, 33, 1000);
      chassis.moveToPoint(40, 35, 3000, { .maxSpeed=60, .minSpeed=25});
      lb.move(4);
    }

  }

  // if the mogo didn't grab try grabbing the rushed for mogo

  

}