#include<iostream>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#define SIZE 4 // ����� ���� ������ ��� 4
using namespace std;
enum moveKey{ KeyUp = 'w', KeyLeft = 'a', KeyRight = 'd', KeyDown = 's' };//������� ���� ��� ������ moveKey
void printTable(char arr[SIZE][SIZE]); //�. ������ ������� � ����������, ����������� 2-������ ������ 4�4
void initTable(char arr[SIZE][SIZE]);//�. ������������� ������� � �����������, ����������� 2-����. ������ 4�4
void randTable(char arr[SIZE][SIZE], int numStep);// ������������ �������, � ����������� (2-����.�., ������� ����������)
void makeMove(char arr[SIZE][SIZE], moveKey key); // �. (2-����.�., ��� moveKey ����������)
void locateSpace(int &row, int &col, char arr[SIZE][SIZE]); //�. (������� ����� ������, ������� ����� �������, ������ 2-�. �. 4�4)
bool userWin(char arr[SIZE][SIZE]);//���.(������� �. 4�4)
void main()
{
	char table[SIZE][SIZE];//������� 2����. �. 4�4
	initTable(table);//����� �. � ���������� table, �.�. ������� �� ������� ����
	randTable(table, 40);//������������(�������, 40 - ��� ����� ��������)
	while (true)//����������� ����
	{
		printTable(table);//�. ������ ����. � ���������� ��������� �������
		int move = getch();//������� ������� �������, ����� �������� ��� ���������� ���������� ��������. ������, ������, 
							//��������� � ����������, �� ������ �� ������������.
		makeMove(table, (moveKey)move);//�������� �. (2�2 ����., ����������� � ���� moveKey ���������� move)
		move = 0; //move �������
		if (userWin(table)) //���� ������������ �������(�������� - �������)
		{
			break;//�����
		}
	}
	cout << "WIN!!!" << endl; //������� ������� � ������

}
bool userWin(char arr[SIZE][SIZE])//���. �. � ���. ������� 2�2
{
	int inc = 0;//������� �����. int � ���������������� 0
	char temp[SIZE][SIZE] = {//������� �. � ����. 2�2
		{ '1', '2', '3', '4' },
		{ '5', '6', '7', '8' },
		{ '9', 'A', 'B', 'C' },
		{ 'D', 'E', 'F', ' ' },
	};
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (arr[i][j] == temp[i][j])//���� ������� � ������� ����� �������� �� ��������� �������
			{
				inc++;//� ����� ���������� ����.
			}
		}
	}
	if (inc == SIZE*SIZE)//���� inc ����� ���������� ��������� �� ���� ����. 16
	{
		return true;//1
	}
	else{
		return false;
	}
}
void initTable(char arr[SIZE][SIZE])
{
	const char temp[SIZE][SIZE] = {
		{ '1', '2', '3', '4' },
		{ '5', '6', '7', '8' },
		{ '9', 'A', 'B', 'C' },
		{ 'D', 'E', 'F', ' ' },
	};
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr[i][j] = temp[i][j];
		}
	}
}
void printTable(char arr[SIZE][SIZE])
{
	system("cls");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

}
void randTable(char arr[SIZE][SIZE], int numStep)
{
	srand(time(NULL));
	for (int i = 0; i < numStep; i++)
	{
		int move = rand() % 4;
		switch (move)
		{
		case 0:
			makeMove(arr, KeyUp);
			break;
		case 1:
			makeMove(arr, KeyDown);
			break;
		case 2:
			makeMove(arr, KeyLeft);
			break;
		case 3:
			makeMove(arr, KeyRight);
			break;
		default:
			break;
		}
	}
}
void locateSpace(int &row, int &col, char arr[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (arr[i][j] == ' ')
			{
				row = i;
				col = j;
				return;
			}
		}
	}
}
void makeMove(char arr[SIZE][SIZE], moveKey key)
{
	int rowsSpace;
	int colSpace;
	locateSpace(rowsSpace, colSpace, arr);
	int rowCurrent = rowsSpace;//��������� ������ �������
	int colCurrent = colSpace;
	switch (key)
	{
	case KeyUp:
	{
				  rowCurrent -= 1;
	}
		break;
	case KeyLeft:
	{
					colCurrent -= 1;
	}
		break;
	case KeyRight:
	{
					 colCurrent += 1;
	}
		break;
	case KeyDown:
	{
					rowCurrent += 1;
	}
		break;
	}
	if (rowCurrent >= 0 && rowCurrent<SIZE && colCurrent >= 0 && colCurrent<SIZE)//������ ������� ������ � �������� �������
	{
		char temp = arr[rowCurrent][colCurrent];
		arr[rowCurrent][colCurrent] = arr[rowsSpace][colSpace];
		arr[rowsSpace][colSpace] = temp;
	}
}