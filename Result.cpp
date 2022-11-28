#include "DxLib.h"
#include "Result.h"
#include "SceneManager.h"
#include "Rule.h"
#include "Sound.h"
#include "Player.h"
#include "UI.h"

Result* Result::Instance = nullptr;
//int Result::score = 0;
//bool Result::IsClear = false;
Result::Result():
    Alpha(0),
    BackgroundGameClear(LoadGraph("Img/BackGround/GameClear.png")),
    BackgroundGameOver(LoadGraph("Img/BackGround/GameOver.png")),
    Background(-1)
{
}

Result::~Result()
{
    DeleteGraph(BackgroundGameClear);
    DeleteGraph(BackgroundGameOver);
}

void Result::Create()
{
    if (!Instance)
    {
        Instance = new Result;
    }
}

void Result::Destroy()
{
    delete Instance;
    Instance = nullptr;
}

SceneBase* Result::Update(SceneManager* sceneManager)
{
    Alpha++;
    if (Alpha > MaxColor)
    {
        Alpha = 0;
    }
    if (rule->IsClear())
    {
        Background = BackgroundGameClear;
    }
    else
    {
        Background = BackgroundGameOver;
    }
    GetJoypadXInputState(DX_INPUT_PAD1, &input);
    //Bƒ{ƒ^ƒ“‚ª“ü—Í‚³‚ê‚½‚ç
    if (input.Buttons[13] == 1 || CheckHitKey(KEY_INPUT_SPACE))
    {
        return sceneManager->GetNextScene(this);
        //delete this;
        //return new Initialize;
    }
    return this;
}

void Result::Draw()
{
    ClearDrawScreen();
    DrawGraph(0, 0, Background, FALSE);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, Alpha);
    ui->ResultWriteBToTitle();
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    ui->ResultWriteScore(rule->GetScore());
    player->ResultDraw();
    ScreenFlip();
}