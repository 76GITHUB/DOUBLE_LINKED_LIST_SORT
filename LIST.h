#pragma once //����� �ߺ� ������ ���ڴ�
#include <iostream>
using namespace std;

#define NAME_SIZE 16 //�̸������� ��ũ�� ����
static int stunum = 1; //�й��� �ֱ����� �������� ��1

enum MODE { //���θ޴��� ���
	MODE_I = 1,//�л������Է�
	MODE_V,//��ϵ� �л�����
	MODE_S,//�л��˻�
	MODE_D,//�л�����
	MODE_J,//�л�����
	MODE_E //����
};

enum VIEW { //����޴�
	V_JUNG=1,//������
	V_YUCK//������
};

enum SORT {//����
	S_N=1,//�й�����
	S_A//��ձ���
};

typedef struct _tagStudent {  //�л�����ü
	char strName[NAME_SIZE] = {}; //�л��̸�
	int iNumber; //�й�
	int iKor;//����
	int iEng;//����
	int iMath;//����
	int iTotal;//����
	int iAvg;//���
}STUDENT, *PSTUDENT;

typedef struct _tagNode { //��� ����ü
	STUDENT tStudent; //�����ͺκ�
	_tagNode* pNext; //�������
	_tagNode* pPrev; //�������
}NODE, *PNODE;

typedef struct _tagList { //����Ʈ����ü
	PNODE pHead; //�Ӹ�
	PNODE pEnd; //����
	int iSize; //������
}LIST, *PLIST;

int Input(int i); //���ڸ� �Է¹ޱ����� �Լ�,���� ���
void Cinput(char* string, int Size);//���ڿ��� �Է¹ޱ����� �Լ�
void SetList(PLIST pList);//����Ʈ�� �����ϱ����� �Լ�
int MainMenu();//���θ޴��� ����ϱ����� �Լ�
void ClearNode(PLIST pList);//�������� �����Ҵ�� ����� �޸𸮵��� �����ϰ� �����ϴ� �Լ�
void SetNode(PLIST pLIST);//��带 �߰����ִ��Լ�
void OutPutStudent(const PSTUDENT pStudent);//�л������� ����ϴ��Լ�
void ViewNode(PLIST pList);//��忡 ����� �����ͺκ��� �������� �Լ�,����ũ�帮������1.������,2.����������� ����
void SerchNode(PLIST pList);//��带 Ž���ϱ����� �Լ�
void DeleteNode(PLIST pList);//��带 �����ϱ����� �Լ�
void Sort(PLIST pList);//����Ʈ ������ ���� �Լ�