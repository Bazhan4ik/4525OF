#include "intake.hpp"
#include "config.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/llemu.hpp"
#include "pros/misc.h"




IntakeMotors::IntakeMotors() : speed(127), reversed(false) { }

Intake::Intake() {
  wheelsAllowed = false;
  chainAllowed = false;
  mode = 0;
  IntakeMotors motors;
}



void IntakeMotors::runChain() {
  intake_chain.move(reversed ? -speed : speed);
}
void IntakeMotors::runWheels() {
  intake_stage1.move(reversed ? -speed : speed);
}
void IntakeMotors::stopChain() {
  intake_chain.brake();
}
void IntakeMotors::stopWheels() {
  intake_stage1.brake();
}
void IntakeMotors::setBrakeMode(pros::MotorBrake type) {
  intake_chain.set_brake_mode(type);
  intake_stage1.set_brake_mode(type);
}
void IntakeMotors::setSpeed(int speed) {
  speed = speed;
}
void IntakeMotors::setReverse(bool value) {
  reversed = value;
}





void Intake::setSpeed(int speed) {
  motors.setSpeed(speed);
}
void Intake::setReverse(bool value) {
  motors.setReverse(value);
}

void Intake::setMode(int m) {
  mode = 1;
}


void Intake::run() {
  wheelsAllowed = true;
  chainAllowed = true;
}
void Intake::run(int nochain) {
  wheelsAllowed = true;
  chainAllowed = false;
}
void Intake::stop() {
  wheelsAllowed = false;
  chainAllowed = false;
}







void Intake::task() {
  opticalSensor.set_integration_time(15);
  opticalSensor.set_led_pwm(99);

  bool sortRingDetected = false;

  while(true) {


    if(ringDetector.get_value()) {
      pros::lcd::print(7, "PRESSED");
    } else {
      pros::lcd::print(7, "NO");
    }

    


    // if driver control
    if(mode == 1) {
      // if a intake button is pressed
      if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) || master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
          intake.setReverse(true);
        } else {
          intake.setReverse(false);
        }
        run();
      } else {
        stop();
      }
    }


    if(wheelsAllowed) {
      motors.runWheels();
    } else {
      motors.stopWheels();
    }
    if(chainAllowed) {
      motors.runChain();
    } else {
      motors.stopChain();
    }

    pros::delay(15);
  }


}

void Intake::taskWrapper(void* instance) {
  static_cast<Intake*>(instance)->task();
}


Intake intake;