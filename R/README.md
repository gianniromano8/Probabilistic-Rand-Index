R version of Probabilistic Rand Index
========================




 ### Usage
**probabilisticRandIndex**(clustering1, clustering2)


 ### Arguments
* clustering1 is a vector with the classes of the objects
* clustering2 is a vector with the classes of the objects

### Value
The Probabilistic Rand Index of clustering1 and clustering2





 ### Examples

   ##### # create clustering 1
c1 <- c(1, 2, 1, 1, 2, 2, 1, 2, 1, 2)

   ##### # create clustering 2
c2 <- c(3, 1, 1, 1, 1, 2, 3, 1, 2, 1)

##### # Compute Probabilistic Rand Index (pri = 0.5212565)
probabilisticRandIndex(c1, c2)  
 			   
    
Other examples are in the file test.R.

### License
MIT license

 ### References

Claudio Carpineto, Giovanni Romano. **Consensus Clustering Based on a New Probabilistic Rand Index with Application to Subtopic Retrieval**. *IEEE Transactions on Pattern Analysis and Machine Intelligence*, Volume 34, Issue 12, pp. 2315-2326, December 2012.

http://search.fub.it/claudio/pdf/TPAMI2012.pdf