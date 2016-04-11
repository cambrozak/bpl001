#Session Five: Advanced Autonomous Roaming: Collision Detection

###Lab: Acelerometer sensor sampling (15min)
####_**Objective: Students get familiar with acceleromters and API for sampling G-Force**_
**Activity:** Students and Instructor write and run code that displays g-force accelerometer data on the LCD<br>

###Lecture: (15min)
####_**Objective: Observe Accelerometer internals, Understand Micro Electro Mechanical Systems**_
**Activity:** Video: [MEMS](https://youtu.be/i2U49usFo10)<br>
**Activity:** Video: [Mass Spring Model, How MEMS are made](https://youtu.be/i2U49usFo10)<br>
**Activity:** Video: [Car Collision Airbag Deployment](https://youtu.be/ObXspXB9sJI)

###Lab: (60min)
####_**Objective: Detect collisions using sudden changes in g-force, Adjust course with a Bump-and-Go algorithm**_
**Activity:** Students and Instructor implement RMS sampling algorithm to detect significant changes in g-force<br>
**Activity:** Students and Instructor integrate motor control code and deploy robots to the test field

###Source Code###
[https://github.com/cambrozak/bpl001/tree/master/session-02](https://github.com/cambrozak/bpl001/tree/master/session-05)<br>
[https://github.com/pololu/lsm303-arduino](https://github.com/pololu/lsm303-arduino#library-reference)<br>
[https://github.com/pololu/zumo-32u4-arduino-library](https://github.com/pololu/zumo-32u4-arduino-library)

###Reference###
[LSM303D Accelerometer Datasheet](https://www.pololu.com/file/download/LSM303D.pdf?file_id=0J703)
[C++ Language Reference for Arduino](https://www.arduino.cc/en/Reference/HomePage)<br>

###Equipment###
* Laptop for Instructor with Arduino IDE and internet access
* Audio, Video, Projector and necessary laptop cables
* Markerboard
* Laptop for each student with Arduino IDE
* Motor, Line Sensor libraries, Source code
* Zumo Robot, one for each student pair
* Batteries
* Micro USB Serial Cable for each Robot
* Black Vinyl Surface
* Foam barrier pads and gaffer tape

<sup><sub>*BPL001 Introduction to Robotics by Carlos Ambrozak* is licensed under a Creative Commons Attribution 4.0 International License.</sub></sup>
