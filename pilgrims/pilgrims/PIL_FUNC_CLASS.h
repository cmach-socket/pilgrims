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
	int aa, cc, bb;
	while (1) {
		aa = input<int>("����ѡ�����ӹ�����ʿԱ��Ӫ(�繥�����2������2)");
		if (aa == 2)aa = 0;
		bb = input<int>("���뱻���ӹ�����ʿԱ������: ");
		cc = input<int>("���뱻���ӹ�����ʿԱ���к�: ");
		if (bing[aa][bb][cc].xue <= 0) {
			printf("�ܻ���Ϊ�ջ���Ѫ������!\n");
			continue;
		}
		break;
	}
	bing[aa][bb][cc].gongji += 5;
	bing[aa][bb][cc].fanci += 5;
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
	int tmp=addxb( dead[deadk], a);
	bing[a][xblist[dead[deadk]].paishu][tmp].xue=1;
	deadk--;
}
void fa1() {//1001����ʹ�ú��� 
	int aa, cc, bb;
	while (1) {
		aa = input<int>("����ѡ�񱻹�����ʿԱ��Ӫ(�繥�����2������2)");
		if (aa == 2)aa = 0;
		bb = input<int>("���뱻������ʿԱ������: ");
		if (bb > 2) {
			printf("������ʿԱ������2��!\n");
			continue;
		}
		cc = input<int>("���뱻������ʿԱ���к�: ");
		if (bing[aa][bb][cc].xue <= 0) {
			printf("�ܻ���Ϊ�ջ���Ѫ������!\n");
			continue;
		}
		break;
	}
	bing[aa][bb][cc].gongji -= 5;
	bing[aa][bb][cc].fanci -= 5;
	return;
}
void fa2() {//1002����ʹ�ú��� 
	int aa, cc, bb = 1;
	while (1) {
		aa = input<int>("����ѡ�񱻹�����1��ʿԱ��Ӫ(�繥�����2������2)");
		if (aa == 2)aa = 0;
		cc = input<int>("���뱻������1��ʿԱ���к�: ");
		if (bing[aa][bb][cc].xue <= 0) {
			printf("�ܻ���Ϊ�ջ���Ѫ������!\n");
			continue;
		}
		break;
	}
	if (bing[aa][bb][cc].bihu) {
		bing[aa][bb][cc].bihu = 0;
		return;
	}
	if (bing[aa][bb][cc].dun > 0) {
		bing[aa][bb][cc].dun -= 1;
	}
	else {
		bing[aa][bb][cc].xue -= 1;
	}
	isdie(aa, bb, cc);
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
		for (int j = 1; j <= k[0][i]; j++) {
			if (vis[0][i][j]) {
				bing[0][i][j].xue -= 1;
				isdie(0, i, j);
			}
		}
	}
	for (int i = 1; i <= MAXP - 1; i++) {
		for (int j = 1; j <= k[1][i]; j++) {
			if (vis[1][i][j]) {
				bing[1][i][j].xue -= 1;
				isdie(1, i, j);
			}
		}
	}
}
void fa5() {//1005����ʹ�ú��� 
	int aa, cc, bb;
	while (1) {
		aa = input<int>("����ѡ��������̵�ʿԱ��Ӫ(�繥�����2������2)");
		if (aa == 2)aa = 0;
		bb = input<int>("���뱻������̵�ʿԱ������: ");
		cc = input<int>("���뱻������̵�ʿԱ���к�: ");
		if (bing[aa][bb][cc].xue <= 0) {
			printf("�ܻ���Ϊ�ջ���Ѫ������!\n");
			continue;
		}
		break;
	}
	bing[aa][bb][cc].shecheng++;
	return;
}
void fa6() {//1006����ʹ�ú���
	int aa, cc, bb;
	aa = player;
	while (1) {
		bb = input<int>("���뱳�̵�ʿԱ������: ");
		cc = input<int>("���뱳�̵�ʿԱ���к�: ");
		if (bing[aa][bb][cc].xue <= 0) {
			printf("�ܻ���Ϊ�ջ���Ѫ������!\n");
			continue;
		}
		break;
	}
	bing[aa][bb][cc].xue -= 1;
	isdie(aa, bb, cc);
}
void wu1() {//2001����ʹ�ú��� 
	int aa, cc, bb = 1;
	while (1) {
		aa = input<int>("����ѡ�񱻹�����1��ʿԱ��Ӫ(�繥�����2������2)");
		if (aa == 2)aa = 0;
		cc = input<int>("���뱻������1��ʿԱ���к�: ");
		if (bing[aa][bb][cc].xue <= 0) {
			printf("�ܻ���Ϊ�ջ���Ѫ������!\n");
			continue;
		}
		break;
	}
	if (bing[aa][bb][cc].bihu) {
		bing[aa][bb][cc].bihu = 0;
		return;
	}
	if (bing[aa][bb][cc].dun > 0) {
		bing[aa][bb][cc].dun -= 5;
	}
	else {
		bing[aa][bb][cc].xue -= 5;
	}
	isdie(aa, bb, cc);
	return;
}
void wu2() {//2002����ʹ�ú��� 
	int aa, cc, bb = 1;
	while (1) {
		aa = input<int>("����ѡ�����Ƶ�1��ʿԱ��Ӫ(�繥�����2������2)");
		if (aa == 2)aa = 0;
		cc = input<int>("���뱻���Ƶ�1��ʿԱ���к�: ");
		if (bing[aa][bb][cc].xue <= 0) {
			printf("�ܻ���Ϊ�ջ���Ѫ������!\n");
			continue;
		}
		break;
	}
	bing[aa][bb][cc].xue += 5;
	if (bing[aa][bb][cc].xue > bing[aa][bb][cc].maxxue)bing[aa][bb][cc].xue = bing[aa][bb][cc].maxxue;
	return;
}