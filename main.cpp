#include "DxLib.h"
#include "Rule.h"
#include "BackGround.h"
#include "Door.h" 
#include "Player.h"
#include "Tool.h"

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
    Tool* tool = new Tool();   

    while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
    {
        //ポインタの切り替え
        if (player->GetGoal() || player->GetDead())
        {
            delete player;
            player = new Player();
        }

        ClearDrawScreen();
        rule->SetNowTime();
        //更新処理郡
        door->Update(rule->GetDeltaTime());
        player->Update(rule->GetDeltaTime(),door);
        tool->Update(rule->GetDeltaTime());

        //描画処理郡
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
    DxLib_End();				// ＤＸライブラリ使用の終了処理 
    return 0;				// ソフトの終了  

}