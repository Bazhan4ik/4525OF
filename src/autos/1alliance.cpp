#include "main.h"
#include "autos.hpp"
#include "config.hpp"
#include "intake.hpp"


void pick_up_two_rings(int option) {
  // pick up two rings
  chassis.turnToPoint(55, -48.5, 2000);
  chassis.moveToPoint(55, -48.5, 2000, { .maxSpeed=70, });
  intake.run();
  // chassis.turnToPoint(55, -64, 2000, { .minSpeed=10, .earlyExitRange=10 });
  chassis.moveToPoint(54.5, -64, 2000, { .maxSpeed=70 });
  // intake.run();
  // chassis.moveToPoint(50, -62.5, 2000, { .maxSpeed=70, });

  chassis.turnToPoint(42, -61, 1000);
  chassis.moveToPoint(42, -57, 1000);

  if(option == 1) {
    // go to corner
    chassis.moveToPoint(4, -61, 2000, {.maxSpeed=60});
    chassis.waitUntilDone();

    chassis.turnToHeading(-160, 1000);
    pneumatic_robot_extension.set_value(true);

    pros::delay(2000);
    intake.stop();

    return;
  } else if(option == 2) {
    // touch the tower
    chassis.moveToPoint(42, -20, 2000, { .maxSpeed=60 });
  } else if(option == 3) {
    // pick up one more ring and then tower

    chassis.turnToHeading(-25, 1000);

    chassis.turnToPoint(21, -16, 2000, { });
    chassis.moveToPoint(21, -16, 2000, { .minSpeed=80, .earlyExitRange=8 });
    chassis.moveToPoint(12, 1, 2000, { .maxSpeed=40, });

    chassis.turnToPoint(33, -8, 1000);
    chassis.moveToPoint(33, -8, 2000, { .maxSpeed=40, .minSpeed=20 });

  }


}




// 1 - 1  =>  pick up mogo and go for the two rings, then one more and then corner 
// 1 - 2  =>  pick up mogo and go for the two rings, then one more and tower 
// 1 - 3  =>  pick up mogo and go for the two rings, then one more and then one near alliance
//
// 2 - 1  =>  pick up mogo, score one ring continue to awp
// 
void auto_alliance_blue(int option1, int option2) {

  intake.setAlliance('b');

  chassis.setPose(0, 0, 0);

  lb.move(2);
  chassis.moveToPoint(0, -15.5, 2000, { .forwards=false });
  chassis.waitUntil(11);
  lb.move(0);

  // chassis.moveToPoint(10, -36, 2000, { .forwards=false, .minSpeed=50, .earlyExitRange=6 });
  chassis.moveToPoint(15, -43, 2000, { .forwards=false, });

  // pickup mogo
  // chassis.moveToPoint(39, -32.5, 2000, { .forwards=false, .maxSpeed=35, .minSpeed=20, .earlyExitRange=6 });
  // chassis.moveToPoint(20, -32.5, 2000, { .forwards=false, .maxSpeed=65, .minSpeed=20, .earlyExitRange=8 });


  // first ring here:
  chassis.turnToPoint(40, -62, 700, { });
  chassis.moveToPoint(40, -62, 2000, { .minSpeed=60, .earlyExitRange=10 });
  intake.run();
  intake.hold();
  // second ring from the stash
  chassis.moveToPoint(59, -65, 2000, { .maxSpeed=60 });

  // move back to align with mogo
  chassis.moveToPoint(43, -62, 2000, { .forwards=false });

  // grab mogo
  chassis.turnToPoint(39, -36, 2000, { .forwards=false });
  chassis.moveToPoint(39, -36, 2000, { .forwards=false, .maxSpeed=50 });

  // turn to the ring in stash
  // chassis.turnToPoint(56, -52, 1000);
  // chassis.moveToPoint(56, -52, 1000, { .maxSpeed=70 });
  // intake.run();

  // chassis.moveToPoint(39, -36, 2000, { .forwards=false, });


  chassis.turnToPoint(20, -20, 800, {  });
  chassis.moveToPoint(20, -20, 2000, { .minSpeed=70, .earlyExitRange=10 });
  intake.run();
  chassis.moveToPoint(11, -6, 2000, { .maxSpeed=60, });


  // last ring pickup
  chassis.moveToPoint(39, 35, 2000, { });
  chassis.waitUntil(20);
  mogo_ungrab();
  grab = false;
  intake.run(1);

  // mogo pickup
  chassis.turnToPoint(43, 10, 2000, {.forwards=false });
  chassis.moveToPoint(43, 10, 2000, {.forwards=false, .maxSpeed=50 });
  grab = true;
  chassis.waitUntilDone();
  intake.run();
  intake.waitUntilScored(1000);
  chassis.moveToPoint(55, -5, 1000, { .forwards=false, .minSpeed=40 });
  lb.move(1);

  return;
  // chassis.moveToPoint(45, -28.5, 2000, { .forwards=false, .maxSpeed=40, });


  if(option1 == 1) {
    pick_up_two_rings(option2);
    return;
  } else if(option1 == 2) {
    // awp
    // pick up first ring
    chassis.turnToPoint(39, -52, 1000);
    chassis.moveToPoint(39, -52, 1000);
    intake.run();
    chassis.waitUntilDone();
    // pros::delay(400);

    // scored one ring

    // next options:
    //    touch the bar
    //    grab the ring in the middle
    //        touch the bar
    //        proceed with awp
    //    corner clear?


    chassis.turnToPoint(20.5, -17.5, 2000, { .maxSpeed=127 });
    chassis.moveToPoint(20.5, -17.5, 2000, { .maxSpeed=127, .minSpeed=30, .earlyExitRange=8 });
    // chassis.moveToPoint(20.5, -17.5, 2000, { .maxSpeed=50 });

    chassis.waitUntilDone();

    chassis.moveToPoint(14, -4, 1000, { .maxSpeed=40 });
    chassis.waitUntilDone();


    mogo_ungrab();
    grab = false;
    intake.run(1);



    // pickup the second MOGO
    chassis.turnToPoint(44, 15, 1000, { .forwards=false, });
    chassis.moveToPoint(44, 15, 2000, { .forwards=false, .maxSpeed=55 });
    grab = true;

    // pickup the ring
    chassis.turnToPoint(40, 36, 1000, { .minSpeed=20, .earlyExitRange=40 });
    chassis.moveToPoint(40, 36, 1000);
    intake.run();

    chassis.moveToPoint(52, -5, 1000, { .forwards=false, .maxSpeed=70 });
    chassis.waitUntil(30);
    intake.stop();
    // lb.move(1);

  }


}



void red_awp() {
  // pickup ring near alliance
  chassis.turnToPoint(13.7, -23, 2000, { });
  chassis.moveToPoint(13.7, -23, 2000, { .maxSpeed=60 });
  intake.run();

 
  // go for the ring on positive side
  chassis.moveToPoint(47, -65, 2000, { .minSpeed=80, .earlyExitRange=12 });
  chassis.waitUntil(20);
  mogo_ungrab();
  grab = false;
  chassis.moveToPoint(47, -65, 2000, { .maxSpeed=50, });
  intake.run(1);

  // pickup last mogo
  chassis.turnToPoint(48, -38, 2000, { .forwards=false, });
  chassis.moveToPoint(48, -38, 2000, { .forwards=false, .maxSpeed=50 });
  grab = true;

  chassis.waitUntilDone();
  intake.run();

  chassis.moveToPoint(65, -40, 2000, { .maxSpeed=60, .minSpeed=25, });


}
void last_steps_red(int option) {
  if(option == 1) {
    // corner
    chassis.turnToHeading(-45, 1000);
    chassis.moveToPoint(15, 32, 2000, { .maxSpeed=70 });
    pneumatic_robot_extension.set_value(true);
  } else if(option == 2) {
    // tower
    chassis.turnToHeading(135, 1000);
    chassis.moveToPoint(48, -7, 2000, { .maxSpeed=60, });
  } else if(option == 3) {
    chassis.turnToHeading(-135, 1000);

    chassis.moveToPoint(13.5, -23, 3000, { .maxSpeed=60 });
    intake.run();

    chassis.turnToHeading(80, 1000);
    chassis.moveToPoint(32, -20, 2000, { .maxSpeed=60, .minSpeed=25 });
  }
}
void auto_alliance_red(int option1, int option2) {

  intake.setAlliance('r');

  chassis.setPose(0, 0, 0);

  lb.move(2);
  chassis.moveToPoint(0, -15.5, 2000, { .forwards=false });
  chassis.waitUntil(12);
  lb.move(0);

  // pickup ring
  chassis.moveToPoint(40, 30, 2000, { .minSpeed=60, .earlyExitRange=8 });
  // chassis.moveToPoint(40, 30, 2000, { .maxSpeed=50 });
  intake.run();
  intake.hold();
  chassis.moveToPoint(58, 32, 2000, { .minSpeed=60, .earlyExitRange=14});
  chassis.moveToPoint(58, 32, 2000, { .maxSpeed=40, });
  chassis.moveToPoint(40, 32, 2000, { .forwards=false, .maxSpeed=60 });

  // pickup mogo
  chassis.turnToPoint(41, 6, 2000, { .forwards=false, });
  chassis.moveToPoint(41, 6, 2000, { .forwards=false, .maxSpeed=50 });

  chassis.waitUntilDone();
  pros::delay(300);



  if(option1 == 2) {
    // awp
    red_awp();
    return;
  }


  // pickup last ring in the stash
  chassis.turnToPoint(57, 19, 1000);
  chassis.moveToPoint(57, 19, 2000, { .maxSpeed=60 });
  intake.run();

  // move back a little
  chassis.moveToPoint(40, 4, 1000, { .forwards=false});

  if(option1 == 1) {
    last_steps_red(option2);
  }


  pros::delay(2000);
  intake.stop();
  



  
}