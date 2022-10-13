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
    void PlayMiss();
    void PlayInDoor();

private:

    //BGM
    int Title;
    int GamePlay;
    int GameOver;
    int GameClear;

    //SE
    int Miss;
    int InDoor;
};

