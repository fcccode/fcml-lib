/*
 * fcml_asm_dialect_intel.h
 *
 *  Created on: 1 wrz 2013
 *      Author: tAs
 */

#ifndef FCML_ASM_DIALECT_GAS_H_
#define FCML_ASM_DIALECT_GAS_H_

#include "fcml_lib_export.h"

#include "fcml_errors.h"
#include "fcml_dialect.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Disables "SystemV/386 SVR3.2" compatibility for the non-commutative arithmetic floating point operations with two register operands.*/
#define FCML_GAS_DIALECT_CF_SYSV_SVR32_INCOMPATIBLE       0x00000001

/* Default combination of configuration flags.*/
#define FCML_GAS_DIALECT_CF_DEFAULT                       0

LIB_EXPORT fcml_ceh_error LIB_CALL fcml_fn_gas_dialect_init( fcml_uint32_t config_flags, fcml_st_dialect **dialect );
LIB_EXPORT void LIB_CALL fcml_fn_gas_dialect_free(fcml_st_dialect *dialect);

#ifdef __cplusplus
}
#endif

#endif /* FCML_ASM_DIALECT_GAS_H_ */
