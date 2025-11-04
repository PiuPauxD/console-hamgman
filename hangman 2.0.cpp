#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

string THE_WORD;

int wrong = 0;
string used = "";
char userGuess;

char guess();
void check();

int main() {
	system("chcp 1251");

	const int MAX_WRONG = 8;
	vector<string> words;
	words.push_back("ответ");
	words.push_back("подсказка");
	words.push_back("мышь");
	srand (static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	THE_WORD = words[0];
	string soFar(THE_WORD.size(), '_') ;

	cout << "Добро пожаловать в Висилецу. Удачи!\n";

	while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
		cout << "\n\nУ вас " << (MAX_WRONG - wrong);
		cout << " допустимых ошибок.\n";
		cout << "\nВы использовали слдедующие буквы:\n" << used << endl;
		cout << "\nПока что, слово:\n" << soFar << endl;

		guess();

		used += userGuess;
		check();
	}

	if (wrong == MAX_WRONG) {
		cout << "\nВас повесили!";
	}
	else {
		cout << "\nВы победили!";
	}
	cout << "\nЗагаданное слово: " << THE_WORD << endl;

	return 0;
}

char guess() {
	char guess;
	cout << "\n\nВведите букву: "; cin >> guess;
	while (used.find(guess) != string::npos) {
		cout << "\nВы уже отгадали " << guess << endl;
		cout << "Введите букву: "; cin >> guess;
	}
	
	return guess;
}

void check() {
	string soFar(THE_WORD.size(), '_');
	if (THE_WORD.find(userGuess) != string::npos) {
		cout << "Верно! " << userGuess << " есть в слове.\n";
		for (int i = 0; i < THE_WORD.length(); ++i) {
			if (THE_WORD[i] == userGuess) {
				soFar[i] = userGuess;
			}
		}
	}
	else {
		cout << "Увы, " << userGuess << " нет в слове.\n";
		++wrong;
	}
}