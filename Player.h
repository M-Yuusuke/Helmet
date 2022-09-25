#pragma once
class Door;
class Player
{
public:
    Player();
    ~Player();
    void Update(float DeltaTime, Door* door);
    void Animation(float deltaTime);
    void Draw();
    void IsDead() { Dead = true; }

    bool GetDead() { return Dead; }

private:
    static int OriginalGraph[6];
    const int FirstPosX = 50;
    const int FirstPosY = 800;
    const int EndPos = 1700;
    const float Width = 176.5f;
    const float Height = 192.0f;

    int X, Y;
    int Graph[6];

    bool Dead;
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
    int AnimPatternNum;
};