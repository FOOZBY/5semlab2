#include <iostream>

using namespace std;

int snail_amount;

void merge(float* arr, int l, int m, int r)
{
	int i = 0, j = 0, k = l;
	int n1 = m - l + 1;
	int n2 = r - m;
	float* L = new float[n1]();
	float* R = new float[n2]();

	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	while (i < n1 && j < n2) 
	{
		if (L[i] <= R[j]) 
		{
			arr[k] = L[i];
			i++;
		}
		else 
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) 
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) 
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}

void mergeSort(float* arr, int l, int r)
{
	
	int m = l + (r - l) / 2;
	if (l < r)
	{
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}


struct Snail
{
	float x = 0, y = 0;
	int length = snail_amount - 1;
	float* paths = new float[length]();

	bool confusion = false;
	float temp;
	void conf_detecter()
	{
		mergeSort(paths, 0, length-1);
		if (paths[0] == paths[1])
			this->confusion = true;
	}
};

float pathlength(float x1, float y1, float x2, float y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}