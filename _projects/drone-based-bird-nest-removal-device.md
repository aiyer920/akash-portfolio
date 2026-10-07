---
layout: project
title: "Drone Based Bird Nest Removal Device"
description: "In this project I programmed, designed, and built a device that attaches to a drone and breaks and removes nests from power lines."
date: 2026-10-01
categories: [Arduino, Solidworks, 3D Printing, Sensors, Manual Machining]
featured_image: "/assets/images/projects/umd-capstone/Group_C5_Photo_4.jpg"

models:
  - file: "/assets/models/umd-capstone/full-assembly.glb"
    description: "Full assembly of the drone based bird nest removal device"

gallery:
  - type: "video"
    file: "/assets/images/projects/umd-capstone/capstone.mp4"
    description: "Bird nest removal device demonstration"
  - type: "image"
    file: "/assets/images/projects/umd-capstone/Group_C5_Photo_4.jpg"
    description: "Capstone project group photo"

code_files:
  - name: "Arduino Device Control"
    file: "ENME472FullCodeNew.ino"
    language: "cpp"
    download_path: "/scripts/umd-capstone/ENME472FullCodeNew.ino"
    content: |
      #include <Servo.h>
      #define CLK 11
      #define DT 10
      #define SW 9
      unsigned long lastRemoteRead = 0;
      const unsigned long remoteInterval = 200;
      int counter2=0;
      int currentStateCLK;
      int lastStateCLK;
      String currentDir = "";

      Servo servoLock;
      int servPin = 4;
      int angleLock = 73
      ; //greater angle lifts J lock higher, less angle brings it lower, angleLock 71, angleRelease 145 for og servo
      int angleRelease = 145;

      int remote = A0;
      int revolutions = 0;
      const int DCforward = 8;    //Pin connected to H bridge input 2
      const int DCbackward = 12;  //Pin connected to H bridge input 1
      int delayTime = 2000;
      int counter=0;

      void setup() {
        // put your setup code here, to run once:
        servoLock.attach(servPin);
        pinMode(DCforward, OUTPUT);
        pinMode(DCbackward, OUTPUT);
        pinMode(CLK, INPUT);
        pinMode(DT, INPUT);
        pinMode(SW, INPUT_PULLUP);
        Serial.begin(9600);  // Initialize serial communication for debugging (optional)
        lastStateCLK = digitalRead(CLK);
        servoLock.write(angleRelease);
      }

      void loop() {
        unsigned long currentMillis = millis();
        if (currentMillis - lastRemoteRead >= remoteInterval) {
          lastRemoteRead = currentMillis;

          int remoteVal = analogRead(remote);
          if (remoteVal < 512) {
            counter++;
        }
      }
        TapSensor(counter);
        if (counter==1) {
          int MotorState = MoveMotor(counter);
          int ServoState = MoveServo(counter);
        }
        if (counter==2){
          digitalWrite(DCforward, LOW);
          digitalWrite(DCbackward, LOW);
        }
      
        if (counter==3) {
          int ServoState = MoveServo(counter);
          if (ServoState == 1) {
          }
          counter=0;
        }
      
      }

      int TapSensor(int RF) {
      
        // Read the current state of CLK
        currentStateCLK = digitalRead(CLK);

        // If last and current state of CLK are different, then pulse occurred
        // React to only 1 state change to avoid double count
        if (currentStateCLK != lastStateCLK && currentStateCLK == 1) {

          // If the DT state is different than the CLK state then
          // the encoder is rotating CCW so decrement
          if (digitalRead(DT) != currentStateCLK) {
            counter2++;
            currentDir = "CCW";
          } else {
            // Encoder is rotating CW so increment
            counter2++;
            currentDir = "CW";
          }
          if (counter2 % 20 == 0){
            revolutions++;
          }
        }
        // Remember last CLK state
        lastStateCLK = currentStateCLK;

        // Put in a slight delay to help debounce the reading
        delay(1);
      }

      int MoveMotor(int RF) {
        int maxWind = 5;
        if (revolutions < maxWind) {
          digitalWrite(DCforward, HIGH);
          digitalWrite(DCbackward, LOW);
          return 0;
        }
        if (revolutions == maxWind) {
          digitalWrite(DCforward, LOW);
          digitalWrite(DCbackward, LOW);
          delay(delayTime);
          revolutions++;
          return 1;
        }
        if (revolutions > maxWind && revolutions < 2 * maxWind + 1) {
          digitalWrite(DCforward, LOW);
          digitalWrite(DCbackward, HIGH);
          return 2;
        }
        if (revolutions == 2 * maxWind + 1) {
          digitalWrite(DCforward, LOW);
          digitalWrite(DCbackward, LOW);
          return 3;
        }
      }


      int MoveServo(int RF) {
        float lock = 4;
        if (revolutions == lock) {
          servoLock.write(angleLock);
          return 0;
        }
        if (counter==3) {
          servoLock.write(angleRelease);
          revolutions = 0;
          return 1;
        }
      }
---

## Overview

For my mechanical engineering capstone, my group and I developed a drone mounted bird nest removal prototype for Baltimore Gas and Electric (BGE). The project explored an alternative to sending technicians up to utility poles to remove nests by hand. I contributed to programming, mechanical design, and building the device, integrating a remotely controlled mechanism with a drone-carried payload. Our device used spring loaded arms to cut nest material with a net to collect broken pieces. We tested induvidual subsystems before conducting field trials with BGE's drone and a mock nest on a mock utility pole. 

## Key Features
One of the main components of our device is the spring powered actuator that uses torsional springs to store energy for the arm to swing and motor driven cable that resets the mechanism between attempts. Another component is the servo operated J lock that holds the raised arms so the cable can unwind before release and avoid backdriving the motor during the swing. Our device also operates remotely with an Arduino based controller that coordinates the DC motor and servo from RF commands. Component testing demonstrated remote operation at distances of at least 200 feet. A scooper pushes broken nest pieces into a net and the whole attachment is hung from 3 cables which attaches to the drone. 

## Design

We developed the SolidWorks assembly around four connected subsystems: the spring loaded cutting frame, the motor and pulley mechanism, the electronics and remote control, and the housing. Two torsion springs drove arms mounted on a bearing-supported shaft. The arms pressed branches against bladed wedges, while a scooper on the same shaft directed material toward a collection bag. A motor-driven cable raised the arms, and a servo-operated J-lock held them while the motor unwound before release. The housing supported the mechanism and provided a sliding lid for access to the electronics and attachment to the drone.

The spring and motor selections were closely linked: the springs needed enough stored energy to break branches, but the motor still had to wind them within the payload and cycle-time constraints. We used a parametric study of branch bending and shear to examine the effects of stick diameter, spring stiffness, arm geometry, and wedge mechanical advantage. The analysis supported combining bending and cutting with repeated swings, rather than expecting every branch to break in one impact.

Structural analysis informed the housing and frame design. A simplified static FEA of the housing lid slot under a 2 lb load predicted a maximum von Mises stress of 0.1493 MPa and a maximum displacement of 0.1601 mm. These were simulation results for the modeled load case; printed infill and real loading still required physical validation. A separate frame study supported adding diagonal braces behind the vertical members to resist branch-contact loads.

## Manufacturing

We used 3D printing to develop and revise custom parts before integrating them with purchased motors, springs, bearings, and fasteners. An early scaled frame prototype incorporated blade slots and net attachment hooks, allowing us to test component fit and the spring-powered cutting concept. The later prototype used a wooden frame and a revised wedge arrangement, so the behavior of the printed prototype could not fully establish the final frame's structural performance.

We used PLA for the housing, scooper, J-lock, motor mount, main pulley, pulley support, and axle mount, with ABS for the shaft-to-arm connectors. Drilling, tapping, sawing, and milling was done to manufacture the aluminum wedges. We drilled the mounting and blade holes, tapped the blade fastener holes, milled the recessed features, and made the initial diagonal cut with a horizontal band saw before finishing it on the mill. Assembly integrated the shaft, bearings, springs, printed components, cable routing, and electronics. Repeated testing exposed the need for stronger frame materials and connections that would make repairs and design changes easier.

## Sensing and Software

I programmed an Arduino-based controller that integrates RF remote commands, rotary-encoder feedback, a DC lifting motor, and a servo-operated J-lock. The operator initiates the mechanism remotely, while the controller coordinates cable winding, locking, unwinding, and release. An H-bridge controls the lifting motor's direction, and the servo positions the lock to hold or release the spring-loaded arms.

The rotary encoder provides CLK and DT signals for tracking rotation. Rotation counts provide an indirect estimate of cable travel and determine when the motor and servo advance through the sequence. The operating sequence begins by winding the cable to raise the arms and load the torsion springs. At four counted revolutions, the controller commands the servo to engage the J-lock. At five revolutions, it stops the motor for two seconds before reversing to unwind the cable while the arms remain locked. The motor stops when the unwinding threshold is reached. The remote command sequence also includes a motor-stop stage and a release stage, which moves the servo out of the way so the springs can drive the arms downward and resets the cycle counters. The final Arduino implementation is available below in Code Files.
