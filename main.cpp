//============================================================================
// Name        : ayman.cpp
// Author      : Ayman Mostafa
// Email       : ayman93live@hotmail.com
// Version     : v5.0
//============================================================================
// K-means clustering algorithm (data mining)
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <functional>
#include <numeric>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define clr(v,d) memset(v,d,sizeof(v));

float rand_FloatRange(float a, float b) {
	return ((b - a) * ((float) rand() / RAND_MAX)) + a;
}
//##########################################################################################
//###################################MAIN FUNCTION##########################################
//##########################################################################################
int main() {
	int i, j, n;
	cout << "Enter the value of (i)\n"; // width of u and X
	cin >> i;
	cout << "Enter the value of (j)\n"; // number of u
	cin >> j;
	cout << "Enter number of data\n";
	cin >> n;
	vector<vector<float>> u(j);
	vector<vector<float>> x(n);
	for (int r = 0; r < j; r++)
		for (int c = 0; c < i; c++) {
			u[r].push_back(rand_FloatRange(-1000, 1000));
		}
	cout << "Enter the data\n";
	for (int r = 0; r < n; r++)
		for (int c = 0; c < i; c++) {
			float tt;
			cin >> tt;
			x[r].push_back(tt);
		}
	vector<vector<float>> newu(j);
	for (int numberOfIteration = 0; numberOfIteration < 1000;
			numberOfIteration++) {
		newu.clear();
		for (int r = 0; r < j; r++)
			for (int c = 0; c < i; c++)
				newu[r].push_back(0);
		vector<int> no(j);
		fill(all(no), 0);
		vector<pair<float, int>> mn;
		for (int r = 0; r < n; r++) {
			mn.clear();
			for (int c = 0; c < j; c++) {
				float res = 0;
				for (int k = 0; k < i; k++) {
					res += (x[r][k] - u[c][k]) * (x[r][k] - u[c][k]);
				}
				res = sqrt(res);
				mn.push_back( { res, c });
			}
			sort(all(mn));
			no[mn[0].second]++;
			for (int k = 0; k < i; k++) {
				newu[mn[0].second][k] += x[r][k];
			}
		}
		for (int r = 0; r < j; r++)
			for (int c = 0; c < i; c++)
				newu[r][c] /= no[r];
	}
	for (int r = 0; r < j; r++) {
		cout << "Values of u" << r + 1 << endl;
		for (int c = 0; c < i; c++)
			cout << newu[r][c] << " ";
		cout << endl;
	}
}
