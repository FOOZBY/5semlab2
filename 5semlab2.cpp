#include "funch.h"

int main()
{
	setlocale(0, "");

	cout << "Введите кол-во улиток: ";
	cin >> snail_amount;
	Snail* snails = new Snail[snail_amount];
	cout << "Для каждой улитки введите стартовую позицию(считать верхний левый угол за 0,0)" << endl;
	for (int i = 0; i < snail_amount; i++)
	{
		cout <<"улитка "<< i << ":\nX: ";
		cin >> snails[i].x;
		cout << "Y: ";
		cin >> snails[i].y;
		cout << endl;
	}
	float shortest_path = 141422;//самое большое расстояние,которое может быть
	float temp = 0;
	int l = 0;

	for (int i = 0; i < snail_amount; i++)
	{
		for (int j = 0; j < snail_amount; j++)
		{
			if (i != j)
			{
				temp = pathlength(snails[i].x, snails[i].y, snails[j].x, snails[j].y);
				snails[i].paths[l] = temp;
				if (temp < shortest_path)
					shortest_path = temp;
				l++;
			}
		}
		snails[i].conf_detecter();
		l = 0;
	}
	int k = 0;
	for (int i = 0; i < snail_amount; i++)
	{
		if (snails[i].confusion)
		{
			cout << "Улитка " << i << " в замешательстве\n";
			k++;
		}
	}
	if (k != snail_amount)
		cout << "кратчайшее время = " << shortest_path << endl << endl;
	
	system("pause");
	return 0;
}