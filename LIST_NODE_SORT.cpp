#include "LIST.h"


int Input(int i) {
	if (i == 0) { //메인메뉴 에서 숫자를 입력받는경우
		int num;
		cin >> num;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			return INT_MAX;
		}
		return num;
	}
	else if (i == 1) { //점수를 입력받는경우
		while (1) {
			int num2;
			cin >> num2;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				num2 = INT_MAX;
			}

			if (num2 == INT_MAX || num2 < 0 || num2>100) {//점수는 0보다작거나 100보다 클수없다
				cout << "잘못입력하셨습니다,다시입력하세요:";
				continue;
			}
			else
				return num2;
		}
	}
}

void Cinput(char* string, int Size) {
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(string, Size - 1);
}

void SetList(PLIST pList) { 
	pList->iSize = 0;
	pList->pHead = new NODE;//싱글링크드리스와는 다르게 동적할당해준다.
	pList->pEnd = new NODE;//하지만 일반노드처럼 데이터를 저장할목적이아닌 단순히 이전,다음을 가르킬 목적이다.
	pList->pHead->pNext = pList->pEnd;//아무노드도추가되어있지않다면,머리는 꼬리를 가르킨다.
	pList->pEnd->pPrev = pList->pHead;//아무노드도추가되어있지않다면,꼬리는머리를 가르킨다.
	pList->pHead->pPrev = NULL;//당연히머리앞부분은 NULL
	pList->pEnd->pNext = NULL;//당연히꼬리뒤는 NULL
}

int MainMenu() {
	while (1) {
		system("cls");
		cout << "============학생 관리 프로그램===============" << endl;
		cout << "1.학생추가" << endl;
		cout << "2.등록된학생보기" << endl;
		cout << "3.학생검색" << endl;
		cout << "4.학생삭제" << endl;
		cout << "5.학생정렬" << endl;
		cout << "6.종료" << endl;
		cout << "입력하세요:";
		int imenu;
		imenu = Input(0);
		if (imenu == INT_MAX || imenu<MODE_I || imenu>MODE_E) {
			cout << endl;
			cout << "잘못입력하셨습니다.";
			system("pause");
			continue;
		}
		else
			return imenu;
	}
}

void ClearNode(PLIST pList) {
	PNODE pNode = pList->pHead;
	while (pNode != NULL) { //현재노드가 NULL이아니라면
		PNODE pNext = pNode->pNext; //pNext라는 공간에 현재노드의 다음노드를 저장
		delete pNode; //그리고 현재노드를 삭제
		pNode = pNext;//아까저장해두었던 '다음노드'가 이제 현재노드가 되는것이다.앞에있는게 삭제되고
	}                  //뒤에서있던놈이 앞으로 온셈
					   //while문을 빠져나왔다는것은 노드가 전부삭제된것이고
	pList->pHead = NULL; //그럼이제 다시 머리는NULL
	pList->pEnd = NULL; //꼬리도 NULL
	pList->iSize = 0; //노드의 갯수도 당연히 0개
}

void SetNode(PLIST pList) {
	system("cls");
	STUDENT tStudent = {};
	cout << "학생 이름:";
	Cinput(tStudent.strName, NAME_SIZE);
	tStudent.iNumber = stunum;
	++stunum;
	cout << "학생 국어점수:";
	tStudent.iKor = Input(1);
	cout << "학생 영어점수:";
	tStudent.iEng = Input(1);
	cout << "학생 수학점수:";
	tStudent.iMath = Input(1);

	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
	tStudent.iAvg = (tStudent.iKor + tStudent.iEng + tStudent.iMath) / 3.f;


	PNODE pNode = new NODE; //노드를 생성(동적할당) 힙 영역에 메모리가 할당되고 해제해주기전까진 남아있게됨
	pNode->tStudent = tStudent; //학생정보를 넣어준다.

	PNODE pPrev = pList->pEnd->pPrev;//새로추가될 노드를 엔드 이전노드와 연결해주어야하기때문에 꼬리이전노드를 따로저장해줌
    
	pPrev->pNext = pNode;// pPev -> 새노드 
	pNode->pPrev = pPrev;// pPrev <- 새노드
	pNode->pNext = pList->pEnd;// 새노드-> 꼬리
	pList->pEnd->pPrev = pNode;// 새노드 <- 꼬리

	++pList->iSize; //노드가 추가될때마다 사이즈도 하나씩늘어나야함
	++tStudent.iNumber;//학번증가
}

void OutPutStudent(const PSTUDENT pStudent) {
	cout << "=============학생정보출력================" << endl;
	cout << "학생이름:" << pStudent->strName << endl;
	cout << "학생학번:" << pStudent->iNumber << endl;
	cout << "학생국어점수:" << pStudent->iKor << endl;
	cout << "학생영어점수:" << pStudent->iEng << endl;
	cout << "학생수학점수:" << pStudent->iMath << endl;
	cout << "학생총점:" << pStudent->iTotal << endl;
	cout << "학생평균점수:" << pStudent->iAvg << endl;
}

void ViewNode(PLIST pList) {
	int menu;
	while (1) {
	system("cls");
	cout << "=============학생정보출력================" << endl;
	cout << "1.학생 정방향 출력" << endl;
	cout << "2.학생 역방향 출력" << endl;
	cout << "입력하세요";
		 menu = Input(0);
		if (menu == INT_MAX || menu<V_JUNG || menu>V_YUCK) {
			continue;
			cout << "잘못 입력 하였습니다" << endl;
			system("pause");
		}
		break;
	}
	system("cls");
	PNODE pNode = NULL;
	switch (menu)
	{
	case V_JUNG:
		pNode = pList->pHead->pNext; //노드는 머리와 꼬리사이에 생성됨 그럼으로 맨앞노드는, 머리 다음임
		while (pNode !=pList->pEnd) {
			OutPutStudent(&pNode->tStudent); //그리고 현재노드의 학생 정보를 출력
			pNode = pNode->pNext;//이제 현재노드에 다음노드를 저장 ,다음 노드로 넘어갔다는 뜻임
		}
		break;
	case V_YUCK:
		 pNode = pList->pEnd->pPrev; //역방향출력이니 꼬리이전노드부터
		while (pNode != pList->pHead) {
			OutPutStudent(&pNode->tStudent); //그리고 현재노드의 학생 정보를 출력
			pNode = pNode->pPrev;//이제 현재노드에 이전노드를 저장 ,이전 노드로 넘어갔다는 뜻임
		}
		break;
	}
	cout << "힉생수:" << pList->iSize << "명" << endl;//이되어 while문을 빠져나오게됨
	return;
}

void SerchNode(PLIST pList) {
	system("cls");
	cout << "=============학생검색================" << endl;
	cout << "검색할 학생의 이름을 입력하세요.";
	char str[NAME_SIZE] = {};
	Cinput(str, NAME_SIZE);
	/*일단.. 초기노드를 맨앞으로 설정하는이유는
	연결리스트는 배열처럼 특정인덱스로 바로접근 할수있는 것이 아니라
	리스트들은 선형구조로 되어있고, 무조건 처음부터 순차적으로 접근해 나가야 되기 때문이다*/
	PNODE pNode = pList->pHead->pNext;
	while (pNode !=pList->pEnd) {
		if (strcmp(pNode->tStudent.strName, str) == 0) {//현재노드의 데이터부분에담긴학생이름과 입력한 학생이름이같다면
			OutPutStudent(&pNode->tStudent);//그학생의 정보를 출력
			return; //출력했으니 함수를 빠져나감
		}
		pNode = pNode->pNext; //그렇지않다면 다음노드로넘어감
	}//노드를넘어가다 마지막노드에 도달했을땐 결국 pNext=NULL이고 이것을pNode에 저장하게되었을때 while문을 빠져나옴
	cout << "검색한 학생을 찾을수 없습니다.";//이런식으로while문을 빠져나왔다는것은 노드의데이터부분에 학생이름과
								//입력한 학생이름이 같은경우를 찾을 수 없는경우다.
	return;
}

void DeleteNode(PLIST pList) {
	system("cls");
	cout << "=============학생삭제================" << endl;
	cout << "삭제할 학생의 이름을 입력하세요.";
	char str[NAME_SIZE] = {};
	Cinput(str, NAME_SIZE);
	PNODE pNode = pList->pHead->pNext;
	while (pNode !=pList->pEnd) {
		if (strcmp(pNode->tStudent.strName, str) == 0) {
			pNode->pPrev->pNext = pNode->pNext;
			pNode->pNext->pPrev = pNode->pPrev;
			delete pNode;
			--pList->iSize;
			cout << "학생삭제완료" << endl;
			return;
		}	
		pNode = pNode->pNext;
	}
	cout << "삭제할 학생을 찾을 수없습니다" << endl;
	return;
}

void Sort(PLIST pList) {
	int menu;
	while (1) {
		system("cls");
		cout << "=============학생 정렬================" << endl;
		cout << "1.학번기준 정렬" << endl;
		cout << "2.평균기준 정렬" << endl;
		cout << "입력하세요";
		menu = Input(0);
		if (menu == INT_MAX || menu<S_N || menu>S_A) {
			continue;
			cout << "잘못 입력 하였습니다" << endl;
			system("pause");
		}
		break;
	}
	system("cls");
	PNODE pFirst = pList->pHead->pNext;
	PNODE pSecond = pFirst->pNext;

	if (pFirst == NULL|| pSecond==NULL) {
		cout << "정렬할 학생이 없습니다." << endl;
		return;
	}


	bool swap = false;
	while (pFirst != pList->pEnd->pPrev) {
		pSecond = pFirst->pNext;
		while (pSecond != pList->pEnd) {
			switch (menu)
			{
			case S_N:
				if (pFirst->tStudent.iNumber > pSecond->tStudent.iNumber) {
					swap = true;
				}
				break;
			case S_A:
				if (pFirst->tStudent.iAvg > pSecond->tStudent.iAvg) {
					swap = true;
				}
				break;
			}
			if (swap) {
				PNODE pFirstPrev = pFirst->pPrev;
				PNODE pFirstNext = pFirst->pNext;

				PNODE pSecondPrev = pSecond->pPrev;
				PNODE pSecondNext = pSecond->pNext;

				if (pFirstNext != pSecond) { //바꾸는대상이 붙어있지 않은경우
					pFirstNext->pPrev = pSecond;
					pSecond->pNext = pFirstNext;

					pSecondPrev->pNext = pFirst;
					pFirst->pPrev = pSecondPrev;
				}
				else { //바꾸는대상이 붙어있는 경우
					pSecond->pNext = pFirst;
					pFirst->pPrev = pSecond;
				}
				pFirst->pNext = pSecondNext;
				pSecondNext->pPrev = pFirst;

				pFirstPrev->pPrev = pSecond;
				pSecond->pPrev = pFirstPrev;

				PNODE pTemp = pFirst;
				pFirst = pSecond;
				pSecond = pTemp;
			}
			pSecond = pSecond->pNext;
		}
		pFirst = pFirst->pNext;
	}
	cout << "정렬이 완료되었습니다" << endl;
}