# sorts
This is just a collection of various sorts with performance data related to them.
The comparison was done on an intel xeon x5670 with clang and mingw-w64(gcc) compilers both with -O2 performance option.

I spent some time playing with various sorts the last few days in part showing others how they work and making changes to them and looking at the differences on compiler explorer. The control flow diagram can offer a lot of insight into why performance is what it is.

The compiler in some cases can make a fairly significant difference in the performance. If you look at buoyancy(insertion sort) vs heap sort notice clang out performs mingw-w64 (gcc). 
Using clang to compile buoyancy out performs heap sort up to a million integers to sort . 
Using GCC to compile heap sort out performs buoyancy at a million integers to sort.

I made several modifications to heap sort I included a few of them below. There are some that aren't included below such as replacing the ternary with just math. 
t = p%2?p/2:p/2-1; 
t=(p%2)(p/2)+((p%2)^1)(p/2+1); 
while you can reduce the number of computations by removing p%2 and p/2 outside of the formula you will never get back the performance of the ternary operator. Sure you eliminate the branches created by the ternary but you end up having to calculate that each loop which works out a lot more than just calculating p%2 each time and what it requires is a lot less work.

You can also see the difference in heap sort 3 vs 4. While on clang placing t = p%2?p/2:p/2-1; into a definition made little difference on gcc systems it made a significant difference.

Getting rid of branches or nested loops doesn't mean you will always get performance gains from it. You can loose performance. A lot can depend on the compiler.

With sort algorithms the biggest increase in efficiency comes from reducing the number of times you need to touch data for comparisons or moves.
