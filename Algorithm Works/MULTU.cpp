#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ofstream fout("MULTU.txt");
	
	////��λ��ֵ
	//for (int i = 0; i < 32; i++) {
	//	fout << "store" << i << " <= 0;" << endl;
	//}

	////һ����
	//for (int i = 0; i < 16; i++) {
	//	fout << "add" << i << '_' << i + 16 << " <= 0;" << endl;
	//}

	////������
	//for (int i = 0; i < 8; i++) {
	//	fout << "add" << i << "__" << i + 8 << " <= 0;" << endl;
	//}

	////������
	//for (int i = 0; i < 4; i++) {
	//	fout << "add" << i << "___" << i + 4 << " <= 0;" << endl;
	//}

	////�ݴ�Ĵ��� 32
	//for (int i = 0; i < 32; i++) {
	//	fout << "reg [63:0] store" << i << ';' << endl;
	//}

	////һ�Ĵ��� 16
	//for (int i = 0; i < 16; i++) {
	//	fout << "reg [63:0] add" << i << '_' << i + 16 << ';' << endl;
	//}

	////�����Ĵ��� 8
	//for (int i = 0; i < 8; i++) {
	//	fout << "reg [63:0] add" << i << "__" << i + 8 << ';' << endl;
	//}

	////�����Ĵ��� 4
	//for (int i = 0; i < 4; i++) {
	//	fout << "reg [63:0] add" << i << "___" << i + 4 << ';' << endl;
	//}

	////��λ��ֵ
	//for (int i = 0; i < 32; i++) {
	//	fout << "store" << i << " <= (b["<< i <<"] == 1) ? {"
	//		<< 32 - i <<"'b0,{" << "a" << "},"<< i << "'b0} : 64'b0;" << endl;
	//}

	////һ����
	//for (int i = 0; i < 16; i++) {
	//	fout << "add" << i << '_' << i + 16 << " <= store" << i << " + store" << i + 16 << ';' << endl;
	//}

	////������
	//for (int i = 0; i < 8; i++) {
	//	fout << "add" << i << "__" << i + 8 << " <= add" << i << '_' << i + 16 << " + add" << i + 8 << '_' << i + 24 << ';' << endl;
	//}

	////������
	//for (int i = 0; i < 4; i++) {
	//	fout << "add" << i << "___" << i + 4 << " <= add" << i << "__" << i + 8 << " + add" << i + 4 << "__" << i + 12 << ';' << endl;
	//}

	

	return 0;
}