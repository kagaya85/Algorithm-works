#include<iostream>
#include<fstream>
#include<stack>

using namespace std;

struct Node{
	int value;
	Node *prior;	//指向该递增子列中的前一个
	int len;
};

int main()
{
	ifstream fin("input.txt");
	int n, maxlen = 1, last;
	Node *num, *p;
	stack<int> S;

	fin >> n;

	num = new(nothrow) Node[n];
	if (num == NULL) {
		cerr << "new error!!!" << endl;
		exit(-1);
	}

	for (int i = 0; i < n; i++) {
		fin >> num[i].value;
		num[i].prior = NULL;
		num[i].len = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (num[i].value > num[j].value && num[i].len <= num[j].len) {
				num[i].len = num[j].len + 1;
				num[i].prior = &num[j];
				if (maxlen < num[i].len) {
					maxlen = num[i].len;
					last = i;
				}
			}
		}
	}

	p = &num[last];

	cout << "the max len is " << maxlen << endl;
	while (p)
	{
		S.push(p->value);
		p = p->prior;
	}

	for (int i = 0; i < maxlen; i++) {
		cout << S.top() << ' ';
		S.pop();
	}

	delete num;
	fin.close();
}