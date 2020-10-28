#include "pitches.h"

class MusicalNote
{
public:
    MusicalNote()
    {
    }
    MusicalNote(int f, int d)
    {
        freq = f;
        duration = d;
    }
    int freq;
    // note durations: 4 = quarter note, 8 = eighth note, etc.:
    int duration;
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