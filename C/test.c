// Copyright 2022 Giovanni Romano and Claudio Carpineto

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.




#include <stdio.h>
#include "probabilisticRandIndex.h"


void printPri(char* name, int size, int vect1[], int vect2[]);
void printIntVect(int size, int vect[]);


int c1[] = {1, 2, 1, 1, 2, 2, 1, 2, 1, 2};
int c2[] = {1, 2, 1, 1, 2, 2, 1, 2, 1, 2};

int c3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int c4[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int c5[] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
int c6[] = {1, 1, 1, 1, 3, 2, 2, 2, 2, 3};

int c7[] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
int c8[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};




int main() {
  int objectN = 10;
  printPri("Equal partitions (PRI = 1)", objectN, c1, c2);
  printPri("Totally different partitions (PRI = 0)", objectN, c3, c4);
  printPri("Similar partitions (PRI = 818975)", objectN, c5, c6);
  printPri("Dissimilar partitions (PRI = 380483)", objectN, c7, c8);
  printf("\n");
}


void printPri(char* caseName, int objectN, int vect1[], int vect2[]) {
  printf("\n\n%s", caseName);
  printIntVect(objectN, vect1);
  printIntVect(objectN, vect2);
  printf("\npri = %G\n", probabilisticRandIndex(objectN, vect1, vect2));
}
 
void printIntVect(int size, int vect[]) {
  printf("\n[%i", vect[0]);
  for (int i=1; i < size; i++) {
    printf(", %i", vect[i]);  
  }
  printf("]");
}

