#include "DxLib.h"
#include "Door.h"

Door::Door()
{
    X = 1615;
    Y = 802;
    TotalGraphNum = 2;
    SideNum = 2;
    WarpNum = 1;
    CoolTime = CoolTimeMax;
    AnimNum = 0;
    LoadDivGraph("../../Img/Door.png", TotalGraphNum,SideNum,WarpNum, Width, Height,Graph);
    IsOpen = false;
}

Door::~Door()
{
    for (int i = 0; i < 2; i++)
    {
        DeleteGraph(Graph[i]);
    }
}

void Door::Draw()
{
    DrawGraph(X, Y, Graph[AnimNum], TRUE);
}

void Door::Update(float deltaTime)
{
   CoolTime -= deltaTime;
   if (CoolTime <= 0)
   {
       AnimNum = GetRand(1);
       if (AnimNum == 0)
       {
           IsOpen = false;
       }
       else
       {
           IsOpen = true;
       }
       CoolTime = CoolTimeMax;
   }
}

bool Door::OnDoor(int PlayerX)
{
    if (PlayerX >= 1700 && IsOpen)
    {
        return true;
    }
    return false;
}


