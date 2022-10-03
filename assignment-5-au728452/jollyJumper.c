#include "jollyjumper.h"
#include <stdbool.h>
#include <malloc.h>



int isJollyJumber(const int seq[], int size) {
/*post: answer to exercise 7.a*/

int diff; // The difference of two consecutive numbers
bool diffs_found[size-1]; // An array that stores the numbers checked, so that if the difference 2 has been found, the value for diff - 1 as index, will be set to be true

for (int i = 0; i < size; i++) // Initialize boolean array
{
    diffs_found[i] = false;
}


for (int i = 0; i<size-1; i++){
    diff = seq[i] - seq[i+1]; // Calculates the difference of the first and next number in the sequence
    if (diff < 0) // Checks if difference is negative, if so it changes to positive number
    {
        diff = -diff;
    }

    if (diff == 0 || diff >= size || diffs_found[diff-1] == true){ // Checks to see if number should be in array
        break;
    }
    else{
        diffs_found[diff-1] = true; // Sets value checked to be true if preconitions are fulfilled
    }
}

for (int i = 0; i < size-1; i++) // Loop to check if all values of the jolly jumper sequence has been found, if the whole boolean array is true, then the sequence is a jolly jumper
{
    if (diffs_found[i] == false)
    {
        return 0;
    }
}

return 1;
}








    


