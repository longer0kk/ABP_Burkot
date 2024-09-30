#include <iostream>
#include "lab_1/lab_1.cpp"
#include "lab_2/lab_2.cpp"
#include "lab_2/lab_2_2.cpp"
#include "lab_3/lab_3.cpp"

using namespace std;

int main(void) 
{
	int lab_num;
	int lab_2_v;
	cout << "Give me number of the lab you want to run: " << endl;
	cin >> lab_num;

	switch (lab_num) {
	
	case 1:
		lab1();
		break;
	
	case 2:
	    cout << "Which one? " << endl;
	    cin >> lab_2_v;
		switch (lab_2_v) {
	       
		   case 1:
		      lab_2();
		      break;
		   
		   case 2:
		      lab_2_2();
	          break;
		}
	break;

	case 3:
		lab_3();
		break;

	
	default:
		cout << "Lab work does not exist." << endl;
	}
	return 0;
}