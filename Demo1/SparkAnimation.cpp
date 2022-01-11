#include "SparkAnimation.h"

void SparkAnimation::reset(PixelStrip *strip) {
  black = 0x000000;
  currentPixel = 0;
  waitTime = 1000.0 / strip->numPixels();
  setTimeout(waitTime);
  strip->clear();
}

void SparkAnimation::draw(PixelStrip *strip) {
  if (isTimedout()) {
    strip->setPixelColor(currentPixel, black);
    currentPixel = (currentPixel + 1) % strip->numPixels();
    strip->setPixelColor(currentPixel, 0x880000);
    setTimeout(waitTime);
  }
}
