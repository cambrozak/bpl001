// BPL001 Motor Control Interface
#ifndef M_h
#define M_h

#define MFORWARD 1
#define MREVERSE -1
#define MLEFT 2
#define MRIGHT 3

#define MMAX_SPEED 200

#define REVERSE_TIME 500
#define ACCELERATE_TIME 500

#define TURN_TIME_MAX 800
#define TURN_TIME_MIN 200

#include <Zumo32U4.h>

class M {
  public:
    void move(int direction);
    void move(int direction, int speed);
    int direction();
    const int FORWARD = MFORWARD;
    const int REVERSE = MREVERSE;
    const int LEFT = MLEFT;
    const int RIGHT = MRIGHT;
    const int MAX_SPEED = MMAX_SPEED;
    
  private:
    Zumo32U4Motors motors;
    void setLights(int yellow, int green, int red);
    int DIRECTION;
};
#endif
