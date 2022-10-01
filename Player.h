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
    //ドアに入れたらtrue
    bool ComeIn;
    int Speed;
    //画像の分割総数
    int TotalGraphNum;
    //横の分割数
    int SideNum;
    //縦の分割数
    int WarpNum;
    //左移動　false
    bool Reverse;
    //アニメーションフレーム
    int AnimFrame;
    //アニメーション開始位置
    int AnimPatternFirst;
};