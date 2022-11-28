#include "DxLib.h"
#include "SceneBase.h"
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

    SceneManager* sceneManager = new SceneManager;
    SceneBase* sceneBase = nullptr;
    sceneBase = sceneManager->GetNextScene(sceneBase);

    while (!ProcessMessage())
    {
        sceneBase = sceneBase->Update(sceneManager);
        sceneBase->Draw();
    }
    delete sceneManager;
    //delete sceneBase;
    DxLib_End();				// ＤＸライブラリ使用の終了処理 
    return 0;				    // ソフトの終了
}