#pragma once
class Door;
class Tool;
class Sound;
class Player
{
public:
    Player();
    ~Player();

    void RandomSelectPlayerGraph();
    void Initialize();
    void NewPlayer();
    void Update(float DeltaTime, Door* door, Tool* tool, Sound* sound);
    void Draw();

    int GetPosX() const { return X; }
    int GetWidth()const { return Width; }
    int GetEndPos() const { return EndPos; }
    int GetDeadNum() const { return DeadNum; }
    bool GetDead() const { return Dead; }
    void IsGoal() { Goal = true; }
    bool GetGoal() const { return Goal; }

private:
    static int DeadNum;
    const int FirstPosX = 50;
    const int FirstPosY = 800;
    const int SpeedMax = 500;
    const int EndPos = 1700;
    const int TotalGraphNum = 6;
    const float Width = 176.5f;
    const float Height = 192.0f;
    const float AnimCoolTimeMax = 0.25f;

    int X, Y;
    int Player1_Graph[6];
    int Player2_Graph[6];
    int Player3_Graph[6];
    int Player4_Graph[6];
    int PlayerNum;
    enum
    {
        Player1,Player2,Player3,Player4
    };

    int Speed;
    
    int DeadFrameCount;
    //アニメーションフレーム
    int AnimFrame;
    float AnimCoolTime;
    int AnimNum;
    //アニメーション開始位置
    int AnimPatternFirst;
    bool Dead;
    bool Goal;
    //右向き false
    bool Reverse;
};