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

    SceneManager* scenemanager = new SceneManager();
    while (true)
    {
        //初期化
        while (!ProcessMessage() && scenemanager->GetScene() == 0)
        {
            scenemanager->Initialize();
        }

        //タイトル
        while (!ProcessMessage() && scenemanager->GetScene() == 1)
        {
            scenemanager->Title();
        }

        //ゲームメイン
        while (!ProcessMessage() && scenemanager->GetScene() == 2)
        {
            scenemanager->GameMain();
        }

        //ゲームクリア
        while (!ProcessMessage() && scenemanager->GetScene() == 3)
        {
            scenemanager->Clear();
        }

        //ゲームオーバー
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
    //    //プレイヤー再生成
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

    //    //更新処理郡
    //    door->Update(rule->GetDeltaTime());
    //    player->Update(rule->GetDeltaTime(), door, tool);
    //    hitcheck->OnDoor(player, door, ui);
    //    tool->Update(rule->GetDeltaTime());

    //    //描画処理郡
    //    background->Draw();
    //    door->Draw();
    //    player->Draw();
    //    tool->Draw();

    //    //UI処理
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

    DxLib_End();				// ＤＸライブラリ使用の終了処理 
    return 0;				// ソフトの終了  

}