#pragma once
void initpai();
void init();
void sys();
void paizu();
int _input();
void setin();
void addpaizu();
void setban();
int buyin();
int buywasd();
int wquse(int);
int gjshou(int, int, int, int);
int addfs(int, int);
int addwq(int, int);







void init() {
	initpai();
	system("mode con cols=120 lines=40");
	slowout("---朝圣者---\n");
	Sleep(500);
	slowout("作者:cmach_socket\n");
	Sleep(500);
	slowout("版本号:"+BAN+"\n");
	system("pause");
	//前言 
	while (1) {
		system("cls");
		if (!bban)printf("---朝圣者---\n");
		if (bban)printf("---本本战斗:天空重合---\n");
		printf("1.开始游戏\n2.更改牌组\n3.设置操作模式\n4.创建牌组\n5.改变版本\n6.退出游戏\n");
		charc = _getch();
		if (charc == '1') {
			break;
		}
		if (charc == '2') {
			paizu();
		}
		if (charc == '3') {
			setin();
		}
		if (charc == '4') {
			addpaizu();
		}
		if (charc == '5') {
			setban();
		}
		if (charc == '6') {
			return;
		}
	}
	//主菜单 
	system("cls");
	ifstream fs1("player1.txt");//牌组路径文件 
	ifstream fs2("player2.txt");
	fs1 >> ppai[1];
	fs2 >> ppai[0];
	f[1] = fopen(ppai[1].c_str(), "r");//牌组文件 
	for (int i = 1; i < MAXIP; i++) {
		fscanf(f[1], "%d", &paip[1][i]);
	}
	fclose(f[1]);
	f[0] = fopen(ppai[0].c_str(), "r");
	for (int i = 1; i < MAXIP; i++) {
		fscanf(f[0], "%d", &paip[0][i]);
	}
	fclose(f[0]);
	finmo = fopen("setin.txt", "r");
	fscanf(finmo, "%d", &inmode);//输入模式 
	for (int i = 1; i < MAXP; i++) {
		k[1][i] = 0;
		k[0][i] = 0;
	}
	fs1.close();
	fs2.close();
	fclose(finmo);
	//打开各项文件加载资源 
	p[1] = input<string>("输入玩家1的名字: ");
	p[0] = input<string>("输入玩家2的名字: ");
	sys();//启动主函数 
	re = fopen("rezult.txt", "a");//打开结果文件 
	time_t curtime;
	time(&curtime);//获取时间 
	fprintf(re, "%s%s战胜了%s\n", ctime(&curtime)
		, pxue[1] <= 0 ? p[0].c_str() : p[1].c_str()
		, pxue[1] <= 0 ? p[1].c_str() : p[0].c_str());
	//记录结果 
	system("pause");
	return;
}
void setban() {//设置版本 
	while (1) {
		system("cls");
		printf("1.正式版《朝圣者》\n2.怀旧版《朝圣者》\n");
		huai = _getch();
		if (huai == '1') {
			bban = 0;
			for (int i = 1; i <= inxbk; i++) {
				xblist[i].name = NAME[i];
			}
			for (int i = 1; i <= infsk; i++) {
				fslist[i].name = FNA[i];
			}
			for (int i = 1; i <= inwqk; i++) {
				wqlist[i].name = WNA[i];
			}
			break;
		}
		if (huai == '2') {
			bban = 1;
			for (int i = 1; i <= inxbk; i++) {
				xblist[i].name = HNAME[i];
			}
			for (int i = 1; i <= infsk; i++) {
				fslist[i].name = HFNA[i];
			}
			for (int i = 1; i <= inwqk; i++) {
				wqlist[i].name = HWNA[i];
			}
			break;
		}
	}
}
void addpaizu() {//创建牌组 
	system("cls");
	tmpapz = input<string>("输入要创建的牌组文件名:\n");
	fapz = fopen(tmpapz.c_str(), "w");
	memset(xbapz, 0, sizeof(xbapz));
	memset(fsapz, 0, sizeof(fsapz));
	memset(wqapz, 0, sizeof(wqapz));
	maxadd = 0;
	//初始化变量 
	while (maxadd <= 20) {
		system("cls");
		printf("输入要添加的单位编号，回车前请确认编号是否正确，输入0或者满20张退出\n");
		for (int i = 1; i <= inxbk; i++) {
			if (!xbapz[i] and xblist[i].bian > 0) {
				printf("%d.%s\n", xblist[i].bian, xblist[i].name.c_str());
			}
		}
		for (int i = 1; i <= infsk; i++) {
			if (!fsapz[i] and xblist[i].bian > 0) {
				printf("%d.%s\n", fslist[i].bian, fslist[i].name.c_str());
			}
		}
		for (int i = 1; i <= inwqk; i++) {
			if (!wqapz[i] and xblist[i].bian > 0) {
				printf("%d.%s\n", wqlist[i].bian, wqlist[i].name.c_str());
			}
		}
		scanf("%d", &wapz);
		if (wapz == 0) {
			break;
		}
		fprintf(fapz, "%d ", wapz);
		if (wapz < 1000) {
			xbapz[wapz] = 1;
		}
		if (wapz >= 1000 and wapz < 2000) {
			fsapz[wapz - 1000] = 1;
		}
		if (wapz >= 2000) {
			wqapz[wapz - 2000] = 1;
		}
		maxadd++;
	}
	fclose(fapz);
	return;
}
void paizu() {
	system("cls");
	printf("1.更改玩家1牌组路径\n2.更改玩家2牌组路径\n");
	chose = _getch();
	printf("输入路径: ");
	scanf("%s", &choses);
	if (chose == '1') {
		fchose = fopen("player1.txt", "w");
	}
	if (chose == '2') {
		fchose = fopen("player2.txt", "w");
	}
	fprintf(fchose, "%s", choses);
	fclose(fchose);
	printf("更改成功\n");
	Sleep(1000);
	return;
}
void setin() {
	system("cls");
	refim = fopen("setin.txt", "w");
	printf("1.输入模式\n2.WASD选定模式\n");
	setmode = _getch();
	if (setmode == '1' or setmode == '2') {
		fprintf(refim, "%c", setmode);
	}
	fclose(refim);
	printf("设置成功\n");
	Sleep(1000);
	return;
}
int buyin() {
	tmpb = input<int>("输入选择进行攻击的士员的排数 若选定武器请输入0  ：");
	if (!tmpb) {
		wquse(player);
		return 1;
	}
	else {
		tmpc = input<int>("输入选择进行攻击的士员的行号: ");
		tmpaa = input<int>("输入选择被攻击的士员阵营(如攻击玩家2就输入2),攻击首脑请输入0: ");

		if (!tmpaa) {
			gjshou(player, tmpb, tmpc, !player);
			return 1;
		}
		if (tmpaa == 2)tmpaa -= 2;
		tmpbb = input<int>("输入被攻击的士员排数: ");
		tmpcc = input<int>("输入被攻击的士员的行号: ");
		gongji(player, tmpb, tmpc, tmpaa, tmpbb, tmpcc);
	}
}

int buywasd() {
	abc tmp1(0,0,0), tmp2(0,0,0);
	printf("选择武器请按0,选择士员请按1");
	tmpm = _getch();
	if (tmpm == '0') {
		wquse(player);
		return 1;
	}
	while (1) {
		tmp1 = wasdin("空格选择攻击的士员,按wasd移动选定,按1取消");
		if (!tmp1.a and !tmp1.b and !tmp1.c) {
			return 1;
		}
		if (tmp1.a != player) {
			printf("此士员并非你方士员!\n");
			Sleep(1000);
			continue;
		}
		break;
	}
	printf("若选定攻击首脑请按0,选择士员请按1");
	tmpm = _getch();
	if (tmpm == '0') {
		wasd[wa][wb][wc] = 0;
		gjshou(tmp1.a, tmp2.b, tmp2.c, !player);
		return 1;
	}
	while (1) {
		tmp2 = wasdin("按空格选择被攻击的士员,按wasd移动选定,按1取消");
		if (!tmp2.a and !tmp2.b and !tmp2.c) {
			return 1;
		}
		break;
	}
	gongji(tmp1.a, tmp1.b, tmp1.c, tmp2.a, tmp2.b, tmp2.c);
}
int _input() {
	bool boolb;
	boolb = 0;
	printf("%s的回合\n", p[player].c_str());
	printf("选择操作:1购买放置单位 2攻击敌方 3结束回合:\n");
	mode = _getch() - '0';
	if (mode == 1) {
		string putname1, putname2;
		int putdian1,putdian2;
		tmpche = 1;
		printf("您的队伍: \n");
		for (int i = 1; i < MAXIP-10; i++) {
			if (paip[player][i] > 0) {
				if (paip[player][i] >= 1000 and paip[player][i] < 2000) {
					putname1 = fslist[paip[player][i] - 1000].name;
					putdian1 = fslist[paip[player][i] - 1000].dianshu;
					//printf("%d.%s ", i, fslist[paip[player][i] - 1000].name.c_str());
				}
				else if (paip[player][i] >= 2000) {
					putname1 = wqlist[paip[player][i] - 2000].name;
					putdian1 = wqlist[paip[player][i] - 2000].dianshu;
					//printf("%d.%s ", i, wqlist[paip[player][i] - 2000].name.c_str());
				}
				else putname1 = xblist[paip[player][i]].name, putdian1 = xblist[paip[player][i]].dianshu;
				//printf("%d.%s ", i, xblist[paip[player][i]].name.c_str());
			}
			if (paip[player][i+10] > 0) {
				if (paip[player][i+10] >= 1000 and paip[player][i+10] < 2000) {
					putname2 = fslist[paip[player][i+10] - 1000].name;
					putdian2 = fslist[paip[player][i+10] - 1000].dianshu;
					//printf("%d.%s ", i, fslist[paip[player][i] - 1000].name.c_str());
				}
				else if (paip[player][i+10] >= 2000) {
					putname2 = wqlist[paip[player][i+10] - 2000].name;
					putdian2 = wqlist[paip[player][i+10] - 2000].dianshu;
					//printf("%d.%s ", i, wqlist[paip[player][i] - 2000].name.c_str());
				}
				else putname2 = xblist[paip[player][i+10]].name, putdian2 = xblist[paip[player][i+10]].dianshu;
				//printf("%d.%s ", i, xblist[paip[player][i]].name.c_str());
				printf("%d.%s %d点                %d.%s %d点\n", i, putname1.c_str(), putdian1, i + 10, putname2.c_str(), putdian2);
			}
		}
		printf("\n");
		tmpbuy = input<int>("输入你要购买的在你队伍中的编号: ");
		if (tmpbuy > 20 or tmpbuy <= 0) {
			printf("输入有误!\n");
			Sleep(1000);
			return 1;
		}
		if (!paip[player][tmpbuy]) {
			printf("此队伍格子中没有有效士员编号!\n");
			Sleep(1000);
			return 1;
		}
		if (paip[player][tmpbuy] >= 1000 and paip[player][tmpbuy] < 2000) {
			tmpche = 2;
		}
		if (paip[player][tmpbuy] >= 2000) {
			tmpche = 3;
		}
		if (tmpche == 1) {
			if (ndian[player] - xblist[paip[player][tmpbuy]].dianshu < 0) {
				printf("点数不够!\n");
				Sleep(1000);
				return 1;
			}
			if (k[player][xblist[paip[player][tmpbuy]].paishu] >= MAXN) {
				printf("此排拥有太多士员!\n");
				Sleep(1000);
				return 1;
			}
			ndian[player] -= xblist[paip[player][tmpbuy]].dianshu;//点数减少 
			if (addxb(paip[player][tmpbuy], player).c) {
				return 1;
			}
		}
		if (tmpche == 2) {
			if (!addfs(paip[player][tmpbuy], player)) {
				return 1;
			}
		}
		if (tmpche == 3) {
			if (!addwq(paip[player][tmpbuy], player)) {
				return 1;
			}
		}
	}
	else if (mode == 2) {
		if (huihes == 1 and player == 1) {
			printf("第1回合无法攻击!\n");
			Sleep(1000);
			return 1;
		}
		if (inmode == 1) {
			return buyin();
		}
		if (inmode == 2) {
			return buywasd();
		}
	}
	else if (mode == 3) {
		printf("%s结束了回合", p[player].c_str());
		Sleep(1000);
		return 0;
	}
	else {
		printf("请输入正确编号\n");
		Sleep(1000);
	}
	return 1;
}
void sys() {
	while (true) {
		ndian[player] += 10, ndian[!player] += 10, huihes++;
		usefa[!player] = 0, usewu[!player] = 0;
		usefa[player] = 0, usewu[player] = 0;
		useji();
		flip();
		while (_input()) {
			flip();
			if (sxb[0]) {
				printf("%s方胜!\n", p[1].c_str());
				return;
			}
			if (sxb[1]) {
				printf("%s方胜!\n", p[0].c_str());
				return;
			}

		}
		player = !player;


		useji();
		flip();
		while (_input()) {
			flip();
			if (sxb[0]) {
				printf("%s方胜!", p[1].c_str());
				return;
			}
			if (sxb[1]) {
				printf("%s方胜!", p[0].c_str());
				return;
			}
		}
		player = !player;
	}
	return;
}
int addfs(int bought, int pl) {
	bought -= 1000;

	if (ndian[pl] - fslist[bought].dianshu < 0) {
		printf("点数不够!\n");
		Sleep(1000);
		return 0;
	}
	if (usefa[pl]) {
		printf("本回合已经使用过法术!\n");
		Sleep(1000);
		return 0;
	}
	ndian[pl] -= fslist[bought].dianshu;
	fslist[bought].use();
	printf("使用了%s\n", fslist[bought].name.c_str());
	Sleep(1000);
	usefa[pl] = 1;
	return 1;
}
int addwq(int bought, int pl) {
	bought -= 2000;
	if (ndian[pl] - wqlist[bought].dianshu < 0) {
		printf("点数不够!\n");
		Sleep(1000);
		return 0;
	}
	ndian[pl] -= wqlist[bought].dianshu;
	pwuqi[pl] = wqlist[bought];
	return 1;
}
int wquse(int pl) {
	if (pwuqi[pl].naiju <= 0) {
		printf("武器缺乏耐久或者并未装备!\n");
		Sleep(1000);
		return 0;
	}
	if (usewu[pl]) {
		printf("本回合已经使用过武器!\n");
		Sleep(1000);
		return 0;
	}
	pwuqi[pl].use();
	pwuqi[pl].naiju--;
	usewu[pl] = 1;
	isbreak(pl);
	return 1;
}
int gjshou(int a, int b, int c, int pl) {//能否攻击首脑
	for (int i = 1; i <= MAXP - 1; i++) {
		if (k[pl][i] > 0) {
			printf("%s仍有士员在场!\n", p[pl].c_str());
			Sleep(1000);
			return 0;
		}
	}
	pxue[pl] -= bing[a][b][c].gongji;
	bing[a][b][c].xue = 0;
	isdie(a, b, c);
	if (pxue[pl] <= 0)sxb[pl] = 1;
	return 1;
}

void initpai() {//初始化购买列表 
	for (int i = 1; i <= inxbk; i++) {
		xblist[i].Xiaobin(NAME[i], I1[i], I2[i], I3[i], I4[i], I5[i], I6[i], I7[i], I8[i], I9[i], I10[i], I11[i], I12[i], I13[i], I14[i], I15[i], I16[i], I17[i], F1[i], F2[i], F3[i]);
	}
	for (int i = 1; i <= infsk; i++) {
		fslist[i].Fashu(FNA[i], FA[i], FDI[i], FBI[i]);
	}
	for (int i = 1; i <= inwqk; i++) {
		wqlist[i].Wuqi(WNA[i], WU[i], WDI[i], NAI[i], WBI[i]);
	}
}










