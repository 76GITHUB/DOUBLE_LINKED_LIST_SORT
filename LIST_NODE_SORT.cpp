#include "LIST.h"


int Input(int i) {
	if (i == 0) { //���θ޴� ���� ���ڸ� �Է¹޴°��
		int num;
		cin >> num;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			return INT_MAX;
		}
		return num;
	}
	else if (i == 1) { //������ �Է¹޴°��
		while (1) {
			int num2;
			cin >> num2;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				num2 = INT_MAX;
			}

			if (num2 == INT_MAX || num2 < 0 || num2>100) {//������ 0�����۰ų� 100���� Ŭ������
				cout << "�߸��Է��ϼ̽��ϴ�,�ٽ��Է��ϼ���:";
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
	pList->pHead = new NODE;//�̱۸�ũ�帮���ʹ� �ٸ��� �����Ҵ����ش�.
	pList->pEnd = new NODE;//������ �Ϲݳ��ó�� �����͸� �����Ҹ����̾ƴ� �ܼ��� ����,������ ����ų �����̴�.
	pList->pHead->pNext = pList->pEnd;//�ƹ���嵵�߰��Ǿ������ʴٸ�,�Ӹ��� ������ ����Ų��.
	pList->pEnd->pPrev = pList->pHead;//�ƹ���嵵�߰��Ǿ������ʴٸ�,�����¸Ӹ��� ����Ų��.
	pList->pHead->pPrev = NULL;//�翬���Ӹ��պκ��� NULL
	pList->pEnd->pNext = NULL;//�翬�������ڴ� NULL
}

int MainMenu() {
	while (1) {
		system("cls");
		cout << "============�л� ���� ���α׷�===============" << endl;
		cout << "1.�л��߰�" << endl;
		cout << "2.��ϵ��л�����" << endl;
		cout << "3.�л��˻�" << endl;
		cout << "4.�л�����" << endl;
		cout << "5.�л�����" << endl;
		cout << "6.����" << endl;
		cout << "�Է��ϼ���:";
		int imenu;
		imenu = Input(0);
		if (imenu == INT_MAX || imenu<MODE_I || imenu>MODE_E) {
			cout << endl;
			cout << "�߸��Է��ϼ̽��ϴ�.";
			system("pause");
			continue;
		}
		else
			return imenu;
	}
}

void ClearNode(PLIST pList) {
	PNODE pNode = pList->pHead;
	while (pNode != NULL) { //�����尡 NULL�̾ƴ϶��
		PNODE pNext = pNode->pNext; //pNext��� ������ �������� ������带 ����
		delete pNode; //�׸��� �����带 ����
		pNode = pNext;//�Ʊ������صξ��� '�������'�� ���� �����尡 �Ǵ°��̴�.�տ��ִ°� �����ǰ�
	}                  //�ڿ����ִ����� ������ �¼�
					   //while���� �������Դٴ°��� ��尡 ���λ����Ȱ��̰�
	pList->pHead = NULL; //�׷����� �ٽ� �Ӹ���NULL
	pList->pEnd = NULL; //������ NULL
	pList->iSize = 0; //����� ������ �翬�� 0��
}

void SetNode(PLIST pList) {
	system("cls");
	STUDENT tStudent = {};
	cout << "�л� �̸�:";
	Cinput(tStudent.strName, NAME_SIZE);
	tStudent.iNumber = stunum;
	++stunum;
	cout << "�л� ��������:";
	tStudent.iKor = Input(1);
	cout << "�л� ��������:";
	tStudent.iEng = Input(1);
	cout << "�л� ��������:";
	tStudent.iMath = Input(1);

	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
	tStudent.iAvg = (tStudent.iKor + tStudent.iEng + tStudent.iMath) / 3.f;


	PNODE pNode = new NODE; //��带 ����(�����Ҵ�) �� ������ �޸𸮰� �Ҵ�ǰ� �������ֱ������� �����ְԵ�
	pNode->tStudent = tStudent; //�л������� �־��ش�.

	PNODE pPrev = pList->pEnd->pPrev;//�����߰��� ��带 ���� �������� �������־���ϱ⶧���� ����������带 ������������
    
	pPrev->pNext = pNode;// pPev -> ����� 
	pNode->pPrev = pPrev;// pPrev <- �����
	pNode->pNext = pList->pEnd;// �����-> ����
	pList->pEnd->pPrev = pNode;// ����� <- ����

	++pList->iSize; //��尡 �߰��ɶ����� ����� �ϳ����þ����
	++tStudent.iNumber;//�й�����
}

void OutPutStudent(const PSTUDENT pStudent) {
	cout << "=============�л��������================" << endl;
	cout << "�л��̸�:" << pStudent->strName << endl;
	cout << "�л��й�:" << pStudent->iNumber << endl;
	cout << "�л���������:" << pStudent->iKor << endl;
	cout << "�л���������:" << pStudent->iEng << endl;
	cout << "�л���������:" << pStudent->iMath << endl;
	cout << "�л�����:" << pStudent->iTotal << endl;
	cout << "�л��������:" << pStudent->iAvg << endl;
}

void ViewNode(PLIST pList) {
	int menu;
	while (1) {
	system("cls");
	cout << "=============�л��������================" << endl;
	cout << "1.�л� ������ ���" << endl;
	cout << "2.�л� ������ ���" << endl;
	cout << "�Է��ϼ���";
		 menu = Input(0);
		if (menu == INT_MAX || menu<V_JUNG || menu>V_YUCK) {
			continue;
			cout << "�߸� �Է� �Ͽ����ϴ�" << endl;
			system("pause");
		}
		break;
	}
	system("cls");
	PNODE pNode = NULL;
	switch (menu)
	{
	case V_JUNG:
		pNode = pList->pHead->pNext; //���� �Ӹ��� �������̿� ������ �׷����� �Ǿճ���, �Ӹ� ������
		while (pNode !=pList->pEnd) {
			OutPutStudent(&pNode->tStudent); //�׸��� �������� �л� ������ ���
			pNode = pNode->pNext;//���� �����忡 ������带 ���� ,���� ���� �Ѿ�ٴ� ����
		}
		break;
	case V_YUCK:
		 pNode = pList->pEnd->pPrev; //����������̴� ��������������
		while (pNode != pList->pHead) {
			OutPutStudent(&pNode->tStudent); //�׸��� �������� �л� ������ ���
			pNode = pNode->pPrev;//���� �����忡 ������带 ���� ,���� ���� �Ѿ�ٴ� ����
		}
		break;
	}
	cout << "������:" << pList->iSize << "��" << endl;//�̵Ǿ� while���� ���������Ե�
	return;
}

void SerchNode(PLIST pList) {
	system("cls");
	cout << "=============�л��˻�================" << endl;
	cout << "�˻��� �л��� �̸��� �Է��ϼ���.";
	char str[NAME_SIZE] = {};
	Cinput(str, NAME_SIZE);
	/*�ϴ�.. �ʱ��带 �Ǿ����� �����ϴ�������
	���Ḯ��Ʈ�� �迭ó�� Ư���ε����� �ٷ����� �Ҽ��ִ� ���� �ƴ϶�
	����Ʈ���� ���������� �Ǿ��ְ�, ������ ó������ ���������� ������ ������ �Ǳ� �����̴�*/
	PNODE pNode = pList->pHead->pNext;
	while (pNode !=pList->pEnd) {
		if (strcmp(pNode->tStudent.strName, str) == 0) {//�������� �����ͺκп�����л��̸��� �Է��� �л��̸��̰��ٸ�
			OutPutStudent(&pNode->tStudent);//���л��� ������ ���
			return; //��������� �Լ��� ��������
		}
		pNode = pNode->pNext; //�׷����ʴٸ� �������γѾ
	}//��带�Ѿ�� ��������忡 ���������� �ᱹ pNext=NULL�̰� �̰���pNode�� �����ϰԵǾ����� while���� ��������
	cout << "�˻��� �л��� ã���� �����ϴ�.";//�̷�������while���� �������Դٴ°��� ����ǵ����ͺκп� �л��̸���
								//�Է��� �л��̸��� ������츦 ã�� �� ���°���.
	return;
}

void DeleteNode(PLIST pList) {
	system("cls");
	cout << "=============�л�����================" << endl;
	cout << "������ �л��� �̸��� �Է��ϼ���.";
	char str[NAME_SIZE] = {};
	Cinput(str, NAME_SIZE);
	PNODE pNode = pList->pHead->pNext;
	while (pNode !=pList->pEnd) {
		if (strcmp(pNode->tStudent.strName, str) == 0) {
			pNode->pPrev->pNext = pNode->pNext;
			pNode->pNext->pPrev = pNode->pPrev;
			delete pNode;
			--pList->iSize;
			cout << "�л������Ϸ�" << endl;
			return;
		}	
		pNode = pNode->pNext;
	}
	cout << "������ �л��� ã�� �������ϴ�" << endl;
	return;
}

void Sort(PLIST pList) {
	int menu;
	while (1) {
		system("cls");
		cout << "=============�л� ����================" << endl;
		cout << "1.�й����� ����" << endl;
		cout << "2.��ձ��� ����" << endl;
		cout << "�Է��ϼ���";
		menu = Input(0);
		if (menu == INT_MAX || menu<S_N || menu>S_A) {
			continue;
			cout << "�߸� �Է� �Ͽ����ϴ�" << endl;
			system("pause");
		}
		break;
	}
	system("cls");
	PNODE pFirst = pList->pHead->pNext;
	PNODE pSecond = pFirst->pNext;

	if (pFirst == NULL|| pSecond==NULL) {
		cout << "������ �л��� �����ϴ�." << endl;
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

				if (pFirstNext != pSecond) { //�ٲٴ´���� �پ����� �������
					pFirstNext->pPrev = pSecond;
					pSecond->pNext = pFirstNext;

					pSecondPrev->pNext = pFirst;
					pFirst->pPrev = pSecondPrev;
				}
				else { //�ٲٴ´���� �پ��ִ� ���
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
	cout << "������ �Ϸ�Ǿ����ϴ�" << endl;
}