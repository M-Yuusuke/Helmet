#pragma once
class UI;
class Player;
class Door;
class Tool;
class HitCheck
{
public:
    HitCheck();
    ~HitCheck();
    void OnDoor(Player* player, Door* door, UI* ui);
    //void HitTool(Tool::DropTool* Array, Player* player);
private:
};

