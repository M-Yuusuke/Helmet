#include "DxLib.h"
#include "Timer.h"

Timer::Timer()
{
    Now = 0.0f;
    Prev = 0.0f;
}

Timer::~Timer()
{
}

void Timer::SetNowTime()
{
    Now = GetNowCount();
}

void Timer::SetPrevTime()
{
    Prev = Now;
}

float Timer::GetDeltaTime()
{
    return (Now - Prev) / 1000.0f;
}
