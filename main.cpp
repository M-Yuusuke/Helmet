#include <vector>
#include "DxLib.h"
#include "Rule.h"
#include "BackGround.h"
#include "Door.h" 
#include "Player.h"
using namespace std;

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
    Player* player;
    int Num = 0;
    Player* playermanager[2];
    for (int i = 0; i < 2; i++)
    {
        playermanager[i] = new Player();
    }
    player = playermanager[Num];
    

    while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
    {
        //�|�C���^�̐؂�ւ�
        if (player->GetDead())
        {
            delete playermanager[Num];
            if (Num == 0)
            {
                playermanager[Num] = new Player();
                Num == 1;
            }
            else
            {
                playermanager[Num] = new Player();
                Num = 0;
            }
            player = playermanager[Num];

        }

        ClearDrawScreen();
        rule->SetNowTime();
        door->Update(rule->GetDeltaTime());
        player->Update(rule->GetDeltaTime(),door);

        background->Draw();
        door->Draw();
        player->Draw();

        ScreenFlip();
        rule->SetPrevTime();
    }

    delete background;
    delete player;
    delete rule;
    DxLib_End();				// �c�w���C�u�����g�p�̏I������ 
    return 0;				// �\�t�g�̏I��  

}