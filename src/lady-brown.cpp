#include "lady-brown.hpp"
#include "config.hpp"
#include "pros/llemu.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"





LadyBrown::LadyBrown() :
  currentPosition(0),
  currentTarget(0),
  finished(true),
  kP(0.031),
  kD(0.055),
  maxSpeed(80),
  previousError(0),
  timerDone(false),
  timer(0),
  mode(0) {}


void LadyBrown::move(int position) {
  timer = pros::millis();
  finished = false;
  
  pros::lcd::print(5, "MOVED");

  // return;

  if(position == 1) {
    maxSpeed = 30;
    currentTarget = 2900;
    lady_brown_arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  } else if(position == 2) {
    maxSpeed = 50;
    currentTarget = 6000;
  } else if(position == 3) {
    currentTarget = 14000;
  } else if(position == 4) {
    // if(mode == 1) {
    //   lady_brown_arm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    //   lady_brown_arm.move(127);
    //   finished = true;
    //   return;
    // }
    maxSpeed = 127;
    currentTarget = 18000;
  } else if(position == 0) {
    // if(mode == 1) {
    //   lady_brown_arm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    //   lady_brown_arm.move(-127);
    //   finished = true;
    //   return;
    // }
    maxSpeed = 80;
    currentTarget = 0;
  }
}

void LadyBrown::brake() {
  if(finished) {
    lady_brown_arm.brake();
  }
}

void LadyBrown::setMode(int newMode) {
  mode = newMode;
}

void LadyBrown::reset() {
  currentPosition = 0;
  rotation_arm.reset();
  rotation_arm.reset_position();
}

void LadyBrown::waitUntilDone() {
  while(true) {
    pros::delay(20);
    if(finished) {
      return;
    }
  }
}

void LadyBrown::task() {
  // lady_brown_arm.move(-127);
  // pros::delay(160);
  // lady_brown_arm.brake();
  reset();
  // finished = true;


  while(true) {
    pros::delay(20);




    if(finished) {
      continue;
    }

    // lady_brown_arm.move(20);

    // continue;

    timerDone = pros::millis() > timer + 1300;
    currentPosition = rotation_arm.get_position();


    int error = currentTarget - currentPosition;
    int derivative = error - previousError;

    double voltage = float(error) * kP + float(derivative) * kD;



    previousError = error;

    printf("LADYBROWN REPORT motorpower: %f  ::: error: %d  ::: currentposition: %d", voltage, error, currentPosition);

    pros::lcd::print(5, "error: %d", currentPosition);
    pros::lcd::print(6, "motorpower: %f", voltage);
    pros::lcd::print(7, "VELOCITY: %d", lady_brown_arm.get_actual_velocity());


    if(voltage> maxSpeed) {
      voltage = maxSpeed;
    } else if(voltage < -maxSpeed) {
      voltage = -maxSpeed;
    }

    if(abs(error) < 150 || timer + 1000 < pros::millis()) {
      lady_brown_arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

      if(currentTarget == 0) {
        lady_brown_arm.move(-50);
        pros::delay(50);
        // reset();
        lady_brown_arm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      }

      lady_brown_arm.brake();

      finished = true;
      previousError = 0;

      continue;
    }

    lady_brown_arm.move(voltage);
  }
}


void LadyBrown::taskWrapper(void* instance) {
  static_cast<LadyBrown*>(instance)->task();
}

LadyBrown lb;