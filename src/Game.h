#include "dependencies\olcPixelGameEngine.h"

	class Game : public olc::PixelGameEngine
	{
	public:
		bool OnUserCreate() override;
		bool OnUserUpdate(float fElapsedTime) override;
	};