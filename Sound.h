#pragma once
class Sound
{
public:
    static void Create();
    static void Destroy();
    static Sound* GetInstance() { return Instance; }
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
    Sound();
    ~Sound();
    static Sound* Instance;

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

