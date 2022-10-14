#include "DxLib.h"
#include "Door.h"
#include "Sound.h"

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


void Door::Update(float DeltaTime,Sound* sound)
{
   CoolTime -= DeltaTime;
   if (CoolTime <= 0)
   {
       AnimNum = GetRand(1);
       OpenPrev = Open;
       if (AnimNum == 0)
       {
           Open = false;
       }
       else
       {
           Open = true;
       }
       if (OpenPrev != Open)
       {
           if (Open)
           {
               sound->PlayOpenDoor();
           }
           else
           {
               sound->PlayCloseDoor();
           }
       }
       CoolTime = CoolTimeMax;
   }
}

void Door::Draw()
{
    DrawGraph(X, Y, Graph[AnimNum], TRUE);
}