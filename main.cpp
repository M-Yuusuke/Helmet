#include "DxLib.h"
#include "Rule.h"
<<<<<<< HEAD
#include "HitCheck.h"
#include "UI.h"
#include "Sound.h"
=======
#include "UI.h"
>>>>>>> origin/main
#include "BackGround.h"
#include "Door.h" 
#include "Player.h"
#include "Tool.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //�t���X�N���[�����[�h
    ChangeWindowMode(FALSE);
    //�𑜓x�E�J���[�r�b�g���̎w��
    SetGraphMode(1920, 1080, 32);

    // �c�w���C�u��������������
    if (DxLib_Init() == -1)
    {
        // �G���[���N�����璼���ɏI��
        return -1;
    }

    Rule* rule = new Rule();
<<<<<<< HEAD
    HitCheck* hitcheck = new HitCheck();
    UI* ui = new UI();
    Sound* sound = new Sound();
=======
    UI* ui = new UI();
>>>>>>> origin/main
    BackGround* background = new BackGround();
    Door* door = new Door();
    Player* player = new Player();
    Tool* tool = new Tool();
    int End;

    sound->PlayGame();
    rule->SetStartTime();
    while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
    {
        End = rule->CheckEnd(player->GetDeadNum());
        //�v���C���[�Đ���
        if (player->GetDead())
        {
<<<<<<< HEAD
            sound->PlayMiss();
=======
>>>>>>> origin/main
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
        door->Update(rule->GetDeltaTime());
        player->Update(rule->GetDeltaTime(),door,tool);
        hitcheck->OnDoor(player,door,ui);
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
<<<<<<< HEAD
        ui->DrawGoodUI(rule->GetDeltaTime());
=======
>>>>>>> origin/main
       
        ScreenFlip();
        rule->SetPrevTime();
    }

    delete rule;
<<<<<<< HEAD
    delete hitcheck;
    delete ui;
    delete sound;
    delete background;
    delete door;
=======
    delete ui;
    delete background;
>>>>>>> origin/main
    delete player;
    delete tool;

    DxLib_End();				// �c�w���C�u�����g�p�̏I������ 
    return 0;				// �\�t�g�̏I��  

}