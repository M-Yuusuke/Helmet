#pragma once
class Tool
{
public:
    Tool();
    ~Tool();
    void HitCheck(int PlayerX,int PlayerY,float Radius);
    void Update(float DeltaTime);
    void Draw();

private:
    const int DropToolMax = 5;
    const int Width = 150;
    const int Height = 150;
    const int EndPositionY = 1050;
    const double PI = 3.14;

    struct DropTool
    {
        int X;
        int Y;
        int DropTime;
        float Radian;
        int Graph;
    };
    DropTool Array[5];
    int DropSpeed;
    int OriginalGraph[5];
};

