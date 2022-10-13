#include "SimpleUnitTest.h"
#include "Ex1.h"
#include "Ex2.h"
#include <iostream>

void testExercises();

int main()
{
	/* -- Auto evaluation -- */
	testExercises();

	system("pause");
	return 0;
}


/* ----------------------------------------------------------------------- */
/*                     DO NOT TOUCH THE CODE BELOW                         */
/* ----------------------------------------------------------------------- */

void testExercises()
{
	// Ex1
#ifdef TEST_EX1
	{
		Soldier* a1 = new Archer(1);
		Soldier* a2 = new Archer(2);
		Soldier* a3 = new Archer(3);

		Soldier* s1 = new Tank(4);
		Soldier* s2 = new Tank(5);
		Soldier* s3 = new Tank(2);

		a1->attack(s1);
		bool res1 = s1->getHealthPoints() == 15;
		a1->attack(s2);
		bool res2 = s2->getHealthPoints() == 15;
		a1->upgrade();
		a1->attack(s2);
		bool res3 = s2->getHealthPoints() == 14;
		s3->attack(a1);
		s3->attack(a1);
		bool res4 = a1->getHealthPoints() == 0;

		s2->move(-3);
		s2->attack(a2);
		bool res5 = a2->getHealthPoints() == 4;

		s2->attack(s3);
		bool res6 = s3->getHealthPoints() == 15;

		delete a1;
		delete a2;
		delete a3;

		delete s1;
		delete s2;
		delete s3;
		TEST(": Exercise 1: Units ", res1 && res2 && res3 && res4 && res5 && res6);
	}
#endif

#ifdef TEST_EX2
	// Ex2
	{
		int auxArray[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		bool res1 = partialSum(auxArray, 10, 0, 9) == 45;
		bool res2 = partialSum(auxArray, 10, 5, 9) == 35;
		bool res3 = partialSum(auxArray, 10, 1, 2) == 3;
		bool res4 = partialSum(auxArray, 10, 1, 1) == 1;
		bool res5 = partialSum(auxArray, 10, -1, 1) == 0;
		bool res6 = partialSum(auxArray, 10, 1, 0) == 0;
		bool res7 = partialSum(auxArray, 10, 1, 10) == 0;
		int auxArray2[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		bool res8 = partialSum(auxArray2, 15, 0, 14) == 15;
		bool res9 = partialSum(auxArray, 10, 12, 15) == 0;
		TEST(": Exercise 2: Partial sum(...)", res1 && res2 && res3 && res4 && res5 && res6 && res7 && res8 && res9);
	}
#endif

	PRINT_TEST_REPORT();
}
