/* { dg-do compile } */ 
/* { dg-options "-O2 -ftree-loop-distribution -fdump-tree-ldist-all" } */

void foo (int N,
	  int * __restrict__ a,
	  int * __restrict__ b,
	  int * __restrict__ c)
{
  int i;

  for (i=1; i < N; i++)
    {
      a[i] += c[i];
      b[i] = a[i - 1] + 1;
    }

  /* This loop should be distributed, and the result should look like
     this:
     |  for (i=1; i < N; i++)
     |    a[i] += c[i];
     |
     |  for (i=1; i < N; i++)
     |    b[i] = a[i - 1] + 1;
  */
}

/* { dg-final { scan-tree-dump-times "distributed" 1 "ldist" { xfail *-*-* } } } */
/* { dg-final { cleanup-tree-dump "ldist" } } */
