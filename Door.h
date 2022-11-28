#pragma once
class Sound;
class Door
{
public:
    static void Create();
    static void Destroy();
    static Door* GetInstance() { return Instance; }
    void Initialize();
    void Update(float DeltaTime, Sound* sound);
    void Draw();
    bool IsOpen()const { return Open; }


private:
    Door();
    ~Door();
    static Door* Instance;
    const int DoorPosX = 1615;
    const int DoorPosY = 802;
    /**画像の分割総数*/
    const int TotalGraphNum = 2;
    /**右側のドアの開閉抽選時間の最大値*/
    const float CoolTimeMax = 1.5f;
    /**右側のドアの幅と高さ*/
    const float Width = 176.5f, Height = 192;

    /**分割した画像のシリアルナンバーを格納する配列*/
    int Graph[2];
    /**右のドアの開閉抽選時間を記録する変数*/
    float CoolTime;
    /**発生させた乱数を格納する変数　アニメーションナンバーにも流用*/
    int AnimNum;
    /**ドアが開いているかどうかのフラグ*/
    bool Open;
    /**前のフレームのドアの状態を記録する変数　ドアの開閉音の再生で必要*/
    bool OpenPrev;
};

