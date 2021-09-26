#include "raylib.h"

/* Play simple 8-bit music
 */
void play_music()
{
   InitAudioDevice();

   Music music = LoadMusicStream("../assets/audio.xm");

   music.looping = false;
   float pitch = 1.0f;

   PlayMusicStream(music);
}
