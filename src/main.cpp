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


  // safe awp
  //    score alliance
  //    score right mogo: 1
  //    score left mogo: middle ring + one more 


  

  

  return;

  // double ring side
  intake.setAlliance('r');

  chassis.setPose(0, 0, 28.3);

  chassis.moveToPoint(-16, -29, 2000, { .forwards=false, .maxSpeed=50 });

  chassis.turnToHeading(135, 1000);

  chassis.moveToPoint(-2.5, -45.5, 1000);
  intake.run();

  chassis.moveToPoint(-3, -44, 1000, { .forwards=false });


  chassis.turnToPoint(8.5, -46, 1000);
  chassis.moveToPoint(8.5, -46, 1000);

  chassis.moveToPoint(-3, -42, 1000, { .forwards=false });

  chassis.turnToPoint(6, -33, 1000);
  chassis.moveToPoint(6, -33, 1000);



  


  return;


  auto_goalRush();

  return;

 
  skills();
}



void opcontrol() {
  // pneumatic_intake.set_value(true);
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
