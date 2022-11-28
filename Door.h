#pragma once
class Sound;
class Door
{
public:
    static void Create();
    static void Destroy();
    static Door* GetInstance() { return Instance; }
    void Initialize();
    void Update(float DeltaTime, Sound* sound);
    void Draw();
    bool IsOpen()const { return Open; }


private:
    Door();
    ~Door();
    static Door* Instance;
    const int DoorPosX = 1615;
    const int DoorPosY = 802;
    /**�摜�̕�������*/
    const int TotalGraphNum = 2;
    /**�E���̃h�A�̊J���I���Ԃ̍ő�l*/
    const float CoolTimeMax = 1.5f;
    /**�E���̃h�A�̕��ƍ���*/
    const float Width = 176.5f, Height = 192;

    /**���������摜�̃V���A���i���o�[���i�[����z��*/
    int Graph[2];
    /**�E�̃h�A�̊J���I���Ԃ��L�^����ϐ�*/
    float CoolTime;
    /**�����������������i�[����ϐ��@�A�j���[�V�����i���o�[�ɂ����p*/
    int AnimNum;
    /**�h�A���J���Ă��邩�ǂ����̃t���O*/
    bool Open;
    /**�O�̃t���[���̃h�A�̏�Ԃ��L�^����ϐ��@�h�A�̊J���̍Đ��ŕK�v*/
    bool OpenPrev;
};

