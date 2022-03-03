//CPE105_B1 - GROUP 6
// GOPOLE, KHYLE MATTHEW P.
// MACHINE PROBLEM - SHORTEST JOB FIRST NON-PREEMPTIVE
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
	int temporary_BT;
	string temporary_N;
	int temporary_CT = 0;

	cout << "SHORTEST JOB FIRST NON-PREEMPTIVE ALGORITHM" << endl;
	cout << "\nEnter the number of processes: ";
	cin >> size;

	//Dynamic Array Declarations
	string* name = new string[size];
	int* burst_time = new int[size];
	int* turnAround_time = new int[size];
	int* waiting_time = new int[size];

	//Inputs using For Loop
	for (int i = 0; i < size; i++)
	{
		cout << "\nEntry Number " << i + 1;
		cout << "\n\nEnter Process Name: ";
		cin >> name[i];
		cout << "\nEnter Burst Time: ";
		cin >> burst_time[i];
		system("cls");
	}

	//Arrange Arrays According to Burst Time in Ascending Order
	for (int j = 0; j < size; j++)
		for (int k = j + 1; k < size; k++)
			if (burst_time[j] > burst_time[k])
			{
				temporary_BT = burst_time[j];
				temporary_N = name[j];
				burst_time[j] = burst_time[k];
				name[j] = name[k];
				burst_time[k] = temporary_BT;
				name[k] = temporary_N;
			}

	//Do Computations for Completion Time OR Turn Around Time
	//Since This is Non-Preemptive which does not consider Arrival time, Turn Around Time is just equal to Completion Time
	// We are assuming that all processes arrived at 0 time unit.
	for (int l = 0; l < size; l++)
	{
			turnAround_time[l] = temporary_CT + burst_time[l];
			temporary_CT = turnAround_time[l];
	}

	
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
	cout << "Process Name\tBurst Time\tTurn Around Time\tWaiting Time" << endl;
	for (int p = 0; p < size; p++)
		cout << name[p] << "\t\t" << burst_time[p] << "\t\t\t" << turnAround_time[p] << "\t\t" << waiting_time[p] << endl;
	cout << "\n\nAverage Turn Around Time: " << fixed << setprecision(2) << averageTurnAround_time << endl;
	cout << "Average Waiting Time: " << fixed << setprecision(2) << averageWaiting_time << endl;

	cout << "\nTHANK YOU FOR USING THE PROGRAM!";

	//Delete the allocated memory for all dynamic arrays
	delete[] name;
	delete[] burst_time;
	delete[] turnAround_time;
	delete[] waiting_time;

	return 0;
}

