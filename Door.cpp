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
           Open = false;
       }
       else
       {
           Open = true;
       }
       CoolTime = CoolTimeMax;
   }
}

bool Door::OnDoor(int PlayerX)
{
    if (PlayerX >= 1700 && Open)
    {
        return true;
    }
    return false;
}


