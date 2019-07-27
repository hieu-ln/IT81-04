// BÀI 1
#include <iostream>
#include <ctime>
using namespace std;

//1.1
#define MAX 5000
int a[MAX];
int n;

//1.2
void init(int a[], int &n)
{
	cout << "Nhap so luong phan tu cua danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10000 + 1;
	}
	cout << "Danh sach da duoc tao ngau nhien nhu sau: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

//1.2
void input(int a[], int &n)
{
	cout << "Nhap so luong phan tu can dung vao danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap " << n << " phan tu: ";
		cin >> a[i];
	}
}

//1.3
void output(int a[], int n)
{
	cout << "Danh sach hien tai la: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

//Ham copy
void CopyArray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
}

//1.4
void insertionSort(int a[], int n)
{
	int x, j;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while (0 <= j && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + i] = x;
	}
}

//Ham hoan 2 so nguyen
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

//1.5
void selectionSort(int a[], int n)
{
	int min_pos, i, j;
	for (i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_pos])
				min_pos = j;
		swap(a[min_pos], a[i]);
	}
}

//1.6
void interchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] > a[i])
				swap(a[i], a[j]); // doi cho a[i] va a[j]
}

//1.7
void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j]) // xet dieu kien phan tu sau nho hon phan tu truoc
				swap(a[j], a[j - 1]);
}

//1.8
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		QuickSort(a, left, j);
	if (i < right)
		QuickSort(a, i, right);
}

//1.9
void shift(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if (j >= n) // neu vi tri j khong ton tai trong danh sach dang xet thi thoat khoi chuong trinh
		return;
	if (j + 1 < n) // neu ton tai vi tri j + 1 trong danh sach dang xet thi thoat khoi chuong trinh
		if (a[j] < a[j + 1]) // neu vi tir j khong ton tai phan tu a[j] < a[j+1]
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
	int i = n / 2;
	while (i >= 0) // tao heap ban dau
	{
		shift(a, i, n - 1);
		i--;
	}
	int right = n - 1; // right la vi tri heap dang xet
	while (right > 0)
	{
		swap(a[0], a[right]); // hoan vi phan tu a[0] cho phan tu cuoi Heap dang xet
		right--; // gioi han lai phan tu cuoi dang xet
		if (right > 0) // kiem tra day dang xet con nhieu hon 1 phan tu
			shift(a, 0, right); // tao Heap lai vi tri 0
	}
}

//1.10
int search(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i < n)
		return i; // x trong danh sach a, va nam o vi tri i
	return -1;// khong tim thay x trong danh sach a
}

//1.12
int binarySearch(int a[], int n, int x)
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
	return -1; // khong tim thay trong danh sach a;
}

int main()
{
	int choice, x, i;
	int b[MAX];
	clock_t start;
	double duration;
	system("cls");
	cout << "-------- BAI TAP 1, CHUONG 3, SAP XEP va TIM KIEM --------\n";
	cout << "0. Khoi tao danh sach ngau nhien\n";
	cout << "1. Nhap danh sach\n";
	cout << "2. Xuat danh sach\n";
	cout << "3. Sap xep thu tu theo phuong phap SELECTION SORT\n";
	cout << "4. Sap xep thu tu theo phuong phap INSERTION SORT\n";
	cout << "5. Sap xep thu tu theo phuong phap BUBBLE SORT\n";
	cout << "6. Sap xep thu tu theo phuong phap INTERCHANGE SORT\n";
	cout << "7. Sap xep thu tu theo phuong phap QUICK SORT\n";
	cout << "8. Sap xep thu tu theo phuong phap HEAP SORT\n";
	cout << "9. Tim kiem theo phuong phap TIM KIEM TUAN TU\n";
	cout << "10. Tim kiem theo phuong phap TIM KIEM NHI PHAN\n";
	do {
		cout << "Vui long chon so de thuc hien: ";
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
			cout << "Danh sach la: " << endl;
			output(a, n);
			break;
		case 3:
			CopyArray(a, b, n);
			start = clock();
			selectionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep thu tu voi SELECTION SORT la: " << endl;
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian SELECTION SORT: " << duration * 1000000 << " Microsecond" << endl;
			break;
		case 4:
			CopyArray(a, b, n);
			start = clock();
			insertionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep thu tu voi INSERTION SORT la: " << endl;
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian INSERTION SORT: " << duration * 1000000 << " Microsecond" << endl;
			break;
		case 5:
			CopyArray(a, b, n);
			start = clock();
			interchangeSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep thu tu voi BUBBLE SORT la: " << endl;
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian BUBBLE SORT: " << duration * 1000000 << " Microsecond" << endl;
			break;
		case 6:
			CopyArray(a, b, n);
			start = clock();
			bubbleSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep thu tu voi INTERCHANGE SORT la: " << endl;
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian INTERCHANGE SORT: " << duration * 1000000 << " Microsecond" << endl;
			break;
		case 7:
			CopyArray(a, b, n);
			start = clock();
			QuickSort(b, 0, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep thu tu voi QUICK SORT la: " << endl;
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian QUICK SORT: " << duration * 1000000 << " Microsecond" << endl;
			break;
		case 8:
			CopyArray(a, b, n);
			start = clock();
			HeapSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep thu tu voi HEAP SORT la: " << endl;
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian HEAP SORT: " << duration * 1000000 << " Microsecond" << endl;
			break;
		case 9:
			cout << "Vui long nhap gia tri can tim x = ";
			cin >> x;
			start = clock();
			i = search(a, n, x);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (i == -1)
				cout << "Khong tim thay x = " << x << " trong mang" << endl;
			else
				cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl;
			if (duration > 0)
				cout << "\n Thoi gian TIM KIEM TUAN TU: " << duration * 1000000 << " Microsecond" << endl;
			break;
		case 10:
			cout << "Vui long nhap gia tri can tim x = ";
			cin >> x;
			start = clock();
			i = binarySearch(b, n, x);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (i == -1)
				cout << "Khong tim thay x = " << x << " trong mang" << endl;
			else
				cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl;
			if (duration > 0)
				cout << "\n Thoi gian TIM KIEM NHI PHAN: " << duration * 1000000 << " Microsecond" << endl;
			break;
		case 11:
			cout << "Goodbye.......!!!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 11);
	system("pause");
	return 0;
}