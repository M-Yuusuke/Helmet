#include "DxLib.h"
#include "Title.h"
#include "SceneManager.h"
#include "Sound.h"
#include "UI.h"

Title* Title::Instance = nullptr;
Title::Title():
    Alpha(0),
    TitleMovie(LoadGraph("Img/BackGround/Title.mp4"))
{
    SeekMovieToGraph(TitleMovie, 0);
}

Title::~Title()
{
    DeleteGraph(TitleMovie);
}

void Title::Create()
{
    if (!Instance)
    {
        Instance = new Title;
    }
}

void Title::Destroy()
{
    delete Instance;
    Instance = nullptr;
}

SceneBase* Title::Update(SceneManager* sceneManager)
{
    Alpha++;
    if (Alpha > MaxColor)
    {
        Alpha = 0;
    }
    //動画が再生されていなければ再生位置を先頭にして再生
    if (GetMovieStateToGraph(TitleMovie) != 1)
    {
        SeekMovieToGraph(TitleMovie, 0);
        PlayMovieToGraph(TitleMovie);
    }
    //ゲームパッドの入力状態を取得
    GetJoypadXInputState(DX_INPUT_PAD1, &input);
    //Bボタンが入力されたら
    if (input.Buttons[13] == 1 || CheckHitKey(KEY_INPUT_SPACE))
    {
        sound->PlayGame();
        return sceneManager->GetNextScene(this);
        //delete this;
        //return new GameMain;
    }
    return this;
}

void Title::Draw()
{
    ClearDrawScreen();
    DrawGraph(0, 0, TitleMovie, FALSE);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, Alpha);
    ui->TitleWriteBToPlay();
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    ScreenFlip();
}