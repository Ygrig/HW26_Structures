#include <iostream>
#include <string>

struct movies {
	std::string title;
	int year;
	std::string genre;
	unsigned int duration;
	unsigned int price;
};

void show_movie(movies &M) { 
	std::cout << "Title: " << M.title << '\n';
	std::cout << "Year: " << M.year << '\n';
	std::cout << "Genre: " << M.genre << '\n';
	std::cout << "Duration: " << M.duration << " min"<<'\n';
	std::cout << "Price: " << M.price << " rub"<<'\n';
}

void expensive(movies& M, movies& N, movies& K) {
	movies* pM = &M;
	movies* pN = &N;
	movies* pK = &K;
	(pM->price) > (pN->price) ? show_movie(M) : ((pN->price) > (pK->price) ? show_movie(N) : show_movie(K));
}

void update_info(movies&M) {
	int n;
	std::cout << "Select type of info for update:\n"; 
	std::cout << "1.Title\n2.Year\n3.Genre\n4.Duration\n5.Price\n";
	std::cin >> n;
	switch (n) {
	case 1: std::cout << "New title: " << '\n';
		std::cin.ignore();
		getline(std::cin, M.title);
		break;
	case 2: std::cout << "New year: " << '\n';
		std::cin >> M.year;
		break;
	case 3: std::cout << "New genre: " << '\n'; 
		std::cin.ignore();
		getline(std::cin, M.genre);
		break;
	case 4: std::cout << "New duration: " << '\n'; 
		std::cin >> M.duration;
		break;
	case 5: std::cout << "New price: " << '\n';
		std::cin >> M.price;
		break;
	default: std::cout << "Input error.\n";
	}
	}

int main() {
	int n;
	movies M1 = { "A Good Year",2006,"romantic comedy",118, 200 };
	movies M2 = { "The Big Short",2015,"biographical drama",130, 215 };
	movies M3 = { "The Best Offer",2013,"thriller",131, 225 };

	std::cout << "Task 26.1 Show_movie function\n";
	show_movie(M1);
	std::cout << '\n';

	std::cout << "Task 26.2 The most expensive CD\n";
	expensive(M1, M2, M3);
	std::cout << '\n';
	
	std::cout << "Task 26.3 Info update\n";
	update_info(M1);
	std::cout << "Information updated.\n\n";
	show_movie(M1);
	
	return 0;
}