#BPLROB 001:  Introduction to Robotics
>Instructor Carlos Ambrozak

> Spring 2016

###General Information

####Class Time
Monday 4-530PM

####Classroom Location 
Main Library Tech Lab<br>
480 Primrose Rd.  Burlingame, CA 94010

####Contact Info
Kim Day day@plsinfo.org, Carlos Ambrozak carlos.ambrozak@gmail.com

####Website
https://github.com/cambrozak/bp001

###Teaching and Learning Style

The primary objective of this course is
to inspire middle school students to take an interest in Robotics
regardless of prior skills and experience. 

A broad top-down approach to the overall subject
combined with a hands-on laboratory setting with bottom-up emphasis on select problems
enables students to learn by discovery and be effective with the technology immediately.
This teaching style provides just enough detail to learn foundational concepts
and hold the interest of budding begginers.

Each classroom session follows a Lab-Lecture-Lab format:

A simple lab exercise is completed as a group to start the session.
Students follow along with the instructor to load prewritten software
and wire up components onto the robot and observe resulting physical behavior.
The sesssion does not proceed until every robot is successfuly performing as expected.

A short lecture explains how and why the lab exercise worked and answers open questions.
The lecture also connects the lab exercise to examples in the real world.

A final lab exercise challenges the students to implement their own original ideas
by combiniong the first lab with previous learnings to date.


###Course Description

The field of Robotics is at a fascinating and exciting point in its evolution.
Robots are no longer confined to the realms of industry and research,
they are rapidly becoming a part of daily life.

This course provides Middle School students with an introduction
to fundamental concepts and practical applications of robotic systems
in order to inspire further study and participation in High School and College programs.

Hands-on laboratory exercises provide experience with
embedded systems, programming, circuits, motors, sensors and servos.

Students collaborate on their own autonomous robot platform
to implement dynamic physical behaviors such as:
edge detection, line following, collision detection, orientation, 
proximity sensing, audio & lcd text output, image sensing, servo controlled arm manipulation

Short lectures connect the laboratory exercises 
to current state of the art happenings across the field of Robotics and beyond.


###Prerequisites

None!  This class is for motivated beginners.


###Class Rules

1. Respect each other.
2. Respect the lab.
3. Respect the equipment.


###Objectives and Outcomes

Students and Instructor will...

Introduce each other, get acquainted and understand overall class objectives,
rules and the how each session is structured in Lab-Lecture-Lab format.

Discuss experience with robots in the real world in order to
understand what a robot is and how it relates to general purpose compters and embedded systems.

Know the characteristics of four main classes of robots: Pre-Programmed, Autonomous, Remote and Augmenting.

Employ simple tactics to identify and overcome two major impediments to hi-tech learning: FUD & Buzzwords. 

Write and upload source code programs for execution on a physical robot.

Find and utilize source code program libraries to understand how libraries work and why they are important.

Maintain source code in a versioned repository to understand revision history, forking, branching and pull requests.

Define expressions, syntax, high-level vs. low-level in order to
understand some general fundamentals of programming languages.

Write programs with typical programming forms to control hardware: variables, if/then, loops, functions.

Write programs that use variables in different scopes to 
understand the general concept of scope in programming
and how it is implemented in the C language for Arduino.

Write C programs using Arduino core and third party APIs to control robot hardware 
in order to get experience with and understand the importance of APIs.

Debug programs successfully with Carlos's foolproof 'EIPOC' meta-tactic and various tools.

Use a simulator to test hardware and software offline.
 
Observe how electrons move through a conductor
using a physical marble-madness model
to understand how elecron flow affects circuit components such as lights LEDs and Motors. 

Build a simple battery from scratch to power an LED and probe it with a multimeter
to understand Electric Current in Circuits and how it relates to Voltage and Resistance.

Add cells to the homeade battery and probe with a multimeter
to understand the concept of Parallel and Series circuits
and how these arrangements affect Voltage and Current.

Construct a Reference Circuit on a breadboard composed of a battery power source,
a fuse, a control switch, an LED and Common Ground to explore and understand
and troubleshoot the three types of circuit problems:
Short Circuits, Grounded Circuits and Open Circuits

Short the Reference Circuit on purpose to observe the symptoms of short circuits
and understand how to detect and fix this common problem.
Blow the fuse on purpose in the Reference Circuit to demonstrate saftey concerns
and the real possibility of damaging hardware with short circuits.

Ground the Reference Circuit on purpose to observe the symptoms of grounded circuits
and understand how to detect and fix this common problem.
Blow the fuse on purpose in the Reference Circuit to demonstrate saftey concerns
and the real possibility of damaging hardware with grounded circuits.

Open the Reference Circuit on purpose by breaking the LED to observe the symptoms of open circuits
and understand how to detect and fix this common problem.
Deterimine if it is possible to damage hardware with open circuits.

Provide the robot with an identity by writing a program to store and display
its name and unique ID on a LCD display and play a distinguishing tune with a Piezo Buzzer.

Provide the robot with edge detection awareness by writing programs to process
input from IR LED/Phototransistors and control motor outputs.
This keeps the robot from roaming beyond the test area.

Provide the robot with path finding abilities by writing programs to process
input from IR LED/Phototransistors and control motor outputs.

Provide the robot with free-roaming capabilities and collision detection
by writing programs that process proximity sensors, accelerometer,
gyroscope and compass inputs and control motor outputs.

Provide the robot with an articulated arm by connecting a pan-tilt mechanism to the chassis
and writing programs to control servo movements and point the arm at objects detected by
proximity sensors.

Provide the robot with the sense of sight by attaching an image sensor
to the pan-tilt mechanism and writing programs to react to different image patterns.


###Schedule

**Session One:** Introductions and Class Orientation<br>
**Lecture:**  What's a Robot?  Hi-Tech Learning<br>
**Exercise:**  Give robot a name.  Edit, compile and load a program, LCD and Audio output.  Saving code in GitHub.


**Session Two: Programming I**<br>
**Exercise: Move the Robot, Edge Detection, Program motor control using libraries & APIs.<br>
**Lecture: Expressions, Syntax, Variables, if/then, loops<br>
**Exercise: Turn the Robot, Speed control, orientation with the gyro and compass, move in a pattern.


**Session Three: Programming II<br>
**Exercise: Line following.  Program processing of IR LED/Phototransistor inputs.<br>
**Lecture: Scope, Functions, High Level vs. Low Level Languages, The Art of Debugging<br>
**Exercise: Step-Thru Debugging with Simulator for Arduino

**Session Four: Circuits<br>
**Exercise: Build a Battery from scratch, light an LED, measure Current, Voltage and Resistance with a Multimeter<br>
**Lecture: Electricity in 30min: Electrons, Current, Voltage, Resistance, Series, Parallel, Ground<br>
**Exercise: Build a Reference Circuit using a battery, LED, Switch and Ground.<br>
Debug the three types of circuit failures: Short Circuits, Grounded Circuits, Open Circuits 

**Session Five: Roaming<br>
**Exercise:  Detect collisions with accelerometer, Detect objects in space with proximity sensors.<br>
**Lecture:  Why Accelerometers and proximity sensors work.<br>
**Exercise: Advanced Roaming, navigating terrain, avoiding moving obstacles.


**Session Six: Servo Mechanical Control<br>
**Exercise: Attach Pan-Tilt servo arm to the Robot<br>
**Lecture: Servo safety, how to servos work<br>
**Exercise: Point the servo arm at detected objects

**Session Seven: Pattern Recognition<br>
**Exercise: Attach Pixy CMUcam5 image sensor to servo arm<br>
**Lecture: Image Sensors and Pattern Recognition<br>
**Exercise:  Program robot for follow/flight when it recognizes certain image patterns.

**Session Eight:** Open Lab<br>
**Exercise:** TBD<br>
**Lecture:** TBD<br>
**Exercise:** TBD


###Equipment

All equipment is kept in the lab at all times.

####Laptop
####Software
* [Arduino IDE](https://www.arduino.cc/en/Main/Software)
* [Simulator for Arduino](http://www.virtronics.com.au/Simulator-for-Arduino.html)

####Hardware
[Zumo 32U4](https://www.pololu.com/product/3126/resources)
[Mini Pan-Tilt Arm and Micro Servos](https://www.adafruit.com/products/1967)
[Pixy CMUcam5 Sensor](https://www.adafruit.com/products/1906) 

###Text and Reference Material

Purdum, Jack J. *Beginning C for Arduino* New York: Apress, 2012. Print.

Atmel ATmega32U4(http://www.atmel.com/devices/atmega32u4.aspx)

[Arduino](https://www.arduino.cc/)


##### License & Copyright
![Creative Commons Lcense](https://i.creativecommons.org/l/by/4.0/80x15.png) *BPL001 Introduction to Robotics* by [Carlos Ambrozak](http://bpl001.ambrozak.com)
is licensed under a [Creative Commons Attribution 4.0 International License](http://creativecommons.org/licenses/by/4.0/).
