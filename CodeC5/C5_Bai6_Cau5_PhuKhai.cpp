#include <iostream>
#include <fstream>
using namespace std;

#define MAX 20
int A[MAX][MAX];
int n;
char vertex[MAX];

void initGraph()
{
	n = 0;
}

void inputGraphFromText()
{
	string line;
	ifstream myfile ("matranke51.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				myfile >> A[i][j];
		}
	}
}

void outputGraph()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] << "  ";
		cout << endl;
	}
}

//STACK
struct Node
{
	int info;
	Node *link;
};
Node *sp;

void initS()
{
	sp = NULL;
}

int isEmpty()
{
	if (sp == NULL)
		return 1;
	return 0;
}

void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int Pop(int &x)
{
	if (sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
//End STACK
//Tim x bang duyet DFS
int C[7];
void init()
{
	for (int i = 0; i < n; i++)//n la so dinh cua do thi
		C[i] = 1;
}
void Search_by_DFS(int x, int s)//s la dinh bat dau
{

	Push(s);
	C[s] = 0;
	int v = -1, u = s;
	while (!isEmpty())
	{
		if (v == n)
		{
			Pop(u);
			if (u == x)
			{
				cout << x << " ton tai!";
				return;
			}
		}
		for (v = 0; v < n; v++)
		{
			if (A[u][v] != 0 && C[v] == 1)
			{
				Push(u);
				Push(v);
				C[v] = 0;
				u = v;
				break;
			}
		}
	}
}

int main()
{
	int choice, x;
	cout << "---BAI 6, CAU 5, CHUONG 5, DUYET DFS---" << endl;
	cout << "1.Khoi tao ma tran rong" << endl
		<< "2.Nhap ma tran ke cua do thi 5.1" << endl
		<< "3.Xuat ma tran ke" << endl
		<< "4.Tim dinh X trong do thi" << endl
		<< "5.Thoat" << endl;

	do {
		cout << "\nVui long nhap so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			initGraph();
			cout << "Khoi tao ma tran rong thanh cong!";
			break;
		case 2:
			inputGraphFromText();
			cout << "Ma tran ke" << endl;
			outputGraph();
			break;
		case 3:
			cout << "Ma tran ke" << endl;
			outputGraph();
			break;
		case 4:
			cout << "Chon dinh can tim: ";
			cin >> x;
			init();
			initS();
			Search_by_DFS(x, 0);
			break;
		case 5:
			cout << "Goodbye!";
			break;
		default:
			cout << "Loi nhap lieu!";
			break;
		}
	} while (choice != 5);

	cout << endl;
	system("pause");
	return 0;
}