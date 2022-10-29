#include <math.h>
#include "DxLib.h"
#include "Tool.h"
#include "Player.h"
#include "HitCheck.h"

Tool::Tool()
{
    LoadDivGraph("Img/DropTools.png", 5, 5, 1, Width, Height, OriginalGraph);
    for (int i = 0; i < DropToolMax; i++)
    {
        Array[i].X = DropToolFirstPosX + 250 * i;
        Array[i].Y = DropToolFirstPosY;
        Array[i].DropTime = GetRand(DropCoolTimeMax);
        Array[i].Radian = 0;
        Array[i].Graph = OriginalGraph[i];
        Array[i].Dead = false;
    }
}

Tool::~Tool()
{
    for (int i = 0; i < DropToolMax; i++)
    {
        DeleteGraph(OriginalGraph[i]);
        DeleteGraph(Array[i].Graph);
        OriginalGraph[i] = -1;
        Array[i].Graph = -1;
    }
}

void Tool::Initialize()
{
    for (int i = 0; i < DropToolMax; i++)
    {
        Array[i].X = DropToolFirstPosX + 250 * i;
        Array[i].Y = DropToolFirstPosY;
        Array[i].DropTime = GetRand(DropCoolTimeMax);
        Array[i].Radian = 0;
        Array[i].Graph = OriginalGraph[i];
        Array[i].Dead = false;
    }
}

bool Tool::CheckHit(int PlayerX, int PlayerY, float Radius) const
{
    for (int i = 0; i < DropToolMax; i++)
    {
        float VX = PlayerX - (Array[i].X + Width / 2);
        float VY = PlayerY - (Array[i].Y + Height / 2);
        float Hypotenuse = pow(VX,2) + pow(VY,2);
        float SumRadius = Radius + (Width / 2);
        if (Hypotenuse <= SumRadius * SumRadius)
        {
            return true;
        }
    }
    return false;
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
            if (Array[i].Y >= EndPositionY || Array[i].Dead)
            {
                Array[i].Y = DropToolFirstPosY;
                Array[i].DropTime = GetRand(DropCoolTimeMax);
                Array[i].Radian = 0;
            }
        }
    }
}

void Tool::Draw()
{
    for (int i = 0; i < DropToolMax; i++)
    {
        DrawRotaGraph(Array[i].X + Width / 2, Array[i].Y + Height / 2, 1.0, Array[i].Radian, Array[i].Graph, TRUE);
        //DrawCircle(Array[i].X + Width / 2, Array[i].Y + Height / 2, Height / 2, GetColor(0, 255, 0), FALSE);
    }
}
