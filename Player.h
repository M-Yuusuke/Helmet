#pragma once
class Door;
class Player
{
public:
    Player();
    ~Player();
    void Update(float DeltaTime, Door* door);
    void Draw();
    void IsDead() { Dead = true; }

    bool GetDead() { return Dead; }
    bool GetGoal() { return Goal; }

private:
    static int OriginalGraph[6];
    const int FirstPosX = 50;
    const int FirstPosY = 800;
    const int EndPos = 1700;
    const float Width = 176.5f;
    const float Height = 192.0f;

    int X, Y;
    int Graph[6];

    int Speed;
    //�摜�̕�������
    int TotalGraphNum;
    //���̕�����
    int SideNum;
    //�c�̕�����
    int WarpNum;
    
    //�A�j���[�V�����t���[��
    int AnimFrame;
    //�A�j���[�V�����J�n�ʒu
    int AnimPatternFirst;
    bool Dead;
    bool Goal;
    //�E���� false
    bool Reverse;
};