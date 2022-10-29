#pragma once
class Scene;
class BackGround;
class Sound;
class Player;
class UI;
class GameClear
{
public:
    GameClear();
    ~GameClear();
    void Update(Scene* scene, Sound* sound);
    void Draw(int Score, Player* player, UI* ui, BackGround* background, Scene* scene);

private:
    const int MaxColor = 255;
    int Alpha;
    //ゲームパッドステータス
    XINPUT_STATE input;
};

