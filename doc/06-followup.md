Today's class was all about [Servo Mechanical Control](https://www.youtube.com/watch?v=KWmTX9QotGk&list=PLEb9Wc8b63OPTJHpk8NzRSd3B3xxAkrRO), or Servos for short.

You started off by writing code to communicate via the I2C bus between the
32U4 main board and the [PixyCam](http://www.cmucam.org/projects/cmucam5/wiki/Introduction_and_Background),
a wonderful vision capture system built by researchers at Carnegie Mellon
University that includes two onboard servo drivers.

You got very familiar with the Pixy servo API and used it to set positions
for the pan and tilt servos directly.  A simple program was used to
manipulate the servo arm manually by pressing buttons and you were able to
adjust the movement rate per button push.

The lecture dived into [servo internals](https://youtu.be/-XSXfqd1N58) and
you could see that a servo consists of a Motor + Gearbox + Control Circuit + Feedback Unit, a Potentiometer](https://www.youtube.com/watch?v=F9U29RkqHXA)
in this case.  We talked briefly about how [Pulse Width Modulation](https://youtu.be/7VR3bYoFH88) is used along with the gearbox to maintain a
servo's position and generate torque to work against counter forces and
lift stuff.

The final lab used a [non-blocking](https://en.wikipedia.org/wiki/Non-blocking_algorithm) algorithm to move
the servo arm continuously in a scanning pattern while simultaneously
updating the LCD display and blinking the Pixy [RGB](https://www.youtube.com/watch?v=fNisT6ROdUo) LED.  This scanner will be
used in the next session to search for visible objects over a wide area.

There are two ways to break a servo: Fry the control circuit with too much
current and break the gearbox by forcing it with your hand.  As luck would
have it, live samples of both types were available for you to inspect that
I destroyed assembling the bots yesterday.  In the tradition of The Rusty
Spike Award this mishap was converted into your learning moment, and I hope that you
can carry on this tradition with your own setbacks in the future.

And last but not least, we had the first real robot sighting of the class
by Jeff!  He spotted the new security robot on patrol at the Stanford Mall.


*Challenge:* Go to Stanford Mall and harass the security robot. Stand in
its way to see how it detects you and maneuvers around obstacles.  Cover
its camera lens and see how it compensates.  Stalk it to find the secret
charging space.  Report back any and all findings.

See you at the final class, Parents please be sure to respond to the email
about attendance, thanks!

Carlos
