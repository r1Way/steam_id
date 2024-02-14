#include"head.h"
void classify()
{
	ifstream fcin("final.txt",ios_base::in);
	string front="data\\";
	string line;
	string path;
	string type = ".txt";
	while (getline(fcin,line))
	{
		//line = capToSmall(line);
		for (int i = 0; i<int(line.size()); i++)
		{
			path = line[i];
			ofstream fcout(front+path+type,ios_base::app);
			fcout << line<<endl;
			fcout.close();
		}
	}
}
