/*
 * FCML - Free Code Manipulation Library.
 * Copyright (C) 2010-2015 Slawomir Wojtasiak
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <fcml_assembler.h>
#include "instructions_u_t.h"
#include "instructions_base_t.h"

fcml_bool fcml_tf_instructions_u_suite_init(void) {
    return FCML_TRUE;
}

fcml_bool fcml_tf_instructions_u_suite_cleanup(void) {
    return FCML_TRUE;
}

void fcml_tf_instruction_UCOMISD(void) {

    FCML_I32( "ucomisd xmm2,mmword ptr [ecx+eax]", 0x66, 0x0F, 0x2E, 0x14, 0x01 );
    FCML_I64( "ucomisd xmm2,mmword ptr [rcx+rax]", 0x66, 0x0F, 0x2E, 0x14, 0x01 );
    FCML_I64( "ucomisd xmm0,xmm0", 0x66, 0x0F, 0x2E, 0xC0 );

    FCML_A64( "ucomisd (%rcx,%rax),%xmm2", 0x66, 0x0f, 0x2e, 0x14, 0x01 );
    FCML_A64( "ucomisd (%rcx,%rax),%xmm2", 0x66, 0x0f, 0x2e, 0x14, 0x01 );
    FCML_A64( "ucomisd %xmm0,%xmm0", 0x66, 0x0f, 0x2e, 0xc0 );

    FCML_I32_M("vucomisd xmm0,mmword ptr [eax]", 2, FCML_MI(0x62, 0xf1, 0xfd, 0x08, 0x2e, 0x00), FCML_MI(0xc5, 0xf9, 0x2e, 0x00));
    FCML_I64_M("vucomisd xmm0,xmm1", 2, FCML_MI(0x62, 0xf1, 0xfd, 0x08, 0x2e, 0xc1), FCML_MI(0xc5, 0xf9, 0x2e, 0xc1));
    FCML_A64_M("vucomisd (%rax),%xmm0", 2, FCML_MI(0x62, 0xf1, 0xfd, 0x08, 0x2e, 0x00), FCML_MI(0xc5, 0xf9, 0x2e, 0x00));
    FCML_A64_M("vucomisd %xmm1,%xmm0", 2, FCML_MI(0x62, 0xf1, 0xfd, 0x08, 0x2e, 0xc1), FCML_MI(0xc5, 0xf9, 0x2e, 0xc1));

    /* AVX-512 */

    FCML_I64("vucomisd xmm1,xmm4,{sae}", 0x62, 0xf1, 0xFD, 0x18, 0x2e, 0xcc);
    FCML_I32_M("vucomisd xmm1,mmword ptr [eax]", 2, FCML_MI(0x62, 0xf1, 0xfd, 0x08, 0x2e, 0x08), FCML_MI(0xc5, 0xf9, 0x2e, 0x08));
}

void fcml_tf_instruction_UCOMISS(void) {

    FCML_I32( "ucomiss xmm2,dword ptr [ecx+eax]", 0x0F, 0x2E, 0x14, 0x01 );
    FCML_I64( "ucomiss xmm2,dword ptr [rcx+rax]", 0x0F, 0x2E, 0x14, 0x01 );
    FCML_I64( "ucomiss xmm0,xmm0", 0x0F, 0x2E, 0xC0 );

    FCML_A64( "ucomiss (%rcx,%rax),%xmm2", 0x0f, 0x2e, 0x14, 0x01 );
    FCML_A64( "ucomiss (%rcx,%rax),%xmm2", 0x0f, 0x2e, 0x14, 0x01 );
    FCML_A64( "ucomiss %xmm0,%xmm0", 0x0f, 0x2e, 0xc0 );

    FCML_I32_M("vucomiss xmm0,dword ptr [eax]", 2, FCML_MI(0x62, 0xf1, 0x7c, 0x08, 0x2e, 0x00), FCML_MI(0xc5, 0xf8, 0x2e, 0x00));
    FCML_I64_M("vucomiss xmm0,xmm1", 2, FCML_MI(0x62, 0xf1, 0x7c, 0x08, 0x2e, 0xc1), FCML_MI(0xc5, 0xf8, 0x2e, 0xc1));
    FCML_A64_M("vucomiss (%rax),%xmm0", 2, FCML_MI(0x62, 0xf1, 0x7c, 0x08, 0x2e, 0x00), FCML_MI(0xc5, 0xf8, 0x2e, 0x00));
    FCML_A64_M("vucomiss %xmm1,%xmm0", 2, FCML_MI(0x62, 0xf1, 0x7c, 0x08, 0x2e, 0xc1), FCML_MI(0xc5, 0xf8, 0x2e, 0xc1));

    /* AVX-512 */

    FCML_I64("vucomiss xmm1,xmm4,{sae}", 0x62, 0xf1, 0x7C, 0x18, 0x2e, 0xcc);
    FCML_I32_M("vucomiss xmm1,dword ptr [eax]", 2, FCML_MI(0x62, 0xf1, 0x7c, 0x08, 0x2e, 0x08), FCML_MI(0xc5, 0xf8, 0x2e, 0x08));
}

void fcml_tf_instruction_UD2(void) {

    FCML_I3264( "ud2", 0x0F, 0x0B );
    FCML_A64( "ud2", 0x0f, 0x0b );
}

void fcml_tf_instruction_UNPCKHPD(void) {

    FCML_I32( "unpckhpd xmm0,xmmword ptr [eax]", 0x66, 0x0F, 0x15, 0x00 );
    FCML_I32( "unpckhpd xmm0,xmm0",  0x66, 0x0F, 0x15, 0xC0 );
    FCML_I64( "unpckhpd xmm0,xmmword ptr [rax]", 0x66, 0x0F, 0x15, 0x00 );

    FCML_A64( "unpckhpd (%rax),%xmm0", 0x66, 0x0f, 0x15, 0x00 );
    FCML_A64( "unpckhpd %xmm0,%xmm0", 0x66, 0x0f, 0x15, 0xc0 );

    FCML_I32_M("vunpckhpd xmm0,xmm6,xmmword ptr [eax]", 2, FCML_MI(0x62, 0xf1, 0xcd, 0x08, 0x15, 0x00), FCML_MI(0xc5, 0xc9, 0x15, 0x00));
    FCML_I32_M("vunpckhpd xmm0,xmm6,xmm0", 2, FCML_MI(0x62, 0xf1, 0xcd, 0x08, 0x15, 0xc0), FCML_MI(0xc5, 0xc9, 0x15, 0xc0));
    FCML_I64_M("vunpckhpd xmm0,xmm6,xmmword ptr [rax]", 2, FCML_MI(0x62, 0xf1, 0xcd, 0x08, 0x15, 0x00), FCML_MI(0xc5, 0xc9, 0x15, 0x00));
    FCML_I64_M("vunpckhpd ymm0,ymm6,ymmword ptr [rax]", 2, FCML_MI(0x62, 0xf1, 0xcd, 0x28, 0x15, 0x00), FCML_MI(0xc5, 0xcd, 0x15, 0x00));
    FCML_A64_M("vunpckhpd %xmm0,%xmm6,%xmm0", 2, FCML_MI(0x62, 0xf1, 0xcd, 0x08, 0x15, 0xc0), FCML_MI(0xc5, 0xc9, 0x15, 0xc0));
    FCML_A64_M("vunpckhpd (%rax),%xmm6,%xmm0", 2, FCML_MI(0x62, 0xf1, 0xcd, 0x08, 0x15, 0x00), FCML_MI(0xc5, 0xc9, 0x15, 0x00));
    FCML_A64_M("vunpckhpd (%rax),%ymm6,%ymm0", 2, FCML_MI(0x62, 0xf1, 0xcd, 0x28, 0x15, 0x00), FCML_MI(0xc5, 0xcd, 0x15, 0x00));

    FCML_A64_A_FAILED("vunpckhpd (%rax),%zmm7,%zmm15", 0xc5, 0x41, 0x15, 0x38);

    /* xmm1, xmm2, m128 */
    FCML_A64_M("vunpckhpd (%rax),%xmm7,%xmm15", 2, FCML_MI(0x62, 0x71, 0xc5, 0x08, 0x15, 0x38), FCML_MI(0xc5, 0x41, 0x15, 0x38));
    FCML_I64_M("vunpckhpd xmm15,xmm7,xmmword ptr [rax]", 2, FCML_MI(0x62, 0x71, 0xc5, 0x08, 0x15, 0x38), FCML_MI(0xc5, 0x41, 0x15, 0x38));
    FCML_A32_M("vunpckhpd (%eax),%xmm6,%xmm7", 2, FCML_MI(0x62, 0xf1, 0xcd, 0x08, 0x15, 0x38), FCML_MI(0xc5, 0xc9, 0x15, 0x38));
    FCML_I32_M("vunpckhpd xmm7,xmm6,xmmword ptr [eax]", 2, FCML_MI(0x62, 0xf1, 0xcd, 0x08, 0x15, 0x38), FCML_MI(0xc5, 0xc9, 0x15, 0x38));
    /* ymm1, ymm2, m256 */
    FCML_A64_M("vunpckhpd (%rax),%ymm7,%ymm15", 2, FCML_MI(0x62, 0x71, 0xc5, 0x28, 0x15, 0x38), FCML_MI(0xc5, 0x45, 0x15, 0x38));
    FCML_I64_M("vunpckhpd ymm15,ymm7,ymmword ptr [rax]", 2, FCML_MI(0x62, 0x71, 0xc5, 0x28, 0x15, 0x38), FCML_MI(0xc5, 0x45, 0x15, 0x38));
    FCML_A32_M("vunpckhpd (%eax),%ymm5,%ymm7", 2, FCML_MI(0x62, 0xf1, 0xd5, 0x28, 0x15, 0x38), FCML_MI(0xc5, 0xd5, 0x15, 0x38));
    FCML_I32_M("vunpckhpd ymm7,ymm5,ymmword ptr [eax]", 2, FCML_MI(0x62, 0xf1, 0xd5, 0x28, 0x15, 0x38), FCML_MI(0xc5, 0xd5, 0x15, 0x38));
    /* zmm1, zmm2, m512 */
    FCML_A64("vunpckhpd (%rax),%zmm7,%zmm15", 0x62, 0x71, 0xc5, 0x48, 0x15, 0x38);
    FCML_I64("vunpckhpd zmm15,zmm7,zmmword ptr [rax]", 0x62, 0x71, 0xc5, 0x48, 0x15, 0x38);
    FCML_A32("vunpckhpd (%eax),%zmm3,%zmm7", 0x62, 0xf1, 0xe5, 0x48, 0x15, 0x38);
    FCML_I32("vunpckhpd zmm7,zmm3,zmmword ptr [eax]", 0x62, 0xf1, 0xe5, 0x48, 0x15, 0x38);
    /* xmm1, xmm2, xmm3 */
    FCML_A64_M("vunpckhpd %xmm1,%xmm7,%xmm15", 2, FCML_MI(0x62, 0x71, 0xc5, 0x08, 0x15, 0xf9), FCML_MI(0xc5, 0x41, 0x15, 0xf9));
    FCML_I64_M("vunpckhpd xmm15,xmm7,xmm1", 2, FCML_MI(0x62, 0x71, 0xc5, 0x08, 0x15, 0xf9), FCML_MI(0xc5, 0x41, 0x15, 0xf9));
    FCML_A32_M("vunpckhpd %xmm1,%xmm2,%xmm7", 2, FCML_MI(0x62, 0xf1, 0xed, 0x08, 0x15, 0xf9), FCML_MI(0xc5, 0xe9, 0x15, 0xf9));
    FCML_I32_M("vunpckhpd xmm7,xmm2,xmm1", 2, FCML_MI(0x62, 0xf1, 0xed, 0x08, 0x15, 0xf9), FCML_MI(0xc5, 0xe9, 0x15, 0xf9));
    /* ymm1, ymm2, ymm3 */
    FCML_A64_M("vunpckhpd %ymm6,%ymm7,%ymm14", 2, FCML_MI(0x62, 0x71, 0xc5, 0x28, 0x15, 0xf6), FCML_MI(0xc5, 0x45, 0x15, 0xf6));
    FCML_I64_M("vunpckhpd ymm14,ymm7,ymm6", 2, FCML_MI(0x62, 0x71, 0xc5, 0x28, 0x15, 0xf6), FCML_MI(0xc5, 0x45, 0x15, 0xf6));
    FCML_A32_M("vunpckhpd %ymm5,%ymm3,%ymm6", 2, FCML_MI(0x62, 0xf1, 0xe5, 0x28, 0x15, 0xf5), FCML_MI(0xc5, 0xe5, 0x15, 0xf5));
    FCML_I32_M("vunpckhpd ymm6,ymm3,ymm5", 2, FCML_MI(0x62, 0xf1, 0xe5, 0x28, 0x15, 0xf5), FCML_MI(0xc5, 0xe5, 0x15, 0xf5));
    /* zmm1, zmm2, zmm3 */
    FCML_A64("vunpckhpd %zmm4,%zmm15,%zmm6", 0x62, 0xf1, 0x85, 0x48, 0x15, 0xf4);
    FCML_I64("vunpckhpd zmm6,zmm15,zmm4", 0x62, 0xf1, 0x85, 0x48, 0x15, 0xf4);
    FCML_A32("vunpckhpd %zmm4,%zmm6,%zmm6", 0x62, 0xf1, 0xcd, 0x48, 0x15, 0xf4);
    FCML_I32("vunpckhpd zmm6,zmm6,zmm4", 0x62, 0xf1, 0xcd, 0x48, 0x15, 0xf4);
    /* disp8 */
    FCML_I32("vunpckhpd zmm1,zmm2,zmmword ptr [esp+00000200h]", 0x62, 0xf1, 0xed, 0x48, 0x15, 0x4c, 0x24, 0x08);
    FCML_A32("vunpckhpd 0x00000200(%esp),%zmm2,%zmm1", 0x62, 0xf1, 0xed, 0x48, 0x15, 0x4c, 0x24, 0x08);
    FCML_I64("vunpckhpd zmm1,zmm2,zmmword ptr [rsp+0000000000000200h]", 0x62, 0xf1, 0xed, 0x48, 0x15, 0x4c, 0x24, 0x08);
    FCML_A64("vunpckhpd 0x0000000000000200(%rsp),%zmm2,%zmm1", 0x62, 0xf1, 0xed, 0x48, 0x15, 0x4c, 0x24, 0x08);
    FCML_I32_M("vunpckhpd ymm1,ymm2,ymmword ptr [esp+00000100h]", 2, FCML_MI(0x62, 0xf1, 0xed, 0x28, 0x15, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xed, 0x15, 0x8c, 0x24, 0x00, 0x01, 0x00, 0x00));
    FCML_A32_M("vunpckhpd 0x00000100(%esp),%ymm2,%ymm1", 2, FCML_MI(0x62, 0xf1, 0xed, 0x28, 0x15, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xed, 0x15, 0x8c, 0x24, 0x00, 0x01, 0x00, 0x00));
    FCML_I64_M("vunpckhpd ymm1,ymm2,ymmword ptr [rsp+0000000000000100h]", 2, FCML_MI(0x62, 0xf1, 0xed, 0x28, 0x15, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xed, 0x15, 0x8c, 0x24, 0x00, 0x01, 0x00, 0x00));
    FCML_A64_M("vunpckhpd 0x0000000000000100(%rsp),%ymm2,%ymm1", 2, FCML_MI(0x62, 0xf1, 0xed, 0x28, 0x15, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xed, 0x15, 0x8c, 0x24, 0x00, 0x01, 0x00, 0x00));
    FCML_I32_M("vunpckhpd xmm1,xmm2,xmmword ptr [esp+00000080h]", 2, FCML_MI(0x62, 0xf1, 0xed, 0x08, 0x15, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xe9, 0x15, 0x8c, 0x24, 0x80, 0x00, 0x00, 0x00));
    FCML_A32_M("vunpckhpd 0x00000080(%esp),%xmm2,%xmm1", 2, FCML_MI(0x62, 0xf1, 0xed, 0x08, 0x15, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xe9, 0x15, 0x8c, 0x24, 0x80, 0x00, 0x00, 0x00));
    FCML_I64_M("vunpckhpd xmm1,xmm2,xmmword ptr [rsp+0000000000000080h]", 2, FCML_MI(0x62, 0xf1, 0xed, 0x08, 0x15, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xe9, 0x15, 0x8c, 0x24, 0x80, 0x00, 0x00, 0x00));
    FCML_A64_M("vunpckhpd 0x0000000000000080(%rsp),%xmm2,%xmm1", 2, FCML_MI(0x62, 0xf1, 0xed, 0x08, 0x15, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xe9, 0x15, 0x8c, 0x24, 0x80, 0x00, 0x00, 0x00));
    /* {k}{z} */
    FCML_A64("vunpckhpd (%r9,%r8),%xmm14,%xmm10{%k4}{z}", 0x62, 0x11, 0x8d, 0x8c, 0x15, 0x14, 0x01);
    FCML_I64("vunpckhpd xmm10{k4}{z},xmm14,xmmword ptr [r9+r8]", 0x62, 0x11, 0x8d, 0x8c, 0x15, 0x14, 0x01);
    FCML_A32("vunpckhpd (%ecx,%eax),%xmm7,%xmm2{%k5}{z}", 0x62, 0xf1, 0xc5, 0x8d, 0x15, 0x14, 0x01);
    FCML_I32("vunpckhpd xmm2{k5}{z},xmm7,xmmword ptr [ecx+eax]", 0x62, 0xf1, 0xc5, 0x8d, 0x15, 0x14, 0x01);
    FCML_A64("vunpckhpd (%r9,%r8),%ymm14,%ymm10{%k4}{z}", 0x62, 0x11, 0x8d, 0xac, 0x15, 0x14, 0x01);
    FCML_I64("vunpckhpd ymm10{k4}{z},ymm14,ymmword ptr [r9+r8]", 0x62, 0x11, 0x8d, 0xac, 0x15, 0x14, 0x01);
    FCML_A32("vunpckhpd (%ecx,%eax),%ymm7,%ymm2{%k5}{z}", 0x62, 0xf1, 0xc5, 0xad, 0x15, 0x14, 0x01);
    FCML_I32("vunpckhpd ymm2{k5}{z},ymm7,ymmword ptr [ecx+eax]", 0x62, 0xf1, 0xc5, 0xad, 0x15, 0x14, 0x01);
    FCML_A64("vunpckhpd (%r9,%r8),%zmm14,%zmm10{%k4}{z}", 0x62, 0x11, 0x8d, 0xcc, 0x15, 0x14, 0x01);
    FCML_I64("vunpckhpd zmm10{k4}{z},zmm14,zmmword ptr [r9+r8]", 0x62, 0x11, 0x8d, 0xcc, 0x15, 0x14, 0x01);
    FCML_A32("vunpckhpd (%ecx,%eax),%zmm7,%zmm2{%k5}{z}", 0x62, 0xf1, 0xc5, 0xcd, 0x15, 0x14, 0x01);
    FCML_I32("vunpckhpd zmm2{k5}{z},zmm7,zmmword ptr [ecx+eax]", 0x62, 0xf1, 0xc5, 0xcd, 0x15, 0x14, 0x01);
    /* {k} */
    FCML_A64("vunpckhpd (%r9,%r8),%xmm14,%xmm10{%k4}", 0x62, 0x11, 0x8d, 0x0c, 0x15, 0x14, 0x01);
    FCML_I64("vunpckhpd xmm10{k4},xmm14,xmmword ptr [r9+r8]", 0x62, 0x11, 0x8d, 0x0c, 0x15, 0x14, 0x01);
    FCML_A32("vunpckhpd (%ecx,%eax),%xmm7,%xmm2{%k5}", 0x62, 0xf1, 0xc5, 0x0d, 0x15, 0x14, 0x01);
    FCML_I32("vunpckhpd xmm2{k5},xmm7,xmmword ptr [ecx+eax]", 0x62, 0xf1, 0xc5, 0x0d, 0x15, 0x14, 0x01);
    FCML_A64("vunpckhpd (%r9,%r8),%ymm14,%ymm10{%k4}", 0x62, 0x11, 0x8d, 0x2c, 0x15, 0x14, 0x01);
    FCML_I64("vunpckhpd ymm10{k4},ymm14,ymmword ptr [r9+r8]", 0x62, 0x11, 0x8d, 0x2c, 0x15, 0x14, 0x01);
    FCML_A32("vunpckhpd (%ecx,%eax),%ymm7,%ymm2{%k5}", 0x62, 0xf1, 0xc5, 0x2d, 0x15, 0x14, 0x01);
    FCML_I32("vunpckhpd ymm2{k5},ymm7,ymmword ptr [ecx+eax]", 0x62, 0xf1, 0xc5, 0x2d, 0x15, 0x14, 0x01);
    FCML_A64("vunpckhpd (%r9,%r8),%zmm14,%zmm10{%k4}", 0x62, 0x11, 0x8d, 0x4c, 0x15, 0x14, 0x01);
    FCML_I64("vunpckhpd zmm10{k4},zmm14,zmmword ptr [r9+r8]", 0x62, 0x11, 0x8d, 0x4c, 0x15, 0x14, 0x01);
    FCML_A32("vunpckhpd (%ecx,%eax),%zmm7,%zmm2{%k5}", 0x62, 0xf1, 0xc5, 0x4d, 0x15, 0x14, 0x01);
    FCML_I32("vunpckhpd zmm2{k5},zmm7,zmmword ptr [ecx+eax]", 0x62, 0xf1, 0xc5, 0x4d, 0x15, 0x14, 0x01);
    /* bcast */
    FCML_I64("vunpckhpd zmm31,zmm21,mmword ptr [rsi]{1to8}", 0x62, 0x61, 0xd5, 0x50, 0x15, 0x3e);
    FCML_A64("vunpckhpd (%rsi){1to8},%zmm21,%zmm31", 0x62, 0x61, 0xd5, 0x50, 0x15, 0x3e);
    FCML_I64("vunpckhpd ymm31,ymm21,mmword ptr [rsi]{1to4}", 0x62, 0x61, 0xd5, 0x30, 0x15, 0x3e);
    FCML_A64("vunpckhpd (%rsi){1to4},%ymm21,%ymm31", 0x62, 0x61, 0xd5, 0x30, 0x15, 0x3e);
    FCML_I64("vunpckhpd xmm31,xmm21,mmword ptr [rsi]{1to2}", 0x62, 0x61, 0xd5, 0x10, 0x15, 0x3e);
    FCML_A64("vunpckhpd (%rsi){1to2},%xmm21,%xmm31", 0x62, 0x61, 0xd5, 0x10, 0x15, 0x3e);
    FCML_A32("vunpckhpd (%esi){1to8},%zmm2,%zmm1", 0x62, 0xf1, 0xed, 0x58, 0x15, 0x0e);
    FCML_I32("vunpckhpd zmm1,zmm2,mmword ptr [esi]{1to8}", 0x62, 0xf1, 0xed, 0x58, 0x15, 0x0e);
    /* {k}{z}{bcast} */
    FCML_A64("vunpckhpd (%rsi){1to4},%ymm21,%ymm31{%k7}{z}", 0x62, 0x61, 0xd5, 0xb7, 0x15, 0x3e);
    FCML_I64("vunpckhpd ymm31{k7}{z},ymm21,mmword ptr [rsi]{1to4}", 0x62, 0x61, 0xd5, 0xb7, 0x15, 0x3e);
    /* {bcast} disp8 */
    FCML_I32("vunpckhpd zmm1,zmm2,mmword ptr [esp+00000040h]{1to8}", 0x62, 0xf1, 0xed, 0x58, 0x15, 0x4c, 0x24, 0x08);
    FCML_A32("vunpckhpd 0x00000040(%esp){1to8},%zmm2,%zmm1", 0x62, 0xf1, 0xed, 0x58, 0x15, 0x4c, 0x24, 0x08);
    FCML_I64("vunpckhpd zmm1,zmm2,mmword ptr [rsp+0000000000000040h]{1to8}", 0x62, 0xf1, 0xed, 0x58, 0x15, 0x4c, 0x24, 0x08);
    FCML_A64("vunpckhpd 0x0000000000000040(%rsp){1to8},%zmm2,%zmm1", 0x62, 0xf1, 0xed, 0x58, 0x15, 0x4c, 0x24, 0x08);
    FCML_I32("vunpckhpd ymm1,ymm2,mmword ptr [esp+00000040h]{1to4}", 0x62, 0xf1, 0xed, 0x38, 0x15, 0x4c, 0x24, 0x08);
    FCML_A32("vunpckhpd 0x00000040(%esp){1to4},%ymm2,%ymm1", 0x62, 0xf1, 0xed, 0x38, 0x15, 0x4c, 0x24, 0x08);
    FCML_I64("vunpckhpd ymm1,ymm2,mmword ptr [rsp+0000000000000040h]{1to4}", 0x62, 0xf1, 0xed, 0x38, 0x15, 0x4c, 0x24, 0x08);
    FCML_A64("vunpckhpd 0x0000000000000040(%rsp){1to4},%ymm2,%ymm1", 0x62, 0xf1, 0xed, 0x38, 0x15, 0x4c, 0x24, 0x08);
    FCML_I32("vunpckhpd xmm1,xmm2,mmword ptr [esp+00000040h]{1to2}", 0x62, 0xf1, 0xed, 0x18, 0x15, 0x4c, 0x24, 0x08);
    FCML_A32("vunpckhpd 0x00000040(%esp){1to2},%xmm2,%xmm1", 0x62, 0xf1, 0xed, 0x18, 0x15, 0x4c, 0x24, 0x08);
    FCML_I64("vunpckhpd xmm1,xmm2,mmword ptr [rsp+0000000000000040h]{1to2}", 0x62, 0xf1, 0xed, 0x18, 0x15, 0x4c, 0x24, 0x08);
    FCML_A64("vunpckhpd 0x0000000000000040(%rsp){1to2},%xmm2,%xmm1", 0x62, 0xf1, 0xed, 0x18, 0x15, 0x4c, 0x24, 0x08);
}

void fcml_tf_instruction_UNPCKHPS(void) {

    FCML_I32( "unpckhps xmm0,xmmword ptr [eax]", 0x0F, 0x15, 0x00 );
    FCML_I32( "unpckhps xmm0,xmm0", 0x0F, 0x15, 0xC0 );
    FCML_I64( "unpckhps xmm0,xmmword ptr [rax]", 0x0F, 0x15, 0x00 );
    FCML_A64( "unpckhps (%rax),%xmm0", 0x0f, 0x15, 0x00 );
    FCML_A64( "unpckhps %xmm0,%xmm0", 0x0f, 0x15, 0xc0 );

    FCML_I32_M("vunpckhps xmm0,xmm6,xmmword ptr [eax]", 2, FCML_MI(0x62, 0xf1, 0x4c, 0x08, 0x15, 0x00), FCML_MI(0xc5, 0xc8, 0x15, 0x00));
    FCML_I32_M("vunpckhps xmm0,xmm6,xmm0", 2, FCML_MI(0x62, 0xf1, 0x4c, 0x08, 0x15, 0xc0), FCML_MI(0xc5, 0xc8, 0x15, 0xc0));
    FCML_I64_M("vunpckhps xmm0,xmm6,xmmword ptr [rax]", 2, FCML_MI(0x62, 0xf1, 0x4c, 0x08, 0x15, 0x00), FCML_MI(0xc5, 0xc8, 0x15, 0x00));
    FCML_A64_M("vunpckhps (%rax),%xmm6,%xmm0", 2, FCML_MI(0x62, 0xf1, 0x4c, 0x08, 0x15, 0x00), FCML_MI(0xc5, 0xc8, 0x15, 0x00));
    FCML_A64_M("vunpckhps %xmm0,%xmm6,%xmm0", 2, FCML_MI(0x62, 0xf1, 0x4c, 0x08, 0x15, 0xc0), FCML_MI(0xc5, 0xc8, 0x15, 0xc0));

    /* xmm1, xmm2, m128 */
    FCML_A64_M("vunpckhps (%rax),%xmm7,%xmm15", 2, FCML_MI(0x62, 0x71, 0x44, 0x08, 0x15, 0x38), FCML_MI(0xc5, 0x40, 0x15, 0x38));
    FCML_I64_M("vunpckhps xmm15,xmm7,xmmword ptr [rax]", 2, FCML_MI(0x62, 0x71, 0x44, 0x08, 0x15, 0x38), FCML_MI(0xc5, 0x40, 0x15, 0x38));
    FCML_A32_M("vunpckhps (%eax),%xmm6,%xmm7", 2, FCML_MI(0x62, 0xf1, 0x4c, 0x08, 0x15, 0x38), FCML_MI(0xc5, 0xc8, 0x15, 0x38));
    FCML_I32_M("vunpckhps xmm7,xmm6,xmmword ptr [eax]", 2, FCML_MI(0x62, 0xf1, 0x4c, 0x08, 0x15, 0x38), FCML_MI(0xc5, 0xc8, 0x15, 0x38));
    /* ymm1, ymm2, m256 */
    FCML_A64_M("vunpckhps (%rax),%ymm7,%ymm15", 2, FCML_MI(0x62, 0x71, 0x44, 0x28, 0x15, 0x38), FCML_MI(0xc5, 0x44, 0x15, 0x38));
    FCML_I64_M("vunpckhps ymm15,ymm7,ymmword ptr [rax]", 2, FCML_MI(0x62, 0x71, 0x44, 0x28, 0x15, 0x38), FCML_MI(0xc5, 0x44, 0x15, 0x38));
    FCML_A32_M("vunpckhps (%eax),%ymm5,%ymm7", 2, FCML_MI(0x62, 0xf1, 0x54, 0x28, 0x15, 0x38), FCML_MI(0xc5, 0xd4, 0x15, 0x38));
    FCML_I32_M("vunpckhps ymm7,ymm5,ymmword ptr [eax]", 2, FCML_MI(0x62, 0xf1, 0x54, 0x28, 0x15, 0x38), FCML_MI(0xc5, 0xd4, 0x15, 0x38));
    /* zmm1, zmm2, m512 */
    FCML_A64("vunpckhps (%rax),%zmm7,%zmm15", 0x62, 0x71, 0x44, 0x48, 0x15, 0x38);
    FCML_I64("vunpckhps zmm15,zmm7,zmmword ptr [rax]", 0x62, 0x71, 0x44, 0x48, 0x15, 0x38);
    FCML_A32("vunpckhps (%eax),%zmm3,%zmm7", 0x62, 0xf1, 0x64, 0x48, 0x15, 0x38);
    FCML_I32("vunpckhps zmm7,zmm3,zmmword ptr [eax]", 0x62, 0xf1, 0x64, 0x48, 0x15, 0x38);
    /* xmm1, xmm2, xmm3 */
    FCML_A64_M("vunpckhps %xmm1,%xmm7,%xmm15", 2, FCML_MI(0x62, 0x71, 0x44, 0x08, 0x15, 0xf9), FCML_MI(0xc5, 0x40, 0x15, 0xf9));
    FCML_I64_M("vunpckhps xmm15,xmm7,xmm1", 2, FCML_MI(0x62, 0x71, 0x44, 0x08, 0x15, 0xf9), FCML_MI(0xc5, 0x40, 0x15, 0xf9));
    FCML_A32_M("vunpckhps %xmm1,%xmm2,%xmm7", 2, FCML_MI(0x62, 0xf1, 0x6c, 0x08, 0x15, 0xf9), FCML_MI(0xc5, 0xe8, 0x15, 0xf9));
    FCML_I32_M("vunpckhps xmm7,xmm2,xmm1", 2, FCML_MI(0x62, 0xf1, 0x6c, 0x08, 0x15, 0xf9), FCML_MI(0xc5, 0xe8, 0x15, 0xf9));
    /* ymm1, ymm2, ymm3 */
    FCML_A64_M("vunpckhps %ymm6,%ymm7,%ymm14", 2, FCML_MI(0x62, 0x71, 0x44, 0x28, 0x15, 0xf6), FCML_MI(0xc5, 0x44, 0x15, 0xf6));
    FCML_I64_M("vunpckhps ymm14,ymm7,ymm6", 2, FCML_MI(0x62, 0x71, 0x44, 0x28, 0x15, 0xf6), FCML_MI(0xc5, 0x44, 0x15, 0xf6));
    FCML_A32_M("vunpckhps %ymm5,%ymm3,%ymm6", 2, FCML_MI(0x62, 0xf1, 0x64, 0x28, 0x15, 0xf5), FCML_MI(0xc5, 0xe4, 0x15, 0xf5));
    FCML_I32_M("vunpckhps ymm6,ymm3,ymm5", 2, FCML_MI(0x62, 0xf1, 0x64, 0x28, 0x15, 0xf5), FCML_MI(0xc5, 0xe4, 0x15, 0xf5));
    /* zmm1, zmm2, zmm3 */
    FCML_A64("vunpckhps %zmm4,%zmm15,%zmm6", 0x62, 0xf1, 0x04, 0x48, 0x15, 0xf4);
    FCML_I64("vunpckhps zmm6,zmm15,zmm4", 0x62, 0xf1, 0x04, 0x48, 0x15, 0xf4);
    FCML_A32("vunpckhps %zmm4,%zmm6,%zmm6", 0x62, 0xf1, 0x4c, 0x48, 0x15, 0xf4);
    FCML_I32("vunpckhps zmm6,zmm6,zmm4", 0x62, 0xf1, 0x4c, 0x48, 0x15, 0xf4);
    /* disp8 */
    FCML_I32("vunpckhps zmm1,zmm2,zmmword ptr [esp+00000200h]", 0x62, 0xf1, 0x6c, 0x48, 0x15, 0x4c, 0x24, 0x08);
    FCML_A32("vunpckhps 0x00000200(%esp),%zmm2,%zmm1", 0x62, 0xf1, 0x6c, 0x48, 0x15, 0x4c, 0x24, 0x08);
    FCML_I64("vunpckhps zmm1,zmm2,zmmword ptr [rsp+0000000000000200h]", 0x62, 0xf1, 0x6c, 0x48, 0x15, 0x4c, 0x24, 0x08);
    FCML_A64("vunpckhps 0x0000000000000200(%rsp),%zmm2,%zmm1", 0x62, 0xf1, 0x6c, 0x48, 0x15, 0x4c, 0x24, 0x08);
    FCML_I32_M("vunpckhps ymm1,ymm2,ymmword ptr [esp+00000100h]", 2, FCML_MI(0x62, 0xf1, 0x6c, 0x28, 0x15, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xec, 0x15, 0x8c, 0x24, 0x00, 0x01, 0x00, 0x00));
    FCML_A32_M("vunpckhps 0x00000100(%esp),%ymm2,%ymm1", 2, FCML_MI(0x62, 0xf1, 0x6c, 0x28, 0x15, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xec, 0x15, 0x8c, 0x24, 0x00, 0x01, 0x00, 0x00));
    FCML_I64_M("vunpckhps ymm1,ymm2,ymmword ptr [rsp+0000000000000100h]", 2, FCML_MI(0x62, 0xf1, 0x6c, 0x28, 0x15, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xec, 0x15, 0x8c, 0x24, 0x00, 0x01, 0x00, 0x00));
    FCML_A64_M("vunpckhps 0x0000000000000100(%rsp),%ymm2,%ymm1", 2, FCML_MI(0x62, 0xf1, 0x6c, 0x28, 0x15, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xec, 0x15, 0x8c, 0x24, 0x00, 0x01, 0x00, 0x00));
    FCML_I32_M("vunpckhps xmm1,xmm2,xmmword ptr [esp+00000080h]", 2, FCML_MI(0x62, 0xf1, 0x6c, 0x08, 0x15, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xe8, 0x15, 0x8c, 0x24, 0x80, 0x00, 0x00, 0x00));
    FCML_A32_M("vunpckhps 0x00000080(%esp),%xmm2,%xmm1", 2, FCML_MI(0x62, 0xf1, 0x6c, 0x08, 0x15, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xe8, 0x15, 0x8c, 0x24, 0x80, 0x00, 0x00, 0x00));
    FCML_I64_M("vunpckhps xmm1,xmm2,xmmword ptr [rsp+0000000000000080h]", 2, FCML_MI(0x62, 0xf1, 0x6c, 0x08, 0x15, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xe8, 0x15, 0x8c, 0x24, 0x80, 0x00, 0x00, 0x00));
    FCML_A64_M("vunpckhps 0x0000000000000080(%rsp),%xmm2,%xmm1", 2, FCML_MI(0x62, 0xf1, 0x6c, 0x08, 0x15, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xe8, 0x15, 0x8c, 0x24, 0x80, 0x00, 0x00, 0x00));
    /* {k}{z} */
    FCML_A64("vunpckhps (%r9,%r8),%xmm14,%xmm10{%k4}{z}", 0x62, 0x11, 0x0c, 0x8c, 0x15, 0x14, 0x01);
    FCML_I64("vunpckhps xmm10{k4}{z},xmm14,xmmword ptr [r9+r8]", 0x62, 0x11, 0x0c, 0x8c, 0x15, 0x14, 0x01);
    FCML_A32("vunpckhps (%ecx,%eax),%xmm7,%xmm2{%k5}{z}", 0x62, 0xf1, 0x44, 0x8d, 0x15, 0x14, 0x01);
    FCML_I32("vunpckhps xmm2{k5}{z},xmm7,xmmword ptr [ecx+eax]", 0x62, 0xf1, 0x44, 0x8d, 0x15, 0x14, 0x01);
    FCML_A64("vunpckhps (%r9,%r8),%ymm14,%ymm10{%k4}{z}", 0x62, 0x11, 0x0c, 0xac, 0x15, 0x14, 0x01);
    FCML_I64("vunpckhps ymm10{k4}{z},ymm14,ymmword ptr [r9+r8]", 0x62, 0x11, 0x0c, 0xac, 0x15, 0x14, 0x01);
    FCML_A32("vunpckhps (%ecx,%eax),%ymm7,%ymm2{%k5}{z}", 0x62, 0xf1, 0x44, 0xad, 0x15, 0x14, 0x01);
    FCML_I32("vunpckhps ymm2{k5}{z},ymm7,ymmword ptr [ecx+eax]", 0x62, 0xf1, 0x44, 0xad, 0x15, 0x14, 0x01);
    FCML_A64("vunpckhps (%r9,%r8),%zmm14,%zmm10{%k4}{z}", 0x62, 0x11, 0x0c, 0xcc, 0x15, 0x14, 0x01);
    FCML_I64("vunpckhps zmm10{k4}{z},zmm14,zmmword ptr [r9+r8]", 0x62, 0x11, 0x0c, 0xcc, 0x15, 0x14, 0x01);
    FCML_A32("vunpckhps (%ecx,%eax),%zmm7,%zmm2{%k5}{z}", 0x62, 0xf1, 0x44, 0xcd, 0x15, 0x14, 0x01);
    FCML_I32("vunpckhps zmm2{k5}{z},zmm7,zmmword ptr [ecx+eax]", 0x62, 0xf1, 0x44, 0xcd, 0x15, 0x14, 0x01);
    /* {k} */
    FCML_A64("vunpckhps (%r9,%r8),%xmm14,%xmm10{%k4}", 0x62, 0x11, 0x0c, 0x0c, 0x15, 0x14, 0x01);
    FCML_I64("vunpckhps xmm10{k4},xmm14,xmmword ptr [r9+r8]", 0x62, 0x11, 0x0c, 0x0c, 0x15, 0x14, 0x01);
    FCML_A32("vunpckhps (%ecx,%eax),%xmm7,%xmm2{%k5}", 0x62, 0xf1, 0x44, 0x0d, 0x15, 0x14, 0x01);
    FCML_I32("vunpckhps xmm2{k5},xmm7,xmmword ptr [ecx+eax]", 0x62, 0xf1, 0x44, 0x0d, 0x15, 0x14, 0x01);
    FCML_A64("vunpckhps (%r9,%r8),%ymm14,%ymm10{%k4}", 0x62, 0x11, 0x0c, 0x2c, 0x15, 0x14, 0x01);
    FCML_I64("vunpckhps ymm10{k4},ymm14,ymmword ptr [r9+r8]", 0x62, 0x11, 0x0c, 0x2c, 0x15, 0x14, 0x01);
    FCML_A32("vunpckhps (%ecx,%eax),%ymm7,%ymm2{%k5}", 0x62, 0xf1, 0x44, 0x2d, 0x15, 0x14, 0x01);
    FCML_I32("vunpckhps ymm2{k5},ymm7,ymmword ptr [ecx+eax]", 0x62, 0xf1, 0x44, 0x2d, 0x15, 0x14, 0x01);
    FCML_A64("vunpckhps (%r9,%r8),%zmm14,%zmm10{%k4}", 0x62, 0x11, 0x0c, 0x4c, 0x15, 0x14, 0x01);
    FCML_I64("vunpckhps zmm10{k4},zmm14,zmmword ptr [r9+r8]", 0x62, 0x11, 0x0c, 0x4c, 0x15, 0x14, 0x01);
    FCML_A32("vunpckhps (%ecx,%eax),%zmm7,%zmm2{%k5}", 0x62, 0xf1, 0x44, 0x4d, 0x15, 0x14, 0x01);
    FCML_I32("vunpckhps zmm2{k5},zmm7,zmmword ptr [ecx+eax]", 0x62, 0xf1, 0x44, 0x4d, 0x15, 0x14, 0x01);
    /* bcast */
    FCML_I64("vunpckhps zmm31,zmm21,dword ptr [rsi]{1to16}", 0x62, 0x61, 0x54, 0x50, 0x15, 0x3e);
    FCML_A64("vunpckhps (%rsi){1to16},%zmm21,%zmm31", 0x62, 0x61, 0x54, 0x50, 0x15, 0x3e);
    FCML_I64("vunpckhps ymm31,ymm21,dword ptr [rsi]{1to8}", 0x62, 0x61, 0x54, 0x30, 0x15, 0x3e);
    FCML_A64("vunpckhps (%rsi){1to8},%ymm21,%ymm31", 0x62, 0x61, 0x54, 0x30, 0x15, 0x3e);
    FCML_I64("vunpckhps xmm31,xmm21,dword ptr [rsi]{1to4}", 0x62, 0x61, 0x54, 0x10, 0x15, 0x3e);
    FCML_A64("vunpckhps (%rsi){1to4},%xmm21,%xmm31", 0x62, 0x61, 0x54, 0x10, 0x15, 0x3e);
    FCML_A32("vunpckhps (%esi){1to16},%zmm2,%zmm1", 0x62, 0xf1, 0x6c, 0x58, 0x15, 0x0e);
    FCML_I32("vunpckhps zmm1,zmm2,dword ptr [esi]{1to16}", 0x62, 0xf1, 0x6c, 0x58, 0x15, 0x0e);
    /* {k}{z}{bcast} */
    FCML_A64("vunpckhps (%rsi){1to8},%ymm21,%ymm31{%k7}{z}", 0x62, 0x61, 0x54, 0xb7, 0x15, 0x3e);
    FCML_I64("vunpckhps ymm31{k7}{z},ymm21,dword ptr [rsi]{1to8}", 0x62, 0x61, 0x54, 0xb7, 0x15, 0x3e);
    /* {bcast} disp8 */
    FCML_I32("vunpckhps zmm1,zmm2,dword ptr [esp+00000020h]{1to16}", 0x62, 0xf1, 0x6c, 0x58, 0x15, 0x4c, 0x24, 0x08);
    FCML_A32("vunpckhps 0x00000020(%esp){1to16},%zmm2,%zmm1", 0x62, 0xf1, 0x6c, 0x58, 0x15, 0x4c, 0x24, 0x08);
    FCML_I64("vunpckhps zmm1,zmm2,dword ptr [rsp+0000000000000020h]{1to16}", 0x62, 0xf1, 0x6c, 0x58, 0x15, 0x4c, 0x24, 0x08);
    FCML_A64("vunpckhps 0x0000000000000020(%rsp){1to16},%zmm2,%zmm1", 0x62, 0xf1, 0x6c, 0x58, 0x15, 0x4c, 0x24, 0x08);
    FCML_I32("vunpckhps ymm1,ymm2,dword ptr [esp+00000020h]{1to8}", 0x62, 0xf1, 0x6c, 0x38, 0x15, 0x4c, 0x24, 0x08);
    FCML_A32("vunpckhps 0x00000020(%esp){1to8},%ymm2,%ymm1", 0x62, 0xf1, 0x6c, 0x38, 0x15, 0x4c, 0x24, 0x08);
    FCML_I64("vunpckhps ymm1,ymm2,dword ptr [rsp+0000000000000020h]{1to8}", 0x62, 0xf1, 0x6c, 0x38, 0x15, 0x4c, 0x24, 0x08);
    FCML_A64("vunpckhps 0x0000000000000020(%rsp){1to8},%ymm2,%ymm1", 0x62, 0xf1, 0x6c, 0x38, 0x15, 0x4c, 0x24, 0x08);
    FCML_I32("vunpckhps xmm1,xmm2,dword ptr [esp+00000020h]{1to4}", 0x62, 0xf1, 0x6c, 0x18, 0x15, 0x4c, 0x24, 0x08);
    FCML_A32("vunpckhps 0x00000020(%esp){1to4},%xmm2,%xmm1", 0x62, 0xf1, 0x6c, 0x18, 0x15, 0x4c, 0x24, 0x08);
    FCML_I64("vunpckhps xmm1,xmm2,dword ptr [rsp+0000000000000020h]{1to4}", 0x62, 0xf1, 0x6c, 0x18, 0x15, 0x4c, 0x24, 0x08);
    FCML_A64("vunpckhps 0x0000000000000020(%rsp){1to4},%xmm2,%xmm1", 0x62, 0xf1, 0x6c, 0x18, 0x15, 0x4c, 0x24, 0x08);
}

void fcml_tf_instruction_UNPCKLPD(void) {

    FCML_I32( "unpcklpd xmm0,xmmword ptr [eax]", 0x66, 0x0F, 0x14, 0x00 );
    FCML_I32( "unpcklpd xmm0,xmm0",  0x66, 0x0F, 0x14, 0xC0 );
    FCML_I64( "unpcklpd xmm0,xmmword ptr [rax]", 0x66, 0x0F, 0x14, 0x00 );

    FCML_A64( "unpcklpd %xmm0,%xmm0", 0x66, 0x0f, 0x14, 0xc0 );
    FCML_A64( "unpcklpd (%rax),%xmm0", 0x66, 0x0f, 0x14, 0x00 );

    FCML_I32_M("vunpcklpd xmm0,xmm6,xmmword ptr [eax]", 2, FCML_MI(0x62, 0xf1, 0xcd, 0x08, 0x14, 0x00), FCML_MI(0xc5, 0xc9, 0x14, 0x00));
    FCML_I32_M("vunpcklpd xmm0,xmm6,xmm0", 2, FCML_MI(0x62, 0xf1, 0xcd, 0x08, 0x14, 0xc0), FCML_MI(0xc5, 0xc9, 0x14, 0xc0));
    FCML_I64_M("vunpcklpd xmm0,xmm6,xmmword ptr [rax]", 2, FCML_MI(0x62, 0xf1, 0xcd, 0x08, 0x14, 0x00), FCML_MI(0xc5, 0xc9, 0x14, 0x00));
    FCML_A64_M("vunpcklpd %xmm0,%xmm6,%xmm0", 2, FCML_MI(0x62, 0xf1, 0xcd, 0x08, 0x14, 0xc0), FCML_MI(0xc5, 0xc9, 0x14, 0xc0));
    FCML_A64_M("vunpcklpd (%rax),%xmm6,%xmm0", 2, FCML_MI(0x62, 0xf1, 0xcd, 0x08, 0x14, 0x00), FCML_MI(0xc5, 0xc9, 0x14, 0x00));

    /* xmm1, xmm2, m128 */
    FCML_A64_M("vunpcklpd (%rax),%xmm7,%xmm15", 2, FCML_MI(0x62, 0x71, 0xc5, 0x08, 0x14, 0x38), FCML_MI(0xc5, 0x41, 0x14, 0x38));
    FCML_I64_M("vunpcklpd xmm15,xmm7,xmmword ptr [rax]", 2, FCML_MI(0x62, 0x71, 0xc5, 0x08, 0x14, 0x38), FCML_MI(0xc5, 0x41, 0x14, 0x38));
    FCML_A32_M("vunpcklpd (%eax),%xmm6,%xmm7", 2, FCML_MI(0x62, 0xf1, 0xcd, 0x08, 0x14, 0x38), FCML_MI(0xc5, 0xc9, 0x14, 0x38));
    FCML_I32_M("vunpcklpd xmm7,xmm6,xmmword ptr [eax]", 2, FCML_MI(0x62, 0xf1, 0xcd, 0x08, 0x14, 0x38), FCML_MI(0xc5, 0xc9, 0x14, 0x38));
    /* ymm1, ymm2, m256 */
    FCML_A64_M("vunpcklpd (%rax),%ymm7,%ymm15", 2, FCML_MI(0x62, 0x71, 0xc5, 0x28, 0x14, 0x38), FCML_MI(0xc5, 0x45, 0x14, 0x38));
    FCML_I64_M("vunpcklpd ymm15,ymm7,ymmword ptr [rax]", 2, FCML_MI(0x62, 0x71, 0xc5, 0x28, 0x14, 0x38), FCML_MI(0xc5, 0x45, 0x14, 0x38));
    FCML_A32_M("vunpcklpd (%eax),%ymm5,%ymm7", 2, FCML_MI(0x62, 0xf1, 0xd5, 0x28, 0x14, 0x38), FCML_MI(0xc5, 0xd5, 0x14, 0x38));
    FCML_I32_M("vunpcklpd ymm7,ymm5,ymmword ptr [eax]", 2, FCML_MI(0x62, 0xf1, 0xd5, 0x28, 0x14, 0x38), FCML_MI(0xc5, 0xd5, 0x14, 0x38));
    /* zmm1, zmm2, m512 */
    FCML_A64("vunpcklpd (%rax),%zmm7,%zmm15", 0x62, 0x71, 0xc5, 0x48, 0x14, 0x38);
    FCML_I64("vunpcklpd zmm15,zmm7,zmmword ptr [rax]", 0x62, 0x71, 0xc5, 0x48, 0x14, 0x38);
    FCML_A32("vunpcklpd (%eax),%zmm3,%zmm7", 0x62, 0xf1, 0xe5, 0x48, 0x14, 0x38);
    FCML_I32("vunpcklpd zmm7,zmm3,zmmword ptr [eax]", 0x62, 0xf1, 0xe5, 0x48, 0x14, 0x38);
    /* xmm1, xmm2, xmm3 */
    FCML_A64_M("vunpcklpd %xmm1,%xmm7,%xmm15", 2, FCML_MI(0x62, 0x71, 0xc5, 0x08, 0x14, 0xf9), FCML_MI(0xc5, 0x41, 0x14, 0xf9));
    FCML_I64_M("vunpcklpd xmm15,xmm7,xmm1", 2, FCML_MI(0x62, 0x71, 0xc5, 0x08, 0x14, 0xf9), FCML_MI(0xc5, 0x41, 0x14, 0xf9));
    FCML_A32_M("vunpcklpd %xmm1,%xmm2,%xmm7", 2, FCML_MI(0x62, 0xf1, 0xed, 0x08, 0x14, 0xf9), FCML_MI(0xc5, 0xe9, 0x14, 0xf9));
    FCML_I32_M("vunpcklpd xmm7,xmm2,xmm1", 2, FCML_MI(0x62, 0xf1, 0xed, 0x08, 0x14, 0xf9), FCML_MI(0xc5, 0xe9, 0x14, 0xf9));
    /* ymm1, ymm2, ymm3 */
    FCML_A64_M("vunpcklpd %ymm6,%ymm7,%ymm14", 2, FCML_MI(0x62, 0x71, 0xc5, 0x28, 0x14, 0xf6), FCML_MI(0xc5, 0x45, 0x14, 0xf6));
    FCML_I64_M("vunpcklpd ymm14,ymm7,ymm6", 2, FCML_MI(0x62, 0x71, 0xc5, 0x28, 0x14, 0xf6), FCML_MI(0xc5, 0x45, 0x14, 0xf6));
    FCML_A32_M("vunpcklpd %ymm5,%ymm3,%ymm6", 2, FCML_MI(0x62, 0xf1, 0xe5, 0x28, 0x14, 0xf5), FCML_MI(0xc5, 0xe5, 0x14, 0xf5));
    FCML_I32_M("vunpcklpd ymm6,ymm3,ymm5", 2, FCML_MI(0x62, 0xf1, 0xe5, 0x28, 0x14, 0xf5), FCML_MI(0xc5, 0xe5, 0x14, 0xf5));
    /* zmm1, zmm2, zmm3 */
    FCML_A64("vunpcklpd %zmm4,%zmm15,%zmm6", 0x62, 0xf1, 0x85, 0x48, 0x14, 0xf4);
    FCML_I64("vunpcklpd zmm6,zmm15,zmm4", 0x62, 0xf1, 0x85, 0x48, 0x14, 0xf4);
    FCML_A32("vunpcklpd %zmm4,%zmm6,%zmm6", 0x62, 0xf1, 0xcd, 0x48, 0x14, 0xf4);
    FCML_I32("vunpcklpd zmm6,zmm6,zmm4", 0x62, 0xf1, 0xcd, 0x48, 0x14, 0xf4);
    /* disp8 */
    FCML_I32("vunpcklpd zmm1,zmm2,zmmword ptr [esp+00000200h]", 0x62, 0xf1, 0xed, 0x48, 0x14, 0x4c, 0x24, 0x08);
    FCML_A32("vunpcklpd 0x00000200(%esp),%zmm2,%zmm1", 0x62, 0xf1, 0xed, 0x48, 0x14, 0x4c, 0x24, 0x08);
    FCML_I64("vunpcklpd zmm1,zmm2,zmmword ptr [rsp+0000000000000200h]", 0x62, 0xf1, 0xed, 0x48, 0x14, 0x4c, 0x24, 0x08);
    FCML_A64("vunpcklpd 0x0000000000000200(%rsp),%zmm2,%zmm1", 0x62, 0xf1, 0xed, 0x48, 0x14, 0x4c, 0x24, 0x08);
    FCML_I32_M("vunpcklpd ymm1,ymm2,ymmword ptr [esp+00000100h]", 2, FCML_MI(0x62, 0xf1, 0xed, 0x28, 0x14, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xed, 0x14, 0x8c, 0x24, 0x00, 0x01, 0x00, 0x00));
    FCML_A32_M("vunpcklpd 0x00000100(%esp),%ymm2,%ymm1", 2, FCML_MI(0x62, 0xf1, 0xed, 0x28, 0x14, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xed, 0x14, 0x8c, 0x24, 0x00, 0x01, 0x00, 0x00));
    FCML_I64_M("vunpcklpd ymm1,ymm2,ymmword ptr [rsp+0000000000000100h]", 2, FCML_MI(0x62, 0xf1, 0xed, 0x28, 0x14, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xed, 0x14, 0x8c, 0x24, 0x00, 0x01, 0x00, 0x00));
    FCML_A64_M("vunpcklpd 0x0000000000000100(%rsp),%ymm2,%ymm1", 2, FCML_MI(0x62, 0xf1, 0xed, 0x28, 0x14, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xed, 0x14, 0x8c, 0x24, 0x00, 0x01, 0x00, 0x00));
    FCML_I32_M("vunpcklpd xmm1,xmm2,xmmword ptr [esp+00000080h]", 2, FCML_MI(0x62, 0xf1, 0xed, 0x08, 0x14, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xe9, 0x14, 0x8c, 0x24, 0x80, 0x00, 0x00, 0x00));
    FCML_A32_M("vunpcklpd 0x00000080(%esp),%xmm2,%xmm1", 2, FCML_MI(0x62, 0xf1, 0xed, 0x08, 0x14, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xe9, 0x14, 0x8c, 0x24, 0x80, 0x00, 0x00, 0x00));
    FCML_I64_M("vunpcklpd xmm1,xmm2,xmmword ptr [rsp+0000000000000080h]", 2, FCML_MI(0x62, 0xf1, 0xed, 0x08, 0x14, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xe9, 0x14, 0x8c, 0x24, 0x80, 0x00, 0x00, 0x00));
    FCML_A64_M("vunpcklpd 0x0000000000000080(%rsp),%xmm2,%xmm1", 2, FCML_MI(0x62, 0xf1, 0xed, 0x08, 0x14, 0x4c, 0x24, 0x08), FCML_MI(0xc5, 0xe9, 0x14, 0x8c, 0x24, 0x80, 0x00, 0x00, 0x00));
    /* {k}{z} */
    FCML_A64("vunpcklpd (%r9,%r8),%xmm14,%xmm10{%k4}{z}", 0x62, 0x11, 0x8d, 0x8c, 0x14, 0x14, 0x01);
    FCML_I64("vunpcklpd xmm10{k4}{z},xmm14,xmmword ptr [r9+r8]", 0x62, 0x11, 0x8d, 0x8c, 0x14, 0x14, 0x01);
    FCML_A32("vunpcklpd (%ecx,%eax),%xmm7,%xmm2{%k5}{z}", 0x62, 0xf1, 0xc5, 0x8d, 0x14, 0x14, 0x01);
    FCML_I32("vunpcklpd xmm2{k5}{z},xmm7,xmmword ptr [ecx+eax]", 0x62, 0xf1, 0xc5, 0x8d, 0x14, 0x14, 0x01);
    FCML_A64("vunpcklpd (%r9,%r8),%ymm14,%ymm10{%k4}{z}", 0x62, 0x11, 0x8d, 0xac, 0x14, 0x14, 0x01);
    FCML_I64("vunpcklpd ymm10{k4}{z},ymm14,ymmword ptr [r9+r8]", 0x62, 0x11, 0x8d, 0xac, 0x14, 0x14, 0x01);
    FCML_A32("vunpcklpd (%ecx,%eax),%ymm7,%ymm2{%k5}{z}", 0x62, 0xf1, 0xc5, 0xad, 0x14, 0x14, 0x01);
    FCML_I32("vunpcklpd ymm2{k5}{z},ymm7,ymmword ptr [ecx+eax]", 0x62, 0xf1, 0xc5, 0xad, 0x14, 0x14, 0x01);
    FCML_A64("vunpcklpd (%r9,%r8),%zmm14,%zmm10{%k4}{z}", 0x62, 0x11, 0x8d, 0xcc, 0x14, 0x14, 0x01);
    FCML_I64("vunpcklpd zmm10{k4}{z},zmm14,zmmword ptr [r9+r8]", 0x62, 0x11, 0x8d, 0xcc, 0x14, 0x14, 0x01);
    FCML_A32("vunpcklpd (%ecx,%eax),%zmm7,%zmm2{%k5}{z}", 0x62, 0xf1, 0xc5, 0xcd, 0x14, 0x14, 0x01);
    FCML_I32("vunpcklpd zmm2{k5}{z},zmm7,zmmword ptr [ecx+eax]", 0x62, 0xf1, 0xc5, 0xcd, 0x14, 0x14, 0x01);
    /* {k} */
    FCML_A64("vunpcklpd (%r9,%r8),%xmm14,%xmm10{%k4}", 0x62, 0x11, 0x8d, 0x0c, 0x14, 0x14, 0x01);
    FCML_I64("vunpcklpd xmm10{k4},xmm14,xmmword ptr [r9+r8]", 0x62, 0x11, 0x8d, 0x0c, 0x14, 0x14, 0x01);
    FCML_A32("vunpcklpd (%ecx,%eax),%xmm7,%xmm2{%k5}", 0x62, 0xf1, 0xc5, 0x0d, 0x14, 0x14, 0x01);
    FCML_I32("vunpcklpd xmm2{k5},xmm7,xmmword ptr [ecx+eax]", 0x62, 0xf1, 0xc5, 0x0d, 0x14, 0x14, 0x01);
    FCML_A64("vunpcklpd (%r9,%r8),%ymm14,%ymm10{%k4}", 0x62, 0x11, 0x8d, 0x2c, 0x14, 0x14, 0x01);
    FCML_I64("vunpcklpd ymm10{k4},ymm14,ymmword ptr [r9+r8]", 0x62, 0x11, 0x8d, 0x2c, 0x14, 0x14, 0x01);
    FCML_A32("vunpcklpd (%ecx,%eax),%ymm7,%ymm2{%k5}", 0x62, 0xf1, 0xc5, 0x2d, 0x14, 0x14, 0x01);
    FCML_I32("vunpcklpd ymm2{k5},ymm7,ymmword ptr [ecx+eax]", 0x62, 0xf1, 0xc5, 0x2d, 0x14, 0x14, 0x01);
    FCML_A64("vunpcklpd (%r9,%r8),%zmm14,%zmm10{%k4}", 0x62, 0x11, 0x8d, 0x4c, 0x14, 0x14, 0x01);
    FCML_I64("vunpcklpd zmm10{k4},zmm14,zmmword ptr [r9+r8]", 0x62, 0x11, 0x8d, 0x4c, 0x14, 0x14, 0x01);
    FCML_A32("vunpcklpd (%ecx,%eax),%zmm7,%zmm2{%k5}", 0x62, 0xf1, 0xc5, 0x4d, 0x14, 0x14, 0x01);
    FCML_I32("vunpcklpd zmm2{k5},zmm7,zmmword ptr [ecx+eax]", 0x62, 0xf1, 0xc5, 0x4d, 0x14, 0x14, 0x01);
    /* bcast */
    FCML_I64("vunpcklpd zmm31,zmm21,mmword ptr [rsi]{1to8}", 0x62, 0x61, 0xd5, 0x50, 0x14, 0x3e);
    FCML_A64("vunpcklpd (%rsi){1to8},%zmm21,%zmm31", 0x62, 0x61, 0xd5, 0x50, 0x14, 0x3e);
    FCML_I64("vunpcklpd ymm31,ymm21,mmword ptr [rsi]{1to4}", 0x62, 0x61, 0xd5, 0x30, 0x14, 0x3e);
    FCML_A64("vunpcklpd (%rsi){1to4},%ymm21,%ymm31", 0x62, 0x61, 0xd5, 0x30, 0x14, 0x3e);
    FCML_I64("vunpcklpd xmm31,xmm21,mmword ptr [rsi]{1to2}", 0x62, 0x61, 0xd5, 0x10, 0x14, 0x3e);
    FCML_A64("vunpcklpd (%rsi){1to2},%xmm21,%xmm31", 0x62, 0x61, 0xd5, 0x10, 0x14, 0x3e);
    FCML_A32("vunpcklpd (%esi){1to8},%zmm2,%zmm1", 0x62, 0xf1, 0xed, 0x58, 0x14, 0x0e);
    FCML_I32("vunpcklpd zmm1,zmm2,mmword ptr [esi]{1to8}", 0x62, 0xf1, 0xed, 0x58, 0x14, 0x0e);
    /* {k}{z}{bcast} */
    FCML_A64("vunpcklpd (%rsi){1to4},%ymm21,%ymm31{%k7}{z}", 0x62, 0x61, 0xd5, 0xb7, 0x14, 0x3e);
    FCML_I64("vunpcklpd ymm31{k7}{z},ymm21,mmword ptr [rsi]{1to4}", 0x62, 0x61, 0xd5, 0xb7, 0x14, 0x3e);
    /* {bcast} disp8 */
    FCML_I32("vunpcklpd zmm1,zmm2,mmword ptr [esp+00000040h]{1to8}", 0x62, 0xf1, 0xed, 0x58, 0x14, 0x4c, 0x24, 0x08);
    FCML_A32("vunpcklpd 0x00000040(%esp){1to8},%zmm2,%zmm1", 0x62, 0xf1, 0xed, 0x58, 0x14, 0x4c, 0x24, 0x08);
    FCML_I64("vunpcklpd zmm1,zmm2,mmword ptr [rsp+0000000000000040h]{1to8}", 0x62, 0xf1, 0xed, 0x58, 0x14, 0x4c, 0x24, 0x08);
    FCML_A64("vunpcklpd 0x0000000000000040(%rsp){1to8},%zmm2,%zmm1", 0x62, 0xf1, 0xed, 0x58, 0x14, 0x4c, 0x24, 0x08);
    FCML_I32("vunpcklpd ymm1,ymm2,mmword ptr [esp+00000040h]{1to4}", 0x62, 0xf1, 0xed, 0x38, 0x14, 0x4c, 0x24, 0x08);
    FCML_A32("vunpcklpd 0x00000040(%esp){1to4},%ymm2,%ymm1", 0x62, 0xf1, 0xed, 0x38, 0x14, 0x4c, 0x24, 0x08);
    FCML_I64("vunpcklpd ymm1,ymm2,mmword ptr [rsp+0000000000000040h]{1to4}", 0x62, 0xf1, 0xed, 0x38, 0x14, 0x4c, 0x24, 0x08);
    FCML_A64("vunpcklpd 0x0000000000000040(%rsp){1to4},%ymm2,%ymm1", 0x62, 0xf1, 0xed, 0x38, 0x14, 0x4c, 0x24, 0x08);
    FCML_I32("vunpcklpd xmm1,xmm2,mmword ptr [esp+00000040h]{1to2}", 0x62, 0xf1, 0xed, 0x18, 0x14, 0x4c, 0x24, 0x08);
    FCML_A32("vunpcklpd 0x00000040(%esp){1to2},%xmm2,%xmm1", 0x62, 0xf1, 0xed, 0x18, 0x14, 0x4c, 0x24, 0x08);
    FCML_I64("vunpcklpd xmm1,xmm2,mmword ptr [rsp+0000000000000040h]{1to2}", 0x62, 0xf1, 0xed, 0x18, 0x14, 0x4c, 0x24, 0x08);
    FCML_A64("vunpcklpd 0x0000000000000040(%rsp){1to2},%xmm2,%xmm1", 0x62, 0xf1, 0xed, 0x18, 0x14, 0x4c, 0x24, 0x08);
}

void fcml_tf_instruction_UNPCKLPS(void) {

    FCML_I32( "unpcklps xmm0,xmmword ptr [eax]", 0x0F, 0x14, 0x00 );
    FCML_I32( "unpcklps xmm0,xmm0", 0x0F, 0x14, 0xC0 );
    FCML_I64( "unpcklps xmm0,xmmword ptr [rax]", 0x0F, 0x14, 0x00 );

    FCML_I32( "vunpcklps xmm0,xmm6,xmmword ptr [eax]", 0xc5, 0xc8, 0x14, 0x00 );
    FCML_I32( "vunpcklps xmm0,xmm6,xmm0", 0xc5, 0xc8, 0x14, 0xc0 );
    FCML_I64( "vunpcklps xmm0,xmm6,xmmword ptr [rax]", 0xc5, 0xc8, 0x14, 0x00 );

    FCML_A64( "unpcklps %xmm0,%xmm0", 0x0f, 0x14, 0xc0 );
    FCML_A64( "unpcklps (%rax),%xmm0", 0x0f, 0x14, 0x00 );
    FCML_A64( "vunpcklps %xmm0,%xmm6,%xmm0", 0xc5, 0xc8, 0x14, 0xc0 );
    FCML_A64( "vunpcklps (%rax),%xmm6,%xmm0", 0xc5, 0xc8, 0x14, 0x00 );
}

fcml_stf_test_case fctl_ti_instructions_u[] = {
    { "fcml_tf_instruction_UCOMISD", fcml_tf_instruction_UCOMISD },
    { "fcml_tf_instruction_UCOMISS", fcml_tf_instruction_UCOMISS },
    { "fcml_tf_instruction_UD2", fcml_tf_instruction_UD2 },
    { "fcml_tf_instruction_UNPCKHPD", fcml_tf_instruction_UNPCKHPD },
    { "fcml_tf_instruction_UNPCKHPS", fcml_tf_instruction_UNPCKHPS },
    { "fcml_tf_instruction_UNPCKLPD", fcml_tf_instruction_UNPCKLPD },
    { "fcml_tf_instruction_UNPCKLPS", fcml_tf_instruction_UNPCKLPS },
    FCML_STF_NULL_TEST
};

fcml_stf_test_suite fctl_si_instructions_u = {
    "suite-fctl_ti_instructions_u", fcml_tf_instructions_u_suite_init, fcml_tf_instructions_u_suite_cleanup, fctl_ti_instructions_u
};

