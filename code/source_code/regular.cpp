#include"head.h"
void regular()
{
	ifstream fcin("after.txt",ios_base::in);
	ofstream fcout("final2.txt", ios_base::out);
	string line;
	string temp;
	while (getline(fcin, line))
	{
		temp = "";
		for (int i = 0; i<int(line.size()); i++)
		{
			if (int(line[i]) >= 32 && int(line[i]) <= 126)
			{
				temp += line[i];
			}
			else
			{
				fcout << temp << endl;
				cout << temp << endl;
				break;
			}
		}
	}
}

string capToSmall(string &s)//�����д�д��ΪСд
{
	string temp;
	char x;
	for (int i = 0; i<int(s.size()); i++)
	{
		if (s[i] >= 'A'&&s[i] <= 'Z')
		{
			x = char(int(s[i]) + int('a'-'A'));
			temp += x;
		}
		else
		{
			temp += s[i];
		}
	}
	return temp;
}

void color(int ForgC, int BackC) //0~15 
{
	/*
	0=��ɫ��1=��ɫ��2=��ɫ��3=����ɫ��4=��ɫ��5=��ɫ��
	6=��ɫ��7=��ɫ��8=��ɫ��9=����ɫ��10=����ɫ��11=ǳ��ɫ��
	12=����ɫ��13=����ɫ��14=����ɫ��15=����ɫ��
	*/
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

