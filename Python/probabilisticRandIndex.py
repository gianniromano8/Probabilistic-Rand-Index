# Copyright 2022 Giovanni Romano and Claudio Carpineto

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.



import math as math

# clustering1 is a vector with the classes of the objects
# clustering2 is a vector with the classes of the objects
# the result is the probabilistic rand index of clustering1 and clustering2
        
def probabilisticRandIndex(clustering1, clustering2):
    # m1 is the number of classes in clustering1
    # m2 is the number of classes in clustering2
    # nij is the number of pairs of objects that satisfy the two properties:
    # n11 same class in clustering1 AND same class in clustering2
    # n10 same class in clustering1 AND different classes in clustering2
    # n01 different classes in clustering1 AND same class in clustering2
    # n00 different classes in clustering1 AND different classes in clustering2
    # w11 is the probabilistic weight of n11
    # w10 is the probabilistic weight of n10
    # w01 is the probabilistic weight of n01
    # w00 is the probabilistic weight of n00  
    n = len(clustering1)
    m1 = 1
    m2 = 1
    n11 = 0
    n10 = 0
    n01 = 0
    n00 = 0
    for object1 in range(0, n - 1):
        objectI_clustering1_class_last = True
        objectI_clustering2_class_last = True
        for object2 in range(object1 + 1, n):
            if (clustering1[object1] == clustering1[object2]):
                objectI_clustering1_class_last = False
                if (clustering2[object1] == clustering2[object2]):
                    objectI_clustering2_class_last =  False
                    n11 += 1
                else: n10 += 1
            else:
                if (clustering2[object1] == clustering2[object2]):
                    objectI_clustering2_class_last = False
                    n01 += 1
                else: n00 += 1
        if objectI_clustering1_class_last: m1 += 1
        if objectI_clustering2_class_last: m2 += 1
        w11 = - math.log2(1.0 / (m1 * m2))
    if (m2 > 1):
        w10 = - math.log2((m2 - 1.0) / (m1 * m2))
    else: w10 = 0
    if (m1 > 1):
        w01 = - math.log2((m1 - 1.0) / (m1 * m2))
    else: w01 = 0
    if ((m2 > 1) and (m1 > 1)):
        w00 = - math.log2(((m1 - 1.0) * (m2 - 1.0)) / (m1 * m2))
    else: w00 = 0 
    return (((w11 * n11) + (w00 * n00)) / ((w11 * n11) + (w10 * n10) + (w01 * n01) + (w00 * n00)))





## example

## create clustering 1
# c1 = [1, 2, 1, 1, 2, 2, 1, 2, 1, 2]

## create clustering 2
# c2 = [3, 1, 1, 1, 1, 2, 3, 1, 2, 1]

## Compute Probabilistic Rand Index (PRI = 0.5212564916017152)
# probabilisticRandIndex(c1, c2)







        
