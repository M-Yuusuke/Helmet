#pragma once
class Rule
{
public:
    Rule();
    ~Rule();
    void Initialize();
    void SetNowTime() { NowTime = GetNowCount(); }
    void SetPrevTime() { PrevTime = NowTime; }
    void SetStartTime() { StartTime = GetNowCount(); }
    int GetLimitTime() { return MaxLimit - (NowTime - StartTime) / 1000.0f; }
    void SetDeltaTime() { DeltaTime = (NowTime - PrevTime) / 1000.0f; }
    float GetDeltaTime() { return DeltaTime; }

private:
    const int MaxLimit = 30;
    int NowTime;
    int PrevTime;
    int StartTime;
    int LimitTime;
    float DeltaTime;
    int Score;
};

