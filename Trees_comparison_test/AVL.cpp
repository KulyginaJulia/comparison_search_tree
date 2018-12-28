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

// Вставка элемента
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
			cout << "Нет места\n" << endl;
		}
	}
	else
	{
		if (x < p->element) // Балансировка
		{
			insert(x, p->left);
			if ((bsheight(p->left) - bsheight(p->right)) == 2) // Проверка bfactor
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
			//cout << "Элемет существует\n" << endl;
		}
	}
	int m, n, d;
	m = bsheight(p->left);
	n = bsheight(p->right);
	d = fmax(m, n);
	p->height = d + 1;
}

// Поиск заданного элемента
bool bstree::find(int x, nodeptr &p)
{
	if (p == NULL)
	{
		cout << "Sorry.Простите, но такого элемента нет\n" << endl;
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
				cout << "Finded.Элемент, который вы искали есть в дереве!\n" << endl;
				return true;
			}
		}
	}
}

// Удаление элемента
bool bstree::del(int x, nodeptr &p)
{
	nodeptr d;
	if (p == NULL)
	{
		cout << "Простите, но такого элемента нет\n" << endl;
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
		cout << "Элемент удален\n" << endl;
		return true;
	}
	else if (p->left == NULL)
	{
		d = p;
		free(d);
		p = p->right;
		cout << "Элемент удален\n" << endl;
		return true;
	}
	else if (p->right == NULL)
	{
		d = p;
		p = p->left;
		free(d);
		cout << "Элемент удален\n" << endl;
		return true;
	}
	else
	{
		p->element = deletemin(p->right);
		return true;
	}
}

// Удаление минимального элемента
int bstree::deletemin(nodeptr &p)
{
	int c;
	cout << "Выбрано удаление минимального значения\n" << endl;
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
// Центрированный обход
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

nodeptr bstree::srl(nodeptr &p1) // Малое левое вращение
{
	nodeptr p2;
	p2 = p1->left;
	p1->left = p2->right;
	p2->right = p1;
	p1->height = fmax(bsheight(p1->left), bsheight(p1->right)) + 1;
	p2->height = fmax(bsheight(p2->left), p1->height) + 1;
	return p2;
}
nodeptr bstree::srr(nodeptr &p1) // Малое правое вращение
{
	nodeptr p2;
	p2 = p1->right;
	p1->right = p2->left;
	p2->left = p1;
	p1->height = fmax(bsheight(p1->left), bsheight(p1->right)) + 1;
	p2->height = fmax(p1->height, bsheight(p2->right)) + 1;
	return p2;
}
nodeptr bstree::drl(nodeptr &p1) // Большое левое вращение
{
	p1->left = srr(p1->left);
	return srl(p1);
}
nodeptr bstree::drr(nodeptr &p1) // Большое правое вращение
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
//	cout << "\n\t\t\t\tАВЛ Дерево" << endl;
//	cout << "\t\t\t\t:::::::::::::::::::\n" << endl;
//
//
//	do
//	{
//		cout << "\t\t::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
//		cout << "\t\t::::1 Заполнить дерево размерности r случайными целыми числами::" << endl;
//		cout << "\t\t::::2 Найти минимальный элемент:::::::::::" << endl;
//		cout << "\t\t::::3 Найти максимальный элемент:::::::::::::::" << endl;
//		cout << "\t\t::::4 Поиск по значению:::::::::::::::::::" << endl;
//		cout << "\t\t::::5 Удалить элемент:::::::::::::::::::" << endl;
//		//		cout << "\t\t::::6 Вариант обхода1:::::::::::::::::" << endl;
//		//		cout << "\t\t::::7 Вариант обхода2::::::::::::::::::" << endl;
//		//		cout << "\t\t::::8 Вариант обхода3::::::::::::::::" << endl;
//		cout << "\t\t::::9 Показать высоту дерева:::" << endl;
//		cout << "\t\t::::0 Выход:::::::::::::::::::::::::::::" << endl;
//		cout << "\t\t::::::::::::::::::::::::::::::::::::::::::::::::\n" << endl;
//
//		cout << "\nВыберите нужное действие и нажмите Enter: ";
//		cin >> choice;
//
//		switch (choice)
//		{
//		case 1:
//			cout << "Введите размерность дерева: ";
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
//			cout << "\nЭлементы добавлены в дерево\n" << endl;
//			delete[] a;
//			break;
//		case 4:
//			cout << "\nВведите искомый элемент: ";
//			cin >> findele;
//			if (root != NULL)
//			{
//				bool flag = bst.find(findele, root);
//			}
//			break;
//		case 5:
//			cout << "\nКакой узел удалять? : ";
//			cin >> delele;
//			bst.del(delele, root);
//			bst.inorder(root);
//			cout << endl;
//			break;
//		case 7:
//			cout << "\n\t\tВариант обхода2" << endl;
//			bst.inorder(root);
//			cout << endl;
//			break;
//		case 9:
//			cout << "\n\t\tВЫСОТА\n" << endl;
//			cout << "TДерево имеет высоту: " << bst.bsheight(root) << endl;
//			break;
//		case 0:
//			break;
//		default:
//			cout << "Неверное значение\n" << endl;
//			break;
//		}
//		system("pause");
//		system("cls");
//	} while (choice != 0);
//	return 0;
//}