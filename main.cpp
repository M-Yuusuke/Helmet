#include "DxLib.h"
#include "Rule.h"
#include "UI.h"
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
    UI* ui = new UI();
    BackGround* background = new BackGround();
    Door* door = new Door();
    Player* player = new Player();
    Tool* tool = new Tool();
    int End;

    rule->SetStartTime();
    while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
    {
        End = rule->CheckEnd(player->GetDeadNum());
        //�v���C���[�Đ���
        if (player->GetDead())
        {
            delete player;
            player = new Player();
        }
        if (player->GetGoal())
        {
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
       
        ScreenFlip();
        rule->SetPrevTime();
    }

    delete rule;
    delete ui;
    delete background;
    delete player;
    delete tool;

    DxLib_End();				// �c�w���C�u�����g�p�̏I������ 
    return 0;				// �\�t�g�̏I��  

}