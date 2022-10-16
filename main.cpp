#include "DxLib.h"
#include "SceneManager.h"

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
        scenemanager->InitializeScene();

        //�^�C�g��
        scenemanager->TitleScene();

        //�Q�[�����C��
        scenemanager->GameMainScene();

        if (scenemanager->GetScene() == 3)
        {
            //�Q�[���N���A
            scenemanager->ClearScene();
        }
        else if (scenemanager->GetScene() == 4)
        {
            //�Q�[���I�[�o�[
            scenemanager->OverScene();
        }
    }
    delete scenemanager;

    DxLib_End();				// �c�w���C�u�����g�p�̏I������ 
    return 0;				// �\�t�g�̏I��  

}