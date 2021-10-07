#pragma once

#include "RenderEngine.h"
#include "GameTimer.h"
#include "GBody.h"

class Game
{
public:
	Game();
	~Game();
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	
	void Run();
	bool Update();

private:
	GameTimer m_Timer;
	RenderEngine* m_pRenderEngine;
	std::vector<GBody> m_GBodies;
};

