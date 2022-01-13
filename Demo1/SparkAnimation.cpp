#include "SparkAnimation.h"

void SparkAnimation::reset(PixelStrip *strip) {
  currentPixel = 0;
  waitTime = 1000.0 / strip->numPixels();
  setTimeout(waitTime);
  strip->clear();
}

void SparkAnimation::draw(PixelStrip *strip) {
  if (isTimedout()) {
    int j = 0;
    for (int i = 0; i<COLOR_LIST_SIZE; i++) {
      j = (currentPixel + strip->numPixels() - i) % strip->numPixels();
      strip->setPixelColor(j, colorList[i]);
    }
    currentPixel = (currentPixel + 1) % strip->numPixels();
    setTimeout(waitTime);
  }
}
