#include "DxLib.h"
#include "Scene.h"
#include "Initialize.h"
#include "Title.h"
#include "GameMain.h"
#include "Result.h"
#include "Rule.h"
#include "HitCheck.h"
#include "UI.h"
#include "Effect.h"
#include "Sound.h"
#include "BackGround.h"
#include "Door.h" 
#include "Player.h"
#include "Tool.h"

Scene::Scene():
    initialize(new Initialize()),
    title(new Title()),
    gamemain(new GameMain()),
    result(new Result()),
    rule(new Rule()),
    hitcheck(new HitCheck()),
    ui(new UI()),
    effect(new Effect()),
    sound(new Sound()),
    background(new BackGround()),
    door(new Door()),
    player(new Player()),
    tool(new Tool()),
    SceneStatus(INIT)
{
}

Scene::~Scene()
{
    delete initialize;
    delete title;
    delete gamemain;
    delete result;
    delete rule;
    delete hitcheck;
    delete ui;
    delete effect;
    delete sound;
    delete background;
    delete door;
    delete player;
    delete tool;
}

void Scene::InitializeScene()
{
    while (!ProcessMessage() && SceneStatus == INIT)
    {
        initialize->Reset(rule, ui, door, player, tool, sound, this);
    }
}

void Scene::TitleScene()
{
    while (!ProcessMessage() && SceneStatus == TITLE)
    {
        title->Update(this, sound);
        title->Draw(background, this);
    }
}

void Scene::GameMainScene()
{
    rule->SetStartTime();
    while (!ProcessMessage() && SceneStatus == GAMEMAIN)
    {
        gamemain->Update(this, rule, ui, effect, hitcheck, door, player, tool, sound);
        gamemain->Draw(rule, ui, effect, background, door, player, tool, this);
    }
}

void Scene::ResultScene()
{
    while (!ProcessMessage() && (SceneStatus == CLEAR || SceneStatus == OVER))
    {
        result->Update(this, sound);
        result->Draw(rule->GetScore(), player, ui, background, this);
    }
}

void Scene::NextScene()
{
    switch (SceneStatus)
    {
    case INIT:
        SceneStatus = TITLE;
        break;
    case TITLE:
        SceneStatus = GAMEMAIN;
        break;
    case CLEAR:
        SceneStatus = INIT;
        break;
    case OVER:
        SceneStatus = INIT;
        break;
    default:
        break;
    }
}

void Scene::ChangeGameClear()
{
    SceneStatus = CLEAR;
}

void Scene::ChangeGameOver()
{
    SceneStatus = OVER;
}
