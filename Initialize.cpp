#include "DxLib.h"
#include "Initialize.h"
#include "Scene.h"
#include "Rule.h"
#include "UI.h"
#include "Sound.h"
#include "Door.h"
#include "Player.h"
#include "Tool.h"

Initialize::Initialize()
{
}

void Initialize::Reset(Rule*rule,UI*ui,Door*door,Player*player,Tool*tool,Sound* sound,Scene* scene)
{
    rule->Initialize();
    ui->Initialize();
    door->Initialize();
    player->Initialize();
    tool->Initialize();
    sound->PlayTitle();
    WaitTimer(500);
    scene->NextScene();
}
