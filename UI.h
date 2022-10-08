#pragma once
class UI
{
public:
    UI();
    ~UI();
    //制限時間
    void WriteLimitTime(int LimitTime);
    //スコア
    void WriteScore(int Score);
    //プレイヤーの死亡回数描画
    void DrawPlayerDead(int DeadNum);

private:
    const int FontSize = 48;
    const int IconWidth = 60;
    const int LimitTimePosX = 850;
    const int ScorePosX = 500;
    const int MissStringPosX = 1200;
    const int MissStringPosY = 10;

    int Graph;
};

