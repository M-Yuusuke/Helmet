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
    //画像の分割総数
    int TotalGraphNum;
    //横の分割数
    int SideNum;
    //縦の分割数
    int WarpNum;
    int Width;
    int Height;
    //アニメーションフレーム
    int AnimFrame;
    //アニメーションの状態を記録する列挙体
    int AnimPattern;
    enum
    {
        Idle, Walk, Dead
    };
    int AnimPatternFirst;
    int AnimPatternNum;
};