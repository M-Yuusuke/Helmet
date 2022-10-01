#pragma once
class Rule
{
public:
    Rule();
    ~Rule();
    void SetNowTime() { Now = GetNowCount(); }
    void SetPrevTime() { Prev = Now; }
    float GetDeltaTime() const { return (Now - Prev) / 1000; }

private:
    float Now;
    float Prev;
    int Score;

};

