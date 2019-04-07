#pragma once
#include "Vector2.h"
#include <vector>
#include <iostream>

class Rectangle {
public:
	const Vector2 tl;
	const Vector2 br;
	Rectangle() : tl(Vector2()), br(Vector2()) {}
	Rectangle(Vector2 newTL, Vector2 newBR) : tl(newTL), br(newBR) {}
	bool containsPoint(Vector2 point);
	std::vector<Vector2> getPoints();
	friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect)
	{
		os << "(" << rect.tl << ", " << rect.br << ")";
		return os;
	}
};