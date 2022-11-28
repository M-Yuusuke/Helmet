#pragma once
#include "DxLib.h"
class Player;
class Sound;
class Rule
{
public:
    static void Create();
    static void Destroy();
    static Rule* GetInstance() { return Instance; }

    int CheckClear(Player* player,Sound* sound);
    //時間関連
    void Initialize();
    void SetNowTime() { NowTime = GetNowCount(); }
    static void SetStartTime() { StartTime = GetNowCount(); }
    void SetDeltaTime() { DeltaTime = (NowTime - PrevTime) / 1000.0f; }
    void SetPrevTime() { PrevTime = NowTime; }
    float GetLimitTime() const { return MaxLimit - (NowTime - StartTime) / 1000.0f; }
    float GetDeltaTime() const { return DeltaTime; }

    //スコア関連
    void IncreaseScore(bool IsExcellent);
    void DecreaseScore();
    int GetScore() const { return Score; }

    bool IsClear()const { return Clear; }

private:
    Rule();
    ~Rule();
    static Rule* Instance;

    const int MaxLimit = 60;
    const int GoodPoint = 10;
    const int ExcellentPoint = 30;
    const int DecreasePoint = 30;

    float NowTime;
    float PrevTime;
    static float StartTime;
    float DeltaTime;
    int Score;
    bool Clear;
};

