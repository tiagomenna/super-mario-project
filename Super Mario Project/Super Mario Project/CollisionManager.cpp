////////////////////////////////////////////////////////////////////////
// CollisionManager.cpp
// Super Mario Project
// Copyright (C) 2011
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "CollisionManager.hpp"
#include <iostream>

namespace Collisions
{
	CollisionManager* CollisionManager::_manager = NULL;

	/* SINGLETON PATTERN */
	CollisionManager* CollisionManager::getManager()
	{
		if(_manager == nullptr)
		{
			_manager = new CollisionManager();
		}

		return _manager;
	}

	void CollisionManager::solveCollisions(EntityMovable* et1, Collisionable* c2, Level*, RenderWindow&)
	{
		vector<bool> infos;
		
		if(detectCollisions(et1, c2, infos))
		{
			et1->onCollision(c2, infos);
		}
	}

	void CollisionManager::solveCollisions(EntityMovable* et1, EntityMovable* et2, Level*, RenderWindow&)
	{
		vector<bool> infos;
		
		if(detectCollisions(et1, et2, infos))
		{
			et1->onCollision(et2, infos);
			et2->onCollision(et1, infos);
		}
	}

	bool CollisionManager::detectCollisions(EntityMovable* et1, Collisionable* c2, vector<bool>& collisions_info)
	{
		sf::FloatRect r1(et1->getHitboxPosition().x, et1->getHitboxPosition().y + et1->getHitboxSize().y,
			et1->getHitboxPosition().x + et1->getHitboxSize().x, et1->getHitboxPosition().y),

			r1Prec(et1->getPreviousHitboxPosition().x, et1->getPreviousHitboxPosition().y + et1->getHitboxSize().y,
			et1->getPreviousHitboxPosition().x + et1->getHitboxSize().x, et1->getPreviousHitboxPosition().y),

			r2(c2->getHitboxPosition().x, c2->getHitboxPosition().y + c2->getHitboxSize().y, 
			c2->getHitboxPosition().x + c2->getHitboxSize().x, c2->getHitboxPosition().y);
		bool collisionDetected = false;

		if(r1Prec.Left <= r2.Right && r1.Left >= r2.Right)
		{
			collisionDetected = true;
			collisions_info.push_back(true);
		}
		else
			collisions_info.push_back(false);
		
		if(r1Prec.Top <= r2.Bottom && r1.Top >= r2.Bottom)
		{
			collisionDetected = true;
			collisions_info.push_back(true);
		}
		else
			collisions_info.push_back(false);

		if(r1Prec.Right <= r2.Left && r1.Right >= r2.Left)
		{
			collisionDetected = true;
			collisions_info.push_back(true);
		}
		else
			collisions_info.push_back(false);

		if(r1Prec.Bottom >= r2.Top && r1.Bottom <= r2.Top)
		{
			collisionDetected = true;
			collisions_info.push_back(true);
		}
		else
			collisions_info.push_back(false);

		return collisionDetected;
	}

	bool CollisionManager::detectCollisions(EntityMovable* et1, EntityMovable* et2, vector<bool>& collisions_info)
	{
		sf::FloatRect r1(et1->getHitboxPosition().x, et1->getHitboxPosition().y + et1->getHitboxSize().y,
			et1->getHitboxPosition().x + et1->getHitboxSize().x, et1->getHitboxPosition().y),

			r1Prec(et1->getPreviousHitboxPosition().x, et1->getPreviousHitboxPosition().y + et1->getHitboxSize().y,
			et1->getPreviousHitboxPosition().x + et1->getHitboxSize().x, et1->getPreviousHitboxPosition().y),

			r2(et2->getHitboxPosition().x, et2->getHitboxPosition().y + et2->getHitboxSize().y, 
			et2->getHitboxPosition().x + et2->getHitboxSize().x, et2->getHitboxPosition().y),

			r2Prec(et2->getPreviousHitboxPosition().x, et2->getPreviousHitboxPosition().y + et2->getHitboxSize().y,
			et2->getPreviousHitboxPosition().x + et2->getHitboxSize().x, et2->getPreviousHitboxPosition().y);
		bool collisionDetected = false;

		if(r1Prec.Left <= r2Prec.Right && r1.Left >= r2.Right)
		{
			collisionDetected = true;
			collisions_info.push_back(true);
		}
		else
			collisions_info.push_back(false);
		
		if(r1Prec.Top <= r2Prec.Bottom && r1.Top >= r2.Bottom)
		{
			collisionDetected = true;
			collisions_info.push_back(true);
		}
		else
			collisions_info.push_back(false);

		if(r1Prec.Right <= r2Prec.Left && r1.Right >= r2.Left)
		{
			collisionDetected = true;
			collisions_info.push_back(true);
		}
		else
			collisions_info.push_back(false);

		if(r1Prec.Bottom >= r2Prec.Top && r1.Bottom <= r2.Top)
		{
			collisionDetected = true;
			collisions_info.push_back(true);
		}
		else
			collisions_info.push_back(false);

		return collisionDetected;

	}

	CollisionManager::~CollisionManager()
	{
		delete _manager;
	}

} // namespace
