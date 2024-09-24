#include "lab_1/lab_1.cpp"
#include "lab_2/lab_2.cpp"
#include "lab_2/lab_2_2.cpp"
#include <iostream>

using namespace std;

int main(void) 
{
	int lab_num;
anchor:
	cout << "Give me number of the lab you want to run" << endl;
	cin >> lab_num;

	switch (lab_num) {
	
	case 1:
		lab1();
		break;
	
	case 2:
		int lab_2_v;
	    cout << "Give me number of the lab you want to run" << endl;
	    cin >> lab_num;
		switch (lab_2_v) {
	       
		   case 1:
		      lab_2();
		      break;
		   
		   case 2:
		      lab_2_2();
	          break;
		}
	
	default:
		cout << "Lab work does not exist";
		break;
	}
	goto anchor;
}