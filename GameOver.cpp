#include "DxLib.h"
#include "GameOver.h"
#include "SceneManager.h"
#include "Rule.h"
#include "Sound.h"

GameOver::GameOver():
    BackGround(LoadGraph("../../Img/GameOver.png"))
{
}

void GameOver::GameOverDraw(SceneManager* scenemanager, Sound* sound, Rule*rule)
{
    ClearDrawScreen();
    DrawGraph(0, 0, BackGround, TRUE);
    SetFontSize(48);
    DrawFormatString(800, 600, GetColor(255, 255, 0), "Score:%d", rule->GetScore());
    if (CheckHitKey(KEY_INPUT_SPACE))
    {
        sound->PlayTitle();
        scenemanager->NextScene();
    }
    ScreenFlip();
}
