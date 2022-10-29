#include "DxLib.h"
#include "Result.h"
#include "Scene.h"
#include "BackGround.h"
#include "Sound.h"
#include "Player.h"
#include "UI.h"

Result::Result():
    Alpha(0)
{
}

Result::~Result()
{
}

void Result::Update(Scene* scene, Sound* sound)
{
    Alpha++;
    if (Alpha > MaxColor)
    {
        Alpha = 0;
    }
    GetJoypadXInputState(DX_INPUT_PAD1, &input);
    //Bƒ{ƒ^ƒ“‚ª“ü—Í‚³‚ê‚½‚ç
    if (input.Buttons[13] == 1)
    {
        //sound->PlayTitle();
        scene->NextScene();
    }
}

void Result::Draw(int Score, Player* player, UI* ui, BackGround* background, Scene* scene)
{
    ClearDrawScreen();
    background->Draw(scene->GetScene());
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, Alpha);
    //DrawGraph(550, 700, BToTitle, TRUE);
    ui->ResultWriteBToTitle();
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    ui->ResultWriteScore(Score);
    player->ResultDraw();
    ScreenFlip();
}
