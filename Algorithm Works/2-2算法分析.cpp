#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");

	int x, score = 0, n, *data, num = 0;

	fin >> n;

	data = new(nothrow) int(n);
	if (data == NULL) {
		cerr << "new error!!!" << endl;
		exit(-1);
	}

	for (int i = 0; i < n; i++) {
		fin >> data[i];
		if (score == 0) {
			x = data[i];
			score++;
		}
		else if (x == data[i])
			score++;
		else
			score--;
	}

	if (score <= 0) {
		cout << "无主元素" << endl;
		delete[] data;
		return 0;
	}

	for (int i = 0; i < n; i++)
		if (data[i] == x)
			num++;

	if (num > n / 2)
		cout << "主元素为" << x << endl;
	else
		cout << "无主元素" << endl;

	delete[] data;

	return 0;
}
