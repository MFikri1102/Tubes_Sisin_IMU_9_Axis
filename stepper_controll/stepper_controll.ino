#include <Stepper.h>
#include <Servo.h>

// Stepper Setup
const int stepsPerRevolution = 200;

int base[4] = {8, 9, 10, 11};
int link1[4] = {12, 13, 14, 15};  // Replace with the correct pin numbers
int link2[4] = {16, 17, 18, 19};  // Replace with the correct pin numbers
int grip[4] = {20, 21, 22, 23};  // Replace with the correct pin numbers

Stepper stepper_base(stepsPerRevolution, base[0], base[1], base[2], base[3]);
Stepper stepper_link1(stepsPerRevolution, link1[0], link1[1], link1[2], link1[3]);
Stepper stepper_link2(stepsPerRevolution, link2[0], link2[1], link2[2], link2[3]);
Stepper stepper_grip(stepsPerRevolution, grip[0], grip[1], grip[2], grip[3]);

// Servo Setup
Servo myservo;
int pos = 0;

// Servo control
void move_servo(Servo &servo_name, int pos) {
  servo_name.write(pos);
  delay(15);
}

// Stepper Control
void move_stepper(Stepper &stepper_name, int steps) {
  stepper_name.step(steps);
}

void setup() {
  myservo.attach(9);  // Attach the servo to pin 9
  // Set the speed for the base stepper motor to 60 rpm:
  stepper_base.setSpeed(60);
  // Initialize the serial port:
  Serial.begin(115200);
}

void loop() {
  move_stepper(stepper_base, 20);
  delay(1000);
}
 