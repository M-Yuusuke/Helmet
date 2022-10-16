#include "DxLib.h"
#include "GameMain.h"
#include "SceneManager.h"
#include "Rule.h"
#include "UI.h"
#include "HitCheck.h"
#include "BackGround.h"
#include "Door.h"
#include "Player.h"
#include "Tool.h"
#include "Sound.h"

GameMain::GameMain()
{
}

void GameMain::GameLoop(SceneManager* scenemanager, Rule* rule,
                        UI* ui, HitCheck* hitcheck, BackGround* background,
                        Door* door, Player* player, Tool* tool, Sound* sound)
{
    //ゲームクリア
    if (rule->GetLimitTime() == 0 && player->GetDeadNum() <= 2)
    {
        sound->PlayClear();
        scenemanager->ChangeGameClear();
    }
    //ゲームオーバー
    if (player->GetDeadNum() == 3)
    {
        sound->PlayOver();
        scenemanager->ChangeGameOver();
    }

    //プレイヤー再生成
    if (player->GetDead())
    {
        sound->PlayMiss();
        scenemanager->NewPalyer();
    }
    if (player->GetGoal())
    {
        sound->PlayInDoor();
        scenemanager->NewPalyer();
        rule->AddScore();
    }

    ClearDrawScreen();
    rule->SetNowTime();
    rule->SetDeltaTime();

    //更新処理郡
    door->Update(rule->GetDeltaTime(), sound);
    player->Update(rule->GetDeltaTime(), door, tool, sound);
    hitcheck->OnDoor(player, door, ui);
    tool->Update(rule->GetDeltaTime());

    //描画処理郡
    background->Draw();
    door->Draw();
    player->Draw();
    tool->Draw();

    //UI処理
    ui->WriteLimitTime(rule->GetLimitTime());
    ui->WriteScore(rule->GetScore());
    ui->DrawPlayerDead(player->GetDeadNum());
    ui->DrawGoodUI(rule->GetDeltaTime());

    ScreenFlip();
    rule->SetPrevTime();
}
