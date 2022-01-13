#include <PixelStrip.h>
#include "SparkAnimation.h"
#include "FlowerAnimation.h"
#include "PulseAnimation.h"

const int BRIGHTNESS = 128;
const int NUM_PIXELSTRIPS = 3;

PixelStrip *strip[NUM_PIXELSTRIPS];

Animation *animation1, *animation2;
PulseAnimation *animation3;

void setup() {
  strip[0] = new PixelStrip((new NEOPIXEL<7>), 12);
  strip[1] =  new PixelStrip((new NEOPIXEL<6>), 7);
  strip[2] =  new PixelStrip((new NEOPIXEL<5>), 8);

  for (int i = 0; i < NUM_PIXELSTRIPS; i++) {
    strip[i]->setup();
    strip[i]->setBrightness(BRIGHTNESS);
    strip[i]->clear();
  }

  animation1 = new SparkAnimation();
  strip[0]->setAnimation(animation1);

  animation2 = new FlowerAnimation();
  strip[1]->setAnimation(animation2);

  animation3 = new PulseAnimation(2);
  animation3->setColor(0, 0x0000CC);
  animation3->setColor(1, 0xCC0000);
  strip[2]->setBrightness(BRIGHTNESS);
  strip[2]->setAnimation(animation3);
}

void loop() {
  for (int i = 0; i < NUM_PIXELSTRIPS; i++) {
    strip[i]->draw();
    strip[i]->show();
  }
  delay(10);
}
