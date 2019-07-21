// BTH2_BT10
#include <iostream>
#include <stdio.h>
using namespace std;
struct Node
{
	int info;
	Node *link;
};

Node *sp;

void init()
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

int Pop(int&x)
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

void output()
{
	Node *p = new Node;
	p = sp;
	while (p != NULL)
	{
		cout << p->info << endl;
		p = p->link;
	}
	cout << endl;
}

int Convert(int tp)
{
	init();
	while (tp != 0)
	{
		int d = tp % 2;
		Push(d);
		tp /= 2;
	}
	int np = 0;
	while (!isEmpty())
	{
		int so;
		if (Pop(so))
			np = np * 10 + so;
	}
	return np;
}

void HNtower(int n, char a, char b, char c)
{
	if (n == 1)
	{
		cout << "\t" << a << "-------" << c << endl;
		return;
	}
	HNtower(n - 1, a, c, b);
	HNtower(1, a, b, c);
	HNtower(n - 1, b, a, c);
	return;
}

int main()
{
	int choice;
	char cont;
	char a = 'A', b = 'B', c = 'C';
	do {
		system("cls");
		cout << "BTH2 BT10 MENU" << endl;
		cout << "1.Khoi tao rong\n2.Kiem tra rong\n3.Them 1 phan tu\n4.Xoa 1 phan tu\n5.Doi 1 so he thap phan sang he nhi phan\n6.Giai bai toan thap Ha Noi\n7.Xuat danh sach\nBan chon: \n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Ban vua khoi tao STACK rong thanh cong!" << endl;
			break;
		case 2:
			if (!isEmpty())
				cout << "STACK khong rong!" << endl;
			else
				cout << "STACK rong!" << endl;
			break;
		case 3:
			int x;
			cout << "Nhap phan tu can them: ";
			cin >> x;
			Push(x);
			break;
		case 4:
			int y;
			Pop(y);
			cout << "Phan tu can lay ra la: " << y << endl;
			break;
		case 5:
			int tp;
			cout << "Nhap gia tri thap phan can doi sang nhi phan: ";
			cin >> tp;
			cout << tp << " co dang nhi phan la: " << Convert(tp) << endl;
			break;
		case 6:

			int n;
			cout << "Nhap so dia: ";
			cin >> n;
			HNtower(n, a, b, c);
			break;
		case 7:
			cout << "STACK hien tai: " << endl;
			output();
			break;
		}
		cout << "Ban co muon tiep tuc(Y/N)" << endl;
		cin >> cont;
	} while (cont == 'Y' || cont == 'y');
	system("pause");
	return 0;
}