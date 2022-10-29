#pragma once
class Scene;
class Rule;
class UI;
class Player;
class Tool;
class Door;
class Sound;
class Initialize 
{
public:
    Initialize();
    void Reset(Rule* rule, UI* ui, Door* door, Player* player, Tool* tool, Sound* sound, Scene* scene);

private:
    
};

