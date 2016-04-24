// BPL001 Feedback Loop Implementation
#include "Feedback.h"

Feedback::Feedback(int32_t proportionalGain, int32_t derivativeGain) {
  mNextPosition = PIXY_RCS_CENTER_POS;
  mProportionalGain = proportionalGain;
  mDerivativeGain = derivativeGain;
  mPreviousError = 0x80000000L;
  mVelocity = 0;
}

// Calculates next position based on the current measured error and the current state
void Feedback::calculateNextPosition(int32_t currentError) {
  
  if (mPreviousError != 0x80000000) {	
    mVelocity = ((currentError * mProportionalGain) + ((currentError - mPreviousError) * mDerivativeGain)) >> 10;

    mNextPosition += mVelocity;

    if (mNextPosition > PIXY_RCS_MAX_POS) {
      mNextPosition = PIXY_RCS_MAX_POS; 
    } else if (mNextPosition < PIXY_RCS_MIN_POS) {
      mNextPosition = PIXY_RCS_MIN_POS;
    }
  }

  mPreviousError = currentError;
}
