#include "DxLib.h"
#include "SceneManager.h"
#include "Title.h"
#include "Sound.h"

Title::Title():
    Alpha(0),
    BackGround(LoadGraph("../../Img/Title.png")),
    SpaceToPlay(LoadGraph("../../Img/SpaceToPlay.png"))
{
}

Title::~Title()
{
    InitGraph();
}

void Title::TitleDraw(SceneManager* scenemanager,Sound* sound)
{
    Alpha++;
    if (Alpha > MaxColor)
    {
        Alpha = 0;
    }
    ClearDrawScreen();
    DrawGraph(0, 0, BackGround, TRUE);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, Alpha);
    DrawGraph(500, 700, SpaceToPlay, TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    if (CheckHitKey(KEY_INPUT_SPACE))
    {
        sound->PlayGame();
        scenemanager->NextScene();
    }
    ScreenFlip();
}
