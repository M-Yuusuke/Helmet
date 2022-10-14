#include "DxLib.h"
#include "SceneManager.h"
#include "Rule.h"
#include "HitCheck.h"
#include "UI.h"
#include "Sound.h"
#include "BackGround.h"
#include "Door.h" 
#include "Player.h"
#include "Tool.h"

SceneManager::SceneManager():
    rule(new Rule()),
    hitcheck(new HitCheck()),
    ui(new UI()),
    sound(new Sound()),
    background(new BackGround()),
    door(new Door()),
    player(new Player()),
    tool(new Tool()),
    scene(INIT)
{
}

SceneManager::~SceneManager()
{
    delete rule;
    delete hitcheck;
    delete ui;
    delete sound;
    delete background;
    delete door;
    delete player;
    delete tool;
}

void SceneManager::Initialize()
{
    rule->Initialize();
    ui->Initialize();
    door->Initialize();
    player->Initialize();
    tool->Initialize();
    sound->PlayTitle();
    WaitTimer(250);
    scene = TITLE;
}

void SceneManager::Title()
{
    ClearDrawScreen();
    SetFontSize(48);
    DrawFormatString(500, 500, GetColor(255, 255, 255), "�^�C�g��");
    DrawFormatString(500, 700, GetColor(255, 255, 255), "SPACE�L�[�ŃQ�[���X�^�[�g");
    if (CheckHitKey(KEY_INPUT_SPACE))
    {
        sound->PlayGame();
        rule->SetStartTime();
        sound->PlayGame();
        scene = GAMEMAIN;
    }
    ScreenFlip();
}

void SceneManager::GameMain()
{
    if (rule->GetLimitTime() == 0 && player->GetDeadNum() <= 2)
    {
        sound->PlayClear();
        scene = CLEAR;
    }
    if (player->GetDeadNum() == 3)
    {
        sound->PlayOver();
        scene = OVER;
    }
    //�v���C���[�Đ���
    if (player->GetDead())
    {
        sound->PlayMiss();
        delete player;
        player = new Player();
    }
    if (player->GetGoal())
    {
        sound->PlayInDoor();
        delete player;
        player = new Player();
        rule->AddScore();
    }

    ClearDrawScreen();
    rule->SetNowTime();
    rule->SetDeltaTime();

    //�X�V�����S
    door->Update(rule->GetDeltaTime(),sound);
    player->Update(rule->GetDeltaTime(), door, tool, sound);
    hitcheck->OnDoor(player, door, ui);
    tool->Update(rule->GetDeltaTime());

    //�`�揈���S
    background->Draw();
    door->Draw();
    player->Draw();
    tool->Draw();

    //UI����
    ui->WriteLimitTime(rule->GetLimitTime());
    ui->WriteScore(rule->GetScore());
    ui->DrawPlayerDead(player->GetDeadNum());
    ui->DrawGoodUI(rule->GetDeltaTime());
    DrawFormatString(0, 0, GetColor(255, 255, 255), "%f", rule->GetDeltaTime());

    ScreenFlip();
    rule->SetPrevTime();
}

void SceneManager::Clear()
{
    ClearDrawScreen();
    SetFontSize(48);
    DrawFormatString(500, 500, GetColor(255, 255, 255), "�Q�[���N���A�I");
    DrawFormatString(500, 700, GetColor(255, 255, 255), "SPACE�L�[�Ń^�C�g����");
    if (CheckHitKey(KEY_INPUT_SPACE))
    {
        sound->PlayTitle();
        scene = INIT;
    }
    ScreenFlip();
}

void SceneManager::Over()
{
    ClearDrawScreen();
    SetFontSize(48);
    DrawFormatString(500, 500, GetColor(255, 255, 255), "�Q�[���I�[�o�[");
    DrawFormatString(500, 700, GetColor(255, 255, 255), "SPACE�L�[�Ń^�C�g����");
    if (CheckHitKey(KEY_INPUT_SPACE))
    {
        sound->PlayTitle();
        scene = INIT;
    }
    ScreenFlip();
}

