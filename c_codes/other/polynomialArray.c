#include <stdio.h>
#include <math.h>

#define MAXDEGREE 101

void addPolyArray(int poly_a[], int poly_b[]) {
    
    size_t i = 0;
    int poly_c[MAXDEGREE];
    
    for (i = 0; i < MAXDEGREE; i++) {
        poly_c[i] = poly_a[i] + poly_b[i];
    }   // End for loop
    
    printf("The sum of the polynomial integers is: ");
    
    for (i = 0; i < MAXDEGREE; i++) {    
        if (i < MAXDEGREE-1 ) {
            printf("%d, ", poly_c[i]);
        }

    }   // End for loop.
    
    printf("\n");
}

int main() {
    
    int pA[] = {12, 4, 3, 8, 0};  // Declare polynmial 1
    int pB[] = {-5, 8, 2, 0, 9};    // Declare polynomial 2
    
    addPolyArray(pA, pB);
    
    return 0;
}