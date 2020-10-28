#include <Arduino.h>

#include "pitches.h"

// notes in the melody:
int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
    4, 8, 8, 4, 4, 4, 4, 4};

int pinVal = 0;

struct MusicalNote
{
    int freq = NOTE_C5;
    // note durations: 4 = quarter note, 8 = eighth note, etc.:
    int duration = 4;
    // Duration in milliseconds
    int GetDurationMs()
    {
        return 1000 / duration;
    }
    // Get ideal pause duration
    int GetPauseMs()
    {
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        return GetDurationMs() * 1.30;
    }
};

struct Sequence16
{
    MusicalNote notes[16];
};

void setup()
{
    Serial.begin(9600);
    // pinMode(A7, );
    // iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < 8; thisNote++)
    {

        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(8, melody[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
    }
}

int noteMin = 31;
int noteMax = 4978;
int noteRange = noteMax - noteMin;

void loop()
{
    // 0-1023
    pinVal += analogRead(A7);
    pinVal /= 2;

    float pinValNorm = pinVal / 1024.0;
    int hz = pinValNorm * noteRange;

    tone(8, hz, 400);
    delay(100);
    noTone(8);
    // Debug
    Serial.println(String(pinVal) + " " + String(hz) + " hz");
}