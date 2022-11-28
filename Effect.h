#pragma once
class Effect
{
public:
    static void Create();
    static void Destroy();
    static Effect* GetInstance() { return Instance; }

    void Update(float DeltaTime);
    void Draw();

    void SetVisible() { IsVisible = true; }
    void OnDamage(float PlayerX, float PlayerY);

private:
    Effect();
    ~Effect();
    static Effect* Instance;
    /**�A�j���[�V�����؂�ւ��̃^�C�~���O*/
    const float AnimCoolTimeMax = 0.125f;
    const float DamageCoolTimeMax = 0.8f;

    /**�摜�̑�������*/
    const int TotalGraphNum = 9;
    /**�摜�T�C�Y*/
    const int GraphSize = 128;
    const int EffectPosX = 1615;
    const int EffectPosY = 800;

    /**�摜�̃V���A���i���o�[���i�[����z��*/
    int Graph[9];
    /**�_���[�W���󂯂��Ƃ��̃G�t�F�N�g���i�[����ϐ�*/
    int Damage;
    int X, Y;
    /**�A�j���[�V�����̐؂�ւ��^�C�~���O���L�^����ϐ�*/
    float AnimCoolTime;
    int AnimNum;
    /**�\������*/
    float VisibleTime;
    /**�_���[�W�G�t�F�N�g�̕\������*/
    float DamageVisibleTime;
    /**�\���t���O�@������:true�@�����Ȃ�:false*/
    bool IsVisible;
    bool IsDamage;
};

