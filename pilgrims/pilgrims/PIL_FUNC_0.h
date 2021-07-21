#pragma once
int gongji(int, int, int, int, int, int);
void fanci(int, int, int, int, int, int);
void isdie(int, int, int);
int addxb(int, int);


int gongji(int a, int b, int c, int aa, int bb, int cc) {//攻击函数 
	if (bing[a][b][c].xue <= 0 or bing[aa][bb][cc].xue <= 0) {
		printf("攻击者或者受击者为空或者血量不足!\n");
		Sleep(1000);
		return 0;
	}
	if (bing[a][b][c].gongji == 0) {
		printf("攻击为0,无法攻击!\n");
		Sleep(1000);
		return 0;
	}
	if (bing[a][b][c].lingjcs <= 0) {
		printf("已经攻击过了\n");
		Sleep(1000);
		return 0;
	}
	if (kqian[aa] > 0) {
		if (!bing[aa][bb][cc].qianfeng) {
			printf("先攻击前锋对象\n");
			Sleep(1000);
			return 0;
		}
	}
	int she = 0;//实际排数 
	for (int i = 1; i <= bb; i++) {
		if (vis[aa][i][cc])she++;
	}
	if (bing[a][b][c].shecheng < she) {
		printf("射程不够\n");
		Sleep(1000);
		return 0;
	}
	if (bing[aa][bb][cc].bihu) {//庇护情况 
		bing[aa][bb][cc].bihu = 0;
		bing[a][b][c].lingjcs--;
		if (!bing[a][b][c].dianji)fanci(a, b, c, aa, bb, cc);
		return 1;
	}
	bing[a][b][c].xue += bing[a][b][c].xixue;//吸血情况 
	if (bing[a][b][c].xue > bing[a][b][c].maxxue)bing[a][b][c].xue = bing[a][b][c].maxxue;
	if (!bing[a][b][c].boolpojia and bing[aa][bb][cc].dun > 0) {//护盾情况 
		bing[aa][bb][cc].dun -= bing[a][b][c].gongji;
	}
	else {
		bing[aa][bb][cc].xue -= bing[a][b][c].gongji;
	}
	bing[a][b][c].lingjcs--;
	if (!bing[a][b][c].dianji)fanci(a, b, c, aa, bb, cc);//电击情况 
	else isdie(aa, bb, cc);
	if (bing[a][b][c].xue > bing[a][b][c].maxxue)bing[a][b][c].xue = bing[a][b][c].maxxue;
	if (bing[aa][bb][cc].xue > bing[aa][bb][cc].maxxue)bing[aa][bb][cc].xue = bing[aa][bb][cc].maxxue;
	return 1;
}
void fanci(int a, int b, int c, int aa, int bb, int cc) {//反刺函数 
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
void isdie(int a, int b, int c) {//判定死亡 
	if (bing[a][b][c].xue > 0) {//有血返回 
		return;
	}
	bing[a][b][c].yuannian();//释放怨念 
	dead[++deadk] = bing[a][b][c].bian;
	if (bing[a][b][c].qianfeng) {
		kqian[a]--;
	}
	bing[a][b][c] = NULLB, vis[a][b][c] = 0;
	for (int i = c + 1; i <= k[a][b]; i++) {//存者向左移动 
		if (vis[a][b][i]) {
			bing[a][b][i - 1] = bing[a][b][i], vis[a][b][i - 1] = 1;
			bing[a][b][i - 1].c = i - 1;
			bing[a][b][i] = NULLB, vis[a][b][i] = 0;
		}
	}
	k[a][b]--;
	return;
}
int addxb(int bought, int pl) {//增加士员 
	bing[pl][xblist[bought].paishu][++k[pl][xblist[bought].paishu]] = xblist[bought];//赋值上场 
	vis[pl][xblist[bought].paishu][k[pl][xblist[bought].paishu]] = 1; //确认有士员才此 
	if (xblist[bought].qianfeng)kqian[pl]++;//前锋士员总数增加 
	bing[pl][xblist[bought].paishu][k[pl][xblist[bought].paishu]].jineng();//释放上阵技能 
	bing[pl][xblist[bought].paishu][k[pl][xblist[bought].paishu]].a = pl;
	bing[pl][xblist[bought].paishu][k[pl][xblist[bought].paishu]].b = xblist[bought].paishu;
	bing[pl][xblist[bought].paishu][k[pl][xblist[bought].paishu]].c = k[pl][xblist[bought].paishu];
	//记录下a b c 
	return 1;
}