#include <math.h>
#include "DxLib.h"
#include "Tool.h"

Tool::Tool()
{
    LoadDivGraph("../../Img/DropTools.png", 5, 5, 1, Width, Height, OriginalGraph);
    for (int i = 0; i < DropToolMax; i++)
    {
        Array[i].X = 400 + 250 * i;
        Array[i].Y = Height / 2;
        Array[i].DropTime = GetRand(20);
        Array[i].Radian = 0;
        Array[i].Graph = OriginalGraph[i];
    }
    DropSpeed = 500;
}

void Tool::HitCheck(int PlayerX, int PlayerY, float Radius)
{
    for (int i = 0; i < DropToolMax; i++)
    {
        int Circle1 = PlayerX - Array[i].X;
        int Circle2 = PlayerY - Array[i].Y;
        int Dimension = sqrt(Circle1 * Circle1 + Circle2 * Circle2);
        if (Dimension <= Radius + Width)
        {
            DrawFormatString(50, 50, GetColor(0, 0, 0),"“–‚½‚Á‚½I");
        }
     }
}

void Tool::Update(float DeltaTime)
{
    for (int i = 0; i < DropToolMax; i++)
    {
        Array[i].DropTime -= DeltaTime;
        if (Array[i].DropTime <= 0)
        {
            Array[i].Y += DropSpeed * DeltaTime;
            Array[i].Radian += static_cast<float>((PI / 180) * 5);
            if (Array[i].Y >= EndPositionY)
            {
                Array[i].Y = Height / 2;
                Array[i].DropTime = GetRand(20);
            }
        }
        
    }
}

void Tool::Draw()
{
    for (int i = 0; i < DropToolMax; i++)
    {
        DrawRotaGraph(Array[i].X, Array[i].Y, 1.0, Array[i].Radian, Array[i].Graph, TRUE);
    }
}
