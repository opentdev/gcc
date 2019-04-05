/* { dg-do compile } */
/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sve_acle.h"

/*
** eor_s8_m_tied1:
**	eor	z0\.b, p0/m, z0\.b, z1\.b
**	ret
*/
TEST_UNIFORM_Z (eor_s8_m_tied1, svint8_t,
		z0 = sveor_s8_m (p0, z0, z1),
		z0 = sveor_m (p0, z0, z1))

/* Bad RA choice: no preferred output sequence.  */
TEST_UNIFORM_Z (eor_s8_m_tied2, svint8_t,
		z1 = sveor_s8_m (p0, z0, z1),
		z1 = sveor_m (p0, z0, z1))

/*
** eor_s8_m_untied:
**	movprfx	z0, z1
**	eor	z0\.b, p0/m, z0\.b, z2\.b
**	ret
*/
TEST_UNIFORM_Z (eor_s8_m_untied, svint8_t,
		z0 = sveor_s8_m (p0, z1, z2),
		z0 = sveor_m (p0, z1, z2))

/*
** eor_w0_s8_m_tied1:
**	mov	(z[0-9]+\.b), w0
**	eor	z0\.b, p0/m, z0\.b, \1
**	ret
*/
TEST_UNIFORM_ZS (eor_w0_s8_m_tied1, svint8_t, int8_t,
		 z0 = sveor_n_s8_m (p0, z0, x0),
		 z0 = sveor_m (p0, z0, x0))

/*
** eor_w0_s8_m_untied:
**	mov	(z[0-9]+\.b), w0
**	movprfx	z0, z1
**	eor	z0\.b, p0/m, z0\.b, \1
**	ret
*/
TEST_UNIFORM_ZS (eor_w0_s8_m_untied, svint8_t, int8_t,
		 z0 = sveor_n_s8_m (p0, z1, x0),
		 z0 = sveor_m (p0, z1, x0))

/*
** eor_b0_s8_m_tied1:
**	mov	(z[0-9]+\.b), b0
**	eor	z1\.b, p0/m, z1\.b, \1
**	ret
*/
TEST_UNIFORM_ZS (eor_b0_s8_m_tied1, svint8_t, int8_t,
		 z1 = sveor_n_s8_m (p0, z1, d0),
		 z1 = sveor_m (p0, z1, d0))

/*
** eor_b0_s8_m_untied:
**	mov	(z[0-9]+\.b), b0
**	movprfx	z1, z2
**	eor	z1\.b, p0/m, z1\.b, \1
**	ret
*/
TEST_UNIFORM_ZS (eor_b0_s8_m_untied, svint8_t, int8_t,
		 z1 = sveor_n_s8_m (p0, z2, d0),
		 z1 = sveor_m (p0, z2, d0))

/*
** eor_1_s8_m_tied1:
**	mov	(z[0-9]+\.b), #1
**	eor	z0\.b, p0/m, z0\.b, \1
**	ret
*/
TEST_UNIFORM_Z (eor_1_s8_m_tied1, svint8_t,
		z0 = sveor_n_s8_m (p0, z0, 1),
		z0 = sveor_m (p0, z0, 1))

/*
** eor_1_s8_m_untied:
**	mov	(z[0-9]+\.b), #1
**	movprfx	z0, z1
**	eor	z0\.b, p0/m, z0\.b, \1
**	ret
*/
TEST_UNIFORM_Z (eor_1_s8_m_untied, svint8_t,
		z0 = sveor_n_s8_m (p0, z1, 1),
		z0 = sveor_m (p0, z1, 1))

/*
** eor_m2_s8_m:
**	mov	(z[0-9]+\.b), #-2
**	eor	z0\.b, p0/m, z0\.b, \1
**	ret
*/
TEST_UNIFORM_Z (eor_m2_s8_m, svint8_t,
		z0 = sveor_n_s8_m (p0, z0, -2),
		z0 = sveor_m (p0, z0, -2))

/*
** eor_s8_z_tied1:
**	movprfx	z0\.b, p0/z, z0\.b
**	eor	z0\.b, p0/m, z0\.b, z1\.b
**	ret
*/
TEST_UNIFORM_Z (eor_s8_z_tied1, svint8_t,
		z0 = sveor_s8_z (p0, z0, z1),
		z0 = sveor_z (p0, z0, z1))

/*
** eor_s8_z_tied2:
**	movprfx	z1\.b, p0/z, z1\.b
**	eor	z1\.b, p0/m, z1\.b, z0\.b
**	ret
*/
TEST_UNIFORM_Z (eor_s8_z_tied2, svint8_t,
		z1 = sveor_s8_z (p0, z0, z1),
		z1 = sveor_z (p0, z0, z1))

/*
** eor_s8_z_untied:
**	movprfx	z0\.b, p0/z, z1\.b
**	eor	z0\.b, p0/m, z0\.b, z2\.b
**	ret
*/
TEST_UNIFORM_Z (eor_s8_z_untied, svint8_t,
		z0 = sveor_s8_z (p0, z1, z2),
		z0 = sveor_z (p0, z1, z2))

/*
** eor_w0_s8_z_tied1:
**	mov	(z[0-9]+\.b), w0
**	movprfx	z0\.b, p0/z, z0\.b
**	eor	z0\.b, p0/m, z0\.b, \1
**	ret
*/
TEST_UNIFORM_ZS (eor_w0_s8_z_tied1, svint8_t, int8_t,
		 z0 = sveor_n_s8_z (p0, z0, x0),
		 z0 = sveor_z (p0, z0, x0))

/*
** eor_w0_s8_z_untied: { xfail *-*-* }
**	mov	(z[0-9]+\.b), w0
**	movprfx	z0\.b, p0/z, z1\.b
**	eor	z0\.b, p0/m, z0\.b, \1
**	ret
*/
TEST_UNIFORM_ZS (eor_w0_s8_z_untied, svint8_t, int8_t,
		 z0 = sveor_n_s8_z (p0, z1, x0),
		 z0 = sveor_z (p0, z1, x0))

/*
** eor_b0_s8_z_tied1:
**	mov	(z[0-9]+\.b), b0
**	movprfx	z1\.b, p0/z, z1\.b
**	eor	z1\.b, p0/m, z1\.b, \1
**	ret
*/
TEST_UNIFORM_ZS (eor_b0_s8_z_tied1, svint8_t, int8_t,
		 z1 = sveor_n_s8_z (p0, z1, d0),
		 z1 = sveor_z (p0, z1, d0))

/*
** eor_b0_s8_z_untied: { xfail *-*-* }
**	mov	(z[0-9]+\.b), b0
**	movprfx	z1\.b, p0/z, z2\.b
**	eor	z1\.b, p0/m, z1\.b, \1
**	ret
*/
TEST_UNIFORM_ZS (eor_b0_s8_z_untied, svint8_t, int8_t,
		 z1 = sveor_n_s8_z (p0, z2, d0),
		 z1 = sveor_z (p0, z2, d0))

/*
** eor_s8_x_tied1:
**	eor	z0\.d, z0\.d, z1\.d
**	ret
*/
TEST_UNIFORM_Z (eor_s8_x_tied1, svint8_t,
		z0 = sveor_s8_x (p0, z0, z1),
		z0 = sveor_x (p0, z0, z1))

/*
** eor_s8_x_tied2:
**	eor	z1\.d, z0\.d, z1\.d
**	ret
*/
TEST_UNIFORM_Z (eor_s8_x_tied2, svint8_t,
		z1 = sveor_s8_x (p0, z0, z1),
		z1 = sveor_x (p0, z0, z1))

/*
** eor_s8_x_untied:
**	eor	z2\.d, z0\.d, z1\.d
**	ret
*/
TEST_UNIFORM_Z (eor_s8_x_untied, svint8_t,
		z2 = sveor_s8_x (p0, z0, z1),
		z2 = sveor_x (p0, z0, z1))

/*
** eor_w0_s8_x_tied1:
**	mov	(z[0-9]+)\.b, w0
**	eor	z0\.d, z0\.d, \1\.d
**	ret
*/
TEST_UNIFORM_ZS (eor_w0_s8_x_tied1, svint8_t, int8_t,
		 z0 = sveor_n_s8_x (p0, z0, x0),
		 z0 = sveor_x (p0, z0, x0))

/*
** eor_w0_s8_x_untied:
**	mov	z1\.b, w0
**	eor	z1\.d, z0\.d, z1\.d
**	ret
*/
TEST_UNIFORM_ZS (eor_w0_s8_x_untied, svint8_t, int8_t,
		 z1 = sveor_n_s8_x (p0, z0, x0),
		 z1 = sveor_x (p0, z0, x0))

/*
** eor_b0_s8_x_tied1:
**	mov	(z[0-9]+)\.b, b0
**	eor	z1\.d, z1\.d, \1\.d
**	ret
*/
TEST_UNIFORM_ZS (eor_b0_s8_x_tied1, svint8_t, int8_t,
		 z1 = sveor_n_s8_x (p0, z1, d0),
		 z1 = sveor_x (p0, z1, d0))

/*
** eor_b0_s8_x_untied:
**	mov	(z[0-9]+)\.b, b0
**	eor	z2\.d, z1\.d, \1\.d
**	ret
*/
TEST_UNIFORM_ZS (eor_b0_s8_x_untied, svint8_t, int8_t,
		 z2 = sveor_n_s8_x (p0, z1, d0),
		 z2 = sveor_x (p0, z1, d0))

/*
** eor_1_s8_x_tied1:
**	eor	z0\.b, z0\.b, #0x1
**	ret
*/
TEST_UNIFORM_Z (eor_1_s8_x_tied1, svint8_t,
		z0 = sveor_n_s8_x (p0, z0, 1),
		z0 = sveor_x (p0, z0, 1))

/*
** eor_1_s8_x_untied:
**	movprfx	z0, z1
**	eor	z0\.b, z0\.b, #0x1
**	ret
*/
TEST_UNIFORM_Z (eor_1_s8_x_untied, svint8_t,
		z0 = sveor_n_s8_x (p0, z1, 1),
		z0 = sveor_x (p0, z1, 1))

/*
** eor_127_s8_x:
**	eor	z0\.b, z0\.b, #0x7f
**	ret
*/
TEST_UNIFORM_Z (eor_127_s8_x, svint8_t,
		z0 = sveor_n_s8_x (p0, z0, 127),
		z0 = sveor_x (p0, z0, 127))

/*
** eor_128_s8_x:
**	eor	z0\.b, z0\.b, #0x80
**	ret
*/
TEST_UNIFORM_Z (eor_128_s8_x, svint8_t,
		z0 = sveor_n_s8_x (p0, z0, 128),
		z0 = sveor_x (p0, z0, 128))

/*
** eor_255_s8_x:
**	mov	(z[0-9]+)\.b, #-1
**	eor	z0\.d, z0\.d, \1\.d
**	ret
*/
TEST_UNIFORM_Z (eor_255_s8_x, svint8_t,
		z0 = sveor_n_s8_x (p0, z0, 255),
		z0 = sveor_x (p0, z0, 255))

/*
** eor_m127_s8_x:
**	eor	z0\.b, z0\.b, #0x81
**	ret
*/
TEST_UNIFORM_Z (eor_m127_s8_x, svint8_t,
		z0 = sveor_n_s8_x (p0, z0, -127),
		z0 = sveor_x (p0, z0, -127))

/*
** eor_m128_s8_x:
**	eor	z0\.b, z0\.b, #0x80
**	ret
*/
TEST_UNIFORM_Z (eor_m128_s8_x, svint8_t,
		z0 = sveor_n_s8_x (p0, z0, -128),
		z0 = sveor_x (p0, z0, -128))

/*
** eor_5_s8_x:
**	mov	(z[0-9]+)\.b, #5
**	eor	z0\.d, z0\.d, \1\.d
**	ret
*/
TEST_UNIFORM_Z (eor_5_s8_x, svint8_t,
		z0 = sveor_n_s8_x (p0, z0, 5),
		z0 = sveor_x (p0, z0, 5))
