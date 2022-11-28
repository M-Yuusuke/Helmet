#pragma once
#include<vector>
using namespace std;

class Door;
class Tool;
class Sound;
class Effect;
class Player
{
public:
    static void Create();
    static void Destroy();
    static Player* GetInstance() { return Instance; }

    /**�����_���Ńv���C���[�̉摜��ύX*/
    void RandomSelectPlayerGraph();
    void Initialize();
    /**�h�A�ɓ������v���C���[��������*/
    void NewPlayer();
    void Update(float DeltaTime, Door* door, Tool* tool, Sound* sound, Effect* effect);
    void Draw();

    /**���U���g��ʂɃS�[���ł����L�����N�^�[�̐l�����L�����N�^�[��\��*/
    void ResultRandomPlayer();
    void ResultDraw();


    int GetPosX() const { return X; }
    float GetWidth()const { return Width; }
    int GetEndPos() const { return EndPos; }
    int GetLifeNum() const { return LifeNum; }
    bool GetDead() const { return Dead; }
    void IsGoal() { Goal = true; GoalNum++;}
    bool GetGoal() const { return Goal; }

private:
    Player();
    ~Player();
    static Player* Instance;
    /**�v���C���[�̎c�@��*/
    static int LifeNum;
    /**�v���C���[�̍ő�c�@��*/
    const int MaxLifeNum = 3;
    /**�v���C���[�̏������W*/
    const int FirstPosX = 50;
    const int FirstPosY = 800;
    const int SpeedMax = 500;
    /**�E���̈ړ�����*/
    const int EndPos = 1700;
    /**�摜�̑�������*/
    const int TotalGraphNum = 6;
    /**�摜�T�C�Y*/
    const float Width = 176.5f;
    const float Height = 192.0f;
    /**�A�j���[�V�������؂�ւ��^�C�~���O*/
    const float AnimCoolTimeMax = 0.25f;

    int X, Y;
    int Player1_Graph[6];
    int Player2_Graph[6];
    int Player3_Graph[6];
    int Player4_Graph[6];
    int PlayerNum;
    enum
    {
        Player1,Player2,Player3,Player4
    };
    int GoalNum;
    int Speed;
    
    int DeadFrameCount;
    /**�A�j���[�V�����t���[��*/
    int AnimFrame;
    float AnimCoolTime;
    int AnimNum;
    //�A�j���[�V�����J�n�ʒu
    int AnimPatternFirst;
    bool Dead;
    bool Goal;

    /**�Q�[���p�b�h�X�e�[�^�X*/
    XINPUT_STATE input;
    /**�����������]�t���O�@������:true �E����:false*/
    bool Reverse;

    /**���U���g��ʂɕ\������v���C���[�̔ԍ����L�^����z��*/
    vector<int> PlayerContainer;
};