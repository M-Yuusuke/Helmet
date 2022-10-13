#pragma once
class Door;
class Tool;
class Player
{
public:
    Player();
    ~Player();

    void Update(float DeltaTime, Door* door,Tool* tool);
    void Draw();

<<<<<<< HEAD
    int GetPosX() const { return X; }
    int GetWidth()const { return Width; }
    int GetEndPos() const { return EndPos; }
=======
>>>>>>> origin/main
    int GetDeadNum() const { return DeadNum; }
    bool GetDead() const { return Dead; }
    void IsGoal() { Goal = true; }
    bool GetGoal() const { return Goal; }

private:
    static int OriginalGraph[6];
    static int DeadNum;
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
    
    int DeadFrameCount;
    //�A�j���[�V�����t���[��
    int AnimFrame;
    //�A�j���[�V�����J�n�ʒu
    int AnimPatternFirst;
    bool Dead;
    bool Goal;
    //�E���� false
    bool Reverse;
};