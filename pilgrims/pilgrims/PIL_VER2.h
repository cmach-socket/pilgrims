#pragma once
int I1[MAXX]{  0,5 ,5,0 ,5,-5,3,4 ,10,5 ,5 ,2 ,0 ,10,10,5 ,0 ,10,10,5 ,5  ,0 ,0 ,5 ,1 ,5 };//gongji 攻击
int	I2[MAXX]{  0,5 ,5,0 ,5,0 ,0,4 ,10,5 ,5 ,2 ,0 ,10,10,5 ,0 ,0 ,10,5 ,5  ,10,2 ,5 ,1 ,5 };//fanci 反刺
int	I3[MAXX]{  0,10,5,15,2,3 ,3,20,5 ,15,7 ,3 ,10,5 ,5 ,7 ,10,10,5 ,5 ,5  ,10,12,10,6 ,5 };//xue 血量
int	I4[MAXX]{  0,1 ,1,0 ,1,1 ,1,1 ,1 ,1 ,1 ,3 ,0 ,1 ,1 ,1 ,0 ,2 ,1 ,1 ,5  ,0 ,0 ,0 ,1 ,1 };//gjcishu 攻击次数
int	I5[MAXX]{  0,1 ,2,1 ,1,3 ,3,1 ,1 ,1 ,1 ,2 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1  ,1 ,1 ,1 ,1 ,1 };//shecheng 射程
int	I6[MAXX]{  0,0 ,0,0 ,0,0 ,0,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0  ,0 ,0 ,0 ,0 ,0 };//dun 盾
int	I7[MAXX]{  0,0 ,0,0 ,0,0 ,0,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,2 ,1 ,0 ,0  ,0 ,0 ,0 ,1 ,0 };//lingjcs 临时攻击次数
int	I8[MAXX]{  0,5 ,5,5 ,2,5 ,5,20,10,15,5 ,5 ,5 ,10,10,5 ,5 ,10,7 ,5 ,5  ,5 ,5 ,15,0 ,10};//dianshu 点数
int	I9[MAXX]{  0,0 ,0,0 ,0,0 ,0,0 ,0 ,5 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0  ,0 ,0 ,0, 0 ,0 };//xixue 吸血
int	I10[MAXX]{ 0,0 ,0,0 ,0,0 ,0,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0  ,0 ,0 ,0 ,0 ,0 };//boolpojia 是否破甲
int	I11[MAXX]{ 0,1 ,2,1 ,1,3 ,3,1 ,1 ,1 ,1 ,2 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1  ,1 ,1 ,1 ,1 ,2 };//paishu 排数
int	I12[MAXX]{ 0,0 ,0,0 ,0,0 ,0,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0  ,0 ,1 ,0 ,0 ,0 };//qianfeng 是否前锋
int	I13[MAXX]{ 1,1 ,1,1 ,1,1 ,1,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1  ,1 ,1 ,1 ,1 ,1 };//boolji 是否攻击
int	I14[MAXX]{ 0,0 ,0,0 ,0,0 ,0,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0  ,0 ,0 ,0 ,0 ,0 };//bihu 是否庇护
int	I15[MAXX]{ 0,0 ,0,0 ,0,1 ,0,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0  ,0 ,0 ,0 ,0 ,0 };//dianji 是否电击
int	I16[MAXX]{ 0,1 ,2,3 ,4,5 ,6,7 ,8 ,9 ,10,11,12,13,14,15,16,17,18,19,-20,21,22,23,24,25};//bian 编号
int I17[MAXX]{ 0,10,5,15,2,3 ,3,20,5 ,15,8 ,3 ,10,5 ,5 ,7 ,10,10,5 ,5 ,5  ,10,12,10 ,6,5 };//maxxue 最大血量
int FDI[MAXX]{ 0,5,1,0,5,3 ,0};//法术点数
int FBI[MAXX]{ 0,1001,1002,1003,1004,1005 ,1006};//法术编号
int WDI[MAXX]{ 0,5,5 };//武器点数
int WBI[MAXX]{ 0,2001,2002 };//武器编号
int NAI[MAXX]{ 0,2,2 };   //武器耐久
string NAME[MAXX]{ "\0","卫兵","猎手","重甲","爆兵","仁心","火击","炼狱","英灵","安德拉","坚石","忍","缄默","执剑人","狡","利矛","清心","叛军","破阵","彼岸","双生","禅","断罪","诙谐" ,"突击兵","亡灵法师"};
string HNAME[MAXX]{ "\0","木头","陈醋","破损老搞","BUG精灵","草草","肚纸","地狱木头","英灵","吸血鬼","前锋假豪","BUG终结者","重甲破损搞","细菌","反木头","笑天犬","刘动","叛军","破阵","22","33","反抗木头","破锋反搞","诙谐","突击兵","灵魂召唤师"};
//士员名称 
string FNA[MAXX]{ "\0","暗杀","惊扰","禁忌术","风暴","焕发","背刺"};
string HFNA[MAXX]{ "\0","火球术","惊扰","死亡黎明","风暴","焕发","自残"};
//法术名称 
string WNA[MAXX]{ "\0","y12激光步枪","急救剂" };
string HWNA[MAXX]{ "\0","战争拳套","急救剂" };
//武器名称 
pfu FA[MAXX]{ NULL,fa1,fa2,fa3,fa4,fa5,fa6};
//法术集合 
pfu WU[MAXX]{ NULL,wu1,wu2 };
//武器集合 
pfux F1[MAXX]{ NULL,tmpyuan,tmpyuan,tmpyuan,tmpyuan,tmpyuan,tmpyuan,tmpyuan,tmpyuan,tmpyuan,tmpyuan,tmpyuan,tmpyuan,yuan13,tmpyuan,tmpyuan,tmpyuan,yuan17,tmpyuan,yuan19,tmpyuan,tmpyuan,tmpyuan,tmpyuan,tmpyuan,tmpyuan};//yuannian
//怨念法术集合 
pfux F2[MAXX]{ NULL,tmpji  ,tmpji  ,tmpji  ,tmpji  ,tmpji  ,tmpji  ,tmpji  ,tmpji  ,tmpji  ,tmpji  ,tmpji  ,tmpji  ,tmpji ,tmpji  ,tmpji,  ji16   ,tmpji ,tmpji  ,tmpji ,tmpji  ,tmpji  ,tmpji  ,ji23   ,ji24   ,ji25   }; //jineng
//上阵函数集合 
pfux F3[MAXX]{ NULL,tmphui ,tmphui ,tmphui ,tmphui ,tmphui ,tmphui ,hui7   ,tmphui ,tmphui ,tmphui ,tmphui ,hui12  ,tmphui,tmphui ,tmphui ,tmphui,tmphui ,tmphui,tmphui ,tmphui ,tmphui ,tmphui ,tmphui ,tmphui ,tmphui };//huihe
//怒气函数集合 