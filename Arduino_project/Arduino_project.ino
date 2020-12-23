
#include <AFMotor.h>
#include <Servo.h> 
#include <NewPing.h>

#define TRIG_PIN A4 // Pin A4 on the Motor Drive Shield soldered to the ultrasonic sensor
#define ECHO_PIN A5 // Pin A5 on the Motor Drive Shield soldered to the ultrasonic sensor
#define MAX_DISTANCE 200 // sets maximum useable sensor measuring distance to 200cm
#define MAX_SPEED 180 // sets speed of DC traction motors to 180/256 or about 70% of full speed - to get power drain down.
#define MAX_SPEED_OFFSET 40 // this sets offset to allow for differences between the two DC traction motors ****** from 20
#define COLL_DIST 35 // sets distance at which robot stops and reverses to 10cm
#define TURN_DIST COLL_DIST+10 // sets distance at which robot veers away from object (not reverse) to 20cm (10+10)
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); // sets up sensor library to use the correct pins to measure distance.

AF_DCMotor motor1(1, MOTOR12_1KHZ); // create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
AF_DCMotor motor2(2, MOTOR12_1KHZ); // create motor #2, using M2 output, set to 1kHz PWM frequency
Servo myservo;  // create servo object to control a servo 

int leftDistance, rightDistance, FrontDistance; //distances on either side
int curDist = 0;
String motorSet = "";
int speedSet = 0;


//-------------------------------------------- SETUP LOOP ----------------------------------------------------------------------------
void setup() {
 myservo.attach(9);  // attaches the servo on pin 9 (SERVO_2 on the Motor Drive Shield to the servo object 
 myservo.write(70); // tells the servo to position at 90-degrees ie. facing forward.
 delay(1000); // delay for one seconds
 
}
//------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------MAIN LOOP ------------------------------------------------------------------------------
void loop() {
 myservo.write(70);  // move eyes forward
 delay(90);
 curDist = readPing();   // read distance
 if (curDist< COLL_DIST) {
  changePath();
 }// if forward is blocked change direction
 
delay(500);
}
//-------------------------------------------------------------------------------------------------------------------------------------

void changePath() {
 moveStop();   // stop forward movement
 myservo.write(30);  // check distance to the right
   delay(1000);
   rightDistance = readPing(); //set right distance
   delay(1000);
   myservo.write(156);  // check distace to the left
   delay(1000);
   leftDistance = readPing(); //set left distance
   delay(1000);
   myservo.write(70); //return to center
   FrontDistance = readPing(); //read front distance
   delay(1000);
   compareDistance();
 }


 
void compareDistance()   // find the longest distance
{
 if (FrontDistance>50 )
 {
  moveForward();
 }
  else if (rightDistance<COLL_DIST) //if right is less obstructed
 {
   turnLeft();
 }

  else if (leftDistance<COLL_DIST) //if left is less obstructed 
 {
   turnRight();
 }

  else //if they are equally obstructed
 {
   turnAround();
 }
}


//-------------------------------------------------------------------------------------------------------------------------------------

int readPing() { // read the ultrasonic sensor distance
 delay(70);   
 unsigned int uS = sonar.ping();
 int cm = uS/US_ROUNDTRIP_CM;
 return cm;
}
//-------------------------------------------------------------------------------------------------------------------------------------
void moveStop() {motor1.run(RELEASE); motor2.run(RELEASE);}  // stop the motors.
//-------------------------------------------------------------------------------------------------------------------------------------
void moveForward() {
   motorSet = "FORWARD";
   motor1.run(FORWARD);      // turn it on going forward
   motor2.run(FORWARD);      // turn it on going forward
 for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=10) // slowly bring the speed up to avoid loading down the batteries too quickly
 {
   motor1.setSpeed(speedSet);
   motor2.setSpeed(speedSet);
   delay(5);
 }
}
//-------------------------------------------------------------------------------------------------------------------------------------
void moveBackward() {
   motorSet = "BACKWARD";
   motor1.run(BACKWARD);      // turn it on going forward
   motor2.run(BACKWARD);     // turn it on going forward
 for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=10) // slowly bring the speed up to avoid loading down the batteries too quickly
 {
   motor1.setSpeed(speedSet);
   motor2.setSpeed(speedSet);
   delay(5);
 }
}  
//-------------------------------------------------------------------------------------------------------------------------------------
void turnRight() {
 motorSet = "RIGHT";
 motor1.run(FORWARD);      // turn motor 1 forward
 motor2.run(BACKWARD);  // turn motor 2 backward
 motor2.setSpeed(speedSet+MAX_SPEED_OFFSET);
 delay(1200); // run motors this way for 400ms
 motorSet = "FORWARD";
 motor1.run(FORWARD);      // set both motors back to forward
 motor2.run(FORWARD);      
}  
//-------------------------------------------------------------------------------------------------------------------------------------
void turnLeft() {
 motorSet = "LEFT";
 motor1.run(BACKWARD);     // turn motor 1 backward
 motor2.run(FORWARD);     // turn motor 2 forward
 motor1.run(speedSet+MAX_SPEED_OFFSET);
 delay(1200); // run motors this way for 400ms
 motorSet = "FORWARD";
 motor1.run(FORWARD);      // turn it on going forward
 motor2.run(FORWARD);      // turn it on going forward
}  
//-------------------------------------------------------------------------------------------------------------------------------------
void turnAround() {
 motorSet = "RIGHT";
 motor1.run(FORWARD);      // turn motor 1 forward
 motor2.run(BACKWARD);     // turn motor 2 backward
 motor2.run(speedSet+MAX_SPEED_OFFSET);
 delay(1500); // run motors this way for 800ms
 motorSet = "FORWARD";
 motor1.run(FORWARD);      // set both motors back to forward
 motor2.run(FORWARD);      
}
