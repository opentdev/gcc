void abort (void);

void parloop (int N)
{
  int i;
  int x[10000000];

  for (i = 0; i < N; i++)
    x[i] = i + 3;

  for (i = 0; i < N; i++)
    {
      if (x[i] != i + 3)
	abort ();
    }
}

int main(void)
{
  parloop(10000000);

  return 0;
}
/* Check that parallel code generation part make the right answer.  */
/* { dg-final { scan-tree-dump-times "loopfn" 5 "final_cleanup" } } */
/* { dg-final { cleanup-tree-dump "parloops" } } */
/* { dg-final { cleanup-tree-dump "final_cleanup" } } */
