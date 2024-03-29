/* PR target/92686 */
/* { dg-do assemble } */
/* { dg-options "-O2 -mavx512bw -mno-avx512dq -mno-avx512vl -mno-xop -masm=intel" } */
/* { dg-require-effective-target avx512bw } */


typedef char v64qi __attribute__((vector_size(64)));
typedef unsigned char v64uqi __attribute__((vector_size(64)));
typedef short v32hi __attribute__((vector_size(64)));
typedef unsigned short v32uhi __attribute__((vector_size(64)));
typedef int v16si __attribute__((vector_size(64)));
typedef unsigned v16usi __attribute__((vector_size(64)));
typedef long long v8di __attribute__((vector_size(64)));
typedef unsigned long long v8udi __attribute__((vector_size(64)));

__attribute__((noipa)) v64qi
f1 (v64qi x, v64qi y)
{
  return x >= y;
}

__attribute__((noipa)) v64uqi
f2 (v64uqi x, v64uqi y)
{
  return x >= y;
}

__attribute__((noipa)) v64qi
f3 (v64qi x, v64qi y)
{
  return x <= y;
}

__attribute__((noipa)) v64uqi
f4 (v64uqi x, v64uqi y)
{
  return x <= y;
}

__attribute__((noipa)) v32hi
f5 (v32hi x, v32hi y)
{
  return x >= y;
}

__attribute__((noipa)) v32uhi
f6 (v32uhi x, v32uhi y)
{
  return x >= y;
}

__attribute__((noipa)) v32hi
f7 (v32hi x, v32hi y)
{
  return x <= y;
}

__attribute__((noipa)) v32uhi
f8 (v32uhi x, v32uhi y)
{
  return x <= y;
}

__attribute__((noipa)) v16si
f9 (v16si x, v16si y)
{
  return x >= y;
}

__attribute__((noipa)) v16usi
f10 (v16usi x, v16usi y)
{
  return x >= y;
}

__attribute__((noipa)) v16si
f11 (v16si x, v16si y)
{
  return x <= y;
}

__attribute__((noipa)) v16usi
f12 (v16usi x, v16usi y)
{
  return x <= y;
}

__attribute__((noipa)) v8di
f13 (v8di x, v8di y)
{
  return x >= y;
}

__attribute__((noipa)) v8udi
f14 (v8udi x, v8udi y)
{
  return x >= y;
}

__attribute__((noipa)) v8di
f15 (v8di x, v8di y)
{
  return x <= y;
}

__attribute__((noipa)) v8udi
f16 (v8udi x, v8udi y)
{
  return x <= y;
}
