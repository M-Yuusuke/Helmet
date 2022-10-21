#include "DxLib.h"
#include "UI.h"

UI::UI():
    PlayerHeadGraph(LoadGraph("../../Img/DeadIcon.png")),
    GoodUI(LoadGraph("../../Img/GoodUI.png")),
    ExcellentUI(LoadGraph("../../Img/ExcellentUI.png")),
    CoolTime(0),
    Visible(false)
{
    SetFontSize(FontSize);
}

UI::~UI()
{
    DeleteGraph(PlayerHeadGraph);
    DeleteGraph(GoodUI);
    DeleteGraph(ExcellentUI);
}

void UI::Initialize()
{
    CoolTime = 0;
    Visible = false;
}

void UI::WriteLimitTime(int LimitTime)
{
    if (LimitTime >= 0)
    {
        DrawFormatString(LimitTimePosX, 0, GetColor(0, 0, 0), "Limit:%d", LimitTime);
    }
    else
    {
        DrawFormatString(LimitTimePosX, 0, GetColor(0, 0, 0), "Limit:0");
    }
}

void UI::WriteScore(int Score)
{
    DrawFormatString(ScorePosX, 0, GetColor(0, 0, 0), "Score:%d", Score);
}

void UI::DrawPlayerDead(int DeadNum)
{
    if (DeadNum > 0)
    {
        DrawFormatString(MissStringPosX, MissStringPosY, GetColor(0, 0, 0), "MISS:");
    }
    for (int i = 0; i <= DeadNum; i++)
    {
        if (i != 0)
        {
            DrawGraph(1270 + i * IconWidth, 0, PlayerHeadGraph, TRUE);
        }
    }
}

void UI::DrawGoodUI(float DeltaTime)
{
    if (Visible && CoolTime > 0)
    {
        CoolTime -= DeltaTime;
        DrawGraph(GoodUIPosX, GoodUIPosY, GoodUI, TRUE);
    }
    else
    {
        Visible = false;
    }
}
