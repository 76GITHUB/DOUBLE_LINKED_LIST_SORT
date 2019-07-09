#pragma once //헤더의 중복 선언을 막겠다
#include <iostream>
using namespace std;

#define NAME_SIZE 16 //이름사이즈 매크로 정의
static int stunum = 1; //학번에 넣기위한 전역변수 값1

enum MODE { //메인메뉴의 모드
	MODE_I = 1,//학생정보입력
	MODE_V,//등록된 학생보기
	MODE_S,//학생검색
	MODE_D,//학생삭제
	MODE_J,//학생정렬
	MODE_E //종료
};

enum VIEW { //보기메뉴
	V_JUNG=1,//정방향
	V_YUCK//역방향
};

enum SORT {//정렬
	S_N=1,//학번기준
	S_A//평균기준
};

typedef struct _tagStudent {  //학생구조체
	char strName[NAME_SIZE] = {}; //학생이름
	int iNumber; //학번
	int iKor;//국어
	int iEng;//영어
	int iMath;//수학
	int iTotal;//총점
	int iAvg;//평균
}STUDENT, *PSTUDENT;

typedef struct _tagNode { //노드 구조체
	STUDENT tStudent; //데이터부분
	_tagNode* pNext; //다음노드
	_tagNode* pPrev; //이전노드
}NODE, *PNODE;

typedef struct _tagList { //리스트구조체
	PNODE pHead; //머리
	PNODE pEnd; //꼬리
	int iSize; //사이즈
}LIST, *PLIST;

int Input(int i); //숫자를 입력받기위한 함수,점수 등등
void Cinput(char* string, int Size);//문자열을 입력받기위한 함수
void SetList(PLIST pList);//리스트를 세팅하기위한 함수
int MainMenu();//메인메뉴를 출력하기위한 함수
void ClearNode(PLIST pList);//힙영역에 동적할당된 노드의 메모리들을 안전하게 해제하는 함수
void SetNode(PLIST pLIST);//노드를 추가해주는함수
void OutPutStudent(const PSTUDENT pStudent);//학생정보를 출력하는함수
void ViewNode(PLIST pList);//노드에 저장된 데이터부분을 보기위한 함수,더블링크드리스에선1.정방향,2.역방향출력을 제공
void SerchNode(PLIST pList);//노드를 탐색하기위한 함수
void DeleteNode(PLIST pList);//노드를 삭제하기위한 함수
void Sort(PLIST pList);//리스트 정렬을 위한 함수