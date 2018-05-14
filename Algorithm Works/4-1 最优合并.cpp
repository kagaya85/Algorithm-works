#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int minMerge(const int *num, const int n)
{
	int *sub, sum = 0, m = n; // m表示剩余的数字

	sub = new(nothrow) int[n];

	for (int i = 0; i < n; i++) {
		sub[i] = num[i];
	}

	while (m > 1) {
		sort(sub, sub + m);
		sub[0] = sub[0] + sub[1];
		sum += sub[0] - 1;
		for (int j = 1; j < m-1; j++) {
			sub[j] = sub[j + 1];
		}
		m--;
	}

	delete sub;
	return sum;
}

int maxMerge(const int *num, const int n)
{
	int *sub, sum = 0, m = n; // m表示剩余的数字

	sub = new(nothrow) int[n];

	for (int i = 0; i < n; i++) {
		sub[i] = num[i];
	}

	while (m > 1) {
		sort(sub, sub + m, cmp);
		sub[0] = sub[0] + sub[1];
		sum += sub[0] - 1;
		for (int j = 1; j < m - 1; j++) {
			sub[j] = sub[j + 1];
		}
		m--;
	}

	delete sub;
	return sum;
}

int main()
{
	int *num, n;
	ifstream fin("input.txt");

	fin >> n;

	num = new(nothrow) int[n];
	
	if (num == NULL) {
		cerr << "new error!" << endl;
		exit(-1);
	}

	for (int i = 0; i < n; i++) {
		fin >> num[i];
	}

	cout << "最大：" << maxMerge(num, n) << endl;
	cout << "最小：" << minMerge(num, n) << endl;

	delete num;
	return 0;
}
