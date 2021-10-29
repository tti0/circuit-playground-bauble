byte intensityAtFrame(unsigned int frameNo, unsigned int framesToPauseAtMinMax) {
  int maximumStartFrame = 255;
  int maximumEndFrame = maximumStartFrame + framesToPauseAtMinMax;
  int minimumStartFrame = maximumEndFrame + 255;
  int minimumEndFrame = minimumStartFrame + framesToPauseAtMinMax;
  
  if (frameNo > 0 and frameNo <= maximumStartFrame) {
    return frameNo;
  } else if (frameNo > maximumStartFrame and frameNo <= maximumEndFrame) {
    return 255;
  } else if (frameNo > maximumEndFrame and frameNo <= minimumStartFrame) {
    return 255 - (frameNo - maximumEndFrame);
  } else if (frameNo > minimumStartFrame and frameNo <= minimumEndFrame) {
    return 0;
  } else {
    return 0;
  }
}

unsigned int highestNumberedFrame(unsigned int framesToPauseAtMinMax) {
  return 255 + framesToPauseAtMinMax + 255 + framesToPauseAtMinMax; // climb up + hold max + climb down + hold min 
}
