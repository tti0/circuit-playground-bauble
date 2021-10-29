#include <Adafruit_CircuitPlayground.h>
#include "twinkleIntensityFrame.h"
#include "colourBrightnessModifier.h"

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels();
  CircuitPlayground.setBrightness(45);
}

void loop() {

  // (1) Cool white twinkle
  int twinkleMinMaxHoldFrames = 200;
  int twinkleHighestNumberedFrame = highestNumberedFrame(twinkleMinMaxHoldFrames);
  // Generate a random offset starting frame for each LED
  int offsets[10] = {random(300), random(300), random(300), random(300), random(300), random(300), random(300), random(300), random(300), random(300)};
  // For each frame of animation (1)
  for (int i = 0; i <= 5000; i++) {
    // For each LED
    for (int j = 0; j <= 9; j++) {
      int myCurrentFrame = (i + offsets[j]) % twinkleHighestNumberedFrame;
      byte myCurrentIntensity = intensityAtFrame(myCurrentFrame, twinkleMinMaxHoldFrames);
      CircuitPlayground.setPixelColor(j, modifiedColourComponent(180, myCurrentIntensity), modifiedColourComponent(180, myCurrentIntensity), modifiedColourComponent(255, myCurrentIntensity));
    }  
  }
}

// (1) cool white twinkle
// (2) nutcracker flash (r/g/w)
// (3) blue gradient
// (2)
// (4) warm white twinkle
// (2)
// (5) rainbow
// (2)

// if switch on
// either button interrupt
// sugarcane lights
// play christmas song
