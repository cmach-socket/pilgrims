#pragma once
int gongji(int, int, int, int, int, int);
void fanci(int, int, int, int, int, int);
void isdie(int, int, int);
int addxb(int, int);


int gongji(int a, int b, int c, int aa, int bb, int cc) {//�������� 
	if (bing[a][b][c].xue <= 0 or bing[aa][bb][cc].xue <= 0) {
		printf("�����߻����ܻ���Ϊ�ջ���Ѫ������!\n");
		Sleep(1000);
		return 0;
	}
	if (bing[a][b][c].gongji == 0) {
		printf("����Ϊ0,�޷�����!\n");
		Sleep(1000);
		return 0;
	}
	if (bing[a][b][c].lingjcs <= 0) {
		printf("�Ѿ���������\n");
		Sleep(1000);
		return 0;
	}
	if (kqian[aa] > 0) {
		if (!bing[aa][bb][cc].qianfeng) {
			printf("�ȹ���ǰ�����\n");
			Sleep(1000);
			return 0;
		}
	}
	int she = 0;//ʵ������ 
	for (int i = 1; i <= bb; i++) {
		if (vis[aa][i][cc])she++;
	}
	if (bing[a][b][c].shecheng < she) {
		printf("��̲���\n");
		Sleep(1000);
		return 0;
	}
	if (bing[aa][bb][cc].bihu) {//�ӻ���� 
		bing[aa][bb][cc].bihu = 0;
		bing[a][b][c].lingjcs--;
		if (!bing[a][b][c].dianji)fanci(a, b, c, aa, bb, cc);
		return 1;
	}
	bing[a][b][c].xue += bing[a][b][c].xixue;//��Ѫ��� 
	if (bing[a][b][c].xue > bing[a][b][c].maxxue)bing[a][b][c].xue = bing[a][b][c].maxxue;
	if (!bing[a][b][c].boolpojia and bing[aa][bb][cc].dun > 0) {//������� 
		bing[aa][bb][cc].dun -= bing[a][b][c].gongji;
	}
	else {
		bing[aa][bb][cc].xue -= bing[a][b][c].gongji;
	}
	bing[a][b][c].lingjcs--;
	if (!bing[a][b][c].dianji)fanci(a, b, c, aa, bb, cc);//������ 
	else isdie(aa, bb, cc);
	if (bing[a][b][c].xue > bing[a][b][c].maxxue)bing[a][b][c].xue = bing[a][b][c].maxxue;
	if (bing[aa][bb][cc].xue > bing[aa][bb][cc].maxxue)bing[aa][bb][cc].xue = bing[aa][bb][cc].maxxue;
	return 1;
}
void fanci(int a, int b, int c, int aa, int bb, int cc) {//���̺��� 
	int she = 0;
	for (int i = 1; i <= b; i++) {
		if (vis[a][i][c])she++;
	}
	if (bing[aa][bb][cc].shecheng < she) {
		isdie(a, b, c);
		isdie(aa, bb, cc);
		return;
	}
	if (bing[a][b][c].bihu) {
		bing[a][b][c].bihu = 0;
		isdie(a, b, c);
		isdie(aa, bb, cc);
		return;
	}
	if (!bing[aa][bb][cc].boolpojia and bing[a][b][c].dun > 0) {
		bing[a][b][c].dun -= bing[aa][bb][cc].fanci;
	}
	else {
		bing[a][b][c].xue -= bing[aa][bb][cc].fanci;
	}
	isdie(a, b, c);
	isdie(aa, bb, cc);
	return;
}
void isdie(int a, int b, int c) {//�ж����� 
	if (bing[a][b][c].xue > 0) {//��Ѫ���� 
		return;
	}
	bing[a][b][c].yuannian();//�ͷ�Թ�� 
	dead[++deadk] = bing[a][b][c].bian;
	if (bing[a][b][c].qianfeng) {
		kqian[a]--;
	}
	bing[a][b][c] = NULLB, vis[a][b][c] = 0;
	for (int i = c + 1; i <= k[a][b]; i++) {//���������ƶ� 
		if (vis[a][b][i]) {
			bing[a][b][i - 1] = bing[a][b][i], vis[a][b][i - 1] = 1;
			bing[a][b][i - 1].c = i - 1;
			bing[a][b][i] = NULLB, vis[a][b][i] = 0;
		}
	}
	k[a][b]--;
	return;
}
int addxb(int bought, int pl) {//����ʿԱ 
	bing[pl][xblist[bought].paishu][++k[pl][xblist[bought].paishu]] = xblist[bought];//��ֵ�ϳ� 
	vis[pl][xblist[bought].paishu][k[pl][xblist[bought].paishu]] = 1; //ȷ����ʿԱ�Ŵ� 
	if (xblist[bought].qianfeng)kqian[pl]++;//ǰ��ʿԱ�������� 
	bing[pl][xblist[bought].paishu][k[pl][xblist[bought].paishu]].jineng();//�ͷ������� 
	bing[pl][xblist[bought].paishu][k[pl][xblist[bought].paishu]].a = pl;
	bing[pl][xblist[bought].paishu][k[pl][xblist[bought].paishu]].b = xblist[bought].paishu;
	bing[pl][xblist[bought].paishu][k[pl][xblist[bought].paishu]].c = k[pl][xblist[bought].paishu];
	//��¼��a b c 
	return 1;
}