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
				// delete a[j-1] 发现递减序列 删除第一项
				for (int q = j; q < len; q++) {
					// move 向前移动后面元素
					a[q - 1] = a[q];
				}
				break;
			}
			else {
				tmp = a[j];
			}
		}
		a[--len] = 0; // 最后补充尾0，同时也相当于删除最后一项
	}


	cout << "the minimum is: " <<a << endl;

	return 0;
}
