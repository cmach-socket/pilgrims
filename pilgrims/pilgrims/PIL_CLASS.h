#pragma once
typedef void(*pfu)();//法术/武器使用函数 
typedef void(*pfux)(int, int, int);//士员 上阵/怒气/怨念函数 
class xiaobin {//士员类 
public:
	int gongji,//攻击 
		fanci,//反刺 
		xue,//血量 
		gjcishu,//攻击次数 
		shecheng,//射程 
		dun,//护盾 
		lingjcs,//临时攻击次数 
		dianshu,//点数 
		xixue,//吸血 
		boolpojia,//破甲 
		paishu,//排数 
		qianfeng,//前锋 
		boolji,//沉默 
		bihu,//庇护 
		dianji,//电击 
		bian,//编号 
		a,
		b,
		c,
		maxxue,//生命上限 
		tmp[MAXTMP];//临时数组 
	string name;//名字 
	pfux yuan, ji, hui;//怨念/上阵/怒气 
	void Xiaobin(string n, int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8, int i9, int i10, int i11, int i12, int i13, int i14, int i15, int i16, int i17, pfux f1, pfux f2, pfux f3) {
		//加载函数 
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
	xiaobin() {//构造函数 
		return;
	}
	void yuannian() {//怨念绑定 
		yuan(a, b, c);
		return;
	}
	void jineng() {// 上阵绑定 
		ji(a, b, c);
		return;
	}
	void huihe() {//怒气绑定 
		hui(a, b, c);
		return;
	}
};
class fashu {//法术类 
public:
	string name;//名字 
	int dianshu,//点数 
		bian;//编号 
	pfu p;//使用 
	fashu() {//构造函数 
		return;
	}
	void Fashu(string n, pfu tmpp, int d, int b) {//加载函数 
		name = n;
		p = tmpp;
		dianshu = d;
		bian = b;
	}
	void use() {//使用函数 
		p();
		return;
	}
};
class wuqi {//武器类 
public:
	int naiju,//耐久 
		dianshu,//点数 
		bian;//编号 
	string name;//名字 
	pfu p;//使用 
	wuqi() {//构造函数 
		return;
	}
	void Wuqi(string n, pfu tmpp, int d, int na, int b) {//加载函数 
		name = n;
		p = tmpp;
		dianshu = d;
		naiju = na;
		bian = b;
	}
	void use() {//使用函数 
		p();
		return;
	}
};
class abc {//坐标三元组
public:
	int a,
		b,
		c;
	abc(int aa, int bb, int cc) {
		a = aa, b = bb, c = cc;
	}
};