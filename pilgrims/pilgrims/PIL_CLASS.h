#pragma once
typedef void(*pfu)();//����/����ʹ�ú��� 
typedef void(*pfux)(int, int, int);//ʿԱ ����/ŭ��/Թ��� 
class xiaobin {//ʿԱ�� 
public:
	int gongji,//���� 
		fanci,//���� 
		xue,//Ѫ�� 
		gjcishu,//�������� 
		shecheng,//��� 
		dun,//���� 
		lingjcs,//��ʱ�������� 
		dianshu,//���� 
		xixue,//��Ѫ 
		boolpojia,//�Ƽ� 
		paishu,//���� 
		qianfeng,//ǰ�� 
		boolji,//��Ĭ 
		bihu,//�ӻ� 
		dianji,//��� 
		bian,//��� 
		a,
		b,
		c,
		maxxue,//�������� 
		tmp[MAXTMP];//��ʱ���� 
	string name;//���� 
	pfux yuan, ji, hui;//Թ��/����/ŭ�� 
	void Xiaobin(string n, int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8, int i9, int i10, int i11, int i12, int i13, int i14, int i15, int i16, int i17, pfux f1, pfux f2, pfux f3) {
		//���غ��� 
		name = n;
		gongji = i1,
		fanci = i2,
		xue = i3,
		gjcishu = i4,
		shecheng = i5,
		dun = i6,
		lingjcs = i7,
		dianshu = i8,
		xixue = i9,
		boolpojia = i10,
		paishu = i11;
		qianfeng = i12;
		boolji = i13;
		bihu = i14;
		dianji = i15;
		bian = i16;
		maxxue = i17;
		yuan = f1;
		ji = f2;
		hui = f3;
	}
	xiaobin() {//���캯�� 
		return;
	}
	void yuannian() {//Թ��� 
		yuan(a, b, c);
		return;
	}
	void jineng() {// ����� 
		ji(a, b, c);
		return;
	}
	void huihe() {//ŭ���� 
		hui(a, b, c);
		return;
	}
};
class fashu {//������ 
public:
	string name;//���� 
	int dianshu,//���� 
		bian;//��� 
	pfu p;//ʹ�� 
	fashu() {//���캯�� 
		return;
	}
	void Fashu(string n, pfu tmpp, int d, int b) {//���غ��� 
		name = n;
		p = tmpp;
		dianshu = d;
		bian = b;
	}
	void use() {//ʹ�ú��� 
		p();
		return;
	}
};
class wuqi {//������ 
public:
	int naiju,//�;� 
		dianshu,//���� 
		bian;//��� 
	string name;//���� 
	pfu p;//ʹ�� 
	wuqi() {//���캯�� 
		return;
	}
	void Wuqi(string n, pfu tmpp, int d, int na, int b) {//���غ��� 
		name = n;
		p = tmpp;
		dianshu = d;
		naiju = na;
		bian = b;
	}
	void use() {//ʹ�ú��� 
		p();
		return;
	}
};
class abc {//������Ԫ��
public:
	int a,
		b,
		c;
	abc(int aa, int bb, int cc) {
		a = aa, b = bb, c = cc;
	}
};