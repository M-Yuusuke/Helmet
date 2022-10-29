#pragma once
class Scene;
class Sound;
class Player;
class UI;
class BackGround;
class Result
{
public:
    Result();
    ~Result();
    void Update(Scene* scene, Sound* sound);
    void Draw(int Score, Player* player, UI* ui, BackGround* background, Scene* scene);
private:
    const int MaxColor = 255;
    int Alpha;
    //ゲームパッドステータス
    XINPUT_STATE input;
};

