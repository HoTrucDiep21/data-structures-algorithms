#include<iostream>
using namespace std;

struct node {
	int data;
	struct node *pL;
	struct node *pR;
};
typedef struct node NODE;
typedef NODE* TREE;

void createTree(TREE &t) {
	t = NULL;
}

void addNodeToTree(TREE &t, int x) {
	if ( t == NULL)
	{
		NODE *p = new NODE;
		p->data = x;
		p->pL = NULL;
		p->pR = NULL;
		t = p;

	}
	else //If tree has elements
	{
		if (t->data > x) {
			addNodeToTree(t->pL, x);
		}
		else if (t->data < x)
		{
			addNodeToTree(t->pR, x);
		}

	}
}

void TraversingTreeNLR(TREE t) {
	if (t != NULL)
	{
		cout << t->data << " ";
		TraversingTreeNLR(t->pL);
		TraversingTreeNLR(t->pR);
	}
}

void TraversingTreeLNR(TREE t) {
	if (t != NULL)
	{
		TraversingTreeLNR(t->pL);
		cout << t->data << " ";
		TraversingTreeLNR(t->pR);
	}
}

void TraversingRNL(TREE t) {
	if (t != NULL)
	{
		TraversingRNL(t->pR);
		cout << t->data << " ";
		TraversingRNL(t->pL);
	}
}

bool isPrime(int x) {
	if (x < 1)
	
		return false;

	for (int i = 2 ;i < x; i++)
	
		if (x % i == 0) 
			return false; 
		
	return true;

	

}

void countPrime(TREE t, int &count) {
	if (t != NULL)
	{
		if (isPrime(t->data) == true) {
			count++;
		}
		countPrime(t->pL, count);
		countPrime(t->pR, count);
	}

	
}

NODE* searchTree(TREE t, int x) {
	if (t == NULL) {
		return NULL;
	}
	else {
		if (x < t->data)
		{
			searchTree(t->pL, x);
		}
		else if (x > t->data) {
			searchTree(t->pR, x);
		}
		else {
			return t; // return Node need Search.
		}
	}
	

}
// Print Root have 2 Node
void exTree2Node(TREE t) {
	if (t != NULL)
	{
		if (t->pL != NULL && t->pR != NULL) {
			cout << t->data << " ";
		}
		exTree2Node(t->pL);
		exTree2Node(t->pR);
	}
}
// Print  Root has 1 Node
void exTree1Node(TREE t) {
	if (t != NULL)
	{
		if ((t->pL != NULL && t->pR == NULL) ||(t->pL == NULL && t->pR != NULL) )
		{
			cout << t->data << " ";

		}
		exTree1Node(t->pL);
		exTree1Node(t->pR);

	}
}
// Print Root Node leaves.
void exNodeLeaves(TREE t) {
	if (t != NULL) {
		if (t->pL == NULL && t->pR == NULL)
		{
			cout << t->data << " ";
		}
		exNodeLeaves(t->pL);
		exNodeLeaves(t->pR);
	}
}

int maxValue(TREE t) {
	if (t->pR == NULL)
	{
		return t->data;
	}

	return maxValue(t->pR);

}
void Menu(TREE t) {
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t========MENU=======\n";
		cout << "\n1. Add Node to Tree";
		cout << "\n2. Export Tree element By NLR.";
		cout << "\n3. Export Tree element By LRN.";
		cout << "\n4. Export Tree element By RNL.";
		cout << "\n5. Count the number of Prime in TREE.";
		cout << "\n6. Search Element in Binary Tree.";
		cout << "\n7. Export Element have 2 Node.";
		cout << "\n8. Export Element have 1 Node.";
		cout << "\n9. Export Element have not Node orther.";
		cout << "\n10. Find max value";
		cout << "\n0. Finished";
		cout << "\n\n\t\t========END=======";

		int choose;
		cout << "\n\tInput choose: ";
		cin >> choose;

		if (choose < 0 || choose > 11)
		{
			cout << "Invalid selection!!!";
			system("pause");
		}
		else if (choose == 1)
		{
			int x;
			cout << "\n\tInput data for X: ";
			cin >> x;
			addNodeToTree(t, x);
		}
		else if (choose == 2)
		{
			cout << "Traversing Tree NLR\n";
			TraversingTreeNLR(t);
			system("pause");
		}
		else if (choose == 3)
		{
			cout << "\nTraversing Tree LNR\n";
			TraversingTreeLNR(t);
			system("pause");
		}
		else if (choose == 4)
		{
			cout << "\nTraversing Tree By RNL\n";
			TraversingRNL(t);
			system("pause");
		}
		else if (choose == 5) {
			int count = 0;
			countPrime(t, count);
			cout << "\nThe number of Prime in Tree is : " << count;

			system("pause");
		}
		else if (choose == 6) {
			int x;
			cout << "\nInput element you need to find: ";
			cin >> x;
			if (searchTree(t, x) == NULL)
			{
				cout << "\nThere is no element " << x << " in Tree!!!";
				system("pause");
			}
			else
			{
				cout << "\nHas find element " << x << " in Tree.";
				system("pause");
			}
		}
		else if (choose == 7) {
			cout << "\nElement have 2 Node: ";
			exTree2Node(t);
			system("pause");
		}
		else if (choose == 8) {
			cout << "\nElement have 1 Node: ";
			exTree1Node(t);
			system("pause");
		}
		else if (choose == 9)
		{
			cout << "\nElement have not Node orther : ";
			exNodeLeaves(t);
			system("pause");
		}
		else if (choose == 10);
		{
			int max = maxValue(t);
			cout << max;
			//cout << "\nMax Value in Binary Tree = " << maxValue(t);
			system("pause");
		}
		else if (choose == 0)
		{
			break;
		}



	}
}


int main() { 
	TREE t;
	createTree(t);
	Menu(t);

	cout << endl;

	system("pause");
	return 0;

}

