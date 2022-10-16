#include "DxLib.h"
#include "GameClear.h"
#include "SceneManager.h"
#include "Sound.h"

GameClear::GameClear():
    BackGround(LoadGraph("../../Img/GameClear.png"))
{
}

void GameClear::GameClearDraw(SceneManager* scenemanager,Sound* sound)
{
    ClearDrawScreen();
    DrawGraph(0, 0, BackGround, TRUE);
    if (CheckHitKey(KEY_INPUT_SPACE))
    {
        sound->PlayTitle();
        scenemanager->NextScene();
    }
    ScreenFlip();
}
