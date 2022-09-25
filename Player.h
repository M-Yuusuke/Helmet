#pragma once
class Player
{
public:
    Player();
    ~Player();
    void Update(float DeltaTime);
    void Animation(float deltaTime);
    void Draw();
    void IsDead();

private:
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
    float Width;
    float Height;
    //�A�j���[�V�����t���[��
    int AnimFrame;
    //�A�j���[�V�����J�n�ʒu
    int AnimPatternFirst;
    int AnimPatternNum;
};