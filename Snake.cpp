#include "Snake.h"

Snake::Snake(int SnakeBlockSize)
{
	m_SnakeSize = SnakeBlockSize;
	m_SnakeBodyRect.setSize(sf::Vector2f(m_SnakeSize - 1, m_SnakeSize - 1));
	Reset();
}

void Snake::Extend()
{
	if (m_SnakeBody.empty())
	{
		return;
	}

	SnakeSegment &SnakeHead = m_SnakeBody[m_SnakeBody.size() - 1];
	SnakeSegment &SnakeTailBone = m_SnakeBody[m_SnakeBody.size() - 2];
	
	if (m_SnakeBody.size() > 1)
	{
		if (SnakeHead.SnakePosition.x == SnakeTailBone.SnakePosition.x)
		{
			if (SnakeHead.SnakePosition.y == SnakeTailBone.SnakePosition.y)
			{
				m_SnakeBody.push_back(SnakeSegment(SnakeHead.SnakePosition.x, SnakeHead.SnakePosition.y + 1));
			}
			else
			{
				m_SnakeBody.push_back(SnakeSegment(SnakeHead.SnakePosition.x, SnakeHead.SnakePosition.y - 1));
			}
		}
		else if (SnakeHead.SnakePosition.y == SnakeTailBone.SnakePosition.y)
		{
			if (SnakeHead.SnakePosition.x > SnakeTailBone.SnakePosition.x)
			{
				m_SnakeBody.push_back(SnakeSegment(SnakeHead.SnakePosition.x + 1, SnakeHead.SnakePosition.y));
			}
			else
			{
				m_SnakeBody.push_back(SnakeSegment(SnakeHead.SnakePosition.x - 1, SnakeHead.SnakePosition.y));
			}
		}
	}
	else
	{
		if (m_SnakeDirection == Direction::Up)
		{
			m_SnakeBody.push_back(SnakeSegment(SnakeHead.SnakePosition.x, SnakeHead.SnakePosition.y + 1));
		}
		else if (m_SnakeDirection == Direction::Down)
		{
			m_SnakeBody.push_back(SnakeSegment(SnakeHead.SnakePosition.x, SnakeHead.SnakePosition.y - 1));
		}
		else if (m_SnakeDirection == Direction::Right)
		{
			m_SnakeBody.push_back(SnakeSegment(SnakeHead.SnakePosition.x + 1, SnakeHead.SnakePosition.y));
		}
		else if (m_SnakeDirection == Direction::Left)
		{
			m_SnakeBody.push_back(SnakeSegment(SnakeHead.SnakePosition.x - 1, SnakeHead.SnakePosition.y));
		}
	}
}

void Snake::Reset()
{
	m_SnakeBody.clear();

	// Starting position (3 long)
	m_SnakeBody.push_back(SnakeSegment(5, 7));
	m_SnakeBody.push_back(SnakeSegment(5, 6));
	m_SnakeBody.push_back(SnakeSegment(5, 5));

	SetDirection(Direction::None);

	m_SnakeSpeed = 15;
	m_SnakeLives = 3;
	m_SnakeScore = 0;
	m_SnakeLost = false;
}

void Snake::Tick()
{

}
