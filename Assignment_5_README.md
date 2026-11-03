In this lab I tested 5 methods for calculating sum. 
I used the codes from github and tested them with different array sizes 
from 2^10 to 2^27.

Normal double sum was not very accurate for bigger arrays because it loses 
small numbers. Kahan and Knuth use corrections to fix this problem. 
Long double has better precision and pairwise adds numbers in smaller groups.

For 2^27 normal sum had error -0.01333 while Kahan, Knuth and pairwise 
had 0 error. Long double had very small error. 
Normal sum was faster than most other methods.

I learned that the order of adding numbers matters. 
In parallel programming different processes can add numbers in different 
order so the final result can be different. 
Using these methods can help reduce errors.