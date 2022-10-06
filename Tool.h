#pragma once
class Tool
{
public:
    Tool();
    ~Tool();
    bool CheckHit(int PlayerX,int PlayerY,float Radius) const;
    void Update(float DeltaTime);
    void Draw();

private:
    const int DropToolMax = 5;
    const int Width = 150;
    const int Height = 150;
    const int EndPositionY = 700;
    const double PI = 3.14;

    struct DropTool
    {
        int X;
        int Y;
        int DropTime;
        float Radian;
        int Graph;
        bool Dead;
    };
    DropTool Array[5];
    int DropSpeed;
    int OriginalGraph[5];
};

