#include <vector>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int razA, razB;
	cout << "Введите , если хотите задать множество поэлеметно, или 2, если хотите задать множество выражением" << endl;
	int choice = 0;
	cin >> choice;
	switch (choice)
	{
	case 1: // 4.1.2
		cout << "введите размерность множества A" << endl; // 4.1.2.1
		cin >> razA;
		cout << "введите размерность множества B" << endl; // 4.1.2.2
		cin >> razB;
		vector<int> a; // 4.1.2.3
		vector<int> b; // 4.1.2.4
		for (int i = 0; i < razA; i++) // 4.1.2.5
		{
			cout << "введите элемент множества A номер" << ' ' << i + 1 << endl;
			int in;
			cin >> in;
			a.push_back(in);
		}
		for (int i = 0; i < razB; i++) //  4.1.2.6
		{
			cout << "введите элемент множества B номер" << ' ' << i + 1 << endl;
			int in;
			cin >> in;
			b.push_back(in);
		}
		break;
	default: // 4.1.3
		cout << "Введите число k - количество членов в многочлене";
		int k;
		cin >> k;
		cout << "Введите нижнюю границу x: ";
		int d;
		cin >> d;
		cout << "Введите верхнюю границу x:";
		int h;
		cin >> h;
		int s{ 1 };
		...
	}
	cout << "Выберите операцию: 1-объединение, 2-пересечение, 3-разность, 4-дополнение, 5-симметр. разность, 6-декартово произвед." << endl;
	cin >> choice; //выбор операции
	vector<int> c;
}