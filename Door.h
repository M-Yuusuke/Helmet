#pragma once
class Door
{
public:
    Door();
    ~Door();
    void Draw();
    void Update(float deltaTime);
private:
    const float CoolTimeMax = 1.5f;
    //画像の分割総数
    int TotalGraphNum;
    //横の分割数
    int SideNum;
    //縦の分割数
    int WarpNum;
    int X, Y;
    float Width;
    int Height;
    int Graph[2];
    float CoolTime;
    int AnimNum;
    bool Open;
};

