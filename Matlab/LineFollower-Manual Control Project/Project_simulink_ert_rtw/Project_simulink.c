/*
 * File: Project_simulink.c
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

#include "Project_simulink.h"
#include "Project_simulink_private.h"

/* Block states (default storage) */
DW_Project_simulink_T Project_simulink_DW;

/* Real-time model */
RT_MODEL_Project_simulink_T Project_simulink_M_;
RT_MODEL_Project_simulink_T *const Project_simulink_M = &Project_simulink_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabCo_e0(codertarget_arduinobase_block_T *obj);
static void matlabCodegenHandle_matla_e0pv4(codertarget_arduinobase_blo_e_T *obj);
static void Project_simu_SystemCore_release(const
  codertarget_arduinobase_int_e_T *obj);
static void Project_simul_SystemCore_delete(const
  codertarget_arduinobase_int_e_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_e_T *obj);
static codertarget_arduinobase_int_e_T *arduino_PWMOutput_arduino_PWMOu
  (codertarget_arduinobase_int_e_T *obj);
static void matlabCodegenHandle_matlabCo_e0(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matla_e0pv4(codertarget_arduinobase_blo_e_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void Project_simu_SystemCore_release(const
  codertarget_arduinobase_int_e_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    MW_PWM_SetDutyCycle(obj->MW_PWM_HANDLE, 0);
  }
}

static void Project_simul_SystemCore_delete(const
  codertarget_arduinobase_int_e_T *obj)
{
  Project_simu_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_e_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Project_simul_SystemCore_delete(obj);
  }
}

static codertarget_arduinobase_int_e_T *arduino_PWMOutput_arduino_PWMOu
  (codertarget_arduinobase_int_e_T *obj)
{
  codertarget_arduinobase_int_e_T *b_obj;
  obj->isInitialized = 0L;
  b_obj = obj;
  obj->Hw.AvailablePwmPinNames.f1 = '2';
  obj->Hw.AvailablePwmPinNames.f2 = '3';
  obj->Hw.AvailablePwmPinNames.f3 = '4';
  obj->Hw.AvailablePwmPinNames.f4 = '5';
  obj->Hw.AvailablePwmPinNames.f5 = '6';
  obj->Hw.AvailablePwmPinNames.f6 = '7';
  obj->Hw.AvailablePwmPinNames.f7 = '8';
  obj->Hw.AvailablePwmPinNames.f8 = '9';
  obj->Hw.AvailablePwmPinNames.f9[0] = '1';
  obj->Hw.AvailablePwmPinNames.f9[1] = '0';
  obj->Hw.AvailablePwmPinNames.f10[0] = '1';
  obj->Hw.AvailablePwmPinNames.f10[1] = '1';
  obj->Hw.AvailablePwmPinNames.f11[0] = '1';
  obj->Hw.AvailablePwmPinNames.f11[1] = '2';
  obj->Hw.AvailablePwmPinNames.f12[0] = '1';
  obj->Hw.AvailablePwmPinNames.f12[1] = '3';
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/* Model step function */
void Project_simulink_step(void)
{
  boolean_T rtb_DigitalInput_l_0;
  boolean_T rtb_DigitalInput_d_0;
  boolean_T rtb_DigitalInput_0;
  int16_T rtb_en2;
  int16_T rtb_en1;
  int16_T rtb_op4;
  int16_T rtb_op3;
  int16_T rtb_op2;
  int16_T rtb_op1;

  /* MATLABSystem: '<S1>/Digital Input' */
  if (Project_simulink_DW.obj_lv.SampleTime !=
      Project_simulink_P.DigitalInput_SampleTime) {
    Project_simulink_DW.obj_lv.SampleTime =
      Project_simulink_P.DigitalInput_SampleTime;
  }

  rtb_DigitalInput_l_0 = readDigitalPin(3);

  /* MATLABSystem: '<S2>/Digital Input' */
  if (Project_simulink_DW.obj_l.SampleTime !=
      Project_simulink_P.DigitalInput_SampleTime_h) {
    Project_simulink_DW.obj_l.SampleTime =
      Project_simulink_P.DigitalInput_SampleTime_h;
  }

  rtb_DigitalInput_d_0 = readDigitalPin(4);

  /* MATLABSystem: '<S3>/Digital Input' */
  if (Project_simulink_DW.obj_c.SampleTime !=
      Project_simulink_P.DigitalInput_SampleTime_d) {
    Project_simulink_DW.obj_c.SampleTime =
      Project_simulink_P.DigitalInput_SampleTime_d;
  }

  rtb_DigitalInput_0 = readDigitalPin(5);

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  MATLABSystem: '<S1>/Digital Input'
   *  MATLABSystem: '<S2>/Digital Input'
   *  MATLABSystem: '<S3>/Digital Input'
   */
  if ((Project_simulink_P.Constant1_Value == 1.0) &&
      (Project_simulink_P.Constant_Value == 1.0)) {
    rtb_op1 = 0;
    rtb_op2 = 1;
    rtb_op3 = 1;
    rtb_op4 = 0;
    rtb_en1 = 100;
    rtb_en2 = 100;
  } else if ((Project_simulink_P.Constant1_Value == 1.0) &&
             (Project_simulink_P.Constant_Value == 2.0)) {
    rtb_op1 = 1;
    rtb_op2 = 0;
    rtb_op3 = 0;
    rtb_op4 = 1;
    rtb_en1 = 100;
    rtb_en2 = 100;
  } else if ((Project_simulink_P.Constant1_Value == 1.0) &&
             (Project_simulink_P.Constant_Value == 3.0)) {
    rtb_op1 = 0;
    rtb_op2 = 1;
    rtb_op3 = 1;
    rtb_op4 = 0;
    rtb_en1 = 60;
    rtb_en2 = 100;
  } else if ((Project_simulink_P.Constant1_Value == 1.0) &&
             (Project_simulink_P.Constant_Value == 4.0)) {
    rtb_op1 = 0;
    rtb_op2 = 1;
    rtb_op3 = 1;
    rtb_op4 = 0;
    rtb_en1 = 100;
    rtb_en2 = 60;
  } else {
    rtb_op1 = 0;
    rtb_op2 = 0;
    rtb_op3 = 0;
    rtb_op4 = 0;
    rtb_en1 = 100;
    rtb_en2 = 100;
  }

  if (Project_simulink_P.Constant1_Value == 2.0) {
    if ((!rtb_DigitalInput_l_0) && rtb_DigitalInput_d_0 && rtb_DigitalInput_0) {
      rtb_op1 = 0;
      rtb_op2 = 1;
      rtb_op3 = 1;
      rtb_op4 = 0;
      rtb_en1 = 100;
      rtb_en2 = 60;
    } else if ((!rtb_DigitalInput_l_0) && (!rtb_DigitalInput_d_0) &&
               (!rtb_DigitalInput_0)) {
      rtb_op1 = 0;
      rtb_op2 = 1;
      rtb_op3 = 1;
      rtb_op4 = 0;
      rtb_en1 = 100;
      rtb_en2 = 100;
    } else if (rtb_DigitalInput_l_0 && rtb_DigitalInput_d_0 &&
               (!rtb_DigitalInput_0)) {
      rtb_op1 = 0;
      rtb_op2 = 1;
      rtb_op3 = 1;
      rtb_op4 = 0;
      rtb_en1 = 60;
      rtb_en2 = 100;
    } else {
      rtb_op1 = 0;
      rtb_op2 = 0;
      rtb_op3 = 0;
      rtb_op4 = 0;
      rtb_en1 = 60;
      rtb_en2 = 100;
    }
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* MATLABSystem: '<S4>/Digital Output' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   */
  writeDigitalPin(12, (uint8_T)rtb_op1);

  /* MATLABSystem: '<S5>/Digital Output' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   */
  writeDigitalPin(13, (uint8_T)rtb_op2);

  /* MATLABSystem: '<S6>/Digital Output' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   */
  writeDigitalPin(8, (uint8_T)rtb_op3);

  /* MATLABSystem: '<S7>/Digital Output' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   */
  writeDigitalPin(9, (uint8_T)rtb_op4);

  /* MATLABSystem: '<Root>/PWM' */
  MW_PWM_SetDutyCycle(Project_simulink_DW.obj.MW_PWM_HANDLE, (real_T)rtb_en1);

  /* MATLABSystem: '<Root>/PWM1' */
  MW_PWM_SetDutyCycle(Project_simulink_DW.obj_h.MW_PWM_HANDLE, (real_T)rtb_en2);
}

/* Model initialize function */
void Project_simulink_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(Project_simulink_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Project_simulink_DW, 0,
                sizeof(DW_Project_simulink_T));

  {
    codertarget_arduinobase_int_e_T *obj;

    /* Start for MATLABSystem: '<S1>/Digital Input' */
    Project_simulink_DW.obj_lv.matlabCodegenIsDeleted = true;
    Project_simulink_DW.obj_lv.isInitialized = 0L;
    Project_simulink_DW.obj_lv.matlabCodegenIsDeleted = false;
    Project_simulink_DW.obj_lv.SampleTime =
      Project_simulink_P.DigitalInput_SampleTime;
    Project_simulink_DW.obj_lv.isSetupComplete = false;
    Project_simulink_DW.obj_lv.isInitialized = 1L;
    digitalIOSetup(3, false);
    Project_simulink_DW.obj_lv.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Input' */
    Project_simulink_DW.obj_l.matlabCodegenIsDeleted = true;
    Project_simulink_DW.obj_l.isInitialized = 0L;
    Project_simulink_DW.obj_l.matlabCodegenIsDeleted = false;
    Project_simulink_DW.obj_l.SampleTime =
      Project_simulink_P.DigitalInput_SampleTime_h;
    Project_simulink_DW.obj_l.isSetupComplete = false;
    Project_simulink_DW.obj_l.isInitialized = 1L;
    digitalIOSetup(4, false);
    Project_simulink_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Input' */
    Project_simulink_DW.obj_c.matlabCodegenIsDeleted = true;
    Project_simulink_DW.obj_c.isInitialized = 0L;
    Project_simulink_DW.obj_c.matlabCodegenIsDeleted = false;
    Project_simulink_DW.obj_c.SampleTime =
      Project_simulink_P.DigitalInput_SampleTime_d;
    Project_simulink_DW.obj_c.isSetupComplete = false;
    Project_simulink_DW.obj_c.isInitialized = 1L;
    digitalIOSetup(5, false);
    Project_simulink_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Output' */
    Project_simulink_DW.obj_n.matlabCodegenIsDeleted = true;
    Project_simulink_DW.obj_n.isInitialized = 0L;
    Project_simulink_DW.obj_n.matlabCodegenIsDeleted = false;
    Project_simulink_DW.obj_n.isSetupComplete = false;
    Project_simulink_DW.obj_n.isInitialized = 1L;
    digitalIOSetup(12, true);
    Project_simulink_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Output' */
    Project_simulink_DW.obj_ht.matlabCodegenIsDeleted = true;
    Project_simulink_DW.obj_ht.isInitialized = 0L;
    Project_simulink_DW.obj_ht.matlabCodegenIsDeleted = false;
    Project_simulink_DW.obj_ht.isSetupComplete = false;
    Project_simulink_DW.obj_ht.isInitialized = 1L;
    digitalIOSetup(13, true);
    Project_simulink_DW.obj_ht.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Output' */
    Project_simulink_DW.obj_la.matlabCodegenIsDeleted = true;
    Project_simulink_DW.obj_la.isInitialized = 0L;
    Project_simulink_DW.obj_la.matlabCodegenIsDeleted = false;
    Project_simulink_DW.obj_la.isSetupComplete = false;
    Project_simulink_DW.obj_la.isInitialized = 1L;
    digitalIOSetup(8, true);
    Project_simulink_DW.obj_la.isSetupComplete = true;

    /* Start for MATLABSystem: '<S7>/Digital Output' */
    Project_simulink_DW.obj_p.matlabCodegenIsDeleted = true;
    Project_simulink_DW.obj_p.isInitialized = 0L;
    Project_simulink_DW.obj_p.matlabCodegenIsDeleted = false;
    Project_simulink_DW.obj_p.isSetupComplete = false;
    Project_simulink_DW.obj_p.isInitialized = 1L;
    digitalIOSetup(9, true);
    Project_simulink_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    Project_simulink_DW.obj.matlabCodegenIsDeleted = true;
    arduino_PWMOutput_arduino_PWMOu(&Project_simulink_DW.obj);
    obj = &Project_simulink_DW.obj;
    Project_simulink_DW.obj.isSetupComplete = false;
    Project_simulink_DW.obj.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0, 0.0);
    MW_PWM_Start(Project_simulink_DW.obj.MW_PWM_HANDLE);
    Project_simulink_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM1' */
    Project_simulink_DW.obj_h.matlabCodegenIsDeleted = true;
    arduino_PWMOutput_arduino_PWMOu(&Project_simulink_DW.obj_h);
    obj = &Project_simulink_DW.obj_h;
    Project_simulink_DW.obj_h.isSetupComplete = false;
    Project_simulink_DW.obj_h.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
    MW_PWM_Start(Project_simulink_DW.obj_h.MW_PWM_HANDLE);
    Project_simulink_DW.obj_h.isSetupComplete = true;
  }
}

/* Model terminate function */
void Project_simulink_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Digital Input' */
  matlabCodegenHandle_matlabCo_e0(&Project_simulink_DW.obj_lv);

  /* Terminate for MATLABSystem: '<S2>/Digital Input' */
  matlabCodegenHandle_matlabCo_e0(&Project_simulink_DW.obj_l);

  /* Terminate for MATLABSystem: '<S3>/Digital Input' */
  matlabCodegenHandle_matlabCo_e0(&Project_simulink_DW.obj_c);

  /* Terminate for MATLABSystem: '<S4>/Digital Output' */
  matlabCodegenHandle_matla_e0pv4(&Project_simulink_DW.obj_n);

  /* Terminate for MATLABSystem: '<S5>/Digital Output' */
  matlabCodegenHandle_matla_e0pv4(&Project_simulink_DW.obj_ht);

  /* Terminate for MATLABSystem: '<S6>/Digital Output' */
  matlabCodegenHandle_matla_e0pv4(&Project_simulink_DW.obj_la);

  /* Terminate for MATLABSystem: '<S7>/Digital Output' */
  matlabCodegenHandle_matla_e0pv4(&Project_simulink_DW.obj_p);

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  matlabCodegenHandle_matlabCodeg(&Project_simulink_DW.obj);

  /* Terminate for MATLABSystem: '<Root>/PWM1' */
  matlabCodegenHandle_matlabCodeg(&Project_simulink_DW.obj_h);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
