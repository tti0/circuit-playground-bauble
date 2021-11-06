// Based on https://learn.adafruit.com/circuit-playground-music/the-sound-of-music and https://hymnary.org/media/fetch/100411

#include "pitches.h"

const int melody[] = {
  NOTE_C5, NOTE_F5, NOTE_F5, NOTE_E5,
  NOTE_F5, NOTE_A5, NOTE_A5, NOTE_G5,
  NOTE_C6, NOTE_C6, NOTE_C6, NOTE_AS5,
  NOTE_A5, NOTE_G5, NOTE_A5,
  
  NOTE_C6, NOTE_C6, NOTE_C6, NOTE_F5,
  NOTE_AS5, NOTE_A5, NOTE_A5, NOTE_G5,
  NOTE_C6, NOTE_C6, NOTE_C6, NOTE_F5,
  NOTE_AS5, NOTE_A5, NOTE_A5, NOTE_G5,
  
  NOTE_D6, NOTE_D6, NOTE_D6, NOTE_C6,
  NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_C6, NOTE_F5,
  NOTE_F5, NOTE_G5, NOTE_F5
  };

const float rhythm[] = {
  4, 4, 2.6, 8,
  4, 4, 4, 4,
  4, 4, 2.6, 8,
  4, 4, 2,

  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,

  4, 4, 4, 4,
  4, 4, 2,
  4, 8, 8, 2.6, 8,
  4, 4, 2
  };

const int numNotes = 46;

void doHarkTheHerald() {
  for (int i = 0; i < numNotes; i++) {
    int noteDuration = 1000 / rhythm[i];
    CircuitPlayground.playTone(melody[i], noteDuration);
    delay(noteDuration * 0.20);
  }
}
