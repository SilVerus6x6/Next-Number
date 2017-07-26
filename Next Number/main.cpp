#include <iostream>
#include <conio.h>
#include <vector>
#include <chrono>
#include <string>
void rob2(std::string &t, int n, int tr=0) {
	for (unsigned int i = n; i < t.length(); i++) {
		for (unsigned int j = i+1; j < t.length(); j++) {
			if ((t[j] < t[i]&&tr==0)||(t[j]>t[i]&&tr==1)) {
				char tmp = t[i];
				t[i] = t[j];
				t[j] = tmp;
			}
		}
	}
}
int rob(std::string &t, unsigned int tr=0) {
	for (unsigned int i = t.length()-1; i >= tr; i--) {
		for (unsigned int j = i-1; j >= tr; j--) {
			if ((t[j] < t[i]&&tr==0)||(t[j]>t[i]&&tr==1)) {
				char tmp = t[i];
				t[i] = t[j];
				t[j] = tmp;
				rob2(t, j+1,tr);
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
	int ilosc = 0;
	std::string liczba;
	std::cout << "How many numbers to check (0 for example): ";
	std::cin >> ilosc;
	while (std::cin.fail()||ilosc<0){
		std::cin.clear();
		std::cin.ignore(256, '\n');
		system("cls");
		std::cout << "How many numbers to check (0 for example): ";
		std::cin >> ilosc;
	}
	if (ilosc == 0) {
		liczby.reserve(5);
		start(liczby);
	}
	else {
		liczby.reserve(ilosc);
		for (int i = 0; i < ilosc; i++) {
			std::cout << "Enter next number (" << i + 1 << "): ";
			std::cin >> liczba;
			liczby.push_back(liczba);
		}
	}
	int s = 0;
	int licznik = 0;
	int tryb = 0;
	std::string t = "";
	for (unsigned int i = 0; i < liczby.size(); i++) {
		tryb = 0;
		if (liczby[i][0] == '-')tryb = 1;
		system("cls");
		licznik = 0;
		std::chrono::high_resolution_clock::time_point tstart = std::chrono::high_resolution_clock::now();
		do {
			std::cout << liczby[i].c_str() << std::endl;
			s = rob(liczby[i],tryb);
			licznik++;
		} while (s == 1);
		std::chrono::high_resolution_clock::time_point tstop = std::chrono::high_resolution_clock::now();
		std::cout << "Number count: " << licznik << std::endl<<"Time: "<< std::chrono::duration_cast<std::chrono::milliseconds>(tstop - tstart).count()<<" ms"<<std::endl;
		_getch();
	}
}