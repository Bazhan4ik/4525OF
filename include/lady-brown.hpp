



class LadyBrown {

public:

  LadyBrown();

  void move(int position);
  void reset();
  void task();
  void waitUntilDone();

  void setMode(int mode);

  static void taskWrapper(void* instance);

  void brake();

  bool isFinished() {
    return finished;
  }


private:
  int currentPosition;
  int currentTarget;

  bool finished;

  float kD;
  float kP;

  int maxSpeed;

  int previousError;

  int timer;
  bool timerDone;

  int mode;

};


extern LadyBrown lb;


