#include "DxLib.h"
#include "Timer.h"
#include "Player.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // �c�w���C�u��������������
    if (DxLib_Init() == -1)
    {
        // �G���[���N�����璼���ɏI�� 
        return -1;
    }

    Player* player = new Player();
    Timer* timer = new Timer();
    while (!ProcessMessage())
    {
        ClearDrawScreen();
        timer->SetNowTime();
        player->Update(timer->GetDeltaTime());
        player->Draw();


        if (CheckHitKey(KEY_INPUT_ESCAPE))
        {
            break;
        }
        ScreenFlip();
        timer->SetPrevTime();
    }

    delete player;
    delete timer;
    DxLib_End();				// �c�w���C�u�����g�p�̏I������ 
    return 0;				// �\�t�g�̏I��  

}