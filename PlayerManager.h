#pragma once
#include<vector>

using namespace std;
class Player;
class PlayerManager
{
public:
    PlayerManager();
    ~PlayerManager();

private:
    vector<Player> playermanager;
};

