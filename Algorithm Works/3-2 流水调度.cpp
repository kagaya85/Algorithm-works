/*
1)��ִ��t[i,1]<t[i,2],��֤M2��û�еȴ���ѡ���һ����ҵʱ����M2ѡ���һ�εȴ�ʱ�����ٵ�,
��t[i,1]ԽС��Խ��ǰִ��;
2)ִ��t[i,1]>=t[i,2]ʱ��Ҫ��֤���һ����ҵ��M2��ִ��ʱ����̣����԰��ռ�������
*/
#include<iostream>
#include<string.h>
#include<algorithm> 
#define N 100
using namespace std;

struct node {
	int time;//ִ��ʱ�� 
	int index;//��ҵ���
	bool group;//1�����һ��������0����ڶ������� 
};

bool cmp(node a, node b)
{//�������� 
	return a.time<b.time;
}
int main()
{
	int i, j, k, n;
	int a[N] = { 0 }, b[N] = { 0 };
	int best[N];//���ŵ������� 
	node c[N];
	cin >> n;
	for (i = 0; i<n; i++) {
		cin >> a[i] >> b[i];
	}
	for (i = 0; i<n; i++) {  //n����ҵ�У�ÿ����ҵ����С�ӹ�ʱ�� 
		c[i].time = a[i]>b[i] ? b[i] : a[i];
		c[i].index = i;
		c[i].group = a[i] <= b[i];

	}
	sort(c, c + n, cmp);//����c[]����ҵʱ����������
	j = 0, k = n - 1;
	for (i = 0; i<n; i++) {
		if (c[i].group) { //��һ�飬��i=0��ʼ���뵽best[]�� 
			best[j++] = c[i].index;
		}
		else {
			best[k--] = c[i].index;
		}
	}
	j = a[best[0]];//���ŵ��������µ�������ʱ�� 
	k = j + b[best[0]];
	for (i = 1; i<n; i++) {
		j += a[best[i]];
		k = j<k ? (k + b[best[i]]) : j + b[best[i]];//������ʱ������ֵ 
	}
	cout << "��Ҫ����ʱ��Ϊ��" << k << endl;
	cout << "�������Ϊ��";
	for (i = 0; i<n; i++) {
		cout << best[i] + 1 << ' ';
	}
	cout << endl;
	return 0;
}