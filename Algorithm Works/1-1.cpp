#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int n, num, temp, res[10];
	//ifstream fin;

	cin >> num;

	//统计位数
	temp = num;
	for (n = 0; temp; n++) {
		temp %= 10;
	}

	//按位统计
	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < 10; j++) {

		}
	}

	return 0;
}
