#include<iostream>
#include<fstream>

using namespace std;

class MaxGapQA {
private:
	int nCount;
	double maxGap = 0;
	double *data;
public:
	MaxGapQA(const char *filename);
	~MaxGapQA();
	double getMaxGap();
	void show(const char *filename);
	int indexOfMax();
	int indexOfMin();
};

MaxGapQA::MaxGapQA(const char *filename)
{
	ifstream fin(filename);
	
	fin >> nCount;

	data = new(nothrow) double[nCount];
	if (data == NULL) {
		cerr << "new error!" << endl;
		exit(-1);
	}

	for (int i = 0; i < nCount; i++) {
		fin >> data[i];
	}

	fin.close();
}

MaxGapQA::~MaxGapQA()
{
	delete[] data;
}

double MaxGapQA::getMaxGap()
{
	int maxIndex, minIndex;
	double max, min, avrGap, tmpGap, tmpHigh;
	int index, *count;		//�ֿ�����
	double *low, *high;		//������½����Ͻ�

	maxIndex = indexOfMax();
	minIndex = indexOfMin();

	max = data[maxIndex];
	min = data[minIndex];

	avrGap = (max - min) / nCount;
	count = new(nothrow) int[nCount - 1];
	low = new(nothrow) double[nCount - 1];
	high = new(nothrow) double[nCount - 1];
	if (!count || !low || !high) {
		cerr << "new error!" << endl;
		exit(-1);
	}

	//��ʼ������,����Ԫ��ǰ������ϱ߽�Ϊ����,�±߽�Ϊ��Сֵ
	low[0] = min;
	high[nCount - 2] = max;
	for (int i = 0; i < nCount - 2; i++) {
		low[i] = max;
		high[i] = min;
		count[i] = 0;
	}

	//��������ֺõ�����
	for (int i = 0; i < nCount; i++) {
		index = int(data[i] / avrGap);
		//����ҿ� �������max�����
		if (index == nCount - 1)
			index -= 1;

		count[index]++;

		//��������Ĵ�С
		if (data[i] < low[index])
			low[index] = data[i];
		if (data[i] > high[index])
			high[index] = data[i];
	}

	tmpHigh = high[0];
	for (int i = 1; i < nCount - 1; i++) {
		if (count[i]) {
			tmpGap = low[i] - tmpHigh;
			if (maxGap < tmpGap)
				maxGap = tmpGap;
			tmpHigh = high[i];
		}
	}

	delete[] count;
	delete[] high;
	delete[] low;

	return maxGap;
}

void MaxGapQA::show(const char *filename)
{
	ofstream fout(filename);

	fout << maxGap;

	fout.close();
}

int MaxGapQA::indexOfMax()
{
	int max = 0;
	
	for (int i = 0; i < nCount; i++) {
		if (data[i] > data[max])
			max = i;
	}
	return max;
}

int MaxGapQA::indexOfMin()
{
	int min = 0;

	for (int i = 0; i < nCount; i++) {
		if (data[i] < data[min])
			min = i;
	}
	return min;
}

int main()
{
	MaxGapQA Q("input.txt");

	Q.getMaxGap();
	
	Q.show("output.txt");

	return 0;
}
