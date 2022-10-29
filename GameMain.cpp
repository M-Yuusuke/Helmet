#include "DxLib.h"
#include "GameMain.h"
#include "Scene.h"
#include "Rule.h"
#include "UI.h"
#include "Effect.h"
#include "HitCheck.h"
#include "BackGround.h"
#include "Door.h"
#include "Player.h"
#include "Tool.h"
#include "Sound.h"

GameMain::GameMain()
{
}

void GameMain::Update(Scene* scene, Rule* rule, UI* ui, Effect* effect, HitCheck* hitcheck, Door* door, Player* player, Tool* tool, Sound* sound)
{
    //ゲームクリア
    if (rule->GetLimitTime() <= 0 && player->GetLifeNum() >= 1)
    {
        sound->PlayClear();
        player->ResultRandomPlayer();
        scene->ChangeGameClear();
    }
    //ゲームオーバー
    if (player->GetLifeNum() == 0)
    {
        sound->PlayOver();
        player->ResultRandomPlayer();
        scene->ChangeGameOver();
    }

    //プレイヤー再生成
    if (player->GetDead())
    {
        sound->PlayMiss();
        WaitTimer(250);
        rule->DecreaseScore();
        player->NewPlayer();
    }
    if (player->GetGoal())
    {
        sound->PlayInDoor();
        ui->SetVisible();
        player->NewPlayer();
        rule->IncreaseScore(ui->GetExcellentUIVisible());
    }

    ClearDrawScreen();
    rule->SetNowTime();
    rule->SetDeltaTime();

    //更新処理郡
    door->Update(rule->GetDeltaTime(), sound);
    player->Update(rule->GetDeltaTime(), door, tool, sound);
    hitcheck->OnDoor(player, door, effect);
    tool->Update(rule->GetDeltaTime());
    ui->Update(rule->GetDeltaTime());
    effect->Update(rule->GetDeltaTime());
}

void GameMain::Draw(Rule* rule, UI* ui, Effect* effect, BackGround* background,
                    Door* door, Player* player, Tool* tool,Scene* scene)
{
    //描画処理郡
    background->Draw(scene->GetScene());
    door->Draw();
    player->Draw();
    tool->Draw();

    //UI処理
    ui->WriteLimitTime(rule->GetLimitTime());
    ui->WriteScore(rule->GetScore());
    ui->DrawPlayerDead(player->GetLifeNum());
    ui->DrawPraise();

    effect->Draw();

    ScreenFlip();
    rule->SetPrevTime();
}
