#include "DxLib.h"
#include "Timer.h"
#include "Player.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // ＤＸライブラリ初期化処理
    if (DxLib_Init() == -1)
    {
        // エラーが起きたら直ちに終了 
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
    DxLib_End();				// ＤＸライブラリ使用の終了処理 
    return 0;				// ソフトの終了  

}