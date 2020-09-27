#ifndef MapConstructor_H
#define MapConstructor_H

#include "Game.h"

#include <vector>

#include "Entity.h"

class MapConstructor : public Game
{
    private:
    Vector2 startPoint;
    Vector2 EstartPoint;
    std::vector<AABB> Walls;
    bool isDrawing = false;
    bool isEreasing = false;

    private:
    bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
	bool OnUserDestroy() override;
};

#endif