//CPE105_B1 - GROUP 6
// 
// MACHINE PROBLEM - FIRST IN FIRST OUT (FIFO)
//Headers

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	//Variable Declarations
	int size;
	float averageWaiting_time;
	float sumWaiting_time = 0;
	float averageTurnAround_time;
	float sumTurnAround_time = 0;
	int temporary_AT;
	int temporary_BT;
	string temporary_N;
	int temporary_CT = 0;

	cout << "FIRST IN FIRST OUT ALGORITHM" << endl;
	cout << "\nEnter the number of processes: ";
	cin >> size;

	//Dynamic Array Declarations
	string* name = new string[size];
	int* arrival_time = new int[size];
	int* burst_time = new int[size];
	int* turnAround_time = new int[size];
	int* waiting_time = new int[size];
	int* completion_time = new int[size];

	//Inputs using For Loop
	for (int i = 0; i < size; i++)
	{
		cout << "\nEntry Number " << i+1;
		cout << "\n\nEnter Process Name: ";
		cin >> name[i];
		cout << "\nEnter Arrival Time: ";
		cin >> arrival_time[i];
		cout << "\nEnter Burst Time: ";
		cin >> burst_time[i];
		system("cls");
	}

	//Arrange Arrays According to Arrival Time in Ascending Order
	for (int j = 0; j < size; j++)
		for (int k = j + 1; k < size; k++)
			if (arrival_time[j] > arrival_time[k])
			{
				temporary_AT = arrival_time[j];
				temporary_BT = burst_time[j];
				temporary_N = name[j];
				arrival_time[j] = arrival_time[k];
				burst_time[j] = burst_time[k];
				name[j] = name[k];
				arrival_time[k] = temporary_AT;
				burst_time[k] = temporary_BT;
				name[k] = temporary_N;
			}

	//Do Computations for Completion Time
	for (int l = 0; l < size; l++)
	{
		if (temporary_CT >= arrival_time[l])
			completion_time[l] = temporary_CT + burst_time[l];
		else
			completion_time[l] = arrival_time[l] + burst_time[l];

		temporary_CT = completion_time[l];

	}

	//Do Computations for Turn Around Time
	for (int m = 0; m < size; m++)
		turnAround_time[m] = completion_time[m] - arrival_time[m];

	//Do Computations for Waiting Time
	for (int n = 0; n < size; n++)
		waiting_time[n] = turnAround_time[n] - burst_time[n];

	//Do Computations for Average Turn Around Time and Average Waiting Time
	for (int o = 0; o < size; o++)
	{
		sumTurnAround_time += turnAround_time[o];
		sumWaiting_time += waiting_time[o];
	}
	averageTurnAround_time = sumTurnAround_time / size;
	averageWaiting_time = sumWaiting_time / size;
	

	//Output the Results
	system("cls");
	cout << "\n\nHERE IS THE FINAL RESULT\n\n";
	cout << "Process Name\tArrival Time\tBurst Time\tTurn Around Time\tWaiting Time" << endl;
	for (int p = 0; p < size; p++)
		cout << name[p] << "\t\t" << arrival_time[p] << "\t\t" << burst_time[p] << "\t\t\t" << turnAround_time[p] << "\t\t" << waiting_time[p] << endl;
	cout << "\n\nAverage Turn Around Time: " << fixed << setprecision(2) << averageTurnAround_time << endl;
	cout << "Average Waiting Time: " << fixed << setprecision(2) << averageWaiting_time << endl;

	cout << "\nTHANK YOU FOR USING THE PROGRAM!";

	//Delete the allocated memory for all dynamic arrays
	delete[] name;
	delete[] burst_time;
	delete[] arrival_time;
	delete[] completion_time;
	delete[] turnAround_time;
	delete[] waiting_time;
	return 0;
}

