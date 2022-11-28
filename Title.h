#pragma once
#include "DxLib.h"
#include "SceneBase.h"
class SceneManager;
class Title : public SceneBase
{
public:
    static void Create();
    static void Destroy();
    SceneBase* Update(SceneManager* sceneManager);
    void Draw()override;

    static Title* GetInstance() { return Instance; }
private:
    Title();
    ~Title();
    static Title* Instance;
    const int MaxColor = 125;
    int Alpha;

    //ゲームパッドステータス
    XINPUT_STATE input;
    int TitleMovie = -1;
};

