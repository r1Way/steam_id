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

string capToSmall(string &s)//将所有大写变为小写
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
	0=黑色，1=蓝色，2=绿色，3=湖蓝色，4=红色，5=紫色；
	6=黄色，7=白色，8=灰色，9=淡蓝色，10=淡绿色，11=浅绿色；
	12=淡红色，13=淡紫色，14=淡黄色，15=亮白色。
	*/
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

