#include "DxLib.h"
#include "Rule.h"
#include "Result.h"
#include "Player.h"
#include "Sound.h"

Rule* Rule::Instance = nullptr;
float Rule::StartTime = -1;
Rule::Rule():
    NowTime(0),
    PrevTime(0),
    Score(0)
{
}

Rule::~Rule()
{
}

void Rule::Create()
{
    if (!Instance)
    {
        Instance = new Rule;
    }
}

void Rule::Destroy()
{
    delete Instance;
    Instance = nullptr;
}

int Rule::CheckClear(Player* player,Sound* sound)
{
    //ゲームクリア
    if (GetLimitTime() <= 0 && player->GetLifeNum() >= 1)
    {
        Clear = true;
        player->ResultRandomPlayer();
        sound->PlayClear();
        return 1;
    }
    //ゲームオーバー
    else if (player->GetLifeNum() == 0)
    {
        Clear = false;
        player->ResultRandomPlayer();
        sound->PlayOver();
        return 2;
    }
    else
    {
        return 0;
    }
}

void Rule::Initialize()
{
    NowTime = 0;
    PrevTime = 0;
    StartTime = 0;
    DeltaTime = 0;
    Score = 0;
    Clear = false;
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
