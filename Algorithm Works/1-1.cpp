#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int n, num, temp, res[10] = 0, high, low, div;
	//ifstream fin;

	cin >> num;

	//统计位数
	temp = num;
	for (n = 0; temp; n++) {
		temp %= 10;
	}

	//按位统计
	for (int i = 0; i < n; i++) {
		//统计0~9的个数
		div = 1;
		for(int m = 0; m < i; m++){
			div *= 10;
		}

		for (int j = 0; j < 10; j++) {
			//取出该位
			temp = num % (div * 10);
			temp /= div;
			high = num / (div * 10);
			low = num % div;
			if(j > temp) {
				res[j] += high * div;
			}
			else if(j == temp){
				res[j] += high * div + low + 1;
			}
			else {
				res[j] += (high + 1) * div
			}
		}
	}
	
	for(int i = 0; i < 10; i++)
		cout << res[i] << endl;

	return 0;
}
