// { dg-do run { target c++11 } }
// { dg-options "-D__STDCPP_WANT_MATH_SPEC_FUNCS__" }
//
// Copyright (C) 2016-2017 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

//  riemann_zeta

// This can take long on simulators, timing out the test.
// { dg-additional-options "-DMAX_ITERATIONS=5" { target simulator } }

#ifndef MAX_ITERATIONS
#define MAX_ITERATIONS (sizeof(data001) / sizeof(testcase_riemann_zeta<double>))
#endif

//  Compare against values generated by the GNU Scientific Library.
//  The GSL can be found on the web: http://www.gnu.org/software/gsl/
#include <limits>
#include <cmath>
#if defined(__TEST_DEBUG)
#  include <iostream>
#  define VERIFY(A) \
  if (!(A)) \
    { \
      std::cout << "line " << __LINE__ \
	<< "  max_abs_frac = " << max_abs_frac \
	<< std::endl; \
    }
#else
#  include <testsuite_hooks.h>
#endif
#include <specfun_testcase.h>

// Test data.
// max(|f - f_GSL|): 8.8817841970012523e-16
// max(|f - f_GSL| / |f_GSL|): 3.7349082148991403e-15
const testcase_riemann_zeta<double>
data001[55] =
{
  { 0.0000000000000000, -10.000000000000000 },
  { -0.0033669820451019579, -9.8000000000000007 },
  { -0.0058129517767319039, -9.5999999999999996 },
  { -0.0072908732290557004, -9.4000000000000004 },
  { -0.0078420910654484442, -9.1999999999999993 },
  { -0.0075757575757575803, -9.0000000000000000 },
  { -0.0066476555677551898, -8.8000000000000007 },
  { -0.0052400095350859429, -8.5999999999999996 },
  { -0.0035434308017674959, -8.4000000000000004 },
  { -0.0017417330388368585, -8.1999999999999993 },
  { 0.0000000000000000, -8.0000000000000000 },
  { 0.0015440036789213961, -7.7999999999999998 },
  { 0.0027852131086497423, -7.5999999999999996 },
  { 0.0036537321227995880, -7.4000000000000004 },
  { 0.0041147930817053468, -7.2000000000000002 },
  { 0.0041666666666666683, -7.0000000000000000 },
  { 0.0038369975032738366, -6.7999999999999998 },
  { 0.0031780270571782981, -6.5999999999999996 },
  { 0.0022611282027338573, -6.4000000000000004 },
  { 0.0011710237049390511, -6.2000000000000002 },
  { 0.0000000000000000, -6.0000000000000000 },
  { -0.0011576366649881879, -5.7999999999999998 },
  { -0.0022106784318564345, -5.5999999999999996 },
  { -0.0030755853460586891, -5.4000000000000004 },
  { -0.0036804380477934787, -5.2000000000000002 },
  { -0.0039682539682539698, -5.0000000000000000 },
  { -0.0038996891301999797, -4.7999999999999998 },
  { -0.0034551830834302711, -4.5999999999999996 },
  { -0.0026366345018725115, -4.4000000000000004 },
  { -0.0014687209305056974, -4.2000000000000002 },
  { 0.0000000000000000, -4.0000000000000000 },
  { 0.0016960463875825202, -3.7999999999999998 },
  { 0.0035198355903356747, -3.5999999999999996 },
  { 0.0053441503206513421, -3.4000000000000004 },
  { 0.0070119720770910540, -3.2000000000000002 },
  { 0.0083333333333333350, -3.0000000000000000 },
  { 0.0090807294856852811, -2.7999999999999998 },
  { 0.0089824623788396681, -2.5999999999999996 },
  { 0.0077130239874243630, -2.4000000000000004 },
  { 0.0048792123593036068, -2.2000000000000002 },
  { 0.0000000000000000, -2.0000000000000000 },
  { -0.0075229347765968010, -1.8000000000000007 },
  { -0.018448986678963775, -1.5999999999999996 },
  { -0.033764987694047593, -1.4000000000000004 },
  { -0.054788441243880631, -1.1999999999999993 },
  { -0.083333333333333398, -1.0000000000000000 },
  { -0.12198707766977103, -0.80000000000000071 },
  { -0.17459571193801401, -0.59999999999999964 },
  { -0.24716546083171492, -0.40000000000000036 },
  { -0.34966628059831484, -0.19999999999999929 },
  { -0.49999999999999994, 0.0000000000000000 },
  { -0.73392092489633953, 0.19999999999999929 },
  { -1.1347977838669825, 0.40000000000000036 },
  { -1.9526614482239983, 0.59999999999999964 },
  { -4.4375384158955677, 0.80000000000000071 },
};
const double toler001 = 2.5000000000000020e-13;
//  riemann_zeta

#ifndef MAX_ITERATIONS
#define MAX_ITERATIONS (sizeof(data001) / sizeof(testcase_riemann_zeta<double>))
#endif


// Test data.
// max(|f - f_GSL|): 2.6645352591003757e-15
// max(|f - f_GSL| / |f_GSL|): 1.1657079722157521e-15
const testcase_riemann_zeta<double>
data002[145] =
{
  { 5.5915824411777502, 1.2000000000000000 },
  { 3.1055472779775792, 1.3999999999999999 },
  { 2.2857656656801324, 1.6000000000000001 },
  { 1.8822296181028220, 1.8000000000000000 },
  { 1.6449340668482275, 2.0000000000000000 },
  { 1.4905432565068937, 2.2000000000000002 },
  { 1.3833428588407359, 2.3999999999999999 },
  { 1.3054778090727803, 2.6000000000000001 },
  { 1.2470314223172541, 2.7999999999999998 },
  { 1.2020569031595945, 3.0000000000000000 },
  { 1.1667733709844674, 3.2000000000000002 },
  { 1.1386637757280420, 3.3999999999999999 },
  { 1.1159890791233376, 3.6000000000000001 },
  { 1.0975105764590047, 3.7999999999999998 },
  { 1.0823232337111381, 4.0000000000000000 },
  { 1.0697514772338095, 4.2000000000000002 },
  { 1.0592817259798355, 4.4000000000000004 },
  { 1.0505173825665735, 4.5999999999999996 },
  { 1.0431480133351789, 4.7999999999999998 },
  { 1.0369277551433700, 5.0000000000000000 },
  { 1.0316598766779168, 5.2000000000000002 },
  { 1.0271855389203537, 5.4000000000000004 },
  { 1.0233754792270300, 5.5999999999999996 },
  { 1.0201237683883446, 5.7999999999999998 },
  { 1.0173430619844492, 6.0000000000000000 },
  { 1.0149609451852233, 6.2000000000000002 },
  { 1.0129170887121841, 6.4000000000000004 },
  { 1.0111610141542708, 6.5999999999999996 },
  { 1.0096503223447120, 6.7999999999999998 },
  { 1.0083492773819229, 7.0000000000000000 },
  { 1.0072276664807169, 7.2000000000000002 },
  { 1.0062598756930512, 7.4000000000000004 },
  { 1.0054241359879634, 7.5999999999999996 },
  { 1.0047019048164696, 7.7999999999999998 },
  { 1.0040773561979444, 8.0000000000000000 },
  { 1.0035369583062013, 8.1999999999999993 },
  { 1.0030691220374448, 8.4000000000000004 },
  { 1.0026639074861505, 8.5999999999999996 },
  { 1.0023127779098220, 8.8000000000000007 },
  { 1.0020083928260823, 9.0000000000000000 },
  { 1.0017444334995897, 9.1999999999999993 },
  { 1.0015154553480514, 9.4000000000000004 },
  { 1.0013167628052648, 9.5999999999999996 },
  { 1.0011443029840295, 9.8000000000000007 },
  { 1.0009945751278182, 10.000000000000000 },
  { 1.0008645533615086, 10.199999999999999 },
  { 1.0007516206744649, 10.400000000000000 },
  { 1.0006535124140847, 10.600000000000000 },
  { 1.0005682678503411, 10.800000000000001 },
  { 1.0004941886041194, 11.000000000000000 },
  { 1.0004298029239944, 11.199999999999999 },
  { 1.0003738349551168, 11.400000000000000 },
  { 1.0003251782761946, 11.600000000000000 },
  { 1.0002828730909989, 11.800000000000001 },
  { 1.0002460865533080, 12.000000000000000 },
  { 1.0002140957818750, 12.199999999999999 },
  { 1.0001862731874056, 12.400000000000000 },
  { 1.0001620737887460, 12.600000000000000 },
  { 1.0001410242422089, 12.800000000000001 },
  { 1.0001227133475783, 13.000000000000000 },
  { 1.0001067838280169, 13.199999999999999 },
  { 1.0000929252097515, 13.400000000000000 },
  { 1.0000808676518718, 13.600000000000000 },
  { 1.0000703765974504, 13.800000000000001 },
  { 1.0000612481350588, 14.000000000000000 },
  { 1.0000533049750668, 14.199999999999999 },
  { 1.0000463929582293, 14.400000000000000 },
  { 1.0000403780253397, 14.600000000000000 },
  { 1.0000351435864272, 14.800000000000001 },
  { 1.0000305882363070, 15.000000000000000 },
  { 1.0000266237704787, 15.199999999999999 },
  { 1.0000231734615617, 15.400000000000000 },
  { 1.0000201705617975, 15.600000000000000 },
  { 1.0000175570017611, 15.800000000000001 },
  { 1.0000152822594086, 16.000000000000000 },
  { 1.0000133023770337, 16.199999999999999 },
  { 1.0000115791066830, 16.399999999999999 },
  { 1.0000100791671644, 16.600000000000001 },
  { 1.0000087735980010, 16.800000000000001 },
  { 1.0000076371976379, 17.000000000000000 },
  { 1.0000066480348633, 17.199999999999999 },
  { 1.0000057870238734, 17.399999999999999 },
  { 1.0000050375546607, 17.600000000000001 },
  { 1.0000043851715013, 17.800000000000001 },
  { 1.0000038172932648, 18.000000000000000 },
  { 1.0000033229700953, 18.199999999999999 },
  { 1.0000028926717153, 18.399999999999999 },
  { 1.0000025181032419, 18.600000000000001 },
  { 1.0000021920449287, 18.800000000000001 },
  { 1.0000019082127167, 19.000000000000000 },
  { 1.0000016611368951, 19.199999999999999 },
  { 1.0000014460565094, 19.399999999999999 },
  { 1.0000012588274738, 19.600000000000001 },
  { 1.0000010958426055, 19.800000000000001 },
  { 1.0000009539620338, 20.000000000000000 },
  { 1.0000008304526344, 20.199999999999999 },
  { 1.0000007229353187, 20.399999999999999 },
  { 1.0000006293391575, 20.600000000000001 },
  { 1.0000005478614529, 20.800000000000001 },
  { 1.0000004769329869, 21.000000000000000 },
  { 1.0000004151877719, 21.199999999999999 },
  { 1.0000003614367254, 21.399999999999999 },
  { 1.0000003146447527, 21.600000000000001 },
  { 1.0000002739108020, 21.800000000000001 },
  { 1.0000002384505029, 22.000000000000000 },
  { 1.0000002075810521, 22.199999999999999 },
  { 1.0000001807080625, 22.399999999999999 },
  { 1.0000001573141093, 22.600000000000001 },
  { 1.0000001369487659, 22.800000000000001 },
  { 1.0000001192199262, 23.000000000000000 },
  { 1.0000001037862520, 23.199999999999999 },
  { 1.0000000903506006, 23.399999999999999 },
  { 1.0000000786543011, 23.600000000000001 },
  { 1.0000000684721728, 23.800000000000001 },
  { 1.0000000596081891, 24.000000000000000 },
  { 1.0000000518917020, 24.199999999999999 },
  { 1.0000000451741575, 24.399999999999999 },
  { 1.0000000393262332, 24.600000000000001 },
  { 1.0000000342353501, 24.800000000000001 },
  { 1.0000000298035037, 25.000000000000000 },
  { 1.0000000259453767, 25.199999999999999 },
  { 1.0000000225866978, 25.399999999999999 },
  { 1.0000000196628109, 25.600000000000001 },
  { 1.0000000171174297, 25.800000000000001 },
  { 1.0000000149015549, 26.000000000000000 },
  { 1.0000000129725304, 26.199999999999999 },
  { 1.0000000112932221, 26.399999999999999 },
  { 1.0000000098313035, 26.600000000000001 },
  { 1.0000000085586331, 26.800000000000001 },
  { 1.0000000074507118, 27.000000000000000 },
  { 1.0000000064862125, 27.199999999999999 },
  { 1.0000000056465688, 27.399999999999999 },
  { 1.0000000049156179, 27.600000000000001 },
  { 1.0000000042792894, 27.800000000000001 },
  { 1.0000000037253340, 28.000000000000000 },
  { 1.0000000032430887, 28.199999999999999 },
  { 1.0000000028232703, 28.399999999999999 },
  { 1.0000000024577977, 28.600000000000001 },
  { 1.0000000021396356, 28.800000000000001 },
  { 1.0000000018626598, 29.000000000000000 },
  { 1.0000000016215385, 29.199999999999999 },
  { 1.0000000014116306, 29.399999999999999 },
  { 1.0000000012288952, 29.600000000000001 },
  { 1.0000000010698147, 29.800000000000001 },
  { 1.0000000009313275, 30.000000000000000 },
};
const double toler002 = 2.5000000000000020e-13;

template<typename Tp, unsigned int Num>
  void
  test(const testcase_riemann_zeta<Tp> (&data)[Num], Tp toler)
  {
    const Tp eps = std::numeric_limits<Tp>::epsilon();
    Tp max_abs_diff = -Tp(1);
    Tp max_abs_frac = -Tp(1);
    unsigned int num_datum = MAX_ITERATIONS;
    for (unsigned int i = 0; i < num_datum; ++i)
      {
	const Tp f = std::riemann_zeta(data[i].s);
	const Tp f0 = data[i].f0;
	const Tp diff = f - f0;
	if (std::abs(diff) > max_abs_diff)
	  max_abs_diff = std::abs(diff);
	if (std::abs(f0) > Tp(10) * eps
	 && std::abs(f) > Tp(10) * eps)
	  {
	    const Tp frac = diff / f0;
	    if (std::abs(frac) > max_abs_frac)
	      max_abs_frac = std::abs(frac);
	  }
      }
    VERIFY(max_abs_frac < toler);
  }

int
main()
{
  test(data001, toler001);
  test(data002, toler002);
  return 0;
}
