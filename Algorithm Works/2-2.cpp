#include<iostream>
#include<cstdlib>
#include<time.h>
#include<fstream>

using namespace std;

template<class T>
int Partition(T *data, int left, int right)
{
	int i = left, j = right + 1;
	T x = data[left];	//参照

	while (true) {
		while (data[++i] < x && i < right)
			;
		while (data[--j] >= x && j > left) //等于x的都在x的右侧
			;
		if (i >= j)
			break;
		swap(data[i], data[j]);
	}

	data[left] = data[j];
	data[j] = x;

	return j;
}

template<class T>
int Partition(T *data, int left, int right, T x)
{
	int i = left, j = right + 1;
	int m = left;
	while (data[m] != x && m <= right)
		m++;
	swap(data[left], data[m]);

	while (true) {
		while (data[++i] < x && i < right)
			;
		while (data[--j] >= x && j > left) //等于x的都在x的右侧
			;
		if (i >= j)
			break;
		swap(data[i], data[j]);
	}

	data[left] = data[j];
	data[j] = x;

	return j;
}

template<class T>
int RandomizedPartion(T *data, int left, int right)
{
	int i;
	
	srand(time(0));

	i = rand() % (right - left + 1) + left;

	swap(data[left], data[i]);

	return Partition(data, left, right);

}

template<class T>
void QuickSort(T *data, int left, int right)
{
	int p;
	if (right <= left)
		return;

	p = Partition(data, left, right);
	QuickSort(data, left, p);
	QuickSort(data, p + 1, right);
}

template<class T>
T RandomizedSelect(T *data, int left, int right, int k)
{
	int i, len, m = 0;	//m is the counter of same number
	if (left == right)
		return data[left];
	
	i = RandomizedPartion(data, left, right);
	len = i - left + 1;

	//把相同的元素放在一起
	for (int n = i + 1, r = right; n < r; r--) {
		if (data[r] == data[i]) {
			swap(data[n], data[r]);
			n++;
			m++;
		}
	}

	if (left + k <= i)
		return RandomizedSelect(data, left, i, k);
	else if (left + k <= i + m)	//处理相同的数
		return data[i];
	else
		return RandomizedSelect(data, i + m + 1, right, k - len - m - 1);

}

//最坏情况O(n)的选择算法
template<class T>
T Select(T *data, int left, int right, int k)
{
	T x, groupNum = (right - left - 4) / 5;
	int len, m = 0;
	int i;	//划分参照序号 
	if (right - left < 75) {
		//排序返回中位数
		QuickSort(data, left, right);
		return data[left + k];
	}

	for (int n = 0; n <= groupNum; n++) {
		//分组排序，将所有组的中位数放到最前面
		QuickSort(data, left + 5 * n, left + 5 * n + 4);
		swap(data[left + n], data[left + 5 * n + 2]);
	}

	//选择划分参照
	x = Select(data, left, left + groupNum, groupNum / 2);
	i = Partition(data, left, right, x);
	len = i - left + 1;

	//把相同的元素放在一起
	for (int n = i + 1, r = right; n < r; r--) {
		if (data[r] == data[i]) {
			swap(data[n], data[r]);
			n++;
			m++;//计数
		}
	}

	if (left + k <= i)
		return Select(data, left, i, k);
	else if (left + k <= i + m)	//处理相同的数，直接返回
		return data[i];
	else
		return Select(data, i + m + 1, right, k - len - m);

}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int num, k, *data;
	fin >> num >> k;

	data = new(nothrow) int[num];
	if (data == NULL) {
		cerr << "new error!!!";
		exit(-1);
	}

	for (int i = 0; i < num; i++)
		fin >> data[i];

	fout << Select(data, 0, num - 1, k - 1) << endl;

	fin.close();
	fout.close();
	delete[] data;

	return 0;
}