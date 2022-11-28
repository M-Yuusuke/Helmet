#pragma once
class UI
{
public:
    static void Create();
    static void Destroy();
    static UI* GetInstance() { return Instance; }

    void Initialize();
    //�^�C�g�����
    void TitleWriteBToPlay();
    //��������
    void WriteLimitTime(int LimitTime);
    //�X�R�A
    void WriteScore(int Score);
    //�v���C���[�̎��S�񐔕`��
    void DrawPlayerDead(int LifeNum);
    //�J�߂�UI�֌W
    void Update(float Deltatime);
    void DrawPraise();
    void SetVisible();
    bool GetExcellentUIVisible() const { return ExcellentUIVisible; }

    //���U���g���
    void ResultWriteScore(int Score);
    void ResultWriteBToTitle();

private:
    UI();
    ~UI();
    static UI* Instance;

    const int FontSize = 60;
    const int LimitTimePosX = 850;
    const int UIPosY = 20;
    const int ScorePosX = 500;

    //�v���C���[�̎c�@�\��
    const int LifeStringPosX = 1200;
    const int IconWidth = 75;
    int PlayerHeadGraph;

    //�J�߂�UI
    const int GoodUIPosX = 1620;
    const int GoodUIPosY = 100;

    const int MeterPosX = 1620;
    const int MeterPosY = 400;
    const int MeterHeight = 32;
    //�A�j���[�V�����̕\������
    const float CoolTimeMax = 5.0f;

    int GoodUI;
    int ExcellentUI;
    float CoolTime;
    bool GoodUIVisible;
    bool ExcellentUIVisible;

    //���U���g���
    const int ResultUIPosX = 600;
    const int ResultUIPosY = 700;

};

