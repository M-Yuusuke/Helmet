#include "DxLib.h"
#include "Rule.h"

Rule::Rule():
    NowTime(0),
    PrevTime(0),
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
    StartTime = 0;
    DeltaTime = 0;
    Score = 0;
}

void Rule::IncreaseScore(bool IsExcellent)
{
    if (IsExcellent)
    {
        Score += ExcellentPoint;
    }
    else
    {
        Score += GoodPoint;
    }
}

void Rule::DecreaseScore()
{
    Score -= DecreasePoint;
    if (Score < 0)
    {
        Score = 0;
    }
}
