Class went by fast yesterday.  Great discussion and insightful questions
from everyone.  You now understand that all computer programs are basically
just a list of *Statements* and *Expressions* written with particular
*Syntax* rules.  You know what a *Compiler* does and that it's not always
accurate in detecting Syntax problems.  The [deep](https://en.wikipedia.org/wiki/Random_number_generation#.22True.22_vs._pseudo-random_numbers)
topic of *Random Number Generators* was discussed and you saw the robot
demonstrate autonomous roaming behavior using this technique.  You even
learned how *Infra Red Phototransistor Sensors* [work](https://www.pololu.com/file/download/GP2S60_DS.pdf?file_id=0J683)!

The main thing to take away from this session is:

*Any* programming language can be learned by playing with its Statements & Expressions and getting familiar with its Syntax.

[Here](https://www.arduino.cc/en/Reference/HomePage) is a link to the
complete list of C++ Statements/Expressions and core functions available to
the Arduino environment.  You're already familiar with a lot of these.  For
the curious, check out [this link](http://en.cppreference.com/w/cpp/language)
just to get a sense of what C++ provides beyond Arduino.
And just for kicks, take a look at some [Python code](http://pythonprogramminglanguage.com/if-statements/) to see a popular
language that tries very hard to have Statements and Expressions that do
not to look like C++.

We touched on *Libraries* at the end, I will summarize here:

*Libraries* make life easier by organizing complex source code under a
simple API.  "API" is jargon for 'interface' which just means a set of
functions that you can call on the Library to use it.  Take a look at 
[this Servo library](https://www.arduino.cc/en/Reference/Servo) that will be used
to control the camera arm.  It provides a couple of simple functions to
rotate the servo motor.  Easy right?  Now take a look
[here](https://github.com/arduino/Arduino/blob/master/libraries/Servo/src/avr/Servo.cpp) at
the complexity underneath this library.  There's about 300 lines of code
and a lot of stuff going on with timers, interrupts and a bunch of stuff
you haven't learned about yet.  The good news is you don't have to know all
of this stuff to use the Servo library and play with servos!  A good
Software Library takes care of all the details and provides a simple
interface that's easy to use in just this fashion.  Kinda like how a good
Public Library organizes books and media to make it easy to find?

**Challenge**

A servo is hooked up to your Pac Man LCD simulator circuit.
Include the Servo.h library and use the API to rotate the servo +10 degrees
each time a pellet is chomped.  Reset the servo position to 0 degrees when
all pellets are chomped.  Hints: Study the [examples](https://www.arduino.cc/en/Tutorial/Sweep) in the API link.
Adjust the chomp rate to allow for the servo to finish moving between chomps.

Christopher brought up *Algorithms* which is an important concept.  We'll
pick up with basic roaming algorithms next week.  You'll receive a couple
of emails this week with some challenges that I think you'll enjoy.  Feel
free to email questions if you get stuck and ask me for a more interesting
challenges if these are too easy.  Also hit me up if you're confused about
how I've presented any of these concepts or just want more information.

Access your circuit here: https://123d.circuits.io/

Click 'Sign In' in the upper right corner

Enter username 'carlos.ambrozak@gmail.com', password 'bpl001robot'

Stay tuned for another email this week,

Carlos
