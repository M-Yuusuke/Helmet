#include "DxLib.h"
#include "GameClear.h"
#include "SceneManager.h"
#include "Rule.h"
#include "Sound.h"

GameClear::GameClear():
    BackGround(LoadGraph("../../Img/GameClear.png"))
{
}

void GameClear::GameClearDraw(SceneManager* scenemanager,Sound* sound, Rule* rule)
{
    ClearDrawScreen();
    DrawGraph(0, 0, BackGround, TRUE);
    DrawFormatString(600, 800, GetColor(255, 255, 0), "Score:%d", rule->GetScore());
    if (CheckHitKey(KEY_INPUT_SPACE))
    {
        sound->PlayTitle();
        scenemanager->NextScene();
    }
    ScreenFlip();
}
