#include "DxLib.h"
#include "Effect.h"

Effect* Effect::Instance = nullptr;
Effect::Effect() :
    Damage(LoadGraph("Img/DamageEffect.png")),
    AnimCoolTime(0),
    AnimNum(0),
    VisibleTime(0),
    IsVisible(false)
{
    LoadDivGraph("Img/Effect.png", TotalGraphNum, TotalGraphNum, 1, GraphSize, GraphSize, Graph);
}

Effect::~Effect()
{
    InitGraph();
}

void Effect::OnDamage(float PlayerX, float PlayerY)
{
    IsDamage = true;
    DamageVisibleTime = DamageCoolTimeMax;
    X = PlayerX - 100;
    Y = PlayerY - 100;
}

void Effect::Create()
{
    if (!Instance)
    {
        Instance = new Effect;
    }
}

void Effect::Destroy()
{
    delete Instance;
    Instance = nullptr;
}

void Effect::Update(float DeltaTime)
{
    if (IsVisible)
    {
        VisibleTime += DeltaTime;
        if (VisibleTime >= AnimCoolTimeMax * TotalGraphNum)
        {
            IsVisible = false;
            VisibleTime = 0;
        }
        if ((AnimCoolTime -= DeltaTime) <= 0)
        {
            AnimNum++;
            AnimCoolTime = AnimCoolTimeMax;
        }
        AnimNum %= TotalGraphNum;
    }
    if (IsDamage)
    {
        DamageVisibleTime -= DeltaTime;
        if (DamageVisibleTime <= 0)
        {
            IsDamage = false;
        }
    }
}

void Effect::Draw()
{
    if (IsVisible)
    {
        DrawGraph(EffectPosX, EffectPosY, Graph[AnimNum], TRUE);
    }
    if (IsDamage)
    {
        DrawGraph(X, Y, Damage, TRUE);
    }
}
