#pragma once
class Rule
{
public:
    Rule();
    ~Rule();
    void SetNowTime() { Now = GetNowCount(); }
    void SetPrevTime() { Prev = Now; }
    float GetDeltaTime() { return (Now - Prev) / 1000.0f; }

private:
    float Now;
    float Prev;
    int Score;

};

