#include "DxLib.h"
#include "Player.h"

Player::Player()
{
    TotalGraphNum = 6;
    SideNum = 2;
    WarpNum = 3;
    Width = 353;
    Height = 384;
    LoadDivGraph("../../Img/Player.png", TotalGraphNum, SideNum, WarpNum, Width, Height, Graph);
}

Player::~Player()
{
}

void Player::Update(float DeltaTime)
{
    Animation(DeltaTime);
}

void Player::Animation(float deltaTime)
{

}

void Player::Draw()
{
    DrawGraph(X, Y, Graph[AnimFrame], TRUE);
}
