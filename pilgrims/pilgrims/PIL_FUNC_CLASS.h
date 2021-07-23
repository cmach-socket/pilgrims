#pragma once
void tmpyuan(int a, int b, int c) {//普通怨念函数 
	return;
}
void tmpji(int a, int b, int c) {//普通上阵函数 
	return;
}
void tmphui(int a, int b, int c) {//普通怒气函数 
	return;
}
void hui7(int a, int b, int c) {//7士员怒气函数 
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
void hui12(int a, int b, int c) {//12士员怒气函数 
	usefa[!a] = 1;
	return;
}
void yuan13(int a, int b, int c) {//13士员怨念函数 
	if (bing[!a][3][1].xue > 0) {
		bing[!a][3][1].xue = 0;
		isdie(!a, 3, 1);
	}
}
void ji16(int a, int b, int c) {//16士员上阵函数 
	abc tmp(0, 0, 0);
	while (1) {
		tmp = wasdin("选择被增加攻击的士员");
		if (bing[tmp.a][tmp.b][tmp.c].xue <= 0) {
			printf("受击者为空或者血量不足!\n");
			Sleep(1000);
			continue;
		}
		break;
	}
	bing[tmp.a][tmp.b][tmp.c].gongji += 5;
	bing[tmp.a][tmp.b][tmp.c].fanci += 5;
	return;
}
void yuan17(int a, int b, int c) {//17士员怨念函数 
	pxue[a] -= 3;
	if (pxue[a] <= 0)sxb[a] = 1;
}
void yuan19(int a, int b, int c) {//19士员怨念函数 
	addxb(20, a);
	return;
}
void ji23(int a, int b, int c) {//23士员上阵函数 
	while (1) {
		bing[a][b][c].tmp[1] = input<int>("1.与左边血量及上限相等 2.与左边攻击及反刺相等");
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
			printf("输入有误!\n");
		}
	}
}
void ji24(int a, int b, int c) {//24士员上阵函数
	ndian[a] -= 1;
}
void ji25(int a, int b, int c) {//25士员上阵函数
	if (deadk <= 0)return;
	abc tmp=addxb( dead[deadk], a);
	bing[tmp.a][tmp.b][tmp.c].xue=1;
	deadk--;
}
void hui26(int a, int b, int c) {//26士员怒气函数
	if (bing[a][b][c].xue <= 5) {
		bing[a][b][c].gongji = 15;
	}
}
void fa1() {//1001法术使用函数 
	abc tmp(0,0,0);
	while (1) {
		tmp = wasdin("选择被攻击的一排士员");
		if (tmp.b> 2) {
			printf("被攻击士员大于了2排!\n");
			Sleep(1000);
			continue;
		}
		if (bing[tmp.a][tmp.b][tmp.c].xue <= 0) {
			printf("受击者为空或者血量不足!\n");
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
void fa2() {//1002法术使用函数 
	abc tmp(0, 0, 0);
	while (1) {
		tmp = wasdin("选择被攻击的一排士员");
		if (tmp.b > 2) {
			printf("被攻击士员大于了2排!\n");
			Sleep(1000);
			continue;
		}
		if (bing[tmp.a][tmp.b][tmp.c].xue <= 0) {
			printf("受击者为空或者血量不足!\n");
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
void fa3() {//1003法术使用函数 
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
void fa4() {//1004法术使用函数 
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
void fa5() {//1005法术使用函数 
	abc tmp(0, 0, 0);
	while (1) {
		tmp = wasdin("选择被增加射程的士员");
		if (bing[tmp.a][tmp.b][tmp.c].xue <= 0) {
			printf("受击者为空或者血量不足!\n");
			Sleep(1000);
			continue;
		}
		break;
	}
	bing[tmp.a][tmp.b][tmp.c].shecheng++;
	return;
}
void fa6() {//1006法术使用函数
	abc tmp(0, 0, 0);
	while (1) {
		tmp = wasdin("选择被背刺的士员");
		if (bing[tmp.a][tmp.b][tmp.c].xue <= 0) {
			printf("受击者为空或者血量不足!\n");
			Sleep(1000);
			continue;
		}
		if (tmp.a != player) {
			printf("非己方士员!");
			Sleep(1000);
			continue;
		}
		break;
	}
	bing[tmp.a][tmp.b][tmp.c].xue -= 1;
	usefa[player] = 0;
	isdie(tmp.a, tmp.b, tmp.c);
}
void fa7() {//1007法术使用函数
	abc tmp(0, 0, 0);
	while (1) {
		tmp = wasdin("选择被攻击的士员");
		if (bing[tmp.a][tmp.b][tmp.c].xue <= 0) {
			printf("受击者为空或者血量不足!\n");
			Sleep(1000);
			continue;
		}
		break;
	}
	bing[tmp.a][tmp.b][tmp.c].hui = tmphui;
}
void wu1() {//2001武器使用函数 
	abc tmp(0, 0, 0);
	while (1) {
		tmp = wasdin("选择被攻击的一排士员");
		if (tmp.b > 2) {
			printf("被攻击士员大于了2排!\n");
			Sleep(1000);
			continue;
		}
		if (bing[tmp.a][tmp.b][tmp.c].xue <= 0) {
			printf("受击者为空或者血量不足!\n");
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
void wu2() {//2002武器使用函数 
	abc tmp(0, 0, 0);
	while (1) {
		tmp = wasdin("选择被治疗的一排士员");
		if (tmp.b > 2) {
			printf("被攻击士员大于了2排!\n");
			Sleep(1000);
			continue;
		}
		if (bing[tmp.a][tmp.b][tmp.c].xue <= 0) {
			printf("被治疗者为空或者血量不足!\n");
			Sleep(1000);
			continue;
		}
		break;
	}
	bing[tmp.a][tmp.b][tmp.c].xue += 5;
	if (bing[tmp.a][tmp.b][tmp.c].xue > bing[tmp.a][tmp.b][tmp.c].maxxue)bing[tmp.a][tmp.b][tmp.c].xue = bing[tmp.a][tmp.b][tmp.c].maxxue;
	return;
}