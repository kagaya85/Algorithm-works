#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int n, num, temp, res[10] = { 0 }, high, low, div;
	
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	//cin >> num;
	fin >> num;
	//统计位数
	temp = num;
	for (n = 0; temp; n++) {
		temp /= 10;
	}

	//按位统计
	for (int i = 0; i < n; i++) {
		
		div = 1;
		for(int m = 0; m < i; m++){
			div *= 10;
		}

		temp = num % (div * 10);
		temp /= div;
		high = num / (div * 10);
		low = num % div;
		//统计0~9的个数
		for (int j = 0; j < 10; j++) {
			//取出该位
			if(j > temp) {
				res[j] += high * div;
			}
			else if(j == temp){
				res[j] += high * div + low + 1;
			}
			else {
				if(div == 1 || j != 0)
					res[j] += (high + 1) * div;
			}
		}
	}
	
	res[0] -= 1;	//自然数以1开头
	for(int i = 0; i < 10; i++)
		fout << res[i] << endl;

	return 0;
}
