#include "DxLib.h"
#include "Initialize.h"
#include "SceneManager.h"
#include "Rule.h"
#include "UI.h"
#include "Sound.h"
#include "Door.h"
#include "Player.h"
#include "Tool.h"

Initialize* Initialize::Instance = nullptr;
Initialize::Initialize()
{
}

Initialize::~Initialize()
{
}

void Initialize::Create()
{
    if (!Instance)
    {
        Instance = new Initialize;
    }
}

void Initialize::Destroy()
{
    delete Instance;
    Instance = nullptr;
}

SceneBase* Initialize::Update(SceneManager* sceneManager)
{
    rule->Initialize();
    ui->Initialize();
    door->Initialize();
    player->Initialize();
    tool->Initialize();
    sound->PlayTitle();
    return sceneManager->GetNextScene(this);
    //delete this;
    //return new Title;
}
