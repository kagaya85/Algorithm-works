#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

struct Guest {
	int no;
	int time;
};

bool cmp(Guest a, Guest b)
{
	return a.time < b.time;
}

int main()
{
	int n, sum = 0, tmp = 0;
	Guest *st;
	ifstream fin("input.txt");

	fin >> n;

	st = new(nothrow) Guest[n];
	
	for (int i = 0; i < n; i++) {
		st[i].no = i;
		fin >> st[i].time;
	}

	sort(st, st + n, cmp);

	cout << "��Ѵ���:";
	for (int i = 0; i < n; i++) {
		cout << st[i].no + 1<< ' ';
		tmp += st[i].time;
		sum += tmp;
	}
	cout << endl << "ƽ���ȴ�ʱ��:" << sum / n << endl;

	delete st;
	return 0;
}