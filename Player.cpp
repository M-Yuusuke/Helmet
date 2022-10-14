#include "DxLib.h"
#include "Player.h"
#include "Door.h"
#include "Tool.h"

//静的変数の初期化
int Player::OriginalGraph[] = { -1,-1,-1,-1,-1,-1 };
int Player::DeadNum = 0;
Player::Player():
    X(FirstPosX),
    Y(FirstPosY),
    Speed(SpeedMax),
    DeadFrameCount(0),
    AnimFrame(0),
    AnimCoolTime(AnimCoolTimeMax),
    AnimNum(0),
    AnimPatternFirst(0),
    Dead(false),
    Goal(false),
    Reverse(false)
{
    if (OriginalGraph[0] == -1)
    {
        LoadDivGraph("../../Img/Player.png", TotalGraphNum, 2, 3, Width, Height, OriginalGraph);
    }
    for (int i = 0; i < 6; i++)
    {
        Graph[i] = OriginalGraph[i];
    }
}

Player::~Player()
{

}

void Player::Initialize()
{
    X = FirstPosX;
    Y = FirstPosY;
    Speed = SpeedMax;
    DeadFrameCount = 0;
    AnimFrame = 0;
    AnimCoolTime = AnimCoolTimeMax;
    AnimNum = 0;
    AnimPatternFirst = 0;
    Dead = false;
    Goal = false;
    Reverse = false;
}

void Player::Update(float DeltaTime, Door* door, Tool* tool)
{
    if (X + Width <= EndPos)
    {
        if (CheckHitKey(KEY_INPUT_D))
        {
            X += Speed * DeltaTime;
            AnimPatternFirst = 2;
            Reverse = false;
        }
    }

    if (X >= 50)
    {
        if (CheckHitKey(KEY_INPUT_A))
        {
            X -= Speed * DeltaTime;
            AnimPatternFirst = 2;
            Reverse = true;
        }
    }

    //無操作のときに待機アニメーションに
    if (!(CheckHitKey(KEY_INPUT_D)|| CheckHitKey(KEY_INPUT_A)))
    {
        AnimPatternFirst = 0;
    }

    Dead = tool->CheckHit(X + Width / 2, Y + Height / 2, Height / 2);

    if (Dead)
    {
        DeadFrameCount++;
        if (DeadFrameCount == 1)
        {
            DeadNum++;
        }
        AnimPatternFirst = 4;
    }
    if ((AnimCoolTime -= DeltaTime) <= 0)
    {
        AnimNum++;
        AnimCoolTime = AnimCoolTimeMax;
    }
    AnimFrame = AnimPatternFirst + (AnimNum % 2);
}

void Player::Draw()
{
    DrawRotaGraph(X + Width / 2, Y + Height / 2, 1.0, 0, Graph[AnimFrame], TRUE, Reverse);
    DrawCircle(X + Width / 2, Y + Height / 2, Height / 2, GetColor(0, 0, 255), FALSE);
}