#include "DxLib.h"
#include "SceneManager.h"
#include "Initialize.h"
#include "Title.h"
#include "GameMain.h"
#include "GameClear.h"
#include "GameOver.h"
#include "Rule.h"
#include "HitCheck.h"
#include "UI.h"
#include "Sound.h"
#include "BackGround.h"
#include "Door.h" 
#include "Player.h"
#include "Tool.h"

SceneManager::SceneManager() :
    initialize(new Initialize()),
    title(new Title()),
    gamemain(new GameMain()),
    gameclear(new GameClear()),
    gameover(new GameOver()),
    rule(new Rule()),
    hitcheck(new HitCheck()),
    ui(new UI()),
    sound(new Sound()),
    background(new BackGround()),
    door(new Door()),
    player(new Player()),
    tool(new Tool()),
    scene(INIT)
{
}

SceneManager::~SceneManager()
{
    delete rule;
    delete hitcheck;
    delete ui;
    delete sound;
    delete background;
    delete door;
    delete player;
    delete tool;
}

void SceneManager::InitializeScene()
{
    while (!ProcessMessage() && scene == INIT)
    {
        initialize->Reset(rule, ui, door, player, tool, sound, this);
    }
}

void SceneManager::TitleScene()
{
    while (!ProcessMessage() && scene == TITLE)
    {
        title->TitleDraw(this,sound);
    }
}

void SceneManager::GameMainScene()
{
    rule->SetStartTime();
    while (!ProcessMessage() && scene == GAMEMAIN)
    {
        gamemain->GameLoop(this, rule, ui, hitcheck, background, door, player, tool, sound);
    }
}

void SceneManager::ClearScene()
{
    while (!ProcessMessage() && scene == CLEAR)
    {
        gameclear->GameClearDraw(this, sound);
    }
}

void SceneManager::OverScene()
{
    while (!ProcessMessage() && scene == OVER)
    {
        gameover->GameOverDraw(this, sound);
    }
}

void SceneManager::NextScene()
{
    switch (scene)
    {
    case INIT:
        scene = TITLE;
        break;
    case TITLE:
        scene = GAMEMAIN;
        break;
    case CLEAR:
        scene = INIT;
        break;
    case OVER:
        scene = INIT;
        break;
    default:
        break;
    }
}

void SceneManager::ChangeGameClear()
{
    scene = CLEAR;
}

void SceneManager::ChangeGameOver()
{
    scene = OVER;
}


void SceneManager::NewPalyer()
{
    delete player;
    player = new Player();
}

