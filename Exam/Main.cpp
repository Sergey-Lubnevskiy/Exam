#include <iostream>
#include <Windows.h>
#include <vector>
#include<ctime>
#include <algorithm>

using namespace std;

int c = 0;
int hp = 0;
const int nof = -1;

class Player
{
private:

	int norm(int number)
	{
		return number > 0 ? number : 0;
	}

	int FSymbols{ 0 };
	int health{ 0 };
	int pArr{ 10 };

	string sWord;

public:

	Player(const string& selectWord, int health) : sWord{ selectWord }, health{ health }
	{
	}

	void setFSymbols(int count)
	{
		FSymbols = norm(count);
	}

	size_t getFSymbols() const
	{
		return FSymbols;
	}

	const string& getSWord() const
	{
		return sWord;
	}

	int getHealth() const
	{
		return health;
	}

	void setHealth(int health)
	{
		health = norm(health);
	}

	bool Die()
	{
		return health == 0;
	}
};

class Game
{
private:

	Player& player;
	const string* dicti;
	string FounLet;

public:
	clock_t t0 = clock();
	Game(Player& player, const std::string* dictionary) : player{ player }, dicti{ dictionary },
		FounLet(player.getSWord().size(), '_')
	{}
	void play()
	{
		cout << "Ñëîâî: ";
		for_each(player.getSWord().begin(), player.getSWord().end(), [](const auto e) {std::cout << '_' << " "; });

		char letter;

		string foundedLetters(player.getSWord().size(), '_');

		while (player.getFSymbols() < player.getSWord().size() && !player.Die())
		{

			cout << endl << "Óãàäàéòå áóêâó: ";
			cin >> letter;

			letter = toupper(letter);

			if (player.getSWord().find(letter) != nof)
			{
				cout << "Íó òàê è áûòü ïðàâåëüíî: ";

				for (int index{ 0 }; index < player.getSWord().size(); ++index)
				{
					if (player.getSWord()[index] == letter)
					{
						foundedLetters[index] = letter;
						player.setFSymbols(player.getFSymbols() + 1);
					}

					cout << foundedLetters[index] << " ";
				}
				c++;
			}
			else
			{
				player.setHealth(player.getHealth() - 1);
				cout << "Íåïðàâåëüíî, ó âàñ îñòàëîñü " << player.getHealth() << " ïûòîê" << endl;
				c++;
				hp++;
				switch (hp)
				{
				case 1:
					cout << "        $$$$$$$$$$$$$$$\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
					cout << " $                          $\n";
					break;
				case 2:
					cout << "        $$$$$$$$$$$$$$$\n";
					cout << "        |             $\n";
					cout << "        |             $\n";
					cout << "        |             $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
					cout << " $                          $\n";
					break;
				case 3:
					cout << "        $$$$$$$$$$$$$$$\n";
					cout << "        |             $\n";
					cout << "        |             $\n";
					cout << "        |             $\n";
					cout << "        O             $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
					cout << " $                          $\n";
					break;
				case 4:
					cout << "        $$$$$$$$$$$$$$$\n";
					cout << "        |             $\n";
					cout << "        |             $\n";
					cout << "        |             $\n";
					cout << "        O             $\n";
					cout << "        |             $\n";
					cout << "        |             $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
					cout << " $                          $\n";
				case 5:
					cout << "        $$$$$$$$$$$$$$$\n";
					cout << "        |             $\n";
					cout << "        |             $\n";
					cout << "        |             $\n";
					cout << "        |             $\n";
					cout << "        O             $\n";
					cout << "      / | \\           $\n";
					cout << "        |             $\n";
					cout << "       / \\            $\n";
					cout << "                      $\n";
					cout << "                      $\n";
					cout << " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
					cout << " $                          $\n";
					break;
				}
			}

		}
	}

	void inf()
	{
		clock_t t1 = clock();
		if (player.getFSymbols() == player.getSWord().size())
		cout << endl <<"Òàê è áûòü: Âû âûèãðàëè!" << endl;
		else 
		cout << "Âû ïðîèãðàëè, óãàäàâ" << player.getFSymbols() << " áóêàâ" << endl;
		cout << "Óøëî ïîïûòîê: " << c << endl;
		cout << "Âðåìÿ: " << (double)(t1 - t0) / CLOCKS_PER_SEC << endl;
	}
};

class Random
{
public:
	static int randRange(int begin, int end)
	{
		return rand() % (end - begin) + begin;
	}
	template<class T>
	static T getArray(const T vec[], int size)
	{
		return vec[randRange(0, size)];
	}
	template<class T>
	static T getVector(const vector<T> vec)
	{
		return vec[randRange(0, vec.size())];
	}
};

int main()
{
	srand(time(0));
	SetConsoleCP(1251);
	setlocale(0, "ru");

	cout << "You wanna play game? \"Âèñåëèöà\"" << endl;

	const int SIZE = 15 ;
	string words[SIZE]{ "ÊÎÐÅÍÜ","ÊÀÐÍÀÂÀË","ÂÅÒÅÐ","ÏÅ×ÀËÜ","ÏÎÁÅÃ","ÌÀÃ","ÇÀÊÀÒ","ÊÈÑËÎÒÀ","ÕÂÎÙ","ÃÎÐÀ","ÃÎËÎÄ","ÂÐÀÃ","ÓÒÊÀ","ÁÓÄÈËÜÍÈÊ","ÐÀÑÑÂÅÒ"};

	Player player(Random::getArray(words, SIZE), 5);
	Game game(player, words);

	game.play();
	game.inf();

	return 0;
}