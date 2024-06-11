// space complexity measures how the memory or space required by an algorithm grows as the size of the input increases.



// observation from time analysis is that sometimes only one operation is required to push_back and add but sometimes you have to do 3*n steps(constant dosent matter)

// O(1)         O(N)

// if you do n(where n is the large number) push back or add operations:
// capactity will be power of twp
// whereever the size/n is a power of 2 then it takes 3*n steps for the next push back or add operation otherwise one step only

//log base 2 n ceil value should be the highest power of 2 for capacity