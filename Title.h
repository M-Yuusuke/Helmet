#pragma once
class Scene;
class BackGround;
class Sound;
class Title
{
public:
    Title();
    ~Title();
    void Update(Scene* scene, Sound* sound);
    void Draw(BackGround* background, Scene* scene);

private:
    const int MaxColor = 255;
    int BToPlay;
    int Alpha;

    //ゲームパッドステータス
    XINPUT_STATE input;
};

