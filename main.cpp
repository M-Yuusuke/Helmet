#include "DxLib.h"
#include "Rule.h"
#include "SceneManager.h"
#include "HitCheck.h"
#include "UI.h"
#include "Sound.h"
#include "BackGround.h"
#include "Door.h" 
#include "Player.h"
#include "Tool.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //�t���X�N���[�����[�h
    ChangeWindowMode(FALSE);
    //�𑜓x�E�J���[�r�b�g���̎w��
    SetGraphMode(1920, 1080, 32);

    // �c�w���C�u��������������
    if (DxLib_Init() == -1)
    {
        // �G���[���N�����璼���ɏI��
        return -1;
    }

    SceneManager* scenemanager = new SceneManager();
    while (true)
    {
        //������
        while (!ProcessMessage() && scenemanager->GetScene() == 0)
        {
            scenemanager->Initialize();
        }

        //�^�C�g��
        while (!ProcessMessage() && scenemanager->GetScene() == 1)
        {
            scenemanager->Title();
        }

        //�Q�[�����C��
        while (!ProcessMessage() && scenemanager->GetScene() == 2)
        {
            scenemanager->GameMain();
        }

        //�Q�[���N���A
        while (!ProcessMessage() && scenemanager->GetScene() == 3)
        {
            scenemanager->Clear();
        }

        //�Q�[���I�[�o�[
        while (!ProcessMessage() && scenemanager->GetScene() == 4)
        {
            scenemanager->Over();
        }

    }
    delete scenemanager;

    DxLib_End();				// �c�w���C�u�����g�p�̏I������ 
    return 0;				// �\�t�g�̏I��  

}