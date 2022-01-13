#include "FlowerAnimation.h"

void FlowerAnimation::reset(PixelStrip *strip) {
  state = 0;
  setTimeout(0);
  strip->clear();
}

void FlowerAnimation::draw(PixelStrip *strip) {
  if (isTimedout()) {
    strip->clear();

    for (int j=0; j<7; j++) {
      strip->setPixelColor(j, stateList[state][j]);
    }

    setTimeout(stateList[state][7]);
    state = (state + 1) % STATE_LIST_SIZE;
  }
}
