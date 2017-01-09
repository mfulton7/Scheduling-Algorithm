#include <iostream>
#include "algorithm.hpp"

//main program for scheduling asks user for input then executes function calls for appropriate algorithms, and returns an analysis on the results (time, average response, metrics, etc.)

int main() {

	int response = 0;
	int programCount;
	std::cout << "Hello, and welcome to my CPU scheduling simulator." << std::endl;
	std::cout << "Please select how many programs you would like to load upon startup." << std::endl;
	std::cin >> programCount;
	std::cout << "Please select the type of scheduling algorithm you would like to test..." << std::endl;
	std::cout << "1 for FCFS" << std::endl;
	std::cout << "2 for SJF" << std::endl;
	std::cout << "3 for STR" << std::endl;
	std::cout << "4 for RR" << std::endl;
	std::cout << "5 to quit" << std::endl;

	while (response != 5) {
		std::cin >> response;

		alg cpu;

		switch (response) {
		case 1:
			// code to execute fcfs scheduling
			cpu.FCFS(programCount);
			break;
		case 2:
			// code to execute sjf
			cpu.SJF(programCount);
			break;
		case 3:
			// code to execute str
			cpu.STR(programCount);
			break;
		case 4:
			//code to execute rr
			cpu.RR(programCount);
			break;
		}
	}

	

}