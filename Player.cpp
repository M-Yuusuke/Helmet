#include "DxLib.h"
#include "Player.h"

Player::Player()
{
    X = 50;
    Y = 800;
    Speed = 500;
    Dead = false;
    TotalGraphNum = 6;
    SideNum = 2;
    WarpNum = 3;
    Width = 176.5f;
    Height = 192.0f;
    LoadDivGraph("../../Img/Player.png", TotalGraphNum, SideNum, WarpNum, Width, Height, Graph);
    AnimPatternFirst = 0;
}

Player::~Player()
{
}

void Player::Update(float DeltaTime)
{
    if (CheckHitKey(KEY_INPUT_D))
    {
        X += Speed * DeltaTime;
        AnimPatternFirst = 3;
    }
    if (CheckHitKey(KEY_INPUT_A))
    {
        X -= Speed * DeltaTime;
        AnimPatternFirst = 3;
    }
    Animation(DeltaTime);
}

void Player::Animation(float deltaTime)
{
    AnimFrame = ((int)deltaTime / 125 % 2) + AnimPatternFirst;
}

void Player::Draw()
{
    if (Dead == false)
    {
        DrawGraph(X, Y, Graph[AnimFrame], TRUE);
    }
}

void Player::IsDead()
{
    Dead = true;
}

