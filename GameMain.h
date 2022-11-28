#pragma once
#include "SceneBase.h"
class SceneManager;
class GameMain:public SceneBase
{
public:
    static void Create();
    static void Destroy();
    SceneBase* Update(SceneManager* sceneManager);
    void Draw()override;

    static GameMain* GetInstance() { return Instance; }
private:
    GameMain();
    ~GameMain();
    static GameMain* Instance;
    int Background = -1;
};

