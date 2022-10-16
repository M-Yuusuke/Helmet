#pragma once
class SceneManager;
class Sound;
class Title
{
public:
    Title();
    ~Title();
    void TitleDraw(SceneManager* scenemanager,Sound*sound);

private:
    const int MaxColor = 255;
    int BackGround;
    int SpaceToPlay;
    int Alpha;
};

