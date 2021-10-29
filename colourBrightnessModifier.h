byte modifiedColourComponent(byte original, byte intensity) {
  float unrounded = original * (intensity / 255.0);
  return round(unrounded);
}
