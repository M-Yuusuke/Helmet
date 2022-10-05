#pragma once
class Door;
class Tool;
class Player
{
public:
    Player();
    ~Player();
    void Update(float DeltaTime, Door* door,Tool* tool);
    void Draw();
    void IsDead() { Dead = true; }

    bool GetDead() const { return Dead; }
    bool GetGoal() const { return Goal; }

private:
    static int OriginalGraph[6];
    const int FirstPosX = 50;
    const int FirstPosY = 800;
    const int EndPos = 1700;
    const float Width = 176.5f;
    const float Height = 192.0f;

    int X, Y;
    int Graph[6];

    int Speed;
    //画像の分割総数
    int TotalGraphNum;
    //横の分割数
    int SideNum;
    //縦の分割数
    int WarpNum;
    
    //アニメーションフレーム
    int AnimFrame;
    //アニメーション開始位置
    int AnimPatternFirst;
    bool Dead;
    bool Goal;
    //右向き false
    bool Reverse;
};