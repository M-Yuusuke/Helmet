#include "DxLib.h"
#include "Scene.h"

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

    Scene* scene = new Scene();

    while (true)
    {
        //������
        scene->InitializeScene();

        //�^�C�g��
        scene->TitleScene();

        //�Q�[�����C��
        scene->GameMainScene();

        //���U���g���
        scene->ResultScene();
    }
    delete scene;

    DxLib_End();				// �c�w���C�u�����g�p�̏I������ 
    return 0;				// �\�t�g�̏I��  

}