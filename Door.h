#pragma once
class Door
{
public:
    Door();
    ~Door();
    void Update(float deltaTime);
    bool OnDoor(int PlayerX);
    void Draw();
private:
    const float CoolTimeMax = 1.5f;
    const float Width = 176.5f, Height = 192;
    //�摜�̕�������
    int TotalGraphNum;
    //���̕�����
    int SideNum;
    //�c�̕�����
    int WarpNum;
    int X, Y;
    int Graph[2];
    float CoolTime;
    int AnimNum;
    bool Open;
};

