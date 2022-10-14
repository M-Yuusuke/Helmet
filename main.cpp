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

    DxLib_End();				// ＤＸライブラリ使用の終了処理 
    return 0;				// ソフトの終了  

}