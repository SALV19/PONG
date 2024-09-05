#include "Ball.h"

Ball::Ball(float startX, float startY)
{
	m_Positon.x = startX;
	m_Positon.y = startY;

	m_Shape.setSize(Vector2f(10, 10));
	m_Shape.setPosition(m_Positon);
}

FloatRect Ball::getPosition()
{
	return m_Shape.getGlobalBounds();
}

RectangleShape Ball::getShape()
{
	return m_Shape;
}
float Ball::getXVelocity()
{
	return m_DirectionX;
}

void Ball::reboundSides()
{
	m_DirectionX *= -1;
	//m_Speed += 5;
}
void Ball::reboundBatOrTop()
{
	m_DirectionY *= -1;
	//m_Speed += 5;
}

void Ball::reboundBottom()
{
	m_Positon.y = 0;
	m_Positon.x = 500;
	m_DirectionY *= -1;
	
}

void Ball::update(Time dt)
{
	m_Positon.y += m_DirectionY * (m_Speed * dt.asSeconds());
	m_Positon.x += m_DirectionX * (m_Speed * dt.asSeconds());

	m_Shape.setPosition(m_Positon);
}

