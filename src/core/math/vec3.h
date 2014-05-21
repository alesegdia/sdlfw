#ifndef __VEC2_H__
#define __VEC2_H__

struct Vec3 {

	Vec3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Vec3( float px, float py, float pz )
	{
		x = px;
		y = py;
		z = pz;
	}

	Vec3( const Vec3& other )
	{ Set(other); }

	void Add(float px, float py, float pz)
	{ x += px; y += py; z += pz;}

	void Set(float x, float y, float z)
	{ this->x=x;this->y=y; this->z=z; }

	void Set(const Vec2& other)
	{ x = other.x; y = other.y; z = other.z; }

	float x;
	float y;
	float z;
};

#endif
