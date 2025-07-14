//Code to print multiplication table of 8 using recursion.
#include <stdio.h>
void Ptable(int i)
{
    if (i > 10) {
        return; // Base case: stop when i exceeds 10
    }
    printf("8 x %d = %d\n", i, 8 * i); // Print the multiplication result
    Ptable(i + 1); // Recursive call with incremented value of i
}
int main()
{
    Ptable(1); // Start the recursion with i = 1
    return 0; // Indicate successful completion
}