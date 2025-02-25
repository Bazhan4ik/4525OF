#pragma once



#include "pros/abstract_motor.hpp"
class IntakeMotors {
private:
  int speed;
  bool reversed;
public:
  IntakeMotors();


  void runChain();
  void runWheels();
  void stopWheels();
  void stopChain();
  void setSpeed(int speed);
  void setReverse(bool value);

  void setBrakeMode(pros::MotorBrake type);


  bool isReversed() { return reversed; }
};

class Intake {

private:

  int mode;
  int alliance; // 0 is sort red, 1 is sort blue 

  bool wheelsAllowed;
  bool chainAllowed;

  IntakeMotors motors;

  int getMode() { return mode; }

public:

  Intake();

  int scored;

  static void taskWrapper(void* instance);

  // main function
  void task();

  // set speed of the whole intake
  void setSpeed(int speed);
  // set intake to reverse
  void setReverse(bool val);

  void run();
  void run(int nochain);
  void stop();

  void setMode(int mode);


  void setAlliance(char alliance);

  void waitUntilScored(int timeout);
};



extern Intake intake;