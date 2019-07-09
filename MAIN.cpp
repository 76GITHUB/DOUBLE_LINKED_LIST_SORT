#include "LIST.h"

int main() {
	LIST tList;

	SetList(&tList);
	while (1) {
		int mode = MainMenu();

		if (mode == MODE_E)
			break;
		switch (mode)
		{
		case MODE_I:
			SetNode(&tList);
			break;
		case MODE_V:
			ViewNode(&tList);
			system("pause");
			break;
		case MODE_S:
			SerchNode(&tList);
			system("pause");
			break;
		case MODE_D:
			DeleteNode(&tList);
			system("pause");
			break;
		case MODE_J:
			Sort(&tList);
			system("pause");
			break;
		}
	}
	ClearNode(&tList);
}