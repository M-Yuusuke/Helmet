#pragma once
class Rule;
class HitCheck;
class UI;
class Sound;
class BackGround;
class Door;
class Player;
class Tool;
class SceneManager
{
public:
    SceneManager();
    ~SceneManager();

    int GetScene()const { return scene; }
    void Initialize();
    void Title();
    void GameMain();
    void Clear();
    void Over();

private:
    Rule* rule;
    HitCheck* hitcheck;
    UI* ui;
    Sound* sound;
    BackGround* background;
    Door* door;
    Player* player;
    Tool* tool;
    enum Scene
    {
        INIT, TITLE, GAMEMAIN, CLEAR, OVER
    };
    Scene scene;
};

