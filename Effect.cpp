#include "DxLib.h"
#include "Effect.h"

Effect::Effect() :
    AnimCoolTime(0),
    AnimNum(0),
    AnimFrame(0),
    VisibleTime(0),
    IsVisible(false)
{
    LoadDivGraph("Img/Effect.png", 9, 9, 1, 128, 128, Graph);
}

Effect::~Effect()
{
    InitGraph();
}

void Effect::Update(float DeltaTime)
{
    if (IsVisible)
    {
        VisibleTime += DeltaTime;
        if (VisibleTime >= 1.125f)
        {
            IsVisible = false;
            VisibleTime = 0;
        }
        if ((AnimCoolTime -= DeltaTime) <= 0)
        {
            AnimNum++;
            AnimCoolTime = AnimCoolTimeMax;
        }
        AnimFrame = (AnimNum % 9);
    }
}

void Effect::Draw()
{
    if (IsVisible)
    {
        DrawGraph(1615,800,Graph[AnimFrame],TRUE);
    }
}
