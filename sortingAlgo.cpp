#include "sortingAlgo.h"
#include <vector>
#include<cstdlib>
#include<ctime>
#include<SFML/Graphics.hpp>


int sleepTime = 100;

// Create an Array of n numbers

void getArr(std::vector<int> &arr, int n, int m) {
	std::srand(0);
	for (int i = 0; i < n; i++) {
		arr[i] = std::rand() % m + 1;
	}
}


// To Handle Events during execution of Algorithms 

void handleEvent(sf::RenderWindow& window, int low, int high) {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.close();
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) sleepTime = low;
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) sleepTime = high;
	}
	
}


// To Display the Shapes on the window

void drawShapes(sf::RenderWindow& window, std::vector<sf::RectangleShape> shape, int n) {
	window.clear();
	for (int k = 0; k < n; k++) window.draw(shape[k]);
	window.display();
	sf::sleep(sf::milliseconds(sleepTime));
}





// Bubble Sort

void sorting::bubbleSort(sf::RenderWindow& window, int n, int m){

	sleepTime = 200;

	std::vector<sf::RectangleShape> shape(n);
	std::vector<int> arr(n);
	getArr(arr, n, m);

	window.setFramerateLimit(240);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {

			for (int k = 0; k < n; k++) {
				shape[k].setSize(sf::Vector2f( 9 , arr[k]));
				shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
				shape[k].setOutlineThickness(0.5f);
				shape[k].setOutlineColor(sf::Color::Black);
				if (k > n-1-i) shape[k].setFillColor(sf::Color::Green);
				else if(k == j || k == j + 1) shape[k].setFillColor(sf::Color::Cyan);
				else shape[k].setFillColor(sf::Color::Red);
			}

			handleEvent(window, 200, 1);

			drawShapes(window, shape, n);

			if (arr[j] > arr[j + 1]) std::swap(arr[j], arr[j + 1]);

		}
	}

	for (int k = 0; k < n; k++) {
		shape[k].setSize(sf::Vector2f(9, arr[k]));
		shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
		shape[k].setOutlineThickness(0.5f);
		shape[k].setOutlineColor(sf::Color::Black);
		shape[k].setFillColor(sf::Color::Green);
	}

	handleEvent(window, 200, 1);
	drawShapes(window, shape, n);

}





// Selection Sort

void sorting::selectionSort(sf::RenderWindow& window, int n, int m){

	sleepTime = 100;

	std::vector<sf::RectangleShape> shape(n);
	std::vector<int> arr(n);
	getArr(arr, n, m);

	window.setFramerateLimit(380);

	for (int i = 0; i < n; i++) {
		
		int index = i;
		
		for (int j = i; j < n; j++) {

			if (arr[index] > arr[j]) index = j;

			for (int k = 0; k < n; k++) {
				shape[k].setSize(sf::Vector2f(9, arr[k]));
				shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
				shape[k].setOutlineThickness(0.5f);
				shape[k].setOutlineColor(sf::Color::Black);
				if (k < i) shape[k].setFillColor(sf::Color::Green);
				else if (k == index || k == i) shape[k].setFillColor(sf::Color::Cyan);
				else if (k == j) shape[k].setFillColor(sf::Color::Magenta);
				else shape[k].setFillColor(sf::Color::Red);
			}

			handleEvent(window, 100, 1);
			drawShapes(window, shape, n);

		}

		if (index == i) continue;

		for (int k = 0; k < n; k++) {
			shape[k].setSize(sf::Vector2f(9, arr[k]));
			shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
			shape[k].setOutlineThickness(0.5f);
			shape[k].setOutlineColor(sf::Color::Black);
			if (k < i) shape[k].setFillColor(sf::Color::Green);
			else if (k == index || k == i) shape[k].setFillColor(sf::Color::Cyan);
			else shape[k].setFillColor(sf::Color::Red);
		}

		std::swap(arr[index], arr[i]);

		handleEvent(window, 100, 1);

		drawShapes(window, shape, n);

	}

	for (int k = 0; k < n; k++) {
		shape[k].setSize(sf::Vector2f(9, arr[k]));
		shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
		shape[k].setOutlineThickness(0.5f);
		shape[k].setOutlineColor(sf::Color::Black);
		shape[k].setFillColor(sf::Color::Green);
	}

	handleEvent(window, 100, 1);
	drawShapes(window, shape, n);


}



// Insertion Sort

void sorting::insertionSort(sf::RenderWindow& window, int n, int m){

	sleepTime = 100;

	std::vector<sf::RectangleShape> shape(n);
	std::vector<int> arr(n);
	getArr(arr, n, m);

	window.setFramerateLimit(120);

	for (int i = 1; i < n; i++) {

		int j = i-1;
		int element = arr[i];

		for (int k = 0; k < n; k++) {
			shape[k].setSize(sf::Vector2f(9, arr[k]));
			shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
			shape[k].setOutlineThickness(0.5f);
			shape[k].setOutlineColor(sf::Color::Black);
			if (k == i) shape[k].setFillColor(sf::Color::Cyan);
			else if (k < i) shape[k].setFillColor(sf::Color::Green);
			else shape[k].setFillColor(sf::Color::Red);
		}

		handleEvent(window, 100, 0);
		drawShapes(window, shape, n);

		while (j >= 0 && arr[j] > element) {
			arr[j+1] = arr[j];
			j--;

			for (int k = 0; k < n; k++) {
				shape[k].setSize(sf::Vector2f(9, arr[k]));
				shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
				shape[k].setOutlineThickness(0.5f);
				shape[k].setOutlineColor(sf::Color::Black);

				if (k > j && k <= i) shape[k].setFillColor(sf::Color::Yellow); 
				else if (k < i) shape[k].setFillColor(sf::Color::Green); 
				else shape[k].setFillColor(sf::Color::Red);
			}
			
			handleEvent(window, 100, 0);
			drawShapes(window, shape, n);

		}

		arr[j + 1] = element;

		for (int k = 0; k < n; k++) {
			shape[k].setSize(sf::Vector2f(9, arr[k]));
			shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
			shape[k].setOutlineThickness(0.5f);
			shape[k].setOutlineColor(sf::Color::Black);

			if (k <= i) shape[k].setFillColor(sf::Color::Green);
			else shape[k].setFillColor(sf::Color::Red);
		}

		handleEvent(window, 100, 0);
		drawShapes(window, shape, n);
		
	}

	for (int i = 0; i < n; i++) {
		
		for (int k = 0; k < n; k++) {
			shape[k].setSize(sf::Vector2f(9, arr[k]));
			shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
			shape[k].setOutlineThickness(0.5f);
			shape[k].setOutlineColor(sf::Color::Black);
			if (k <= i) shape[k].setFillColor(sf::Color::Green);
			else shape[k].setFillColor(sf::Color::Red);
		}

		handleEvent(window, 100, 0);
		drawShapes(window, shape, n);
	}

}




// Merge Sort

void merge(sf::RenderWindow& window, int s, int mid, int e, int m, std::vector<int>& arr, std::vector<sf::RectangleShape>& shape, int n) {
	std::vector<int> temp1(arr.begin() + s, arr.begin() + mid + 1);
	std::vector<int> temp2(arr.begin() + mid+ 1, arr.begin() + e + 1);

	int index = s;
	int i = 0;
	int j = 0;


	for (int k = s; k <= e; k++) {
		shape[k].setSize(sf::Vector2f(9, arr[k]));
		shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
		shape[k].setOutlineThickness(0.5f);
		shape[k].setOutlineColor(sf::Color::Black);
		shape[k].setFillColor(sf::Color::Yellow);
	}

	handleEvent(window, 200, 0);
	drawShapes(window, shape, n);

	while (i < temp1.size() && j < temp2.size()) {
		
		for (int k = s; k <= e; k++) {
			shape[k].setSize(sf::Vector2f(9, arr[k]));
			shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
			shape[k].setOutlineThickness(0.5f);
			shape[k].setOutlineColor(sf::Color::Black);
			if (k < index) shape[k].setFillColor(sf::Color::Green);
			else shape[k].setFillColor(sf::Color::Yellow);
		}

		handleEvent(window, 200, 0);
		drawShapes(window, shape, n);

		
		if (temp1[i] < temp2[j]) arr[index++] = temp1[i++];
		else arr[index++] = temp2[j++];

	}

	
	while (i < temp1.size()) 
		arr[index++] = temp1[i++];

	while (j < temp2.size()) 
		arr[index++] = temp2[j++];

	for (int k = s; k <= e; k++) {
		shape[k].setSize(sf::Vector2f(9, arr[k]));
		shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
		shape[k].setOutlineThickness(0.5f);
		shape[k].setOutlineColor(sf::Color::Black);
		shape[k].setFillColor(sf::Color::Green);
	}

	handleEvent(window, 200, 0);
	drawShapes(window, shape, n);

	

}

void mergeSortUtil(sf::RenderWindow& window, int s, int e, int m, std::vector<int> &arr, std::vector<sf::RectangleShape> &shape, int n) {

	if (s >= e) return;

	int mid = s + (e-s)/2;

	mergeSortUtil(window, s, mid, m, arr, shape, n);
	mergeSortUtil(window, mid+1, e, m, arr, shape, n);

	for (int k = 0; k < n; k++) {
		shape[k].setSize(sf::Vector2f(9, arr[k]));
		shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
		shape[k].setOutlineThickness(0.5f);
		shape[k].setOutlineColor(sf::Color::Black);
		shape[k].setFillColor(sf::Color::Red);
	}

	handleEvent(window, 200, 0);
	drawShapes(window, shape, n);

	merge(window, s, mid, e, m, arr, shape, n);

}


void sorting::mergeSort(sf::RenderWindow& window, int n, int m){

	sleepTime = 200;
	
	std::vector<sf::RectangleShape> shape(n);
	std::vector<int> arr(n);
	getArr(arr, n, m);

	window.setFramerateLimit(80);

	for (int k = 0; k < n; k++) {
		shape[k].setSize(sf::Vector2f(9, arr[k]));
		shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
		shape[k].setOutlineThickness(0.5f);
		shape[k].setOutlineColor(sf::Color::Black);
		shape[k].setFillColor(sf::Color::Red);
	}

	handleEvent(window, 200, 0);
	drawShapes(window, shape, n);

	mergeSortUtil(window, 0, n-1, m, arr, shape, n);

	for (int k = 0; k < n; k++) {
		shape[k].setSize(sf::Vector2f(9, arr[k]));
		shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
		shape[k].setOutlineThickness(0.5f);
		shape[k].setOutlineColor(sf::Color::Black);
		shape[k].setFillColor(sf::Color::Green);
	}

	handleEvent(window, 200, 0);
	drawShapes(window, shape, n);

}






// Quick Sort


void quickSortUtil(sf::RenderWindow& window, int s, int e, int m, std::vector<int>& arr, std::vector<sf::RectangleShape>& shape, int n) {

	if (s >= e) return;

	int pivot = arr[s];

	int pindex = 0;
	int cnt = 0;

	std::vector<bool> found(n, 0);

	for (int i = s+1; i <= e; i++) {
		if (arr[i] < pivot) {
			found[i] = 1;
			cnt++;
		}

		for (int k = 0; k < n; k++) {
			shape[k].setSize(sf::Vector2f(9, arr[k]));
			shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
			shape[k].setOutlineThickness(0.5f);
			shape[k].setOutlineColor(sf::Color::Black);
			if (found[k] == 1) shape[k].setFillColor(sf::Color::Magenta);
			else if (k == i) shape[k].setFillColor(sf::Color::Cyan);
			else if(k >=s && k<=e) shape[k].setFillColor(sf::Color::Yellow);
			else shape[k].setFillColor(sf::Color::Red);
		}

		handleEvent(window, 100, 0);
		drawShapes(window, shape, n);

	}
	
	pindex = s + cnt;

	for (int k = 0; k < n; k++) {
		shape[k].setSize(sf::Vector2f(9, arr[k]));
		shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
		shape[k].setOutlineThickness(0.5f);
		shape[k].setOutlineColor(sf::Color::Black);
		if (k == pindex || k == s) shape[k].setFillColor(sf::Color::Cyan);
		else if (k > s && k <= e) shape[k].setFillColor(sf::Color::Yellow);
		else shape[k].setFillColor(sf::Color::Red);
	}

	handleEvent(window, 100, 0);
	drawShapes(window, shape, n);


	std::swap(arr[s], arr[pindex]);

	for (int k = 0; k < n; k++) {
		shape[k].setSize(sf::Vector2f(9, arr[k]));
		shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
		shape[k].setOutlineThickness(0.5f);
		shape[k].setOutlineColor(sf::Color::Black);
		if (k == pindex || k == s) shape[k].setFillColor(sf::Color::Cyan);
		else if (k > s && k <= e) shape[k].setFillColor(sf::Color::Yellow);
		else shape[k].setFillColor(sf::Color::Red);
	}

	handleEvent(window, 100, 0);
	drawShapes(window, shape, n);

	int i = s;
	int j = pindex + 1;

	while (i < pindex && j <= e) {
		while (i < pindex && arr[i] < arr[pindex]) i++;
		while (j <= e && arr[j] >= arr[pindex]) j++;

		for (int k = 0; k < n; k++) {
			shape[k].setSize(sf::Vector2f(9, arr[k]));
			shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
			shape[k].setOutlineThickness(0.5f);
			shape[k].setOutlineColor(sf::Color::Black);
			if (k == pindex) shape[k].setFillColor(sf::Color::Green);
			else if(k == i || k == j) shape[k].setFillColor(sf::Color::Cyan);
			else if (k >= s && k <= e) shape[k].setFillColor(sf::Color::Yellow);
			else shape[k].setFillColor(sf::Color::Red);
		}

		handleEvent(window, 100, 0);
		drawShapes(window, shape, n);

		if(i < pindex && j <= e ) std::swap(arr[i], arr[j]);


		for (int k = 0; k < n; k++) {
			shape[k].setSize(sf::Vector2f(9, arr[k]));
			shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
			shape[k].setOutlineThickness(0.5f);
			shape[k].setOutlineColor(sf::Color::Black);
			if (k == pindex) shape[k].setFillColor(sf::Color::Green);
			else if (k == i || k == j) shape[k].setFillColor(sf::Color::Cyan);
			else if (k >= s && k <= e) shape[k].setFillColor(sf::Color::Yellow);
			else shape[k].setFillColor(sf::Color::Red);
		}

		handleEvent(window, 100, 0);
		drawShapes(window, shape, n);

	}

	quickSortUtil(window, s, pindex - 1, m, arr, shape, n);
	quickSortUtil(window, pindex+1, e, m, arr, shape, n);

}

void sorting::quickSort(sf::RenderWindow& window, int n, int m){

	sleepTime = 100;

	std::vector<sf::RectangleShape> shape(n);
	std::vector<int> arr(n);
	getArr(arr, n, m);

	window.setFramerateLimit(120);

	for (int k = 0; k < n; k++) {
		shape[k].setSize(sf::Vector2f(9, arr[k]));
		shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
		shape[k].setOutlineThickness(0.5f);
		shape[k].setOutlineColor(sf::Color::Black);
		shape[k].setFillColor(sf::Color::Red);
	}

	handleEvent(window, 100, 0);
	drawShapes(window, shape, n);

	quickSortUtil(window, 0, n - 1, m, arr, shape, n);

	for (int i = 0; i < n; i++) {
		
		for (int k = 0; k < n; k++) {
			shape[k].setSize(sf::Vector2f(9, arr[k]));
			shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
			shape[k].setOutlineThickness(0.5f);
			shape[k].setOutlineColor(sf::Color::Black);
			if (k <= i) shape[k].setFillColor(sf::Color::Green);
			else shape[k].setFillColor(sf::Color::Red);
		}

		handleEvent(window, 100, 0);
		drawShapes(window, shape, n);
	}

}






// Heap Sort

void heapify(std::vector<int>& arr, int index, int size, sf::RenderWindow& window, std::vector<sf::RectangleShape>& shape, int n, int m, int sorted) {

	int largestIndex = index;
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;

	if (leftChild < size && arr[largestIndex] < arr[leftChild]) largestIndex = leftChild;
	if (rightChild < size && arr[largestIndex] < arr[rightChild]) largestIndex = rightChild;

	for (int k = 0; k < n; k++) {
		shape[k].setSize(sf::Vector2f(9, arr[k]));
		shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
		shape[k].setOutlineThickness(0.5f);
		shape[k].setOutlineColor(sf::Color::Black);
		if (k >= sorted) shape[k].setFillColor(sf::Color::Green);  
		else if (k == index) shape[k].setFillColor(sf::Color::Magenta);  
		else if (k == leftChild || k == rightChild) shape[k].setFillColor(sf::Color::Yellow); 
		else shape[k].setFillColor(sf::Color::Red); 
	}

	handleEvent(window, 500, 0);
	drawShapes(window, shape, n);

	if (largestIndex == index) return;

	std::swap(arr[largestIndex], arr[index]);

	heapify(arr, largestIndex, size, window, shape, n, m, sorted);

}



void sorting::heapSort(sf::RenderWindow& window, int n, int m){

	sleepTime = 500;

	std::vector<sf::RectangleShape> shape(n);
	std::vector<int> arr(n);
	getArr(arr, n, m);

	window.setFramerateLimit(60);

	for (int k = 0; k < n; k++) {
		shape[k].setSize(sf::Vector2f(9, arr[k]));
		shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
		shape[k].setOutlineThickness(0.5f);
		shape[k].setOutlineColor(sf::Color::Black);
		shape[k].setFillColor(sf::Color::Red);
	}

	handleEvent(window, 500, 0);
	drawShapes(window, shape, n);


	for (int i = (n / 2 - 1); i >= 0; i--) {
		heapify(arr, i, n, window, shape, n, m, n);
	}

	for (int i = n-1; i >=0; i--) {
		std::swap(arr[0], arr[i]);
		heapify(arr, 0, i, window, shape, n, m, i);
	}

	for (int k = 0; k < n; k++) {
		shape[k].setSize(sf::Vector2f(9, arr[k]));
		shape[k].setPosition(sf::Vector2f(10 * k, m + 50 - arr[k]));
		shape[k].setOutlineThickness(0.5f);
		shape[k].setOutlineColor(sf::Color::Black);
		shape[k].setFillColor(sf::Color::Green);
	}

	handleEvent(window, 500, 0);
	drawShapes(window, shape, n);


}



