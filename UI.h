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
<<<<<<< HEAD
    //褒めるUIの描画
    void DrawGoodUI(float DeltaTime);
    void SetVisible() { Visible = true; CoolTime = CoolTimeMax; }
=======
>>>>>>> origin/main

private:
    const int FontSize = 48;
    const int IconWidth = 60;
    const int LimitTimePosX = 850;
    const int ScorePosX = 500;
<<<<<<< HEAD

    //プレイヤーのミス回数カウント
    const int MissStringPosX = 1200;
    const int MissStringPosY = 10;
    int PlayerHeadGraph;

    //褒めるUI
    const int GoodUIPosX = 1620;
    const int GoodUIPosY = 100;
    const int CoolTimeMax = 3;
    int GoodUI;
    float CoolTime;
    int ExcellentUI;
    bool Visible;
=======
    const int MissStringPosX = 1200;
    const int MissStringPosY = 10;

    int Graph;
>>>>>>> origin/main
};

