/*
 * File: Project_simulink.h
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

#ifndef RTW_HEADER_Project_simulink_h_
#define RTW_HEADER_Project_simulink_h_
#include <stddef.h>
#include <string.h>
#ifndef Project_simulink_COMMON_INCLUDES_
# define Project_simulink_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* Project_simulink_COMMON_INCLUDES_ */

#include "Project_simulink_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_e_T obj; /* '<Root>/PWM' */
  codertarget_arduinobase_int_e_T obj_h;/* '<Root>/PWM1' */
  codertarget_arduinobase_block_T obj_c;/* '<S3>/Digital Input' */
  codertarget_arduinobase_block_T obj_l;/* '<S2>/Digital Input' */
  codertarget_arduinobase_block_T obj_lv;/* '<S1>/Digital Input' */
  codertarget_arduinobase_blo_e_T obj_p;/* '<S7>/Digital Output' */
  codertarget_arduinobase_blo_e_T obj_la;/* '<S6>/Digital Output' */
  codertarget_arduinobase_blo_e_T obj_ht;/* '<S5>/Digital Output' */
  codertarget_arduinobase_blo_e_T obj_n;/* '<S4>/Digital Output' */
} DW_Project_simulink_T;

/* Parameters (default storage) */
struct P_Project_simulink_T_ {
  real_T DigitalInput_SampleTime;      /* Expression: 1
                                        * Referenced by: '<S1>/Digital Input'
                                        */
  real_T DigitalInput_SampleTime_h;    /* Expression: 1
                                        * Referenced by: '<S2>/Digital Input'
                                        */
  real_T DigitalInput_SampleTime_d;    /* Expression: 1
                                        * Referenced by: '<S3>/Digital Input'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 5
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Project_simulink_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_Project_simulink_T Project_simulink_P;

/* Block states (default storage) */
extern DW_Project_simulink_T Project_simulink_DW;

/* Model entry point functions */
extern void Project_simulink_initialize(void);
extern void Project_simulink_step(void);
extern void Project_simulink_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Project_simulink_T *const Project_simulink_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Project_simulink'
 * '<S1>'   : 'Project_simulink/Digital Input'
 * '<S2>'   : 'Project_simulink/Digital Input1'
 * '<S3>'   : 'Project_simulink/Digital Input2'
 * '<S4>'   : 'Project_simulink/Digital Output'
 * '<S5>'   : 'Project_simulink/Digital Output1'
 * '<S6>'   : 'Project_simulink/Digital Output2'
 * '<S7>'   : 'Project_simulink/Digital Output3'
 * '<S8>'   : 'Project_simulink/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_Project_simulink_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
