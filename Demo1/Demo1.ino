#include <PixelStrip.h>
#include "SparkAnimation.h"
#include "PulseAnimation.h"

const int BRIGHTNESS = 128;

PixelStrip *strip1 = new PixelStrip((new NEOPIXEL<7>), 12);
PixelStrip *strip2 = new PixelStrip((new NEOPIXEL<6>), 12);
PixelStrip *strip3 = new PixelStrip((new NEOPIXEL<5>), 8);
Animation *animation1, *animation2;
PulseAnimation *animation3;

void setup() {
  animation1 = new SparkAnimation();
  strip1->setup();
  strip1->clear();
  strip1->setBrightness(BRIGHTNESS);
  strip1->setAnimation(animation1);

  animation2 = new SparkAnimation();
  strip2->setup();
  strip2->clear();
  strip2->setBrightness(BRIGHTNESS);
  strip2->setAnimation(animation2);

  animation3 = new PulseAnimation(2);
  animation3->setColor(0, 0x0000CC);
  animation3->setColor(1, 0xCC0000);
  strip3->setup();
  strip3->clear();
  strip3->setBrightness(BRIGHTNESS);
  strip3->setAnimation(animation3);
}

void loop() {
  strip1->draw();
  strip2->draw();
  strip3->draw();
  strip1->show();
  strip2->show();
  strip3->show();
  delay(10);
}
