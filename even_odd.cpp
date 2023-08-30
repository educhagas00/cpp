#include<iostream>
#include <cstdlib>

int compare_equal(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x %2 == 1)
		return 1;
	else if (*x %2 == 0)
		return -1;

	return 0;
}

int compare_impar(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x < *y)
		return 1;
	else if (*x > *y)
		return -1;

	return 0;
}

int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}

int main() {

    int n;
    std::cin >> n;
    int* vet = new int[n]; // malloc

    for(int i = 0; i < n; i++)
    {
        std::cin >> vet[i];
    }

    qsort(vet,n,sizeof(int),compare_equal);

    int i = 0;

    while(vet[i] %2 == 0)
    {
        i++;
    }

    qsort(vet,i,sizeof(int),compare);
    qsort(&vet[i],n - i,sizeof(int),compare_impar);


    for(int i = 0; i < n; i++)
    {
        std::cout << vet[i] << " ";
    }

    delete[] vet; // free maloc

    return 0;
}
