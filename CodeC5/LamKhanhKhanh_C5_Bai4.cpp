//Project: Code5_Bai1.cpp
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

#define MAX 20
int A[MAX][MAX];
int n;
char vertex[MAX];

struct Node {
	int info;
	Node *link;
};

Node *sp;
Node *front, * rear;

void InitStack() {
	sp = NULL;
}
int isEmptyS() {
	if (sp == NULL) return 1;
	return 0;
}

void PushS(int x) {
	Node *p = new Node;
	p -> info = x;
	p -> link = sp;
	sp = p;
}

int PopS(int &x) {
	if (sp != NULL) {
		Node *p = sp;
		x = p -> info;
		sp = p -> link;
		delete p;
		return 1;
	}
	return 0;
}

void InitQueue() {
	front = NULL;
	rear = NULL;
}

int isEmptyQ() {
	if (front == NULL)
		return 1;
	return 0;
}

void PushQ(int x) {
	Node *p = new Node;
	p -> info = x;
	p -> link = NULL;
	if (rear == NULL) front= p;
	else rear -> link = p;
	rear = p;
}

int PopQ(int &x) {
	if (front != NULL) {
		Node *p = front;
		front = p -> link;
		x = p -> info;
		if (front == NULL) rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

void InitGraph() {
	n = 0;
}

void initGraphFromText() {
	string line;
	ifstream myfile ("matranke1.txt");
	if (myfile.is_open()) {
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				myfile >> A[i][j];
	}
}

void inputGraph() {
	cout << "Nhap so dinh do thi n: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap ten dinh: "; cin >> vertex[i];
		cout << "Nhap vao dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
}

void outputGraph() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

void output(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
}

int C[100], bfs[100];
int nbfs = 0;

void InitC() {
	for (int i = 0; i < n; i++)
		C[i] = 1;
}

void BFS(int v) {
	int w, p;
	PushQ(v);
	C[v] = 0;
	while (front != NULL) {
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for (w = 0; w < n; w++)
			if (C[w] && A[p][w] == 1) {
				PushQ(w);
				C[w] = 0;
			}
	}
}

int dfs[100];
int ndfs = 0;

void DFS(int s) {
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (isEmptyS() == 0) {
		if (v == n)
			PopS(u);
		for (v = 0; v < n; v++)
			if (A[u][v] != 0 && C[v] == 1) {
				PushS(u);
				PushS(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
	}
}

void Search_by_BFS(int x,int v) {
	int w, p;
	PushQ(v);
	C[v] = 0;
	while (front != NULL) {
		PopQ(p);
		if(x == p) {
			cout << "Tim thay x = " << x << endl;
			return;
		}
		for (w = 0; w < n; w++)
			if (C[w] && A[p][w] == 1) {
				PushQ(w);
				C[w] = 0;
			}
	}
}

int main() {
	int a[MAX], b[MAX];
	int choice, sp, sp_b, x, i;
	system("cls");
	cout << " ---------- BAI TAP 4 - CHUONG 5 - DO THI ---------- " << endl;
	cout << "1. Khoi tao Ma Tran Ke Rong" << endl;
	cout << "2. Nhap Ma Tran Ke tu file Text" << endl;
	cout << "3. Nhap Ma Tran Ke" << endl;
	cout << "4. Xuat Ma Tran Ke" << endl;
	cout << "5. Duyet do thi theo chieu rong BFS - DSLK" << endl;
	cout << "7. Tim dinh co gia tri x theo BFS" << endl;
	cout << "8. Thoat" << endl;
	do {
		cout << "\nVui long chon so de thuc hien: "; cin >> choice;
		switch(choice) {
		case 1:
			InitGraph();
			cout << "Ban vua khoi tao Ma Tran Ke thanh cong\n";
			break;
		case 2:
			initGraphFromText();
			cout << "Ban vua nhap Ma Tran Ke tu file: \n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			InitQueue();
			InitC();
			cout << "Vui long nhap dinh xuat phatL "; cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu dinh sau khi duyet BFS:" << endl;
			output(bfs, n);
			break;
		case 6:
			InitStack();
			InitC();
			cout << "Vui long nhap dinh xuat phatL "; cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu dinh sau khi duyet DFS:" << endl;
			output(dfs, n);
			break;
		case 7:
			output(dfs, n);
			break;
		case 8:
			cout << "Good Bye...!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 8);
	return 0;
}