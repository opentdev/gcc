/* PR target/88547 */
/* { dg-do assemble } */
/* { dg-options "-O2 -mavx512bw -mavx512vl -mno-avx512dq -mno-xop -masm=intel" } */
/* { dg-require-effective-target avx512bw } */
/* { dg-require-effective-target avx512vl } */

typedef signed char v32qi __attribute__((vector_size(32)));
typedef unsigned char v32uqi __attribute__((vector_size(32)));
typedef short v16hi __attribute__((vector_size(32)));
typedef unsigned short v16uhi __attribute__((vector_size(32)));
typedef int v8si __attribute__((vector_size(32)));
typedef unsigned v8usi __attribute__((vector_size(32)));
typedef long long v4di __attribute__((vector_size(32)));
typedef unsigned long long v4udi __attribute__((vector_size(32)));

__attribute__((noipa)) v32qi
f1 (v32qi x, v32qi y)
{
  return x >= y;
}

__attribute__((noipa)) v32uqi
f2 (v32uqi x, v32uqi y)
{
  return x >= y;
}

__attribute__((noipa)) v32qi
f3 (v32qi x, v32qi y)
{
  return x <= y;
}

__attribute__((noipa)) v32uqi
f4 (v32uqi x, v32uqi y)
{
  return x <= y;
}

__attribute__((noipa)) v16hi
f5 (v16hi x, v16hi y)
{
  return x >= y;
}

__attribute__((noipa)) v16uhi
f6 (v16uhi x, v16uhi y)
{
  return x >= y;
}

__attribute__((noipa)) v16hi
f7 (v16hi x, v16hi y)
{
  return x <= y;
}

__attribute__((noipa)) v16uhi
f8 (v16uhi x, v16uhi y)
{
  return x <= y;
}

__attribute__((noipa)) v8si
f9 (v8si x, v8si y)
{
  return x >= y;
}

__attribute__((noipa)) v8usi
f10 (v8usi x, v8usi y)
{
  return x >= y;
}

__attribute__((noipa)) v8si
f11 (v8si x, v8si y)
{
  return x <= y;
}

__attribute__((noipa)) v8usi
f12 (v8usi x, v8usi y)
{
  return x <= y;
}

__attribute__((noipa)) v4di
f13 (v4di x, v4di y)
{
  return x >= y;
}

__attribute__((noipa)) v4udi
f14 (v4udi x, v4udi y)
{
  return x >= y;
}

__attribute__((noipa)) v4di
f15 (v4di x, v4di y)
{
  return x <= y;
}

__attribute__((noipa)) v4udi
f16 (v4udi x, v4udi y)
{
  return x <= y;
}
