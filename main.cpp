#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "sortingAlgo.h"

void greeting() {
	system("cls");

	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "|               Sorting Algorithm Visualizer                 |" << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;

	std::cout << "| " << "\033[33m" << "1. " << "\033[0m" << "Bubble Sort                                             |" << std::endl;
	std::cout << "| " << "\033[33m" << "2. " << "\033[0m" << "Selection Sort                                          |" << std::endl;
	std::cout << "| " << "\033[33m" << "3. " << "\033[0m" << "Insertion Sort                                          |" << std::endl;
	std::cout << "| " << "\033[33m" << "4. " << "\033[0m" << "Merge Sort                                              |" << std::endl;
	std::cout << "| " << "\033[33m" << "5. " << "\033[0m" << "Quick Sort                                              |" << std::endl;
	std::cout << "| " << "\033[33m" << "6. " << "\033[0m" << "Heap Sort                                               |" << std::endl;
	std::cout << "| " << "\033[33m" << "7. " << "\033[0m" << "Exit                                                    |" << std::endl;

	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "Enter your choice: ";
}

int main() {

	int n = 100;
	int m = 400;
	
	sorting object;


	while(true) {

		int select = 1;
		greeting();
		std::cin >> select;

		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\033[31m" << "Invalid choice." << "\033[0m" << std::endl;
			system("Pause");
			greeting();
			std::cin >> select;
		}
		
		if (select == 7) {
			std::cout << "\033[32m" << "Thank you for using the application." << "\033[0m" << std::endl;
			system("Pause");
			break;
		}
		if (select > 7) {
			std::cout << "\033[31m" << "Invalid choice." << "\033[0m" << std::endl;
			system("Pause");
			continue;
		} 

		sf::RenderWindow window(sf::VideoMode(n * 10, m + 50), "Sorting Algorithm Visualiser");

		sf::Music music;
		music.openFromFile("bell.wav");

		while (window.isOpen()) {

			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			if (select == 1) object.bubbleSort(window, n, m);
			else if (select == 2) object.selectionSort(window, n, m);
			else if (select == 3) object.insertionSort(window, n, m);
			else if (select == 4) object.mergeSort(window, n, m);
			else if (select == 5) object.quickSort(window, n, m);
			else if (select == 6) object.heapSort(window, n, m);

			music.play();

			while (window.isOpen()) {
				sf::Event event;
				while (window.pollEvent(event)) {
					if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
						window.close();
					}
				}
			}

		}

	}

}