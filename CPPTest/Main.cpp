#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

//	각 문제를 해결했을 때마다, 해당 시점에서 commit 할 것.
//	commit 메시지는 자유롭게 해도 됩니다.
	  struct subject 
	  {
          string itemName;
          int score;
      };
      struct student 
	  {
          string name;		// 학생이름
          int subjectCount;	// 응시과목수
          subject* pItem;		// 과목 목록
      };

int main()
{
	//	1번
	//	0~99 범위의 임의의 정수 100개를 저장하고, 오름차순으로 정렬하여 출력하시오.
	//	단, 모든 변수는 int형 포인터만 사용할 것.

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
	

	//	2번
	//	사람(Person)을 나타낼 클래스를 작성하시오. Person.h, Person.cpp 파일을 만들어 구현할 것.
	//	모든 변수, 함수는 public으로 접근하게 할 것.
	//	멤버변수
	//		이름(name)			: string
	//		나이(age)			: int
	//		생사여부(isAlive)	: bool
	//	멤버함수
	//		말하기(talk)			: "Hello, world!"를 출력한다.
	//		잠자기(sleep)		: "zzz"를 출력한다.






	//  3번
	//	반 성적 관리 시스템
    //  학생(student)에 대한 구조체와 응시과목(item)에 대한 구조체를 만든다.
    //
    //  list.txt 파일을 읽어들여 main에서 student* 포인터를 이용하여 인원별로 동적할당
    //  또한 응시과목별로 subject에 대한 동적할당을 구현한다.
    //  파일에서 모든 데이터를 읽었다면
    //  맨 위에는 "총 응시인원: 00명" 을 표시하고,
    //  학생이름: 이름 / 응시과목수: 0개 / 과목1: 00, 과목2: 00, 과목3: 00 ...
    //  와 같은 꼴로 출력한다.
    //
    //  추가로 현재 데이터에 한명만 직접 콘솔에서 추가하여
    //  총 응시인원과 새로운 학생에 대한 점수를 출력하는 코드를 만들어보실 것!
    //
    //  struct subject {
    //      string itemName;
    //      int score;
    //  };
    //  struct student {
    //      string name;		// 학생이름
    //      int subjectCount;	// 응시과목수
    //      subject* pItem;		// 과목 목록
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

	cout <<"이름과 과목수를 입력해주세요"<<endl;

	cin >> Student[i].name >> Student[i].subjectCount;

	Student[i].pItem = new subject[Student[i].subjectCount];

	cout << "과목과 과목점수 입력해주세요" << endl;

	for (int j = 0; j < Student[i].subjectCount; j++)
	{
		cin >> Student[i].pItem[j].itemName >> Student[i].pItem[j].score;
	}

	for (int k = 0; k < i + 1; k++)
	{
		cout << " 학생이름: " << Student[k].name << " 응시 과목수: " << Student[k].subjectCount << " ";

		for (int j = 0; j < Student[k].subjectCount; j++)
		{
			cout << Student[k].pItem[j].itemName << " : " << Student[k].pItem[j].score << " ";
		}

		cout << endl;

	}


	list.close();
	
	//	4번
	//	교육자에게 하고싶은 말을 적으시오.
	//	
	// 잘 못따라가는 학생 부족하지만 열심히할게요!
	return 0;
}