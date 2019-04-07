#include "Rectangle.h"
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

template <>
struct hash<Vector2> {
	std::size_t operator()(const Vector2& v) const {
		auto large = v.x > v.y ? v.x : v.y;
		return v.x + v.y * large;
	}
};

unordered_set<Vector2> findOverlap(vector<Rectangle>& rects) {
	unordered_set<Vector2> points;
	for (auto rect1 : rects) {
		for (auto p : rect1.getPoints()) {
			bool contained = true;
			for (auto rect2 : rects) {
				if (!rect2.containsPoint(p)) {
					contained = false;
					break;
				}
			}
			if (contained) points.insert(p);
		}
	}
	return points;
}

// Time Complexity: O(n^2), n = number of rectangles
int main() {
	vector<Rectangle> rects = {
		Rectangle(Vector2(0, 4), Vector2(4, 0)),
		Rectangle(Vector2(0, 2), Vector2(2, 0)),
		Rectangle(Vector2(0, 1), Vector2(1, 0))
	};
	auto points = findOverlap(rects);
	hash<Vector2> hasher;
	for (auto point : points)
		cout << point << " " << hasher(point) << endl;
}

// For a O(n) solution, track the overlap and adjust
// the overlap rectangle by rectangle.
