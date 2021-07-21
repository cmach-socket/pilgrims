#pragma once
namespace cmy {
	template<class T1>
	T1 input(std::string out) {
		std::cout << out;
		T1 a;
		std::cin >> a;
		return a;
	}
	void slowout(std::string s) {
		for (int i = 0; i < s.size(); i++) {
			printf("%c", s[i]);
			Sleep(20);
		}
		return;
	}
}