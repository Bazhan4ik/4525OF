#include "autos.hpp"
#include "intake.hpp"
#include "config.hpp"
#include "lady-brown.hpp"
#include "mogo-grabber.hpp"


void red_pos() {
  intake.setAlliance('r');

  chassis.setPose(0, 0, 0);

  lb.move(2);
  chassis.moveToPoint(0, -15.5, 2000, { .forwards=false });
  chassis.waitUntil(12);
  lb.move(0);

  // move away from the wall
  chassis.moveToPoint(7, -42, 2000, { .forwards=false, });

  // grab first mogo
  chassis.turnToPoint(40, -37, 2000, { .forwards=false });
  chassis.moveToPoint(40, -37, 2000, { .forwards=false, .maxSpeed=55  });
  chassis.waitUntilDone();

  // first ring
  chassis.turnToPoint(40, -59, 2000);
  chassis.moveToPoint(40, -59, 2000);
  intake.run();

  chassis.turnToHeading(90, 1000);

  chassis.moveToPoint(24, -60, 2000, { .forwards=false });
  mogo_ungrab();
  grab = false;
  intake.stop();

  chassis.waitUntilDone();
  chassis.moveToPoint(30, -59.5, 2000, { .forwards=false });

  chassis.turnToHeading(-90, 1000);

  // grab second mogo
  chassis.moveToPoint(52, -59.5, 2000, { .forwards=false, .maxSpeed=40 });
  grab = true;
  chassis.waitUntilDone();
  pros::delay(400);

  chassis.moveToPoint(24, -32, 2000, { .minSpeed=80, .earlyExitRange=10 });
  intake.run();
  chassis.moveToPoint(11, 5, 5000, { .maxSpeed=45 });
  chassis.moveToPoint(18, -32, 2000, { .forwards=false });

}