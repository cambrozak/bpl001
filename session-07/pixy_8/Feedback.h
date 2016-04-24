// BPL001 Feedback Loop Interface
#ifndef Feedback_h
#define Feedback_h

#include <Zumo32U4.h>
#include <PixyI2C.h>

class Feedback {
  public:
    Feedback(int32_t proportionalGain, int32_t derivativeGain);
    void calculateNextPosition(int32_t currentError);
    int32_t mNextPosition;
    int32_t mPreviousError;
    int32_t mProportionalGain;
    int32_t mDerivativeGain;
    long int mVelocity;
};
#endif
