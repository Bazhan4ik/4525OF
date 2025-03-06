#include "main.h"
#include "config.hpp"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "liblvgl/llemu.hpp"
#include "pros/misc.h"
#include "ui/ui.hpp"







void initialize() {
  // ui_init();
  pros::lcd::initialize();

  chassis.calibrate();

  mogo_ungrab();


  pros::Task grabberTask(mogo_grabber);
  pros::Task ladyBrownTask(LadyBrown::taskWrapper, &lb);
  pros::Task intakeTask(Intake::taskWrapper, &intake);

  // lb.init();

  pros::Task backgroundthingstask([&]() {
    while (true) {
      pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
      pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
      pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading


      pros::delay(50);
    }
  });
}

void disabled() {}

void competition_initialize() {}


void autonomous() {
  pneumatic_intake.set_value(true);

  // newest: red alliance stake + mogo 1 ring + mogo 1 ring
  red_pos();



  // BLUE goal rush
  // 2 ring mogo, 1 ring mogo, close to corner
        // auto_goalRush(1);
  // 2 ring mogo, 1 ring mogo, touch the tower 
        // auto_goalRush(2);
  // 1 ring mogo, 1 ring mogo, touch the tower
        // auto_goalRush(3);

// RED goal rush: 2 ring mogo + 1 ring mogo + tower
        // auto_goalRush_red(1, 1);
        // auto_goalRush_red(1, 0); // NO TOWER
// RED goal rush: 1 ring + 1 ring mogo + tower
        // auto_goalRush_red(2, 1);
        // auto_goalRush_red(2, 0); // NO TOWER
 

// awp
          // auto_alliance_blue(2, 1);     // FINISH ALL BLUE
          // auto_alliance_red(2, 1);
// alliance, 3 ring mogo, corner
          // auto_alliance_blue(1, 1);
          // auto_alliance_red(1, 1);
// alliance, 3 ring mogo, tower
          // auto_alliance_blue(1, 2);
          // auto_alliance_red(1, 2);
// alliance, 4 ring mogo, tower
          // auto_alliance_blue(1, 3);
          // auto_alliance_red(1, 3);



// 4 rings + tower
            //  neg_blue(1);
            // neg_red(1);
// 4 rings + corner
            //  neg_blue(2);
            //  neg_red(2);
// 5 rings + tower 
            //  neg_blue(3);
            //  neg_red(3);
// 5 rings + corner
            //  neg_blue(4);
            //  neg_red(4);
  


  

 
  // skills();
}



void opcontrol() {

  pneumatic_intake.set_value(true);


  intake.setMode(1);
  lb.setMode(1);


  // intake.setAlliance('r');

  bool curext = false;

  while (true) {
    int leftY = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightY = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    chassis.tank(leftY, rightY);


    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      mogo_ungrab();
      grab = false;
    } else {
      grab = true;
    }


    if(lb.isFinished()) {
      if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
        intake.setAlliance('n');
      }
      if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        lb.move(1);
      }
      if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
        lb.move(0);
      } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y) || master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
        lb.move(4);
      } else if(lb.isFinished()){
        lb.brake();
      }
    }

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
      lb.reset();
    }

    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
      pneumatic_robot_extension.set_value(true);
    }
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
      pneumatic_robot_extension.set_value(false);
    }


    pros::delay(25);
  }

}
