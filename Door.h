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

    //画像の分割総数
    int TotalGraphNum;
    //横の分割数
    int SideNum;
    //縦の分割数
    int WarpNum;
    int X, Y;
    int Graph[2];
    float CoolTime;
    int AnimNum;
    bool IsOpen;
};

