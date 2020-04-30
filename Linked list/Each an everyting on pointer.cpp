#include<bits/stdc++.h>
using namespace std;

/*
A pointer is a variable that contains an address.IN your PC every variable is sorted is certain place in its memory.
The exact place where a variable is placed is called variable's address.

With a pointer you able are to know the exact address of another variable.

int c = 5;
int *p = &c; pointer p now contains the address where 5.

keep mind *p is a variable to
int **P = &p a double pointer that contains the address of the pointer p.
  */

int main()
{
    int v;
    cin >> v;
    int *p,**P,***pp;
    p=&v;
    P=&p;
    pp=&P;
    cout<<v<<" "<<*p<<" "<<**P<<" "<<***pp<<endl;

}
