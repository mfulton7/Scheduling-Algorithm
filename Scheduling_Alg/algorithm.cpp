#include "algorithm.hpp"



void alg::totalWait(int size) {
	//code to print the time to completion of all cpu processes
	std::cout << "Total times to complete processes..." << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << wait[i] << std::endl;
	}
}

void alg::avgWait(int size) {
	//code to calculate and print the average wait time for processes to execute
	std::cout << "Average wait time for processes..." << std::endl;
	int j = 0;
	for (int i = 0; i < size; ++i) {
		j += wait[i];
	}
	j = j / size;

	std::cout << j << std::endl;
}

void alg::minWait(int size) {
	//code to calc and print the minimum wait time
	std::cout << "Minimum wait time of processes..." << std::endl;
	int min = wait[0];
	for (int i = 0; i < wait.size(); ++i)
	{
		if (wait[i] < min)
		{
			min = wait[i];
		}
	}
}

void alg::maxWait(int size) {
	//code to calc and print the max wait time
	std::cout << "Maximum wait time of processes..." << std::endl;
	int max = wait[0];
	for (int i = 0; i < wait.size(); ++i) {
		if (wait[i] > max) {
			max = wait[i];
		}
	}
}


// code for algorithms, how they behave and how they interact with queues
void alg::FCFS(int size)
{
	int tmp;
	//code to open the desired text file to open, read, populate queues
	std::ifstream data("data.txt");
	if (data.is_open()) {
		for (int i = 0; i < size; ++i) {			
			data >> tmp;
			//std::cerr << ready.size();
			ready.push_back(tmp);
		}
	}
	//code to keep track of wait times

	//initializes time waiting list
	for (int i = 0; i < size; ++i) {
		wait.push_back(0);
	}

	//code to move through ready queue
	int spot = 0;
	while (spot < size) {
		//decrements value of number @ current spot in array
		ready[spot] -= 10;
		
		//keeps track time waiting for all nonfinished cpu processes
		int difference = 0;
		if (ready[spot] < 0) {
		//	wait[spot] += (10 + ready[spot]);
			difference = (10 + ready[spot]);
			for (int i = spot+1; i < size; ++i) {
				wait[i] += difference;
			}
		}
		else {


		 		for (int i = spot+1; i < size; ++i) {
					wait[i] += 10;
				}
		}
		if (ready[spot] <= 0) {
			++spot;
		}
	}

	

	


}

void alg::SJF(int size)
{
	int tmp;
	//code to open the desired text file to open, read, populate queues
	std::ifstream data("data.txt");
	if (data.is_open()) {
		for (int i = 0; i < size; ++i)  {
			data >> tmp;
			//std::cerr << ready.size();
			ready.push_back(tmp);
		}
	}

	//code to check which function is shortest
	std::sort(ready.begin(), ready.end());

	//initializes time waiting list
	for (int i = 0; i < size; ++i) {
		wait.push_back(0);
	}

	//code to move through ready queue
	int spot = 0;
	while (spot < size) {
		//decrements value of number @ current spot in array
		ready[spot] -= 10;

		//keeps track time waiting for all nonfinished cpu processes
		int difference = 0;
		if (ready[spot] < 0) {
			//	wait[spot] += (10 + ready[spot]);
			difference = (10 + ready[spot]);
			for (int i = spot + 1; i < size; ++i) {
				wait[i] += difference;
			}
		}
		else {


			for (int i = spot + 1; i < size; ++i) {
				wait[i] += 10;
			}
		}
		if (ready[spot] <= 0) {
			++spot;
		}
	}

	//code to print the time to completion of all cpu processes
	std::cout << "Total times to complete processes..." << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << wait[i] << std::endl;
	}

	//code to calculate and print the average wait time for processes to execute
	std::cout << "Average wait time for processes..." << std::endl;
	int j = 0;
	for (int i = 0; i < size; ++i) {
		j += wait[i];
	}
	j = j / size;

	std::cout << j << std::endl;


}

void alg::STR(int size)
{
	int tmp;
	//code to open the desired text file to open, read, populate queues
	std::ifstream data("data.txt");
	if (data.is_open()) {
		for (int i = 0; i < size; ++i) {
			data >> tmp;
			//std::cerr << ready.size();
			ready.push_back(tmp);
		}
	}

	//code to keep track of wait times

	//initializes time waiting list
	for (int i = 0; i < size; ++i) {
		wait.push_back(0);
	}

	//code to check which function is shortest
	std::sort(ready.begin(), ready.end());

	//code to move through ready queue
	int spot = 0;
	while (spot < size) {
		//decrements value of number @ current spot in array
		ready[spot] -= 10;

		//keeps track time waiting for all nonfinished cpu processes
		int difference = 0;
		if (ready[spot] < 0) {
			//	wait[spot] += (10 + ready[spot]);
			difference = (10 + ready[spot]);
			for (int i = 0; i < size; ++i) {
				if (i != spot && ready[i] > 0) {
					wait[i] += difference;
				}
			}
		}
		else {


			for (int i = 0; i < size; ++i) {
				if (i != spot && ready[i] > 0) {
					wait[i] += 10;
				}
			}
		}

		//reads new input from file then reorders the list 
		if (!data.eof()) {
			data >> tmp;
			ready.push_back(tmp);
			std::sort(ready.begin(), ready.end());
		}
		//problem this allows for str but messes up results, since the ready queue is moved around it won't match the wait queue

		//this code only increments the spot if the process is finished not good for rr
		/*
		if (ready[spot] <= 0) {
		++spot;
		}
		*/
		//code to check if current process is still the shortest
		// this won't work code is bugged and the wait list must be reupdated
		/*
		if (ready[spot] > ready[spot + 1] && ready[spot +1] > 0) {
			//code to switch the shortest func to top of ready queue
			tmp = ready[spot];
			ready[spot] = ready[spot + 1];
			ready[spot + 1] = tmp;
			//code to update wait queue to accurately reflect changes
			tmp = wait[spot];
			wait[spot] = wait[spot + 1];
			wait[spot + 1] = tmp;
		}
		*/
		++spot;
	}

	//code to print the time to completion of all cpu processes
	std::cout << "Total times to complete processes..." << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << wait[i] << std::endl;
	}

	//code to calculate and print the average wait time for processes to execute
	std::cout << "Average wait time for processes..." << std::endl;
	int j = 0;
	for (int i = 0; i < size; ++i) {
		j += wait[i];
	}
	j = j / size;

	std::cout << j << std::endl;

}

void alg::RR(int size){
	int tmp;
	//code to open the desired text file to open, read, populate queues
	std::ifstream data("data.txt");
	if (data.is_open()) {
		for (int i = 0; i < size; ++i) {
			data >> tmp;
			//std::cerr << ready.size();
			ready.push_back(tmp);
		}
	}

	//code to keep track of wait times

	//initializes time waiting list
	for (int i = 0; i < size; ++i) {
		wait[i] = 0;
	}

	//code to move through ready queue
	int spot = 0;
	while (spot < size) {
		//decrements value of number @ current spot in array
		ready[spot] -= 10;

		//keeps track time waiting for all nonfinished cpu processes
		int difference = 0;
		if (ready[spot] < 0) {
			//	wait[spot] += (10 + ready[spot]);
			difference = (10 + ready[spot]);
			for (int i = 0; i < size; ++i) {
				if (i != spot && ready[i] > 0) {
					wait[i] += difference;
				}
			}
		}
		else {


			for (int i = 0; i < size; ++i) {
				if (i != spot && ready[i] > 0) {
					wait[i] += 10;
				}
			}
		}
		//this code only increments the spot if the process is finished not good for rr
		/*
		if (ready[spot] <= 0) {
			++spot;
		}
		*/
		++spot;
	}

	//code to print the time to completion of all cpu processes
	std::cout << "Total times to complete processes..." << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << wait[i] << std::endl;
	}

	//code to calculate and print the average wait time for processes to execute
	std::cout << "Average wait time for processes..." << std::endl;
	int j = 0;
	for (int i = 0; i < size; ++i) {
		j += wait[i];
	}
	j = j / size;

	std::cout << j << std::endl;

}
//starts random number seed
void num_gen::initialize()
{
	srand(time(NULL));
}

//generates and returns a random number on a range based upon arguement
int num_gen::generate(int y)
{
	int x;
	x = rand() % y + 1;
	return x;
}
