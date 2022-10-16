#include "DxLib.h"
#include "GameOver.h"
#include "SceneManager.h"
#include "Sound.h"

GameOver::GameOver():
    BackGround(LoadGraph("../../Img/GameOver.png"))
{
}

void GameOver::GameOverDraw(SceneManager* scenemanager, Sound* sound)
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
