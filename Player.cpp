#include "DxLib.h"
#include "Player.h"
#include "Door.h"
//ê√ìIïœêîÇÃèâä˙âª
int Player::OriginalGraph[] = { -1,-1,-1,-1,-1,-1 };
Player::Player()
{
    X = FirstPosX;
    Y = FirstPosY;
    Speed = 500;
    Dead = false;
    TotalGraphNum = 6;
    SideNum = 2;
    WarpNum = 3;
    if (OriginalGraph[0] == -1)
    {
        LoadDivGraph("../../Img/Player.png", TotalGraphNum, SideNum, WarpNum, Width, Height, OriginalGraph);
    }
    for (int i = 0; i < 6; i++)
    {
        Graph[i] = OriginalGraph[i];
    }
    AnimPatternFirst = 0;
}

Player::~Player()
{
}

void Player::Update(float DeltaTime, Door* door)
{
    if (X + Width <= EndPos)
    {
        if (CheckHitKey(KEY_INPUT_D))
        {
            X += Speed * DeltaTime;
            AnimPatternFirst = 3;
        }
    }
    else
    {
        Dead = door->OnDoor(X + Width);
    }
    if (X >= 50)
    {
        if (CheckHitKey(KEY_INPUT_A))
        {
            X -= Speed * DeltaTime;
            AnimPatternFirst = 3;
        }
    }
    Animation(DeltaTime);
}

void Player::Animation(float deltaTime)
{
    AnimFrame = ((int)deltaTime / 125 % 2) + AnimPatternFirst;
}

void Player::Draw()
{
    if (!Dead)
    {
        DrawGraph(X, Y, Graph[AnimFrame], TRUE);
    }
}