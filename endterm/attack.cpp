#include <stdio.h>
#include "�w�b�_�[.h"

void move(int i) {
	if (i == 1) {
        Sleep(500);
        printf("�����%d�̃_���[�W\n", data[1][1]);
        Sleep(500);
        enemyhp -= data[1][1];
	   
	}
	else if (i == 2) {
        int defenseflag = 1;

	}
	else {

	}
}

void enemy() {
    int moveflag;
    moveflag=(rand() % 3 + 1);
    if (moveflag == 1) {
        Sleep(500);
        printf("���Ȃ���%d�̃_���[�W\n", data[0][1]);
        Sleep(500);
        yourhp -= data[0][1];

    }
    else if (moveflag == 2) {
        Sleep(500);
        printf("���Ȃ���%d�̃_���[�W\n", data[0][1]);
        Sleep(500);
        yourhp -= data[0][1];
    }
    else {
        Sleep(500);
        printf("���Ȃ���%d�̃_���[�W\n", data[0][1]);
        Sleep(500);
        yourhp -= data[0][1];
    }
}

void CSV2Array(const char* filename, int data[max][4]) {

    FILE* fp;
    char s[BUFFSIZE];
    errno_t error;
    char delim[] = ",";//�f���~�^�i�����n����j�����ł̓J���}�Ƌ�
    char* ctx;
    char* ary[6];
    char* a;
    int i = 0;
    int index = 0;

    error = fopen_s(&fp, filename, "r");
    if (error != 0)
        fprintf_s(stderr, "failed to open");
    else {
        while (fgets(s, BUFFSIZE, fp) != NULL) {
            ary[0] = strtok_s(s, ",", &ctx);
            ary[1] = strtok_s(NULL, ",", &ctx);
            ary[2] = strtok_s(NULL, ",", &ctx);
            if (index > 0) {
                data[i][0] = atoi(ary[0]);
                data[i][1] = atoi(ary[1]);
                data[i][2] = atoi(ary[2]);

                i++;
            }
            index++;




        }
        fclose(fp);


    }

}
void getGurrentDirectory(char* currentDirectory) {
    GetCurrentDirectory(CHARBUFF, currentDirectory);
}

void hp() {
    yourhp = data[0][0];
    enemyhp = data[1][0];
}

void getdata() {
    char currentDirectory[CHARBUFF];
    getGurrentDirectory(currentDirectory);
    char section[CHARBUFF];
    sprintf_s(section, "section");
    char keyWord[CHARBUFF];
    sprintf_s(keyWord, "keyword");
    char settingFile[CHARBUFF];
    sprintf_s(settingFile, "%s\\setting.ini", currentDirectory);
    char keyValue[CHARBUFF];
    if (GetPrivateProfileString(section, keyWord, "none", keyValue, CHARBUFF, settingFile) != 0) {
        fprintf(stdout, "%s , %s\n", settingFile, keyValue);
    }
    else {
        fprintf(stdout, "%s doesn't contain [$s] %s\n", settingFile, section, keyWord);
    }

    CSV2Array(keyValue, data);
}