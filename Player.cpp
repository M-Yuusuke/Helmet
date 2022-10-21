#include "DxLib.h"
#include "Player.h"
#include "Door.h"
#include "Tool.h"
#include "Sound.h"

int Player::DeadNum = 0;
Player::Player():
    X(FirstPosX),
    Y(FirstPosY),
    PlayerNum(0),
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
    LoadDivGraph("../../Img/Player1.png", TotalGraphNum, 2, 3, Width, Height, Player1_Graph);
    LoadDivGraph("../../Img/Player2.png", TotalGraphNum, 2, 3, Width, Height, Player2_Graph);
    LoadDivGraph("../../Img/Player3.png", TotalGraphNum, 2, 3, Width, Height, Player3_Graph);
    LoadDivGraph("../../Img/Player4.png", TotalGraphNum, 2, 3, Width, Height, Player4_Graph);
}

Player::~Player()
{
}

void Player::RandomSelectPlayerGraph()
{
    int Rand = GetRand(4);
    switch (Rand)
    {
    case 0:
        PlayerNum = Player1;
        break;
    case 1:
        PlayerNum = Player2;
        break;
    case 2:
        PlayerNum = Player3;
        break;
    case 3:
        PlayerNum = Player4;
        break;
    default:
        break;
    }
}

void Player::Initialize()
{
    X = FirstPosX;
    Y = FirstPosY;
    RandomSelectPlayerGraph();
    Speed = SpeedMax;
    DeadFrameCount = 0;
    DeadNum = 0;
    AnimFrame = 0;
    AnimCoolTime = AnimCoolTimeMax;
    AnimNum = 0;
    AnimPatternFirst = 0;
    Dead = false;
    Goal = false;
    Reverse = false;
}

void Player::NewPlayer()
{
    X = FirstPosX;
    Y = FirstPosY;
    RandomSelectPlayerGraph();
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

void Player::Update(float DeltaTime, Door* door, Tool* tool,Sound* sound)
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

    //動いているときに足音を再生し、無操作のときに待機アニメーションにする
    if (CheckHitKey(KEY_INPUT_D)|| CheckHitKey(KEY_INPUT_A))
    {
        sound->PlayWalk();
    }
    else
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
    switch (PlayerNum)
    {
    case Player1:
        DrawRotaGraph(X + Width / 2, Y + Height / 2, 1.0, 0, Player1_Graph[AnimFrame], TRUE, Reverse);
        break;
    case Player2:
        DrawRotaGraph(X + Width / 2, Y + Height / 2, 1.0, 0, Player2_Graph[AnimFrame], TRUE, Reverse);
        break;
    case Player3:
        DrawRotaGraph(X + Width / 2, Y + Height / 2, 1.0, 0, Player3_Graph[AnimFrame], TRUE, Reverse);
        break;
    case Player4:
        DrawRotaGraph(X + Width / 2, Y + Height / 2, 1.0, 0, Player4_Graph[AnimFrame], TRUE, Reverse);
        break;
    default:
        break;
    }
    DrawCircle(X + Width / 2, Y + Height / 2, Height / 2, GetColor(0, 0, 255), FALSE);
}