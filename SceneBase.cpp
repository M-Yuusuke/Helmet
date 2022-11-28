#include "SceneBase.h"
#include "Rule.h"
#include "HitCheck.h"
#include "UI.h"
#include "Effect.h"
#include "Sound.h"
#include "Door.h" 
#include "Player.h"
#include "Tool.h"

SceneBase::SceneBase()
{
    //各クラスのインスタンスを生成
    Rule::Create();
    HitCheck::Create();
    Player::Create();
    Door::Create();
    Tool::Create();
    UI::Create();
    Effect::Create();
    Sound::Create();

    //各クラスのインスタンスを取得
    rule = Rule::GetInstance();
    hitcheck = HitCheck::GetInstance();
    player = Player::GetInstance();
    door = Door::GetInstance();
    tool = Tool::GetInstance();
    ui = UI::GetInstance();
    effect = Effect::GetInstance();
    sound = Sound::GetInstance();
}

SceneBase::~SceneBase()
{
    //delete rule;
    //delete hitcheck;
    //delete player;
    //delete door;
    //delete tool;
    //delete ui;
    //delete effect;
    //delete sound;
    //各クラスのインスタンスを消去
    Rule::Destroy();
    HitCheck::Destroy();
    Player::Destroy();
    Door::Destroy();
    Tool::Destroy();
    UI::Destroy();
    Effect::Destroy();
    Sound::Destroy();
}

void SceneBase::Draw()
{
}
