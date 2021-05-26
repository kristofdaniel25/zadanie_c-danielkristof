#include <stdio.h>
#include <math.h>

void cyklicky_posun_rychlo(int* p, int l, int s)
{
	s = l - s;
	int i,k, j, temp, posun;
	for (i = 0; i < no_of_iterations(l,s); i++)
	{
		j = i;
		temp = p[i];
		while(1)
		{
			posun = (j + s) % l;
			if (posun == i) break;
			p[j] = p[posun];
			j = posun; 
		}
		p[j] = temp;
	}
}

int no_of_iterations(int N, int k)
{
	int i = 2;
	if (N % k == 0)
	{
		return  abs(k);
	}
	else if (N % (N - k) == 0 && (N - k != 1))
	{
		return abs(N - k);
	}
	else
	{
		while (k % i != 0)
			i++;
		if (i == k)
			return 1;
		else return no_of_iterations(N, k/(i));
	}
	
}

int NSD(int a, int b)
{
	if (b == 0) return a;
	else return NSD(b, a % b);
}

void print(int* p, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%.2d ", p[i]);
	}
}


int main()
{
	srand(time(0));
	int pole[100000], i, n, k;

	printf("Zadaj velkost pola:\n");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		pole[i] = i;
	}
	printf("Povodne pole:\n");
	print(pole, n);
	printf("\nZadaj s, pocet pozicii, o ktore sa pole posunie:\n");

	scanf("%d", &k);

	cyklicky_posun_rychlo(pole, n, k);
	printf("\nPole po posunuti:\n");

	print(pole, n);
	return 0;

}
