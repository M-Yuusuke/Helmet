#include "DxLib.h"
#include "Sound.h"

Sound::Sound():
    Title(LoadSoundMem("../../Sound/BGM/Title.ogg")),
    GamePlay(LoadSoundMem("../../Sound/BGM/GamePlay.ogg")),
    GameOver(LoadSoundMem("../../Sound/BGM/GameOver.ogg")),
    GameClear(LoadSoundMem("../../Sound/BGM/GameClear.ogg")),
    Miss(LoadSoundMem("../../Sound/SE/Miss.ogg")),
    InDoor(LoadSoundMem("../../Sound/SE/InDoor.ogg"))
{
}

Sound::~Sound()
{
    InitSoundMem();
}

void Sound::PlayTitle()
{
    StopSoundMem(GamePlay);
    StopSoundMem(GameOver);
    StopSoundMem(GameClear);
    PlaySoundMem(Title,DX_PLAYTYPE_LOOP, TRUE);
}

void Sound::PlayGame()
{
    StopSoundMem(Title);
    PlaySoundMem(GamePlay, DX_PLAYTYPE_LOOP, TRUE);
}

void Sound::PlayClear()
{
    StopSoundMem(GamePlay);
    PlaySoundMem(GameClear, DX_PLAYTYPE_LOOP, TRUE);
}

void Sound::PlayOver()
{
    StopSoundMem(GamePlay);
    PlaySoundMem(GameOver, DX_PLAYTYPE_LOOP, TRUE);
}

void Sound::PlayMiss()
{
    if (CheckSoundMem(Miss) == 0)
    {
        PlaySoundMem(Miss, DX_PLAYTYPE_BACK, TRUE);
    }
}

void Sound::PlayInDoor()
{
    if (CheckSoundMem(InDoor) == 0)
    {
        PlaySoundMem(InDoor, DX_PLAYTYPE_BACK, TRUE);
    }
}
