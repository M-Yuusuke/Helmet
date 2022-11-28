#pragma once
class UI
{
public:
    static void Create();
    static void Destroy();
    static UI* GetInstance() { return Instance; }

    void Initialize();
    //タイトル画面
    void TitleWriteBToPlay();
    //制限時間
    void WriteLimitTime(int LimitTime);
    //スコア
    void WriteScore(int Score);
    //プレイヤーの死亡回数描画
    void DrawPlayerDead(int LifeNum);
    //褒めるUI関係
    void Update(float Deltatime);
    void DrawPraise();
    void SetVisible();
    bool GetExcellentUIVisible() const { return ExcellentUIVisible; }

    //リザルト画面
    void ResultWriteScore(int Score);
    void ResultWriteBToTitle();

private:
    UI();
    ~UI();
    static UI* Instance;

    const int FontSize = 60;
    const int LimitTimePosX = 850;
    const int UIPosY = 20;
    const int ScorePosX = 500;

    //プレイヤーの残機表示
    const int LifeStringPosX = 1200;
    const int IconWidth = 75;
    int PlayerHeadGraph;

    //褒めるUI
    const int GoodUIPosX = 1620;
    const int GoodUIPosY = 100;

    const int MeterPosX = 1620;
    const int MeterPosY = 400;
    const int MeterHeight = 32;
    //アニメーションの表示時間
    const float CoolTimeMax = 5.0f;

    int GoodUI;
    int ExcellentUI;
    float CoolTime;
    bool GoodUIVisible;
    bool ExcellentUIVisible;

    //リザルト画面
    const int ResultUIPosX = 600;
    const int ResultUIPosY = 700;

};

