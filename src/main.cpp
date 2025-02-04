#include "main.h"
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

  // auto_5Rings();
  // auto_goalRush();

  // auto_awp_safe();

  // return;
  // skills();
  // auto_goalRush();

  auto_red_goalRush();
  return;
  auto_red_awp_5Rings();
  return;
  auto_red_5Rings();
  return;
  auto_5Rings();
  return;
  // USABLE
  auto_awp_5Rings();
  return;
  // USABLE
  auto_awp_safe();
  return;
  // USABLE
  auto_goalRush();
  return;
  // USABLE
  auto_awp_goalRush();
  return;

  
  skills();
}



void opcontrol() {
  pneumatic_intake.set_value(true);
  intake.setMode(1);
  lb.setMode(1);

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
      if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) || master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        lb.move(1);
      }
      if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
        lb.move(0);
      } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
        lb.move(4);
      } else if(lb.isFinished()){
        lb.brake();
      }
    }

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
      lb.reset();
    }

    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
      curext = !curext;
      pneumatic_robot_extension.set_value(curext);
    }


    pros::delay(25);
  }

}
