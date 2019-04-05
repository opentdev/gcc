/* { dg-do compile } */
/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sve_acle.h"

/*
** div_u32_m_tied1:
**	udiv	z0\.s, p0/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (div_u32_m_tied1, svuint32_t,
		z0 = svdiv_u32_m (p0, z0, z1),
		z0 = svdiv_m (p0, z0, z1))

/* Bad RA choice: no preferred output sequence.  */
TEST_UNIFORM_Z (div_u32_m_tied2, svuint32_t,
		z1 = svdiv_u32_m (p0, z0, z1),
		z1 = svdiv_m (p0, z0, z1))

/*
** div_u32_m_untied:
**	movprfx	z0, z1
**	udiv	z0\.s, p0/m, z0\.s, z2\.s
**	ret
*/
TEST_UNIFORM_Z (div_u32_m_untied, svuint32_t,
		z0 = svdiv_u32_m (p0, z1, z2),
		z0 = svdiv_m (p0, z1, z2))

/*
** div_w0_u32_m_tied1:
**	mov	(z[0-9]+\.s), w0
**	udiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_w0_u32_m_tied1, svuint32_t, uint32_t,
		 z0 = svdiv_n_u32_m (p0, z0, x0),
		 z0 = svdiv_m (p0, z0, x0))

/*
** div_w0_u32_m_untied:
**	mov	(z[0-9]+\.s), w0
**	movprfx	z0, z1
**	udiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_w0_u32_m_untied, svuint32_t, uint32_t,
		 z0 = svdiv_n_u32_m (p0, z1, x0),
		 z0 = svdiv_m (p0, z1, x0))

/*
** div_s0_u32_m_tied1:
**	mov	(z[0-9]+\.s), s0
**	udiv	z1\.s, p0/m, z1\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_s0_u32_m_tied1, svuint32_t, uint32_t,
		 z1 = svdiv_n_u32_m (p0, z1, d0),
		 z1 = svdiv_m (p0, z1, d0))

/*
** div_s0_u32_m_untied:
**	mov	(z[0-9]+\.s), s0
**	movprfx	z1, z2
**	udiv	z1\.s, p0/m, z1\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_s0_u32_m_untied, svuint32_t, uint32_t,
		 z1 = svdiv_n_u32_m (p0, z2, d0),
		 z1 = svdiv_m (p0, z2, d0))

/*
** div_2_u32_m_tied1:
**	mov	(z[0-9]+\.s), #2
**	udiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_Z (div_2_u32_m_tied1, svuint32_t,
		z0 = svdiv_n_u32_m (p0, z0, 2),
		z0 = svdiv_m (p0, z0, 2))

/*
** div_2_u32_m_untied:
**	mov	(z[0-9]+\.s), #2
**	movprfx	z0, z1
**	udiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_Z (div_2_u32_m_untied, svuint32_t,
		z0 = svdiv_n_u32_m (p0, z1, 2),
		z0 = svdiv_m (p0, z1, 2))

/*
** div_u32_z_tied1:
**	movprfx	z0\.s, p0/z, z0\.s
**	udiv	z0\.s, p0/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (div_u32_z_tied1, svuint32_t,
		z0 = svdiv_u32_z (p0, z0, z1),
		z0 = svdiv_z (p0, z0, z1))

/*
** div_u32_z_tied2:
**	movprfx	z1\.s, p0/z, z1\.s
**	udivr	z1\.s, p0/m, z1\.s, z0\.s
**	ret
*/
TEST_UNIFORM_Z (div_u32_z_tied2, svuint32_t,
		z1 = svdiv_u32_z (p0, z0, z1),
		z1 = svdiv_z (p0, z0, z1))

/*
** div_u32_z_untied:
**	movprfx	z0\.s, p0/z, z1\.s
**	udiv	z0\.s, p0/m, z0\.s, z2\.s
**	ret
*/
TEST_UNIFORM_Z (div_u32_z_untied, svuint32_t,
		z0 = svdiv_u32_z (p0, z1, z2),
		z0 = svdiv_z (p0, z1, z2))

/*
** div_w0_u32_z_tied1:
**	mov	(z[0-9]+\.s), w0
**	movprfx	z0\.s, p0/z, z0\.s
**	udiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_w0_u32_z_tied1, svuint32_t, uint32_t,
		 z0 = svdiv_n_u32_z (p0, z0, x0),
		 z0 = svdiv_z (p0, z0, x0))

/*
** div_w0_u32_z_untied: { xfail *-*-* }
**	mov	(z[0-9]+\.s), w0
**	movprfx	z0\.s, p0/z, z1\.s
**	udiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_w0_u32_z_untied, svuint32_t, uint32_t,
		 z0 = svdiv_n_u32_z (p0, z1, x0),
		 z0 = svdiv_z (p0, z1, x0))

/*
** div_s0_u32_z_tied1:
**	mov	(z[0-9]+\.s), s0
**	movprfx	z1\.s, p0/z, z1\.s
**	udiv	z1\.s, p0/m, z1\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_s0_u32_z_tied1, svuint32_t, uint32_t,
		 z1 = svdiv_n_u32_z (p0, z1, d0),
		 z1 = svdiv_z (p0, z1, d0))

/*
** div_s0_u32_z_untied: { xfail *-*-* }
**	mov	(z[0-9]+\.s), s0
**	movprfx	z1\.s, p0/z, z2\.s
**	udiv	z1\.s, p0/m, z1\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_s0_u32_z_untied, svuint32_t, uint32_t,
		 z1 = svdiv_n_u32_z (p0, z2, d0),
		 z1 = svdiv_z (p0, z2, d0))

/*
** div_u32_x_tied1:
**	udiv	z0\.s, p0/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (div_u32_x_tied1, svuint32_t,
		z0 = svdiv_u32_x (p0, z0, z1),
		z0 = svdiv_x (p0, z0, z1))

/*
** div_u32_x_tied2:
**	udivr	z1\.s, p0/m, z1\.s, z0\.s
**	ret
*/
TEST_UNIFORM_Z (div_u32_x_tied2, svuint32_t,
		z1 = svdiv_u32_x (p0, z0, z1),
		z1 = svdiv_x (p0, z0, z1))

/*
** div_u32_x_untied:
**	movprfx	z2, z0
**	udiv	z2\.s, p0/m, z2\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (div_u32_x_untied, svuint32_t,
		z2 = svdiv_u32_x (p0, z0, z1),
		z2 = svdiv_x (p0, z0, z1))

/*
** div_w0_u32_x_tied1:
**	mov	(z[0-9]+\.s), w0
**	udiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_w0_u32_x_tied1, svuint32_t, uint32_t,
		 z0 = svdiv_n_u32_x (p0, z0, x0),
		 z0 = svdiv_x (p0, z0, x0))

/*
** div_w0_u32_x_untied:
**	mov	z1\.s, w0
**	udivr	z1\.s, p0/m, z1\.s, z0\.s
**	ret
*/
TEST_UNIFORM_ZS (div_w0_u32_x_untied, svuint32_t, uint32_t,
		 z1 = svdiv_n_u32_x (p0, z0, x0),
		 z1 = svdiv_x (p0, z0, x0))

/*
** div_s0_u32_x_tied1:
**	mov	(z[0-9]+\.s), s0
**	udiv	z1\.s, p0/m, z1\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_s0_u32_x_tied1, svuint32_t, uint32_t,
		 z1 = svdiv_n_u32_x (p0, z1, d0),
		 z1 = svdiv_x (p0, z1, d0))

/*
** div_s0_u32_x_untied:
**	mov	z2\.s, s0
**	udivr	z2\.s, p0/m, z2\.s, z1\.s
**	ret
*/
TEST_UNIFORM_ZS (div_s0_u32_x_untied, svuint32_t, uint32_t,
		 z2 = svdiv_n_u32_x (p0, z1, d0),
		 z2 = svdiv_x (p0, z1, d0))

/*
** div_2_u32_x_tied1:
**	mov	(z[0-9]+\.s), #2
**	udiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_Z (div_2_u32_x_tied1, svuint32_t,
		z0 = svdiv_n_u32_x (p0, z0, 2),
		z0 = svdiv_x (p0, z0, 2))

/*
** div_2_u32_x_untied:
**	mov	z0\.s, #2
**	udivr	z0\.s, p0/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (div_2_u32_x_untied, svuint32_t,
		z0 = svdiv_n_u32_x (p0, z1, 2),
		z0 = svdiv_x (p0, z1, 2))

