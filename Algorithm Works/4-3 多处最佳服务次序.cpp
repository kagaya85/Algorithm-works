#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

struct Guest {
	int no;
	int time;
	
	Guest()
	{  // 构造函数
		no = 0;
		time = 0;
	}
};

bool cmp(Guest a, Guest b)
{
	return a.time < b.time;
}

//  返回数组中最小值的序号
int minIndex(int *subsum, int s)
{
	int minIndex = 0;
	for (int i = 1; i < s; i++) {
		if (subsum[i] < subsum[minIndex]) {
			minIndex = i;
		}
	}

	return minIndex;
}

int main()
{
	int n, s, sum = 0;
	int *subsum, *spIndex, *tmp;
	Guest *st, **sp;
	ifstream fin("input.txt");

	fin >> n >> s;

	st = new(nothrow) Guest[n];
	sp = new(nothrow) Guest*[s];
	subsum = new(nothrow) int[s] {0};
	tmp = new(nothrow) int[s] {0};
	spIndex = new(nothrow) int[s] {0};
	for (int i = 0; i < s; i++) {
		sp[i] = new(nothrow) Guest[n];
	}

	for (int i = 0; i < n; i++) {
		st[i].no = i;
		fin >> st[i].time;
	}

	sort(st, st + n, cmp);

	for (int i = 0; i < n; i++) {
		int mi;
		mi = minIndex(subsum, s);
		sp[mi][spIndex[mi]++] = st[i];
		subsum[mi] += st[i].time;
		tmp[mi] += subsum[mi];
	}

	cout << "最佳次序:" << endl;
	for (int i = 0; i < s; i++) {
		cout << i << " : ";
		for (int j = 0; j < spIndex[i]; j++) {
			cout << sp[i][j].no + 1 << ':' << sp[i][j].time << "  ";
		}
		cout << "队列等待时间:" << subsum[i] << endl;
	}

	for (int i = 0; i < s; i++) {
		sum += tmp[i];
	}

	cout << endl << "平均等待时间:" <<  sum/n << endl;

	for (int i = 0; i < s; i++) {
		delete sp[i];
	}
	
	delete st;
	delete[] sp;
	delete subsum;
	delete spIndex;
	return 0;
}