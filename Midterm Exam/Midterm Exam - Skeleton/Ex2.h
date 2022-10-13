/* ----------------------------------------------------------------------- */
/*                         INSERT YOUR NAME HERE                           */
/* ----------------------------------------------------------------------- */

#ifndef EX2_H
#define EX2_H

// Uncomment to test the exercise
#define TEST_EX2

int partialSum(int* pIntArray, int pArraySize, int pInitPos, int pEndPos)
{
	
	if ((pInitPos < pEndPos) && (pInitPos >= 0) && (pEndPos <= pArraySize)) {
		int hold = 0;
		for(int i = pInitPos; i < pEndPos; i++){
			hold += *(pIntArray + pInitPos);
		}
		return hold;
	}
	else if(pInitPos = pEndPos){
		return 1;
	}
	else {
		return 0;
	}
}


#endif