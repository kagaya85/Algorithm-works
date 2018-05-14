#include<iostream>
#include<fstream>

#define MAXNUM 2*100+1

using namespace std;

inline int max(int x, int y) { return x > y ? x : y; }
inline int min(int x, int y) { 
	if (y <= 0)
		return x;
	else
		return x < y ? x : y; 
}

void dp(int (*fmax)[MAXNUM], int (*fmin)[MAXNUM], int n, int *sum)
{
	// 初始化
	for (int i = 0; i < 2 * n - 1; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			fmax[i][j] = 0;
			fmin[i][j] = 0;
		}
	}

	// d为间隔距离
	for (int d = 1; d <= n - 1; d++) {
		for (int i = 0; i < n; i++) {
			int j = i + d;

			fmax[i][j] = fmax[i + 1][j] + sum[j + 1] - sum[i];
			fmin[i][j] = fmin[i + 1][j] + sum[j + 1] - sum[i];
			for (int k = i + 1; k < j; k++) {
				fmax[i][j] = max(fmax[i][j], fmax[i][k] + fmax[k + 1][j] + sum[j + 1] - sum[i]);
				fmin[i][j] = min(fmin[i][j], fmin[i][k] + fmin[k + 1][j] + sum[j + 1] - sum[i]);
			}
			if (i < n - 1) {
				fmax[i + n][j + n] = fmax[i][j];
				fmin[i + n][j + n] = fmin[i][j];
			}
		}
	}
}

void get_res(int(*fmax)[MAXNUM], int(*fmin)[MAXNUM], int &maxres, int &minres, int n)
{
	maxres = fmax[0][0 + n - 1];
	minres = fmin[0][0 + n - 1];
	for (int i = 1; i < n; i++) {
		maxres = max(maxres, fmax[i][i + n - 1]);
		minres = min(minres, fmin[i][i + n - 1]);
	}
}

int main()
{
	int fmax[MAXNUM][MAXNUM], fmin[MAXNUM][MAXNUM], sum[MAXNUM], n, maxres, minres;
	ifstream fin("input.txt");

	fin >> n;

	sum[0] = 0;	
	for (int i = 1; i <= n; i++) {
		fin >> sum[i];
		if(i != n - 1)
			sum[i + n] = sum[i];
	}

	for (int i = 1; i <= 2 * n - 1 - 1; i++) {
		sum[i + 1] += sum[i];
	}
	
	dp(fmax, fmin, n, sum);
	get_res(fmax, fmin, maxres, minres, n);

	cout << minres << endl;
	cout << maxres << endl;

	return 0;
}