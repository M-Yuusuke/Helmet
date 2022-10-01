#pragma once
class Door;

class Player
{
public:
    Player();
    ~Player();
    void Update(int DeltaTime, Door* door);
    void Animation(int DeltaTime);
    void Draw();
    void IsDead() { Dead = true; }

    bool GetDead() const { return Dead; }
    bool IsComeIn() const { return ComeIn; }

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
    //�h�A�ɓ��ꂽ��true
    bool ComeIn;
    int Speed;
    //�摜�̕�������
    int TotalGraphNum;
    //���̕�����
    int SideNum;
    //�c�̕�����
    int WarpNum;
    //���ړ��@false
    bool Reverse;
    //�A�j���[�V�����t���[��
    int AnimFrame;
    //�A�j���[�V�����J�n�ʒu
    int AnimPatternFirst;
};