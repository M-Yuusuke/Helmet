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
    float GetLimitTime() const { return MaxLimit - (NowTime - StartTime) / 1000.0f; }
    float GetDeltaTime() const { return DeltaTime; }

    //スコア関連
    void IncreaseScore(bool IsExcellent);
    void DecreaseScore();
    int GetScore() const { return Score; }

private:
    const int MaxLimit = 60;
    const int GoodPoint = 10;
    const int ExcellentPoint = 30;
    const int DecreasePoint = 30;

    float NowTime;
    float PrevTime;
    float StartTime;
    float DeltaTime;
    int Score;
};

