#include <vector>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int razA, razB;
	cout << "������� , ���� ������ ������ ��������� ����������, ��� 2, ���� ������ ������ ��������� ����������" << endl;
	int choice = 0;
	cin >> choice;
	switch (choice)
	{
	case 1: // 4.1.2
		cout << "������� ����������� ��������� A" << endl; // 4.1.2.1
		cin >> razA;
		cout << "������� ����������� ��������� B" << endl; // 4.1.2.2
		cin >> razB;
		vector<int> a; // 4.1.2.3
		vector<int> b; // 4.1.2.4
		for (int i = 0; i < razA; i++) // 4.1.2.5
		{
			cout << "������� ������� ��������� A �����" << ' ' << i + 1 << endl;
			int in;
			cin >> in;
			a.push_back(in);
		}
		for (int i = 0; i < razB; i++) //  4.1.2.6
		{
			cout << "������� ������� ��������� B �����" << ' ' << i + 1 << endl;
			int in;
			cin >> in;
			b.push_back(in);
		}
		break;
	default: // 4.1.3
		cout << "������� ����� k - ���������� ������ � ����������";
		int k;
		cin >> k;
		cout << "������� ������ ������� x: ";
		int d;
		cin >> d;
		cout << "������� ������� ������� x:";
		int h;
		cin >> h;
		int s{ 1 };
		...
	}
	cout << "�������� ��������: 1-�����������, 2-�����������, 3-��������, 4-����������, 5-�������. ��������, 6-��������� ��������." << endl;
	cin >> choice; //����� ��������
	vector<int> c;
}