#ifndef Game_H
#define Game_H

#include "..\dependencies\olcPixelGameEngine.h"

#include <vector>
#include "Entity.h"
#include "Vector2.h"
#include "Collision_Trigger.h"

class Game : public olc::PixelGameEngine
{
public:
	std::vector<Entity*> Entities;
	std::vector<Collision_Trigger*> Triggers;
	Entity* player;
	Vector2 CameraCord;
	Vector2 pivot;
	float TileSize = 32.0f;
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