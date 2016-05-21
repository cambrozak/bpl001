Computer Vision is one of the hottest topics in robotics today.  All of the major universities have classes and teams focused on this particular area.  The good folks at Carnegie Mellon University developed and open-sourced the [Pixy](http://www.cmucam.org/projects/cmucam5) sensor that we used today.

This session began with a demo of two robots on the test field.  One robot carried a fluorescent ball in a random pattern using the bump-n-go accelerometer algorithm.  The other robot followed the first one around the field and appeared as if it was trying to keep a safe distance by reversing and spinning occasionally, all the while keeping the camera arm pointed at he ball.  It used computer vision and a feedback algorithm to achieve this life-like effect.

We started off by [training the Pixy sensor](https://youtu.be/7znEmgYZXL0) to recognize specific color signatures with the monitor program.  The monitor snapped a picture and allowed us to select areas of color that we wanted the sensor to track.  The signatures were stored on the Pixy sensor chip.  You all were able to see some of the surprising results when things across the room and up in the ceiling were recognized.

Next, we wrote some code that accessed the Pixy sensor in real time and displayed the recognized signatures on the LCD screen.  The Pixy API also provided x,y coordinates and height data for each detected object.  We then loaded a program that combined signature recognition with the servo arm scanner from last session.  This program would simply stop moving the arm once an object was detected.  The final program brought everything together: Servo arm scanning, Pixy vision and motor instructions for following the largest object in the field of vision.  You were able to deploy your robot and taunt it with the fluorescent balls and other objects to test it's capabilities.

A Feedback Control algorithm is responsible for connecting vision, servo and motors together in such a way as to appear smooth in motion and almost life-like.  We discussed in lecture how feedback is accomplished by measuring the error between the current position of the robot and the target position and using this error value to adjust motors and servos several times per second, each time re-calculating the error and feeding it back into the next calculation.  Our  algorithm makes a [Proportional](https://youtu.be/JEpWlTl95Tw?t=30s) adjustment and a [Derivative](https://youtu.be/JEpWlTl95Tw?t=9m10s) adjustment.  The proportional adjustment takes care of getting the robot to move quickly if it's way off target.  The Derivative adjustment looks at how fast the error is changing over time and produce small corrections as it gets closer to the target so that it doesn't overshoot and miss! 

I'm super grateful to have had the opportunity to hack on robots with this group!  I'd like to thank everyone including Students and Parents for making this an awesome class.  Big props to Kim Day for conceiving and organizing as part of the library's young adult program, huge props to Jeff and the IT staff and special thanks to the Library Board of Directors and my employer, Intuit, for funding.

Please be on the lookout for the survey email, and always feel free to send questions about robotics and programming to this email address.

Syllabus, lesson plans and most of the source code for the class is available here:

https://github.com/cambrozak/bpl001

So long, and thanks for the cakes!
