#pragma once
class Scene;
class Rule;
class UI;
class Effect;
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
    void Update(Scene* scene, Rule* rule,
        UI* ui, Effect* effect, HitCheck* hitcheck,
        Door* door, Player* player, Tool* tool, Sound* sound);

    void Draw( Rule* rule,UI* ui, Effect* effect,  BackGround* background,
        Door* door, Player* player, Tool* tool, Scene* scene);
private:
};

