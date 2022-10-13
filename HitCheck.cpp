#include "DxLib.h"
#include "HitCheck.h"
#include "UI.h"
#include "Player.h"
#include "Door.h"
#include "Tool.h"

HitCheck::HitCheck()
{
}

HitCheck::~HitCheck()
{
}

//�h�A�ƃv���C���[�̓����蔻��
void HitCheck::OnDoor(Player* player, Door* door, UI* ui)
{
    if (player->GetPosX() + player->GetWidth() >= player->GetEndPos() && door->IsOpen())
    {
        player->IsGoal();
        ui->SetVisible();
    }
}
