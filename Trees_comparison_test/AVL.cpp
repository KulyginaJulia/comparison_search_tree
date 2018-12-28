#include "include/AVL.h"
#include <cstring>

using namespace std;

//bstree::bstree(int n, nodeptr& root)
//{
//	int* a = new int[n];
//	for (int i = 0; i < n; i++) {
//		a[i] = 1 + rand() % 10000;
//		this->insert(a[i], root);
//	}
//	delete[] a;
//}

void bstree::generator(int n, nodeptr& root)
{
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = 1 + rand() % 100000;
	}
	for (int i = 0; i < n; i++)
		this->insert(a[i], root);
	delete[] a;
}

// ������� ��������
void bstree::insert(int x, nodeptr &p)
{
	if (p == NULL)
	{
		p = new nodeptr_;
		p->element = x;
		p->left = NULL;
		p->right = NULL;
		p->height = 0;
		if (p == NULL)
		{
			cout << "��� �����\n" << endl;
		}
	}
	else
	{
		if (x < p->element) // ������������
		{
			insert(x, p->left);
			if ((bsheight(p->left) - bsheight(p->right)) == 2) // �������� bfactor
			{
				if (x < p->left->element)
				{
					p = srl(p);
				}
				else
				{
					p = drl(p);
				}
			}
		}
		else if (x > p->element)
		{
			insert(x, p->right);
			if ((bsheight(p->right) - bsheight(p->left)) == 2)
			{
				if (x > p->right->element)
				{
					p = srr(p);
				}
				else
				{
					p = drr(p);
				}
			}
		}
		else
		{
			//this->insert(1 + x, p);
			//cout << "������ ����������\n" << endl;
		}
	}
	int m, n, d;
	m = bsheight(p->left);
	n = bsheight(p->right);
	d = fmax(m, n);
	p->height = d + 1;
}

// ����� ��������� ��������
bool bstree::find(int x, nodeptr &p)
{
	if (p == NULL)
	{
		cout << "Sorry.��������, �� ������ �������� ���\n" << endl;
		return false;
	}
	else
	{
		if (x < p->element)
		{
			find(x, p->left);
		}
		else
		{
			if (x > p->element)
			{
				find(x, p->right);
			}
			else
			{
				cout << "Finded.�������, ������� �� ������ ���� � ������!\n" << endl;
				return true;
			}
		}
	}
}

// �������� ��������
bool bstree::del(int x, nodeptr &p)
{
	nodeptr d;
	if (p == NULL)
	{
		cout << "��������, �� ������ �������� ���\n" << endl;
		return false;
	}
	else if (x < p->element)
	{
		del(x, p->left);
	}
	else if (x > p->element)
	{
		del(x, p->right);
	}
	else if ((p->left == NULL) && (p->right == NULL))
	{
		d = p;
		free(d);
		p = NULL;
		cout << "������� ������\n" << endl;
		return true;
	}
	else if (p->left == NULL)
	{
		d = p;
		free(d);
		p = p->right;
		cout << "������� ������\n" << endl;
		return true;
	}
	else if (p->right == NULL)
	{
		d = p;
		p = p->left;
		free(d);
		cout << "������� ������\n" << endl;
		return true;
	}
	else
	{
		p->element = deletemin(p->right);
		return true;
	}
}

// �������� ������������ ��������
int bstree::deletemin(nodeptr &p)
{
	int c;
	cout << "������� �������� ������������ ��������\n" << endl;
	if (p->left == NULL)
	{
		c = p->element;
		p = p->right;
		return c;
	}
	else
	{
		c = deletemin(p->left);
		return c;
	}
}
void bstree::set_a(int p) {
	string b;
	b = string(this->get_a());
	b += " ";
	b += p;
	this->a_str = NULL;
	this->a_str = new char[b.length()];
	this->a_str = b.data();
	//(b.c_str());
}
// �������������� �����
void bstree::inorder(nodeptr p)
{
	if (p != NULL)
	{
		inorder(p->left);
		this->set_a(p->element);
		//cout << p->element << "\t";
		inorder(p->right);
	}
}
int bstree::bsheight(nodeptr p)
{
	int t;
	if (p == NULL)
	{
		return -1;
	}
	else
	{
		t = p->height;
		return t;
	}
}

nodeptr bstree::srl(nodeptr &p1) // ����� ����� ��������
{
	nodeptr p2;
	p2 = p1->left;
	p1->left = p2->right;
	p2->right = p1;
	p1->height = fmax(bsheight(p1->left), bsheight(p1->right)) + 1;
	p2->height = fmax(bsheight(p2->left), p1->height) + 1;
	return p2;
}
nodeptr bstree::srr(nodeptr &p1) // ����� ������ ��������
{
	nodeptr p2;
	p2 = p1->right;
	p1->right = p2->left;
	p2->left = p1;
	p1->height = fmax(bsheight(p1->left), bsheight(p1->right)) + 1;
	p2->height = fmax(p1->height, bsheight(p2->right)) + 1;
	return p2;
}
nodeptr bstree::drl(nodeptr &p1) // ������� ����� ��������
{
	p1->left = srr(p1->left);
	return srl(p1);
}
nodeptr bstree::drr(nodeptr &p1) // ������� ������ ��������
{
	p1->right = srl(p1->right);
	return srr(p1);
}

//int main()
//{
//	setlocale(LC_ALL, "Russian");
//
//	nodeptr root, min, max;
//	int choice, findele, delele;
//	char ch = 'y';
//	bstree bst;
//	int *a;
//	root = NULL;
//	cout << "\n\t\t\t\t��� ������" << endl;
//	cout << "\t\t\t\t:::::::::::::::::::\n" << endl;
//
//
//	do
//	{
//		cout << "\t\t::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
//		cout << "\t\t::::1 ��������� ������ ����������� r ���������� ������ �������::" << endl;
//		cout << "\t\t::::2 ����� ����������� �������:::::::::::" << endl;
//		cout << "\t\t::::3 ����� ������������ �������:::::::::::::::" << endl;
//		cout << "\t\t::::4 ����� �� ��������:::::::::::::::::::" << endl;
//		cout << "\t\t::::5 ������� �������:::::::::::::::::::" << endl;
//		//		cout << "\t\t::::6 ������� ������1:::::::::::::::::" << endl;
//		//		cout << "\t\t::::7 ������� ������2::::::::::::::::::" << endl;
//		//		cout << "\t\t::::8 ������� ������3::::::::::::::::" << endl;
//		cout << "\t\t::::9 �������� ������ ������:::" << endl;
//		cout << "\t\t::::0 �����:::::::::::::::::::::::::::::" << endl;
//		cout << "\t\t::::::::::::::::::::::::::::::::::::::::::::::::\n" << endl;
//
//		cout << "\n�������� ������ �������� � ������� Enter: ";
//		cin >> choice;
//
//		switch (choice)
//		{
//		case 1:
//			cout << "������� ����������� ������: ";
//			int n;
//			cin >> n;
//			a = new int[n];
//			int i;
//
//			for (i = 0; i < n; i++) {
//				a[i] = 1 + rand() % 10000;
//				bst.insert(a[i], root);
//			}
//
//			cout << "\n�������� ��������� � ������\n" << endl;
//			delete[] a;
//			break;
//		case 4:
//			cout << "\n������� ������� �������: ";
//			cin >> findele;
//			if (root != NULL)
//			{
//				bool flag = bst.find(findele, root);
//			}
//			break;
//		case 5:
//			cout << "\n����� ���� �������? : ";
//			cin >> delele;
//			bst.del(delele, root);
//			bst.inorder(root);
//			cout << endl;
//			break;
//		case 7:
//			cout << "\n\t\t������� ������2" << endl;
//			bst.inorder(root);
//			cout << endl;
//			break;
//		case 9:
//			cout << "\n\t\t������\n" << endl;
//			cout << "T������ ����� ������: " << bst.bsheight(root) << endl;
//			break;
//		case 0:
//			break;
//		default:
//			cout << "�������� ��������\n" << endl;
//			break;
//		}
//		system("pause");
//		system("cls");
//	} while (choice != 0);
//	return 0;
//}