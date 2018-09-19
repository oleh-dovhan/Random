#include <iostream>
#include "RandGenerator.h"
using namespace std;


void print_1_5(BasicRand* num0, int number0)
{
	double a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0, a10 = 0, a11 = 0;
	for (int i = 0; i < number0; i++)
	{
		double x = static_cast <double> (num0->getRandValue()) / num0->getModule();
		if (x >= 0 && x < 0.1) a1 += 1. / number0;
		else if (x >= 0.1 && x < 0.2) a2 += 1. / number0;
		else if (x >= 0.2 && x < 0.3) a3 += 1. / number0;
		else if (x >= 0.3 && x < 0.4) a4 += 1. / number0;
		else if (x >= 0.4 && x < 0.5) a5 += 1. / number0;
		else if (x >= 0.5 && x < 0.6) a6 += 1. / number0;
		else if (x >= 0.6 && x < 0.7) a7 += 1. / number0;
		else if (x >= 0.7 && x < 0.8) a8 += 1. / number0;
		else if (x >= 0.8 && x < 0.9) a9 += 1. / number0;
		else if (x >= 0.9 && x <= 1) a10 += 1. / number0;
		else a11 += 1. / number0;
	}
	cout << "[0, 0.1)     " << 100 * a1 << "%" << endl;
	cout << "[0.1, 0.2)   " << 100 * a2 << "%" << endl;
	cout << "[0.2, 0.3)   " << 100 * a3 << "%" << endl;
	cout << "[0.3, 0.4)   " << 100 * a4 << "%" << endl;
	cout << "[0.4, 0.5)   " << 100 * a5 << "%" << endl;
	cout << "[0.5, 0.6)   " << 100 * a6 << "%" << endl;
	cout << "[0.6, 0.7)   " << 100 * a7 << "%" << endl;
	cout << "[0.7, 0.8)   " << 100 * a8 << "%" << endl;
	cout << "[0.8, 0.9)   " << 100 * a9 << "%" << endl;
	cout << "[0.9, 1]     " << 100 * a10 << "%" << endl;
	cout << "Other        " << 100 * a11 << "%" << endl;
}

void print_6_8(BasicRand* num0, int number0)
{
	double a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0;
	for (int i = 0; i < number0; i++)
	{
		double x = static_cast <double> (num0->getRandValue()) / num0->getModule();
		if (x >= -3 && x < -2) a1 += 1. / number0;
		else if (x >= -2 && x < -1) a2 += 1. / number0;
		else if (x >= -1 && x < 0) a3 += 1. / number0;
		else if (x >= 0 && x < 1) a4 += 1. / number0;
		else if (x >= 1 && x < 2) a5 += 1. / number0;
		else if (x >= 2 && x <= 3) a6 += 1. / number0;
		else a7 += 1. / number0;
	}
	cout << "[-3, -2)  " << 100 * a1 << "%" << endl;
	cout << "[-2, -1)  " << 100 * a2 << "%" << endl;
	cout << "[-1, 0)   " << 100 * a3 << "%" << endl;
	cout << "[0, 1)    " << 100 * a4 << "%" << endl;
	cout << "[1, 2)    " << 100 * a5 << "%" << endl;
	cout << "[2, 3]    " << 100 * a6 << "%" << endl;
	cout << "Other     " << 100 * a7 << "%" << endl;
}

void print_9_10(BasicRand* num0, int number0)
{
	double a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0, a10 = 0, a11 = 0;
	for (int i = 0; i < number0; i++)
	{
		double x = static_cast <double> (num0->getRandValue()) / num0->getModule();
		if (x >= 0 && x < 10) a1 += 1. / number0;
		else if (x >= 10 && x < 20) a2 += 1. / number0;
		else if (x >= 20 && x < 30) a3 += 1. / number0;
		else if (x >= 30 && x < 40) a4 += 1. / number0;
		else if (x >= 40 && x < 50) a5 += 1. / number0;
		else if (x >= 50 && x < 60) a6 += 1. / number0;
		else if (x >= 60 && x < 70) a7 += 1. / number0;
		else if (x >= 70 && x < 80) a8 += 1. / number0;
		else if (x >= 80 && x < 90) a9 += 1. / number0;
		else if (x >= 90 && x <= 100) a10 += 1. / number0;
		else a11 += 1. / number0;
	}
	cout << "[0, 10)    " << 100 * a1 << "%" << endl;
	cout << "[10, 20)   " << 100 * a2 << "%" << endl;
	cout << "[20, 30)   " << 100 * a3 << "%" << endl;
	cout << "[30, 40)   " << 100 * a4 << "%" << endl;
	cout << "[40, 50)   " << 100 * a5 << "%" << endl;
	cout << "[50, 60)   " << 100 * a6 << "%" << endl;
	cout << "[60, 70)   " << 100 * a7 << "%" << endl;
	cout << "[70, 80)   " << 100 * a8 << "%" << endl;
	cout << "[80, 90)   " << 100 * a9 << "%" << endl;
	cout << "[90, 100]  " << 100 * a10 << "%" << endl;
	cout << "Other      " << 100 * a11 << "%" << endl;
}


 
int main()
{
	int bottom;
	BasicRand* randValue;
	do
	{
		cout << "Number: "; cin >> bottom;
	} while (bottom < 1 || bottom > 10);

	switch (bottom)
	{
	case 1: randValue = new LinearCong_1; print_1_5(randValue, 2000); break;
	case 2: randValue = new SquareLinear_2; print_1_5(randValue, 2000); break;
	case 3: randValue = new FibRand_3; print_1_5(randValue, 2000); break;
	case 4: randValue = new InverseCongSequence_4; print_1_5(randValue, 2000); break;
	case 5: randValue = new AssociationSets_5; print_1_5(randValue, 2000); break;
	case 6: randValue = new ThreeSigma_6; print_6_8(randValue, 2000); break;
	case 7: randValue = new Polar_7; print_6_8(randValue, 2000); break;
	case 8: randValue = new Relations_8; print_6_8(randValue, 2000); break;
	case 9: randValue = new MethodLog_9; print_9_10(randValue, 2000); break;
	case 10: randValue = new Arens_10; print_9_10(randValue, 2000); break;
	default: cout << "Error" << endl;
	}
	system("pause");
	return 0;
}
