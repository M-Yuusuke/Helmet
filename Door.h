#pragma once
class Door
{
public:
    Door();
    ~Door();
    void Initialize();
    void Update(float DeltaTime);
    void Draw();
    bool IsOpen()const { return Open; }

private:
    const int DoorPositionX = 1615;
    const int DoorPositionY = 802;
    const int TotalGraphNum = 2;
    const float CoolTimeMax = 1.5f;
    const float Width = 176.5f, Height = 192;

    int X, Y;
    int Graph[2];
    float CoolTime;
    int AnimNum;
    bool Open;
};

