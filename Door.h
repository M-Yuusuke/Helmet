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
    //‰æ‘œ‚Ì•ªŠ„‘”
    int TotalGraphNum;
    //‰¡‚Ì•ªŠ„”
    int SideNum;
    //c‚Ì•ªŠ„”
    int WarpNum;
    int X, Y;
    float Width;
    int Height;
    int Graph[2];
    float CoolTime;
    int AnimNum;
    bool Open;
};

