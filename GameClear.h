#pragma once
class SceneManager;
class Sound;
class Rule;
class GameClear
{
public:
    GameClear();
    void GameClearDraw(SceneManager* scenemanager, Sound* sound, Rule* rule);

private:
    int BackGround;
};

