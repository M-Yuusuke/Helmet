#pragma once
class UI
{
public:
    UI();
    ~UI();
    //��������
    void WriteLimitTime(int LimitTime);
    //�X�R�A
    void WriteScore(int Score);
    //�v���C���[�̎��S�񐔕`��
    void DrawPlayerDead(int DeadNum);
<<<<<<< HEAD
    //�J�߂�UI�̕`��
    void DrawGoodUI(float DeltaTime);
    void SetVisible() { Visible = true; CoolTime = CoolTimeMax; }
=======
>>>>>>> origin/main

private:
    const int FontSize = 48;
    const int IconWidth = 60;
    const int LimitTimePosX = 850;
    const int ScorePosX = 500;
<<<<<<< HEAD

    //�v���C���[�̃~�X�񐔃J�E���g
    const int MissStringPosX = 1200;
    const int MissStringPosY = 10;
    int PlayerHeadGraph;

    //�J�߂�UI
    const int GoodUIPosX = 1620;
    const int GoodUIPosY = 100;
    const int CoolTimeMax = 3;
    int GoodUI;
    float CoolTime;
    int ExcellentUI;
    bool Visible;
=======
    const int MissStringPosX = 1200;
    const int MissStringPosY = 10;

    int Graph;
>>>>>>> origin/main
};

