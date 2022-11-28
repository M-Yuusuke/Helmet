#include "DxLib.h"
#include "GameMain.h"
#include "SceneManager.h"
#include "Rule.h"
#include "UI.h"
#include "Effect.h"
#include "HitCheck.h"
#include "Door.h"
#include "Player.h"
#include "Tool.h"
#include "Sound.h"

GameMain* GameMain::Instance = nullptr;
GameMain::GameMain()
{
    if (Background == -1)
    {
        Background = LoadGraph("Img/BackGround/BackGround.png");
    }
}

GameMain::~GameMain()
{
    DeleteGraph(Background);
}

void GameMain::Create()
{
    if (!Instance)
    {
        Instance = new GameMain;
    }
}

void GameMain::Destroy()
{
    delete Instance;
    Instance = nullptr;
}

SceneBase* GameMain::Update(SceneManager* sceneManager)
{
    //ƒvƒŒƒCƒ„[Ä¶¬
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

    rule->SetNowTime();
    rule->SetDeltaTime(); 

    //XVˆ—ŒS
    door->Update(rule->GetDeltaTime(), sound);
    player->Update(rule->GetDeltaTime(), door, tool, sound, effect);
    hitcheck->OnDoor(player, door, effect);
    tool->Update(rule->GetDeltaTime());
    ui->Update(rule->GetDeltaTime());
    effect->Update(rule->GetDeltaTime());

    if (rule->CheckClear(player, sound) != 0)
    {
        return sceneManager->GetNextScene(this);
        //delete this;
        //return new Result;
    }

    return this;
}

void GameMain::Draw()
{
    ClearDrawScreen();
    //•`‰æˆ—ŒS
    DrawGraph(0, 0, Background, FALSE);
    door->Draw();
    player->Draw();
    tool->Draw();

    //UIˆ—
    ui->WriteLimitTime(rule->GetLimitTime());
    ui->WriteScore(rule->GetScore());
    ui->DrawPlayerDead(player->GetLifeNum());
    ui->DrawPraise();

    effect->Draw();

    ScreenFlip();
    rule->SetPrevTime();
}