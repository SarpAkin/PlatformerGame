#ifndef Game_H
#define Game_H

#include "..\dependencies\olcPixelGameEngine.h"

#include <vector>
#include "Entity.h"
#include "Vector2.h"

class Game : public olc::PixelGameEngine
{
public:
	std::vector<Entity*> Entities;
	Entity* player;
	Vector2 CameraCord;
	Vector2 pivot;
	float TileSize = 16.0f;
public:
	void DrawEntity(olc::Sprite*,Entity& e);
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
	bool OnUserDestroy() override;
	inline Vector2 GetCamCord()
	{
		return CameraCord - pivot / TileSize;
	}
};

#endif