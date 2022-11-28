#pragma once
class SceneBase;
class Initialize;
class Title;
class GameMain;
class Result;
class SceneManager
{
public:
    SceneManager();
    ~SceneManager();
    
    SceneBase* GetNextScene(SceneBase* NowScene)const;

private:
    Initialize* initialize;
    Title* title;
    GameMain* gamemain;
    Result* result;
};

