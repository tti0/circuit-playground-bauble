const unsigned long red = 0xFF0000;
const unsigned long green = 0x32FF00;
const unsigned long white = 0xFFFFFF;

void doNutcrackerFlash() {
  for (int i = 0; i < 3; i++) {
    CircuitPlayground.clearPixels();
    CircuitPlayground.setPixelColor(0, red);
    CircuitPlayground.setPixelColor(1, green);
    CircuitPlayground.setPixelColor(2, white);
    CircuitPlayground.setPixelColor(3, red);
    CircuitPlayground.setPixelColor(4, green);
    CircuitPlayground.setPixelColor(5, white);
    CircuitPlayground.setPixelColor(6, red);
    CircuitPlayground.setPixelColor(7, green);
    CircuitPlayground.setPixelColor(8, white);
    CircuitPlayground.setPixelColor(9, red);
    delay(1000);
    CircuitPlayground.setPixelColor(0, green);
    CircuitPlayground.setPixelColor(1, white);
    CircuitPlayground.setPixelColor(2, red);
    CircuitPlayground.setPixelColor(3, green);
    CircuitPlayground.setPixelColor(4, white);
    CircuitPlayground.setPixelColor(5, red);
    CircuitPlayground.setPixelColor(6, green);
    CircuitPlayground.setPixelColor(7, white);
    CircuitPlayground.setPixelColor(8, red);
    CircuitPlayground.setPixelColor(9, green);
    delay(1000);
    CircuitPlayground.setPixelColor(0, white);
    CircuitPlayground.setPixelColor(1, red);
    CircuitPlayground.setPixelColor(2, green);
    CircuitPlayground.setPixelColor(3, white);
    CircuitPlayground.setPixelColor(4, red);
    CircuitPlayground.setPixelColor(5, green);
    CircuitPlayground.setPixelColor(6, white);
    CircuitPlayground.setPixelColor(7, red);
    CircuitPlayground.setPixelColor(8, green);
    CircuitPlayground.setPixelColor(9, white);
    delay(1000);    
  }
}
