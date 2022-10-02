#include <math.h>
#include "DxLib.h"
#include "Tool.h"

Tool::Tool()
{
    LoadDivGraph("../../Img/DropTools.png", 5, 5, 1, Width, Height, OriginalGraph);
    for (int i = 0; i < DropToolMax; i++)
    {
        Array[i].X = 400 + 200 * i;
        Array[i].Y = Height;
        Array[i].DropTime = GetRand(5);
        Array[i].Radian = 0;
        Array[i].Graph = OriginalGraph[i];
    }
    DropSpeed = 500;
}

void Tool::Update(float DeltaTime)
{
    for (int i = 0; i < DropToolMax; i++)
    {
        Array[i].DropTime -= DeltaTime;
        if (Array[i].DropTime <= 0)
        {
            Array[i].Y += DropSpeed * DeltaTime;
            //Array[i].Radian += static_cast<float>((PI / 180) * 5);
            if (Array[i].Y >= EndPositionY)
            {
                Array[i].Y = Height;
                Array[i].DropTime = GetRand(5);
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
