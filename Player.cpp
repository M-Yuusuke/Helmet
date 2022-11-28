#include <vector>
#include "DxLib.h"
#include "Player.h"
#include "Door.h"
#include "Tool.h"
#include "Sound.h"
#include "Effect.h"

Player* Player::Instance = nullptr;
int Player::LifeNum = 0;
Player::Player():
    X(FirstPosX),
    Y(FirstPosY),
    PlayerNum(0),
    GoalNum(0),
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
    LoadDivGraph("Img/Player/Player1.png", TotalGraphNum, 2, 3, Width, Height, Player1_Graph);
    LoadDivGraph("Img/Player/Player2.png", TotalGraphNum, 2, 3, Width, Height, Player2_Graph);
    LoadDivGraph("Img/Player/Player3.png", TotalGraphNum, 2, 3, Width, Height, Player3_Graph);
    LoadDivGraph("Img/Player/Player4.png", TotalGraphNum, 2, 3, Width, Height, Player4_Graph);
}

Player::~Player()
{
}

void Player::Create()
{
    if (!Instance)
    {
        Instance = new Player;
    }
}

void Player::Destroy()
{
    delete Instance;
    Instance = nullptr;
}

void Player::RandomSelectPlayerGraph()
{
    int Rand = GetRand(3);
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
    GoalNum = 0;
    Speed = SpeedMax;
    DeadFrameCount = 0;
    LifeNum = MaxLifeNum;
    AnimFrame = 0;
    AnimCoolTime = AnimCoolTimeMax;
    AnimNum = 0;
    AnimPatternFirst = 0;
    Dead = false;
    Goal = false;
    Reverse = false;

    PlayerContainer.clear();
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

void Player::Update(float DeltaTime, Door* door, Tool* tool,Sound* sound, Effect* effect)
{
    GetJoypadXInputState(DX_INPUT_PAD1, &input);
    if (X + Width <= EndPos)
    {

        //���X�e�B�b�N���E�ɓ|�� or �\���L�[�E����͂����Ƃ�
        if (input.ThumbLX > 0 || input.Buttons[XINPUT_BUTTON_DPAD_RIGHT] == 1 || CheckHitKey(KEY_INPUT_D))
        {
            X += Speed * DeltaTime;
            AnimPatternFirst = 2;
            Reverse = false;
        }
    }

    if (X >= 50)
    {
        //���X�e�B�b�N�����ɓ|�� or �\���L�[������͂����Ƃ�
        if (input.ThumbLX < 0 || input.Buttons[XINPUT_BUTTON_DPAD_LEFT] == 1 || CheckHitKey(KEY_INPUT_A))
        {
            X -= Speed * DeltaTime;
            AnimPatternFirst = 2;
            Reverse = true;
        }
    }

    //���͂���Ă���Ε���SE���Đ�
    if ((input.ThumbLX != 0|| input.Buttons[XINPUT_BUTTON_DPAD_LEFT] == 1||
        input.Buttons[XINPUT_BUTTON_DPAD_RIGHT] == 1)||
        (CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_A)))
    {
        sound->PlayWalk();
    }
    else
    {
        sound->StopWalk();
        AnimPatternFirst = 0;
    }

    Dead = tool->CheckHit(X + Width / 2, Y + Height / 2, Height / 2, effect);

    if (Dead)
    {
        DeadFrameCount++;
        if (DeadFrameCount == 1)
        {
            LifeNum--;
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
    //DrawCircle(X + Width / 2, Y + Height / 2, Height / 2, GetColor(0, 0, 255), FALSE);
}



//--------------------------------------------------------------------//
//���U���g���
//--------------------------------------------------------------------//
void Player::ResultRandomPlayer()
{
    for (int i = 0; i < GoalNum; i++)
    {
        PlayerContainer.push_back(GetRand(3));
    }
}

void Player::ResultDraw()
{
    for (int i = 0; i < PlayerContainer.size(); i++)
    {
        switch (PlayerContainer[i])
        {
        case Player1:
            DrawRotaGraph(500 + Width / 2 * i, 1080 - Height / 2, 0.5, 0, Player1_Graph[0], TRUE);
            break;
        case Player2:
            DrawRotaGraph(500 + Width / 2 * i, 1080 - Height / 2, 0.5, 0, Player2_Graph[0], TRUE);
            break;
        case Player3:
            DrawRotaGraph(500 + Width / 2 * i, 1080 - Height / 2, 0.5, 0, Player3_Graph[0], TRUE);
            break;
        case Player4:
            DrawRotaGraph(500 + Width / 2 * i, 1080 - Height / 2, 0.5, 0, Player4_Graph[0], TRUE);
            break;
        default:
            break;
        }
    }
}
