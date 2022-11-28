#include "SceneManager.h"
#include "SceneBase.h"
#include "Initialize.h"
#include "Title.h"
#include "GameMain.h"
#include "Result.h"
#include "Rule.h"

SceneManager::SceneManager()
{
    Initialize::Create();
    Title::Create();
    GameMain::Create();
    Result::Create();

    initialize = Initialize::GetInstance();
    title = Title::GetInstance();
    gamemain = GameMain::GetInstance();
    result = Result::GetInstance();
}

SceneManager::~SceneManager()
{

    Initialize::Destroy();
    Title::Destroy();
    GameMain::Destroy();
    Result::Destroy();

}

SceneBase* SceneManager::GetNextScene(SceneBase* NowScene) const
{
    if (initialize == NowScene)
    {
        return title;
    }
    if (title == NowScene)
    {
        Rule::SetStartTime();
        return gamemain;
    }
    if (gamemain == NowScene)
    {
        return result;
    }
    if (result == NowScene || nullptr == NowScene)
    {
        return initialize;
    }
}
