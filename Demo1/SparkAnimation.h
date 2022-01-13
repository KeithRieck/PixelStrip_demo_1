#ifndef SparkAnimation_h
#define SparkAnimation_h
#include <PixelStrip.h>

class SparkAnimation : public Animation {
  public:
    void reset(PixelStrip *strip);
    void draw(PixelStrip *strip);
    unsigned long waitTime = 10;
  private:
    int currentPixel;
    const int COLOR_LIST_SIZE = 5;
    uint32_t colorList[5] = { 0xffffff, 0x880000, 0x442200, 0x111100, 0x000000 };
};
#endif
