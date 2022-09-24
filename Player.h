#pragma once
class Player
{
public:
    Player();
    ~Player();
    void Update(float DeltaTime);
    void Animation(float deltaTime);
    void Draw();

private:
    int X, Y;
    int Graph[6];
    //�摜�̕�������
    int TotalGraphNum;
    //���̕�����
    int SideNum;
    //�c�̕�����
    int WarpNum;
    int Width;
    int Height;
    //�A�j���[�V�����t���[��
    int AnimFrame;
    //�A�j���[�V�����̏�Ԃ��L�^����񋓑�
    int AnimPattern;
    enum
    {
        Idle, Walk, Dead
    };
    int AnimPatternFirst;
    int AnimPatternNum;
};