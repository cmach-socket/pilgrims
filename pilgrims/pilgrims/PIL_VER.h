#pragma once
xiaobin bing[MAXPLAY][MAXP][MAXN], NULLB;
//		����						��ʿԱ 
wuqi pwuqi[MAXPLAY];
//˫�������� 
bool vis[MAXPLAY][MAXP][MAXN];
//�Ƿ���ʿԱ�ڴ˴� 
int k[MAXPLAY][MAXP]{ 0 }, kqian[MAXPLAY], dead[MAXX], deadk;
//ÿ�ŵ�ʿԱ����		ǰ������ 		���߱��  �������� 

string p[MAXPLAY], ppai[MAXPLAY], tmpapz;
//		�������  �����ļ�·��  ���������� 
int pxue[MAXPLAY]{ 20,20 }, paip[MAXPLAY][MAXIP], ndian[MAXPLAY]{ 15,15 };
//  ���Ѫ��              ��Ҷ���			  ��ҵ��� 
int huihes, mode, tmpbuy, tmpche, tmpb, tmpc, tmpaa, tmpbb, tmpcc, inmode, wa, wb, wc, wapz, maxadd;
//  �غ��� ���� ����  ����ʲô                        	 ����ģʽ WASD��ʱ��¼  ���������� 
bool player = 1, sxb[MAXPLAY]{ 0,0 }, usefa[MAXPLAY]{ 0,0 }, usewu[MAXPLAY]{ 0,0 }, wasd[MAXPLAY][MAXP][MAXN], xbapz[MAXX], fsapz[MAXX], wqapz[MAXX], bban = 0;
//��ǰ�غ���� �Ƿ���������     �Ƿ�ʹ�ü���         �Ƿ�ʹ������		WASD��¼��					�Ƿ������ʿԱ/����/���� 
char charc, chose, setmode, tmpm, capz, huai;
// �˵����� ����·������ ����ģʽ�趨 WASD���� ��ӵ�λ���� �汾ѡ������ 
wuqi NULLW;
//������ 
FILE* f[MAXPLAY], * fchose, * re, * finmo, * refim, * fapz;
//    ��player1/2.txt�ļ� дplayer1/2.txt�ļ�   rezult.txt   ��setin.txt дsetin.txt ��������ļ� 
char choses[MAXC];
//���ĵ�����·���� 
xiaobin xblist[MAXX]; //��ʼʿԱ�б� 
fashu fslist[MAXX];//��ʼ�����б� 
wuqi wqlist[MAXX];//��ʼ�����б� 
