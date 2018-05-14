#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int  n, k, remain, fillNum = 0;
	int dist;
	ifstream fin("input.txt");

	fin >> n >> k;
	remain = n;
	for (int i = 0; i < k + 1; i++) {
		fin >> dist;
		if (n < dist) {
			cout << "No result" << endl;
			return 0;
		}
		else if (remain < dist) {
			fillNum++;
			remain = n;
		}
		remain -= dist;
	}

	cout << "总加油次数" <<fillNum << endl;

	return 0;
}