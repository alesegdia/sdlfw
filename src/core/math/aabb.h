#ifndef __AABB_H__
#define __AABB_H__

#include "vec2.h"

class AABB {

public:

	AABB() : topLeft(0,0), botRight(0,0) {}
	AABB( Vec2 topLeft, Vec2 botRight )
	{ set(topLeft.x, topLeft.y, botRight.x, botRight.y); }
	AABB( float x1, float y1, float x2, float y2 )
	{ set(x1,y1,x2,y2); }

	void set( float x1, float y1, float x2, float y2 )
	{
		topLeft.x = x1;
		topLeft.y = y1;
		botRight.x = x2;
		botRight.y = y2;
		calculateHalfSize();
	}

	void calculateHalfSize()
	{
		HalfSize.x = botRight.x - topLeft.x;
		HalfSize.y = botRight.y - topLeft.y;
	}

	bool intersects( const AABB& other ) const
	{
		if( other.botRight.x < topLeft.x || other.topLeft.x > botRight.x )
			return false;
		if( other.botRight.y < topLeft.y || other.topLeft.y > botRight.y )
			return false;
		return true;
	}

	const Vec2& gettopLeft() const
	{ return topLeft; }
	const Vec2& getbotRight() const
	{ return botRight; }
	const Vec2& getHalfSize() const
	{ return HalfSize; }

	void Move(float x, float y)
	{
		botRight.Add(x,y);
		topLeft.Add(x,y);
	}

	void Place(float x, float y)
	{
		topLeft.Set(x,y);
		botRight.Set(x+W(),y+H());
	}

	void SetSize(float w, float h)
	{
		botRight.x = topLeft.x + w;
		botRight.y = topLeft.y + h;
		HalfSize.x = w/2;
		HalfSize.y = h/2;
	}

	float X() const
	{ return topLeft.x; }
	float Y() const
	{ return topLeft.y; }
	float W() const
	{ return HalfSize.x*2; } //botRight.x - topLeft.x; }
	float H() const
	{ return HalfSize.y*2; } //botRight.y - topLeft.y; }
	float HalfWidth() const
	{ return HalfSize.x; }
	/*
	void UpdateRect()
	{
		Rect.x = GetX();
		Rect.y = GetY();
		Rect.w = ;
	}*/

private:
	Vec2 topLeft;
	Vec2 botRight;

	// unused
	Vec2 HalfSize;

};

#endif
