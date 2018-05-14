#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ofstream fout("MULT.txt");

	////初始化
	//for (int i = 0; i < 32; i++) {
	//	fout << "store" << i << " <= 0;" << endl;
	//}

	////一级初始化
	//for (int i = 0; i < 16; i++) {
	//	fout << "add" << i << '_' << i + 16 << " <= 0;" << endl;
	//}

	////二级初始化
	//for (int i = 0; i < 8; i++) {
	//	fout << "add" << i << "__" << i + 8 << " <= 0;" << endl;
	//}

	////三级初始化
	//for (int i = 0; i < 4; i++) {
	//	fout << "add" << i << "___" << i + 4 << " <= 0;" << endl;
	//}

	//暂存寄存器 32
	for (int i = 0; i < 32; i++) {
		fout << "reg [63:0] store" << i << ';' << endl;
	}

	//一寄存器 16
	for (int i = 0; i < 16; i++) {
		fout << "reg [63:0] add" << i << '_' << i + 16 << ';' << endl;
	}

	//二级寄存器 8
	for (int i = 0; i < 8; i++) {
		fout << "reg [63:0] add" << i << "__" << i + 8 << ';' << endl;
	}

	//三级寄存器 4
	for (int i = 0; i < 4; i++) {
		fout << "reg [63:0] add" << i << "___" << i + 4 << ';' << endl;
	}

	//移位赋值
	for (int i = 0; i < 32; i++) {
		if(i < 31)
			fout << "store" << i << " <= (b[" << i << "] == 1) ? {{"
				<< 32 - i <<"{a[31]}},{" << "a" << "},"<< i << "'b0} : 64'b0;" << endl;
		else    // i == 31 处理符号位
			fout << "store" << i << " <= {"
				<< "a[31],{" << "a" << "}," << i << "'b0};" << endl;
	}

	//一级加
	for (int i = 0; i < 16; i++) {
		fout << "add" << i << '_' << i + 16 << " <= store" << i << " + store" << i + 16 << ';' << endl;
	}

	//二级加
	for (int i = 0; i < 8; i++) {
		fout << "add" << i << "__" << i + 8 << " <= add" << i << '_' << i + 16 << " + add" << i + 8 << '_' << i + 24 << ';' << endl;
	}

	//三级加
	for (int i = 0; i < 4; i++) {
		fout << "add" << i << "___" << i + 4 << " <= add" << i << "__" << i + 8 << " + add" << i + 4 << "__" << i + 12 << ';' << endl;
	}



	return 0;
}