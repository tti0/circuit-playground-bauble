#include <Adafruit_CircuitPlayground.h>
#include "twinkleIntensityFrame.h"
#include "colourBrightnessModifier.h"
#include "nutcrackerPattern.h"
#include "harkTheHerald.h"

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels();
  CircuitPlayground.setBrightness(45);
}

void loop() {

  // Generate twinkle LED offsets and set twinkle constants for this loop
  const int twinkleMinMaxHoldFrames = 200;
  const int twinkleHighestNumberedFrame = highestNumberedFrame(twinkleMinMaxHoldFrames);
  // Generate a random offset starting frame for each LED
  int offsets[10] = {};
  for (int i = 0; i <= 9; i++) {
    offsets[i] = random(0, 500);
  }

  // (1) Cool white twinkle
  // For each frame of animation (1)
  for (int i = 0; i <= 3000; i++) {
    // For each LED
    for (int j = 0; j <= 9; j++) {
      int myCurrentFrame = (i + offsets[j]) % twinkleHighestNumberedFrame;
      byte myCurrentIntensity = intensityAtFrame(myCurrentFrame, twinkleMinMaxHoldFrames);
      CircuitPlayground.setPixelColor(j, modifiedColourComponent(180, myCurrentIntensity), modifiedColourComponent(180, myCurrentIntensity), modifiedColourComponent(255, myCurrentIntensity));
    }  
  }

  // (2) Nutcracker flash (r/g/w)
  doNutcrackerFlash();

  // (3) Warm white twinkle
  // For each frame of animation (1)
  for (int i = 0; i <= 3000; i++) {
    // For each LED
    for (int j = 0; j <= 9; j++) {
      int myCurrentFrame = (i + offsets[j]) % twinkleHighestNumberedFrame;
      byte myCurrentIntensity = intensityAtFrame(myCurrentFrame, twinkleMinMaxHoldFrames);
      CircuitPlayground.setPixelColor(j, modifiedColourComponent(255, myCurrentIntensity), modifiedColourComponent(220, myCurrentIntensity), modifiedColourComponent(50, myCurrentIntensity));
    }
  }

  // (2) Nutcracker flash (r/g/w)
  doNutcrackerFlash();

  // (4) Rainbow cycle
  // Based on https://github.com/adafruit/Adafruit_CircuitPlayground/blob/master/examples/mega_demo/RainbowCycleDemo.h
  for(int i = 0; i <= 3000; i++) {
    // Make an offset based on the current millisecond count scaled by the current speed.
    uint32_t offset = millis() / 10;
    // Loop through each pixel and set it to an incremental color wheel value.
    for(int j = 0; j < 10; j++) {
      CircuitPlayground.setPixelColor(j, CircuitPlayground.colorWheel(((j * 256 / 10) + offset) & 255));
    }
  }

  // (2) Nutcracker flash (r/g/w)
  doNutcrackerFlash();

}
