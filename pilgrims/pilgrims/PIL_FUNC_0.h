#pragma once
int gongji(int, int, int, int, int, int);
void fanci(int, int, int, int, int, int);
void isdie(int, int, int);
abc addxb(int, int);
void useji();
void flip();
void _move();
void isbreak(int);
abc wasdin();


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
abc addxb(int bought, int pl) {//����ʿԱ 
	bing[pl][xblist[bought].paishu][++k[pl][xblist[bought].paishu]] = xblist[bought];//��ֵ�ϳ� 
	vis[pl][xblist[bought].paishu][k[pl][xblist[bought].paishu]] = 1; //ȷ����ʿԱ�Ŵ� 
	if (xblist[bought].qianfeng)kqian[pl]++;//ǰ��ʿԱ�������� 
	bing[pl][xblist[bought].paishu][k[pl][xblist[bought].paishu]].a = pl;
	bing[pl][xblist[bought].paishu][k[pl][xblist[bought].paishu]].b = xblist[bought].paishu;
	bing[pl][xblist[bought].paishu][k[pl][xblist[bought].paishu]].c = k[pl][xblist[bought].paishu];
	//��¼��a b c 
	bing[pl][xblist[bought].paishu][k[pl][xblist[bought].paishu]].jineng();//�ͷ������� 
	abc tmp(pl, xblist[bought].paishu, k[pl][xblist[bought].paishu]);
	return tmp;
}
 void useji() {
	 for (int i = 1; i <= MAXP - 1; i++) {
		 for (int j = 1; j <= k[player][i]; j++) {
			 if (vis[player][i][j]) {
				 bing[player][i][j].huihe();
				 bing[player][i][j].lingjcs = bing[player][i][j].gjcishu;
			 }
		 }
	 }
	 for (int i = 1; i <= MAXP - 1; i++) {
		 for (int j = 1; j <= k[!player][i]; j++) {
			 if (vis[!player][i][j]) {
				 bing[!player][i][j].huihe();
				 bing[!player][i][j].lingjcs = bing[player][i][j].gjcishu;
			 }
		 }
	 }
	 return;
 }
 void flip() {
	 system("cls");
	 printf("���1 %s������:    %sѪ��%d ����:%d ����:%s �;�:%d\n", p[1].c_str()
		 , p[1].c_str()
		 , pxue[1]
		 , ndian[1]
		 , pwuqi[1].name.c_str()
		 , pwuqi[1].naiju);
	 for (int i = MAXP - 1; i > 0; i--) {
		 printf("%d: ", i);
		 //printf("%d",k[1][i]);
		 for (int j = 1; j <= k[1][i]; j++) {
			 printf("%d.%c%s%c%d %c%d ", j
				 , wasd[1][i][j] ? '*' : '\0'
				 , bing[1][i][j].name.c_str()
				 , bing[1][i][j].xue >= 10 ? '\0' : '0'
				 , bing[1][i][j].xue
				 , bing[1][i][j].gongji >= 10 or bing[1][i][j].gongji < 0 ? '\0' : '0'
				 , bing[1][i][j].gongji);
		 }
		 printf("\n");
	 }
	 printf("-----------------------------------------------------------------------------------------------------------------------\n");
	 for (int i = 1; i <= MAXP - 1; i++) {
		 printf("%d: ", i);
		 for (int j = 1; j <= k[0][i]; j++) {
			 printf("%d.%c%s%c%d %c%d ", j
				 , wasd[0][i][j] ? '*' : '\0'
				 , bing[0][i][j].name.c_str()
				 , bing[0][i][j].xue >= 10 ? '\0' : '0'
				 , bing[0][i][j].xue
				 , bing[0][i][j].gongji >= 10 or bing[0][i][j].gongji < 0 ? '\0' : '0'
				 , bing[0][i][j].gongji);
		 }
		 printf("\n");
	 }
	 printf("���2 %s������:    %sѪ��%d ����:%d ����:%s �;�:%d\n", p[0].c_str()
		 , p[0].c_str()
		 , pxue[0]
		 , ndian[0]
		 , pwuqi[0].name.c_str()
		 , pwuqi[0].naiju);
	 return;
 }
 void _move(int tmpg) {
	 wasd[wa][wb][wc] = 0;
	 if (tmpg == 'w') {
		 if (wa == 1 and wb == 4 and vis[1][wb][wc]) {
		 }
		 else if (wa == 0 and wb == 1 and vis[1][wb][wc]) {
			 wa = 1;
		 }
		 else if (wa == 1 and vis[wa][wb + 1][wc]) {
			 wb++;
		 }
		 else if (wa == 0 and vis[wa][wb - 1][wc]) {
			 wb--;
		 }
		 else if (wb < 3 and wa == 1 and vis[wa][wb + 2][wc]) {
			 wb += 2;
		 }
		 else if (wb == 1 and wa == 1 and vis[wa][wb + 3][wc]) {
			 wb += 3;
		 }
		 else if (wb > 2 and wa == 0 and vis[wa][wb - 2][wc]) {
			 wb -= 2;
		 }
		 else if (wb == 4 and wa == 0 and vis[wa][wb - 3][wc]) {
			 wb -= 3;
		 }
	 }
	 if (tmpg == 's') {
		 if (wa == 0 and wb == 4) {
		 }
		 else if (wa == 1 and wb == 1 and vis[0][wb][wc]) {
			 wa = 0;
		 }
		 else if (wa == 1 and vis[wa][wb - 1][wc]) {
			 wb--;
		 }
		 else if (wa == 0 and vis[wa][wb + 1][wc]) {
			 wb++;
		 }
		 else if (wb < 3 and wa == 0 and vis[wa][wb + 2][wc]) {
			 wb += 2;
		 }
		 else if (wb == 1 and wa == 0 and vis[wa][wb + 3][wc]) {
			 wb += 3;
		 }
		 else if (wb > 2 and wa == 1 and vis[wa][wb - 2][wc]) {
			 wb -= 2;
		 }
		 else if (wb == 4 and wa == 1 and vis[wa][wb - 3][wc]) {
			 wb -= 3;
		 }
	 }
	 if (tmpg == 'a') {
		 if (wc > 1 and vis[wa][wb][wc - 1]) {
			 wc--;
		 }
	 }
	 if (tmpg == 'd') {
		 if (wc < k[wa][wb] and vis[wa][wb][wc + 1]) {
			 wc++;
		 }
	 }
	 wasd[wa][wb][wc] = 1;
 }
 void isbreak(int pl) {
	 if (pwuqi[pl].naiju > 0) {
		 return;
	 }
	 pwuqi[pl] = NULLW;
	 return;
 }
 abc wasdin(string s) {
	 wasd[wa][wb][wc] = 0;
	 wa = 1, wb = 1, wc = 1;
	 wasd[1][1][1] = 1;
	 while (1) {
		 flip();
		 printf("%s\n",s.c_str());
		 tmpm = _getch();
		 if (tmpm == ' ') {
			 wasd[wa][wb][wc] = 0;
			 break;
		 }
		 if (tmpm == '1') {
			 wasd[wa][wb][wc] = 0;
			 return abc(0,0,0);
		 }
		 _move(tmpm);
	 }
	 wasd[wa][wb][wc] = 0;
	 return abc(wa, wb, wc);
}