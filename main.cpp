#include "DxLib.h"
#include "Timer.h"
#include "BackGround.h"
#include "Door.h" 
#include "Player.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //フルスクリーンモード
    ChangeWindowMode(FALSE);
    //解像度・カラービット数の指定
    SetGraphMode(1920, 1080, 32);

    // ＤＸライブラリ初期化処理
    if (DxLib_Init() == -1)
    {
        // エラーが起きたら直ちに終了 
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
    DxLib_End();				// ＤＸライブラリ使用の終了処理 
    return 0;				// ソフトの終了  

}