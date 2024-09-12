#include <stdlib.h>
#include "array_utils.h"

void generate_array(int size) {
    for (int i =0; i<size;i++) {
        A[i] = rand() % 100;
    }
}