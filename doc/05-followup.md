There were lots of great questions, observations and dialog in this
session, and I have to admit that I thought the material might be a little
boring and I'm grateful to everyone for contributing to the discussion to
liven it up and dive deeper into related topics such as Calibration and Bus
systems.

We covered just two devices: Magnetometers and Gyroscopes.  These are used
to control position in space and they are found in everything from phones,
cars, planes, spacecraft and of course Robots.

**Gyroscope**

At first [glance](https://www.pololu.com/picture/view/0J6721), these look
like just another black chip on the board, and in studying the software
[interface](https://github.com/pololu/lsm303-arduino) we find just a few
functions available such as ready(), heading() and data access to x, y, z
values.  It doesn't seem like much, but if we [zoom into this chip](https://youtu.be/XsjvaYAFN1M) we see that it's a mechanical device that is
always in motion!  We saw firsthand running the [RotationResist](https://github.com/pololu/zumo-32u4-arduino-library/tree/master/examples/RotationResist)
example program that the robot could use the gyro to stubbornly resist our
attempts to physically turn it, even if we picked it up off the table.
Just like the large [Atlas](https://www.youtube.com/watch?v=rVlhMGQgDkY)
robot that we saw resisting hockey stick pushes in the video.

Here's a link to buy the gyroscope that was in the [video](https://www.youtube.com/watch?v=cquvA_IpEsA), they're only about $10 and
I'll be picking one up myself :)
http://amzn.com/B000FGKHZ2

**Magnetometer**

We wrote code together as a group to access the Magnetometer and print a
heading value to the LCD screen.  We used the familiar [Zumo32U4.h](https://github.com/pololu/zumo-32u4-arduino-library) library to
instantiate a LSM303 object (the Magnetometer) and we used the heading()
function on that object to obtain the number of degrees towards the north
pole.  We saw it changing on the LCD as we moved the robot around.

**Calibration**

We did not have time to calibrate the Magnetometer so that it could
accurately detect true north, but we discussed the concept of calibration
in general which is important.  [Here's](https://www.youtube.com/watch?v=KSe6hITpr_o) an interesting example
calibrating sensors on a quad copter using a freezer!

**Bus**

Some of you noticed right away that we also needed the [Wire.h](https://www.arduino.cc/en/Reference/Wire) library and this lead to a
discussion about how the main Atmel processor uses a 'bus' to talk to
several of the chips on the board.  We'll be using that same bus to talk to
the camera in an upcoming class.  Buses are present in every computer
system and if we were to have built our robot from scratch, we'd have spent
a day or two wiring up sensor chips to the various buses on the main Atmel
chip.  Read [this discussion](http://superuser.com/a/462093) and look
closely at the pictures for a good summary of buses on a typical PC/laptop,
or just think about all of the USB devices that you plug into your
computers, they use the single Universal Serial *Bus* to communicate with
the CPU.

See you next week!

Carlos
