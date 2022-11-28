#include "DxLib.h"
#include "Door.h"
#include "Sound.h"

Door* Door::Instance = nullptr;
Door::Door() :
    CoolTime(CoolTimeMax),
    AnimNum(0),
    Open(false),
    OpenPrev(false)
{
    LoadDivGraph("Img/Door.png", TotalGraphNum,2,1, Width, Height,Graph);
}

Door::~Door()
{
    DeleteGraph(Graph[0]);
    DeleteGraph(Graph[1]);
}

void Door::Create()
{
    if (!Instance)
    {
        Instance = new Door;
    }
}

void Door::Destroy()
{
    delete Instance;
    Instance = nullptr;
}

void Door::Initialize()
{
    CoolTime = CoolTimeMax;
    AnimNum = 0;
    Open = false;
    OpenPrev = false;
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
    DrawGraph(DoorPosX, DoorPosY, Graph[AnimNum], TRUE);
}