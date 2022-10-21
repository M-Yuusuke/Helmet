#pragma once
class Rule
{
public:
    Rule();
    ~Rule();
    //���Ԋ֘A
    void Initialize();
    bool CheckEnd(int PlayerDeadNum);
    void SetStartTime() { StartTime = GetNowCount(); }
    void SetNowTime() { NowTime = GetNowCount(); }
    void SetDeltaTime() { DeltaTime = (NowTime - PrevTime) / 1000.0f; }
    void SetPrevTime() { PrevTime = NowTime; }
    int GetLimitTime() const { return MaxLimit - (NowTime - StartTime) / 1000.0f; }
    float GetDeltaTime() const { return DeltaTime; }

    //�X�R�A�֘A
    void AddScore() { Score += AddPoint; }
    int GetScore() const { return Score; }

private:
    const int MaxLimit = 60;
    const int AddPoint = 10;

    float NowTime;
    float PrevTime;
    float StartTime;
    float DeltaTime;
    int Score;
};

