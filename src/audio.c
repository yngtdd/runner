#include "raylib.h"

/* Play simple 8-bit music
 */
Music load_music()
{
   InitAudioDevice();

   Music music = LoadMusicStream("../assets/audio.xm");
   music.looping = false;

   return music;

}
