#include <MotorControl.h>
#include <LineFollower.h>

MotorControl motorcntrl(1,2,3,4,7,5);
LineFollower lineflw(A0,A1,A2,A3,A4,13);
void setup() {
}

void loop() {
  lineflw.line_follower();
}
