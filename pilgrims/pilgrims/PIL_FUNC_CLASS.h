#pragma once
void tmpyuan(int a, int b, int c) {//��ͨԹ��� 
	return;
}
void tmpji(int a, int b, int c) {//��ͨ������ 
	return;
}
void tmphui(int a, int b, int c) {//��ͨŭ������ 
	return;
}
void hui7(int a, int b, int c) {//7ʿԱŭ������ 
	if (player != a) {
		return;
	}
	if (bing[a][b][c].tmp[1] == 0) {
		bing[a][b][c].tmp[1] = 1;
		return;
	}
	bing[a][b][c].gongji += 4;
	bing[a][b][c].fanci += 4;
	return;
}
void hui12(int a, int b, int c) {//12ʿԱŭ������ 
	usefa[!a] = 1;
	return;
}
void yuan13(int a, int b, int c) {//13ʿԱԹ��� 
	if (bing[!a][3][1].xue > 0) {
		bing[!a][3][1].xue = 0;
		isdie(!a, 3, 1);
	}
}
void ji16(int a, int b, int c) {//16ʿԱ������ 
	abc tmp(0, 0, 0);
	while (1) {
		tmp = wasdin("ѡ�����ӹ�����ʿԱ");
		if (bing[tmp.a][tmp.b][tmp.c].xue <= 0) {
			printf("�ܻ���Ϊ�ջ���Ѫ������!\n");
			Sleep(1000);
			continue;
		}
		break;
	}
	bing[tmp.a][tmp.b][tmp.c].gongji += 5;
	bing[tmp.a][tmp.b][tmp.c].fanci += 5;
	return;
}
void yuan17(int a, int b, int c) {//17ʿԱԹ��� 
	pxue[a] -= 3;
	if (pxue[a] <= 0)sxb[a] = 1;
}
void yuan19(int a, int b, int c) {//19ʿԱԹ��� 
	addxb(20, a);
	return;
}
void ji23(int a, int b, int c) {//23ʿԱ������ 
	while (1) {
		bing[a][b][c].tmp[1] = input<int>("1.�����Ѫ����������� 2.����߹������������");
		if (bing[a][b][c].tmp[1] == 1) {
			bing[a][b][c].xue = bing[a][b][c - 1].xue;
			bing[a][b][c].maxxue = bing[a][b][c - 1].maxxue;
			break;
		}
		else if (bing[a][b][c].tmp[1] == 2) {
			bing[a][b][c].gongji = bing[a][b][c - 1].gongji;
			bing[a][b][c].fanci = bing[a][b][c - 1].fanci;
			break;
		}
		else {
			printf("��������!\n");
		}
	}
}
void ji24(int a, int b, int c) {//24ʿԱ������
	ndian[a] -= 1;
}
void ji25(int a, int b, int c) {//25ʿԱ������
	if (deadk <= 0)return;
	abc tmp=addxb( dead[deadk], a);
	bing[tmp.a][tmp.b][tmp.c].xue=1;
	deadk--;
}
void hui26(int a, int b, int c) {//26ʿԱŭ������
	if (bing[a][b][c].xue <= 5) {
		bing[a][b][c].gongji = 15;
	}
}
void fa1() {//1001����ʹ�ú��� 
	abc tmp(0,0,0);
	while (1) {
		tmp = wasdin("ѡ�񱻹�����һ��ʿԱ");
		if (tmp.b> 2) {
			printf("������ʿԱ������2��!\n");
			Sleep(1000);
			continue;
		}
		if (bing[tmp.a][tmp.b][tmp.c].xue <= 0) {
			printf("�ܻ���Ϊ�ջ���Ѫ������!\n");
			Sleep(1000);
			continue;
		}
		break;
	}
	if (bing[tmp.a][tmp.b][tmp.c].bihu) {
		bing[tmp.a][tmp.b][tmp.c].bihu = 0;
		return;
	}
	if (bing[tmp.a][tmp.b][tmp.c].dun > 0) {
		bing[tmp.a][tmp.b][tmp.c].dun -= 5;
	}
	else {
		bing[tmp.a][tmp.b][tmp.c].xue -= 5;
		isdie(tmp.a, tmp.b, tmp.c);
	}
	
	return;
}
void fa2() {//1002����ʹ�ú��� 
	abc tmp(0, 0, 0);
	while (1) {
		tmp = wasdin("ѡ�񱻹�����һ��ʿԱ");
		if (tmp.b > 2) {
			printf("������ʿԱ������2��!\n");
			Sleep(1000);
			continue;
		}
		if (bing[tmp.a][tmp.b][tmp.c].xue <= 0) {
			printf("�ܻ���Ϊ�ջ���Ѫ������!\n");
			Sleep(1000);
			continue;
		}
		break;
	}
	if (bing[tmp.a][tmp.b][tmp.c].bihu) {
		bing[tmp.a][tmp.b][tmp.c].bihu = 0;
		return;
	}
	if (bing[tmp.a][tmp.b][tmp.c].dun > 0) {
		bing[tmp.a][tmp.b][tmp.c].dun -= 1;
	}
	else {
		bing[tmp.a][tmp.b][tmp.c].xue -= 1;
		isdie(tmp.a, tmp.b, tmp.c);
	}
	return;
}
void fa3() {//1003����ʹ�ú��� 
	ndian[player] -= 30;
	for (int i = 1; i <= MAXP - 1; i++) {
		for (int j = 1; j <= k[0][i]; j++) {
			if (vis[0][i][j]) {
				bing[0][i][j].xue = -1000;
				//isdie(0, i, j);
			}
		}
	}
	for (int i = 1; i <= MAXP - 1; i++) {
		for (int j = 1; j <= k[1][i]; j++) {
			if (vis[1][i][j]) {
				bing[1][i][j].xue = -1000;
				//isdie(1, i, j);
			}
		}
	}
	for (int k = 0; k <= 1; k++) {
		for (int i = 1; i <= MAXP - 1; i++) {
			for (int j = 1; j <= MAXN; j++) {
				if (vis[k][i][1]) {
					isdie(k, i, 1);
				}
			}
		}
	}
	
}
void fa4() {//1004����ʹ�ú��� 
	for (int i = 1; i <= MAXP - 1; i++) {
		for (int j = k[0][i]; j >= 1; j--) {
			if (vis[0][i][j]) {
				bing[0][i][j].xue -= 1;
				isdie(0, i, j);
			}
		}
	}
	for (int i = 1; i <= MAXP - 1; i++) {
		for (int j = k[1][i]; j >= 1; j--) {
			if (vis[1][i][j]) {
				bing[1][i][j].xue -= 1;
				isdie(1, i, j);
			}
		}
	}
}
void fa5() {//1005����ʹ�ú��� 
	abc tmp(0, 0, 0);
	while (1) {
		tmp = wasdin("ѡ��������̵�ʿԱ");
		if (bing[tmp.a][tmp.b][tmp.c].xue <= 0) {
			printf("�ܻ���Ϊ�ջ���Ѫ������!\n");
			Sleep(1000);
			continue;
		}
		break;
	}
	bing[tmp.a][tmp.b][tmp.c].shecheng++;
	return;
}
void fa6() {//1006����ʹ�ú���
	abc tmp(0, 0, 0);
	while (1) {
		tmp = wasdin("ѡ�񱻱��̵�ʿԱ");
		if (bing[tmp.a][tmp.b][tmp.c].xue <= 0) {
			printf("�ܻ���Ϊ�ջ���Ѫ������!\n");
			Sleep(1000);
			continue;
		}
		if (tmp.a != player) {
			printf("�Ǽ���ʿԱ!");
			Sleep(1000);
			continue;
		}
		break;
	}
	bing[tmp.a][tmp.b][tmp.c].xue -= 1;
	usefa[player] = 0;
	isdie(tmp.a, tmp.b, tmp.c);
}
void fa7() {//1007����ʹ�ú���
	abc tmp(0, 0, 0);
	while (1) {
		tmp = wasdin("ѡ�񱻹�����ʿԱ");
		if (bing[tmp.a][tmp.b][tmp.c].xue <= 0) {
			printf("�ܻ���Ϊ�ջ���Ѫ������!\n");
			Sleep(1000);
			continue;
		}
		break;
	}
	bing[tmp.a][tmp.b][tmp.c].hui = tmphui;
}
void wu1() {//2001����ʹ�ú��� 
	abc tmp(0, 0, 0);
	while (1) {
		tmp = wasdin("ѡ�񱻹�����һ��ʿԱ");
		if (tmp.b > 2) {
			printf("������ʿԱ������2��!\n");
			Sleep(1000);
			continue;
		}
		if (bing[tmp.a][tmp.b][tmp.c].xue <= 0) {
			printf("�ܻ���Ϊ�ջ���Ѫ������!\n");
			Sleep(1000);
			continue;
		}
		break;
	}
	if (bing[tmp.a][tmp.b][tmp.c].bihu) {
		bing[tmp.a][tmp.b][tmp.c].bihu = 0;
		return;
	}
	if (bing[tmp.a][tmp.b][tmp.c].dun > 0) {
		bing[tmp.a][tmp.b][tmp.c].dun -= 5;
	}
	else {
		bing[tmp.a][tmp.b][tmp.c].xue -= 5;
		isdie(tmp.a, tmp.b, tmp.c);
	}

	return;
}
void wu2() {//2002����ʹ�ú��� 
	abc tmp(0, 0, 0);
	while (1) {
		tmp = wasdin("ѡ�����Ƶ�һ��ʿԱ");
		if (tmp.b > 2) {
			printf("������ʿԱ������2��!\n");
			Sleep(1000);
			continue;
		}
		if (bing[tmp.a][tmp.b][tmp.c].xue <= 0) {
			printf("��������Ϊ�ջ���Ѫ������!\n");
			Sleep(1000);
			continue;
		}
		break;
	}
	bing[tmp.a][tmp.b][tmp.c].xue += 5;
	if (bing[tmp.a][tmp.b][tmp.c].xue > bing[tmp.a][tmp.b][tmp.c].maxxue)bing[tmp.a][tmp.b][tmp.c].xue = bing[tmp.a][tmp.b][tmp.c].maxxue;
	return;
}