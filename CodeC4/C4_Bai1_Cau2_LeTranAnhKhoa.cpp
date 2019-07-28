// BTH4_BT2
#include <iostream>
using namespace std;

#define COUNT 20
//2.1 Khai bao cau truc cay nhi phan tim kiem
struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;

//2.2 Khai bao cay rong
void tree_Empty()
{
	root = NULL;
}

//2.3 Them mot phan tu vao cay( khong dung de quy)
void insertNode(Node *&p, int x)
{
	if (p == NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->info == x)
			return; // da co Node co gia tri x
		else
			if (p->info > x)
				return insertNode(p->left, x);
			else
				return insertNode(p->right, x);
	}
}

//2.4 Tim mot phan tu trong cay( khong dung de quy)
Node *search(Node *p, int x)
{
	while (p != NULL)
	{
		if (p->info == x)
			return p;
		else
			if (p->info > x)
				p = p->left;
			else // p->info < x
				p = p->right;
	}
	return NULL;
}

//2.5 Xoa mot phan tu trong cay( dung de quy)
void searchStandFor(Node *&p, Node*&q)
{
	if (q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}
int Delete(Node *&T, int x)
{
	if (T == NULL)
		return 0;
	if (T->info == x)
	{
		Node *p = T;
		if (T->left == NULL)
			T = T->right;
		else
			if (T->right == NULL)
				T = T->left;
			else // co 2 con
				searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if (T->info < x)
		return Delete(T->right, x);
	if (T->info > x)
		return Delete(T->left, x);
}

//2.6 Duyet cay theo thu tu NLR
void duyetNLR(Node *p)
{
	if (p != NULL)
	{
		cout << p->info << "  ";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}

//2.7 Duyet cay theo thu tu LNR
void duyetLNR(Node *p)
{
	if (p != NULL)
	{
		duyetLNR(p->left);
		cout << p->info << "  ";
		duyetLNR(p->right);
	}
}

//2.8 Duyet cay theo thu tu LRN
void duyetLRN(Node *p)
{
	if (p != NULL)
	{
		duyetLRN(p->left);

		duyetLRN(p->right);
		cout << p->info << "  ";
	}
}

// Ham xuat cay
void print2DUtil(Node *p, int space)
{
	// Base case
	if (p == NULL)
		return;

	// Increase distance between levels
	space += COUNT;

	// Process right child first
	print2DUtil(p->right, space);

	// Print current node after space
	// count
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << "\n";

	// Process left child
	print2DUtil(p->left, space);
}

// Wrapper over print2DUtil
void Process_Tree()
{
	// Pass initial space count as 0
	print2DUtil(root, 0);
}

int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout << "---------- BAI TAP 2, CHUONG 4, CAY NPTK ----------" << endl;
	cout << "1. Khoi tao CAY NPTK rong" << endl;
	cout << "2. Them mot phan tu vao CAY NPTK" << endl;
	cout << "3. Tim kiem mot phan tu trong CAY NPTK" << endl;
	cout << "4. Xoa mot phan tu trong CAY NPTK" << endl;
	cout << "5. Duyet CAY NPTK theo LNR" << endl;
	cout << "6. Duyet CAY NPTK theo NLR" << endl;
	cout << "7. Duyet CAY NPTK theo LRN" << endl;
	cout << "8. Xuat CAY NPTK" << endl;
	cout << "9. Thoat" << endl;
	do {
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			tree_Empty();
			cout << "Khoi tao CAY NPTK thanh cong !!! \n";
			break;
		case 2:
			cout << "Vui long nhap gia tri can them: ";
			cin >> x;
			insertNode(root, x);
			cout << "CAY NPTK sau khi them la: ";
			Process_Tree();
			break;
		case 3:
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			p = search(root, x);
			if (p != NULL)
				cout << "Tim thay x = " << x << " trong CAY NPTK" << endl;
			else
				cout << "Khong tim thay x = " << x << " trong CAY NPTK" << endl;
			break;
		case 4:
			cout << "Vui long nhap gia tri x can xoa: ";
			cin >> x;
			i = Delete(root, x);
			if (i == 0)
				cout << "Khong tim thay x = " << x << " trong CAY NPTK de xoa" << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu x = " << x << " trong CAY NPTK" << endl;
				cout << "CAY NPTK sau khi xoa la: ";
				Process_Tree();
			}
			break;
		case 5:
			cout << "CAY NPTK duyet theo LNR la: ";
			duyetLNR(root);
			cout << endl;
			break;
		case 6:
			cout << "CAY NPTK duyet theo NLR la: ";
			duyetNLR(root);
			cout << endl;
			break;
		case 7:
			cout << "CAY NPTK duyet theo LRN la: ";
			duyetLRN(root);
			cout << endl;
			break;
		case 8:
			cout << "CAY NPTK nhu sau: ";
			Process_Tree();
			break;
		case 9:
			cout << "Goodbye.....!!!\n";
			break;
		default:
			break;
		}
	} while (choice != 9);
	system("pause");
	return 0;
}