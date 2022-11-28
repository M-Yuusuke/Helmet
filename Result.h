#pragma once
#include"SceneBase.h"
class SceneManager;
class Result:public SceneBase
{
public:
    static void Create();
    static void Destroy();
    SceneBase* Update(SceneManager* sceneManager);
    void Draw()override;

    static Result* GetInstance() { return Instance; }
    //static void SetIsClear(const bool Clear) { IsClear = Clear; }
    //static void SetScore(const int Score) { score = Score; }

private:
    Result();
    ~Result();
    static Result* Instance;

    const int MaxColor = 255;
    int Alpha;
    //ゲームパッドステータス
    XINPUT_STATE input;
    int BackgroundGameClear = -1;
    int BackgroundGameOver = -1;
    int Background;
    //static int score;
    //static bool IsClear;
};

