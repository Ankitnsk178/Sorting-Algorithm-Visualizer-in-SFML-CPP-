#pragma once

#include<SFML/Graphics.hpp>



class sorting {

public:

	void bubbleSort(sf::RenderWindow& window, int n, int m);
	void selectionSort(sf::RenderWindow& window, int n, int m);
	void insertionSort(sf::RenderWindow& window, int n, int m);
	void mergeSort(sf::RenderWindow& window, int n, int m);
	void quickSort(sf::RenderWindow& window, int n, int m);
	void heapSort(sf::RenderWindow& window, int n, int m);

};