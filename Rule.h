#pragma once
class Rule
{
public:
    Rule();
    ~Rule();
    //時間関連
    void Initialize();
    void SetStartTime() { StartTime = GetNowCount(); }
    void SetNowTime() { NowTime = GetNowCount(); }
    void SetDeltaTime() { DeltaTime = (NowTime - PrevTime) / 1000.0f; }
    void SetPrevTime() { PrevTime = NowTime; }
    int GetLimitTime() const { return MaxLimit - (NowTime - StartTime) / 1000.0f; }
    float GetDeltaTime() const { return DeltaTime; }

    //スコア関連
    void AddScore() { Score += AddPoint; }
    int GetScore() const { return Score; }

private:
    const int MaxLimit = 30;
    const int AddPoint = 5;

    int NowTime;
    int PrevTime;
    int StartTime;
    int LimitTime;
    float DeltaTime;
    int Score;
};

