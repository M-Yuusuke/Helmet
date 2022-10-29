#pragma once
class Effect
{
public:
    Effect();
    ~Effect();
    void Update(float DeltaTime);
    void Draw();

    void SetVisible() { IsVisible = true; }
private:
    const float AnimCoolTimeMax = 0.125f;
    int Graph[9];
    float AnimCoolTime;
    int AnimNum;
    int AnimFrame;
    float VisibleTime;
    //Œ©‚¦‚é true
    bool IsVisible;
};

