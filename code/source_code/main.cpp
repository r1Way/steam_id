#include"head.h"

int main()
{
	string id;
	cout << "please enter your steam id : ";
	cin >> id;
	string	small_id = capToSmall(id);
	int n =int( id.size());
	string front = "data\\";
	string path;
	string type=".txt";
	for (int len = 0 ;len<n;len++)
	{
		color(14, 0);
		cout << "match degree : " << len +1<< endl;
		for (int i = 0; i<n;i++)//steam id ����
		{
			int j = i + len;
			if (j < n)
			{
				path = id[i];
				ifstream fcin(front+path+type,ios_base::in);
				string line;
				while (getline(fcin, line))//��ȡ
				{
					string small_line = capToSmall(line);
					int small_len = int(small_line.size());
					for (int p = 0; p < small_len; p++)//file�е�����ĸλ��
					{
						if (p + len >= small_len)//Խ��
						{
							break;
						}
						else
						{
							if (small_line[p] == id[i])//����ĸƥ��
							{
								int q = 0;
								for (; q <=len; q++)//�ȶԺ���  modify
								{
									if (small_line[p + q] != small_id[i + q])
									{
										break;
									}
								}

								if (q == len+1)//ƥ��ɹ� modify  print
								{
									color(7, 0);
									int z = 0;
									for (; z < p; z++)
									{
										cout << line[z];
									}
									color(4,0);
									for (; z <= p+len; z++)
									{
										cout << line[z];
									}
									color(7, 0);
									for (; z < small_len; z++)
									{
										cout << line[z];
									}
									cout << endl;
								}
							}
						}
					}

				}
				fcin.close();
			}
			else
			{
				break;
			}
			cout << endl;
		}
		cout << endl;
	}
	color(15,0);
	system("pause");
	return 0;
}