#pragma once
class Sound
{
public:
    Sound();
    ~Sound();

    //BGM
    void PlayTitle();
    void PlayGame();
    void PlayClear();
    void PlayOver();

    //SE
    void StopSE();
    void PlayWalk();
    void StopWalk();
    void PlayMiss();
    void PlayInDoor();
    void PlayOpenDoor();
    void PlayCloseDoor();

private:

    //BGM
    int Title;
    int GamePlay;
    int GameOver;
    int GameClear;

    //SE
    int Walk;
    int Miss;
    int InDoor;
    int OpenDoor;
    int CloseDoor;
};

