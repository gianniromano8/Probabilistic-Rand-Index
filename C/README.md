Ansi C version of Probabilistic Rand Index
========================


 ### Usage
**probabilisticRandIndex**(objectN, clustering1, clustering2)



 ### Arguments

* objectN is the number of the objects
* clustering1 is an integer vector with the classes of the objects
* clustering2 is an integer vector with the classes of the objects


### Value
The Probabilistic Rand Index of clustering1 and clustering2


### Usage example
gcc probabilisticRandIndex.c test.c -o priTest

./priTest
    


### License
MIT license

 ### References

Claudio Carpineto, Giovanni Romano. **Consensus Clustering Based on a New Probabilistic Rand Index with Application to Subtopic Retrieval**. *IEEE Transactions on Pattern Analysis and Machine Intelligence*, Volume 34, Issue 12, pp. 2315-2326, December 2012.

http://search.fub.it/claudio/pdf/TPAMI2012.pdf