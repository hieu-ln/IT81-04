//Project: C3_Bai1.cpp
#include <iostream>
#include <ctime>
#include <stdio.h>
using namespace std;

#define MAX 5000
//Cau 1.1
int a[MAX];
int n;

//Cau 1.2: Nhap danh sach tu dong, ngau nhien
void init(int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: ";
		cin >> n;
		for (int i = 0; i < n; i++)
			a[i] = rand() % 10000 + 1;
		cout << "Danh sach da duoc nhap ngau nhien nhu sau: \n";
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
}
//Cau 1.2: Nhap danh sach
void input(int a[], int n)
{
	cout << "Nhap vao so luong phan tu danh sach: "; cin >> n;
	cout << "Nhap vao cac phan tu cua danh sach: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] = ";
		cin >> a[i];
	}
}
//Cau 1.3: Xuat danh sach
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void CopyArray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
//Cau 1.4: Insertion Sort
void insertionSort(int a[], int n)
{
	int i, key, j;
	for (int i = 0; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}
//ham hoan doi 2 so nguyen
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

//Cau 1.5: Selection Sort
void SelectionSort(int a[], int n)
{
	int  min_pos, i, j;
	for (i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_pos])
				min_pos = j;
		swap(a[min_pos], a[i]);
	}
}

void InsertionSort(int a[], int n)
{
	int x, i, j;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while(0 <= j && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
//Cau 1.6: Interchange Sort
void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}

//Cau 1.7: Bubble Sort
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(a[j], a[j - 1]);
}
//Cau 1.8: Quick Sort
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while(i < j) 
	{
		while(a[i] < x)
			i++;
		while(a[j] > x)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		QuickSort(a, left,j );
	if (i < right)
		QuickSort(a, i, right);
}
//Cau 1.9: Heap Sort
void shift(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if (j >= n) 
		return;
	if (j + 1 < n) 
		if (a[j] < a[j + 1] )
			j++;

	if (a[i] >= a[j]) 
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
	}
}
void HeapSort(int a[], int n)
{
	int i = n / 2 - 1;
	while (i >= 0) 
	{	
		shift(a, i, n - 1);
		i--;
	}
	int right = n - 1;
	while (right > 0)
	{	
		swap(a[0], a[right]);
		right--;
		if (right > 0)
			shift(a, 0, right);
	}
}

//Cau 1.10: Tim kiem tuan tu
int Search(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if(i < n)
		return i; 
	return -1;
}
//Cau 1.11: Tim kiem nhi phan
int BinarySearch(int a[], int n, int x)
{
	int left = 0, right = n - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x)
			return mid;
		if (x > a[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout << "----- CHUONG 3 - BAI 1 -----\n";
	cout << "0. Khoi tao danh sach ngau nhien" << endl;
	cout << "1. Nhap danh sach" << endl;
	cout << "2. Xuat danh sach" << endl;
	cout << "3. Selection Sort" << endl;
	cout << "4. Insertion Sort" << endl;
	cout << "5. Interchange Sort" << endl;
	cout << "6. Bubble Sort" << endl;
	cout << "7. Quick Sort" << endl;
	cout << "8. Heap Sort" << endl;
	cout << "9. Tim kiem tuan tu" << endl;
	cout << "10. Tim kiem nhi phan" << endl;
	cout << "11. Thoat" << endl;
	do {
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			init(a, n);
			break;
		case 1:
			input(a, n);
			break;
		case 2:
			output(a, n);
			break;
		case 3:
			CopyArray(a, b, n);
			start = clock();
			SelectionSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi xep thu tu voi Selection Sort: ";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian Seclection Sort: " << duration * 1000000;
			break;
		case 4:
			CopyArray(a, b, n);
			start = clock();
			InsertionSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi xep thu tu voi Insertion Sort: ";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian Insertion Sort: " << duration * 1000000;
			break;
		case 5:
			CopyArray(a, b, n);
			start = clock();
			InterchangeSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi xep thu tu voi Interchange Sort: ";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian Interchange Sort: " << duration * 1000000;
			break;
		case 6:
			CopyArray(a, b, n);
			start = clock();
			BubbleSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi xep thu tu voi Bubble Sort: ";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian Bubble Sort: " << duration * 1000000;
			break;
		case 7:
			CopyArray(a, b, n);
			start = clock();
			QuickSort(b, 0, n - 1);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi xep thu tu voi Quick Sort: ";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian Quick Sort: " << duration * 1000000;
			break;
		case 8:
			CopyArray(a, b, n);
			start = clock();
			HeapSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi xep thu tu voi Heap Sort: ";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian Heap Sort: " << duration * 1000000;
			break;
		case 9:
			cout << "Vui long nhap gia tri x: ";
			cin >> x;
			start = clock();
			i = Search(a, n, x);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (i == -1)
				cout << "Khong tim thay x = " << x << " trong day!" << endl;
			else
				cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl;
			if (duration > 0)
				cout << "Thoi gian tim kiem Tuan Tu: " << duration * 1000000;
			break;
		case 10:
			cout << "Vui long nhap gia tri x: ";
			cin >> x;
			start = clock();
			i = BinarySearch(a, n, x);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (i == -1)
				cout << "Khong tim thay x = " << x << " trong day!" << endl;
			else
				cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl;
			if (duration > 0)
				cout << "Thoi gian tim kiem Nhi Phan: " << duration * 1000000;
			break;
		case 11:
			cout << "Say Good Bye...!!!\n";
			break;
		default:
			break;
		}
	} while (choice != 11);
	return 0;
}