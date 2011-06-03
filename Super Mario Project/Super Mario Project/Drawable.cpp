////////////////////////////////////////////////////////////////////////
// Drawable.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Drawable.hpp"

namespace Rendering
{
	Drawable::Drawable(const string& textureName)
	{
		InitializeDrawable(textureName);
	}

	Drawable::Drawable(const string& textureName, Coord<float>& position)
	{
		InitializeDrawable(textureName);
		_position = position;
	}

	void Drawable::InitializeDrawable(const string& textureName)
	{
		_texture = new Texture(textureName);
		_spriteNumbersByState = vector<int>();
		_animationSpeeds = vector<int>();
		_position = Coord<float>();
	}

	Texture* Drawable::getTexture()
	{
		return _texture;
	}

	Coord<float> Drawable::getPosition()
	{
		return _position;
	}

	void Drawable::setPosition(float x, float y)
	{
		_position.set(x, y);
	}

	Drawable::~Drawable()
	{
	}
} // namespace
