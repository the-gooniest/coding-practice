#include "Rectangle.h"

using namespace std;

bool Rectangle::containsPoint(Vector2 p) {
	return p.x >= tl.x && p.x <= br.x && p.y <= tl.y && p.y >= br.y;
}

vector<Vector2> Rectangle::getPoints() {
	vector<Vector2> points = {
		Vector2(tl.x, tl.y),
		Vector2(tl.x, br.y),
		Vector2(br.x, tl.y),
		Vector2(br.x, br.y)
	};
	return points;
}