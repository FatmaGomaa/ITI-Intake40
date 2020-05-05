/*
 * File: Project_simulink_types.h
 *
 * Code generated for Simulink model 'Project_simulink'.
 *
 * Model version                  : 1.165
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Feb 11 13:00:31 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Project_simulink_types_h_
#define RTW_HEADER_Project_simulink_types_h_
#include "rtwtypes.h"

/* Custom Type definition for MATLABSystem: '<Root>/PWM' */
#include "MW_SVD.h"
#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
} codertarget_arduinobase_block_T;

#endif                                 /*typedef_codertarget_arduinobase_block_T*/

#ifndef typedef_codertarget_arduinobase_blo_e_T
#define typedef_codertarget_arduinobase_blo_e_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
} codertarget_arduinobase_blo_e_T;

#endif                                 /*typedef_codertarget_arduinobase_blo_e_T*/

#ifndef typedef_cell_Project_simulink_T
#define typedef_cell_Project_simulink_T

typedef struct {
  char_T f1;
  char_T f2;
  char_T f3;
  char_T f4;
  char_T f5;
  char_T f6;
  char_T f7;
  char_T f8;
  char_T f9[2];
  char_T f10[2];
  char_T f11[2];
  char_T f12[2];
} cell_Project_simulink_T;

#endif                                 /*typedef_cell_Project_simulink_T*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct {
  cell_Project_simulink_T AvailablePwmPinNames;
} codertarget_arduinobase_inter_T;

#endif                                 /*typedef_codertarget_arduinobase_inter_T*/

#ifndef typedef_codertarget_arduinobase_int_e_T
#define typedef_codertarget_arduinobase_int_e_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  codertarget_arduinobase_inter_T Hw;
  MW_Handle_Type MW_PWM_HANDLE;
} codertarget_arduinobase_int_e_T;

#endif                                 /*typedef_codertarget_arduinobase_int_e_T*/

/* Parameters (default storage) */
typedef struct P_Project_simulink_T_ P_Project_simulink_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Project_simulink_T RT_MODEL_Project_simulink_T;

#endif                                 /* RTW_HEADER_Project_simulink_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
