#include "DxLib.h"
#include "Rule.h"

Rule::Rule():
    NowTime(0),
    PrevTime(0),
    LimitTime(MaxLimit),
    Score(0)
{
}

Rule::~Rule()
{
}

void Rule::Initialize()
{
    NowTime = 0;
    PrevTime = 0;
    LimitTime = MaxLimit;
    Score = 0;
}
