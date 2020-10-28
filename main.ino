#include <Arduino.h>

#include "note.h"

// notes in the melody:
int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
    4, 8, 8, 4, 4, 4, 4, 4};

int melody2[] = {
    NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C5, 0, 0, 0};
int noteDurations2[] = {
    8, 8, 8, 8, 2, 4, 4, 4};

int pinVal = 0;

class Sequence8
{
public:
    Sequence8()
    {
    }
    MusicalNote notes[8];

    void Play()
    {
        for (int iNote = 0; iNote < 8; iNote++)
        {
            // Play
            tone(8, notes[iNote].freq, notes[iNote].GetDurationMs());
            // Wait
            delay(notes[iNote].GetPauseMs());
            // Stop
            noTone(8);
        }
    }
};

class Sequence16
{
    MusicalNote notes[16];
};

Sequence8 seq;

void setup()
{
    Serial.begin(9600);

    // pinMode(A7, );
    //     int melody2[] = {
    //     NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C5, 0, 0, 0};
    // int noteDurations2[] = {
    //     8, 8, 8, 8, 2, 4, 4, 4};
    seq.notes[0] = MusicalNote(NOTE_C4, 8);
    seq.notes[1] = MusicalNote(NOTE_D4, 8);
    seq.notes[2] = MusicalNote(NOTE_DS4, 8);
    seq.notes[3] = MusicalNote(NOTE_F4, 8);
    seq.notes[4] = MusicalNote(NOTE_C4, 2);
    seq.notes[5] = MusicalNote(NOTE_C4, 4);
    seq.notes[6] = MusicalNote(NOTE_C3, 4);
    seq.notes[7] = MusicalNote(NOTE_C4, 2);
}

int noteMin = 31;
int noteMax = 4978;
int noteRange = noteMax - noteMin;

void loop()
{
    seq.Play();

    // 0-1023
    // pinVal += analogRead(A7);
    // pinVal /= 2;

    // float pinValNorm = pinVal / 1024.0;
    // int hz = pinValNorm * noteRange;

    // tone(8, hz, 400);
    // delay(100);
    // noTone(8);
    // // Debug
    // Serial.println(String(pinVal) + " " + String(hz) + " hz");
}