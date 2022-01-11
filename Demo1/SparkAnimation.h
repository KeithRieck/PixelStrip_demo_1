#ifndef SparkAnimation_h
#define SparkAnimation_h
#include <PixelStrip.h>

class SparkAnimation : public Animation {
  public:
    void reset(PixelStrip *strip);
    void draw(PixelStrip *strip);
    unsigned long waitTime = 10;
  private:
    uint32_t black;
    int currentPixel;
};
#endif
