#include "DxLib.h"
#include "BackGround.h"

BackGround::BackGround():
    Title(LoadGraph("Img/BackGround/Title.png")),
    GameMain(LoadGraph("Img/BackGround/BackGround.png")),
    GameClear(LoadGraph("Img/BackGround/GameClear.png")),
    GameOver(LoadGraph("Img/BackGround/GameOver.png"))
{
}

BackGround::~BackGround()
{
    DeleteGraph(GameMain);
}

void BackGround::Draw(int SceneStatus)
{
    
    if (SceneStatus == 1)
    {
        //タイトル
        DrawGraph(0, 0, Title, FALSE);
    }
    if (SceneStatus == 2)
    {
        //ゲームメイン
        DrawGraph(0, 0, GameMain, FALSE);
    }
    else if (SceneStatus == 3)
    {
        //ゲームクリア
        DrawGraph(0, 0, GameClear, FALSE);
    }
    else if(SceneStatus == 4)
    {
        //ゲームオーバー
        DrawGraph(0, 0, GameOver, FALSE);
    }
}
