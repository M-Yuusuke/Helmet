#include "DxLib.h"
#include "Rule.h"
#include "SceneManager.h"
#include "HitCheck.h"
#include "UI.h"
#include "Sound.h"
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

    SceneManager* scenemanager = new SceneManager();
    while (true)
    {
        //������
        while (!ProcessMessage() && scenemanager->GetScene() == 0)
        {
            scenemanager->Initialize();
        }

        //�^�C�g��
        while (!ProcessMessage() && scenemanager->GetScene() == 1)
        {
            scenemanager->Title();
        }

        //�Q�[�����C��
        while (!ProcessMessage() && scenemanager->GetScene() == 2)
        {
            scenemanager->GameMain();
        }

        //�Q�[���N���A
        while (!ProcessMessage() && scenemanager->GetScene() == 3)
        {
            scenemanager->Clear();
        }

        //�Q�[���I�[�o�[
        while (!ProcessMessage() && scenemanager->GetScene() == 4)
        {
            scenemanager->Over();
        }

    }
    delete scenemanager;
    //Rule* rule = new Rule();
    //HitCheck* hitcheck = new HitCheck();
    //UI* ui = new UI();
    //Sound* sound = new Sound();
    //BackGround* background = new BackGround();
    //Door* door = new Door();
    //Player* player = new Player();
    //Tool* tool = new Tool();

    //sound->PlayGame();
    //rule->SetStartTime();
    //while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
    //{
    //    //�v���C���[�Đ���
    //    if (player->GetDead())
    //    {
    //        sound->PlayMiss();
    //        delete player;
    //        player = new Player();
    //    }
    //    if (player->GetGoal())
    //    {
    //        sound->PlayInDoor();
    //        delete player;
    //        player = new Player();
    //        rule->AddScore();
    //    }

    //    ClearDrawScreen();
    //    rule->SetNowTime();
    //    rule->SetDeltaTime();

    //    //�X�V�����S
    //    door->Update(rule->GetDeltaTime());
    //    player->Update(rule->GetDeltaTime(), door, tool);
    //    hitcheck->OnDoor(player, door, ui);
    //    tool->Update(rule->GetDeltaTime());

    //    //�`�揈���S
    //    background->Draw();
    //    door->Draw();
    //    player->Draw();
    //    tool->Draw();

    //    //UI����
    //    ui->WriteLimitTime(rule->GetLimitTime());
    //    ui->WriteScore(rule->GetScore());
    //    ui->DrawPlayerDead(player->GetDeadNum());
    //    ui->DrawGoodUI(rule->GetDeltaTime());
    //    DrawFormatString(0, 0, GetColor(255, 255, 255), "%f", rule->GetDeltaTime());

    //    ScreenFlip();
    //    rule->SetPrevTime();
    //}

    
    /*delete rule;
    delete hitcheck;
    delete ui;
    delete sound;
    delete background;
    delete door;
    delete player;
    delete tool;*/

    DxLib_End();				// �c�w���C�u�����g�p�̏I������ 
    return 0;				// �\�t�g�̏I��  

}