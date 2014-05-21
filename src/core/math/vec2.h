#ifndef __VEC2_H__
#define __VEC2_H__

struct Vec2 {

	Vec2()
	{
		x = 0;
		y = 0;
	}

	Vec2( float px, float py )
	{
		x = px;
		y = py;
	}

	Vec2( const Vec2& other )
	{ Set(other); }

	void Add(float px, float py)
	{ x += px; y += py; }

	void Set(float x, float y)
	{ this->x=x;this->y=y; }

	void Set(const Vec2& other)
	{ x = other.x; y = other.y; }

	float x;
	float y;
};

#endif
