#include "DxLib.h"
#include "Scene.h"

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

    Scene* scene = new Scene();

    while (true)
    {
        //初期化
        scene->InitializeScene();

        //タイトル
        scene->TitleScene();

        //ゲームメイン
        scene->GameMainScene();

        //リザルト画面
        scene->ResultScene();
    }
    delete scene;

    DxLib_End();				// ＤＸライブラリ使用の終了処理 
    return 0;				// ソフトの終了  

}