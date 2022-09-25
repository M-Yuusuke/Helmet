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
    //‰æ‘œ‚Ì•ªŠ„‘”
    int TotalGraphNum;
    //‰¡‚Ì•ªŠ„”
    int SideNum;
    //c‚Ì•ªŠ„”
    int WarpNum;
    int X, Y;
    int Graph[2];
    float CoolTime;
    int AnimNum;
    bool Open;
};

