#include "DxLib.h"
#include "Player.h"
#include "Door.h"
#include "Tool.h"

//ê√ìIïœêîÇÃèâä˙âª
int Player::OriginalGraph[] = { -1,-1,-1,-1,-1,-1 };
Player::Player()
{
    X = FirstPosX;
    Y = FirstPosY;
    Speed = 500;
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
    AnimFrame = 0;
    AnimPatternFirst = 0;
    Dead = false;
    Goal = false;
    Reverse = false;
}

Player::~Player()
{
}

void Player::Update(float DeltaTime, Door* door, Tool* tool)
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
        Goal = door->OnDoor(X + Width, EndPos);
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
    AnimFrame = ((int)DeltaTime / 125 % 2) + AnimPatternFirst;
    tool->HitCheck(X, Y, Height);
}

void Player::Draw()
{
    //if (!Dead)
    //{
    //    DrawGraph(X, Y, Graph[AnimFrame], TRUE);
    //}
    DrawRotaGraph(X + Width / 2, Y + Height / 2, 1.0, 0, Graph[AnimFrame], TRUE, Reverse);
}