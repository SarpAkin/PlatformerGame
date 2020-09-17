#ifndef Game_H
#define Game_H

#include "dependencies\olcPixelGameEngine.h"

#include <vector>
#include "Entity.h"
#include "Vector2.h"

class Game : public olc::PixelGameEngine
{
public:
	std::vector<Entity*> Entities;
	Vector2* CameraCord;
	float TileSize = 32.0f;
public:
	void DrawEntity(olc::Sprite*,Entity& e);
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
	bool OnUserDestroy() override;
};

#endif