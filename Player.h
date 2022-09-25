#pragma once
class Player
{
public:
    Player();
    ~Player();
    void Update(float DeltaTime);
    void Animation(float deltaTime);
    void Draw();
    void IsDead();

private:
    int X, Y;
    int Graph[6];

    bool Dead;
    int Speed;
    //画像の分割総数
    int TotalGraphNum;
    //横の分割数
    int SideNum;
    //縦の分割数
    int WarpNum;
    float Width;
    float Height;
    //アニメーションフレーム
    int AnimFrame;
    //アニメーション開始位置
    int AnimPatternFirst;
    int AnimPatternNum;
};