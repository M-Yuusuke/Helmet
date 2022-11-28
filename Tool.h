#pragma once
class HitCheck;
class Player;
class Effect;
class Tool
{
public:
    static void Create();
    static void Destroy();
    static Tool* GetInstance() { return Instance; }

    void Initialize();
    bool CheckHit(int PlayerX,int PlayerY,float Radius,Effect* effect) const;
    void Update(float DeltaTime);
    void Draw();

private:
    Tool();
    ~Tool();
    static Tool* Instance;

    const int DropToolFirstPosX = 400;
    const int DropToolFirstPosY = 95;
    const int DropToolMax = 5;
    const int DropSpeed = 500;
    const float DropCoolTimeMax = 7;
    const int Width = 150;
    const int Height = 150;
    const int EndPositionY = 800;
    const double PI = 3.14;

    struct DropTool
    {
        int X;
        int Y;
        float DropTime;
        float Radian;
        int Graph;
        bool Dead;
    };
    DropTool Array[5];
    int OriginalGraph[5];
};

