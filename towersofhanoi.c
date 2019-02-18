#include <stdio.h>

/*
A very elegant solution from the use of recursion.Assume that the number of disks is n. To get the largest disk to the
bottom of tower B, we ,move the remaining n-1 disks to lower C and then move the largest to tower B. now we are left
with the task of moving the disks from C to B. to do this, we have towersA and b are available. the fact that tower B
has a disk on it can be ignored as the disk is larger than the disks being moved from tower C and so any disk can be
placed on top of it . this algorithm is invoked by function towers(n,A,B,c).
the solution for an n-disk problem is formulated in terms of solution to (n-1)-disk problems.
*/
void towers(int, char, char, char);// a globally declared function for towers of hanoi

int main()
{
    int num;

    printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The moves in the Tower of Hanoi are :\n");
    towers(num, 'A', 'C', 'B');//a recursive call to the towers of hanoi
    return 0;
}
void towers(int num, char a, char b, char temp)
{
    if (num == 1)           // base case for towers of hanoi
    {
        printf("\n Move disk 1 from tower %c to tower %c", a, b);
        return;
    }
    // solution to(n-1)-disk is solution to n-disk,

    towers(num - 1, a, temp, b); //move top disk from tower A to temp and next top disk to tower B

    printf("\n Move disk %d from tower %c to tower %c", num, a, b);

    towers(num - 1, temp, b, a);//move top disk from tower temp to tower B and next top disk to tower A
}
