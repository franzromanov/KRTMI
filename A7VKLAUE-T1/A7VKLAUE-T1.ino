#include<AFMotor.h>
#include <Servo.h>

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
//gripper
Servo claw,gripf,hand;

 
char command; 

void setup(){      
  Serial.begin(9600);
  
claw.attach(10);
gripf.attach(9);
hand.attach(8);

claw.write(50);
gripf.write(15);
hand.write(0);
 
}
void loop() {
  Serial.println(command);
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop();

    switch(command){
    case 'B':  
      forward();
      break;
    case 'F':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    case 'G':
      forward_leftturn();
      break;
    case 'I':
      forward_rightturn();
      break;
    case 'H':
      backward_leftturn();
      break;
    case 'J':
      backward_rightturn();
      break;
    case 'q':
      rotate();
      break;
      //gripper
      //frontlight
     case 'W':
      gripf_rot();
      break;
     case 'w':
      gripf_norm();
      break;
      //backlight
     case 'U':
      claw_open();
      break;
     case 'u':
      claw_norm();
      break;
      //horns
     case 'V':
      hand_up();
      break;
     case 'v':
      hand_norm();
      break;
    }
  } 
}


void forward()
{
  motor1.setSpeed(500); 
  motor1.run(FORWARD); 
  motor2.setSpeed(500); 
  motor2.run(FORWARD); 
  motor3.setSpeed(500);
  motor3.run(FORWARD); 
  motor4.setSpeed(500);
  motor4.run(FORWARD); 
}
 
void back()
{
  motor1.setSpeed(500); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(500); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(500); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(500); 
  motor4.run(BACKWARD); 
}
 
void left()
{
  motor1.setSpeed(100); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(1000); 
  motor2.run(FORWARD); 
  motor3.setSpeed(100);
  motor3.run(BACKWARD);  
  motor4.setSpeed(1000); 
  motor4.run(FORWARD); 
}
 
void right()
{
  motor1.setSpeed(1000); 
  motor1.run(FORWARD); 
  motor2.setSpeed(100); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(1000); 
  motor3.run(FORWARD); 
  motor4.setSpeed(100); 
  motor4.run(BACKWARD); 
} 

void forward_leftturn()
{
  motor1.setSpeed(0); 
  motor1.run(RELEASE); 
  motor2.setSpeed(1000); 
  motor2.run(FORWARD); 
  motor3.setSpeed(1000); 
  motor3.run(FORWARD); 
  motor4.setSpeed(0); 
  motor4.run(RELEASE); 
}

void forward_rightturn()
{
  motor1.setSpeed(1000); 
  motor1.run(FORWARD); 
  motor2.setSpeed(0); 
  motor2.run(RELEASE); 
  motor3.setSpeed(0); 
  motor3.run(RELEASE); 
  motor4.setSpeed(1000); 
  motor4.run(FORWARD); 
}

void backward_leftturn()
{
  motor1.setSpeed(1000); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(0); 
  motor2.run(RELEASE); 
  motor3.setSpeed(0); 
  motor3.run(RELEASE); 
  motor4.setSpeed(1000); 
  motor4.run(BACKWARD); 
}

void backward_rightturn()
{
  motor1.setSpeed(0); 
  motor1.run(RELEASE); 
  motor2.setSpeed(1000); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(1000); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(0); 
  motor4.run(RELEASE); 
}

void rotate()
{
  motor1.setSpeed(1000); 
  motor1.run(FORWARD); 
  motor2.setSpeed(1000); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(1000); 
  motor3.run(FORWARD); 
  motor4.setSpeed(1000); 
  motor4.run(BACKWARD); 
}


void Stop()
{
  motor1.setSpeed(0); 
  motor1.run(RELEASE); 
  motor2.setSpeed(0); 
  motor2.run(RELEASE); 
  motor3.setSpeed(0); 
  motor3.run(RELEASE); 
  motor4.setSpeed(0); 
  motor4.run(RELEASE); 
}

void gripf_norm(){
  gripf.write(15);
}
void gripf_rot(){
  gripf.write(110);
}

void claw_norm(){
  claw.write(50);
}
void claw_open(){
  claw.write(100);
}
void hand_norm(){
  hand.write(0);
}
void hand_up(){
  hand.write(20);
}
