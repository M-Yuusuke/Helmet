#pragma once

class SceneManager;
class Rule;
class HitCheck;
class Player;
class Door;
class Tool;
class UI;
class Effect;
class Sound;

class SceneBase
{
public:
    SceneBase();
    virtual ~SceneBase();

    virtual SceneBase* Update(SceneManager* sceneManager) = 0;
    virtual void Draw();

protected:
    Rule* rule;
    HitCheck* hitcheck;
    Player* player;
    Door* door;
    Tool* tool;
    UI* ui;
    Effect* effect;
    Sound* sound;
};

