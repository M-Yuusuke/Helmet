#pragma once
class Player;
class Door;
class Tool;
class Effect;
class HitCheck
{
public:
    static void Create();
    static void Destroy();
    static HitCheck* GetInstance() { return Instance; }

    void OnDoor(Player* player, Door* door,Effect* effect);
    //void HitTool(Tool::DropTool* Array, Player* player);

private:
    HitCheck();
    ~HitCheck();
    static HitCheck* Instance;
};

