#pragma once
#include"SceneBase.h"
class Initialize : public SceneBase
{
public:
    static void Create();
    static void Destroy();
    SceneBase* Update(SceneManager* sceneManager);

    static Initialize* GetInstance() { return Instance; }
private:
    Initialize();
    ~Initialize();
    static Initialize* Instance;
};

