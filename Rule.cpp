#include "DxLib.h"
#include "Rule.h"

Rule::Rule():
    NowTime(0),
    PrevTime(0),
    Score(0),
    End(false)
{
}

Rule::~Rule()
{
}

void Rule::Initialize()
{
    NowTime = 0;
    PrevTime = 0;
    Score = 0;
}

bool Rule::CheckEnd(int PlayerDeadNum)
{
    if (PlayerDeadNum == 3 || GetLimitTime() <= 0)
    {
        return true;
    }
    return false;
}
