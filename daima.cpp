#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
void Swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void BubbleSort(int n,int a[])
{
	int i, j;
	for (i = 0;i < n;i++)
	{
		for (j = 1;j < n - i;j++)
		{
			if (a[j] < a[j - 1])
			{
				Swap(&a[j], &a[j - 1]);
			}
		}
	}
}//√∞≈›≈≈–Ú

void InsertSort(int n, int a[])
{
	int i, j, x;
	for (i = 1;i < n;i++)
	{
		x = a[i];
		for (j = i;j > 0;j--)
		{
			if (x < a[j - 1])
			{
				Swap(&a[j], &a[j - 1]);
			}
		}
	}
}//≤Â»Î≈≈–Ú

void SwapSort(int n, int a[])
{
	int min, i, j,target=0;
	for (i = 0;i < n;i++)
	{
		min = a[i];
		for (j = i;j < n;j++)
		{
			if (min > a[j])
			{
				min = a[j];
				target = j;
			}
		}
		Swap(&a[target], &a[i]);
	}
}//—°‘Ò≈≈–Ú

void QuickS(int a[], int left, int right)
{
	if (right <= left)
	{
		return;
	}
	int i = left , j = right;
	int temp = a[left];
	while (i < j)
	{
		while (i < j && a[j] >= temp)
		{
			--j;
		}
		while (i < j && temp > a[i])
		{
			++i;
		}
		if (i != j)
		{
			int t;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	QuickS(a, left, i - 1);
	QuickS(a, i + 1, right);
}
void QuickSort(int n,int a[])
{
	QuickS(a, 0, n - 1);
}//øÏÀŸ≈≈–Ú

void Merge(int a[], int b[], int left, int mid, int right)
{
	int i, j, target;
	i = left;
	j = mid+1;
	target = left;
	while ((i<=mid)&&(j<=right))
	{
		if (a[i] <= a[j])
		{
			b[target++] = a[i++];
		}
		else
		{
			b[target++] = a[j++];
		}
	}
	while (i <= mid)
	{
		b[target++] = a[i++];
	}
	while (j <= right)
	{
		b[target++] = a[j++];
	}
	for (int i = left;i <= right;i++)
	{
		a[i] = b[i];
	}
}
void Allevate(int a[], int b[], int left, int right)
{	
	if (left==right)
	{
		return;
	}
	//Œ‘≤€
	int mid = (left + right) / 2;
	Allevate(a, b, left, mid);
	Allevate(a, b, mid + 1, right);
	Merge(a, b , left, mid, right);
}
void MergeSort(int n, int a[])
{	
	int add = n;
	int* addArr = (int*)malloc(sizeof(int) * add);
	Allevate(a, addArr, 0, (n - 1));
}//πÈ≤¢≈≈–Ú

int main()
{
	int n;
	scanf_s("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	if (arr != NULL)
	{
		for (int i = 0;i < n;i++)
		{
			arr[i] = rand();
		}
	}
	printf("\n");
	int* test1 = (int*)malloc(sizeof(int) * n);
	int* test2 = (int*)malloc(sizeof(int) * n);
	int* test3 = (int*)malloc(sizeof(int) * n);
	int* test4 = (int*)malloc(sizeof(int) * n);
	int* test5 = (int*)malloc(sizeof(int) * n);
	for (int i = 0;i < n;i++)
	{
		if (test1 != NULL && test2 != NULL && test3 != NULL && test4 != NULL && test5 != NULL && arr != NULL)
		{
			test1[i] = arr[i];
			test2[i] = arr[i];
			test3[i] = arr[i];
			test4[i] = arr[i];
			test5[i] = arr[i];
		}
	}
	free(arr);
	clock_t start, end;
	double total;

	
	start = clock();
	BubbleSort(n, test1);
	free(test1);
	end = clock();
	total = (double)(end - start) / CLOCKS_PER_SEC;
	printf("√∞≈›=%lf /s\n", total);

	start = clock();
	InsertSort(n, test2);
	free(test2);
	end = clock();
	total = (double)(end - start) / CLOCKS_PER_SEC;
	printf("≤Â»Î=%lf /s\n", total);

	start = clock();
	SwapSort(n, test3);
	free(test3);
	end = clock();
	total = (double)(end - start) / CLOCKS_PER_SEC;
	printf("—°‘Ò=%lf /s\n", total);
	
	start = clock();
	QuickSort(n, test4);
	free(test4);
	end = clock();
	total = (double)(end - start) / CLOCKS_PER_SEC;
	printf("øÏ≈≈=%lf /s\n", total);

	start = clock();
	MergeSort(n, test5);
	free(test5);
	end = clock();
	total = (double)(end - start) / CLOCKS_PER_SEC;
	printf("πÈ≤¢=%lf /s\n", total);

	return 0;
}

