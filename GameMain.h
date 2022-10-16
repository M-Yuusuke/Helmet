#pragma once
class SceneManager;
class Rule;
class UI;
class HitCheck;
class BackGround;
class Door;
class Player;
class Tool;
class Sound;

class GameMain
{
public:
    GameMain();
    void GameLoop(SceneManager* scenemanager, Rule* rule,
        UI* ui, HitCheck* hitcheck, BackGround* background,
        Door* door, Player* player, Tool* tool, Sound* sound);
private:
};

