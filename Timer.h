#pragma once
class Timer
{
public:
    Timer();
    ~Timer();
    void SetNowTime();
    void SetPrevTime();
    float GetDeltaTime();

private:
    float Now;
    float Prev;
};

