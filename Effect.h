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
    /**アニメーション切り替わりのタイミング*/
    const float AnimCoolTimeMax = 0.125f;
    const float DamageCoolTimeMax = 0.8f;

    /**画像の総分割数*/
    const int TotalGraphNum = 9;
    /**画像サイズ*/
    const int GraphSize = 128;
    const int EffectPosX = 1615;
    const int EffectPosY = 800;

    /**画像のシリアルナンバーを格納する配列*/
    int Graph[9];
    /**ダメージを受けたときのエフェクトを格納する変数*/
    int Damage;
    int X, Y;
    /**アニメーションの切り替わるタイミングを記録する変数*/
    float AnimCoolTime;
    int AnimNum;
    /**表示時間*/
    float VisibleTime;
    /**ダメージエフェクトの表示時間*/
    float DamageVisibleTime;
    /**表示フラグ　見える:true　見えない:false*/
    bool IsVisible;
    bool IsDamage;
};

