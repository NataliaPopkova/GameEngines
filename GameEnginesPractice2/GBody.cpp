#include "GBody.h"

GBody::GBody(float radius)
	: m_fRadius(radius), m_Position({ 0, 0, 0 }), m_Velocity({ 0, 0.1, 0 }) {}

void GBody::Update(float deltaTime)
{
	m_Position.x += m_Velocity.x * deltaTime;
	m_Position.y += m_Velocity.y * deltaTime;
}

Ogre::Vector3 GBody::GetPosition()
{
	return Ogre::Vector3({
		m_fRadius * cos(m_Position.x),
		m_fRadius * sin(m_Position.x),
		0 });
}