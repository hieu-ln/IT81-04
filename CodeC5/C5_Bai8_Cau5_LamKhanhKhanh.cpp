#include <iostream>
#include <fstream>
using namespace std;
#define MAX 50
int A[MAX][MAX];
int n;
int vertex[MAX];
//cau 8.1
void docfile()
{
	ifstream myfile("do_thi_1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				myfile >> A[i][j];
	}
	else
		cout << "Doc file that bai\n";
}
void khoitaoG()
{
	n = 0;
}
//hàm xuất đồ thị
void xuatG()
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
	}
}
void xuatver(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
}

struct Node
{
	int infor;
	Node* link;
};
Node* front,*rear;

//STACK
void khoitaoQ()
{
	front = NULL;
	rear = NULL;
}
int ktrongS()
{
	if (front == NULL)
		return 1;
	return 0;
}

void them(int x)
{
	Node* p = new Node;
	p->infor = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
	{
		rear->link = p;
	}
	rear = p;
}
int xoa(int &x)
{
	if (rear != NULL)
	{
		Node*p = front;
		x = p->infor;
		front = p->link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//duyệt theo BFS
int C[100], bfs[100];
int nbfs = 0;
void khoitaoC()
{
	for (int i = 0; i < n; i++)
		C[i] = 1;
}
void BFS(int q)
{
	int w, p;
	them(q);
	C[q] = 0;
	while (rear != NULL)
	{
		xoa(p);
		bfs[nbfs] = p;
		nbfs++;
		for (int w = 0; w < n; w++)
		{
			if (C[w] == 1 && A[p][w] == 1)
			{
				them(w);
				C[w] = 0;
			}
		}
	}
}
//cau 8.5
void tim(int x, int q)
{
	int w, p;
	them(q);
	C[q] = 0;
	while (front != NULL)
	{
		xoa(p);
		if (x == p)
		{
			cout << "Tim thay x= " << x << endl;
			return;
		}
		for(int w=0;w<n;w++)
			if (C[w] && A[p][w] == 1)
			{
				them(w);
				C[w] = 0;
			}
	}
}
int main()
{
	int chon, x;
	system("cls");
	cout << " ---------- BAI TAP 4 , CHUONG 5 , DO THI ----------" << endl;
	cout << "1. khoi tao MA TRAN KE rong" << endl;
	cout << "2. Nhap MA TRAN KE tu file text" << endl;
	cout << "3. Xuat MA TRAN KE " << endl;
	cout << "4. Duyet do thi theo chieu rong BFS _ DSLK " << endl;
	cout << "5. Tim dinh co gia tri x theo BFS" << endl;
	cout << "6. Thoat" << endl;
	do
	{
		cout << "\nVui long chon yeu cau: ";
		cin >> chon;
		switch (chon)
		{
			case 1:
				khoitaoG();
				cout << "Khoi tao ma tran rong thanh cong\n";
				break;
			case 2:
				docfile();
				cout << "Ban vua nhap ma tran ke bang file\n";
				xuatG();
				break;
			case 3:
				cout << "Ma tran ke vua nhap:\n";
				xuatG();
				break;
			case 4:
				khoitaoQ();
				khoitaoC();
				cout << "Nhap dinh xuat phat: ";
				cin >> x;
				nbfs = 0;
				BFS(x);
				cout << "Thu tu sau khi duyet BFS: ";
				xuatver(bfs, n);
				break;
			case 5:
				khoitaoQ();
				khoitaoC();
				nbfs = 0;
				cout << "dinh can tim trong do thi: ";
				cin >> x;
				tim(x, 0);
				cout << endl;
				break;
			case 6:
				cout << "Good bye\n";
				break;
		default:
			break;
		}
	} while (chon != 6);
	system("pause");
	return 0;
}