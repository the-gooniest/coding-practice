#ifndef VECTOR2
#define VECTOR2
#include <iostream>

class Vector2 {
public:
	const int x;
	const int y;
	Vector2() : x(0), y(0) {}
	Vector2(int nx, int ny): x(nx), y(ny) {}
	friend std::ostream& operator<<(std::ostream& os, const Vector2& vec)
	{
		os << "(" << vec.x << ", " << vec.y << ")";
		return os;
	}
	bool operator==(const Vector2& v) const {
		return (v.x == x && v.y == y);
	}
};

#endif