#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<iomanip>
#define endl "\n"
#define _USE_MATH_DEFINES
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;
char cube[7][4][4] = {};
char a, b, c, d, e, f, g, h, i, j, k,l;
void clock(int n) {
	a = cube[n][1][1];
	b = cube[n][1][2];
	c = cube[n][1][3];
	d = cube[n][2][1];
	e = cube[n][2][3];
	f = cube[n][3][1];
	g = cube[n][3][2];
	h = cube[n][3][3];
	cube[n][1][1] = f;
	cube[n][1][2] = d;
	cube[n][1][3] = a;
	cube[n][2][1] = g;
	cube[n][2][3] = b;
	cube[n][3][1] = h;
	cube[n][3][2] = e;
	cube[n][3][3] = c;
}
void aclock(int n) {
	a = cube[n][1][1];
	b = cube[n][1][2];
	c = cube[n][1][3];
	d = cube[n][2][1];
	e = cube[n][2][3];
	f = cube[n][3][1];
	g = cube[n][3][2];
	h = cube[n][3][3];
	cube[n][1][1] = c;
	cube[n][1][2] = e;
	cube[n][1][3] = h;
	cube[n][2][1] = b;
	cube[n][2][3] = g;
	cube[n][3][1] = a;
	cube[n][3][2] = d;
	cube[n][3][3] = f;
}



int main(int argc, const char* argv[]) {
	fastio;
	
	//1-top 2-bottom 3-front 4-back 5-left 6-right
	
	int t, n;
	string s;
	cin >> t;
	for (int x = 0; x < t; x++) {
		for (int i = 1; i <= 3; i++) {
			for (int k = 1; k <= 3; k++) {
				cube[1][i][k] = 'w';
			}
		}
		for (int i = 1; i <= 3; i++) {
			for (int k = 1; k <= 3; k++) {
				cube[2][i][k] = 'y';
			}
		}
		for (int i = 1; i <= 3; i++) {
			for (int k = 1; k <= 3; k++) {
				cube[3][i][k] = 'r';
			}
		}
		for (int i = 1; i <= 3; i++) {
			for (int k = 1; k <= 3; k++) {
				cube[4][i][k] = 'o';
			}
		}
		for (int i = 1; i <= 3; i++) {
			for (int k = 1; k <= 3; k++) {
				cube[5][i][k] = 'g';
			}
		}
		for (int i = 1; i <= 3; i++) {
			for (int k = 1; k <= 3; k++) {
				cube[6][i][k] = 'b';
			}
		}
		cin >> n;
		for (int y = 0; y < n; y++) {
			cin >> s;
			if (s == "U+") {
				clock(1);
				a = cube[3][1][1];
				b = cube[3][1][2];
				c = cube[3][1][3];
				d = cube[6][1][1];
				e = cube[6][1][2];
				f = cube[6][1][3];
				g = cube[4][1][1];
				h = cube[4][1][2];
				i = cube[4][1][3];
				j = cube[5][1][1];
				k = cube[5][1][2];
				l = cube[5][1][3];
				cube[3][1][1] = d;
				cube[3][1][2] = e;
				cube[3][1][3] = f;
				cube[6][1][1] = g;
				cube[6][1][2] = h;
				cube[6][1][3] = i;
				cube[4][1][1] = j;
				cube[4][1][2] = k;
				cube[4][1][3] = l;
				cube[5][1][1] = a;
				cube[5][1][2] = b;
				cube[5][1][3] = c;
			}
			else if (s == "U-") {
				aclock(1);
				a = cube[3][1][1];
				b = cube[3][1][2];
				c = cube[3][1][3];
				d = cube[6][1][1];
				e = cube[6][1][2];
				f = cube[6][1][3];
				g = cube[4][1][1];
				h = cube[4][1][2];
				i = cube[4][1][3];
				j = cube[5][1][1];
				k = cube[5][1][2];
				l = cube[5][1][3];
				cube[3][1][1] = j;
				cube[3][1][2] = k;
				cube[3][1][3] = l;
				cube[6][1][1] = a;
				cube[6][1][2] = b;
				cube[6][1][3] = c;
				cube[4][1][1] = d;
				cube[4][1][2] = e;
				cube[4][1][3] = f;
				cube[5][1][1] = g;
				cube[5][1][2] = h;
				cube[5][1][3] = i;
			}
			else if (s == "D+") {
				clock(2);
				a = cube[3][3][1];
				b = cube[3][3][2];
				c = cube[3][3][3];
				d = cube[6][3][1];
				e = cube[6][3][2];
				f = cube[6][3][3];
				g = cube[4][3][1];
				h = cube[4][3][2];
				i = cube[4][3][3];
				j = cube[5][3][1];
				k = cube[5][3][2];
				l = cube[5][3][3];
				cube[3][3][1] = j;
				cube[3][3][2] = k;
				cube[3][3][3] = l;
				cube[6][3][1] = a;
				cube[6][3][2] = b;
				cube[6][3][3] = c;
				cube[4][3][1] = d;
				cube[4][3][2] = e;
				cube[4][3][3] = f;
				cube[5][3][1] = g;
				cube[5][3][2] = h;
				cube[5][3][3] = i;
			}
			else if (s == "D-") {
				aclock(2);
				a = cube[3][3][1];
				b = cube[3][3][2];
				c = cube[3][3][3];
				d = cube[6][3][1];
				e = cube[6][3][2];
				f = cube[6][3][3];
				g = cube[4][3][1];
				h = cube[4][3][2];
				i = cube[4][3][3];
				j = cube[5][3][1];
				k = cube[5][3][2];
				l = cube[5][3][3];
				cube[3][3][1] = d;
				cube[3][3][2] = e;
				cube[3][3][3] = f;
				cube[6][3][1] = g;
				cube[6][3][2] = h;
				cube[6][3][3] = i;
				cube[4][3][1] = j;
				cube[4][3][2] = k;
				cube[4][3][3] = l;
				cube[5][3][1] = a;
				cube[5][3][2] = b;
				cube[5][3][3] = c;
			}
			else if (s == "F+") {
				clock(3);
				a = cube[1][3][1];
				b = cube[1][3][2];
				c = cube[1][3][3];
				d = cube[6][1][1];
				e = cube[6][2][1];
				f = cube[6][3][1];
				g = cube[2][3][1];
				h = cube[2][3][2];
				i = cube[2][3][3];
				j = cube[5][1][3];
				k = cube[5][2][3];
				l = cube[5][3][3];
				cube[1][3][1] = l;
				cube[1][3][2] = k;
				cube[1][3][3] = j;
				cube[6][1][1] = a;
				cube[6][2][1] = b;
				cube[6][3][1] = c;
				cube[2][3][1] = d;
				cube[2][3][2] = e;
				cube[2][3][3] = f;
				cube[5][1][3] = i;
				cube[5][2][3] = h;
				cube[5][3][3] = g;
			}
			else if (s == "F-") {
				aclock(3);
				a = cube[1][3][1];
				b = cube[1][3][2];
				c = cube[1][3][3];
				d = cube[6][1][1];
				e = cube[6][2][1];
				f = cube[6][3][1];
				g = cube[2][3][1];
				h = cube[2][3][2];
				i = cube[2][3][3];
				j = cube[5][1][3];
				k = cube[5][2][3];
				l = cube[5][3][3];
				cube[1][3][1] = d;
				cube[1][3][2] = e;
				cube[1][3][3] = f;
				cube[6][1][1] = g;
				cube[6][2][1] = h;
				cube[6][3][1] = i;
				cube[2][3][1] = l;
				cube[2][3][2] = k;
				cube[2][3][3] = j;
				cube[5][1][3] = c;
				cube[5][2][3] = b;
				cube[5][3][3] = a;
			}
			else if (s == "B+") {
				clock(4);
				a = cube[1][1][1];
				b = cube[1][1][2];
				c = cube[1][1][3];
				d = cube[6][1][3];
				e = cube[6][2][3];
				f = cube[6][3][3];
				g = cube[2][1][1];
				h = cube[2][1][2];
				i = cube[2][1][3];
				j = cube[5][1][1];
				k = cube[5][2][1];
				l = cube[5][3][1];
				cube[1][1][1] = d;
				cube[1][1][2] = e;
				cube[1][1][3] = f;
				cube[6][1][3] = g;
				cube[6][2][3] = h;
				cube[6][3][3] = i;
				cube[2][1][1] = l;
				cube[2][1][2] = k;
				cube[2][1][3] = j;
				cube[5][1][1] = c;
				cube[5][2][1] = b;
				cube[5][3][1] = a;
			}
			else if (s == "B-") {
				aclock(4);
				a = cube[1][1][1];
				b = cube[1][1][2];
				c = cube[1][1][3];
				d = cube[6][1][3];
				e = cube[6][2][3];
				f = cube[6][3][3];
				g = cube[2][1][1];
				h = cube[2][1][2];
				i = cube[2][1][3];
				j = cube[5][1][1];
				k = cube[5][2][1];
				l = cube[5][3][1];
				cube[1][1][1] = l;
				cube[1][1][2] = k;
				cube[1][1][3] = j;
				cube[6][1][3] = a;
				cube[6][2][3] = b;
				cube[6][3][3] = c;
				cube[2][1][1] = d;
				cube[2][1][2] = e;
				cube[2][1][3] = f;
				cube[5][1][1] = i;
				cube[5][2][1] = h;
				cube[5][3][1] = g;
			}
			else if (s == "L+") {
				clock(5);
				a = cube[1][1][1];
				b = cube[1][2][1];
				c = cube[1][3][1];
				d = cube[3][1][1];
				e = cube[3][2][1];
				f = cube[3][3][1];
				g = cube[2][1][3];
				h = cube[2][2][3];
				i = cube[2][3][3];
				j = cube[4][1][3];
				k = cube[4][2][3];
				l = cube[4][3][3];
				cube[1][1][1] = l;
				cube[1][2][1] = k;
				cube[1][3][1] = j;
				cube[3][1][1] = a;
				cube[3][2][1] = b;
				cube[3][3][1] = c;
				cube[2][1][3] = f;
				cube[2][2][3] = e;
				cube[2][3][3] = d;
				cube[4][1][3] = g;
				cube[4][2][3] = h;
				cube[4][3][3] = i;
			}
			else if (s == "L-") {
				aclock(5);
				a = cube[1][1][1];
				b = cube[1][2][1];
				c = cube[1][3][1];
				d = cube[3][1][1];
				e = cube[3][2][1];
				f = cube[3][3][1];
				g = cube[2][1][3];
				h = cube[2][2][3];
				i = cube[2][3][3];
				j = cube[4][1][3];
				k = cube[4][2][3];
				l = cube[4][3][3];
				cube[1][1][1] = d;
				cube[1][2][1] = e;
				cube[1][3][1] = f;
				cube[3][1][1] = i;
				cube[3][2][1] = h;
				cube[3][3][1] = g;
				cube[2][1][3] = j;
				cube[2][2][3] = k;
				cube[2][3][3] = l;
				cube[4][1][3] = c;
				cube[4][2][3] = b;
				cube[4][3][3] = a;
			}
			else if (s == "R+") {
				clock(6);
				a = cube[1][1][3];
				b = cube[1][2][3];
				c = cube[1][3][3];
				d = cube[3][1][3];
				e = cube[3][2][3];
				f = cube[3][3][3];
				g = cube[2][1][1];
				h = cube[2][2][1];
				i = cube[2][3][1];
				j = cube[4][1][1];
				k = cube[4][2][1];
				l = cube[4][3][1];
				cube[1][1][3] = d;
				cube[1][2][3] = e;
				cube[1][3][3] = f;
				cube[3][1][3] = i;
				cube[3][2][3] = h;
				cube[3][3][3] = g;
				cube[2][1][1] = j;
				cube[2][2][1] = k;
				cube[2][3][1] = l;
				cube[4][1][1] = c;
				cube[4][2][1] = b;
				cube[4][3][1] = a;
			}
			else if (s == "R-") {
				aclock(6);
				a = cube[1][1][3];
				b = cube[1][2][3];
				c = cube[1][3][3];
				d = cube[3][1][3];
				e = cube[3][2][3];
				f = cube[3][3][3];
				g = cube[2][1][1];
				h = cube[2][2][1];
				i = cube[2][3][1];
				j = cube[4][1][1];
				k = cube[4][2][1];
				l = cube[4][3][1];
				cube[1][1][3] = l;
				cube[1][2][3] = k;
				cube[1][3][3] = j;
				cube[3][1][3] = a;
				cube[3][2][3] = b;
				cube[3][3][3] = c;
				cube[2][1][1] = f;
				cube[2][2][1] = e;
				cube[2][3][1] = d;
				cube[4][1][1] = g;
				cube[4][2][1] = h;
				cube[4][3][1] = i;
			}
		}
		for (int q = 1; q <= 3; q++) {
			for (int w = 1; w <= 3; w++) {
				cout << cube[1][q][w];
			}
			cout << endl;
		}
		
	}
}