#include<iostream>

using namespace std;

int main()
{
	char a[100] = { 0 };
	int n, len;
	char tmp;
	cout << "please input a: ";
	cin >> a;
	cout << "please input n: ";
	cin >> n;

	len = (int)strlen(a);

	for (int i = 0; i < n; i++) {
		tmp = a[0];
		for (int j = 1; j < len; j++) {
			if (a[j] < tmp) {
				// delete a[j-1] ���ֵݼ����� ɾ����һ��
				for (int q = j; q < len; q++) {
					// move ��ǰ�ƶ�����Ԫ��
					a[q - 1] = a[q];
				}
				break;
			}
			else {
				tmp = a[j];
			}
		}
		a[--len] = 0; // ��󲹳�β0��ͬʱҲ�൱��ɾ�����һ��
	}


	cout << "the minimum is: " <<a << endl;

	return 0;
}
