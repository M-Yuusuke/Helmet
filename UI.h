#pragma once
class UI
{
public:
    UI();
    ~UI();
    void Initialize();
    //��������
    void WriteLimitTime(int LimitTime);
    //�X�R�A
    void WriteScore(int Score);
    //�v���C���[�̎��S�񐔕`��
    void DrawPlayerDead(int DeadNum);
    //�J�߂�UI�̕`��
    void DrawGoodUI(float DeltaTime);
    void SetVisible() { CoolTime = CoolTimeMax; Visible = true; }

private:
    const int FontSize = 48;
    const int IconWidth = 60;
    const int LimitTimePosX = 850;
    const int ScorePosX = 500;

    //�v���C���[�̃~�X�񐔃J�E���g
    const int MissStringPosX = 1200;
    const int MissStringPosY = 10;
    int PlayerHeadGraph;

    //�J�߂�UI
    const int GoodUIPosX = 1620;
    const int GoodUIPosY = 100;
    const float CoolTimeMax = 3.0f;
    int GoodUI;
    float CoolTime;
    int ExcellentUI;
    bool Visible;
};

