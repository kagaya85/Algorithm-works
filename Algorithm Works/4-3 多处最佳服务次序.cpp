#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

struct Guest {
	int no;
	int time;
	
	Guest()
	{  // ���캯��
		no = 0;
		time = 0;
	}
};

bool cmp(Guest a, Guest b)
{
	return a.time < b.time;
}

//  ������������Сֵ�����
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

	cout << "��Ѵ���:" << endl;
	for (int i = 0; i < s; i++) {
		cout << i << " : ";
		for (int j = 0; j < spIndex[i]; j++) {
			cout << sp[i][j].no + 1 << ':' << sp[i][j].time << "  ";
		}
		cout << "���еȴ�ʱ��:" << subsum[i] << endl;
	}

	for (int i = 0; i < s; i++) {
		sum += tmp[i];
	}

	cout << endl << "ƽ���ȴ�ʱ��:" <<  sum/n << endl;

	for (int i = 0; i < s; i++) {
		delete sp[i];
	}
	
	delete st;
	delete[] sp;
	delete subsum;
	delete spIndex;
	return 0;
}