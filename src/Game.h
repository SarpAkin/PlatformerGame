#ifndef Game_H
#define Game_H

#include "..\dependencies\olcPixelGameEngine.h"

#include <vector>
#include "Entity.h"
#include "Vector2.h"
#include "Collision_Trigger.h"
#include "Entities\Player.h"
#include "Entities\Player.h"


const float MaxTileSize = 128;
const float MinTileSize = 4;

class Game : public olc::PixelGameEngine
{
public:
	std::vector<Entity*> Entities;
	std::vector<Collision_Trigger*> Triggers;
	Player* player;
	Vector2 CameraCord;
	Vector2 pivot;
	bool isTriggersVisible = false;
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
	inline Vector2 ScreenCordToLocal(int x,int y)
	{
		return GetCamCord() + Vector2(x,y) / TileSize;
	}
	inline olc::vi2d LocalCordToScreen(Vector2 v)
	{
		Vector2 final = (v - GetCamCord()) * TileSize;
		return olc::vi2d((int32_t)final.x,(int32_t)final.y);
	}
};

#endif