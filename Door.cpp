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
    LoadDivGraph("../../Img/Door.png", TotalGraphNum,SideNum,WarpNum, Width, Height,Graph);
}

Door::~Door()
{
    DeleteGraph(Graph[0]);
    DeleteGraph(Graph[1]);
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
