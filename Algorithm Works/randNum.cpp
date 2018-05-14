#include<iostream>
#include<fstream> 
#include<cstdlib>
#include<time.h>
#include<iomanip>

using namespace std;

//do not include high
int myRand(int low, int high)
{
	return low + rand() % (high - low);
}

int *shuffle(int *data, int n)
{
	int rand, temp;
	
	for (int i = 0; i < n - 1; i++) {
		rand = myRand(i, n);
		temp = data[rand];
		data[rand] = data[i];
		data[i] = temp;
	}
	
	return data;
}

int main()
{
	ofstream fout("input.txt");
	const int n = 5000;
	int data[n], k;

	srand(int(time(0)));

	cout << "请输入需查找第几" << "(1-" << n << ")个数:";
	cin >> k;

	fout << n << ' ' << k << endl;

	for (int i = 0; i < n; i++)
		data[i] = i + 1;	// 1~5000

	shuffle(data, n);

	for (int i = 0; i < n; i++) {
		fout << setw(4) << data[i] << ' ';
		if ((i + 1) % 10 == 0)
			fout << endl;
	}

	fout.close();
	return 0;
}