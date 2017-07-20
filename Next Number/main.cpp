#include <iostream>
#include <conio.h>
#include <vector>
#include <chrono>
void rob2(std::string &t, int n) {
	for (int i = n; i < t.length(); i++) {
		for (int j = i+1; j < t.length(); j++) {
			if (t[j] < t[i]) {
				char tmp = t[i];
				t[i] = t[j];
				t[j] = tmp;
			}
		}
	}
}
int rob(std::string &t) {
	for (int i = t.length()-1; i >= 0; i--) {
		for (int j = i-1; j >= 0; j--) {
			if (t[j] < t[i]) {
				char tmp = t[i];
				t[i] = t[j];
				t[j] = tmp;
				rob2(t, j+1);
				return 1;
			}
		}
	}
	return 0;
}
void start(std::vector<std::string>&l) {
	std::string t = "292761";
	l.push_back(t);
	t = "1234";
	l.push_back(t);
	t = "1243";
	l.push_back(t);
	t = "234765";
	l.push_back(t);
	t = "19000";
	l.push_back(t);
	t = "25451";
	l.push_back(t);
}
void main() {
	std::vector<std::string> liczby;
	liczby.reserve(5);
	start(liczby);
	int s = 0;
	int licznik = 0;
	std::string t = "";
	for (int i = 0; i < liczby.size(); i++) {
		system("cls");
		licznik = 0;
		std::chrono::high_resolution_clock::time_point tstart = std::chrono::high_resolution_clock::now();
		do {
			std::cout << liczby[i].c_str() << std::endl;
			s = rob(liczby[i]);
			licznik++;
		} while (s == 1);
		std::chrono::high_resolution_clock::time_point tstop = std::chrono::high_resolution_clock::now();
		std::cout << "Number count: " << licznik << std::endl<<"Time: "<< std::chrono::duration_cast<std::chrono::milliseconds>(tstop - tstart).count()<<" ms"<<std::endl;
		_getch();
	}
}