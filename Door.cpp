#include "DxLib.h"
#include "Door.h"

Door::Door() :
    X(DoorPositionX),
    Y(DoorPositionY),
    CoolTime(CoolTimeMax)
{
    LoadDivGraph("../../Img/Door.png", TotalGraphNum,2,1, Width, Height,Graph);
}

Door::~Door()
{
    DeleteGraph(Graph[0]);
    DeleteGraph(Graph[1]);
}

void Door::Initialize()
{
    CoolTime = CoolTimeMax;
}

void Door::Draw()
{
    DrawGraph(X, Y, Graph[AnimNum], TRUE);
}

void Door::Update(float DeltaTime)
{
   CoolTime -= DeltaTime;
   if (CoolTime <= 0)
   {
       AnimNum = GetRand(1);
       if (AnimNum == 0)
       {
           Open = false;
       }
       else
       {
           Open = true;
       }
       CoolTime = CoolTimeMax;
   }
}
