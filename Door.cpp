#include "DxLib.h"
#include "Door.h"

Door::Door()
{
    X = 1615;
    Y = 802;
    Width = 176.5;
    Height = 192;
    TotalGraphNum = 2;
    SideNum = 2;
    WarpNum = 1;
    CoolTime = CoolTimeMax;
    LoadDivGraph("../../Img/Door.png", TotalGraphNum,SideNum,WarpNum, Width, Height,Graph);
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
       CoolTime = CoolTimeMax;
   }
}


