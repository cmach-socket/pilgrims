#pragma once
int I1[MAXX]{ 0,5 ,5,0 ,5,-5,3,4 ,10,5 ,5 ,2 ,0 ,10,10,5 ,0 ,10,10,5 ,5  ,0 ,0 ,5 };//gongji
int	I2[MAXX]{ 0,5 ,5,0 ,5,0 ,0,4 ,10,5 ,5 ,2 ,0 ,10,10,5 ,0 ,0 ,10,5 ,5  ,10,2 ,5 };//fanci
int	I3[MAXX]{ 0,10,5,15,2,3 ,3,20,5 ,15,7 ,3 ,10,5 ,5 ,7 ,10,10,5 ,5 ,5  ,10,12,10 };//xue
int	I4[MAXX]{ 0,1 ,1,0 ,1,1 ,1,1 ,1 ,1 ,1 ,3 ,0 ,1 ,1 ,1 ,0 ,2 ,1 ,1 ,5  ,0 ,0 ,0 };//gjcishu
int	I5[MAXX]{ 0,1 ,2,1 ,1,3 ,3,1 ,1 ,1 ,1 ,2 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1  ,1 ,1 ,1 };//shecheng
int	I6[MAXX]{ 0,0 ,0,0 ,0,0 ,0,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0  ,0 ,0 ,0 };//dun
int	I7[MAXX]{ 0,0 ,0,0 ,0,0 ,0,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,2 ,1 ,0 ,0  ,0 ,0 ,0 };//lingjcs
int	I8[MAXX]{ 0,5 ,5,5 ,2,5 ,5,20,10,15,5 ,5 ,5 ,10,10,5 ,5 ,10,7 ,5 ,5  ,5 ,5 ,15 };//dianshu
int	I9[MAXX]{ 0,0 ,0,0 ,0,0 ,0,0 ,0 ,5 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0  ,0 ,0 ,0 };//xixue
int	I10[MAXX]{ 0,0 ,0,0 ,0,0 ,0,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0  ,0 ,0 ,0 };//boolpojia
int	I11[MAXX]{ 0,1 ,2,1 ,1,3 ,3,1 ,1 ,1 ,1 ,2 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1  ,1 ,1 ,1 };//paishu
int	I12[MAXX]{ 0,0 ,0,0 ,0,0 ,0,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0  ,0 ,1 ,0 };//qianfeng
int	I13[MAXX]{ 1,1 ,1,1 ,1,1 ,1,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1  ,1 ,1 ,1 };//boolji
int	I14[MAXX]{ 0,0 ,0,0 ,0,0 ,0,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0  ,0 ,0 ,0 };//bihu
int	I15[MAXX]{ 0,0 ,0,0 ,0,1 ,0,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0  ,0 ,0 ,0 };//dianji
int	I16[MAXX]{ 0,1 ,2,3 ,4,5 ,6,7 ,8 ,9 ,10,11,12,13,14,15,16,17,18,19,-20,21,22,23 };//bian
int I17[MAXX]{ 0,10,5,15,2,3 ,3,20,5 ,15,8 ,3 ,10,5 ,5 ,7 ,10,10,5 ,5 ,5  ,10,12,10 };//maxxue
int FDI[MAXX]{ 0,5,1,0,5,3 };
int FBI[MAXX]{ 0,1001,1002,1003,1004,1005 };
int WDI[MAXX]{ 0,5,5 };
int WBI[MAXX]{ 0,2001,2002 };
int NAI[MAXX]{ 0,2,2 };
string NAME[MAXX]{ "\0","����","����","�ؼ�","����","����","���","����","Ӣ��","������","��ʯ","��","��Ĭ","ִ����","��","��ì","����","�Ѿ�","����","�˰�","˫��","��","����","ڶг" };
string HNAME[MAXX]{ "\0","ľͷ","�´�","�����ϸ�","BUG����","�ݲ�","��ֽ","����ľͷ","Ӣ��","��Ѫ��","ǰ��ٺ�","BUG�ս���","�ؼ������","ϸ��","��ľͷ","Ц��Ȯ","����","�Ѿ�","����","22","33","����ľͷ","�Ʒ淴��","ڶг" };
//ʿԱ���� 
string FNA[MAXX]{ "\0","��ɱ","����","������","�籩","����" };
string HFNA[MAXX]{ "\0","������","����","��������","�籩","����" };
//�������� 
string WNA[MAXX]{ "\0","y12���ⲽǹ","���ȼ�" };
string HWNA[MAXX]{ "\0","ս��ȭ��","���ȼ�" };
//�������� 
pfu FA[MAXX]{ NULL,fa1,fa2,fa3,fa4,fa5 };
//�������� 
pfu WU[MAXX]{ NULL,wu1,wu2 };
//�������� 
pfux F1[MAXX]{ NULL,tmpyuan,tmpyuan,tmpyuan,tmpyuan,tmpyuan,tmpyuan,tmpyuan,tmpyuan,tmpyuan,tmpyuan,tmpyuan,tmpyuan,yuan13,tmpyuan,tmpyuan,tmpyuan,yuan17,tmpyuan,yuan19,tmpyuan,tmpyuan,tmpyuan,tmpyuan };//yuannian
//Թ������� 
pfux F2[MAXX]{ NULL,tmpji  ,tmpji  ,tmpji  ,tmpji  ,tmpji  ,tmpji  ,tmpji  ,tmpji  ,tmpji  ,tmpji  ,tmpji  ,tmpji  ,tmpji ,tmpji  ,tmpji,  ji16   ,tmpji ,tmpji  ,tmpji ,tmpji  ,tmpji  ,tmpji  ,ji23 }; //jineng
//���������� 
pfux F3[MAXX]{ NULL,tmphui ,tmphui ,tmphui ,tmphui ,tmphui ,tmphui ,hui7   ,tmphui ,tmphui ,tmphui ,tmphui ,hui12  ,tmphui,tmphui ,tmphui ,tmphui,tmphui ,tmphui,tmphui ,tmphui ,tmphui ,tmphui ,tmphui };//huihe
//ŭ���������� 