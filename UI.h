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

private:
    const int FontSize = 48;
    const int IconWidth = 60;
    const int LimitTimePosX = 850;
    const int ScorePosX = 500;
    const int MissStringPosX = 1200;
    const int MissStringPosY = 10;

    int Graph;
};

