#include "DxLib.h"
#include "Rule.h"
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

    BackGround* background = new BackGround();
    Rule* rule = new Rule();
    Door* door = new Door();
    Player* player = new Player();
    Tool* tool = new Tool();   

    while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
    {
        //�|�C���^�̐؂�ւ�
        if (player->GetGoal() || player->GetDead())
        {
            delete player;
            player = new Player();
        }

        ClearDrawScreen();
        rule->SetNowTime();
        //�X�V�����S
        door->Update(rule->GetDeltaTime());
        player->Update(rule->GetDeltaTime(),door);
        tool->Update(rule->GetDeltaTime());

        //�`�揈���S
        background->Draw();
        door->Draw();
        player->Draw();
        tool->Draw();

        //DrawFormatString(0, 0,GetColor(0,0,0),"%5.4f", rule->GetDeltaTime());
        ScreenFlip();
        rule->SetPrevTime();
    }

    delete background;
    delete player;
    delete rule;
    //delete tool;
    DxLib_End();				// �c�w���C�u�����g�p�̏I������ 
    return 0;				// �\�t�g�̏I��  

}