#pragma once
class SceneManager;
class Sound;
class Rule;
class GameOver
{
public:
    GameOver();
    void GameOverDraw(SceneManager* scenemanager,Sound*sound, Rule* rule);
private:
    int BackGround;
};

