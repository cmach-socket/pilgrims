#pragma once
void initpai();
void init();
void flip();
void sys();
void useji();
void paizu();
int _input();
void isbreak(int);
void setin();
void _move();
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
	slowout("---��ʥ��---\n");
	Sleep(500);
	slowout("����:cmach_socket\n");
	Sleep(500);
	slowout("�汾��:1.0.210322\n");
	system("pause");
	//ǰ�� 
	while (1) {
		system("cls");
		if (!bban)printf("---��ʥ��---\n");
		if (bban)printf("---����ս��:����غ�---\n");
		printf("1.��ʼ��Ϸ\n2.��������\n3.���ò���ģʽ\n4.��������\n5.�ı�汾\n6.�˳���Ϸ\n");
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
	//���˵� 
	system("cls");
	ifstream fs1("player1.txt");//����·���ļ� 
	ifstream fs2("player2.txt");
	fs1 >> ppai[1];
	fs2 >> ppai[0];
	f[1] = fopen(ppai[1].c_str(), "r");//�����ļ� 
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
	fscanf(finmo, "%d", &inmode);//����ģʽ 
	for (int i = 1; i < MAXP; i++) {
		k[1][i] = 0;
		k[0][i] = 0;
	}
	fs1.close();
	fs2.close();
	fclose(finmo);
	//�򿪸����ļ�������Դ 
	p[1] = input<string>("�������1������: ");
	p[0] = input<string>("�������2������: ");
	sys();//���������� 
	re = fopen("rezult.txt", "a");//�򿪽���ļ� 
	time_t curtime;
	time(&curtime);//��ȡʱ�� 
	fprintf(re, "%s%sսʤ��%s\n", ctime(&curtime)
		, pxue[1] <= 0 ? p[0].c_str() : p[1].c_str()
		, pxue[1] <= 0 ? p[1].c_str() : p[0].c_str());
	//��¼��� 
	system("pause");
	return;
}
void setban() {//���ð汾 
	while (1) {
		system("cls");
		printf("1.��ʽ�桶��ʥ�ߡ�\n2.���ɰ桶��ʥ�ߡ�\n");
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
void addpaizu() {//�������� 
	system("cls");
	tmpapz = input<string>("����Ҫ�����������ļ���:\n");
	fapz = fopen(tmpapz.c_str(), "w");
	memset(xbapz, 0, sizeof(xbapz));
	memset(fsapz, 0, sizeof(fsapz));
	memset(wqapz, 0, sizeof(wqapz));
	maxadd = 0;
	//��ʼ������ 
	while (maxadd <= 20) {
		system("cls");
		printf("����Ҫ��ӵĵ�λ��ţ��س�ǰ��ȷ�ϱ���Ƿ���ȷ������0������20���˳�\n");
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
	printf("1.�������1����·��\n2.�������2����·��\n");
	chose = _getch();
	printf("����·��: ");
	scanf("%s", &choses);
	if (chose == '1') {
		fchose = fopen("player1.txt", "w");
	}
	if (chose == '2') {
		fchose = fopen("player2.txt", "w");
	}
	fprintf(fchose, "%s", choses);
	fclose(fchose);
	printf("���ĳɹ�\n");
	Sleep(1000);
	return;
}
void setin() {
	system("cls");
	refim = fopen("setin.txt", "w");
	printf("1.����ģʽ\n2.WASDѡ��ģʽ\n");
	setmode = _getch();
	if (setmode == '1' or setmode == '2') {
		fprintf(refim, "%c", setmode);
	}
	fclose(refim);
	printf("���óɹ�\n");
	Sleep(1000);
	return;
}
int buyin() {
	tmpb = input<int>("����ѡ����й�����ʿԱ������ ��ѡ������������0  ��");
	if (!tmpb) {
		if (!wquse(player)) {
			return 1;
		}
		else return 1;
	}
	else {
		tmpc = input<int>("����ѡ����й�����ʿԱ���к�: ");
		tmpaa = input<int>("����ѡ�񱻹�����ʿԱ��Ӫ(�繥�����2������2),��������������0: ");

		if (!tmpaa) {
			if (gjshou(player, tmpb, tmpc, !player)) {
				return 1;
			}
			else return 1;
		}
		if (tmpaa == 2)tmpaa -= 2;
		tmpbb = input<int>("���뱻������ʿԱ����: ");
		tmpcc = input<int>("���뱻������ʿԱ���к�: ");
		gongji(player, tmpb, tmpc, tmpaa, tmpbb, tmpcc);
	}
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
int buywasd() {
	int tmpwa, tmpwb, tmpwc, tmpwaa, tmpwbb, tmpwcc;
	wa = 1, wb = 1, wc = 1;
	wasd[1][1][1] = 1;
	while (1) {
		flip();
		printf("���ո�ѡ����й�����ʿԱ,��wasd�ƶ�ѡ��,��ѡ�������밴0,��1ȡ��\n");
		tmpm = _getch();
		if (tmpm == ' ') {
			if (wa != player) {
				printf("��ʿԱ�����㷽ʿԱ!\n");
				Sleep(1000);
				continue;
			}
			wasd[wa][wb][wc] = 0;
			break;
		}
		if (tmpm == '0') {
			wasd[wa][wb][wc] = 0;
			if (!wquse(player)) {

				return 1;
			}
			else return 1;
		}
		if (tmpm == '1') {
			wasd[wa][wb][wc] = 0;
			return 1;
		}
		_move(tmpm);
	}
	tmpwa = wa, tmpwb = wb, tmpwc = wc;
	wasd[wa][wb][wc] = 0;
	wa = 1, wb = 1, wc = 1;
	wasd[1][1][1] = 1;
	while (1) {
		flip();
		printf("���ո�ѡ�񱻹�����ʿԱ,��wasd�ƶ�ѡ��,��ѡ�������밴0,��1ȡ��\n");
		tmpm = _getch();
		if (tmpm == ' ') {
			break;
		}
		if (tmpm == '0') {
			wasd[wa][wb][wc] = 0;
			if (gjshou(tmpwa, tmpwb, tmpwc, !player)) {
				return 1;
			}
			else return 1;
		}
		if (tmpm == '1') {
			return 1;
		}
		_move(tmpm);
	}
	tmpwaa = wa, tmpwbb = wb, tmpwcc = wc;
	gongji(tmpwa, tmpwb, tmpwc, tmpwaa, tmpwbb, tmpwcc);
	wasd[wa][wb][wc] = 0;
	wa = 0, wb = 0, wc = 0;
}
int _input() {
	bool boolb;
	boolb = 0;
	printf("%s�Ļغ�\n", p[player].c_str());
	printf("ѡ�����:1������õ�λ 2�����з� 3�����غ�:\n");
	mode = _getch() - '0';
	if (mode == 1) {
		tmpche = 1;
		printf("���Ķ���: ");
		for (int i = 1; i < MAXIP; i++) {
			if (paip[player][i] > 0) {
				if (paip[player][i] >= 1000 and paip[player][i] < 2000) {
					printf("%d.%s ", i, fslist[paip[player][i] - 1000].name.c_str());
					continue;
				}
				if (paip[player][i] >= 2000) {
					printf("%d.%s ", i, wqlist[paip[player][i] - 2000].name.c_str());
					continue;
				}
				printf("%d.%s ", i, xblist[paip[player][i]].name.c_str());
			}
		}
		printf("\n");
		tmpbuy = input<int>("������Ҫ�������������еı��: ");
		if (tmpbuy > 20 or tmpbuy <= 0) {
			printf("��������!\n");
			Sleep(1000);
			return 1;
		}
		if (!paip[player][tmpbuy]) {
			printf("�˶��������û����ЧʿԱ���!\n");
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
				printf("��������!\n");
				Sleep(1000);
				return 1;
			}
			if (k[player][xblist[paip[player][tmpbuy]].paishu] >= MAXN) {
				printf("����ӵ��̫��ʿԱ!\n");
				Sleep(1000);
				return 1;
			}
			ndian[player] -= xblist[paip[player][tmpbuy]].dianshu;//�������� 
			if (!addxb(paip[player][tmpbuy], player)) {
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
			printf("��1�غ��޷�����!\n");
			Sleep(1);
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
		printf("%s�����˻غ�", p[player].c_str());
		Sleep(1000);
		return 0;
	}
	else {
		printf("��������ȷ���\n");
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
				printf("%s��ʤ!\n", p[1].c_str());
				return;
			}
			if (sxb[1]) {
				printf("%s��ʤ!\n", p[0].c_str());
				return;
			}

		}
		player = !player;


		useji();
		flip();
		while (_input()) {
			flip();
			if (sxb[0]) {
				printf("%s��ʤ!", p[1].c_str());
				return;
			}
			if (sxb[1]) {
				printf("%s��ʤ!", p[0].c_str());
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
		printf("��������!\n");
		Sleep(1000);
		return 0;
	}
	if (usefa[pl]) {
		printf("���غ��Ѿ�ʹ�ù�����!\n");
		Sleep(1000);
		return 0;
	}
	ndian[pl] -= fslist[bought].dianshu;
	fslist[bought].use();
	printf("ʹ����%s\n", fslist[bought].name.c_str());
	Sleep(1000);
	usefa[pl] = 1;
	return 1;
}
int addwq(int bought, int pl) {
	bought -= 2000;
	if (ndian[pl] - wqlist[bought].dianshu < 0) {
		printf("��������!\n");
		Sleep(1000);
		return 0;
	}
	ndian[pl] -= wqlist[bought].dianshu;
	pwuqi[pl] = wqlist[bought];
	return 1;
}
int wquse(int pl) {
	if (pwuqi[pl].naiju <= 0) {
		printf("����ȱ���;û��߲�δװ��!\n");
		Sleep(1000);
		return 0;
	}
	if (usewu[pl]) {
		printf("���غ��Ѿ�ʹ�ù�����!\n");
		Sleep(1000);
		return 0;
	}
	pwuqi[pl].use();
	pwuqi[pl].naiju--;
	usewu[pl] = 1;
	isbreak(pl);
	return 1;
}
void isbreak(int pl) {
	if (pwuqi[pl].naiju > 0) {
		return;
	}
	pwuqi[pl] = NULLW;
	return;
}
int gjshou(int a, int b, int c, int pl) {
	for (int i = 1; i <= MAXP - 1; i++) {
		if (k[pl][i] > 0) {
			printf("%s����ʿԱ�ڳ�!\n", p[pl].c_str());
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

void initpai() {//��ʼ�������б� 
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










