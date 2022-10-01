#include <vector>
#include "DxLib.h"
#include "Rule.h"
#include "BackGround.h"
#include "Door.h"
#include "Player.h"
using namespace std;

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
    Rule* rule = new Rule();
    Door* door = new Door();
    Player* player = new Player();

    while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
    {
        //ポインタの切り替え
        if (player->IsComeIn())
        {
            delete player;
            player = new Player();
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
    DxLib_End();				// ＤＸライブラリ使用の終了処理 
    return 0;				// ソフトの終了  

}