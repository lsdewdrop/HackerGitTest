#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

//	�� ������ �ذ����� ������, �ش� �������� commit �� ��.
//	commit �޽����� �����Ӱ� �ص� �˴ϴ�.
	  struct subject 
	  {
          string itemName;
          int score;
      };
      struct student 
	  {
          string name;		// �л��̸�
          int subjectCount;	// ���ð����
          subject* pItem;		// ���� ���
      };

int main()
{
	//	1��
	//	0~99 ������ ������ ���� 100���� �����ϰ�, ������������ �����Ͽ� ����Ͻÿ�.
	//	��, ��� ������ int�� �����͸� ����� ��.

	srand(time(NULL));
	int* arrr=new int[100];
	for(int i=0; i<100; i++)
	{
		arrr[i]=rand()%100;
	}
	for(int i=0; i<100; i++)
	{
		for(int j=0;j<100; j++)
		{
			if(arrr[i]<arrr[j])
			{
				int temp=arrr[j];
				arrr[j]=arrr[i];
				arrr[i]=temp;
			}
		}
	}
	for(int i=0; i<100; i++)
	{
		cout<<arrr[i]<<endl;
	}
	

	//	2��
	//	���(Person)�� ��Ÿ�� Ŭ������ �ۼ��Ͻÿ�. Person.h, Person.cpp ������ ����� ������ ��.
	//	��� ����, �Լ��� public���� �����ϰ� �� ��.
	//	�������
	//		�̸�(name)			: string
	//		����(age)			: int
	//		���翩��(isAlive)	: bool
	//	����Լ�
	//		���ϱ�(talk)			: "Hello, world!"�� ����Ѵ�.
	//		���ڱ�(sleep)		: "zzz"�� ����Ѵ�.






	//  3��
	//	�� ���� ���� �ý���
    //  �л�(student)�� ���� ����ü�� ���ð���(item)�� ���� ����ü�� �����.
    //
    //  list.txt ������ �о�鿩 main���� student* �����͸� �̿��Ͽ� �ο����� �����Ҵ�
    //  ���� ���ð��񺰷� subject�� ���� �����Ҵ��� �����Ѵ�.
    //  ���Ͽ��� ��� �����͸� �о��ٸ�
    //  �� ������ "�� �����ο�: 00��" �� ǥ���ϰ�,
    //  �л��̸�: �̸� / ���ð����: 0�� / ����1: 00, ����2: 00, ����3: 00 ...
    //  �� ���� �÷� ����Ѵ�.
    //
    //  �߰��� ���� �����Ϳ� �Ѹ� ���� �ֿܼ��� �߰��Ͽ�
    //  �� �����ο��� ���ο� �л��� ���� ������ ����ϴ� �ڵ带 ������ ��!
    //
    //  struct subject {
    //      string itemName;
    //      int score;
    //  };
    //  struct student {
    //      string name;		// �л��̸�
    //      int subjectCount;	// ���ð����
    //      subject* pItem;		// ���� ���
    //  };

	student Student[10];


	ifstream list;
	list.open("list.txt", ios::in);

	int i = 0;

	while (!list.eof())
	{

	list >> Student[i].name >> Student[i].subjectCount;

	Student[i].pItem = new subject[Student[i].subjectCount];

	for (int j = 0; j < Student[i].subjectCount; j++)
	{
	list >> Student[i].pItem[j].itemName >> Student[i].pItem[j].score;
	}

	i++;

	}

	cout <<"�̸��� ������� �Է����ּ���"<<endl;

	cin >> Student[i].name >> Student[i].subjectCount;

	Student[i].pItem = new subject[Student[i].subjectCount];

	cout << "����� �������� �Է����ּ���" << endl;

	for (int j = 0; j < Student[i].subjectCount; j++)
	{
		cin >> Student[i].pItem[j].itemName >> Student[i].pItem[j].score;
	}

	for (int k = 0; k < i + 1; k++)
	{
		cout << " �л��̸�: " << Student[k].name << " ���� �����: " << Student[k].subjectCount << " ";

		for (int j = 0; j < Student[k].subjectCount; j++)
		{
			cout << Student[k].pItem[j].itemName << " : " << Student[k].pItem[j].score << " ";
		}

		cout << endl;

	}


	list.close();
	
	//	4��
	//	�����ڿ��� �ϰ���� ���� �����ÿ�.
	//	
	// �� �����󰡴� �л� ���������� �������ҰԿ�!
	return 0;
}