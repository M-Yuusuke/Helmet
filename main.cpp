#include "DxLib.h"
#include "SceneManager.h"

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
        scenemanager->InitializeScene();

        //タイトル
        scenemanager->TitleScene();

        //ゲームメイン
        scenemanager->GameMainScene();

        if (scenemanager->GetScene() == 3)
        {
            //ゲームクリア
            scenemanager->ClearScene();
        }
        else if (scenemanager->GetScene() == 4)
        {
            //ゲームオーバー
            scenemanager->OverScene();
        }
    }
    delete scenemanager;

    DxLib_End();				// ＤＸライブラリ使用の終了処理 
    return 0;				// ソフトの終了  

}