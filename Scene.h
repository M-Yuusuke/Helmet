#pragma once
class Initialize;
class Title;
class GameMain;
class Result;
class Rule;
class HitCheck;
class UI;
class Effect;
class Sound;
class BackGround;
class Door;
class Player;
class Tool;

class Scene
{
public:
    Scene();
    ~Scene();

    int GetScene()const { return SceneStatus; }
    void InitializeScene();
    void TitleScene();
    void GameMainScene();
    void ResultScene();

    void NextScene();
    void ChangeGameClear();
    void ChangeGameOver();

private:
    Initialize* initialize;
    Title* title;
    GameMain* gamemain;
    Result* result;
    Rule* rule;
    HitCheck* hitcheck;
    UI* ui;
    Effect* effect;
    Sound* sound;
    BackGround* background;
    Door* door;
    Player* player;
    Tool* tool;
    
    int SceneStatus;
    enum 
    {
        INIT, TITLE, GAMEMAIN, CLEAR, OVER
    };
};

