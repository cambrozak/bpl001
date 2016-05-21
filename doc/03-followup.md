Great class today, we all wrote a program from scratch together that fired
up the motors for a turning test.  Up to now you've only worked with code
that was already written.

We covered ['Mixed Case' and 'Camel Case'](https://en.wikipedia.org/wiki/CamelCase) conventions and I could tell that
you had no trouble reading and writing in this fashion once you understood why programmers use them.

You got familiar with importing the [Zumo32U4.h library](http://pololu.github.io/zumo-32u4-arduino-library/annotated.html) and
wrote a [custom function](https://en.wikipedia.org/wiki/Function_prototype) to
wait for the button press.

You declared and used objects from the library to control the LCD 
[Zumo32U4LCD](http://pololu.github.io/zumo-32u4-arduino-library/class_zumo32_u4_l_c_d.html),
Button A [Zumo32U4ButtonA](http://pololu.github.io/zumo-32u4-arduino-library/class_zumo32_u4_button_a.html)
and the Motors [Zumo32U4Motors](http://pololu.github.io/zumo-32u4-arduino-library/class_zumo32_u4_motors.html).
Some of you even experimented with additional libraries to control the
other buttons!  Highly encouraged, *please feel free to hack on the robot
and explore all of the libraries during class if you get ahead.*

Debugging! You experienced first hand that programming requires precise
spelling and syntax.  The most common issues were misspellings,
upper/lowercase and missing semicolons.  I've been programming
professionally for 20yrs and I encounter this stuff every day, so please
don't feel bad if you struggled a bit, this is actually how programming
gets done by the pros!  It's just a matter of getting familiar with the
syntax and using the compiler to detect and fix problems quickly.

I sped through a lecture on Algorithms and demo'd a perpendicular parking
algorithm that appears to work most of the time, but I wouldn't trust my
car with it.  We saw footage of a [more sophisticated autonomous parking algorithm](https://www.youtube.com/watch?v=rwyVkvBy0Wg)
 done by engineers at BMW that might be more trustworthy.  Please send me questions about
algorithms if you're researching the topic on your own.  The subject is
often presented in a complex way, but the spirit of crafting good
algorithms is actually all about simplicity.  Review the slides [here](https://docs.google.com/presentation/d/1qbsejn4cL1tgz9DGNN6XLlbOqR58pdn_9AwLl96yP6Y/edit?usp=sharing).

**Challenge**

The last slide in the lecture shows a picture of the robot
parked in a parking space marked with lines on the sides and a line in
front.  Write an algorithm to park the robot in a parking space.  The
dimensions of the space will always be exactly as shown in the picture,
just wide enough for the left and right sensors to lock in on the
sidelines.  *Hint: You'll need the middle sensor for this one.*

Write the final version of your algorithm in plain language on one side of
a single sheet of paper.  Use the other side to provide tables, diagrams
and pictures to help others implement your algorithm if you feel they are
necessary.

See you next week!

Carlos
