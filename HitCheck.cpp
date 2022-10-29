#include "DxLib.h"
#include "HitCheck.h"
#include "Player.h"
#include "Door.h"
#include "Tool.h"
#include "Effect.h"

HitCheck::HitCheck()
{
}

HitCheck::~HitCheck()
{
}

//ドアとプレイヤーの当たり判定
void HitCheck::OnDoor(Player* player, Door* door, Effect* effect)
{
    if (player->GetPosX() + player->GetWidth() >= player->GetEndPos() && door->IsOpen())
    {
        effect->SetVisible();
        player->IsGoal();
    }
}
