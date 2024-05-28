/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: final_project.c
 *
 * Code generated for Simulink model 'final_project'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Nov 20 20:26:23 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "final_project.h"
#include "final_project_private.h"

/* Block signals (default storage) */
B_final_project_T final_project_B;

/* Block states (default storage) */
DW_final_project_T final_project_DW;

/* Real-time model */
static RT_MODEL_final_project_T final_project_M_;
RT_MODEL_final_project_T *const final_project_M = &final_project_M_;

/* Model step function */
void final_project_step(void)
{
  real_T u;
  real_T v;
  uint32_T duration;
  int16_T i;
  char_T tmp[31];
  uint8_T tmp_0;

  /* SignalConversion: '<S1>/Out' incorporates:
   *  Constant: '<S1>/Vector'
   *  MultiPortSwitch: '<S1>/Output'
   *  UnitDelay: '<S2>/Output'
   */
  final_project_B.Out =
    final_project_P.DesiredShaftAngle_OutValues[final_project_DW.Output_DSTATE];

  /* ToString: '<Root>/To String1' incorporates:
   *  SignalConversion: '<S1>/Out'
   */
  snprintf(&final_project_B.rtb_ToString1_m[0], 256U, "%hhu",
           final_project_B.Out);

  /* MATLABSystem: '<Root>/Ultrasonic Sensor' */
  if (final_project_DW.obj.TunablePropsChanged) {
    final_project_DW.obj.TunablePropsChanged = false;
  }

  MW_UltrasonicRead(&duration, 1, 4, 5, 10);

  /* Gain: '<Root>/Gain' incorporates:
   *  MATLABSystem: '<Root>/Ultrasonic Sensor'
   */
  u = (real_T)duration * 0.000343 / 2.0 * final_project_P.Gain_Gain;
  v = fabs(u);
  if (v < 4.503599627370496E+15) {
    if (v >= 0.5) {
      u = floor(u + 0.5);
    } else {
      u *= 0.0;
    }
  }

  if (rtIsNaN(u) || rtIsInf(u)) {
    u = 0.0;
  } else {
    u = fmod(u, 256.0);
  }

  /* Gain: '<Root>/Gain' */
  final_project_B.Gain = (uint8_T)(u < 0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)
    -u : (int16_T)(uint8_T)u);

  /* ToString: '<Root>/To String' incorporates:
   *  Gain: '<Root>/Gain'
   */
  snprintf(&final_project_B.rtb_ToString_c[0], 256U, "%hhu",
           final_project_B.Gain);

  /* Switch: '<Root>/Switch' incorporates:
   *  StringConstant: '<Root>/String Constant'
   *  StringConstant: '<Root>/String Constant1'
   */
  if (final_project_B.Gain > final_project_P.Switch_Threshold) {
    strncpy(&final_project_B.Switch[0], &final_project_P.StringConstant1_String
            [0], 255U);
    final_project_B.Switch[255] = '\x00';
  } else {
    strncpy(&final_project_B.Switch[0], &final_project_P.StringConstant_String[0],
            255U);
    final_project_B.Switch[255] = '\x00';
  }

  /* End of Switch: '<Root>/Switch' */

  /* StringConcatenate: '<Root>/String Concatenate' incorporates:
   *  StringConstant: '<Root>/String Constant2'
   *  StringConstant: '<Root>/String Constant3'
   *  StringConstant: '<Root>/String Constant4'
   *  ToString: '<Root>/To String'
   *  ToString: '<Root>/To String1'
   */
  final_project_B.cv[0] = '\x00';
  strncat(&final_project_B.cv[0], &final_project_B.rtb_ToString1_m[0], 255U);
  i = (int16_T)strlen(&final_project_B.cv[0]);
  strncat(&final_project_B.cv[i], &final_project_P.StringConstant2_String[0],
          255U - i);
  i += (int16_T)strlen(&final_project_B.cv[i]);
  strncat(&final_project_B.cv[i], &final_project_B.rtb_ToString_c[0], 255U - i);
  i += (int16_T)strlen(&final_project_B.cv[i]);
  strncat(&final_project_B.cv[i], &final_project_P.StringConstant3_String[0],
          255U - i);
  i += (int16_T)strlen(&final_project_B.cv[i]);
  strncat(&final_project_B.cv[i], &final_project_B.Switch[0], 255U - i);
  i += (int16_T)strlen(&final_project_B.cv[i]);
  strncat(&final_project_B.cv[i], &final_project_P.StringConstant4_String[0],
          255U - i);

  /* StringConcatenate: '<Root>/String Concatenate' */
  strncpy(&final_project_B.StringConcatenate[0], &final_project_B.cv[0], 255U);
  final_project_B.StringConcatenate[255] = '\x00';

  /* StringToASCII: '<Root>/String to ASCII' */
  strncpy(&tmp[0], &final_project_B.StringConcatenate[0], 31U);
  for (i = 0; i < 31; i++) {
    /* StringToASCII: '<Root>/String to ASCII' */
    final_project_B.StringtoASCII[i] = (uint8_T)tmp[i];
  }

  /* MATLABSystem: '<Root>/Standard Servo Write1' */
  if (final_project_B.Out > 180) {
    tmp_0 = 180U;
  } else {
    tmp_0 = final_project_B.Out;
  }

  MW_servoWrite(0, tmp_0);

  /* End of MATLABSystem: '<Root>/Standard Servo Write1' */
  /* Sum: '<S3>/FixPt Sum1' incorporates:
   *  Constant: '<S3>/FixPt Constant'
   *  UnitDelay: '<S2>/Output'
   */
  final_project_DW.Output_DSTATE += final_project_P.FixPtConstant_Value;

  /* Switch: '<S4>/FixPt Switch' */
  if (final_project_DW.Output_DSTATE > final_project_P.LimitedCounter_uplimit) {
    /* Sum: '<S3>/FixPt Sum1' incorporates:
     *  Constant: '<S4>/Constant'
     */
    final_project_DW.Output_DSTATE = final_project_P.Constant_Value;
  }

  /* End of Switch: '<S4>/FixPt Switch' */
  {                                    /* Sample time: [0.01s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  final_project_M->Timing.taskTime0 =
    ((time_T)(++final_project_M->Timing.clockTick0)) *
    final_project_M->Timing.stepSize0;
}

/* Model initialize function */
void final_project_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(final_project_M, 5.0);
  final_project_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  final_project_M->Sizes.checksums[0] = (1455116105U);
  final_project_M->Sizes.checksums[1] = (429549258U);
  final_project_M->Sizes.checksums[2] = (3555713700U);
  final_project_M->Sizes.checksums[3] = (1847759830U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    final_project_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(final_project_M->extModeInfo,
      &final_project_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(final_project_M->extModeInfo,
                        final_project_M->Sizes.checksums);
    rteiSetTPtr(final_project_M->extModeInfo, rtmGetTPtr(final_project_M));
  }

  /* InitializeConditions for Sum: '<S3>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S2>/Output'
   */
  final_project_DW.Output_DSTATE = final_project_P.Output_InitialCondition;

  /* Start for MATLABSystem: '<Root>/Ultrasonic Sensor' */
  final_project_DW.obj.isInitialized = 1L;
  MW_UltrasonicSetup(4, 5);
  final_project_DW.obj.TunablePropsChanged = false;

  /* Start for MATLABSystem: '<Root>/Standard Servo Write1' */
  MW_servoAttach(0, 9);
}

/* Model terminate function */
void final_project_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
