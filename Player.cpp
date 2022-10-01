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
    ComeIn = false;
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
    Reverse = false;
    AnimFrame = 0;
    AnimPatternFirst = 0;
}

Player::~Player()
{
}

void Player::Update(int DeltaTime, Door* door)
{
    if (X + Width <= EndPos)
    {
        if (CheckHitKey(KEY_INPUT_D))
        {
            X += Speed * DeltaTime;
            AnimPatternFirst = 3;
            Reverse = false;
        }
    }
    else
    {
        ComeIn = door->OnDoor(X + Width);
    }
    if (X >= 50)
    {
        if (CheckHitKey(KEY_INPUT_A))
        {
            X -= Speed * DeltaTime;
            AnimPatternFirst = 3;
            Reverse = true;
        }
    }
    Animation(DeltaTime);
}

void Player::Animation(int DeltaTime)
{
    AnimFrame = ((int)DeltaTime / 125 % 2) + AnimPatternFirst;
}

void Player::Draw()
{
    if (!Dead)
    {
        DrawRotaGraph(X + Width / 2, Y + Height / 2, 1.0,0, Graph[AnimFrame],TRUE, Reverse);
    }
}