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


#include <math.h>


// objectN is the number of the objects
// clustering1 is an integer vector of length objectN with the classes of the objects
// clustering2 is an integer vector of length objectN with the classes of the objects
// the result is the probabilistic rand index of clustering1 and clustering2


double probabilisticRandIndex(int objectN, int clustering1[], int clustering2[]) {
   // m1 is the number of classes in clustering1
   // m2 is the number of classes in clustering2
   // nij is the number of pairs of objects that satisfy the two properties:
   // n11 same class in clustering1 AND same class in clustering2
   // n10 same class in clustering1 AND different classes in clustering2
   // n01 different classes in clustering1 AND same class in clustering2
   // n00 different classes in clustering1 AND different classes in clustering2
   // w11 is the probabilistic weight of n11
   // w10 is the probabilistic weight of n10
   // w01 is the probabilistic weight of n01
   // w00 is the probabilistic weight of n00  
   int m1 = 1; 
   int m2 = 1;  
   int n11 = 0;
   int n10 = 0; 
   int n01 = 0; 
   int n00 = 0;
   double w11;
   double w10 = 0;
   double w01 = 0;
   double w00 = 0;
   int objectI_clustering1_class_last;
   int objectI_clustering2_class_last;
   for (int objectI = 0; objectI < (objectN - 1); objectI++) {
     objectI_clustering1_class_last = 1;
     objectI_clustering2_class_last = 1;
     for (int objectJ = (objectI + 1); objectJ < objectN; objectJ++) {
       if (clustering1[objectI] == clustering1[objectJ]) {
	 objectI_clustering1_class_last = 0;
	 if (clustering2[objectI] == clustering2[objectJ]) {
	   objectI_clustering2_class_last = 0;
	   n11++;
	 }
	 else n10++;
       }
       else if (clustering2[objectI] == clustering2[objectJ]) {
	 objectI_clustering2_class_last = 0;
	 n01++;
       }
       else n00++;
     }
     if (objectI_clustering1_class_last == 1) m1++;
     if (objectI_clustering2_class_last == 1) m2++;
   }
   w11 = - log2(1.0 / (m1 * m2));
   if (m2 > 1) 
     w10 = - log2((m2 - 1.0) / (m1 * m2));
   if (m1 > 1) 
     w01 = - log2((m1 - 1.0) / (m1 * m2));
   if ((m2 > 1) && (m1 > 1))
     w00 = - log2(((m1 - 1.0) * (m2 - 1.0)) / (m1 * m2));
   return (((w11 * n11) + (w00 * n00)) / ((w11 * n11) + (w10 * n10) + (w01 * n01) + (w00 * n00)));
    }

