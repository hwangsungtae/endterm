﻿#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "ヘッダー.h"
#define CHARBUFF 124
#define max 100
int data[max][4];
int yourhp;
int enemyhp;

int main()
{
	
	getdata();

	hp();

	while (1) {
		int i;
		printf("行動を数字で入力してください\n");
		printf("attack:1\ndeffense:2\nheal:3\n");
		fscanf_s(stdin, "%d", &i);
		if (i > 3) {
			printf("表示されている数字を入力してください\n");
			continue;
		}
		move(i);
		enemy();

		if (yourhp <= 0) {
			printf("あなたは力尽きた");
			return 0;
		}
		else if (enemyhp <= 0) {
			printf("あなたは戦いに勝利した");
			return 0;
		}
	}
}

