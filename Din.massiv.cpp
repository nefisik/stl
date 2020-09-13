#include <iostream>
using std::cout;
using std::cin;

void funArray(int **mass, const int nstr, const int nstb);

int main()
{	//ввод размера динамического двумерного массива:
	int N, M;
	cin >>N>>M;
	//выделение места в памяти под динамический двумерный массив:
	int **Arr=new int* [N];
	for(int i=0; i<N; i++)
		Arr[i]=new int [M];
	//заполнение массива данными:
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin>>Arr[i][j];
	//передача массива в функцию:
	funArray(Arr,N,M);

	cin.get();
	cin.get();
	return 0;
}

void funArray(int **mass, const int nstr, const int nstb)
{	
	for(int i=0; i<nstr; i++)
	{
			cout<<"\n";
			for(int j=0; j<nstb; j++)
				cout<<mass[i][j]<<"  ";
	}
}
