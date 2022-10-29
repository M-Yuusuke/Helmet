#pragma once
class Player;
class Door;
class Tool;
class Effect;
class HitCheck
{
public:
    HitCheck();
    ~HitCheck();
    void OnDoor(Player* player, Door* door,Effect* effect);
    //void HitTool(Tool::DropTool* Array, Player* player);
private:
};

