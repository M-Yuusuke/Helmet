#include "DxLib.h"
#include "Timer.h"
#include "BackGround.h"
#include "Door.h" 
#include "Player.h"

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
    Timer* timer = new Timer();
    Door* door = new Door();
    Player* player = new Player();

    while (!ProcessMessage())
    {
        ClearDrawScreen();
        timer->SetNowTime();
        door->Update(timer->GetDeltaTime());
        player->Update(timer->GetDeltaTime());

        background->Draw();
        door->Draw();
        player->Draw();


        if (CheckHitKey(KEY_INPUT_ESCAPE))
        {
            break;
        }
        ScreenFlip();
        timer->SetPrevTime();
    }

    delete background;
    delete player;
    delete timer;
    DxLib_End();				// �c�w���C�u�����g�p�̏I������ 
    return 0;				// �\�t�g�̏I��  

}