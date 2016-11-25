#include<iostream>
#define MAX 10

using namespace std;

void quick_sort(int arr[], int left, int right);

int main(void)
{
	int arr[MAX];
	int i = 0;
	while (scanf("%d", &arr[i++])&&i != MAX)
		;
	quick_sort(arr, 0, sizeof(arr)/sizeof(int)-1);
	system("pause");
	return 0;
}

void quick_sort(int arr[], int left, int right)
{
	int rand_chose;
	if (left == right)
		return;
	rand_chose = left + rand() % (right - left);
	int chose_number = arr[rand_chose];
	int L = left, R = right;
	while (L < R)
	{
		while (L != R && arr[L] < chose_number)
			++L;
		while (L != R && arr[R] > chose_number)
			--R;
		if (L < R)
		{
			int temp = arr[L];
			arr[L] = arr[rand_chose];
			arr[rand_chose] = temp;
			++L;
			--R;
		}
	}
	{
		int temp = arr[L];
		arr[L] = arr[rand_chose];
		arr[rand_chose] = temp;
	}
	quick_sort(arr, rand_chose + 1, right);
	quick_sort(arr, left, rand_chose);
}