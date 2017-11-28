#pragma once

#include "SFML\Graphics.hpp"

using SnakeContainer = std::vector<SnakeSegment>;

struct SnakeSegment
{
	SnakeSegment(int x, int y) : SnakePosition(x, y) {}
	
	sf::Vector2i SnakePosition;
};

enum class Direction
{
	None, Up, Down, Left, Right
};

class Snake
{
	
public:

	Snake(int SnakeBlockSize);

	Direction GetDirection()
	{
		return m_SnakeDirection;
	}

	sf::Vector2i GetPosition()
	{
		return (!m_SnakeBody.empty() ? m_SnakeBody.front().position : sf::Vector2i(1, 1));
	}

	void SetDirection(Direction Dir)
	{
		Dir = m_SnakeDirection;
	}

	void IncreaseScore()
	{
		m_SnakeScore += 10;
	}

	void ToggleLost()
	{
		m_SnakeLost = !m_SnakeLost;
	}

	void Lose()
	{
		m_SnakeLost = true;
	}

	void Cut(int NumberOfSegments);
	void Render(sf::RenderWindow &GameWindow);
	void Extend();
	void Reset();
	void Move();
	void Tick();

	int GetSpeed()
	{
		return m_SnakeSpeed;
	}

	int GetLives()
	{
		return m_SnakeLives;
	}

	int GetScore()
	{
		return m_SnakeScore;
	}

	bool HasLost()
	{
		return m_SnakeLost;
	}

private:

	void CheckCollision();

	SnakeContainer m_SnakeBody;

	Direction m_SnakeDirection;

	sf::RectangleShape m_SnakeBodyRect;

	int m_SnakeSize;
	int m_SnakeSpeed;
	int m_SnakeLives;
	int m_SnakeScore;

	bool m_SnakeLost;

};