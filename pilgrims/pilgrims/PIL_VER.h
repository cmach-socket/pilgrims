#pragma once
xiaobin bing[MAXPLAY][MAXP][MAXN], NULLB;
//		场地						空士员 
wuqi pwuqi[MAXPLAY];
//双方武器槽 
bool vis[MAXPLAY][MAXP][MAXN];
//是否有士员在此处 
int k[MAXPLAY][MAXP]{ 0 }, kqian[MAXPLAY], dead[MAXX], deadk;
//每排的士员数量		前锋数量 		死者编号  死者人数 

string p[MAXPLAY], ppai[MAXPLAY], tmpapz;
//		玩家名称  牌组文件路径  创建牌组名 
int pxue[MAXPLAY]{ 20,20 }, paip[MAXPLAY][MAXIP], ndian[MAXPLAY]{ 15,15 };
//  玩家血量              玩家队伍			  玩家点数 
int huihes, mode, tmpbuy, tmpche, tmpb, tmpc, tmpaa, tmpbb, tmpcc, inmode, wa, wb, wc, wapz, maxadd;
//  回合数 操作 购买  购买什么                        	 输入模式 WASD临时记录  最大添加数量 
bool player = 1, sxb[MAXPLAY]{ 0,0 }, usefa[MAXPLAY]{ 0,0 }, usewu[MAXPLAY]{ 0,0 }, wasd[MAXPLAY][MAXP][MAXN], xbapz[MAXX], fsapz[MAXX], wqapz[MAXX], bban = 0;
//当前回合玩家 是否首脑死亡     是否使用技能         是否使用武器		WASD记录表					是否已添加士员/法术/武器 
char charc, chose, setmode, tmpm, capz, huai;
// 菜单输入 牌组路径更改 输入模式设定 WASD输入 添加单位输入 版本选定输入 
wuqi NULLW;
//空武器 
FILE* f[MAXPLAY], * fchose, * re, * finmo, * refim, * fapz;
//    读player1/2.txt文件 写player1/2.txt文件   rezult.txt   读setin.txt 写setin.txt 添加牌组文件 
char choses[MAXC];
//更改的牌组路径名 
xiaobin xblist[MAXX]; //初始士员列表 
fashu fslist[MAXX];//初始法术列表 
wuqi wqlist[MAXX];//初始武器列表 
