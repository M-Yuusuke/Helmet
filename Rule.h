#pragma once
class Rule
{
public:
    Rule();
    ~Rule();
    void SetNowTime() { NowTime = GetNowCount(); }
    void SetPrevTime() { PrevTime = NowTime; }
    float GetDeltaTime() { return (NowTime - PrevTime) / 1000.0f; }

private:
    int NowTime;
    int PrevTime;
    int Score;
};

