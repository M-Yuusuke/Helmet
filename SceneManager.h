#pragma once
class Initialize;
class Title;
class GameMain;
class GameClear;
class GameOver;
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
    void InitializeScene();
    void TitleScene();
    void GameMainScene();
    void ClearScene();
    void OverScene();

    void NextScene();
    void ChangeGameClear();
    void ChangeGameOver();

    void NewPalyer();

private:
    Initialize* initialize;
    Title* title;
    GameMain* gamemain;
    GameClear* gameclear;
    GameOver* gameover;
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

