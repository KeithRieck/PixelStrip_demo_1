#include <PixelStrip.h>
#include "MyAnimation.h"

const int BRIGHTNESS = 128;

PixelStrip *strip1 = new PixelStrip((new NEOPIXEL<7>), 8);
PixelStrip *strip2 = new PixelStrip((new NEOPIXEL<6>), 12);
PixelStrip *strip3 = new PixelStrip((new NEOPIXEL<5>), 12);

void setup() {
  strip1->setup();
  strip1->setBrightness(BRIGHTNESS);
  strip1->setAnimation(new MyAnimation());
  strip2->setup();
  strip2->setBrightness(BRIGHTNESS);
  strip2->setAnimation(new MyAnimation());
  strip3->setup();
  strip3->setBrightness(BRIGHTNESS);
  strip3->setAnimation(new MyAnimation());
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
