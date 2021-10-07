#include "Game.h"

Game::Game() :
	m_pRenderEngine(nullptr)
{
	m_pRenderEngine = new RenderEngine();

	for (int i = 0; i < 5; ++i)
	{
		m_GBodies.push_back(GBody((i + 1) * 100));
	}

	m_Timer.Start();
}

Game::~Game()
{
}

void Game::Run()
{
	m_Timer.Reset();

	while (true)
	{
		m_pRenderEngine->GetRT()->RC_BeginFrame();

		m_Timer.Tick();

		if (!Update())
			break;

		m_pRenderEngine->GetRT()->RC_EndFrame();
	}
}

bool Game::Update()
{
	static float t = 0;
	float deltaTime = m_Timer.DeltaTime();
	// t += m_Timer.DeltaTime();
	t += 0.001f;
	m_pRenderEngine->GetRT()->RC_OscillateCamera(10.0f + sin(t));

	for (int i = 0; i < m_GBodies.size(); ++i)
	{
		m_GBodies[i].Update(deltaTime);
		m_pRenderEngine->GetRT()->RC_UpdateGBody(i, m_GBodies[i].GetPosition());
	}

	return true;
}
