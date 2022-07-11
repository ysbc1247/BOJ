#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
#include<functional>
#define endl "\n"
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;


struct point {
	int x, y;
};

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	ll ret = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (ret > 0) {
		return 1;
	}
	else if (ret < 0) {
		return -1;
	}
	else {
		return 0;
	}
}
bool cross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) <= 0 && 
		ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) <= 0) {
		if ((x1 < x3 && x1 < x4 && x2 < x3 && x2 < x4) || 
			(x3 < x1 && x3 < x2 && x4 < x1 && x4 < x2)) {
			return false;
		}
		if ((y1 < y3 && y1 < y4 && y2 < y3 && y2 < y4) || 
			(y3 < y1 && y3 < y2 && y4 < y1 && y4 < y2)) {
			return false;
		}
		return true;
	}
	return false;

}
bool rect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	int line = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
	int rec = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);
	if (line == 0 && rec <= 0) {
		return true;
	}
	else {
		return false;
	}
}
bool line(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	int line = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
	int rec = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);
	if (line <0 && rec <= 0) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	fastio;
	int t; cin >> t;
	while (t--) {
		int xmin, ymin, xmax, ymax;
		cin >> xmin >> ymin >> xmax >> ymax;
		point r1 = { xmin,ymin };
		point r2 = { xmin,ymax };
		point r3 = { xmax,ymin };
		point r4 = { xmax,ymax };
		point l1, l2;
		int x1, y1, x2, y2;
		cin >> l1.x >> l1.y >> l2.x >> l2.y;
		if (l1.x > l2.x) {
			swap(l1, l2);
		}
		bool isnone = true;
		if (cross(l1.x, l1.y, l2.x, l2.y, r1.x, r1.y, r2.x, r2.y) ||
			cross(l1.x, l1.y, l2.x, l2.y, r2.x, r2.y, r4.x, r4.y) ||
			cross(l1.x, l1.y, l2.x, l2.y, r4.x, r4.y, r3.x, r3.y) ||
			cross(l1.x, l1.y, l2.x, l2.y, r3.x, r3.y, r1.x, r1.y)) {
			isnone = false;
		}
		if (isnone) {
			cout << 0 << endl;
			continue;
		}
		if (l1.x == l2.x && l1.x == xmax) {
			if ((l1.y < ymax) && (l2.y > ymin) || (l2.y < ymax) && (l1.y > ymin)) {
				cout << 4 << endl;
				continue;
			}
		}
		if (l1.x == l2.x && l1.x == xmin) {
			if ((l1.y < ymax) && (l2.y > ymin) || (l2.y < ymax) && (l1.y > ymin)) {
				cout << 4 << endl;
				continue;
			}
		}
		else if (l1.y == l2.y && l1.y == ymax) {
			if ((l1.x < xmax) && (l2.x > xmin) || (l2.x < xmax) && (l1.x > xmin)) {
				cout << 4 << endl;
				continue;
			}
		}
		else if (l1.y == l2.y && l1.y == ymin) {
			if ((l1.x < xmax) && (l2.x > xmin) || (l2.x < xmax) && (l1.x > xmin)) {
				cout << 4 << endl;
				continue;
			}
		}
		int cnt_rect_line = 0;
		int cnt_rect_point = 0;
		if (line(l1.x, l1.y, l2.x, l2.y, r1.x, r1.y, r2.x, r2.y)) {
			cnt_rect_line++;
		}
		if (line(l1.x, l1.y, l2.x, l2.y, r2.x, r2.y, r4.x, r4.y)) {
			cnt_rect_line++;
		}
		if (line(l1.x, l1.y, l2.x, l2.y, r4.x, r4.y, r3.x, r3.y)) {
			cnt_rect_line++;
		}
		if (line(l1.x, l1.y, l2.x, l2.y, r3.x, r3.y, r1.x, r1.y)) {
			cnt_rect_line++;
		}

		if (rect(l1.x, l1.y, l2.x, l2.y, r1.x, r1.y, r2.x, r2.y)) {
			cnt_rect_point++;
		}
		if (rect(l1.x, l1.y, l2.x, l2.y, r2.x, r2.y, r4.x, r4.y)) {
			cnt_rect_point++;
		}
		if (rect(l1.x, l1.y, l2.x, l2.y, r4.x, r4.y, r3.x, r3.y)) {
			cnt_rect_point++;
		}
		if (rect(l1.x, l1.y, l2.x, l2.y, r3.x, r3.y, r1.x, r1.y)) {
			cnt_rect_point++;
		}
		cout << cnt_rect_line + cnt_rect_point / 2 << endl;
	}
}