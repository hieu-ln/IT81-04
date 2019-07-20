#include <iostream>
#include <stdio.h>
using namespace std;

# define MAX 100
int a[MAX];
int n;

void input (int a[], int &n)
{
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cout<<"nhap a["<<i<<"] = ";
		cin>>a[i];
	}
}
void output (int a[], int n)
{
	for (int i=0; i<n; i++)
	cout<< "Phan tu thu " << i+1 << " la: " << a[i]<<endl;
}
int search (int a[],int n, int x)
{
	int i=0;
	while ((i<n) && (a[i]!=x))
		i++;
	if (i==n)
		return -1;
	return i;
}
int insert_last (int a[], int &n, int x)
{
	if (n<MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	else 
		return 0;
}
int delete_last (int a[], int &n)
{
	if (n > 0)
	{
		n--;
		return 1;
	}
	else 
		return 0;
}
int deletei (int a[], int &n, int i)
{
	if (i >= 0 && i < n)
	{
		for (int j=i; j < n-1; j++)
			a[j] = a[j+1];
		n--;
		return 1;
	}
	else 
		return 0;
}
int search_delete (int a[], int &n, int x)
{
	for (int i=0; i < n; i++)
	{
		if (a[i] == x)
		{
			deletei(a,n,i);
			return 1;
		}
	}
			return 0;
	
}

int main()
{
	int choice=0;
	int x,i;
	system ("cls");
	cout << "------ BAI TAP 1, CHUONG 2, DANH SACH DAC ------\n";
	cout << "1. Nhap danh sach" << endl;
	cout << "2. Xuat danh sach" << endl;
	cout << "3. Tim phan tu co gia tri x trong danh sach" << endl;
	cout << "4. Them phan tu vao cuoi danh sach" << endl;
	cout << "5. Xoa phan tu cuoi danh sach" << endl;
	cout << "6. Xoa phan tu tai vi tri i" << endl;
	cout << "7. Tim phan tu voi gia tri x va xoa no" << endl;
	cout << "8. Thoat " << endl;

	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
				input(a,n);
				cout << "Ban vua nhap danh sach thanh cong" << endl;
				break;
			case 2:
				cout << "Danh sach ban vua nhap la: \n";
				output(a,n);
				break;
			case 3:
				cout << "Vui long nhap x can tim: ";
				cin >> x;
				i = search(a,n,x);
				if (i == -1)
					cout << "Khong tim thay phan tu co gia tri " << x << endl;
				else
					cout << "Tim thay tai vi tri i=" << i << endl;
				break;
			case 4:
				cout << "Vui long nhap x can them vao cuoi DS: ";
				cin >> x;
				i = insert_last(a,n,x);
				if (i == 0)
					cout << "Danh sach da day khong the them. " << endl;
				else
					cout << "Da them phan tu " << x << " vao cuoi DS" << endl;
					cout << "Danh sach sau khi them \n ";
					output(a,n);
				break;
			case 5:
				i=delete_last(a,n);
				if (i>0)
				{
					cout << "Xoa thanh cong.\n";
					cout << "Danh sach sau khi xoa: \n";
					output (a,n);
				}
				else
					cout << "Danh sach rong\n";
				break;
			case 6: 
				cout << "Vui long nhap vi tri can xoa: ";
				cin >> i;
				i = deletei(a,n,i);
				if (i==1)
				{
					cout << "Xoa thanh cong.\n";
					cout << "Danh sach sau khi xoa:\n";
					output (a,n);
				}
				else 
					cout << "Khong co phan tu nao de xoa.";
				break;
			case 7:
				cout << "Vui long nhap gia tri can xoa: ";
				cin >> x;
				i = search_delete(a,n,x);
				if (i==1)
				{
					cout << "Xoa thanh cong.\n";
					cout << "Danh sach sau khi xoa:\n";
					output (a,n);
				}
				else 
					cout << "Khong co phan tu nao de xoa.\n";
				break;
		}
	} while (choice!=8);
	return 0;
}