#include "DxLib.h"
#include "GameOver.h"
#include "Scene.h"
#include "BackGround.h"
#include "Sound.h"
#include "Player.h"
#include "UI.h"


GameOver::GameOver():
    Alpha(0)
{
}

GameOver::~GameOver()
{
    InitGraph();
}

void GameOver::Update(Scene* scene, Sound* sound)
{
    //if (CheckHitKey(KEY_INPUT_SPACE))
    //{
    //    sound->PlayTitle();
    //    scene->NextScene();
    //}
    Alpha++;
    if (Alpha > MaxColor)
    {
        Alpha = 0;
    }
    GetJoypadXInputState(DX_INPUT_PAD1, &input);
    //Bƒ{ƒ^ƒ“‚ª“ü—Í‚³‚ê‚½‚ç
    if (input.Buttons[13] == 1) 
    {
        sound->PlayTitle();
        scene->NextScene();
    }
}

void GameOver::Draw(int Score, Player* player, UI* ui,BackGround* background,Scene* scene)
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
