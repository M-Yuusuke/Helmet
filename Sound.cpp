#include "DxLib.h"
#include "Sound.h"

Sound::Sound():
    Title(LoadSoundMem("../../Sound/BGM/Title.ogg")),
    GamePlay(LoadSoundMem("../../Sound/BGM/GamePlay.ogg")),
    GameOver(LoadSoundMem("../../Sound/BGM/GameOver.ogg")),
    GameClear(LoadSoundMem("../../Sound/BGM/GameClear.ogg")),
    Walk(LoadSoundMem("../../Sound/SE/Walk.mp3")),
    Miss(LoadSoundMem("../../Sound/SE/Miss.ogg")),
    InDoor(LoadSoundMem("../../Sound/SE/InDoor.ogg")),
    OpenDoor(LoadSoundMem("../../Sound/SE/OpenDoor.mp3")),
    CloseDoor(LoadSoundMem("../../Sound/SE/CloseDoor.mp3"))
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
    StopSoundMem(Walk);
    StopSoundMem(Miss);
    StopSoundMem(InDoor);
    StopSoundMem(OpenDoor);
    StopSoundMem(CloseDoor);
    StopSoundMem(GamePlay);
    PlaySoundMem(GameClear, DX_PLAYTYPE_LOOP, TRUE);
}

void Sound::PlayOver()
{
    StopSoundMem(Walk);
    StopSoundMem(Miss);
    StopSoundMem(InDoor);
    StopSoundMem(OpenDoor);
    StopSoundMem(CloseDoor);
    StopSoundMem(GamePlay);
    PlaySoundMem(GameOver, DX_PLAYTYPE_LOOP, TRUE);
}

void Sound::PlayWalk()
{
    if (CheckSoundMem(Walk) == 0)
    {
        PlaySoundMem(Walk, DX_PLAYTYPE_BACK, TRUE);
    }
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

void Sound::PlayOpenDoor()
{
    if (CheckSoundMem(OpenDoor) == 0)
    {
        PlaySoundMem(OpenDoor, DX_PLAYTYPE_BACK, TRUE);
    }
}

void Sound::PlayCloseDoor()
{
    if (CheckSoundMem(CloseDoor) == 0)
    {
        PlaySoundMem(CloseDoor, DX_PLAYTYPE_BACK, TRUE);
    }
}
