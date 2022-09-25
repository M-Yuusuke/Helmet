#include "DxLib.h"
#include "BackGround.h"

BackGround::BackGround()
{
    X = 0;
    Y = 0;
    Graph = LoadGraph("../../Img/BackGround.png");
}

BackGround::~BackGround()
{
    DeleteGraph(Graph);
}

void BackGround::Draw()
{
    DrawGraph(X, Y, Graph, FALSE);
}
