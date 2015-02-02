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
#include "instructions_r_t.h"
#include "instructions_base_t.h"

fcml_bool fcml_tf_instructions_r_suite_init(void) {
	return FCML_TRUE;
}

fcml_bool fcml_tf_instructions_r_suite_cleanup(void) {
	return FCML_TRUE;
}

void fcml_tf_instruction_RCL(void) {

    FCML_I32_M( "rcl byte ptr [eax],01h", 2, FCML_MI( 0xc0, 0x10, 0x01 ), FCML_MI( 0xd0, 0x10 ) );
    FCML_I3264_M( "rcl al,01h", 2, FCML_MI( 0xc0, 0xd0, 0x01 ), FCML_MI( 0xd0, 0xd0 ) );

    FCML_A32_M( "rclb $0x01,(%eax)", 2, FCML_MI( 0xc0, 0x10, 0x01 ), FCML_MI( 0xd0, 0x10 ) );
    FCML_A3264_M( "rcl $0x01,%al", 2, FCML_MI( 0xc0, 0xd0, 0x01 ), FCML_MI( 0xd0, 0xd0 ) );

    FCML_I32( "rcl byte ptr [eax],cl", 0xD2, 0x10 );
    FCML_I32( "rcl al,cl", 0xD2, 0xD0 );
    FCML_A64( "rclb %cl,(%rax)", 0xd2, 0x10 );
    FCML_I64_D( "rcl al,cl", 0x48, 0xD2, 0xD0 );

    FCML_I32( "rcl byte ptr [eax],0ffh", 0xc0, 0x10, 0xff );
    FCML_I32( "rcl byte ptr [eax],0ffh", 0xc0, 0x10, 0xff );
    FCML_A64( "rclb $0xff,(%rax)", 0xc0, 0x10, 0xff );
    FCML_I32( "rcl al,0ffh", 0xC0, 0xD0, 0xFF );
    FCML_I64_D( "rcl al,0ffh", 0x48, 0xC0, 0xD0, 0xFF );
    FCML_A64( "rcl $0xff,%al", 0xc0, 0xd0, 0xff );

    FCML_I32_M( "rcl dword ptr [eax],01h", 2, FCML_MI( 0xc1, 0x10, 0x01 ), FCML_MI( 0xd1, 0x10 ) );
    FCML_I32_M( "rcl eax,01h", 2, FCML_MI( 0xc1, 0xd0, 0x01 ), FCML_MI( 0xd1, 0xd0 ) );
    FCML_I64_D( "rcl rax,01h", 0x48, 0xD1, 0xD0 );

    FCML_A64_M( "rcll $0x01,(%rax)", 2, FCML_MI( 0xc1, 0x10, 0x01 ), FCML_MI( 0xd1, 0x10 ) );
    FCML_A64_M( "rcl $0x01,%eax", 2, FCML_MI( 0xc1, 0xd0, 0x01 ), FCML_MI( 0xd1, 0xd0 ) );

    FCML_I32( "rcl dword ptr [eax],cl", 0xD3, 0x10 );
    FCML_I32( "rcl eax,cl", 0xD3, 0xD0 );
    FCML_I64_D( "rcl rax,cl", 0x48, 0xD3, 0xD0 );

    FCML_A64( "rcl %cl,%eax", 0xd3, 0xd0 );
    FCML_A64( "rcl %cl,%rax", 0x48, 0xd3, 0xd0 );

    FCML_I32( "rcl dword ptr [eax],0ffh", 0xC1, 0x10, 0xff );
    FCML_I32( "rcl eax,0ffh", 0xC1, 0xD0, 0xff );
    FCML_I64_D( "rcl rax,0ffh", 0x48, 0xC1, 0xD0, 0xff );

    FCML_A64( "rcl $0xff,%eax", 0xc1, 0xd0, 0xff );
    FCML_A64( "rcl $0xff,%rax", 0x48, 0xc1, 0xd0, 0xff );
}

void fcml_tf_instruction_RCR(void) {

    FCML_I32_M( "rcr byte ptr [eax],01h", 2, FCML_MI( 0xc0, 0x18, 0x01 ), FCML_MI( 0xd0, 0x18 ) );
    FCML_I32_M( "rcr al,01h", 2, FCML_MI( 0xc0, 0xd8, 0x01 ), FCML_MI( 0xd0, 0xd8 ) );
    FCML_I64_M( "rcr al,01h", 2, FCML_MI( 0xc0, 0xd8, 0x01 ), FCML_MI( 0xd0, 0xd8 ) );

    FCML_A64( "rcr $0x00,%al", 0xc0, 0xd8, 0x00 );
    FCML_A64_M( "rcrb $0x01,(%rax)", 2, FCML_MI( 0xc0, 0x18, 0x01 ), FCML_MI( 0xd0, 0x18 ) );

    FCML_I32( "rcr byte ptr [eax],cl", 0xD2, 0x18 );
    FCML_I32( "rcr al,cl", 0xD2, 0xD8 );
    FCML_I64_D( "rcr al,cl", 0x48, 0xD2, 0xD8 );

    FCML_A64( "rcr %cl,%al", 0xd2, 0xd8 );
    FCML_A64( "rcrb %cl,(%rax)", 0xd2, 0x18 );

    FCML_I32( "rcr byte ptr [eax],0ffh", 0xC0, 0x18, 0xFF );
    FCML_I32( "rcr al,0ffh", 0xC0, 0xD8, 0xFF );
    FCML_I64_D( "rcr al,0ffh", 0x48, 0xC0, 0xD8, 0xFF );

    FCML_A64( "rcrb $0xff,(%rax)", 0xc0, 0x18, 0xff );
    FCML_A64( "rcr $0xff,%al", 0xc0, 0xd8, 0xff );

    FCML_I32_M( "rcr dword ptr [eax],01h", 2, FCML_MI( 0xc1, 0x18, 0x01 ), FCML_MI( 0xd1, 0x18 ) );
    FCML_I32_M( "rcr eax,01h", 2, FCML_MI( 0xc1, 0xd8, 0x01 ), FCML_MI( 0xd1, 0xd8 ) );
    FCML_I64_D( "rcr rax,01h", 0x48, 0xD1, 0xD8 );

    FCML_A64_M( "rcrl $0x01,(%rax)", 2, FCML_MI( 0xc1, 0x18, 0x01 ), FCML_MI( 0xd1, 0x18 ) );
    FCML_A64_M( "rcr $0x01,%eax", 2, FCML_MI( 0xc1, 0xd8, 0x01 ), FCML_MI( 0xd1, 0xd8 ) );

    FCML_I32( "rcr dword ptr [eax],cl", 0xD3, 0x18 );
    FCML_I32( "rcr eax,cl", 0xD3, 0xD8 );
    FCML_I64_D( "rcr rax,cl", 0x48, 0xD3, 0xD8 );

    FCML_A64( "rcrl %cl,(%rax)", 0xd3, 0x18 );
    FCML_A64( "rcr %cl,%eax", 0xd3, 0xd8 );

    FCML_I32( "rcr dword ptr [eax],0ffh", 0xC1, 0x18, 0xff );
    FCML_I32( "rcr eax,0ffh", 0xC1, 0xD8, 0xff );
    FCML_I64( "rcr rax,0ffh", 0x48, 0xC1, 0xD8, 0xff );

    FCML_A64( "rcr $0xff,%eax", 0xc1, 0xd8, 0xff );
    FCML_A64( "rcrl $0xff,(%rax)", 0xc1, 0x18, 0xff );
}

void fcml_tf_instruction_ROL(void) {

    FCML_I32_M( "rol byte ptr [eax],01h", 2, FCML_MI( 0xc0, 0x00, 0x01 ), FCML_MI( 0xd0, 0x00 ) );
    FCML_I32_M( "rol al,01h", 2, FCML_MI( 0xc0, 0xc0, 0x01 ), FCML_MI( 0xd0, 0xc0 ) );
    FCML_I64_D( "rol al,01h", 0x48, 0xD0, 0xC0 );

    FCML_A64_M( "rolb $0x01,(%rax)", 2, FCML_MI( 0xc0, 0x00, 0x01 ), FCML_MI( 0xd0, 0x00 ) );
    FCML_A64_M( "rol $0x01,%al", 2, FCML_MI( 0xc0, 0xc0, 0x01 ), FCML_MI( 0xd0, 0xc0 ) );

    FCML_I32( "rol byte ptr [eax],cl", 0xD2, 0x00 );
    FCML_I32( "rol al,cl", 0xD2, 0xC0 );
    FCML_I64_D( "rol al,cl", 0x48, 0xD2, 0xC0 );

    FCML_A64( "rolb %cl,(%rax)", 0xd2, 0x00 );

    FCML_I32( "rol byte ptr [eax],0ffh", 0xC0, 0x00, 0xFF );
    FCML_I32( "rol al,0ffh", 0xC0, 0xC0, 0xFF );
    FCML_I64_D( "rol al,0ffh", 0x48, 0xC0, 0xC0, 0xFF );

    FCML_A64( "rolb $0xff,(%rax)", 0xc0, 0x00, 0xff );
    FCML_A64( "rol $0xff,%al", 0xc0, 0xc0, 0xff );

    FCML_I32_M( "rol dword ptr [eax],01h", 2, FCML_MI( 0xc1, 0x00, 0x01 ), FCML_MI( 0xd1, 0x00 ) );
    FCML_I32_M( "rol eax,01h", 2, FCML_MI( 0xc1, 0xc0, 0x01 ), FCML_MI( 0xd1, 0xc0 ) );
    FCML_I64_D( "rol rax,01h", 0x48, 0xD1, 0xC0 );

    FCML_A64_M( "rol $0x01,%eax", 2, FCML_MI( 0xc1, 0xc0, 0x01 ), FCML_MI( 0xd1, 0xc0 ) );

    FCML_I32( "rol dword ptr [eax],cl", 0xD3, 0x00 );
    FCML_I32( "rol eax,cl", 0xD3, 0xC0 );
    FCML_I64_D( "rol rax,cl", 0x48, 0xD3, 0xC0 );

    FCML_A64( "rol %cl,%eax", 0xd3, 0xc0 );
    FCML_A64( "roll %cl,(%rax)", 0xd3, 0x00 );

    FCML_I32( "rol dword ptr [eax],0ffh", 0xC1, 0x00, 0xff );
    FCML_I32( "rol eax,0ffh", 0xC1, 0xC0, 0xff );
    FCML_I64( "rol rax,0ffh", 0x48, 0xC1, 0xC0, 0xff );

    FCML_A64( "roll $0xff,(%rax)", 0xc1, 0x00, 0xff );
    FCML_A64( "rol $0xff,%eax", 0xc1, 0xc0, 0xff );
}

void fcml_tf_instruction_ROR(void) {

    FCML_I32_M( "ror byte ptr [eax],01h", 2, FCML_MI( 0xc0, 0x08, 0x01 ), FCML_MI( 0xd0, 0x08 ) );
    FCML_I32_M( "ror al,01h", 2, FCML_MI( 0xc0, 0xc8, 0x01 ), FCML_MI( 0xd0, 0xc8 ) );
    FCML_I64_D( "ror al,01h", 0x48, 0xD0, 0xC8 );

    FCML_A64_M( "rorb $0x01,(%rax)", 2, FCML_MI( 0xc0, 0x08, 0x01 ), FCML_MI( 0xd0, 0x08 ) );
    FCML_A64_M( "ror $0x01,%al", 2, FCML_MI( 0xc0, 0xc8, 0x01 ), FCML_MI( 0xd0, 0xc8 ) );

    FCML_I32( "ror byte ptr [eax],cl", 0xD2, 0x08 );
    FCML_I32( "ror al,cl", 0xD2, 0xC8 );
    FCML_I64_D( "ror al,cl", 0x48, 0xD2, 0xC8 );

    FCML_A64( "rorb %cl,(%rax)", 0xd2, 0x08 );
    FCML_A64( "ror %cl,%al", 0xd2, 0xc8 );

    FCML_I32( "ror byte ptr [eax],0ffh", 0xC0, 0x08, 0xFF );
    FCML_I32( "ror al,0ffh", 0xC0, 0xC8, 0xFF );
    FCML_I64_D( "ror al,0ffh", 0x48, 0xC0, 0xC8, 0xFF );

    FCML_A64( "rorb $0xff,(%rax)", 0xc0, 0x08, 0xff );
    FCML_A64( "ror $0xff,%al", 0xc0, 0xc8, 0xff );

    FCML_I32_M( "ror dword ptr [eax],01h", 2, FCML_MI( 0xc1, 0x08, 0x01 ), FCML_MI( 0xd1, 0x08 ) );
    FCML_I32_M( "ror eax,01h", 2, FCML_MI( 0xc1, 0xc8, 0x01 ), FCML_MI( 0xd1, 0xc8 ) );
    FCML_I64_M( "ror rax,01h", 2, FCML_MI( 0x48, 0xc1, 0xc8, 0x01 ), FCML_MI( 0x48, 0xd1, 0xc8 ) );

    FCML_A32_M( "rorl $0x01,(%eax)", 2, FCML_MI( 0xc1, 0x08, 0x01 ), FCML_MI( 0xd1, 0x08 ) );
    FCML_A32_M( "rorw $0x01,(%eax)", 2, FCML_MI( 0x66, 0xc1, 0x08, 0x01 ), FCML_MI( 0x66, 0xd1, 0x08 ) );
    FCML_A64_M( "rorq $0x01,(%rax)", 2, FCML_MI( 0x48, 0xc1, 0x08, 0x01 ), FCML_MI( 0x48, 0xd1, 0x08 ) );

    FCML_I32( "ror dword ptr [eax],cl", 0xD3, 0x08 );
    FCML_I32( "ror eax,cl", 0xD3, 0xC8 );
    FCML_I64( "ror rax,cl", 0x48, 0xD3, 0xC8 );

    FCML_A64( "rorl %cl,(%rax)", 0xd3, 0x08 );

    FCML_I32( "ror dword ptr [eax],0ffh", 0xC1, 0x08, 0xff );
    FCML_I32( "ror eax,0ffh", 0xC1, 0xC8, 0xff );
    FCML_I64( "ror rax,0ffh", 0x48, 0xC1, 0xC8, 0xff );

    FCML_A64( "rorl $0xff,(%rax)", 0xc1, 0x08, 0xff );
    FCML_A64( "ror $0xff,%eax", 0xc1, 0xc8, 0xff );
}

void fcml_tf_instruction_RCPPS(void) {

    FCML_I64( "rcpps xmm0,xmmword ptr [rax]", 0x0F, 0x53, 0x00 );
    FCML_I32( "rcpps xmm0,xmm1", 0x0F, 0x53, 0xC1 );

    FCML_I32( "vrcpps xmm2,xmmword ptr [eax]", 0xc5, 0xf8, 0x53, 0x10 );

    FCML_I32_A( "vrcpps long_form xmm2,xmmword ptr [eax]", 0xc4, 0xe1, 0x78, 0x53, 0x10 );
    FCML_I64( "vrcpps ymm2,ymmword ptr [rax]", 0xc5, 0xfc, 0x53, 0x10 );

    FCML_A64( "rcpps (%rax),%xmm0", 0x0f, 0x53, 0x00 );
    FCML_A64( "rcpps %xmm1,%xmm0", 0x0f, 0x53, 0xc1 );
    FCML_A64( "vrcpps (%rax),%xmm2", 0xc5, 0xf8, 0x53, 0x10 );
    FCML_A64( "vrcpps (%rax),%ymm2", 0xc5, 0xfc, 0x53, 0x10 );
}

void fcml_tf_instruction_RCPSS(void) {

    FCML_I32( "rcpss xmm2,dword ptr [eax]", 0xF3, 0x0F, 0x53, 0x10 );
    FCML_I32( "rcpss xmm3,xmm0", 0xF3, 0x0F, 0x53, 0xD8 );
    FCML_I64( "rcpss xmm2,dword ptr [rax]", 0xF3, 0x0F, 0x53, 0x10 );

    FCML_I64( "vrcpss xmm3,xmm3,xmm0", 0xc5, 0xe2, 0x53, 0xd8 );
    FCML_I32( "vrcpss xmm3,xmm7,xmm0", 0xc5, 0xc2, 0x53, 0xd8 );
    FCML_I32( "vrcpss xmm3,xmm0,dword ptr [eax]", 0xc5, 0xfa, 0x53, 0x18 );

    FCML_A64( "rcpss (%rax),%xmm2", 0xf3, 0x0f, 0x53, 0x10 );
    FCML_A64( "rcpss %xmm0,%xmm3", 0xf3, 0x0f, 0x53, 0xd8 );
    FCML_A64( "rcpss (%rax),%xmm2", 0xf3, 0x0f, 0x53, 0x10 );
    FCML_A64( "vrcpss %xmm0,%xmm3,%xmm3", 0xc5, 0xe2, 0x53, 0xd8 );
    FCML_A64( "vrcpss %xmm0,%xmm7,%xmm3", 0xc5, 0xc2, 0x53, 0xd8 );
    FCML_A64( "vrcpss (%rax),%xmm0,%xmm3", 0xc5, 0xfa, 0x53, 0x18 );
}

void fcml_tf_instruction_RDFSBASE(void) {

    FCML_I32_FAILED( "rdfsbase eax", 0x66, 0xF3, 0x0F, 0xAE, 0xC0 );
    FCML_I64( "rdfsbase eax", 0xF3, 0x0F, 0xAE, 0xC0 );
    FCML_I64_D( "rdfsbase eax", 0x66, 0xF3, 0x0F, 0xAE, 0xC0 );
    FCML_I64( "rdfsbase rax", 0xF3, 0x48, 0x0F, 0xAE, 0xC0 );

    FCML_I32_FAILED( "rdgsbase eax", 0xF3, 0x0F, 0xAE, 0xC8 );
    FCML_I64( "rdgsbase eax", 0xF3, 0x0F, 0xAE, 0xC8 );
    FCML_I64_D( "rdgsbase eax", 0x66, 0xF3, 0x0F, 0xAE, 0xC8 );
    FCML_I64( "rdgsbase rax", 0xF3, 0x48, 0x0F, 0xAE, 0xC8 );

    FCML_A64( "rdfsbase %eax", 0xf3, 0x0f, 0xae, 0xc0 );
    FCML_A64( "rdfsbase %rax", 0xf3, 0x48, 0x0f, 0xae, 0xc0 );
    FCML_A64( "rdgsbase %eax", 0xf3, 0x0f, 0xae, 0xc8 );
    FCML_A64( "rdgsbase %rax", 0xf3, 0x48, 0x0f, 0xae, 0xc8 );
}

void fcml_tf_instruction_RDRAND(void) {

    FCML_I32( "rdrand ax", 0x66, 0x0F, 0xC7, 0xF0 );
    FCML_I64( "rdrand ax", 0x66, 0x0F, 0xC7, 0xF0 );

    FCML_I32( "rdrand eax", 0x0F, 0xC7, 0xF0 );
    FCML_I64( "rdrand eax", 0x0F, 0xC7, 0xF0 );

    FCML_I64( "rdrand rax", 0x48, 0x0F, 0xC7, 0xF0 );

    FCML_A64( "rdrand %ax", 0x66, 0x0f, 0xc7, 0xf0 );
    FCML_A64( "rdrand %eax", 0x0f, 0xc7, 0xf0 );
    FCML_A64( "rdrand %rax", 0x48, 0x0f, 0xc7, 0xf0 );
}

void fcml_tf_instruction_RDTSCP(void) {

    FCML_I32( "rdtscp", 0x0f, 0x01, 0xf9 );
    FCML_I64( "rdtscp", 0x0f, 0x01, 0xf9 );

    FCML_A64( "rdtscp", 0x0f, 0x01, 0xf9 );
}

void fcml_tf_instruction_RDTSC(void) {

    FCML_I3264( "rdtsc", 0x0F, 0x31 );

    FCML_A3264( "rdtsc", 0x0F, 0x31 );
}

void fcml_tf_instruction_RDPMC(void) {

    FCML_I3264( "rdpmc", 0x0F, 0x33 );

    FCML_A64( "rdpmc", 0x0f, 0x33 );
}

void fcml_tf_instruction_RDMSR(void) {

    FCML_I3264( "rdmsr", 0x0F, 0x32 );

    FCML_A64( "rdmsr", 0x0f, 0x32 );
}

void fcml_tf_instruction_RET(void) {

    FCML_I3264( "ret", 0xC3 );
    FCML_I3264( "retf", 0xCB );

    FCML_I3264( "ret 0ffffh", 0xC2, 0xFF, 0xFF );
    FCML_I3264( "retf 0ffffh", 0xCA, 0xFF, 0xFF );

    FCML_A64( "retq", 0xc3 );
    FCML_A32( "ret", 0xc3 );
    FCML_A64( "retw", 0x66, 0xc3 );
    FCML_A32( "ret $0xffff", 0xc2, 0xff, 0xff );
    FCML_A64( "retq $0xffff", 0xc2, 0xff, 0xff );
    FCML_A64( "retw $0xffff", 0x66, 0xc2, 0xff, 0xff );
    FCML_A64( "lretw", 0x66, 0xcb );
    FCML_A64( "lret", 0xcb );
    FCML_A64( "lretq", 0x48, 0xcb );
    FCML_A64( "lretq $0xffff", 0x48, 0xca, 0xff, 0xff );
    FCML_A32( "lret $0xffff", 0xca, 0xff, 0xff );
    FCML_A64( "lretw $0xffff", 0x66, 0xca, 0xff, 0xff );
}

void fcml_tf_instruction_ROUNDPD(void) {

    FCML_I64( "roundpd xmm0,xmmword ptr [rax],0ffh", 0x66, 0x0F, 0x3A, 0x09, 0x00, 0xFF );
    FCML_I32( "roundpd xmm0,xmm1,0ffh", 0x66, 0x0F, 0x3A, 0x09, 0xC1, 0xFF );

    FCML_I64( "vroundpd xmm3,xmm0,0ffh", 0xC4, 0xE3, 0x79, 0x09, 0xD8, 0xFF );
    FCML_I32( "vroundpd xmm3,xmm0,0ffh", 0xC4, 0xE3, 0x79, 0x09, 0xD8, 0xFF );
    FCML_I32( "vroundpd ymm0,ymmword ptr [eax],0ffh", 0xC4, 0xE3, 0x7D, 0x09, 0x00, 0xFF );

    FCML_A64( "roundpd $0xff,(%rax),%xmm0", 0x66, 0x0f, 0x3a, 0x09, 0x00, 0xff );
    FCML_A64( "roundpd $0xff,%xmm1,%xmm0", 0x66, 0x0f, 0x3a, 0x09, 0xc1, 0xff );
    FCML_A64( "vroundpd $0xff,%xmm0,%xmm3", 0xc4, 0xe3, 0x79, 0x09, 0xd8, 0xff );
    FCML_A64( "vroundpd $0xff,%xmm0,%xmm3", 0xc4, 0xe3, 0x79, 0x09, 0xd8, 0xff );
    FCML_A64( "vroundpd $0xff,(%rax),%ymm0", 0xc4, 0xe3, 0x7d, 0x09, 0x00, 0xff );
}

void fcml_tf_instruction_ROUNDPS(void) {

    FCML_I64( "roundps xmm0,xmmword ptr [rax],0ffh", 0x66, 0x0F, 0x3A, 0x08, 0x00, 0xFF );
    FCML_I32( "roundps xmm0,xmm1,0ffh", 0x66, 0x0F, 0x3A, 0x08, 0xC1, 0xFF );

    FCML_I64( "vroundps xmm3,xmm0,0ffh", 0xC4, 0xE3, 0x79, 0x08, 0xD8, 0xFF );
    FCML_I32( "vroundps xmm3,xmm0,0ffh", 0xC4, 0xE3, 0x79, 0x08, 0xD8, 0xFF );
    FCML_I32( "vroundps ymm0,ymmword ptr [eax],0ffh", 0xC4, 0xE3, 0x7D, 0x08, 0x00, 0xFF );

    FCML_A64( "roundps $0xff,(%rax),%xmm0", 0x66, 0x0f, 0x3a, 0x08, 0x00, 0xff );
    FCML_A64( "roundps $0xff,%xmm1,%xmm0", 0x66, 0x0f, 0x3a, 0x08, 0xc1, 0xff );
    FCML_A64( "vroundps $0xff,%xmm0,%xmm3", 0xc4, 0xe3, 0x79, 0x08, 0xd8, 0xff );
    FCML_A64( "vroundps $0xff,%xmm0,%xmm3", 0xc4, 0xe3, 0x79, 0x08, 0xd8, 0xff );
    FCML_A64( "vroundps $0xff,(%rax),%ymm0", 0xc4, 0xe3, 0x7d, 0x08, 0x00, 0xff );
}

void fcml_tf_instruction_ROUNDSD(void) {

    FCML_I64( "roundsd xmm0,mmword ptr [rax],0ffh", 0x66, 0x0F, 0x3A, 0x0B, 0x00, 0xFF );
    FCML_I32( "roundsd xmm0,xmm1,0ffh", 0x66, 0x0F, 0x3A, 0x0B, 0xC1, 0xFF );

    FCML_I64( "vroundsd xmm3,xmm0,xmm0,0ffh", 0xC4, 0xE3, 0x79, 0x0B, 0xD8, 0xFF );
    FCML_I32( "vroundsd xmm3,xmm3,xmm0,0ffh", 0xC4, 0xE3, 0x61, 0x0B, 0xD8, 0xFF );

    FCML_A64( "roundsd $0xff,(%rax),%xmm0", 0x66, 0x0f, 0x3a, 0x0b, 0x00, 0xff );
    FCML_A64( "roundsd $0xff,%xmm1,%xmm0", 0x66, 0x0f, 0x3a, 0x0b, 0xc1, 0xff );
    FCML_A64( "vroundsd $0xff,%xmm0,%xmm0,%xmm3", 0xc4, 0xe3, 0x79, 0x0b, 0xd8, 0xff );
    FCML_A64( "vroundsd $0xff,%xmm0,%xmm3,%xmm3", 0xc4, 0xe3, 0x61, 0x0b, 0xd8, 0xff );
}

void fcml_tf_instruction_ROUNDSS(void) {

    FCML_I64( "roundss xmm0,dword ptr [rax],0ffh", 0x66, 0x0F, 0x3A, 0x0A, 0x00, 0xFF );
    FCML_I32( "roundss xmm0,xmm1,0ffh", 0x66, 0x0F, 0x3A, 0x0A, 0xC1, 0xFF );

    FCML_I64( "vroundss xmm3,xmm0,xmm0,0ffh", 0xC4, 0xE3, 0x79, 0x0A, 0xD8, 0xFF );
    FCML_I32( "vroundss xmm3,xmm6,xmm0,0ffh", 0xC4, 0xE3, 0x49, 0x0A, 0xD8, 0xFF );

    FCML_A64( "roundss $0xff,(%rax),%xmm0", 0x66, 0x0f, 0x3a, 0x0a, 0x00, 0xff );
    FCML_A64( "roundss $0xff,%xmm1,%xmm0", 0x66, 0x0f, 0x3a, 0x0a, 0xc1, 0xff );
    FCML_A64( "vroundss $0xff,%xmm0,%xmm0,%xmm3", 0xc4, 0xe3, 0x79, 0x0a, 0xd8, 0xff );
    FCML_A64( "vroundss $0xff,%xmm0,%xmm6,%xmm3", 0xc4, 0xe3, 0x49, 0x0a, 0xd8, 0xff );
}

void fcml_tf_instruction_RSM(void) {

    FCML_I32( "rsm", 0x0F, 0xAA );
    FCML_I64_FAILED( "rsm", 0x0F, 0xAA );

    FCML_A32( "rsm", 0x0f, 0xaa );
}

void fcml_tf_instruction_RSQRTPS(void) {

    FCML_I64( "rsqrtps xmm0,xmmword ptr [rax]", 0x0F, 0x52, 0x00 );
    FCML_I32( "rsqrtps xmm0,xmm1", 0x0F, 0x52, 0xC1 );

    FCML_I3264( "vrsqrtps xmm3,xmm0", 0xc5, 0xf8, 0x52, 0xd8 );
    FCML_I32( "vrsqrtps ymm0,ymmword ptr [eax]", 0xc5, 0xfc, 0x52, 0x00 );

    FCML_A64( "rsqrtps (%rax),%xmm0", 0x0f, 0x52, 0x00 );
    FCML_A64( "rsqrtps %xmm1,%xmm0", 0x0f, 0x52, 0xc1 );
    FCML_A64( "vrsqrtps %xmm0,%xmm3", 0xc5, 0xf8, 0x52, 0xd8 );
    FCML_A64( "vrsqrtps (%rax),%ymm0", 0xc5, 0xfc, 0x52, 0x00 );
}

void fcml_tf_instruction_RSQRTSS(void) {

    FCML_I64( "rsqrtss xmm0,dword ptr [rax]", 0xF3, 0x0F, 0x52, 0x00 );
    FCML_I32( "rsqrtss xmm0,xmm1", 0xF3, 0x0F, 0x52, 0xC1 );

    FCML_I64( "vrsqrtss xmm0,xmm6,dword ptr [rax]", 0xc5, 0xca, 0x52, 0x00 );
    FCML_I32( "vrsqrtss xmm3,xmm6,xmm0", 0xc5, 0xca, 0x52, 0xd8 );

    FCML_A64( "rsqrtss (%rax),%xmm0", 0xf3, 0x0f, 0x52, 0x00 );
    FCML_A64( "rsqrtss %xmm1,%xmm0", 0xf3, 0x0f, 0x52, 0xc1 );
    FCML_A64( "vrsqrtss (%rax),%xmm6,%xmm0", 0xc5, 0xca, 0x52, 0x00 );
    FCML_A64( "vrsqrtss %xmm0,%xmm6,%xmm3", 0xc5, 0xca, 0x52, 0xd8 );
}

void fcml_tf_instruction_RORX(void) {

    FCML_I32_D( "rorx eax,dword ptr [eax],01h", 0xC4, 0xE3, 0x43, 0xF0, 0x00, 0x01 );
    FCML_I32( "rorx eax,dword ptr [eax],01h", 0xc4, 0xe3, 0x7b, 0xf0, 0x00, 0x01 );
    FCML_I32_D( "rorx eax,eax,01h", 0xC4, 0xE3, 0x43, 0xF0, 0xC0, 0x01 );
    FCML_I32( "rorx eax,eax,01h", 0xc4, 0xe3, 0x7b, 0xf0, 0xc0, 0x01 );

    FCML_I64_D( "rorx rax,qword ptr [rax],01h", 0xC4, 0xE3, 0xC3, 0xF0, 0x00, 0x01 );
    FCML_I64( "rorx rax,qword ptr [rax],01h", 0xc4, 0xe3, 0xfb, 0xf0, 0x00, 0x01 );
    FCML_I64_D( "rorx rax,rax,01h", 0xC4, 0xE3, 0xC3, 0xF0, 0xC0, 0x01 );
    FCML_I64( "rorx rax,rax,01h", 0xc4, 0xe3, 0xfb, 0xf0, 0xc0, 0x01 );

    FCML_A64( "rorx $0x01,(%rax),%eax", 0xc4, 0xe3, 0x7b, 0xf0, 0x00, 0x01 );
    FCML_A64( "rorx $0x01,%eax,%eax", 0xc4, 0xe3, 0x7b, 0xf0, 0xc0, 0x01 );
    FCML_A64( "rorx $0x01,(%rax),%rax", 0xc4, 0xe3, 0xfb, 0xf0, 0x00, 0x01 );
    FCML_A64( "rorx $0x01,%rax,%rax", 0xc4, 0xe3, 0xfb, 0xf0, 0xc0, 0x01 );
}

void fcml_tf_instruction_RDSEED(void) {

    FCML_I32( "rdseed ax", 0x66, 0x0F, 0xC7, 0xF8 );
    FCML_I64( "rdseed ax", 0x66, 0x0F, 0xC7, 0xF8 );

    FCML_I32( "rdseed eax", 0x0F, 0xC7, 0xF8 );
    FCML_I64( "rdseed eax", 0x0F, 0xC7, 0xF8 );

    FCML_I64( "rdseed rax", 0x48, 0x0F, 0xC7, 0xF8 );

    FCML_A64( "rdseed %ax", 0x66, 0x0f, 0xc7, 0xf8 );
    FCML_A64( "rdseed %ax", 0x66, 0x0f, 0xc7, 0xf8 );
    FCML_A64( "rdseed %eax", 0x0f, 0xc7, 0xf8 );
    FCML_A64( "rdseed %eax", 0x0f, 0xc7, 0xf8 );
    FCML_A64( "rdseed %rax", 0x48, 0x0f, 0xc7, 0xf8 );
}

fcml_stf_test_case fctl_ti_instructions_r[] = {
	{ "fcml_tf_instruction_RCL", fcml_tf_instruction_RCL },
	{ "fcml_tf_instruction_RCR", fcml_tf_instruction_RCR },
	{ "fcml_tf_instruction_ROL", fcml_tf_instruction_ROL },
	{ "fcml_tf_instruction_ROR", fcml_tf_instruction_ROR },
	{ "fcml_tf_instruction_RCPPS", fcml_tf_instruction_RCPPS },
	{ "fcml_tf_instruction_RCPSS", fcml_tf_instruction_RCPSS },
	{ "fcml_tf_instruction_RDFSBASE", fcml_tf_instruction_RDFSBASE },
	{ "fcml_tf_instruction_RDRAND", fcml_tf_instruction_RDRAND },
	{ "fcml_tf_instruction_RDTSCP", fcml_tf_instruction_RDTSCP },
	{ "fcml_tf_instruction_RDTSC", fcml_tf_instruction_RDTSC },
	{ "fcml_tf_instruction_RDPMC", fcml_tf_instruction_RDPMC },
	{ "fcml_tf_instruction_RDMSR", fcml_tf_instruction_RDMSR },
	{ "fcml_tf_instruction_RET", fcml_tf_instruction_RET },
	{ "fcml_tf_instruction_ROUNDPD", fcml_tf_instruction_ROUNDPD },
	{ "fcml_tf_instruction_ROUNDPS", fcml_tf_instruction_ROUNDPS },
	{ "fcml_tf_instruction_ROUNDSD", fcml_tf_instruction_ROUNDSD },
	{ "fcml_tf_instruction_ROUNDSS", fcml_tf_instruction_ROUNDSS },
	{ "fcml_tf_instruction_RSM", fcml_tf_instruction_RSM },
	{ "fcml_tf_instruction_RSQRTPS", fcml_tf_instruction_RSQRTPS },
	{ "fcml_tf_instruction_RSQRTSS", fcml_tf_instruction_RSQRTSS },
	{ "fcml_tf_instruction_RORX", fcml_tf_instruction_RORX },
	{ "fcml_tf_instruction_RDSEED", fcml_tf_instruction_RDSEED },
	FCML_STF_NULL_TEST
};

fcml_stf_test_suite fctl_si_instructions_r = {
	"suite-fctl_ti_instructions_r", fcml_tf_instructions_r_suite_init, fcml_tf_instructions_r_suite_cleanup, fctl_ti_instructions_r
};



