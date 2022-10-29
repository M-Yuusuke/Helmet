#include "DxLib.h"
#include "Title.h"
#include "Scene.h"
#include "BackGround.h"
#include "Sound.h"

Title::Title():
    Alpha(0),
    BToPlay(LoadGraph("Img/BToPlay.png"))
{
}

Title::~Title()
{
    InitGraph();
}

void Title::Update(Scene* scene, Sound* sound)
{
    Alpha++;
    if (Alpha > MaxColor)
    {
        Alpha = 0;
    }
    GetJoypadXInputState(DX_INPUT_PAD1, &input);
    //Bボタンが入力されたら
    if (input.Buttons[13] == 1)
    {
        sound->PlayGame();
        scene->NextScene();
    }
}

void Title::Draw(BackGround* background,Scene* scene)
{
    ClearDrawScreen();
    background->Draw(scene->GetScene());
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, Alpha);
    DrawGraph(550, 700, BToPlay, TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    //if (CheckHitKey(KEY_INPUT_SPACE))
    //{
    //    sound->PlayGame();
    //    scene->NextScene();
    //}
    ScreenFlip();
}
