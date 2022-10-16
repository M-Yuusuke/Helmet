#pragma once
class SceneManager;
class Sound;
class GameOver
{
public:
    GameOver();
    void GameOverDraw(SceneManager* scenemanager,Sound*sound);
private:
    int BackGround;
};

