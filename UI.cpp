#include "DxLib.h"
#include "UI.h"

UI* UI::Instance = nullptr;
UI::UI():
    PlayerHeadGraph(LoadGraph("Img/DeadIcon.png")),
    GoodUI(LoadGraph("Img/GoodUI.png")),
    ExcellentUI(LoadGraph("Img/ExcellentUI.png")),
    CoolTime(0),
    GoodUIVisible(false),
    ExcellentUIVisible(false)
{
    if (AddFontResourceEx("Img/font/misaki_gothic_2nd.ttf", FR_PRIVATE, NULL) > 0)
    {
        ;
    }
    else
    {
        //フォント読み込みエラー処理
        MessageBox(NULL, "フォント読込失敗", "", MB_OK);
    }
    SetFontSize(FontSize);
    ChangeFont("美咲ゴシック第2", DX_CHARSET_DEFAULT);
}

UI::~UI()
{
    DeleteGraph(PlayerHeadGraph);
    DeleteGraph(GoodUI);
    DeleteGraph(ExcellentUI);
    //外部フォントのデータ削除
    if (RemoveFontResourceEx("Img/font/misaki_gothic_2nd.ttf", FR_PRIVATE, NULL))
    {
        ;
    }
    else
    {
        MessageBox(NULL, "remove failure", "", MB_OK);
    }
}

void UI::Create()
{
    if (!Instance)
    {
        Instance = new UI;
    }
}

void UI::Destroy()
{
    delete Instance;
    Instance = nullptr;
}

void UI::Initialize()
{
    CoolTime = 0;
    SetFontSize(FontSize);
}

void UI::TitleWriteBToPlay()
{
    SetFontSize(160);
    DrawString(ResultUIPosX, 800, "B", GetColor(255, 0, 0));
    DrawString(ResultUIPosX, 800, "  To Play", GetColor(255, 255, 255));
}

void UI::WriteLimitTime(int LimitTime)
{
    SetFontSize(FontSize);
    if (LimitTime >= 0)
    {
        DrawFormatString(LimitTimePosX, UIPosY, GetColor(0, 0, 0), "Limit:%d", LimitTime);
    }
    else
    {
        DrawFormatString(LimitTimePosX, UIPosY, GetColor(0, 0, 0), "Limit:0");
    }
}

void UI::WriteScore(int Score)
{
    DrawFormatString(ScorePosX, UIPosY, GetColor(0, 0, 0), "Score:%d", Score);
}

void UI::DrawPlayerDead(int LifeNum)
{
    if (LifeNum > 0)
    {
        DrawFormatString(LifeStringPosX, UIPosY, GetColor(0, 0, 0), "LIFE:");
    }
    for (int i = 0; i <= LifeNum; i++)
    {
        if (i != 0)
        {
            DrawGraph(1300 + i * IconWidth, UIPosY, PlayerHeadGraph, TRUE);
        }
    }
}

void UI::Update(float Deltatime)
{
    CoolTime -= Deltatime;
    if (CoolTime <= 0)
    {
        GoodUIVisible = false;
        ExcellentUIVisible = false;
    }
}

void UI::DrawPraise()
{
    if (GoodUIVisible)
    {
        DrawGraph(GoodUIPosX, GoodUIPosY, GoodUI, TRUE);
    }
    if (ExcellentUIVisible)
    {
        DrawGraph(GoodUIPosX, GoodUIPosY, ExcellentUI, TRUE);
    }
    if (GoodUIVisible || ExcellentUIVisible)
    {
        //メータの変動部分描画
        DrawBox(MeterPosX, MeterPosY, MeterPosX + (CoolTime * 50), MeterPosY + MeterHeight, GetColor(00, 00, 255), TRUE);
    }
}

void UI::SetVisible()
{
    if (GoodUIVisible)
    {
        ExcellentUIVisible = true;
    }
    else
    {
        GoodUIVisible = true;
    }
    CoolTime = CoolTimeMax;
}

//リザルト画面
void UI::ResultWriteScore(int Score)
{
    SetFontSize(160);
    DrawFormatString(650, 500, GetColor(255, 255, 0), "Score:%d", Score);
}

void UI::ResultWriteBToTitle()
{
    DrawString(ResultUIPosX, ResultUIPosY, "B", GetColor(255, 0, 0));
    DrawString(ResultUIPosX, ResultUIPosY, "  To Title", GetColor(255, 255, 255));
}
