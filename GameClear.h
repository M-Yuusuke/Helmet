#pragma once
class SceneManager;
class Sound;
class GameClear
{
public:
    GameClear();
    void GameClearDraw(SceneManager* scenemanager, Sound* sound);

private:
    int BackGround;
};

