/*
 * Hoverboard Firmware - Decompiled & Annotated
 * MCU: STM32F103 (ARM Cortex-M3)
 * Decompiled with Ghidra
 */

/* STM32F103 Peripheral Base Addresses */
#define PERIPH_BASE       0x40000000
#define APB1PERIPH_BASE   PERIPH_BASE
#define APB2PERIPH_BASE   (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE    (PERIPH_BASE + 0x20000)

#define TIM1_BASE         0x40012C00  // Advanced timer (motor PWM)
#define TIM2_BASE         0x40000000
#define TIM3_BASE         0x40000400
#define TIM4_BASE         0x40000800
#define GPIOA_BASE        0x40010800
#define GPIOB_BASE        0x40010C00
#define GPIOC_BASE        0x40011000
#define USART1_BASE       0x40013800
#define USART2_BASE       0x40004400
#define ADC1_BASE         0x40012400
#define ADC2_BASE         0x40012800
#define RCC_BASE          0x40021000

/* Timer Register Offsets */
#define TIM_CR1    0x00  // Control register 1
#define TIM_CR2    0x04  // Control register 2
#define TIM_SMCR   0x08  // Slave mode control
#define TIM_DIER   0x0C  // DMA/Interrupt enable
#define TIM_SR     0x10  // Status register
#define TIM_EGR    0x14  // Event generation
#define TIM_CCMR1  0x18  // Capture/compare mode 1
#define TIM_CCMR2  0x1C  // Capture/compare mode 2
#define TIM_CCER   0x20  // Capture/compare enable
#define TIM_CNT    0x24  // Counter
#define TIM_PSC    0x28  // Prescaler
#define TIM_ARR    0x2C  // Auto-reload
#define TIM_CCR1   0x34  // Capture/compare 1
#define TIM_CCR2   0x38  // Capture/compare 2
#define TIM_CCR3   0x3C  // Capture/compare 3
#define TIM_BDTR   0x44  // Break and dead-time

/* GPIO Register Offsets */
#define GPIO_CRL   0x00  // Config low (pins 0-7)
#define GPIO_CRH   0x04  // Config high (pins 8-15)
#define GPIO_IDR   0x08  // Input data
#define GPIO_ODR   0x0C  // Output data
#define GPIO_BSRR  0x10  // Bit set/reset
#define GPIO_BRR   0x14  // Bit reset

/* ADC Register Offsets */
#define ADC_SR     0x00  // Status
#define ADC_CR1    0x04  // Control 1
#define ADC_CR2    0x08  // Control 2
#define ADC_SQR1   0x2C  // Sequence register 1
#define ADC_DR     0x4C  // Data register

typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
typedef int int32_t;
typedef short int16_t;
typedef char int8_t;

/* ========== DECOMPILED FUNCTIONS ========== */

/* ----------------------------------------
 * Reset_Handler @ 0x8000138
 * Entry point after reset
 * ---------------------------------------- */

void Reset_Handler(void)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = DAT_08000164;
  puVar3 = (undefined4 *)((int)&DAT_08000164 + DAT_08000164);
  iVar2 = DAT_08000164 + 0x8000163;
  if (puVar3 == (undefined4 *)((int)&DAT_08000164 + DAT_08000168)) {
    FUN_080001ec();
  }
  UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x8000170);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
    UNRECOVERED_JUMPTABLE = (code *)(iVar2 - (int)UNRECOVERED_JUMPTABLE);
  }
                    /* WARNING: Could not recover jumptable at 0x08000162. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)
            (*puVar3,*(undefined4 *)((int)&DAT_08000168 + iVar1),*(undefined4 *)(iVar1 + 0x800016c))
  ;
  return;
}



/* ----------------------------------------
 * FUN_080001e4 @ 0x80001e4
 * Startup / low-level init
 * ---------------------------------------- */

undefined8 FUN_080001e4(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,param_1);
}



/* ----------------------------------------
 * FUN_080001e8 @ 0x80001e8
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_080001e8(void)

{
  return;
}



/* ----------------------------------------
 * SystemInit @ 0x80001ec
 * Initialize clocks and peripherals
 * ---------------------------------------- */

void SystemInit(void)

{
  undefined4 uVar1;
  undefined4 extraout_r2;
  undefined8 uVar2;
  
  uVar1 = FUN_08000252();
  FUN_080001e4(uVar1,extraout_r2);
  FUN_08003fe4();
  uVar2 = FUN_0800029c();
  FUN_080001e8();
  FUN_080002b0((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  (*DAT_08000234)();
                    /* WARNING: Could not recover jumptable at 0x08000212. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_08000238)();
  return;
}



/* ----------------------------------------
 * FUN_080001fe @ 0x80001fe
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_080001fe(undefined4 param_1,undefined4 param_2)

{
  FUN_080001e8();
  FUN_080002b0(param_1,param_2);
  (*DAT_08000234)();
                    /* WARNING: Could not recover jumptable at 0x08000212. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_08000238)();
  return;
}



/* ----------------------------------------
 * FUN_08000228 @ 0x8000228
 * Startup / low-level init
 * ---------------------------------------- */

undefined8 FUN_08000228(void)

{
  return CONCAT44(DAT_08000240,DAT_0800023c);
}



/* ----------------------------------------
 * FUN_08000252 @ 0x8000252
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_08000252(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 unaff_lr;
  uint *puVar3;
  
  uVar1 = FUN_080002a8();
  *(undefined4 *)((uVar1 & 0xfffffff8) + 0x5c) = unaff_lr;
  puVar3 = (uint *)((uVar1 & 0xfffffff8) + 0x58);
  *puVar3 = uVar1;
  FUN_08000228();
  puVar2 = (undefined4 *)*puVar3;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  puVar2[5] = 0;
  puVar2[6] = 0;
  puVar2[7] = 0;
  puVar2[8] = 0;
  puVar2[9] = 0;
  puVar2[10] = 0;
  puVar2[0xb] = 0;
  puVar2[0xc] = 0;
  puVar2[0xd] = 0;
  puVar2[0xe] = 0;
  puVar2[0xf] = 0;
  return;
}



/* ----------------------------------------
 * FUN_0800029c @ 0x800029c
 * Startup / low-level init
 * ---------------------------------------- */

undefined4 FUN_0800029c(undefined4 param_1)

{
  FUN_080001fe(param_1);
  return DAT_080002ac;
}



/* ----------------------------------------
 * FUN_080002a8 @ 0x80002a8
 * Startup / low-level init
 * ---------------------------------------- */

undefined4 FUN_080002a8(void)

{
  return DAT_080002ac;
}



/* ----------------------------------------
 * halt_error @ 0x80002b0
 * Startup / low-level init
 * ---------------------------------------- */

void halt_error(void)

{
  software_bkpt(0xab);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ----------------------------------------
 * timer_set_enable @ 0x80002be
 * Startup / low-level init
 * ---------------------------------------- */

void timer_set_enable(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    uVar1 = *(uint *)(param_1 + 8) & 0xfffffffe;
  }
  else {
    uVar1 = *(uint *)(param_1 + 8) | 1;
  }
  *(uint *)(param_1 + 8) = uVar1;
  return;
}



/* ----------------------------------------
 * timer_set_output @ 0x80002d2
 * Startup / low-level init
 * ---------------------------------------- */

void timer_set_output(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    uVar1 = *(uint *)(param_1 + 8) & 0xfffffeff;
  }
  else {
    uVar1 = *(uint *)(param_1 + 8) | 0x100;
  }
  *(uint *)(param_1 + 8) = uVar1;
  return;
}



/* ----------------------------------------
 * rcc_periph_enable @ 0x80002e8
 * Startup / low-level init
 * ---------------------------------------- */

void rcc_periph_enable(int param_1)

{
  if (param_1 == DAT_08000320) {
    param_1 = param_1 >> 0x15;
  }
  else if (param_1 == DAT_08000324) {
    param_1 = param_1 >> 0x14;
  }
  else {
    if (param_1 != DAT_08000328) {
      return;
    }
    param_1 = 0x8000;
  }
  FUN_080020d4(param_1,1);
  FUN_080020d4(param_1,0);
  return;
}



/* ----------------------------------------
 * FUN_0800032c @ 0x800032c
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_0800032c(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    uVar1 = *(uint *)(param_1 + 8) & 0xffefffff;
  }
  else {
    uVar1 = *(uint *)(param_1 + 8) | 0x100000;
  }
  *(uint *)(param_1 + 8) = uVar1;
  return;
}



/* ----------------------------------------
 * timer_set_bdtr @ 0x8000340
 * Startup / low-level init
 * ---------------------------------------- */

void timer_set_bdtr(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    uVar1 = *(uint *)(param_1 + 8) & 0xffff7fff;
  }
  else {
    uVar1 = *(uint *)(param_1 + 8) | 0x8000;
  }
  *(uint *)(param_1 + 8) = uVar1;
  return;
}



/* ----------------------------------------
 * timer_set_deadtime @ 0x8000354
 * Startup / low-level init
 * ---------------------------------------- */

void timer_set_deadtime(int param_1,uint param_2)

{
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffff8fff | param_2;
  return;
}



/* ----------------------------------------
 * adc_check_ready @ 0x8000360
 * Startup / low-level init
 * ---------------------------------------- */

bool adc_check_ready(int param_1)

{
  return *(int *)(param_1 + 8) << 0x1d < 0;
}



/* ----------------------------------------
 * adc_check_busy @ 0x800036e
 * Startup / low-level init
 * ---------------------------------------- */

bool adc_check_busy(int param_1)

{
  return *(int *)(param_1 + 8) << 0x1c < 0;
}



/* ----------------------------------------
 * FUN_0800037c @ 0x800037c
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_0800037c(int param_1,uint *param_2)

{
  *(uint *)(param_1 + 4) =
       *param_2 | *(uint *)(param_1 + 4) & DAT_080003bc | (uint)(byte)param_2[1] << 8;
  *(uint *)(param_1 + 8) =
       param_2[3] | param_2[2] |
       *(uint *)(param_1 + 8) & DAT_080003c0 | (uint)*(byte *)((int)param_2 + 5) << 1;
  *(uint *)(param_1 + 0x2c) =
       *(uint *)(param_1 + 0x2c) & 0xff0fffff | ((byte)param_2[4] - 1 & 0xff) << 0x14;
  return;
}



/* ----------------------------------------
 * FUN_080003c4 @ 0x80003c4
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_080003c4(int param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  
  if (param_2 < 10) {
    *(uint *)(param_1 + 0x10) =
         *(uint *)(param_1 + 0x10) & ~(7 << (param_2 * 3 & 0xff)) | param_4 << (param_2 * 3 & 0xff);
  }
  else {
    uVar1 = (param_2 - 10) * 3;
    *(uint *)(param_1 + 0xc) =
         *(uint *)(param_1 + 0xc) & ~(7 << (uVar1 & 0xff)) | param_4 << (uVar1 & 0xff);
  }
  uVar1 = ((param_3 - ((*(uint *)(param_1 + 0x38) << 10) >> 0x1e)) + 2) * 5;
  *(uint *)(param_1 + 0x38) =
       *(uint *)(param_1 + 0x38) & ~(0x1f << (uVar1 & 0xff)) | param_2 << (uVar1 & 0xff);
  return;
}



/* ----------------------------------------
 * FUN_0800040e @ 0x800040e
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_0800040e(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & 0xffcfffff | (param_2 + -1) * 0x100000;
  return;
}



/* ----------------------------------------
 * FUN_0800041e @ 0x800041e
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_0800041e(int param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  
  if (param_2 < 10) {
    *(uint *)(param_1 + 0x10) =
         *(uint *)(param_1 + 0x10) & ~(7 << (param_2 * 3 & 0xff)) | param_4 << (param_2 * 3 & 0xff);
  }
  else {
    uVar1 = (param_2 - 10) * 3;
    *(uint *)(param_1 + 0xc) =
         *(uint *)(param_1 + 0xc) & ~(7 << (uVar1 & 0xff)) | param_4 << (uVar1 & 0xff);
  }
  if (param_3 < 7) {
    uVar1 = (param_3 - 1) * 5;
    *(uint *)(param_1 + 0x34) =
         *(uint *)(param_1 + 0x34) & ~(0x1f << (uVar1 & 0xff)) | param_2 << (uVar1 & 0xff);
    return;
  }
  if (param_3 < 0xd) {
    uVar1 = (param_3 - 7) * 5;
    *(uint *)(param_1 + 0x30) =
         *(uint *)(param_1 + 0x30) & ~(0x1f << (uVar1 & 0xff)) | param_2 << (uVar1 & 0xff);
    return;
  }
  uVar1 = (param_3 - 0xd) * 5;
  *(uint *)(param_1 + 0x2c) =
       *(uint *)(param_1 + 0x2c) & ~(0x1f << (uVar1 & 0xff)) | param_2 << (uVar1 & 0xff);
  return;
}



/* ----------------------------------------
 * adc_start @ 0x8000492
 * Startup / low-level init
 * ---------------------------------------- */

void adc_start(int param_1)

{
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 8;
  return;
}



/* ----------------------------------------
 * FUN_0800049c @ 0x800049c
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_0800049c(undefined2 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  do {
    iVar2 = FUN_08000f2c(2);
    puVar1 = DAT_080004cc;
  } while (iVar2 == 0);
  param_1[2] = (short)*DAT_080004cc;
  param_1[1] = (short)((uint)*puVar1 >> 0x10);
  *param_1 = (short)puVar1[1];
  param_1[3] = (short)((uint)puVar1[1] >> 0x10);
  FUN_080004d4(DAT_080004d0,0);
  return;
}



/* ----------------------------------------
 * FUN_080004d4 @ 0x80004d4
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_080004d4(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    uVar1 = *(uint *)(param_1 + 8) & 0xffafffff;
  }
  else {
    uVar1 = *(uint *)(param_1 + 8) | 0x500000;
  }
  *(uint *)(param_1 + 8) = uVar1;
  return;
}



/* ----------------------------------------
 * adc_stop @ 0x80004e8
 * Startup / low-level init
 * ---------------------------------------- */

void adc_stop(int param_1)

{
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 4;
  return;
}



/* ----------------------------------------
 * FUN_080004f2 @ 0x80004f2
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_080004f2(undefined4 *param_1)

{
  *param_1 = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 5) = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 4) = 1;
  return;
}



/* ----------------------------------------
 * FUN_08000504 @ 0x8000504
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_08000504(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint *puVar4;
  short *psVar5;
  undefined4 *puVar6;
  uint *puVar7;
  short *psVar8;
  short sVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 uVar15;
  uint uVar16;
  uint *puVar17;
  char cVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  
  puVar6 = DAT_080006f8;
  psVar5 = DAT_080006f4;
  puVar4 = DAT_080006f0;
  puVar3 = DAT_080006ec;
  puVar2 = DAT_080006e8;
  if (*DAT_080006e4 == '\0') {
    *DAT_080006e8 = 0;
    *DAT_08000704 = 0;
    *puVar3 = 0;
    *puVar4 = 0;
    *psVar5 = 0;
    goto LAB_08000618;
  }
  uVar10 = *DAT_080006f8;
  uVar11 = FUN_08005aac(uVar10,*DAT_080006e8,param_3,param_4,param_4);
  uVar11 = FUN_080058b0(uVar11,DAT_080006fc);
  *puVar3 = uVar11;
  uVar19 = FUN_080054f4(uVar10);
  uVar19 = FUN_08005124((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0x33333333,DAT_08000700);
  puVar7 = DAT_08000704;
  uVar20 = FUN_080054f4(*DAT_08000704);
  FUN_08004cf4((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar19,
               (int)((ulonglong)uVar19 >> 0x20));
  uVar12 = FUN_08004c90();
  puVar17 = DAT_08000710;
  uVar13 = DAT_08000708;
  *puVar7 = uVar12;
  uVar14 = DAT_0800070c;
  uVar16 = *puVar17;
  if ((int)uVar13 < (int)uVar12) {
    *puVar7 = uVar13;
LAB_08000584:
    puVar17 = DAT_08000710;
    cVar18 = 0x7fffff < uVar16;
    if ((int)uVar16 < 0x800000) {
LAB_080005a0:
      if (uVar14 <= *puVar7) goto LAB_080005a6;
      goto LAB_080005b8;
    }
    FUN_08005a48(*puVar7);
    if (cVar18 != '\0') goto LAB_0800059a;
LAB_08000594:
    uVar13 = *puVar17;
LAB_0800059c:
    *puVar4 = uVar13;
  }
  else {
    if (uVar12 <= DAT_08000714) {
      if (0x7fffff < (int)uVar12) goto LAB_08000584;
      goto LAB_080005a0;
    }
    *puVar7 = DAT_08000714;
LAB_080005a6:
    puVar17 = DAT_08000710;
    cVar18 = uVar14 <= uVar16;
    if ((bool)cVar18) {
      FUN_08005a48(*puVar7);
      if (cVar18 != '\0') goto LAB_08000594;
LAB_0800059a:
      uVar13 = *puVar7;
      goto LAB_0800059c;
    }
LAB_080005b8:
    puVar17 = DAT_08000710;
    *puVar4 = 0;
    *puVar7 = 0;
    *puVar17 = 0;
  }
  uVar10 = *puVar6;
  uVar11 = FUN_080058b0(uVar10,DAT_08000718);
  uVar11 = FUN_0800554c(uVar11,*puVar4);
  FUN_0800554c(uVar11,*DAT_080006ec);
  sVar9 = FUN_080057b8();
  sVar1 = *DAT_0800071c;
  *psVar5 = sVar9 + sVar1;
  if (0x3ff < (short)(sVar9 + sVar1)) {
    *psVar5 = 0x3ff;
  }
  if (*psVar5 < -0x3ff) {
    *psVar5 = -0x3ff;
  }
  *puVar2 = uVar10;
LAB_08000618:
  psVar8 = DAT_0800072c;
  puVar3 = DAT_08000728;
  puVar2 = DAT_08000724;
  if (*DAT_08000720 == '\0') {
    *DAT_08000724 = 0;
    *DAT_08000710 = 0;
    *puVar3 = 0;
    *puVar4 = 0;
    *psVar8 = 0;
  }
  else {
    uVar10 = *DAT_08000730;
    uVar11 = FUN_08005aac(uVar10,*DAT_08000724);
    uVar11 = FUN_080058b0(uVar11,DAT_080006fc);
    *puVar3 = uVar11;
    uVar19 = FUN_080054f4(uVar10);
    uVar19 = FUN_08005124((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0x33333333,DAT_08000700);
    puVar7 = DAT_08000710;
    uVar20 = FUN_080054f4(*DAT_08000710);
    FUN_08004cf4((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar19,
                 (int)((ulonglong)uVar19 >> 0x20));
    uVar14 = FUN_08004c90();
    uVar13 = DAT_08000708;
    *puVar7 = uVar14;
    if (((int)uVar13 < (int)uVar14) || (uVar13 = DAT_08000714, DAT_08000714 < uVar14)) {
      *puVar7 = uVar13;
    }
    uVar15 = FUN_080058b0(uVar10,DAT_08000718);
    uVar15 = FUN_0800554c(uVar15,*puVar4);
    FUN_0800554c(uVar15,uVar11);
    sVar9 = FUN_080057b8();
    sVar1 = *DAT_0800071c;
    *psVar8 = sVar9 - sVar1;
    if (0x3ff < (short)(sVar9 - sVar1)) {
      *psVar8 = 0x3ff;
    }
    if (*psVar8 < -0x3ff) {
      *psVar8 = -0x3ff;
    }
    *puVar2 = uVar10;
  }
  *DAT_08000734 = *psVar5;
  *DAT_08000738 = -*psVar8;
  return;
}



/* ----------------------------------------
 * FUN_0800073c @ 0x800073c
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_0800073c(void)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  byte *pbVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  char *pcVar14;
  char *pcVar15;
  
  pcVar8 = DAT_080009ac;
  pcVar7 = DAT_080009a8;
  pcVar6 = DAT_080009a4;
  pcVar15 = DAT_080009a0;
  pcVar14 = DAT_08000998;
  cVar1 = *DAT_0800099c;
  cVar11 = '\x01';
  cVar12 = '\x01';
  cVar10 = '\0';
  if (*DAT_08000998 == '\0') {
    if (cVar1 != '\0') {
      *DAT_080009a4 = '\x01';
      cVar13 = -0x38;
      do {
        if (*pcVar8 != '\0') {
          cVar13 = cVar13 + -1;
          *pcVar8 = '\0';
        }
      } while (cVar13 != '\0');
      *pcVar6 = '\0';
    }
  }
  else if (cVar1 == '\0') {
    *DAT_080009a0 = '\0';
    *pcVar7 = '\0';
  }
  pbVar9 = DAT_080009b0;
  *pcVar14 = cVar1;
  pcVar14 = DAT_080009bc;
  bVar2 = *pbVar9;
  if (*pcVar15 == '\0') {
    cVar1 = *pcVar7;
    cVar12 = cVar11;
    if ((cVar1 != '\0') && (cVar12 = '\x02', cVar1 != '\x01')) {
      if (cVar1 != '\x02') {
        *pcVar6 = '\0';
        *pbVar9 = 0;
        *pcVar7 = '\0';
        *pcVar15 = '\x01';
        return;
      }
      *pcVar6 = '\x03';
      if (0x4f < bVar2) {
        *pbVar9 = 0;
        *pcVar7 = '\x03';
        return;
      }
      goto LAB_080007ca;
    }
LAB_080008aa:
    *pcVar6 = cVar12;
LAB_080008d0:
    if (0x4f < bVar2) {
LAB_08000884:
      *pbVar9 = 0;
      *pcVar7 = cVar12;
      return;
    }
  }
  else {
    if (cVar1 != '\0') goto LAB_0800079c;
    if (*DAT_080009b4 != '\0') {
      *pcVar6 = '\x03';
      return;
    }
    if (*DAT_080009b8 != '\0') {
      if (*DAT_080009bc != '\0') {
        return;
      }
      *pcVar6 = '\x03';
      if (bVar2 < 0x50) goto LAB_080007ca;
      *pbVar9 = 0;
      *pcVar14 = '\x01';
      goto LAB_0800079c;
    }
    cVar1 = *DAT_080009c0;
    if (cVar1 == '\0') {
      pcVar14 = DAT_080009cc;
      if (*DAT_080009c4 != '\0') goto LAB_080007e4;
    }
    else {
      pcVar14 = DAT_080009c8;
      if (*DAT_080009c4 == '\0') {
LAB_080007e4:
        *pcVar14 = '\x01';
      }
    }
    pcVar14 = DAT_080009e0;
    cVar13 = *DAT_080009d0;
    cVar4 = *DAT_080009d4;
    cVar5 = *DAT_080009d8;
    cVar3 = *DAT_080009dc;
    if (((cVar13 == '\0') || (cVar4 != '\0')) || (cVar3 != '\0')) {
      if ((cVar13 == '\0' && cVar5 == '\0') && (cVar3 != '\0')) {
        *DAT_080009e4 = '\x01';
      }
      if (((cVar13 != '\0') || (cVar4 == '\0')) || ((cVar3 != '\0' || (cVar5 != '\0'))))
      goto LAB_08000834;
LAB_08000844:
      *pcVar14 = '\x01';
    }
    else {
      *DAT_080009e4 = '\x01';
LAB_08000834:
      if (((cVar13 == '\0' && cVar4 == '\0') && cVar3 == '\0') && (cVar5 != '\0'))
      goto LAB_08000844;
    }
    *DAT_080009c4 = cVar1;
    *DAT_080009d4 = cVar13;
    *DAT_080009d8 = cVar3;
    pcVar15 = DAT_080009e8;
    if (*DAT_080009e8 != '\0') {
      if (*pcVar7 != '\0') {
        *pcVar6 = '\0';
        *pbVar9 = 0;
        *pcVar7 = '\0';
        *pcVar15 = '\0';
        return;
      }
      *pcVar6 = '\x01';
      if (bVar2 < 0x78) goto LAB_080007ca;
      goto LAB_08000884;
    }
    pcVar15 = DAT_080009c8;
    if (*DAT_080009c8 != '\0') {
LAB_080008e0:
      cVar12 = cVar11;
      if ((*pcVar7 != '\0') && (cVar12 = '\x02', *pcVar7 != '\x01')) {
LAB_0800089c:
        *pcVar6 = '\0';
        *pbVar9 = 0;
        *pcVar7 = '\0';
        *pcVar15 = '\0';
        return;
      }
      goto LAB_080008aa;
    }
    if (*DAT_080009cc == '\0') {
      pcVar15 = DAT_080009e4;
      if (*DAT_080009e4 != '\0') goto LAB_080008e0;
      if (*pcVar14 == '\0') {
        if (*DAT_080009ec == '\0') {
          if (*DAT_080009f0 != '\0') {
            if (199 < bVar2) {
              *pbVar9 = 0;
              if (*pcVar6 == '\0') {
                cVar10 = '\x04';
              }
              goto LAB_0800079c;
            }
            goto LAB_080007ca;
          }
          if (*DAT_080009f4 != '\0') {
            if (bVar2 < 100) goto LAB_080007ca;
            *pbVar9 = 0;
            if (*pcVar6 == '\0') {
              *pcVar6 = '\x02';
              return;
            }
            goto LAB_0800079c;
          }
          if (*DAT_080009f8 == '\0') goto LAB_0800079c;
        }
        if (99 < bVar2) {
          *pbVar9 = 0;
          if (*pcVar6 == '\0') {
            *pcVar6 = '\x01';
            return;
          }
LAB_0800079c:
          *pcVar6 = cVar10;
          return;
        }
        goto LAB_080007ca;
      }
      if (*pcVar7 == '\0') goto LAB_080008cc;
      if (*pcVar7 != '\x01') {
        *pcVar6 = '\0';
        *pbVar9 = 0;
        *pcVar7 = '\0';
        *pcVar14 = '\0';
        return;
      }
    }
    else {
      if (*pcVar7 == '\0') {
LAB_080008cc:
        *pcVar6 = '\x02';
        cVar12 = cVar11;
        goto LAB_080008d0;
      }
      pcVar15 = DAT_080009cc;
      if (*pcVar7 != '\x01') goto LAB_0800089c;
    }
    *pcVar6 = '\x01';
    if (0x4f < bVar2) {
      *pbVar9 = 0;
      *pcVar7 = '\x02';
      return;
    }
  }
LAB_080007ca:
  *pbVar9 = bVar2 + 1;
  return;
}



/* ----------------------------------------
 * FUN_080009fc @ 0x80009fc
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_080009fc(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  byte *pbVar3;
  byte bVar4;
  
  pbVar3 = DAT_08000a60;
  uVar2 = DAT_08000a5c;
  if (param_1 == 0) goto LAB_08000a52;
  bVar1 = *DAT_08000a60;
  if (param_1 == 1) {
    if (bVar1 == 0) {
      bVar4 = 6;
      goto LAB_08000a20;
    }
  }
  else if (param_1 == 2) {
    if (bVar1 == 0) {
      bVar4 = 5;
      goto LAB_08000a20;
    }
  }
  else if (param_1 == 3) {
    if (bVar1 == 0) {
      bVar4 = 4;
      goto LAB_08000a20;
    }
  }
  else if ((param_1 == 4) && (bVar1 == 0)) {
    bVar4 = 0xf;
LAB_08000a20:
    DAT_08000a60[1] = bVar4;
    goto LAB_08000a32;
  }
  if (DAT_08000a60[1] <= bVar1) {
    *DAT_08000a60 = 0;
    if (pbVar3[2] != 0) {
      pbVar3[2] = 0;
      FUN_080014da(uVar2,0x10);
      return;
    }
    pbVar3[2] = 1;
LAB_08000a52:
    FUN_080014d6(uVar2,0x10);
    return;
  }
LAB_08000a32:
  *pbVar3 = bVar1 + 1;
  return;
}



/* ----------------------------------------
 * FUN_08000a64 @ 0x8000a64
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_08000a64(void)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined1 *puVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  
  iVar4 = DAT_08000b58;
  iVar8 = DAT_08000b50;
  uVar1 = *(ushort *)(DAT_08000b50 + 10);
  iVar7 = (int)DAT_08000b4c[3] + (int)*DAT_08000b4c + (int)DAT_08000b4c[1] + (int)DAT_08000b4c[2] >>
          2;
  *DAT_08000b54 = (short)iVar7 - uVar1;
  puVar5 = DAT_08000b64;
  sVar2 = *(short *)(iVar4 + 2);
  sVar3 = *DAT_08000b5c;
  if (((int)(uVar1 + 0x2a8) < iVar7) || (sVar3 < 0x447)) {
    *DAT_08000b60 = '\x01';
    if (sVar2 < 0) {
      *(short *)(iVar4 + 2) = sVar2 + 1;
    }
    else {
      *(short *)(iVar4 + 2) = sVar2 + -1;
    }
  }
  else if (*DAT_08000b60 != '\0') {
    *DAT_08000b60 = '\0';
    *puVar5 = 2;
  }
  pcVar6 = DAT_08000b74;
  iVar4 = DAT_08000b70;
  uVar1 = *(ushort *)(iVar8 + 8);
  iVar8 = (int)DAT_08000b68[3] + (int)*DAT_08000b68 + (int)DAT_08000b68[1] + (int)DAT_08000b68[2] >>
          2;
  *DAT_08000b6c = (short)iVar8 - uVar1;
  sVar2 = *(short *)(iVar4 + 2);
  if (((int)(uVar1 + 0x2a8) < iVar8) || (sVar3 < 0x447)) {
    *pcVar6 = '\x01';
    if (sVar2 < 0) {
      *(short *)(iVar4 + 2) = sVar2 + 1;
    }
    else {
      *(short *)(iVar4 + 2) = sVar2 + -1;
    }
  }
  else if (*pcVar6 != '\0') {
    *pcVar6 = '\0';
    *puVar5 = 2;
  }
  return;
}



/* ----------------------------------------
 * FUN_08000b7c @ 0x8000b7c
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_08000b7c(void)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short *psVar5;
  int *piVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  psVar5 = DAT_08000cb0;
  iVar9 = ((int)DAT_08000ca8[3] + (int)*DAT_08000ca8 + (int)DAT_08000ca8[1] + (int)DAT_08000ca8[2])
          * 0x4000;
  iVar10 = iVar9 >> 0x10;
  sVar3 = (short)((uint)iVar9 >> 0x10);
  *DAT_08000cac = sVar3;
  iVar8 = DAT_08000cb4;
  iVar9 = *psVar5 * 0x7d;
  sVar4 = (short)((int)(iVar9 + ((uint)(iVar9 >> 0x1f) >> 0x19)) >> 7) +
          (short)((int)(iVar10 * 3 + ((uint)(iVar10 * 3 >> 0x1f) >> 0x19)) >> 7);
  *psVar5 = sVar4;
  iVar8 = FUN_080057f0(iVar8 / (int)sVar4);
  iVar9 = DAT_08000cbc;
  piVar6 = DAT_08000cb8;
  *DAT_08000cb8 = iVar8;
  if ((iVar9 <= iVar8) || (iVar9 = DAT_08000cc0, iVar8 <= DAT_08000cc0)) {
    *piVar6 = iVar9;
  }
  sVar4 = *DAT_08000cc8;
  sVar2 = *DAT_08000ccc;
  iVar9 = ((int)sVar4 + (int)sVar2) * 8;
  *DAT_08000cc4 =
       (short)((int)(*DAT_08000cc4 * 0x78 + ((uint)(*DAT_08000cc4 * 0x78 >> 0x1f) >> 0x19)) >> 7) +
       (short)((int)(iVar9 + ((uint)(iVar9 >> 0x1f) >> 0x19)) >> 7);
  iVar9 = DAT_08000cd4;
  psVar5 = DAT_08000cd0;
  if (((int)sVar4 + (int)sVar2) - 1U < 0x68) {
    if (iVar10 < *DAT_08000cd0) {
      uVar1 = *(ushort *)(DAT_08000cd4 + 0x12);
      *(ushort *)(DAT_08000cd4 + 0x12) = uVar1 + 1;
      if (600 < uVar1) {
        *(undefined2 *)(iVar9 + 0x12) = 0;
        *psVar5 = sVar3;
      }
    }
    else {
      *(undefined2 *)(DAT_08000cd4 + 0x12) = 0;
    }
    *DAT_08000cd8 =
         (short)((int)(*DAT_08000cd8 * 100 + ((uint)(*DAT_08000cd8 * 100 >> 0x1f) >> 0x19)) >> 7) +
         (short)((int)(iVar10 * 0x1c + ((uint)(iVar10 * 0x1c >> 0x1f) >> 0x19)) >> 7);
  }
  sVar3 = *psVar5;
  if (sVar3 < 0x563) {
    *DAT_08000cdc = 1;
  }
  else {
    *DAT_08000cdc = 0;
  }
  pcVar7 = DAT_08000ce0;
  if (sVar3 < 0x543) {
    *DAT_08000ce0 = '\x01';
  }
  else {
    *DAT_08000ce0 = '\0';
  }
  if (((*(uint *)(DAT_08000ce4 + 8) < 0x546) && (*(uint *)(DAT_08000cec + 8) < 0x546)) &&
     (*pcVar7 == '\x01')) {
    *DAT_08000ce8 = 1;
    return;
  }
  *DAT_08000ce8 = 0;
  return;
}



/* ----------------------------------------
 * FUN_08000cf0 @ 0x8000cf0
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_08000cf0(void)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = FUN_080014c8(DAT_08000d2c,0x1000);
  iVar2 = DAT_08000d34;
  puVar1 = DAT_08000d30;
  if (iVar3 == 0) {
    *(undefined1 *)(DAT_08000d34 + 5) = 0;
    if (9 < *(byte *)(iVar2 + 4)) {
      *puVar1 = 1;
      return;
    }
    *(byte *)(iVar2 + 4) = *(byte *)(iVar2 + 4) + 1;
    return;
  }
  *(undefined1 *)(DAT_08000d34 + 4) = 0;
  if (9 < *(byte *)(iVar2 + 5)) {
    *puVar1 = 0;
    return;
  }
  *(byte *)(iVar2 + 5) = *(byte *)(iVar2 + 5) + 1;
  return;
}



/* ----------------------------------------
 * FUN_08000d38 @ 0x8000d38
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_08000d38(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined2 *puVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  
  if ((*DAT_08000e00 == '\0') || (*DAT_08000e08 == '\0' && *DAT_08000e0c == '\0')) {
    *DAT_08000e04 = 0;
  }
  else {
    *DAT_08000e04 = 1;
  }
  puVar3 = DAT_08000e20;
  iVar2 = DAT_08000e1c;
  puVar1 = DAT_08000e18;
  if (*(char *)(DAT_08000e10 + 0x3b) == *(char *)(DAT_08000e14 + 0x3b)) {
    *DAT_08000e18 = 0;
    *(undefined1 *)(iVar2 + 0xf) = 0;
    goto LAB_08000df0;
  }
  bVar4 = *(char *)(DAT_08000e1c + 0xf) + 1;
  uVar5 = *(uint *)(DAT_08000e14 + 8) + *(uint *)(DAT_08000e10 + 8);
  if (*DAT_08000e24 == '\0') {
    uVar6 = (uint)*DAT_08000e28;
    if (uVar5 >> 1 < uVar6 + 3) goto LAB_08000dd6;
LAB_08000dda:
    *DAT_08000e18 = 0;
    *(undefined1 *)(iVar2 + 0xf) = 0;
  }
  else {
    if (0x289 < uVar5) goto LAB_08000dda;
    uVar6 = 0x144;
LAB_08000dd6:
    if ((((uVar6 < *(uint *)(DAT_08000e14 + 8)) || (uVar6 < *(uint *)(DAT_08000e10 + 8))) ||
        (*(char *)(DAT_08000e14 + 0x14) == '\0')) || (*(char *)(DAT_08000e10 + 0x14) == '\0'))
    goto LAB_08000dda;
    *(byte *)(DAT_08000e1c + 0xf) = bVar4;
    if (2 < bVar4) {
      *puVar1 = 1;
      *(undefined1 *)(iVar2 + 0xf) = 3;
    }
  }
  uVar5 = DAT_08000e2c / (uVar5 >> 1);
  *puVar3 = (short)uVar5;
  if (0xc < (uVar5 & 0xffff)) {
    return;
  }
LAB_08000df0:
  *puVar3 = 0;
  return;
}



/* ----------------------------------------
 * FUN_08000e30 @ 0x8000e30
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_08000e30(uint *param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    uVar1 = *param_1 & 0xfffe;
  }
  else {
    uVar1 = *param_1 | 1;
  }
  *param_1 = uVar1;
  return;
}



/* ----------------------------------------
 * FUN_08000e48 @ 0x8000e48
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_08000e48(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  
  *param_1 = *param_1 & 0xfffe;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if (param_1 == DAT_08000f24) {
    uVar1 = DAT_08000f24[-1] | 0xf;
  }
  else if (param_1 == DAT_08000f24 + 5) {
    uVar1 = DAT_08000f24[-1] | 0xf0;
  }
  else if (param_1 == DAT_08000f24 + 10) {
    uVar1 = DAT_08000f24[-1] | 0xf00;
  }
  else if (param_1 == DAT_08000f24 + 0xf) {
    uVar1 = DAT_08000f24[-1] | 0xf000;
  }
  else if (param_1 == DAT_08000f24 + 0x14) {
    uVar1 = DAT_08000f24[-1] | 0xf0000;
  }
  else if (param_1 == DAT_08000f24 + 0x19) {
    uVar1 = DAT_08000f24[-1] | 0xf00000;
  }
  else {
    if (param_1 != DAT_08000f24 + 0x1e) {
      puVar2 = DAT_08000f28 + -1;
      if (param_1 == DAT_08000f28) {
        uVar1 = *puVar2 | 0xf;
      }
      else if (param_1 == DAT_08000f28 + 5) {
        uVar1 = *puVar2 | 0xf0;
      }
      else if (param_1 == DAT_08000f28 + 10) {
        uVar1 = *puVar2 | 0xf00;
      }
      else if (param_1 == DAT_08000f28 + 0xf) {
        uVar1 = *puVar2 | 0xf000;
      }
      else {
        if (param_1 != DAT_08000f28 + 0x14) {
          return;
        }
        uVar1 = *puVar2 | 0xf0000;
      }
      *puVar2 = uVar1;
      return;
    }
    uVar1 = DAT_08000f24[-1] | 0xf000000;
  }
  DAT_08000f24[-1] = uVar1;
  return;
}



/* ----------------------------------------
 * FUN_08000f2c @ 0x8000f2c
 * Startup / low-level init
 * ---------------------------------------- */

bool FUN_08000f2c(uint param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_08000f48;
  if ((int)(param_1 << 3) < 0) {
    puVar1 = DAT_08000f44;
  }
  return (*puVar1 & param_1) != 0;
}



/* ----------------------------------------
 * adc_init @ 0x8000f4c
 * Startup / low-level init
 * ---------------------------------------- */

void adc_init(uint *param_1,uint *param_2)

{
  *param_1 = param_2[2] | param_2[8] | param_2[4] | param_2[5] | param_2[6] | param_2[7] |
             param_2[9] | param_2[10] | *param_1 & 0xffff800f;
  param_1[1] = param_2[3];
  param_1[2] = *param_2;
  param_1[3] = param_2[1];
  return;
}



/* ----------------------------------------
 * FUN_08000f88 @ 0x8000f88
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_08000f88(uint param_1)

{
  undefined1 *puVar1;
  
  FUN_08002c38(0xfffffffb);
  puVar1 = DAT_08000fb0;
  *DAT_08000fb0 = (char)(param_1 >> 3);
  *(short *)(puVar1 + 2) = (short)(param_1 >> 3) * 1000;
  return;
}



/* ----------------------------------------
 * FUN_08000fb4 @ 0x8000fb4
 * Startup / low-level init
 * ---------------------------------------- */

/* WARNING: Removing unreachable block (ram,0x08000fd2) */

void FUN_08000fb4(void)

{
                    /* WARNING: Do nothing block with infinite loop */
  do {
  } while( true );
}



/* ----------------------------------------
 * FUN_08000fdc @ 0x8000fdc
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_08000fdc(void)

{
  *DAT_08000fe4 = 1;
  return;
}



/* ----------------------------------------
 * FUN_08000fe8 @ 0x8000fe8
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_08000fe8(void)

{
  return;
}



/* ----------------------------------------
 * FUN_08000fec @ 0x8000fec
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_08000fec(void)

{
  *DAT_08000ff4 = 1;
  return;
}



/* ----------------------------------------
 * FUN_08000ff8 @ 0x8000ff8
 * Startup / low-level init
 * ---------------------------------------- */

void FUN_08000ff8(void)

{
  *DAT_08001000 = 1;
  return;
}



/* ----------------------------------------
 * FUN_08001004 @ 0x8001004
 * Unknown function
 * ---------------------------------------- */

void FUN_08001004(undefined4 param_1)

{
  *(undefined4 *)(DAT_0800100c + 0xc) = param_1;
  return;
}



/* ----------------------------------------
 * FUN_08001010 @ 0x8001010
 * Unknown function
 * ---------------------------------------- */

void FUN_08001010(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_08001118(0xb0000);
  iVar1 = DAT_08001048;
  if (iVar2 == 4) {
    *(uint *)(DAT_08001048 + 0x10) = *(uint *)(DAT_08001048 + 0x10) | 2;
    *(undefined4 *)(iVar1 + 0x14) = param_1;
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x40;
    FUN_08001118(0xb0000);
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0x1ffd;
  }
  return;
}



/* ----------------------------------------
 * FUN_0800104c @ 0x800104c
 * Unknown function
 * ---------------------------------------- */

undefined4 FUN_0800104c(void)

{
  undefined4 uVar1;
  
  uVar1 = 4;
  if ((*(uint *)(DAT_08001070 + 0xc) & 1) != 0) {
    return 1;
  }
  if (*(int *)(DAT_08001070 + 0xc) << 0x1d < 0) {
    uVar1 = 2;
  }
  else if (*(int *)(DAT_08001070 + 0xc) << 0x1b < 0) {
    return 3;
  }
  return uVar1;
}



/* ----------------------------------------
 * FUN_08001074 @ 0x8001074
 * Unknown function
 * ---------------------------------------- */

void FUN_08001074(void)

{
  *(uint *)(DAT_08001080 + 0x10) = *(uint *)(DAT_08001080 + 0x10) | 0x80;
  return;
}



/* ----------------------------------------
 * FUN_08001084 @ 0x8001084
 * Unknown function
 * ---------------------------------------- */

void FUN_08001084(uint param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_08001098;
  *DAT_08001098 = *DAT_08001098 & 0xffffffef;
  *puVar1 = *puVar1 | param_1;
  return;
}



/* ----------------------------------------
 * FUN_0800109c @ 0x800109c
 * Unknown function
 * ---------------------------------------- */

void FUN_0800109c(undefined2 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_08001118(0x2000);
  iVar1 = DAT_080010e8;
  if (iVar2 == 4) {
    *(uint *)(DAT_080010e8 + 0x10) = *(uint *)(DAT_080010e8 + 0x10) | 1;
    *param_1 = (short)param_2;
    iVar2 = FUN_08001118(0x2000);
    if (iVar2 == 4) {
      param_1[1] = (short)((uint)param_2 >> 0x10);
      FUN_08001118(0x2000);
    }
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0x1ffe;
  }
  return;
}



/* ----------------------------------------
 * FUN_080010ec @ 0x80010ec
 * Unknown function
 * ---------------------------------------- */

void FUN_080010ec(uint param_1)

{
  *DAT_080010fc = *DAT_080010fc & 0x38 | param_1;
  return;
}



/* ----------------------------------------
 * FUN_08001100 @ 0x8001100
 * Unknown function
 * ---------------------------------------- */

void FUN_08001100(void)

{
  int iVar1;
  
  iVar1 = DAT_08001110;
  *(undefined4 *)(DAT_08001110 + 4) = DAT_0800110c;
  *(undefined4 *)(iVar1 + 4) = DAT_08001114;
  return;
}



/* ----------------------------------------
 * FUN_08001118 @ 0x8001118
 * Unknown function
 * ---------------------------------------- */

int FUN_08001118(void)

{
  int iVar1;
  int extraout_r3;
  int extraout_r3_00;
  int iVar2;
  
  iVar1 = FUN_0800104c();
  iVar2 = extraout_r3;
  while (iVar1 == 1) {
    if (iVar2 == 0) goto LAB_08001130;
    iVar1 = FUN_0800104c();
    iVar2 = extraout_r3_00 + -1;
  }
  if (iVar2 == 0) {
LAB_08001130:
    iVar1 = 5;
  }
  return iVar1;
}



/* ----------------------------------------
 * FUN_0800113c @ 0x800113c
 * Unknown function
 * ---------------------------------------- */

void FUN_0800113c(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  
  iVar2 = DAT_0800117c;
  iVar1 = DAT_08001178;
  uVar5 = 0x10;
  do {
    uVar4 = FUN_080024c8(iVar1 + (0x10 - uVar5) * 2);
    *(undefined2 *)(iVar2 + (0x10 - uVar5) * 2) = uVar4;
    iVar3 = DAT_08001180;
    uVar5 = uVar5 - 1 & 0xff;
  } while (uVar5 != 0);
  *(undefined2 *)(DAT_08001180 + 0xe) = *(undefined2 *)(iVar2 + 0xc);
  *(undefined2 *)(iVar3 + 0x12) = *(undefined2 *)(iVar2 + 0x10);
  *(undefined2 *)(iVar3 + 0x10) = *(undefined2 *)(iVar2 + 0x14);
  *(undefined2 *)(iVar3 + 0x14) = *(undefined2 *)(iVar2 + 0x18);
  *(undefined2 *)(iVar3 + 0x16) = *(undefined2 *)(iVar2 + 0x1a);
  return;
}



/* ----------------------------------------
 * FUN_08001184 @ 0x8001184
 * Unknown function
 * ---------------------------------------- */

void FUN_08001184(void)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  puVar1 = DAT_08001218;
  *DAT_08001218 = 0x101;
  puVar1[1] = 0x1234;
  puVar1[2] = 0xffff;
  puVar1[3] = 0x1384;
  puVar1[4] = 0xfffe;
  puVar1[5] = 0xf038;
  iVar2 = DAT_0800121c;
  puVar1[6] = *(undefined2 *)(DAT_0800121c + 0xe);
  puVar1[8] = *(undefined2 *)(iVar2 + 0x12);
  puVar1[10] = *(undefined2 *)(iVar2 + 0x10);
  puVar1[0xc] = *(undefined2 *)(iVar2 + 0x18);
  puVar1[0xd] = *(undefined2 *)(iVar2 + 0x1a);
  FUN_08001100();
  iVar2 = DAT_08001220;
  iVar3 = FUN_08001010(DAT_08001220);
  if (iVar3 == 4) {
    uVar4 = 0x10;
    do {
      FUN_0800109c(iVar2 + (0x10 - uVar4) * 2,(int)(short)puVar1[0x10 - uVar4]);
      FUN_08001004(0x34);
      uVar4 = uVar4 - 1 & 0xff;
      FUN_08000fb4(1);
    } while (uVar4 != 0);
    uVar4 = 0x10;
    do {
      puVar1[0x10 - uVar4] = 0;
      uVar4 = uVar4 - 1 & 0xff;
    } while (uVar4 != 0);
    FUN_08001074();
  }
  FUN_08001074();
  return;
}



/* ----------------------------------------
 * FUN_08001224 @ 0x8001224
 * Unknown function
 * ---------------------------------------- */

void FUN_08001224(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 in_r3;
  undefined4 local_20;
  
  uVar1 = DAT_08001310;
  local_20 = in_r3;
  FUN_08001324(DAT_08001310);
  uVar2 = DAT_08001314;
  FUN_08001324(DAT_08001314);
  uVar3 = DAT_08001318;
  FUN_08001324(DAT_08001318);
  FUN_08001324(DAT_0800131c);
  FUN_08001470(DAT_08001320,1);
  local_20 = 0x40300e0;
  FUN_080013d8(uVar2,&local_20);
  local_20 = 0x4031c00;
  FUN_080013d8(uVar3,&local_20);
  local_20 = 0x10030020;
  FUN_080013d8(uVar1,&local_20);
  local_20 = 0x10030010;
  FUN_080013d8(uVar1,&local_20);
  FUN_080014d6(uVar1,0x10);
  local_20 = 0x10030004;
  FUN_080013d8(uVar2,&local_20);
  FUN_080014d6(uVar2,4);
  local_20 = 0x48031000;
  FUN_080013d8(uVar1,&local_20);
  local_20 = CONCAT22(local_20._2_2_,0x1000);
  local_20 = CONCAT13(4,(undefined3)local_20);
  FUN_080013d8(uVar2,&local_20);
  local_20 = CONCAT22(local_20._2_2_,0x40);
  local_20 = CONCAT13(4,(undefined3)local_20);
  FUN_080013d8(uVar1,&local_20);
  return;
}



/* ----------------------------------------
 * FUN_08001324 @ 0x8001324
 * Unknown function
 * ---------------------------------------- */

void FUN_08001324(int param_1)

{
  if (param_1 == DAT_080013bc) {
    FUN_080020d4(4,1);
    param_1 = 4;
  }
  else if (param_1 == DAT_080013c0) {
    FUN_080020d4(8,1);
    param_1 = 8;
  }
  else if (param_1 == DAT_080013c4) {
    FUN_080020d4(0x10,1);
    param_1 = 0x10;
  }
  else if (param_1 == DAT_080013c8) {
    FUN_080020d4(0x20,1);
    param_1 = 0x20;
  }
  else if (param_1 == DAT_080013cc) {
    FUN_080020d4(0x40,1);
    param_1 = 0x40;
  }
  else if (param_1 == DAT_080013d0) {
    FUN_080020d4(0x80,1);
    param_1 = 0x80;
  }
  else {
    if (param_1 != DAT_080013d4) {
      return;
    }
    param_1 = param_1 >> 0x16;
    FUN_080020d4(param_1,1);
  }
  FUN_080020d4(param_1,0);
  return;
}



/* ----------------------------------------
 * gpio_config @ 0x80013d8
 * Configure GPIO pin mode and speed
 * ---------------------------------------- */

void gpio_config(uint *param_1,ushort *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = 0;
  uVar2 = *(byte *)((int)param_2 + 3) & 0xf;
  if ((int)((uint)*(byte *)((int)param_2 + 3) << 0x1b) < 0) {
    uVar2 = uVar2 | (byte)param_2[1];
  }
  if ((char)*param_2 != '\0') {
    uVar4 = *param_1;
    do {
      uVar3 = 1 << (uVar1 & 0xff);
      if ((*param_2 & uVar3) == uVar3) {
        uVar4 = uVar2 << (uVar1 << 2 & 0xff) | uVar4 & ~(0xf << (uVar1 << 2 & 0xff));
        if (*(char *)((int)param_2 + 3) == '(') {
          param_1[5] = uVar3;
        }
        else if (*(char *)((int)param_2 + 3) == 'H') {
          param_1[4] = uVar3;
        }
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < 8);
    *param_1 = uVar4;
  }
  if (0xff < *param_2) {
    uVar4 = param_1[1];
    uVar1 = 0;
    do {
      uVar3 = 1 << (uVar1 + 8 & 0xff);
      if ((*param_2 & uVar3) == uVar3) {
        uVar4 = uVar4 & ~(0xf << (uVar1 << 2 & 0xff)) | uVar2 << (uVar1 << 2 & 0xff);
        if (*(char *)((int)param_2 + 3) == '(') {
          param_1[5] = uVar3;
        }
        if (*(char *)((int)param_2 + 3) == 'H') {
          param_1[4] = uVar3;
        }
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < 8);
    param_1[1] = uVar4;
  }
  return;
}



/* ----------------------------------------
 * FUN_08001470 @ 0x8001470
 * Unknown function
 * ---------------------------------------- */

void FUN_08001470(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = DAT_080014c4;
  if ((int)param_1 < 0) {
    uVar3 = *(uint *)(DAT_080014c4 + 0x1c);
  }
  else {
    uVar3 = *(uint *)(DAT_080014c4 + 4);
  }
  uVar4 = (param_1 & 0xffff) << ((param_1 >> 0x15 & 0xf) << 4);
  if ((param_1 << 10) >> 0x1e == 3) {
    uVar3 = uVar3 & 0xf0ffffff;
    *(uint *)(DAT_080014c4 + 4) = *(uint *)(DAT_080014c4 + 4) & 0xf0ffffff;
  }
  else {
    uVar1 = uVar4;
    if ((int)(param_1 << 0xb) < 0) {
      uVar1 = 3 << ((param_1 << 0xc) >> 0x1c);
    }
    uVar3 = uVar3 & ~uVar1 | 0xf000000;
  }
  if (param_2 != 0) {
    uVar3 = uVar3 | uVar4;
  }
  if (-1 < (int)param_1) {
    *(uint *)(iVar2 + 4) = uVar3;
    return;
  }
  *(uint *)(iVar2 + 0x1c) = uVar3;
  return;
}



/* ----------------------------------------
 * FUN_080014c8 @ 0x80014c8
 * Unknown function
 * ---------------------------------------- */

bool FUN_080014c8(int param_1,uint param_2)

{
  return (*(uint *)(param_1 + 8) & param_2) != 0;
}



/* ----------------------------------------
 * FUN_080014d6 @ 0x80014d6
 * Unknown function
 * ---------------------------------------- */

void FUN_080014d6(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}



/* ----------------------------------------
 * FUN_080014da @ 0x80014da
 * Unknown function
 * ---------------------------------------- */

void FUN_080014da(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return;
}



/* ----------------------------------------
 * FUN_080014e0 @ 0x80014e0
 * Unknown function
 * ---------------------------------------- */

void FUN_080014e0(int param_1,short *param_2)

{
  short sVar1;
  undefined4 *puVar2;
  short sVar3;
  undefined4 uVar4;
  
  puVar2 = DAT_08001508;
  uVar4 = *DAT_08001504;
  *(short *)(param_1 + 0x10) = (short)uVar4;
  *(short *)(param_1 + 0x12) = (short)*puVar2;
  sVar1 = *(short *)(param_1 + 4) - (short)uVar4;
  param_2[2] = sVar1;
  sVar3 = *(short *)(param_1 + 6) - *(short *)(param_1 + 0x12);
  param_2[1] = sVar3;
  *param_2 = -(sVar3 + sVar1);
  return;
}



/* ----------------------------------------
 * FUN_0800150c @ 0x800150c
 * Unknown function
 * ---------------------------------------- */

void FUN_0800150c(short *param_1,short *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_0800152c;
  uVar2 = *DAT_08001528;
  param_1[6] = (short)uVar2;
  param_1[7] = (short)*puVar1;
  *param_2 = *param_1 - (short)uVar2;
  param_2[1] = param_1[1] - param_1[7];
  return;
}



/* ----------------------------------------
 * FUN_08001530 @ 0x8001530
 * Unknown function
 * ---------------------------------------- */

void FUN_08001530(void)

{
  short sVar1;
  int iVar2;
  undefined1 *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  short sVar6;
  short sVar7;
  undefined2 uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  undefined4 in_r3;
  undefined2 *puVar13;
  byte *pbVar14;
  int iVar15;
  
  puVar3 = DAT_0800179c;
  iVar15 = DAT_08001798;
  *(undefined4 *)(DAT_08001798 + 8) = 0xffff;
  *(undefined4 *)(iVar15 + 0x48) = 0xffff;
  puVar3[9] = 0;
  puVar3[10] = 0;
  puVar3[0xb] = 0;
  puVar3[0xc] = 0;
  puVar3[6] = 0;
  puVar3[2] = 0;
  puVar3[1] = 0;
  puVar3[7] = 0;
  puVar3[0xd] = 0xf;
  sVar6 = 0x32;
  do {
    if (puVar3[3] != '\0') {
      sVar6 = sVar6 + -1;
      puVar3[3] = 0;
    }
  } while (sVar6 != 0);
  if (0x4d8 < ((uint)*(ushort *)(DAT_0800179c + 0x22) +
              (uint)*(ushort *)(DAT_0800179c + 0x1c) + (uint)*(ushort *)(DAT_0800179c + 0x1e) +
              (uint)*(ushort *)(DAT_0800179c + 0x20)) * 0x10000 >> 0x12) {
    FUN_080014da(DAT_080017a0,0x20,(uint)*(ushort *)(DAT_0800179c + 0x20),in_r3,in_r3);
  }
  FUN_0800113c();
  iVar15 = 0x28;
  sVar6 = 100;
  do {
    if (puVar3[3] != '\0') {
      sVar6 = sVar6 + -1;
      puVar3[3] = 0;
    }
    puVar4 = DAT_080017a4;
  } while (sVar6 != 0);
  *DAT_080017a4 = *DAT_080017a4 | 0x8000;
  puVar5 = DAT_080017a8;
  *DAT_080017a8 = *DAT_080017a8 | 0x8000;
  sVar6 = 0x17c;
  do {
    if (puVar3[3] != '\0') {
      sVar6 = sVar6 + -1;
      puVar3[3] = 0;
    }
    iVar2 = DAT_08001798;
  } while (sVar6 != 0);
  puVar13 = (undefined2 *)(DAT_08001798 + 0xac);
  iVar9 = (uint)*(ushort *)(DAT_0800179c + 0x2a) +
          (uint)*(ushort *)(DAT_0800179c + 0x24) + (uint)*(ushort *)(DAT_0800179c + 0x26) +
          (uint)*(ushort *)(DAT_0800179c + 0x28);
  uVar10 = (uint)(iVar9 * 0x10000) >> 0x12;
  *(ushort *)(DAT_08001798 + 0xb4) = (ushort)iVar9 >> 2;
  if ((0x8b9 < uVar10) || (uVar10 < 0x64f)) {
    puVar3[4] = 1;
    *puVar5 = (ushort)(((uint)*puVar5 << 0x11) >> 0x11);
  }
  iVar9 = (uint)*(ushort *)(DAT_0800179c + 0x32) +
          (uint)*(ushort *)(DAT_0800179c + 0x2c) + (uint)*(ushort *)(DAT_0800179c + 0x2e) +
          (uint)*(ushort *)(DAT_0800179c + 0x30);
  uVar10 = (uint)(iVar9 * 0x10000) >> 0x12;
  *(ushort *)(iVar2 + 0xb6) = (ushort)iVar9 >> 2;
  if ((0x8b9 < uVar10) || (uVar10 < 0x64f)) {
    puVar3[5] = 1;
    *puVar4 = (ushort)(((uint)*puVar4 << 0x11) >> 0x11);
  }
  sVar7 = 0x10;
  iVar9 = 0;
  sVar6 = *(short *)(iVar2 + 0xb8);
  sVar1 = *(short *)(iVar2 + 0xba);
  iVar12 = 0;
  do {
    if (puVar3[3] != '\0') {
      sVar7 = sVar7 + -1;
      puVar3[3] = 0;
      iVar9 = iVar9 + sVar6;
      iVar12 = iVar12 + sVar1;
    }
  } while (sVar7 != 0);
  uVar10 = (uint)(iVar9 << 0xc) >> 0x10;
  *puVar13 = (short)((uint)(iVar9 << 0xc) >> 0x10);
  uVar11 = (uint)(iVar12 << 0xc) >> 0x10;
  *(short *)(iVar2 + 0xae) = (short)((uint)(iVar12 << 0xc) >> 0x10);
  if ((((0x8b9 < uVar10) || (uVar10 < 0x64f)) || (0x8b9 < uVar11)) || (uVar11 < 0x64f)) {
    puVar3[4] = 1;
    *puVar5 = (ushort)(((uint)*puVar5 << 0x11) >> 0x11);
  }
  sVar7 = 0x10;
  iVar9 = 0;
  sVar6 = *(short *)(iVar2 + 0xbc);
  sVar1 = *(short *)(iVar2 + 0xbe);
  iVar12 = 0;
  do {
    if (puVar3[3] != '\0') {
      sVar7 = sVar7 + -1;
      puVar3[3] = 0;
      iVar9 = iVar9 + sVar6;
      iVar12 = iVar12 + sVar1;
    }
  } while (sVar7 != 0);
  uVar10 = (uint)(iVar9 << 0xc) >> 0x10;
  *(short *)(iVar2 + 0xb0) = (short)((uint)(iVar9 << 0xc) >> 0x10);
  uVar11 = (uint)(iVar12 << 0xc) >> 0x10;
  *(short *)(iVar2 + 0xb2) = (short)((uint)(iVar12 << 0xc) >> 0x10);
  if (((0x8b9 < uVar10) || (uVar10 < 0x64f)) || ((0x8b9 < uVar11 || (uVar11 < 0x64f)))) {
    puVar3[5] = 1;
    *puVar4 = (ushort)(((uint)*puVar4 << 0x11) >> 0x11);
  }
  *puVar4 = (ushort)(((uint)*puVar4 << 0x11) >> 0x11);
  *puVar5 = (ushort)(((uint)*puVar5 << 0x11) >> 0x11);
  uVar8 = FUN_080024c8(DAT_080017ac);
  iVar2 = DAT_08001798;
  pbVar14 = (byte *)(DAT_08001798 + 0x80);
  *(undefined2 *)pbVar14 = uVar8;
  uVar8 = FUN_080024c8(DAT_080017ac + 2);
  *(undefined2 *)(iVar2 + 0x82) = uVar8;
  uVar8 = FUN_080024c8(DAT_080017ac + 4);
  *(undefined2 *)(iVar2 + 0x84) = uVar8;
  uVar8 = FUN_080024c8(DAT_080017ac + 6);
  *(undefined2 *)(iVar2 + 0x86) = uVar8;
  uVar8 = FUN_080024c8(DAT_080017ac + 8);
  *(undefined2 *)(iVar2 + 0x88) = uVar8;
  uVar8 = FUN_080024c8(DAT_080017ac + 10);
  *(undefined2 *)(iVar2 + 0x8a) = uVar8;
  *(ushort *)(puVar3 + 0x18) = (ushort)*pbVar14 * 0x100 + (*(ushort *)(iVar2 + 0x84) >> 8) + 0x1212;
  *(ushort *)(puVar3 + 0x1a) =
       (ushort)*(byte *)(iVar2 + 0x86) * 0x100 + (*(ushort *)(iVar2 + 0x88) >> 8) + 0x2121;
  if ((int)*(short *)(puVar3 + 0x10) == iVar15 + 0x300) {
    *(undefined2 *)(puVar3 + 0x10) = 0;
    FUN_08001184();
    FUN_0800113c();
  }
  *puVar3 = 1;
  puVar3[8] = 0;
  return;
}



/* ----------------------------------------
 * FUN_080017b4 @ 0x80017b4
 * Unknown function
 * ---------------------------------------- */

void FUN_080017b4(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  
  iVar3 = DAT_0800187c;
  uVar2 = DAT_08001858;
  if (*DAT_08001854 == '\0') {
    if (*DAT_0800185c == '\0') {
      if (*DAT_08001860 == '\0') {
        if (*DAT_08001864 == '\0') {
          if (*DAT_08001868 == '\0') {
            if (*DAT_0800186c == '\0') {
              if (*DAT_08001870 == '\0') {
                if (*DAT_08001874 == '\0') {
                  if (*DAT_08001878 == '\0') {
                    FUN_080014d6(DAT_08001858,4);
                    return;
                  }
                  bVar4 = 9;
                }
                else {
                  bVar4 = 6;
                }
              }
              else {
                bVar4 = 5;
              }
            }
            else {
              bVar4 = 4;
            }
          }
          else {
            bVar4 = 3;
          }
        }
        else {
          bVar4 = 2;
        }
      }
      else {
        bVar4 = 1;
      }
    }
    else {
      bVar4 = 8;
    }
  }
  else {
    bVar4 = 7;
  }
  cVar1 = *(char *)(DAT_0800187c + 7);
  if ((cVar1 == '\0') &&
     (bVar5 = *(char *)(DAT_0800187c + 6) + 1, *(byte *)(DAT_0800187c + 6) = bVar5, bVar4 < bVar5))
  {
    *(undefined1 *)(iVar3 + 6) = 0;
  }
  if ((*(byte *)(iVar3 + 6) < bVar4) && (cVar1 != '\0')) {
    FUN_080014da(uVar2,4);
  }
  else {
    FUN_080014d6(uVar2,4);
  }
  *(byte *)(iVar3 + 7) = *(byte *)(iVar3 + 7) ^ 1;
  return;
}



/* ----------------------------------------
 * FUN_08001884 @ 0x8001884
 * Unknown function
 * ---------------------------------------- */

void FUN_08001884(void)

{
  undefined4 in_r3;
  undefined4 local_8;
  
  local_8 = in_r3;
  FUN_08001910(0x500);
  local_8 = 0x1020119;
  FUN_080018ac(&local_8);
  return;
}



/* ----------------------------------------
 * FUN_080018ac @ 0x80018ac
 * Unknown function
 * ---------------------------------------- */

void FUN_080018ac(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = *param_1;
  if (param_1[3] != 0) {
    uVar2 = 0x700 - (*DAT_08001908 & 0x700) >> 8;
    *(char *)((uint)bVar1 + DAT_0800190c) =
         (char)(((uint)param_1[2] & 0xfU >> (uVar2 & 0xff) | (uint)param_1[1] << (4 - uVar2 & 0xff))
               << 4);
    *(int *)((uint)(*param_1 >> 5) * 4 + -0x1fff1f00) = 1 << (*param_1 & 0x1f);
    return;
  }
  *(int *)((uint)(bVar1 >> 5) * 4 + -0x1fff1e80) = 1 << (bVar1 & 0x1f);
  return;
}



/* ----------------------------------------
 * FUN_08001910 @ 0x8001910
 * Unknown function
 * ---------------------------------------- */

void FUN_08001910(uint param_1)

{
  *DAT_08001920 = param_1 | DAT_0800191c;
  return;
}



/* ----------------------------------------
 * FUN_08001928 @ 0x8001928
 * Unknown function
 * ---------------------------------------- */

void FUN_08001928(void)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  uint *puVar6;
  char *pcVar7;
  int *piVar8;
  undefined2 *puVar9;
  undefined4 *puVar10;
  short *psVar11;
  byte *pbVar12;
  uint *puVar13;
  short sVar14;
  undefined4 uVar15;
  int iVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  uint uVar19;
  uint uVar20;
  undefined4 uVar21;
  undefined4 in_r3;
  char cVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  
  pcVar7 = DAT_08001d1c;
  puVar6 = DAT_08001d18;
  *DAT_08001d18 = 0;
  puVar6[1] = 0;
  puVar6[2] = 0;
  piVar8 = DAT_08001d24;
  if (*pcVar7 == '\0' && *DAT_08001d20 == '\0') {
    uVar15 = FUN_08005820(((uint)*DAT_08001d28 * 10) / 100 + 0x3c);
    *DAT_08001d2c = uVar15;
    puVar9 = DAT_08001d34;
    bVar1 = *DAT_08001d30;
    *DAT_08001d34 = (short)(0x798 / bVar1);
    if (0x144 < 0x798 / bVar1) {
      *puVar9 = 0x144;
    }
    uVar15 = FUN_08005820(*DAT_08001d38);
    iVar16 = FUN_08005634(uVar15,DAT_08001d3c);
    *piVar8 = iVar16;
    if (iVar16 < 0x3f000001) {
      *piVar8 = 0x3f000000;
    }
  }
  pcVar7 = DAT_08001d50;
  iVar16 = DAT_08001d44;
  cVar22 = *(char *)(DAT_08001d40 + 0x3b);
  cVar5 = *(char *)(DAT_08001d44 + 0x3b);
  if (cVar22 == cVar5) {
    *DAT_08001d48 = 0xffff;
  }
  else {
    uVar19 = (*(int *)(DAT_08001d40 + 8) + *(int *)(DAT_08001d44 + 8)) * 0x8000;
    uVar20 = uVar19 >> 0x10;
    *DAT_08001d48 = (short)(uVar19 >> 0x10);
    cVar2 = *pcVar7;
    cVar3 = *DAT_08001d4c;
    cVar4 = *DAT_08001d54;
    if ((((uVar20 < 0xa8) || (cVar2 != '\0')) || (cVar3 != '\0')) || (cVar4 != '\0')) {
      puVar6[2] = DAT_08001d58;
      if ((cVar2 == '\0' && cVar3 == '\0') && cVar4 == '\0') goto LAB_08001a18;
      *DAT_08001d68 = DAT_08001d64;
      uVar15 = DAT_08001d6c;
    }
    else {
      if (uVar20 < 0x170) {
        FUN_080057f0(0x170 - uVar20);
        uVar23 = FUN_080054f4();
        FUN_08005124((int)uVar23,(int)((ulonglong)uVar23 >> 0x20),DAT_08001d5c,DAT_08001d60,in_r3);
        uVar19 = FUN_08004c90();
        puVar6[2] = uVar19;
      }
LAB_08001a18:
      *DAT_08001d68 = DAT_08001d70;
      uVar15 = DAT_08001d74;
    }
    *DAT_08001d78 = uVar15;
  }
  if ((cVar22 == '\x01') && (cVar5 == '\0')) {
    puVar6[2] = puVar6[2] ^ 0x80000000;
  }
  uVar21 = *DAT_08001d7c;
  uVar15 = FUN_08005aac(puVar6[2]);
  uVar17 = FUN_080058b0(*DAT_08001d78,*DAT_08001d80);
  uVar18 = FUN_080058b0(*DAT_08001d68,uVar15);
  uVar18 = FUN_0800554c(uVar18,uVar21);
  uVar17 = FUN_0800554c(uVar18,uVar17);
  *DAT_08001d7c = uVar17;
  puVar10 = DAT_08001d84;
  *DAT_08001d80 = uVar15;
  uVar15 = *puVar10;
  uVar19 = FUN_0800554c(uVar17);
  puVar10 = DAT_08001d88;
  *puVar6 = uVar19;
  uVar19 = FUN_0800554c(uVar17,*puVar10);
  psVar11 = DAT_08001d8c;
  puVar6[1] = uVar19;
  sVar14 = *psVar11;
  if (cVar22 == cVar5) {
    if (0 < sVar14) goto LAB_08001acc;
joined_r0x08001abe:
    if (sVar14 < 0) {
LAB_08001ad2:
      *psVar11 = sVar14 + 1;
    }
  }
  else {
    if ((*(char *)(DAT_08001d40 + 0x16) == '\0') && (*(char *)(iVar16 + 0x16) == '\0')) {
      if (sVar14 <= *DAT_08001d90) {
        if (sVar14 < *DAT_08001d90) goto LAB_08001ad2;
        goto LAB_08001ad4;
      }
    }
    else if (sVar14 < 1) goto joined_r0x08001abe;
LAB_08001acc:
    *psVar11 = sVar14 + -1;
  }
LAB_08001ad4:
  sVar14 = FUN_080057b8(uVar15);
  uVar19 = FUN_08003fda((int)sVar14);
  pbVar12 = DAT_08001d94;
  if (uVar19 < 0x87) {
LAB_08001b24:
    *pbVar12 = 0;
  }
  else {
    sVar14 = FUN_080057b8(*puVar10);
    uVar19 = FUN_08003fda((int)sVar14);
    pcVar7 = DAT_08001d98;
    if (uVar19 < 0x87) goto LAB_08001b24;
    if (*DAT_08001d98 == '\0') {
      if (*pbVar12 < 0x59) {
        *pbVar12 = *pbVar12 + 1;
      }
      else {
        *DAT_08001d9c = (ushort)(((uint)*DAT_08001d9c << 0x11) >> 0x11);
        *DAT_08001da0 = (ushort)(((uint)*DAT_08001da0 << 0x11) >> 0x11);
        *pcVar7 = '\x01';
      }
    }
  }
  puVar13 = DAT_08001da8;
  iVar16 = DAT_08001da4;
  cVar22 = *DAT_08001d1c;
  if (cVar22 == '\0') {
    uVar19 = *puVar6 ^ 0x80000000;
LAB_08001b64:
    *puVar13 = uVar19;
  }
  else {
    if (DAT_08001da4 < (int)*DAT_08001da8) {
      uVar23 = FUN_080054f4();
      FUN_08005320((int)uVar23,(int)((ulonglong)uVar23 >> 0x20),DAT_08001dac,DAT_08001db0);
LAB_08001b60:
      uVar19 = FUN_08004c90();
      goto LAB_08001b64;
    }
    if (DAT_08001db4 <= *DAT_08001da8) {
      uVar23 = FUN_080054f4();
      FUN_08004cf4((int)uVar23,(int)((ulonglong)uVar23 >> 0x20),DAT_08001dac,DAT_08001db0);
      goto LAB_08001b60;
    }
    uVar19 = 0;
    *DAT_08001da8 = 0;
  }
  uVar19 = FUN_0800554c(*puVar6,uVar19);
  *puVar6 = uVar19;
  puVar13 = DAT_08001db8;
  cVar5 = *DAT_08001d20;
  if (cVar5 == '\0') {
    uVar20 = puVar6[1] ^ 0x80000000;
LAB_08001bb8:
    *puVar13 = uVar20;
  }
  else {
    if (iVar16 < (int)*DAT_08001db8) {
      uVar23 = FUN_080054f4();
      FUN_08005320((int)uVar23,(int)((ulonglong)uVar23 >> 0x20),DAT_08001dac,DAT_08001db0);
LAB_08001bb4:
      uVar20 = FUN_08004c90();
      goto LAB_08001bb8;
    }
    if (DAT_08001db4 <= *DAT_08001db8) {
      uVar23 = FUN_080054f4();
      FUN_08004cf4((int)uVar23,(int)((ulonglong)uVar23 >> 0x20),DAT_08001dac,DAT_08001db0);
      goto LAB_08001bb4;
    }
    uVar20 = 0;
    *DAT_08001db8 = 0;
  }
  uVar20 = FUN_0800554c(puVar6[1],uVar20);
  puVar6[1] = uVar20;
  uVar15 = DAT_08001dc4;
  if (*DAT_08001dbc == '\0') {
    if ((cVar22 == '\0') || (cVar5 == '\0')) goto LAB_08001e40;
    if ((uVar19 < DAT_08001dc0) || (cVar22 = DAT_08001dc0 <= uVar20, !(bool)cVar22)) {
      if ((0x7fffff < (int)uVar19) && (cVar22 = 0x7fffff < uVar20, 0x7fffff < (int)uVar20)) {
        FUN_08005a48(uVar20,uVar19);
        if (cVar22 == '\0') goto LAB_08001de4;
        FUN_08005848(puVar6[1],*puVar6);
        goto joined_r0x08001e22;
      }
      iVar16 = *piVar8;
      uVar19 = FUN_080058b0(iVar16,uVar19);
      *puVar6 = uVar19;
      uVar19 = FUN_080058b0(iVar16,uVar20);
    }
    else {
      FUN_08005848(uVar20,uVar19);
      if (cVar22 != '\0') {
        FUN_08005a48(puVar6[1],*puVar6);
joined_r0x08001e22:
        if (cVar22 != '\0') goto LAB_08001e40;
        uVar19 = puVar6[1];
        uVar15 = FUN_08005aac(*puVar6);
        uVar15 = FUN_080058b0(uVar15,*piVar8);
        uVar19 = FUN_0800554c(uVar15,uVar19);
        goto LAB_08001e3a;
      }
LAB_08001de4:
      uVar19 = *puVar6;
      uVar15 = FUN_08005aac(puVar6[1]);
      uVar15 = FUN_080058b0(uVar15,*piVar8);
      uVar19 = FUN_0800554c(uVar15,uVar19);
    }
LAB_08001e3e:
    puVar6[1] = uVar19;
  }
  else {
    if ((cVar22 == '\0') || (cVar5 == '\0')) goto LAB_08001e40;
    if ((uVar19 < DAT_08001dc0) || (cVar22 = DAT_08001dc0 <= uVar20, !(bool)cVar22)) {
      if (((int)uVar19 < 0x800000) || (cVar22 = 0x7fffff < uVar20, (int)uVar20 < 0x800000)) {
        uVar23 = FUN_080054f4(uVar19);
        uVar24 = FUN_080054f4(*piVar8);
        uVar24 = FUN_08005124((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),0x33333333,uVar15);
        uVar15 = (undefined4)((ulonglong)uVar24 >> 0x20);
        FUN_08005124((int)uVar24,uVar15,(int)uVar23,(int)((ulonglong)uVar23 >> 0x20));
        uVar19 = FUN_08004c90();
        *puVar6 = uVar19;
        uVar23 = FUN_080054f4(uVar20);
        FUN_08005124((int)uVar23,(int)((ulonglong)uVar23 >> 0x20),(int)uVar24,uVar15);
        uVar19 = FUN_08004c90();
        puVar6[1] = uVar19;
        goto LAB_08001e40;
      }
      FUN_08005a48(uVar20,uVar19);
      if (cVar22 == '\0') {
        uVar19 = *puVar6;
        uVar23 = FUN_080054f4();
        uVar17 = FUN_08005aac(puVar6[1],uVar19);
        FUN_080058b0(uVar17,*piVar8);
        uVar24 = FUN_080054f4();
        uVar24 = FUN_08005124((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),0x33333333,uVar15);
        goto LAB_08001cba;
      }
      FUN_08005848(puVar6[1],*puVar6);
    }
    else {
      FUN_08005848(uVar20,uVar19);
      if (cVar22 == '\0') {
        uVar19 = *puVar6;
        uVar23 = FUN_080054f4();
        uVar17 = FUN_08005aac(puVar6[1],uVar19);
        FUN_080058b0(uVar17,*piVar8);
        uVar24 = FUN_080054f4();
        uVar24 = FUN_08005124((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),0x33333333,uVar15);
LAB_08001cba:
        FUN_08004cf4((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),(int)uVar23,
                     (int)((ulonglong)uVar23 >> 0x20));
        uVar19 = FUN_08004c90();
        goto LAB_08001e3e;
      }
      FUN_08005a48(puVar6[1],*puVar6);
    }
    if (cVar22 != '\0') goto LAB_08001e40;
    uVar19 = puVar6[1];
    uVar23 = FUN_080054f4();
    uVar17 = FUN_08005aac(*puVar6,uVar19);
    FUN_080058b0(uVar17,*piVar8);
    uVar24 = FUN_080054f4();
    uVar24 = FUN_08005124((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),0x33333333,uVar15);
    FUN_08004cf4((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),(int)uVar23,
                 (int)((ulonglong)uVar23 >> 0x20));
    uVar19 = FUN_08004c90();
LAB_08001e3a:
    *puVar6 = uVar19;
  }
LAB_08001e40:
  *DAT_08001e6c = *puVar6;
  *DAT_08001e70 = puVar6[1];
  return;
}



/* ----------------------------------------
 * FUN_08001e74 @ 0x8001e74
 * Unknown function
 * ---------------------------------------- */

void FUN_08001e74(void)

{
  ushort uVar1;
  ushort *puVar2;
  char *pcVar3;
  int iVar4;
  ushort *puVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  short sVar9;
  undefined1 *puVar10;
  int iVar11;
  uint uVar12;
  
  puVar2 = DAT_08001fec;
  uVar12 = ((uint)DAT_08001fe8[3] +
           (uint)*DAT_08001fe8 + (uint)DAT_08001fe8[1] + (uint)DAT_08001fe8[2]) * 0x10000 >> 0x12;
  if (*DAT_08001fec < 1000) {
    *DAT_08001fec = *DAT_08001fec + 1;
  }
  pcVar8 = DAT_08002008;
  puVar10 = DAT_08002004;
  pcVar7 = DAT_08002000;
  pcVar6 = DAT_08001ffc;
  puVar5 = DAT_08001ff8;
  iVar4 = DAT_08001ff4;
  pcVar3 = DAT_08001ff0;
  if (*DAT_08001ff0 == '\0') {
    if (uVar12 < 0x4d9) {
      *DAT_0800200c = 0;
      *pcVar3 = '\x01';
      puVar10 = DAT_08002014;
    }
    else {
      puVar10 = DAT_08002010;
      if (*DAT_0800200c < 0x5dc) {
        *DAT_0800200c = *DAT_0800200c + 1;
        goto LAB_08001f92;
      }
    }
    *puVar10 = 1;
  }
  else {
    uVar1 = *DAT_08001ff8;
    if (uVar12 < 0x4d9) {
      if (((6 < uVar1) && (*DAT_08001ffc == '\0')) && (*DAT_08002000 == '\0')) {
        if (*puVar2 < 800) {
          *DAT_0800201c = *DAT_0800201c ^ 1;
          *DAT_08002020 = 1;
          *puVar2 = 800;
        }
        else {
          *DAT_08002004 = 1;
          sVar9 = 200;
          do {
            if (*pcVar8 != '\0') {
              sVar9 = sVar9 + -1;
              *pcVar8 = '\0';
            }
          } while (sVar9 != 0);
          *puVar10 = 0;
          FUN_080014d6(DAT_08002018,0x20);
        }
      }
      *puVar5 = 0;
    }
    else if (uVar1 < 0x1f5) {
      *DAT_08001ff8 = uVar1 + 1;
    }
    if (((*(char *)(DAT_08002024 + 0x16) == '\0') || (*(char *)(DAT_08002028 + 0x16) == '\0')) ||
       (((((((((*DAT_0800202c == '\0' && *DAT_08002030 == '\0') && *DAT_08002034 == '\0') &&
             *DAT_08002038 == '\0') && *DAT_0800203c == '\0') && *DAT_08002040 == '\0') &&
          *DAT_08002044 == '\0') && *DAT_08002048 == '\0') && *DAT_0800204c == '\0' &&
        (*pcVar7 != '\0' || *pcVar6 != '\0')))) {
      *(undefined4 *)(iVar4 + 0x14) = 0;
    }
    else {
      uVar12 = *(uint *)(iVar4 + 0x14);
      if ((uint)*DAT_08002058 * 0x7271 < uVar12 || (uint)*DAT_08002058 * 0x7271 - uVar12 == 0) {
        if (*DAT_0800205c == '\0') {
          *puVar10 = 1;
          sVar9 = 200;
          do {
            if (*pcVar8 != '\0') {
              sVar9 = sVar9 + -1;
              *pcVar8 = '\0';
            }
          } while (sVar9 != 0);
          *puVar10 = 0;
        }
        FUN_080014d6(DAT_08002018,0x20);
      }
      else {
        *(uint *)(iVar4 + 0x14) = uVar12 + 1;
      }
    }
  }
LAB_08001f92:
  uVar12 = DAT_08002050;
  iVar11 = *(int *)(iVar4 + 0x18) + 1;
  *(int *)(iVar4 + 0x18) = iVar11;
  *DAT_08002054 = (short)((uint)(iVar11 * 0x800) / uVar12);
  return;
}



/* ----------------------------------------
 * delay_us @ 0x8002060
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void delay_us(uint param_1)

{
  *(uint *)(DAT_08002070 + 4) = *(uint *)(DAT_08002070 + 4) & 0xffff3fff | param_1;
  return;
}



/* ----------------------------------------
 * FUN_08002074 @ 0x8002074
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_08002074(uint param_1,int param_2)

{
  if (param_2 == 0) {
    param_1 = *(uint *)(DAT_08002088 + 0x14) & ~param_1;
  }
  else {
    param_1 = *(uint *)(DAT_08002088 + 0x14) | param_1;
  }
  *(uint *)(DAT_08002088 + 0x14) = param_1;
  return;
}



/* ----------------------------------------
 * FUN_0800208c @ 0x800208c
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_0800208c(uint param_1,int param_2)

{
  if (param_2 == 0) {
    param_1 = *(uint *)(DAT_080020a0 + 0x1c) & ~param_1;
  }
  else {
    param_1 = *(uint *)(DAT_080020a0 + 0x1c) | param_1;
  }
  *(uint *)(DAT_080020a0 + 0x1c) = param_1;
  return;
}



/* ----------------------------------------
 * FUN_080020a4 @ 0x80020a4
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_080020a4(uint param_1,int param_2)

{
  if (param_2 == 0) {
    param_1 = *(uint *)(DAT_080020b8 + 0x10) & ~param_1;
  }
  else {
    param_1 = *(uint *)(DAT_080020b8 + 0x10) | param_1;
  }
  *(uint *)(DAT_080020b8 + 0x10) = param_1;
  return;
}



/* ----------------------------------------
 * FUN_080020bc @ 0x80020bc
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_080020bc(uint param_1,int param_2)

{
  if (param_2 == 0) {
    param_1 = *(uint *)(DAT_080020d0 + 0x18) & ~param_1;
  }
  else {
    param_1 = *(uint *)(DAT_080020d0 + 0x18) | param_1;
  }
  *(uint *)(DAT_080020d0 + 0x18) = param_1;
  return;
}



/* ----------------------------------------
 * rcc_clock_enable @ 0x80020d4
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void rcc_clock_enable(uint param_1,int param_2)

{
  if (param_2 == 0) {
    param_1 = *(uint *)(DAT_080020e8 + 0xc) & ~param_1;
  }
  else {
    param_1 = *(uint *)(DAT_080020e8 + 0xc) | param_1;
  }
  *(uint *)(DAT_080020e8 + 0xc) = param_1;
  return;
}



/* ----------------------------------------
 * FUN_080020ec @ 0x80020ec
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_080020ec(void)

{
  FUN_080022e8();
  FUN_080020bc(4,1);
  FUN_080020bc(8,1);
  FUN_080020bc(0x10,1);
  FUN_080020bc(1);
  FUN_080020bc(0x800);
  FUN_080020bc(0x2000);
  FUN_080020bc(0x200);
  FUN_080020bc(0x400);
  FUN_080020bc(0x8000);
  FUN_08002074(1);
  FUN_0800208c(0x20000);
  FUN_0800208c(0x40000);
  return;
}



/* ----------------------------------------
 * FUN_08002158 @ 0x8002158
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_08002158(void)

{
  uint *puVar1;
  
  puVar1 = DAT_0800218c;
  *DAT_0800218c = *DAT_0800218c | 1;
  puVar1[1] = puVar1[1] & DAT_08002190;
  *puVar1 = *puVar1 & DAT_08002194;
  *puVar1 = *puVar1 & 0xfffbffff;
  puVar1[1] = puVar1[1] & 0xff80ffff;
  puVar1[2] = 0x9f0000;
  return;
}



/* ----------------------------------------
 * FUN_08002198 @ 0x8002198
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_08002198(uint *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = DAT_0800221c;
  uVar3 = *(uint *)(DAT_0800221c + 4) & 0xc;
  if (((uVar3 == 0) || (uVar3 == 4)) || (uVar3 != 8)) {
    *param_1 = DAT_08002220;
  }
  else {
    if (((*(uint *)(DAT_0800221c + 4) & 0x10000) == 0) ||
       (uVar3 = DAT_08002220, *(int *)(DAT_0800221c + 4) << 0xe < 0)) {
      uVar3 = DAT_08002224;
    }
    *param_1 = uVar3 * (((*(uint *)(DAT_0800221c + 4) & 0x3c0000) >> 0x12) + 2);
  }
  iVar2 = DAT_08002228;
  uVar3 = *param_1 >> *(sbyte *)(DAT_08002228 + (*(uint *)(iVar1 + 4) >> 4 & 0xf));
  param_1[1] = uVar3;
  param_1[2] = uVar3 >> *(sbyte *)(iVar2 + (*(uint *)(iVar1 + 4) >> 8 & 7));
  uVar3 = uVar3 >> *(sbyte *)(iVar2 + (*(uint *)(iVar1 + 4) >> 0xb & 7));
  param_1[3] = uVar3;
  param_1[4] = uVar3 / *(byte *)(DAT_08002228 + -4 + (*(uint *)(iVar1 + 4) >> 0xe & 3));
  return;
}



/* ----------------------------------------
 * FUN_0800222c @ 0x800222c
 * Peripheral driver / HAL function
 * ---------------------------------------- */

bool FUN_0800222c(uint param_1)

{
  uint uVar1;
  
  if (param_1 >> 5 == 1) {
    uVar1 = *DAT_08002258;
  }
  else if (param_1 >> 5 == 2) {
    uVar1 = DAT_08002258[8];
  }
  else {
    uVar1 = DAT_08002258[9];
  }
  return (1 << (param_1 & 0x1f) & uVar1) != 0;
}



/* ----------------------------------------
 * FUN_0800225c @ 0x800225c
 * Peripheral driver / HAL function
 * ---------------------------------------- */

uint FUN_0800225c(void)

{
  return *(uint *)(DAT_08002268 + 4) & 0xc;
}



/* ----------------------------------------
 * FUN_0800226c @ 0x800226c
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_0800226c(uint param_1)

{
  *(uint *)(DAT_0800227c + 4) = *(uint *)(DAT_0800227c + 4) & 0xffffff0f | param_1;
  return;
}



/* ----------------------------------------
 * FUN_08002280 @ 0x8002280
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_08002280(undefined4 param_1)

{
  *DAT_08002288 = param_1;
  return;
}



/* ----------------------------------------
 * FUN_0800228c @ 0x800228c
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_0800228c(uint param_1)

{
  *(uint *)(DAT_0800229c + 4) = *(uint *)(DAT_0800229c + 4) & 0xfffff8ff | param_1;
  return;
}



/* ----------------------------------------
 * FUN_080022a0 @ 0x80022a0
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_080022a0(int param_1)

{
  *(uint *)(DAT_080022b0 + 4) = *(uint *)(DAT_080022b0 + 4) & 0xffffc7ff | param_1 << 3;
  return;
}



/* ----------------------------------------
 * FUN_080022b4 @ 0x80022b4
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_080022b4(undefined4 param_1)

{
  *(undefined4 *)(DAT_080022bc + 0x60) = param_1;
  return;
}



/* ----------------------------------------
 * FUN_080022c0 @ 0x80022c0
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_080022c0(uint param_1,uint param_2)

{
  *(uint *)(DAT_080022d0 + 4) = param_1 | param_2 | *(uint *)(DAT_080022d0 + 4) & 0xffc0ffff;
  return;
}



/* ----------------------------------------
 * FUN_080022d4 @ 0x80022d4
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_080022d4(uint param_1)

{
  *(uint *)(DAT_080022e4 + 4) = *(uint *)(DAT_080022e4 + 4) & 0xfffffffc | param_1;
  return;
}



/* ----------------------------------------
 * FUN_080022e8 @ 0x80022e8
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_080022e8(void)

{
  int iVar1;
  
  FUN_08002158();
  FUN_08002280(1);
  do {
    iVar1 = FUN_0800222c(0x21);
  } while (iVar1 == 0);
  FUN_08001084(0x10);
  FUN_080010ec(2);
  FUN_0800226c(0);
  FUN_0800228c(0x400);
  FUN_080022a0(0);
  FUN_080022c0(0,0x380000);
  FUN_080022b4(1);
  do {
    iVar1 = FUN_0800222c(0x39);
  } while (iVar1 == 0);
  FUN_080022d4(2);
  do {
    iVar1 = FUN_0800225c();
  } while (iVar1 != 8);
  return;
}



/* ----------------------------------------
 * FUN_08002348 @ 0x8002348
 * Peripheral driver / HAL function
 * ---------------------------------------- */

uint FUN_08002348(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_08002374;
  uVar1 = FUN_080014c8(DAT_08002374,0x400);
  iVar2 = FUN_080014c8(iVar3,iVar3 >> 0x13);
  iVar3 = FUN_080014c8(iVar3,iVar3 >> 0x12);
  return uVar1 | iVar2 << 1 | iVar3 << 2;
}



/* ----------------------------------------
 * hall_read_state @ 0x8002378
 * Peripheral driver / HAL function
 * ---------------------------------------- */

uint hall_read_state(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = DAT_080023a0;
  uVar2 = FUN_080014c8(DAT_080023a0,0x20);
  iVar3 = FUN_080014c8(uVar1,0x40);
  iVar4 = FUN_080014c8(uVar1,0x80);
  return uVar2 | iVar3 << 1 | iVar4 << 2;
}



/* ----------------------------------------
 * FUN_080023a4 @ 0x80023a4
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_080023a4(void)

{
  byte bVar1;
  byte bVar2;
  undefined1 *puVar3;
  int iVar4;
  byte *pbVar5;
  char cVar6;
  
  iVar4 = DAT_080024a0;
  puVar3 = DAT_0800249c;
  cVar6 = *DAT_08002494;
  if (cVar6 == '\0') {
    cVar6 = *DAT_08002498;
  }
  if (cVar6 == '\x04') {
    bVar2 = *(byte *)(DAT_080024a0 + 0xe);
    *(byte *)(DAT_080024a0 + 0xe) = bVar2 + 1;
    if (8 < bVar2) {
      *puVar3 = 1;
      *(undefined1 *)(iVar4 + 10) = 0;
    }
  }
  else {
    if (*(byte *)(DAT_080024a0 + 10) < 0x50) {
      *(byte *)(DAT_080024a0 + 10) = *(byte *)(DAT_080024a0 + 10) + 1;
    }
    else {
      *DAT_0800249c = 0;
    }
    *(undefined1 *)(iVar4 + 0xe) = 0;
  }
  pbVar5 = DAT_080024b4;
  bVar2 = *DAT_080024b4;
  if ((((*DAT_080024a4 != '\0' || *DAT_080024a8 != '\0') || *DAT_080024ac != '\0') ||
       *DAT_080024b0 != '\0') && (bVar2 == 0)) {
    return;
  }
  bVar1 = *(byte *)(DAT_080024a0 + 3);
  if (cVar6 == '\x02') {
    if (bVar1 < 9) {
LAB_08002436:
      *(byte *)(iVar4 + 3) = bVar1 + 1;
    }
    else if (*(char *)(DAT_080024a0 + 9) == '\0') {
      *(undefined1 *)(iVar4 + 9) = 1;
      *pbVar5 = bVar2 ^ 1;
    }
  }
  else if (cVar6 == '\x01') {
    if (bVar1 < 9) goto LAB_08002436;
    if (*(char *)(DAT_080024a0 + 9) == '\0') {
      *(undefined1 *)(iVar4 + 9) = 1;
      *pbVar5 = 0;
    }
  }
  else {
    if (cVar6 != '\b') {
      if (*(byte *)(iVar4 + 8) < 0x50) {
        *(byte *)(iVar4 + 8) = *(byte *)(iVar4 + 8) + 1;
      }
      else {
        *(undefined1 *)(iVar4 + 8) = 0;
        *(undefined1 *)(iVar4 + 0xc) = 0;
        *(undefined1 *)(iVar4 + 9) = 0;
      }
      *(undefined2 *)(iVar4 + 0x10) = 0;
      *(undefined1 *)(iVar4 + 3) = 0;
      goto LAB_0800246c;
    }
    if (bVar1 < 9) goto LAB_08002436;
    if (*(char *)(iVar4 + 0xc) == '\0') {
      *DAT_080024b8 = *DAT_080024b8 ^ 1;
      puVar3 = DAT_080024bc;
      *(undefined1 *)(iVar4 + 0xc) = 1;
      *puVar3 = 1;
    }
  }
  *(undefined1 *)(iVar4 + 8) = 0;
LAB_0800246c:
  puVar3 = DAT_080024c4;
  if (*DAT_080024c0 == '\x01') {
    if (*(byte *)(iVar4 + 0xd) < 0x50) {
      *(byte *)(iVar4 + 0xd) = *(byte *)(iVar4 + 0xd) + 1;
      return;
    }
    if (*(char *)(iVar4 + 0xb) != '\0') {
      *DAT_080024c0 = '\0';
      *puVar3 = 0;
      return;
    }
  }
  else {
    *(undefined1 *)(iVar4 + 0xd) = 0;
  }
  return;
}



/* ----------------------------------------
 * FUN_080024c8 @ 0x80024c8
 * Peripheral driver / HAL function
 * ---------------------------------------- */

undefined4 FUN_080024c8(undefined4 *param_1)

{
  return *param_1;
}



/* ----------------------------------------
 * FUN_080024d0 @ 0x80024d0
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_080024d0(void)

{
  uint uVar1;
  ushort *puVar2;
  ushort *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined2 local_98;
  undefined2 local_96;
  undefined2 local_94;
  undefined2 local_92;
  undefined2 local_90;
  undefined2 local_8e;
  undefined2 local_8c;
  undefined2 local_8a;
  undefined2 local_88;
  undefined1 local_86;
  undefined1 local_85;
  undefined2 local_84;
  undefined2 local_82;
  undefined2 local_80;
  undefined2 local_7e;
  undefined2 local_7c;
  undefined2 local_7a;
  undefined2 local_78;
  undefined2 local_74;
  undefined2 local_72;
  undefined2 local_70;
  undefined2 local_6e;
  undefined1 local_6c;
  int local_68;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined1 local_38;
  undefined1 local_37;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined1 local_2c;
  
  puVar2 = DAT_08002964;
  FUN_08002e10(DAT_08002964);
  FUN_08003268(&local_74);
  local_74 = 3;
  local_72 = 0x40;
  local_70 = 0x200;
  local_6e = 0;
  local_6c = 1;
  FUN_080031cc(puVar2,&local_74);
  FUN_08002da8(puVar2,1);
  FUN_0800327a(puVar2,1);
  FUN_080031b0(puVar2,0x20);
  local_98 = 0x60;
  local_94 = 4;
  local_90 = 0;
  local_8e = 8;
  local_8c = 0;
  local_96 = 1;
  local_92 = 0;
  local_8a = 0x200;
  FUN_08002f90(puVar2,&local_98);
  FUN_0800301c(puVar2,&local_98);
  FUN_080030b0(puVar2,&local_98);
  local_98 = 0x70;
  local_92 = 0x1fd;
  local_96 = 1;
  local_90 = 0;
  local_8c = 0;
  FUN_08003138(puVar2,&local_98);
  FUN_08002dde(puVar2,1);
  FUN_08003010(puVar2,8);
  FUN_0800309c(puVar2,8);
  FUN_0800312c(puVar2,8);
  FUN_0800319c(puVar2,8);
  local_80 = 0x100;
  local_84 = 0;
  local_7c = 0x1000;
  local_82 = 0;
  local_7e = 0x20;
  local_7a = 0;
  local_78 = 0;
  FUN_08002dbc(puVar2,&local_84);
  FUN_08002f80(puVar2,0x81,1);
  FUN_08002df2(puVar2,0x81);
  FUN_080031c0(puVar2,0);
  FUN_080031c4(puVar2,0);
  FUN_080031c8(puVar2,0);
  puVar3 = DAT_08002968;
  FUN_08002e10(DAT_08002968);
  FUN_08003268(&local_74);
  local_74 = 3;
  local_72 = 0x40;
  local_70 = 0x200;
  local_6e = 0;
  local_6c = 1;
  FUN_080031cc(puVar3,&local_74);
  FUN_08002da8(puVar3,1);
  FUN_0800327a(puVar3,1);
  FUN_080031b0(puVar3,0x20);
  local_98 = 0x60;
  local_94 = 4;
  local_90 = 0;
  local_8e = 8;
  local_8c = 0;
  local_96 = 1;
  local_92 = 0;
  local_8a = 0x200;
  FUN_08002f90(puVar3,&local_98);
  FUN_0800301c(puVar3,&local_98);
  FUN_080030b0(puVar3,&local_98);
  FUN_08002dde(puVar3,1);
  FUN_08003010(puVar3,8);
  FUN_0800309c(puVar3,8);
  FUN_0800312c(puVar3,8);
  local_80 = 0x100;
  local_84 = 0;
  local_7c = 0x1000;
  local_82 = 0;
  local_7e = 0x20;
  local_7a = 0;
  local_78 = 0;
  FUN_08002dbc(puVar3,&local_84);
  FUN_08002f80(puVar3,0x81,1);
  FUN_08002df2(puVar3,0x81);
  FUN_080031c0(puVar3,0);
  FUN_080031c4(puVar3,0);
  FUN_080031c8(puVar3,0);
  FUN_08002df8(puVar2,1);
  FUN_08002df8(puVar3,1);
  DAT_08002964[0x10] = DAT_08002964[0x10] | 0x555;
  DAT_08002968[0x10] = DAT_08002968[0x10] | 0x555;
  *puVar2 = *puVar2 | 1;
  *puVar3 = *puVar3 | 1;
  uVar1 = DAT_0800296c;
  local_88 = 0x780;
  local_86 = 3;
  local_85 = 0x18;
  gpio_config(DAT_0800296c,&local_88);
  local_88 = 0xe003;
  local_86 = 3;
  local_85 = 0x18;
  gpio_config(DAT_08002970,&local_88);
  uVar4 = DAT_08002974;
  local_88 = 0x1c0;
  local_86 = 3;
  local_85 = 0x18;
  gpio_config(DAT_08002974,&local_88);
  delay_us(0x8000);
  local_88 = 3;
  local_85 = 0;
  gpio_config(uVar1,&local_88);
  local_88 = 0x38;
  local_85 = 0;
  gpio_config(uVar4,&local_88);
  local_88 = 7;
  local_85 = 0;
  gpio_config(uVar4,&local_88);
  uVar1 = uVar1 >> 0xd | uVar1 << 0x13;
  FUN_08000e48(uVar1);
  local_68 = DAT_08002978;
  local_64 = DAT_0800297c;
  uStack_60 = 0;
  uStack_5c = 2;
  local_58 = 0;
  uStack_54 = 0x80;
  local_50 = 0x200;
  uStack_4c = 0x800;
  local_48 = 0x20;
  local_44 = 0x2000;
  uStack_40 = 0;
  adc_init(uVar1,&local_68);
  rcc_periph_enable(DAT_08002978 + -0x4c);
  uVar4 = DAT_08002980;
  rcc_periph_enable(DAT_08002980);
  FUN_080004f2(&local_3c);
  local_3c = 0x10000;
  local_38 = 1;
  local_37 = 0;
  local_34 = 0xe0000;
  uStack_30 = 0;
  local_2c = 2;
  FUN_0800037c(DAT_08002978 + -0x4c,&local_3c);
  FUN_0800037c(uVar4,&local_3c);
  FUN_0800040e(DAT_08002978 + -0x4c,2);
  FUN_0800040e(uVar4,2);
  FUN_080003c4(DAT_08002978 + -0x4c,0,1);
  FUN_080003c4(uVar4,0xd,1);
  FUN_080003c4(DAT_08002978 + -0x4c,0xf,2,1);
  FUN_080003c4(uVar4,0xe,2,1);
  FUN_0800041e(DAT_08002978 + -0x4c,10,1);
  FUN_0800041e(uVar4,0xb,1);
  FUN_0800041e(DAT_08002978 + -0x4c,0xc,2,1);
  FUN_0800041e(uVar4,1,2);
  timer_set_deadtime(DAT_08002978 + -0x4c,0x1000);
  timer_set_deadtime(uVar4,0x1000);
  timer_set_bdtr(DAT_08002978 + -0x4c,1);
  timer_set_bdtr(uVar4,1);
  FUN_0800032c(uVar4,1);
  timer_set_enable(DAT_08002978 + -0x4c,1);
  timer_set_enable(uVar4,1);
  FUN_08000fb4(2);
  adc_start(DAT_08002978 + -0x4c);
  iVar6 = DAT_08002978 + -0x4c;
  do {
    iVar5 = adc_check_busy(iVar6);
  } while (iVar5 != 0);
  adc_stop(iVar6);
  do {
    iVar5 = adc_check_ready(iVar6);
  } while (iVar5 != 0);
  adc_start(uVar4);
  do {
    iVar5 = adc_check_busy(uVar4);
  } while (iVar5 != 0);
  adc_stop(uVar4);
  do {
    iVar5 = adc_check_ready(uVar4);
  } while (iVar5 != 0);
  timer_set_output(iVar6,1);
  FUN_08000e30(uVar1,1);
  return;
}



/* ----------------------------------------
 * main_control_loop @ 0x8002984
 * Main while(1) loop - reads sensors, controls motors
 * ---------------------------------------- */

void main_control_loop(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  ushort *puVar13;
  ushort *puVar14;
  char *pcVar15;
  uint uVar16;
  int iVar17;
  undefined1 *puVar18;
  char *pcVar19;
  uint uVar20;
  bool bVar21;
  
  puVar18 = DAT_08002c18;
  iVar17 = DAT_08002c14;
  uVar16 = DAT_08002c10;
  pcVar15 = DAT_08002bd0;
  puVar14 = DAT_08002bcc;
  puVar13 = DAT_08002bc8;
  bVar21 = *DAT_08002bc4 == '\0';
  while (bVar21) {
    bVar21 = *DAT_08002bd4 == '\0';
    while( true ) {
      if (bVar21) goto LAB_08002b9a;
      bVar21 = *DAT_08002bd8 == '\0';
      if ((!bVar21) || (bVar21 = *DAT_08002bdc == '\0', !bVar21)) break;
      bVar21 = *DAT_08002be0 == '\0';
      if (!bVar21) {
        cVar1 = *DAT_08002be4;
        cVar2 = *DAT_08002bf0;
        cVar3 = *DAT_08002be8;
        cVar4 = *DAT_08002bec;
        cVar5 = *DAT_08002bf4;
        cVar6 = *DAT_08002bf8;
        cVar9 = *DAT_08002bfc;
        cVar10 = *DAT_08002c00;
        cVar11 = *DAT_08002c04;
        cVar12 = *DAT_08002c08;
        cVar7 = *DAT_08002c0c;
        cVar8 = *DAT_08002c1c;
        if ((cVar1 == '\x01') && (pcVar19 = DAT_08002c20, cVar3 == '\0')) {
LAB_08002a8a:
          *pcVar19 = '\0';
        }
        else if ((cVar3 == '\x01') && (cVar1 == '\x01')) {
          if (*DAT_08002c20 == '\0') {
            uVar20 = *DAT_08002c24;
            if ((((((((cVar4 == '\0' && cVar2 == '\0') && cVar5 == '\0') && cVar6 == '\0') &&
                   cVar9 == '\0') && cVar10 == '\0') && cVar11 == '\0') && cVar12 == '\0') &&
               (((uVar20 <= DAT_08002c10 && ((int)uVar20 <= DAT_08002c14)) ||
                (((DAT_08002c10 < uVar20 || (DAT_08002c14 < (int)uVar20)) && (cVar7 != '\0')))))) {
              *DAT_08002c20 = '\x01';
              if (*pcVar15 == '\0') {
                *puVar13 = *puVar13 | 0x8000;
              }
              if (cVar7 == '\0') {
                *puVar14 = *puVar14 | 0x8000;
              }
              *pcVar15 = '\x01';
              pcVar19 = DAT_08002c28;
              *puVar18 = 0;
              goto LAB_08002a8a;
            }
            if (((DAT_08002c10 <= uVar20) || (DAT_08002c14 <= (int)uVar20)) && (cVar7 == '\0')) {
              *DAT_08002c18 = 1;
            }
          }
        }
        else if (((cVar3 == '\0' && cVar1 == '\0') && (*DAT_08002c20 != '\0')) && (cVar8 == '\0')) {
          *DAT_08002c20 = '\0';
          *puVar13 = (ushort)(((uint)*puVar13 << 0x11) >> 0x11);
          *puVar14 = (ushort)(((uint)*puVar14 << 0x11) >> 0x11);
          *pcVar15 = '\0';
          *puVar18 = 0;
        }
        *DAT_08002be8 = cVar1;
        if (cVar8 == '\0') {
          if (((*DAT_08002c30 == '\0') && (*DAT_08002c2c != '\0')) && (cVar1 == '\0')) {
            *DAT_08002c2c = '\0';
            *puVar13 = (ushort)(((uint)*puVar13 << 0x11) >> 0x11);
            *puVar14 = (ushort)(((uint)*puVar14 << 0x11) >> 0x11);
            *DAT_08002c0c = '\0';
            *puVar18 = 0;
          }
          goto LAB_08002b8a;
        }
        pcVar19 = DAT_08002c2c;
        if (*DAT_08002c30 != '\0') {
          if (*DAT_08002c2c != '\0') goto LAB_08002b8a;
          uVar20 = *DAT_08002c34;
          if ((((((((cVar4 != '\0' || cVar2 != '\0') || cVar5 != '\0') || cVar6 != '\0') ||
                 cVar9 != '\0') || cVar10 != '\0') || cVar11 != '\0') || cVar12 != '\0') ||
             (((uVar16 < uVar20 || (iVar17 < (int)uVar20)) &&
              (((uVar20 <= uVar16 && ((int)uVar20 <= iVar17)) || (*pcVar15 == '\0')))))) {
            if (((uVar16 <= uVar20) || (iVar17 <= (int)uVar20)) && (*pcVar15 == '\0')) {
              *puVar18 = 1;
            }
            goto LAB_08002b8a;
          }
          *DAT_08002c2c = '\x01';
          if (*pcVar15 == '\0') {
            *puVar13 = *puVar13 | 0x8000;
          }
          pcVar15 = DAT_08002c0c;
          if (cVar7 == '\0') {
            *puVar14 = *puVar14 | 0x8000;
          }
          *pcVar15 = '\x01';
          pcVar19 = DAT_08002c28;
          *puVar18 = 0;
        }
        *pcVar19 = '\0';
LAB_08002b8a:
        if (cVar8 == '\0' && cVar1 == '\0') {
          *puVar18 = 0;
        }
        *DAT_08002c30 = cVar8;
        return;
      }
    }
  }
LAB_08002b9a:
  *DAT_08002c20 = '\0';
  *puVar13 = (ushort)(((uint)*puVar13 << 0x11) >> 0x11);
  pcVar19 = DAT_08002c2c;
  *pcVar15 = '\0';
  *pcVar19 = '\0';
  *puVar14 = (ushort)(((uint)*puVar14 << 0x11) >> 0x11);
  *DAT_08002c0c = '\0';
  return;
}



/* ----------------------------------------
 * FUN_08002c38 @ 0x8002c38
 * Peripheral driver / HAL function
 * ---------------------------------------- */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08002c38(int param_1)

{
  if (param_1 == 4) {
    _DAT_e000e010 = _DAT_e000e010 | 4;
  }
  else {
    _DAT_e000e010 = _DAT_e000e010 & 0xfffffffb;
  }
  return;
}



/* ----------------------------------------
 * FUN_08002c54 @ 0x8002c54
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_08002c54(void)

{
  uint *puVar1;
  
  puVar1 = DAT_08002c8c;
  *DAT_08002c8c = *DAT_08002c8c | 1;
  puVar1[1] = puVar1[1] & DAT_08002c90;
  *puVar1 = *puVar1 & DAT_08002c94;
  *puVar1 = *puVar1 & 0xfffbffff;
  puVar1[1] = puVar1[1] & 0xff80ffff;
  puVar1[2] = 0x9f0000;
  *DAT_08002c98 = (int)puVar1 << 0xf;
  return;
}



/* ----------------------------------------
 * FUN_08002c9c @ 0x8002c9c
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_08002c9c(void)

{
  ushort *puVar1;
  byte *pbVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined2 *puVar5;
  uint uVar6;
  
  puVar1 = DAT_08002d5c;
  if ((*DAT_08002d5c & 1) != 0) {
    FUN_080009fc(*DAT_08002d60);
    puVar3 = DAT_08002d68;
    pbVar2 = DAT_08002d64;
    if (*DAT_08002d64 < 0x10) {
      *DAT_08002d64 = *DAT_08002d64 + 1;
    }
    else {
      *DAT_08002d64 = 0;
      *puVar3 = 1;
    }
    puVar3 = DAT_08002d6c;
    if (pbVar2[1] < 3) {
      pbVar2[1] = pbVar2[1] + 1;
    }
    else {
      pbVar2[1] = 0;
      *puVar3 = 1;
    }
    pcVar4 = DAT_08002d70;
    if (*DAT_08002d70 != '\0') {
      FUN_08004664(DAT_08002d74);
      FUN_080041bc(DAT_08002d78);
      *DAT_08002d7c = *(undefined1 *)(DAT_08002d74 + 0xc);
      *DAT_08002d80 = *(undefined1 *)(DAT_08002d78 + 0xc);
    }
    FUN_0800150c(DAT_08002d88,DAT_08002d84);
    FUN_080014e0(DAT_08002d88,DAT_08002d8c);
    FUN_080004d4(DAT_08002d90,1);
    if (*pcVar4 != '\0') {
      FUN_08003290();
      FUN_08003398();
    }
    FUN_0800049c(DAT_08002d94);
    puVar5 = DAT_08002d94;
    uVar6 = (uint)pbVar2[1];
    *(undefined2 *)(DAT_08002d98 + uVar6 * 2) = DAT_08002d94[2];
    *(undefined2 *)(DAT_08002d9c + uVar6 * 2) = puVar5[1];
    *(undefined2 *)(DAT_08002da0 + uVar6 * 2) = *puVar5;
    *(undefined2 *)(DAT_08002da4 + uVar6 * 2) = puVar5[3];
    FUN_08003504();
    FUN_08003674();
    *puVar1 = 0xfffe;
    *puVar1 = 0xfffe;
  }
  return;
}



/* ----------------------------------------
 * timer_enable @ 0x8002da8
 * Enable timer counting
 * ---------------------------------------- */

void timer_enable(ushort *param_1,int param_2)

{
  ushort uVar1;
  
  if (param_2 == 0) {
    uVar1 = *param_1 & 0xff7f;
  }
  else {
    uVar1 = *param_1 | 0x80;
  }
  *param_1 = uVar1;
  return;
}



/* ----------------------------------------
 * FUN_08002dbc @ 0x8002dbc
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_08002dbc(int param_1,ushort *param_2)

{
  *(ushort *)(param_1 + 0x44) =
       *param_2 | param_2[1] | param_2[2] | param_2[3] | param_2[4] | param_2[5] | param_2[6];
  return;
}



/* ----------------------------------------
 * FUN_08002dde @ 0x8002dde
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_08002dde(int param_1,int param_2)

{
  ushort uVar1;
  
  if (param_2 == 0) {
    uVar1 = *(ushort *)(param_1 + 4) & 0xfffe;
  }
  else {
    uVar1 = *(ushort *)(param_1 + 4) | 1;
  }
  *(ushort *)(param_1 + 4) = uVar1;
  return;
}



/* ----------------------------------------
 * FUN_08002df2 @ 0x8002df2
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_08002df2(int param_1,ushort param_2)

{
  *(ushort *)(param_1 + 0x10) = ~param_2;
  return;
}



/* ----------------------------------------
 * FUN_08002df8 @ 0x8002df8
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_08002df8(int param_1,int param_2)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 0x44);
  if (param_2 == 0) {
    uVar1 = (ushort)(((uint)uVar1 << 0x11) >> 0x11);
  }
  else {
    uVar1 = uVar1 | 0x8000;
  }
  *(ushort *)(param_1 + 0x44) = uVar1;
  return;
}



/* ----------------------------------------
 * timer_init @ 0x8002e10
 * Initialize timer peripheral
 * ---------------------------------------- */

void timer_init(int param_1)

{
  if (param_1 == DAT_08002f40) {
    param_1 = param_1 >> 0x13;
    goto LAB_08002f2c;
  }
  if (param_1 == 0x40000000) {
    FUN_080020a4(1);
    param_1 = 1;
  }
  else if (param_1 == DAT_08002f44) {
    FUN_080020a4(2,1);
    param_1 = 2;
  }
  else if (param_1 == DAT_08002f48) {
    FUN_080020a4(4,1);
    param_1 = 4;
  }
  else if (param_1 == DAT_08002f4c) {
    FUN_080020a4(8,1);
    param_1 = 8;
  }
  else if (param_1 == DAT_08002f50) {
    FUN_080020a4(0x10,1);
    param_1 = 0x10;
  }
  else {
    if (param_1 != DAT_08002f54) {
      if (param_1 == DAT_08002f58) {
        param_1 = param_1 >> 0x11;
      }
      else if (param_1 == DAT_08002f5c) {
        param_1 = 0x80000;
      }
      else if (param_1 == DAT_08002f60) {
        param_1 = 0x100000;
      }
      else {
        if (param_1 != DAT_08002f64) {
          if (param_1 == DAT_08002f68) {
            FUN_080020a4(0x40,1);
            param_1 = 0x40;
          }
          else if (param_1 == DAT_08002f6c) {
            FUN_080020a4(0x80,1);
            param_1 = 0x80;
          }
          else {
            if (param_1 != DAT_08002f70) {
              if (param_1 == DAT_08002f74) {
                param_1 = 0x10000;
              }
              else if (param_1 == DAT_08002f78) {
                param_1 = 0x20000;
              }
              else {
                if (param_1 != DAT_08002f7c) {
                  return;
                }
                param_1 = 0x40000;
              }
              goto LAB_08002f2c;
            }
            param_1 = param_1 >> 0x16;
            FUN_080020a4(param_1,1);
          }
          goto LAB_08002f02;
        }
        param_1 = 0x200000;
      }
LAB_08002f2c:
      rcc_clock_enable(param_1,1);
      rcc_clock_enable(param_1,0);
      return;
    }
    FUN_080020a4(0x20,1);
    param_1 = 0x20;
  }
LAB_08002f02:
  FUN_080020a4(param_1,0);
  return;
}



/* ----------------------------------------
 * FUN_08002f80 @ 0x8002f80
 * Peripheral driver / HAL function
 * ---------------------------------------- */

void FUN_08002f80(int param_1,ushort param_2,int param_3)

{
  if (param_3 == 0) {
    param_2 = *(ushort *)(param_1 + 0xc) & ~param_2;
  }
  else {
    param_2 = *(ushort *)(param_1 + 0xc) | param_2;
  }
  *(ushort *)(param_1 + 0xc) = param_2;
  return;
}



/* ----------------------------------------
 * pwm_channel_config @ 0x8002f90
 * Configure PWM output channel
 * ---------------------------------------- */

void pwm_channel_config(int param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  
  *(ushort *)(param_1 + 0x20) = *(ushort *)(param_1 + 0x20) & 0xfffe;
  uVar3 = *(ushort *)(param_1 + 4);
  uVar1 = *param_2;
  uVar2 = param_2[1] | param_2[4] | *(ushort *)(param_1 + 0x20) & 0xfffd;
  if ((((param_1 == DAT_08002ffc) || (param_1 == DAT_08003000)) || (param_1 == DAT_08003004)) ||
     ((param_1 == DAT_08003008 || (param_1 == DAT_0800300c)))) {
    uVar2 = param_2[2] | (param_2[5] | uVar2 & 0xfff7) & 0xfffb;
    uVar3 = param_2[7] | param_2[6] | uVar3 & 0xfcff;
  }
  *(ushort *)(param_1 + 4) = uVar3;
  *(ushort *)(param_1 + 0x18) = uVar1 | *(ushort *)(param_1 + 0x18) & 0xff8c;
  *(ushort *)(param_1 + 0x34) = param_2[3];
  *(ushort *)(param_1 + 0x20) = uVar2;
  return;
}



/* ----------------------------------------
 * FUN_08003010 @ 0x8003010
 * Unknown function
 * ---------------------------------------- */

void FUN_08003010(int param_1,ushort param_2)

{
  *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) & 0xfff7 | param_2;
  return;
}



/* ----------------------------------------
 * FUN_0800301c @ 0x800301c
 * Unknown function
 * ---------------------------------------- */

void FUN_0800301c(int param_1,short *param_2)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  
  *(ushort *)(param_1 + 0x20) = *(ushort *)(param_1 + 0x20) & 0xffef;
  uVar3 = *(ushort *)(param_1 + 4);
  sVar1 = *param_2;
  uVar2 = param_2[1] << 4 | param_2[4] << 4 | *(ushort *)(param_1 + 0x20) & 0xffdf;
  if ((param_1 == DAT_08003094) || (param_1 == DAT_08003098)) {
    uVar2 = param_2[2] << 4 | (param_2[5] << 4 | uVar2 & 0xff7f) & 0xffbf;
    uVar3 = param_2[7] << 2 | param_2[6] << 2 | uVar3 & 0xf3ff;
  }
  *(ushort *)(param_1 + 4) = uVar3;
  *(ushort *)(param_1 + 0x18) = sVar1 << 8 | *(ushort *)(param_1 + 0x18) & 0x8cff;
  *(short *)(param_1 + 0x38) = param_2[3];
  *(ushort *)(param_1 + 0x20) = uVar2;
  return;
}



/* ----------------------------------------
 * FUN_0800309c @ 0x800309c
 * Unknown function
 * ---------------------------------------- */

void FUN_0800309c(int param_1,short param_2)

{
  *(ushort *)(param_1 + 0x18) = param_2 << 8 | *(ushort *)(param_1 + 0x18) & 0xf7ff;
  return;
}



/* ----------------------------------------
 * FUN_080030b0 @ 0x80030b0
 * Unknown function
 * ---------------------------------------- */

void FUN_080030b0(int param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  
  *(ushort *)(param_1 + 0x20) = *(ushort *)(param_1 + 0x20) & 0xfeff;
  uVar3 = *(ushort *)(param_1 + 4);
  uVar1 = *param_2;
  uVar2 = param_2[1] << 8 | param_2[4] << 8 | *(ushort *)(param_1 + 0x20) & 0xfdff;
  if ((param_1 == DAT_08003124) || (param_1 == DAT_08003128)) {
    uVar2 = param_2[2] << 8 | (param_2[5] << 8 | uVar2 & 0xf7ff) & 0xfbff;
    uVar3 = param_2[7] << 4 | param_2[6] << 4 | uVar3 & 0xcfff;
  }
  *(ushort *)(param_1 + 4) = uVar3;
  *(ushort *)(param_1 + 0x1c) = uVar1 | *(ushort *)(param_1 + 0x1c) & 0xff8c;
  *(ushort *)(param_1 + 0x3c) = param_2[3];
  *(ushort *)(param_1 + 0x20) = uVar2;
  return;
}



/* ----------------------------------------
 * FUN_0800312c @ 0x800312c
 * Unknown function
 * ---------------------------------------- */

void FUN_0800312c(int param_1,ushort param_2)

{
  *(ushort *)(param_1 + 0x1c) = *(ushort *)(param_1 + 0x1c) & 0xfff7 | param_2;
  return;
}



/* ----------------------------------------
 * FUN_08003138 @ 0x8003138
 * Unknown function
 * ---------------------------------------- */

void FUN_08003138(int param_1,short *param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  
  *(ushort *)(param_1 + 0x20) = *(ushort *)(param_1 + 0x20) & 0xefff;
  uVar4 = *(ushort *)(param_1 + 4);
  sVar1 = *param_2;
  sVar2 = param_2[4];
  sVar3 = param_2[1];
  if ((param_1 == DAT_08003194) || (param_1 == DAT_08003198)) {
    uVar4 = param_2[6] << 6 | uVar4 & 0xbfff;
  }
  *(ushort *)(param_1 + 4) = uVar4;
  *(ushort *)(param_1 + 0x1c) = sVar1 << 8 | *(ushort *)(param_1 + 0x1c) & 0x8cff;
  *(short *)(param_1 + 0x40) = param_2[3];
  *(ushort *)(param_1 + 0x20) = sVar3 << 0xc | sVar2 << 0xc | *(ushort *)(param_1 + 0x20) & 0xdfff;
  return;
}



/* ----------------------------------------
 * FUN_0800319c @ 0x800319c
 * Unknown function
 * ---------------------------------------- */

void FUN_0800319c(int param_1,short param_2)

{
  *(ushort *)(param_1 + 0x1c) = param_2 << 8 | *(ushort *)(param_1 + 0x1c) & 0xf7ff;
  return;
}



/* ----------------------------------------
 * FUN_080031b0 @ 0x80031b0
 * Unknown function
 * ---------------------------------------- */

void FUN_080031b0(int param_1,ushort param_2)

{
  *(ushort *)(param_1 + 4) = *(ushort *)(param_1 + 4) & 0xff8f;
  *(ushort *)(param_1 + 4) = *(ushort *)(param_1 + 4) | param_2;
  return;
}



/* ----------------------------------------
 * FUN_080031c0 @ 0x80031c0
 * Unknown function
 * ---------------------------------------- */

void FUN_080031c0(int param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0x34) = param_2;
  return;
}



/* ----------------------------------------
 * FUN_080031c4 @ 0x80031c4
 * Unknown function
 * ---------------------------------------- */

void FUN_080031c4(int param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0x38) = param_2;
  return;
}



/* ----------------------------------------
 * FUN_080031c8 @ 0x80031c8
 * Unknown function
 * ---------------------------------------- */

void FUN_080031c8(int param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0x3c) = param_2;
  return;
}



/* ----------------------------------------
 * timer_config @ 0x80031cc
 * Configure timer parameters
 * ---------------------------------------- */

void timer_config(ushort *param_1,ushort *param_2)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort uVar3;
  
  puVar2 = DAT_08003244;
  puVar1 = DAT_08003240;
  uVar3 = *param_1;
  if ((((param_1 == DAT_08003240) || (param_1 == DAT_08003244)) || (param_1 == (ushort *)0x40000000)
      ) || (((param_1 == DAT_08003248 || (param_1 == DAT_0800324c)) || (param_1 == DAT_08003250))))
  {
    uVar3 = param_2[1] | uVar3 & 0xff8f;
  }
  if ((param_1 != DAT_08003254) && (param_1 != DAT_08003258)) {
    uVar3 = param_2[3] | uVar3 & 0xfcff;
  }
  *param_1 = uVar3;
  param_1[0x16] = param_2[2];
  param_1[0x14] = *param_2;
  if ((((param_1 == puVar1) || (param_1 == puVar2)) || (param_1 == DAT_0800325c)) ||
     ((param_1 == DAT_08003260 || (param_1 == DAT_08003264)))) {
    param_1[0x18] = (ushort)(byte)param_2[4];
  }
  param_1[10] = 1;
  return;
}



/* ----------------------------------------
 * FUN_08003268 @ 0x8003268
 * Unknown function
 * ---------------------------------------- */

void FUN_08003268(undefined2 *param_1)

{
  param_1[2] = 0xffff;
  *param_1 = 0;
  param_1[3] = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}



/* ----------------------------------------
 * FUN_0800327a @ 0x800327a
 * Unknown function
 * ---------------------------------------- */

void FUN_0800327a(ushort *param_1,int param_2)

{
  ushort uVar1;
  
  if (param_2 == 0) {
    uVar1 = *param_1 & 0xfffb;
  }
  else {
    uVar1 = *param_1 | 4;
  }
  *param_1 = uVar1;
  return;
}



/* ----------------------------------------
 * FUN_08003290 @ 0x8003290
 * Unknown function
 * ---------------------------------------- */

void FUN_08003290(void)

{
  short *psVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  psVar1 = DAT_08003360;
  uVar5 = FUN_08003fda((int)*DAT_08003360);
  puVar2 = DAT_08003364;
  uVar6 = FUN_08003fda((int)(short)DAT_08003364[1]);
  if (uVar6 < uVar5) {
    if (*DAT_08003368 != '\0') goto LAB_080032dc;
    iVar8 = (int)(short)puVar2[1];
    sVar4 = *psVar1;
    iVar7 = (int)sVar4;
    if (iVar8 < iVar7) {
      iVar8 = iVar8 + (uint)*DAT_0800336c;
      if (iVar8 < iVar7) {
LAB_080032d6:
        puVar2[1] = (short)iVar8;
        goto LAB_080032dc;
      }
    }
    else {
      if (iVar8 <= iVar7) goto LAB_080032dc;
      iVar8 = iVar8 - (uint)*DAT_0800336c;
      if (iVar7 < iVar8) goto LAB_080032d6;
    }
  }
  else {
    sVar4 = *psVar1;
  }
  puVar2[1] = sVar4;
LAB_080032dc:
  iVar8 = DAT_08003378;
  psVar1 = DAT_08003374;
  iVar7 = DAT_08003370;
  if (*(char *)(DAT_08003370 + 0x16) == '\0') {
    if ((*(short *)(DAT_0800338c + 0x10) < 0xf08) && (*(short *)(DAT_0800338c + 0x12) < 0xf08)) {
      FUN_080041a0(DAT_08003394,DAT_08003390);
      FUN_08004b48(DAT_08003390,DAT_08003374,DAT_0800337c);
      FUN_08004154((int)-*psVar1,DAT_08003378);
      *puVar2 = *(undefined2 *)(iVar8 + 0xc);
    }
  }
  else {
    *puVar2 = 0;
    *psVar1 = 0;
    *(undefined2 *)(iVar8 + 6) = 0;
  }
  FUN_080034a0(*(undefined2 *)(iVar7 + 0x18),DAT_0800337c);
  FUN_08004b0c(DAT_08003364,DAT_08003380,DAT_0800337c);
  FUN_08004b96(DAT_08003380,DAT_08003384);
  puVar3 = DAT_08003388;
  puVar2 = DAT_08003384;
  *DAT_08003388 = *DAT_08003384;
  puVar3[2] = puVar2[1];
  puVar3[4] = puVar2[2];
  return;
}



/* ----------------------------------------
 * FUN_08003398 @ 0x8003398
 * Unknown function
 * ---------------------------------------- */

void FUN_08003398(void)

{
  short *psVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  psVar1 = DAT_08003468;
  uVar5 = FUN_08003fda((int)*DAT_08003468);
  puVar2 = DAT_0800346c;
  uVar6 = FUN_08003fda((int)(short)DAT_0800346c[1]);
  if (uVar6 < uVar5) {
    if (*DAT_08003470 != '\0') goto LAB_080033e4;
    iVar8 = (int)(short)puVar2[1];
    sVar4 = *psVar1;
    iVar7 = (int)sVar4;
    if (iVar8 < iVar7) {
      iVar8 = iVar8 + (uint)*DAT_08003474;
      if (iVar8 < iVar7) {
LAB_080033de:
        puVar2[1] = (short)iVar8;
        goto LAB_080033e4;
      }
    }
    else {
      if (iVar8 <= iVar7) goto LAB_080033e4;
      iVar8 = iVar8 - (uint)*DAT_08003474;
      if (iVar7 < iVar8) goto LAB_080033de;
    }
  }
  else {
    sVar4 = *psVar1;
  }
  puVar2[1] = sVar4;
LAB_080033e4:
  iVar8 = DAT_08003480;
  psVar1 = DAT_0800347c;
  iVar7 = DAT_08003478;
  if (*(char *)(DAT_08003478 + 0x16) == '\0') {
    if ((*(short *)(DAT_08003494 + 0xc) < 0xf08) && (*(short *)(DAT_08003494 + 0xe) < 0xf08)) {
      FUN_080041a0(DAT_0800349c,DAT_08003498);
      FUN_08004b48(DAT_08003498,DAT_0800347c,DAT_08003484);
      FUN_08004154((int)-*psVar1,DAT_08003480);
      *puVar2 = *(undefined2 *)(iVar8 + 0xc);
    }
  }
  else {
    *puVar2 = 0;
    *psVar1 = 0;
    *(undefined2 *)(iVar8 + 6) = 0;
  }
  FUN_080034a0(*(undefined2 *)(iVar7 + 0x18),DAT_08003484);
  FUN_08004b0c(DAT_0800346c,DAT_08003488,DAT_08003484);
  FUN_08004b96(DAT_08003488,DAT_0800348c);
  puVar3 = DAT_08003490;
  puVar2 = DAT_0800348c;
  *DAT_08003490 = *DAT_0800348c;
  puVar3[2] = puVar2[1];
  puVar3[4] = puVar2[2];
  return;
}



/* ----------------------------------------
 * FUN_080034a0 @ 0x80034a0
 * Unknown function
 * ---------------------------------------- */

void FUN_080034a0(uint param_1,short *param_2)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar1 = DAT_08003500;
  uVar5 = param_1 >> 6 & 0x300;
  uVar3 = (param_1 << 0x12) >> 0x18;
  iVar4 = 0xff - uVar3;
  if (uVar5 == 0) {
    *param_2 = *(short *)(DAT_08003500 + uVar3 * 2);
    sVar2 = *(short *)(iVar1 + iVar4 * 2);
  }
  else {
    if (uVar5 == 0x100) {
      *param_2 = *(short *)(DAT_08003500 + iVar4 * 2);
      sVar2 = *(short *)(iVar1 + uVar3 * 2);
    }
    else {
      if (uVar5 != 0x200) {
        if (uVar5 != 0x300) {
          return;
        }
        *param_2 = -*(short *)(DAT_08003500 + iVar4 * 2);
        sVar2 = *(short *)(iVar1 + uVar3 * 2);
        goto LAB_080034d2;
      }
      *param_2 = -*(short *)(DAT_08003500 + uVar3 * 2);
      sVar2 = *(short *)(iVar1 + iVar4 * 2);
    }
    sVar2 = -sVar2;
  }
LAB_080034d2:
  param_2[1] = sVar2;
  return;
}



/* ----------------------------------------
 * FUN_08003504 @ 0x8003504
 * Unknown function
 * ---------------------------------------- */

void FUN_08003504(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  ushort uVar10;
  undefined8 uVar11;
  
  pbVar4 = DAT_0800363c;
  puVar5 = DAT_08003638;
  if (-1 < (int)((uint)*DAT_08003634 << 0x1a)) {
    if (*DAT_08003664 == '\0') {
      return;
    }
    uVar10 = *(ushort *)(DAT_0800363c + 0xc);
    *(ushort *)(DAT_0800363c + 0xc) = uVar10 + 1;
    puVar6 = DAT_08003668;
    if (uVar10 < 0x49c8) {
      return;
    }
    *puVar5 = 0;
    *puVar6 = 1;
    *DAT_0800366c = (ushort)(((uint)*DAT_0800366c << 0x11) >> 0x11);
    *DAT_08003670 = (ushort)(((uint)*DAT_08003670 << 0x11) >> 0x11);
    return;
  }
  iVar7 = FUN_08003fc0();
  *(short *)(pbVar4 + 4) = (short)iVar7;
  puVar6 = DAT_08003640;
  uVar10 = *(short *)(pbVar4 + 8) + 1;
  *(ushort *)(pbVar4 + 8) = uVar10;
  if (iVar7 << 0x17 < 0) {
    if (uVar10 == 0xe) {
      *puVar5 = *puVar6;
      bVar1 = puVar6[9];
      bVar2 = puVar6[8];
      if (((ushort)((ushort)(byte)puVar6[1] + (ushort)(byte)puVar6[2] * 0x100) ==
           (ushort)((ushort)(byte)puVar6[3] + (ushort)(byte)puVar6[4] * 0x100)) &&
         ((cVar3 = puVar6[5], cVar3 == 'U' || (cVar3 == -0x56)))) {
        uVar8 = FUN_080057f0();
        uVar8 = FUN_08005634(uVar8,DAT_08003648);
        uVar9 = FUN_0800554c(uVar8,*DAT_0800364c);
        uVar9 = FUN_08005634(uVar9,0xc0000000);
        *DAT_08003650 = uVar9;
        *DAT_0800364c = uVar8;
        uVar11 = FUN_080050f4((int)(short)((ushort)bVar2 + (ushort)bVar1 * 0x100));
        FUN_08004e44((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,DAT_08003654);
        uVar8 = FUN_08004c90();
        puVar5 = DAT_0800365c;
        *DAT_08003658 = uVar8;
        if (cVar3 == 'U') {
          *puVar5 = 1;
          *pbVar4 = 0;
        }
        else {
          bVar1 = *pbVar4;
          *pbVar4 = bVar1 + 1;
          if (2 < bVar1) {
            *puVar5 = 0;
          }
        }
        if (puVar6[6] == puVar6[7]) {
          *DAT_08003660 = (byte)puVar6[6] - 0x58;
        }
      }
      else {
        *DAT_08003644 = 1;
      }
    }
    pbVar4[8] = 0;
    pbVar4[9] = 0;
  }
  else if (0xd < uVar10) goto LAB_080035fa;
  puVar6[*(ushort *)(pbVar4 + 8)] = (char)iVar7;
LAB_080035fa:
  pbVar4[0xc] = 0;
  pbVar4[0xd] = 0;
  return;
}



/* ----------------------------------------
 * FUN_08003674 @ 0x8003674
 * Unknown function
 * ---------------------------------------- */

void FUN_08003674(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  ushort uVar12;
  undefined8 uVar13;
  
  iVar5 = DAT_080037e4;
  pcVar4 = DAT_080037e0;
  if (-1 < (int)((uint)*DAT_080037dc << 0x1a)) {
    if (*DAT_08003824 == '\0') {
      return;
    }
    uVar12 = *(ushort *)(DAT_080037e4 + 0xe);
    *(ushort *)(DAT_080037e4 + 0xe) = uVar12 + 1;
    puVar8 = DAT_08003828;
    if (uVar12 < 0x49c8) {
      return;
    }
    *pcVar4 = '\0';
    *puVar8 = 1;
    *DAT_0800382c = (ushort)(((uint)*DAT_0800382c << 0x11) >> 0x11);
    *DAT_08003830 = (ushort)(((uint)*DAT_08003830 << 0x11) >> 0x11);
    return;
  }
  iVar9 = FUN_08003fc0();
  *(short *)(iVar5 + 6) = (short)iVar9;
  pcVar6 = DAT_080037e8;
  uVar12 = *(short *)(iVar5 + 10) + 1;
  *(ushort *)(iVar5 + 10) = uVar12;
  if (iVar9 << 0x17 < 0) {
    if (uVar12 == 0xe) {
      cVar3 = *pcVar6;
      if (cVar3 == *(char *)(iVar5 + 3)) {
        *pcVar4 = cVar3;
      }
      *pcVar4 = cVar3;
      bVar1 = pcVar6[9];
      bVar2 = pcVar6[8];
      if (((ushort)((ushort)(byte)pcVar6[1] + (ushort)(byte)pcVar6[2] * 0x100) ==
           (ushort)((ushort)(byte)pcVar6[3] + (ushort)(byte)pcVar6[4] * 0x100)) &&
         ((cVar3 = pcVar6[5], cVar3 == 'U' || (cVar3 == -0x56)))) {
        uVar10 = FUN_080057f0();
        uVar10 = FUN_08005634(uVar10,DAT_080037f0);
        puVar7 = DAT_080037f4;
        uVar11 = FUN_0800554c(uVar10,*DAT_080037f4);
        uVar11 = FUN_08005bfa(uVar11,0xffffffff);
        *DAT_080037f8 = uVar11;
        *puVar7 = uVar10;
        uVar13 = FUN_080050f4((int)(short)((ushort)bVar2 + (ushort)bVar1 * 0x100));
        FUN_08004e44((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),0,DAT_080037fc);
        uVar10 = FUN_08004c90();
        puVar8 = DAT_08003804;
        *DAT_08003800 = uVar10;
        if (cVar3 == 'U') {
          *puVar8 = 1;
          *(undefined1 *)(iVar5 + 1) = 0;
        }
        else {
          bVar1 = *(byte *)(iVar5 + 1);
          *(byte *)(iVar5 + 1) = bVar1 + 1;
          if (bVar1 < 3) {
            *(byte *)(iVar5 + 1) = bVar1 + 2;
          }
          else {
            *puVar8 = 0;
          }
        }
        if (pcVar6[6] == pcVar6[7]) {
          *DAT_08003808 = (byte)pcVar6[6] - 0x58;
        }
        if (*DAT_0800380c == '\0' && *DAT_08003810 == '\0') {
          *DAT_08003814 = pcVar6[10];
          *DAT_08003818 = pcVar6[0xb];
          *DAT_0800381c = pcVar6[0xc];
          pcVar4 = DAT_08003820;
          cVar3 = pcVar6[0xd];
          *DAT_08003820 = cVar3;
          if (cVar3 == '\0') {
            *pcVar4 = '\n';
          }
        }
      }
      else {
        *DAT_080037ec = 1;
      }
    }
    *(undefined2 *)(iVar5 + 10) = 0;
  }
  else if (0xd < uVar12) goto LAB_080037a2;
  pcVar6[*(ushort *)(iVar5 + 10)] = (char)iVar9;
LAB_080037a2:
  *(undefined2 *)(iVar5 + 0xe) = 0;
  return;
}



/* ----------------------------------------
 * FUN_08003834 @ 0x8003834
 * Unknown function
 * ---------------------------------------- */

void FUN_08003834(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  
  puVar2 = DAT_0800394c;
  puVar1 = DAT_08003948;
  uVar8 = *(uint *)(DAT_08003940 + 8);
  uVar7 = *(uint *)(DAT_08003950 + 8);
  if ((uVar8 < 0x547) || (uVar7 < 0x547)) {
    if (*(char *)(DAT_08003950 + 0x3b) != *(char *)(DAT_08003940 + 0x3b)) {
      if ((uVar8 < 0x15e) && (uVar7 < 0x15e)) {
        if (uVar8 <= uVar7 + 0x37) {
          uVar8 = uVar8 + 0x37;
          goto LAB_080038aa;
        }
LAB_0800389c:
        *DAT_08003944 = 1;
LAB_080038b0:
        *puVar1 = 0;
      }
      else {
        if (uVar7 + 0x58 < uVar8) goto LAB_0800389c;
        uVar8 = uVar8 + 0x58;
LAB_080038aa:
        *DAT_08003944 = 0;
        if (uVar7 <= uVar8) goto LAB_080038b0;
        *puVar1 = 1;
      }
      *puVar2 = 1;
      goto LAB_080038b8;
    }
    if (uVar8 < 0x546) {
      *DAT_08003944 = 1;
    }
    else {
      *DAT_08003944 = 0;
    }
    if (0x545 < uVar7) goto LAB_0800387a;
    *puVar1 = 1;
  }
  else {
    *DAT_08003944 = 0;
LAB_0800387a:
    *puVar1 = 0;
  }
  *puVar2 = 0;
LAB_080038b8:
  pcVar6 = DAT_0800396c;
  pcVar5 = DAT_08003964;
  pbVar4 = DAT_08003960;
  pbVar3 = DAT_0800395c;
  puVar1 = DAT_08003958;
  if (*DAT_08003954 == '\0') {
    *DAT_0800395c = 0;
    if (*pcVar6 == '\0') {
      *puVar1 = 0;
      if (*DAT_08003970 == '\0') {
        *pbVar4 = 1;
      }
      else {
        *pbVar4 = *pbVar4 ^ 1;
      }
    }
    else {
      *puVar1 = 1;
      *pbVar4 = 0;
    }
  }
  else {
    *DAT_08003960 = 0;
    if (*pcVar5 == '\0') {
      *puVar1 = 0;
      if (*DAT_08003968 < 0x662) {
        *pbVar3 = *pbVar3 ^ 1;
      }
      else {
        *pbVar3 = 1;
      }
    }
    else {
      *puVar1 = 1;
      *pbVar3 = 0;
    }
  }
  *DAT_08003974 = *pbVar4;
  *DAT_08003978 = *pbVar3;
  puVar2 = DAT_08003980;
  puVar1 = DAT_0800397c;
  *DAT_0800397c = 0;
  *puVar2 = 0;
  if (*DAT_08003984 == '\0') {
    if (*DAT_08003988 != '\0' || *DAT_0800398c != '\0') {
      *puVar2 = 1;
      return;
    }
  }
  else {
    *puVar1 = 1;
  }
  return;
}



/* ----------------------------------------
 * FUN_08003990 @ 0x8003990
 * Unknown function
 * ---------------------------------------- */

void FUN_08003990(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  short sVar14;
  int iVar15;
  int iVar16;
  ushort *puVar17;
  char *pcVar18;
  byte *pbVar19;
  byte *pbVar20;
  ushort *puVar21;
  byte bVar22;
  ushort uVar23;
  byte bVar24;
  uint uVar25;
  ushort uVar26;
  byte bVar27;
  
  iVar15 = DAT_08003d08;
  sVar14 = (short)((((int)*DAT_08003d00 + (int)*DAT_08003d04) * 0xd1) / 100);
  *(short *)(DAT_08003d08 + 0x12) = sVar14;
  if (sVar14 < 1) {
    *(undefined2 *)(iVar15 + 0x12) = 0;
  }
  iVar16 = DAT_08003d14;
  sVar14 = (short)((*DAT_08003d0c * 0xfa) / 100) + 0x50;
  bVar22 = (byte)((ushort)sVar14 >> 8);
  *(short *)(iVar15 + 0x10) = sVar14;
  pcVar18 = DAT_08003d1c;
  puVar17 = DAT_08003d18;
  uVar25 = (uint)(*(int *)(iVar16 + 8) + *(int *)(DAT_08003d10 + 8)) >> 1;
  *(uint *)(iVar15 + 0x14) = uVar25;
  *puVar17 = 0;
  cVar1 = *pcVar18;
  cVar2 = *DAT_08003d20;
  cVar8 = *DAT_08003d24;
  cVar9 = *DAT_08003d28;
  cVar3 = *DAT_08003d2c;
  cVar10 = *DAT_08003d30;
  if (cVar1 == '\0') {
    if (cVar2 == '\0') {
      if (cVar8 == '\0') {
        if (cVar9 == '\0') {
          if (*DAT_08003d34 == '\0') {
            if (*DAT_08003d38 == '\0') {
              if (cVar3 == '\0') {
                if (cVar10 == '\0') goto LAB_08003a5c;
                uVar26 = 0x4000;
              }
              else {
                uVar26 = 0x8000;
              }
            }
            else {
              uVar26 = 0x800;
            }
          }
          else {
            uVar26 = 8;
          }
        }
        else {
          uVar26 = 0x200;
        }
      }
      else {
        uVar26 = 2;
      }
    }
    else {
      uVar26 = 0x100;
    }
    *puVar17 = uVar26;
  }
  else {
    *puVar17 = 1;
  }
LAB_08003a5c:
  pbVar20 = DAT_08003d40;
  pbVar19 = DAT_08003d3c;
  if (*(byte *)(DAT_08003d08 + 2) < 0xf) {
    *(byte *)(DAT_08003d08 + 2) = *(byte *)(DAT_08003d08 + 2) + 1;
  }
  else {
    *(undefined1 *)(DAT_08003d08 + 2) = 0;
    *pbVar19 = 0;
    pbVar19[1] = 0;
    pbVar19[2] = 0;
    pbVar19[3] = 0;
    pcVar18 = DAT_08003d44;
    pbVar19[4] = 0;
    pbVar19[5] = 0;
    if (*pcVar18 != '\0') {
      *pbVar19 = 1;
    }
    if (*DAT_08003d48 != '\0') {
      *pbVar19 = *pbVar19 | 2;
    }
    if (*DAT_08003d4c != '\0') {
      *pbVar19 = *pbVar19 | 4;
    }
    if (*DAT_08003d50 != '\0') {
      *pbVar19 = *pbVar19 | 8;
    }
    cVar4 = *DAT_08003d54;
    if (cVar4 != '\0') {
      *pbVar19 = *pbVar19 | 0x10;
    }
    cVar5 = *DAT_08003d58;
    if (cVar5 != '\0') {
      *pbVar19 = *pbVar19 | 0x20;
    }
    cVar6 = *DAT_08003d5c;
    if (cVar6 != '\0') {
      pbVar19[3] = 0x28;
    }
    iVar15 = DAT_08003d14;
    bVar24 = *DAT_08003d60;
    pbVar19[4] = bVar24;
    cVar11 = *(char *)(iVar16 + 0x16);
    cVar12 = *(char *)(iVar15 + 0x3b);
    cVar7 = *(char *)(DAT_08003d10 + 0x16);
    cVar13 = *(char *)(DAT_08003d10 + 0x3b);
    if (((cVar11 == '\0') && (cVar7 == '\0')) && (cVar12 != cVar13)) {
      if (uVar25 < 0x321) {
        if (uVar25 < 0x196) {
          bVar27 = 3;
        }
        else {
          bVar27 = 2;
        }
        pbVar19[5] = bVar27;
      }
      else {
        pbVar19[5] = 1;
      }
    }
    *pbVar20 = 0;
    pbVar20[1] = 0;
    pbVar20[2] = 0;
    pbVar20[3] = 0;
    pcVar18 = DAT_08003d64;
    pbVar20[4] = 0;
    pbVar20[5] = 0;
    if (*pcVar18 != '\0') {
      *pbVar20 = 1;
    }
    if (*DAT_08003d68 != '\0') {
      *pbVar20 = *pbVar20 | 2;
    }
    if (*DAT_08003d6c != '\0') {
      *pbVar20 = *pbVar20 | 4;
    }
    if (*DAT_08003d70 != '\0') {
      *pbVar20 = *pbVar20 | 8;
    }
    if (cVar4 != '\0') {
      *pbVar20 = *pbVar20 | 0x10;
    }
    if (cVar5 != '\0') {
      *pbVar20 = *pbVar20 | 0x20;
    }
    if (cVar1 == '\0') {
      if (cVar2 != '\0') {
        bVar27 = 5;
        goto LAB_08003c0a;
      }
      if (cVar8 == '\0') {
        if (cVar9 == '\0') {
          if (*DAT_08003d74 == '\0') {
            if (*DAT_08003d78 == '\0') {
              if (cVar10 == '\0') {
                if (cVar3 == '\0') goto LAB_08003c0c;
                bVar27 = 8;
              }
              else {
                bVar27 = 7;
              }
            }
            else {
              bVar27 = 6;
            }
          }
          else {
            bVar27 = 3;
          }
        }
        else {
          bVar27 = 2;
        }
        goto LAB_08003c0a;
      }
      pbVar20[2] = 1;
    }
    else {
      bVar27 = 4;
LAB_08003c0a:
      pbVar20[2] = bVar27;
    }
LAB_08003c0c:
    if (cVar6 == '\x01') {
      pbVar20[3] = 0x28;
    }
    pbVar20[4] = bVar24;
    pbVar20[1] = 1;
    if (((cVar11 == '\0') && (cVar7 == '\0')) && (cVar12 != cVar13)) {
      if (uVar25 < 0x321) {
        if (uVar25 < 0x196) {
          bVar24 = 3;
        }
        else {
          bVar24 = 2;
        }
        pbVar20[5] = bVar24;
      }
      else {
        pbVar20[5] = 1;
      }
    }
  }
  puVar21 = DAT_08003d80;
  iVar15 = DAT_08003d08;
  uVar23 = *DAT_08003d84;
  uVar26 = *DAT_08003d88;
  switch(*(undefined1 *)(DAT_08003d08 + 2)) {
  case 0:
    *DAT_08003d7c = *pbVar19 | 0x100;
    uVar23 = *pbVar20 | 0x100;
    break;
  case 1:
    *DAT_08003d7c = (ushort)pbVar19[1];
    uVar23 = (ushort)pbVar20[1];
    break;
  case 2:
    *DAT_08003d7c = (ushort)pbVar19[2];
    uVar23 = (ushort)pbVar20[2];
    break;
  case 3:
    *DAT_08003d7c = (ushort)pbVar19[3];
    uVar23 = (ushort)pbVar20[3];
    break;
  case 4:
    *DAT_08003d7c = (ushort)pbVar19[4];
    uVar23 = (ushort)pbVar20[4];
    break;
  case 5:
    *DAT_08003d7c = (ushort)pbVar19[5];
    uVar23 = (ushort)pbVar20[5];
    break;
  case 6:
    *DAT_08003d7c = 0;
    uVar23 = uVar23 & 0xff;
    break;
  case 7:
    *DAT_08003d7c = 0;
    uVar23 = uVar23 >> 8;
    break;
  case 8:
    *DAT_08003d7c = 0;
    bVar22 = (byte)sVar14;
    goto LAB_08003cce;
  case 9:
    *DAT_08003d7c = 0;
    goto LAB_08003cf4;
  case 10:
    *DAT_08003d7c = 0;
    bVar22 = (byte)*puVar17;
    goto LAB_08003cce;
  case 0xb:
    *DAT_08003d7c = 0;
    uVar23 = *puVar17 >> 8;
    break;
  case 0xc:
    *DAT_08003d7c = 0;
    uVar23 = uVar26 & 0xff;
    break;
  case 0xd:
    *DAT_08003d7c = 0;
    uVar23 = uVar26 >> 8;
    break;
  case 0xe:
    *DAT_08003d7c = 0;
    bVar22 = *(byte *)(iVar15 + 0x12);
LAB_08003cce:
    uVar23 = (ushort)bVar22;
    break;
  case 0xf:
    *DAT_08003d7c = 0;
    bVar22 = (byte)((ushort)*(undefined2 *)(iVar15 + 0x12) >> 8);
LAB_08003cf4:
    uVar23 = (ushort)bVar22;
    break;
  default:
    goto switchD_08003c62_default;
  }
  *puVar21 = uVar23;
switchD_08003c62_default:
  return;
}



/* ----------------------------------------
 * FUN_08003d8c @ 0x8003d8c
 * Unknown function
 * ---------------------------------------- */

void FUN_08003d8c(void)

{
  undefined4 uVar1;
  undefined4 local_30;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_20;
  undefined1 local_1e;
  undefined1 local_1d;
  
  uVar1 = DAT_08003e74;
  local_20 = 4;
  local_1e = 3;
  local_1d = 0x18;
  gpio_config(DAT_08003e74,&local_20);
  local_20 = 8;
  local_1e = 3;
  local_1d = 4;
  gpio_config(uVar1,&local_20);
  uVar1 = DAT_08003e78;
  local_20 = 0x400;
  local_1e = 3;
  local_1d = 0x18;
  gpio_config(DAT_08003e78,&local_20);
  local_20 = 0x800;
  local_1e = 3;
  local_1d = 4;
  gpio_config(uVar1,&local_20);
  uVar1 = DAT_08003e7c;
  FUN_08003e98(DAT_08003e7c);
  local_2c = 0x1000;
  local_28 = 0;
  local_30 = 0xcb73;
  local_2a = 0;
  local_24 = 0;
  local_26 = 0xc;
  FUN_08003f0c(uVar1,&local_30);
  FUN_08003fc8(uVar1,0);
  FUN_08003e84(uVar1,1);
  uVar1 = DAT_08003e80;
  FUN_08003e98(DAT_08003e80);
  local_2c = 0x1000;
  local_28 = 0;
  local_30 = 0xcb73;
  local_2a = 0;
  local_24 = 0;
  local_26 = 0xc;
  FUN_08003f0c(uVar1,&local_30);
  FUN_08003fc8(uVar1,0);
  FUN_08003e84(uVar1,1);
  return;
}



/* ----------------------------------------
 * FUN_08003e84 @ 0x8003e84
 * Unknown function
 * ---------------------------------------- */

void FUN_08003e84(int param_1,int param_2)

{
  ushort uVar1;
  
  if (param_2 == 0) {
    uVar1 = *(ushort *)(param_1 + 0xc) & 0xdfff;
  }
  else {
    uVar1 = *(ushort *)(param_1 + 0xc) | 0x2000;
  }
  *(ushort *)(param_1 + 0xc) = uVar1;
  return;
}



/* ----------------------------------------
 * FUN_08003e98 @ 0x8003e98
 * Unknown function
 * ---------------------------------------- */

void FUN_08003e98(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == DAT_08003ef8) {
    rcc_clock_enable(0x4000);
    rcc_clock_enable(0x4000,0);
    return;
  }
  if (param_1 == DAT_08003efc) {
    uVar1 = 0x20000;
  }
  else if (param_1 == DAT_08003f00) {
    uVar1 = 0x40000;
  }
  else if (param_1 == DAT_08003f04) {
    uVar1 = 0x80000;
  }
  else {
    if (param_1 != DAT_08003f08) {
      return;
    }
    uVar1 = 0x100000;
  }
  FUN_080020a4(uVar1);
  FUN_080020a4(uVar1,0);
  return;
}



/* ----------------------------------------
 * FUN_08003f0c @ 0x8003f0c
 * Unknown function
 * ---------------------------------------- */

void FUN_08003f0c(int param_1,int *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_20 [8];
  int local_18;
  int local_14;
  
  *(ushort *)(param_1 + 0x10) = *(ushort *)((int)param_2 + 6) | *(ushort *)(param_1 + 0x10) & 0xcfff
  ;
  *(ushort *)(param_1 + 0xc) =
       *(ushort *)(param_2 + 1) | *(ushort *)(param_2 + 2) |
       *(ushort *)((int)param_2 + 10) | *(ushort *)(param_1 + 0xc) & 0xe9f3;
  *(ushort *)(param_1 + 0x14) = *(ushort *)(param_2 + 3) | *(ushort *)(param_1 + 0x14) & 0xfcff;
  FUN_08002198(auStack_20);
  if (param_1 == DAT_08003fbc) {
    local_18 = local_14;
  }
  if ((int)((uint)*(ushort *)(param_1 + 0xc) * 0x10000) < 0) {
    uVar3 = *param_2 << 1;
  }
  else {
    uVar3 = *param_2 << 2;
  }
  uVar3 = (uint)(local_18 * 0x19) / uVar3;
  uVar2 = uVar3 % 100;
  if ((int)((uint)*(ushort *)(param_1 + 0xc) << 0x10) < 0) {
    uVar1 = (ushort)((uVar2 * 8 + 0x32) / 100) & 7;
  }
  else {
    uVar1 = (ushort)((uVar2 * 0x10 + 0x32) / 100) & 0xf;
  }
  *(ushort *)(param_1 + 8) = uVar1 | (ushort)(uVar3 / 100 << 4);
  return;
}



/* ----------------------------------------
 * FUN_08003fc0 @ 0x8003fc0
 * Unknown function
 * ---------------------------------------- */

ushort FUN_08003fc0(int param_1)

{
  return *(ushort *)(param_1 + 4) & 0x1ff;
}



/* ----------------------------------------
 * FUN_08003fc8 @ 0x8003fc8
 * Unknown function
 * ---------------------------------------- */

void FUN_08003fc8(int param_1,ushort param_2)

{
  *(ushort *)(param_1 + 0x10) = *(ushort *)(param_1 + 0x10) & 0xfff0;
  *(ushort *)(param_1 + 0x10) = *(ushort *)(param_1 + 0x10) | param_2;
  return;
}



/* ----------------------------------------
 * FUN_08003fda @ 0x8003fda
 * Unknown function
 * ---------------------------------------- */

uint FUN_08003fda(uint param_1)

{
  if ((int)param_1 < 1) {
    param_1 = -param_1;
  }
  return param_1 & 0xffff;
}



/* ----------------------------------------
 * FUN_08003fe4 @ 0x8003fe4
 * Unknown function
 * ---------------------------------------- */

void FUN_08003fe4(void)

{
  byte *pbVar1;
  ushort *puVar2;
  undefined1 *puVar3;
  ushort *puVar4;
  char *pcVar5;
  byte bVar6;
  ushort *puVar7;
  undefined1 *puVar8;
  ushort *puVar9;
  
  pbVar1 = DAT_0800412c;
  while (*(short *)(pbVar1 + 2) != 0) {
    *(short *)(pbVar1 + 2) = *(short *)(pbVar1 + 2) + -1;
  }
  FUN_08000f88(0x40);
  FUN_080020ec();
  FUN_08001224();
  FUN_080024d0();
  FUN_08001884();
  FUN_08003d8c();
  FUN_08001530();
  pcVar5 = DAT_0800413c;
  puVar4 = DAT_08004138;
  puVar3 = DAT_08004134;
  puVar2 = DAT_08004130;
  puVar9 = DAT_08004130 + 0x1a;
  do {
    if ((int)((uint)*puVar2 << 0x18) < 0) {
      *puVar3 = 1;
      *puVar2 = 0;
      *puVar9 = (ushort)(((uint)*puVar9 << 0x11) >> 0x11);
      *puVar4 = (ushort)(((uint)*puVar4 << 0x11) >> 0x11);
      puVar8 = DAT_08004140;
LAB_08004080:
      *puVar8 = 1;
    }
    else {
      puVar7 = DAT_08004138 + -0x1a;
      if ((int)((uint)*puVar7 << 0x18) < 0) {
        *puVar3 = 1;
        *puVar7 = 0;
        *puVar9 = (ushort)(((uint)*puVar9 << 0x11) >> 0x11);
        *puVar4 = (ushort)(((uint)*puVar4 << 0x11) >> 0x11);
        puVar8 = DAT_08004144;
        goto LAB_08004080;
      }
    }
    if (*pcVar5 != '\0') {
      FUN_08000a64();
      FUN_08003990();
      *pcVar5 = '\0';
    }
    if (*DAT_08004148 != '\0') {
      *DAT_08004148 = '\0';
      bVar6 = *pbVar1;
      *pbVar1 = bVar6 + 1;
      if ((byte)(bVar6 + 1) < 2) {
        FUN_08001928();
        FUN_08000504();
        main_control_loop();
      }
      else {
        *pbVar1 = 0;
        FUN_08000b7c();
        FUN_080023a4();
        if (*DAT_0800414c == '\x01') {
          FUN_08001e74();
        }
        if (*DAT_08004150 == '\x01') {
          FUN_0800073c();
        }
        FUN_08000cf0();
        bVar6 = pbVar1[1] + 1;
        pbVar1[1] = bVar6;
        if (bVar6 < 0x7d) {
          if (bVar6 == 1) {
            FUN_08003834();
          }
          else if (bVar6 == 2) {
            FUN_08000d38();
          }
          else if (bVar6 == 3) {
            FUN_08000fdc();
          }
          else if (bVar6 == 4) {
            FUN_08000fe8();
          }
          else if (bVar6 == 5) {
            FUN_08000fec();
          }
          else if (bVar6 == 6) {
            FUN_08000ff8();
          }
        }
        else {
          pbVar1[1] = 0;
          FUN_080017b4();
        }
      }
    }
  } while( true );
}



/* ----------------------------------------
 * FUN_08004154 @ 0x8004154
 * Motor control / FOC algorithm
 * ---------------------------------------- */

void FUN_08004154(int param_1,undefined2 *param_2)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_0800419c;
  param_2[5] = (short)DAT_0800419c;
  iVar1 = -iVar4;
  param_2[4] = (short)iVar1;
  *param_2 = (short)param_1;
  if (param_1 < 1) {
    if (param_1 < 0) {
      sVar2 = -1;
    }
    else {
      sVar2 = 0;
    }
  }
  else {
    sVar2 = 1;
  }
  iVar3 = (param_1 >> 2) + (int)(short)(sVar2 + param_2[3]);
  param_2[3] = sVar2 + param_2[3];
  if ((iVar3 < iVar4) || (iVar4 = iVar1, iVar1 < iVar3)) {
    param_2[3] = (short)iVar4;
    iVar3 = iVar4;
  }
  param_2[6] = (short)((uint)(iVar3 << 10) >> 0x10);
  return;
}



/* ----------------------------------------
 * FUN_080041a0 @ 0x80041a0
 * Motor control / FOC algorithm
 * ---------------------------------------- */

void FUN_080041a0(short *param_1,short *param_2)

{
  *param_2 = *param_1;
  param_2[1] = (short)((uint)(((int)*param_1 + param_1[1] * 2) * 0x93ce) >> 0x10);
  return;
}



/* ----------------------------------------
 * FUN_080041bc @ 0x80041bc
 * Motor control / FOC algorithm
 * ---------------------------------------- */

void FUN_080041bc(ushort *param_1)

{
  ushort uVar1;
  char cVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  
  if (param_1[1] < 0xafc) {
    param_1[1] = param_1[1] + 1;
  }
  uVar3 = (uint)param_1[1];
  if (uVar3 < 0xafc) {
    if ((0x3f5 < *(uint *)(param_1 + 4)) || (0x3f4 < uVar3 * 5)) goto LAB_080041fe;
  }
  else {
    param_1[4] = 0x41e8;
    param_1[5] = 0;
    *(undefined1 *)((int)param_1 + 0x13) = 0;
    *(undefined1 *)(param_1 + 10) = 0;
    *(undefined1 *)(param_1 + 0x1d) = 0;
LAB_080041fe:
    param_1[0xf] = param_1[0x14];
  }
  if ((*(uint *)(param_1 + 4) < 0x547) && (uVar3 * 6 < 0x547)) {
    if (5 < *(byte *)((int)param_1 + 0x17)) {
      *(undefined1 *)(param_1 + 0xb) = 0;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0xb) = 1;
    *(undefined1 *)((int)param_1 + 0x17) = 0;
  }
  uVar4 = *param_1;
  uVar3 = (uint)uVar4;
  uVar5 = (uint)param_1[0xd];
  if (*(char *)((int)param_1 + 0x3b) == '\0') {
    if (*(char *)((int)param_1 + 0x15) != '\x01') {
      if (*(char *)((int)param_1 + 0x39) == '\0') {
        uVar7 = (uint)param_1[0xf];
LAB_08004294:
        if (uVar5 <= uVar7 + uVar3) goto LAB_080042c4;
      }
      else {
LAB_080042a2:
        if (uVar5 < uVar3) {
          *(undefined1 *)((int)param_1 + 0x39) = 0;
        }
      }
LAB_080042ba:
      uVar4 = -uVar4;
      goto LAB_080042bc;
    }
    uVar7 = (uint)param_1[0xf];
    if (uVar7 != 0) {
      if ((char)param_1[0x1c] != '\0') goto LAB_08004294;
      if (uVar5 < uVar3) {
        *(undefined1 *)(param_1 + 0x1c) = 1;
      }
      goto LAB_080042ba;
    }
    if (*(char *)((int)param_1 + 0x39) != '\0') goto LAB_080042a2;
    if (uVar3 < uVar5) goto LAB_080042ba;
LAB_080042c4:
    param_1[0xd] = (ushort)uVar7;
  }
  else {
    if (*(char *)((int)param_1 + 0x15) == '\x06') {
      uVar7 = (uint)param_1[0xf];
      if (uVar7 == 0xffff) {
        if (*(char *)((int)param_1 + 0x39) != '\0') goto LAB_08004240;
      }
      else if ((char)param_1[0x1c] == '\0') {
        if (0xffff - uVar3 < uVar5) {
          *(undefined1 *)(param_1 + 0x1c) = 1;
        }
        goto LAB_080042bc;
      }
    }
    else {
      if (*(char *)((int)param_1 + 0x39) != '\0') {
LAB_08004240:
        if (0xffff - uVar3 < uVar5) {
          *(undefined1 *)((int)param_1 + 0x39) = 0;
        }
        goto LAB_080042bc;
      }
      uVar7 = (uint)param_1[0xf];
    }
    if ((int)(uVar7 - uVar3) <= (int)uVar5) goto LAB_080042c4;
LAB_080042bc:
    param_1[0xd] = uVar4 + param_1[0xd];
  }
  cVar2 = FUN_08002348();
  *(char *)(param_1 + 8) = cVar2;
  if ((cVar2 == '\0') || (cVar2 == '\a')) {
    if ((byte)param_1[9] < 0x1e) {
      *(byte *)(param_1 + 9) = (byte)param_1[9] + 1;
      *(undefined1 *)(param_1 + 8) = *(undefined1 *)((int)param_1 + 0x11);
    }
  }
  else {
    *(undefined1 *)(param_1 + 9) = 0;
  }
  if ((uint)(byte)param_1[8] == (uint)*(byte *)((int)param_1 + 0x11)) goto LAB_08004630;
  *(undefined1 *)((int)param_1 + 0x39) = 0;
  iVar6 = DAT_0800465c;
  *(undefined1 *)((int)param_1 + 0x13) = 1;
  uVar4 = *(short *)(iVar6 + (uint)(byte)param_1[8] * 2) - (ushort)*(byte *)((int)param_1 + 0x15);
  param_1[7] = uVar4;
  if ((uVar4 == 1) || (uVar4 == 0xfffb)) {
    *(undefined1 *)((int)param_1 + 0x3b) = 1;
  }
  else if ((uVar4 == 0xffff) || (uVar4 == 5)) {
    *(undefined1 *)((int)param_1 + 0x3b) = 0;
  }
  if ((char)param_1[0x1e] != *(char *)((int)param_1 + 0x3b)) {
    param_1[4] = 0x41e8;
    param_1[5] = 0;
    *(undefined1 *)((int)param_1 + 0x13) = 0;
    *(undefined1 *)(param_1 + 10) = 0;
    *(undefined1 *)(param_1 + 0x1d) = 0;
  }
  *(char *)(param_1 + 0x1e) = *(char *)((int)param_1 + 0x3b);
  if (*(byte *)((int)param_1 + 0x17) < 6) {
    *(byte *)((int)param_1 + 0x17) = *(byte *)((int)param_1 + 0x17) + 1;
  }
  param_1[(byte)param_1[0x1d] + 0x16] = param_1[1];
  param_1[1] = 0;
  if ((char)param_1[10] == '\0') {
    if (*(char *)((int)param_1 + 0x13) == '\0') {
      param_1[4] = 0x41e8;
      param_1[5] = 0;
      *(undefined1 *)(param_1 + 0xb) = 1;
    }
    else {
      *(uint *)(param_1 + 4) = (uint)param_1[(byte)param_1[0x1d] + 0x16] * 6;
    }
    if ((char)param_1[0x1d] != '\x05') goto LAB_0800439c;
    *(undefined1 *)(param_1 + 10) = 1;
LAB_080043a4:
    *(undefined1 *)(param_1 + 0x1d) = 0;
  }
  else {
    *(uint *)(param_1 + 4) =
         (uint)param_1[0x16] + (uint)param_1[0x17] + (uint)param_1[0x18] + (uint)param_1[0x19] +
         (uint)param_1[0x1a] + (uint)param_1[0x1b];
LAB_0800439c:
    if (4 < (byte)param_1[0x1d]) goto LAB_080043a4;
    *(byte *)(param_1 + 0x1d) = (byte)param_1[0x1d] + 1;
  }
  if (*(uint *)(param_1 + 4) < 0x2e) {
    param_1[4] = 0x2e;
    param_1[5] = 0;
  }
  cVar2 = *(char *)(iVar6 + (uint)(byte)param_1[8] * 2);
  *(char *)((int)param_1 + 0x15) = cVar2;
  *(byte *)((int)param_1 + 0x11) = (byte)param_1[8];
  if (cVar2 == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    FUN_08002df8(DAT_08004660,0);
    goto LAB_08004606;
  }
  if (*(char *)((int)param_1 + 0x3b) == '\0') {
    switch(cVar2) {
    default:
      goto switchD_080044cc_caseD_0;
    case '\x01':
      param_1[0x10] = 0x1555;
      param_1[0x11] = 0x2aaa;
      param_1[0x12] = 0x16c1;
      param_1[0x13] = 0x3e93;
      param_1[0x14] = 0;
      uVar4 = 0xec16;
      break;
    case '\x02':
      param_1[0x10] = 0x3fff;
      param_1[0x11] = 0x5555;
      param_1[0x12] = 0x416c;
      param_1[0x13] = 0x693e;
      param_1[0x14] = 0x2aaa;
      param_1[0x15] = 0x16c1;
      goto switchD_080044cc_caseD_0;
    case '\x03':
      param_1[0x10] = 0x6aaa;
      param_1[0x11] = 0x8000;
      param_1[0x12] = 0x6c17;
      param_1[0x13] = 0x93e9;
      param_1[0x14] = 0x5555;
      uVar4 = 0x416c;
      break;
    case '\x04':
      param_1[0x10] = 0x9555;
      param_1[0x11] = 0xaaaa;
      param_1[0x12] = 0x96c1;
      param_1[0x13] = 0xbe93;
      param_1[0x14] = 0x8000;
      uVar4 = 0x6c17;
      break;
    case '\x05':
      param_1[0x10] = 0xbfff;
      param_1[0x11] = 0xd555;
      param_1[0x12] = 0xc16c;
      param_1[0x13] = 0xe93e;
      param_1[0x14] = 0xaaaa;
      uVar4 = 0x96c1;
      break;
    case '\x06':
      param_1[0x10] = 0xeaaa;
      param_1[0x11] = 0xffff;
      param_1[0x12] = 0xec16;
      param_1[0x13] = 0x13e9;
      param_1[0x14] = 0xd555;
      param_1[0x15] = 0xc16c;
      if ((char)param_1[0x1c] == '\0') {
        *(undefined1 *)((int)param_1 + 0x39) = 1;
      }
      goto switchD_080044cc_caseD_0;
    }
    param_1[0x15] = uVar4;
switchD_080044cc_caseD_0:
    uVar4 = param_1[0xd];
    uVar1 = param_1[0x11];
    goto LAB_08004598;
  }
  switch(cVar2) {
  case '\x01':
    param_1[0x10] = 0x1555;
    param_1[0x11] = 0;
    param_1[0x12] = 0xec16;
    param_1[0x13] = 0x13e9;
    param_1[0x14] = 0x2aaa;
    param_1[0x15] = 0x3e93;
    if ((char)param_1[0x1c] == '\0') {
      *(undefined1 *)((int)param_1 + 0x39) = 1;
    }
    break;
  case '\x02':
    param_1[0x10] = 0x3fff;
    param_1[0x11] = 0x2aaa;
    param_1[0x12] = 0x16c1;
    param_1[0x13] = 0x3e93;
    param_1[0x14] = 0x5555;
    param_1[0x15] = 0x693e;
    break;
  case '\x03':
    param_1[0x10] = 0x6aaa;
    param_1[0x11] = 0x5555;
    param_1[0x12] = 0x416c;
    param_1[0x13] = 0x693e;
    param_1[0x14] = 0x8000;
    uVar4 = 0x93e9;
    goto LAB_0800447c;
  case '\x04':
    param_1[0x10] = 0x9555;
    param_1[0x11] = 0x8000;
    param_1[0x12] = 0x6c17;
    param_1[0x13] = 0x93e9;
    param_1[0x14] = 0xaaaa;
    uVar4 = 0xbe93;
    goto LAB_0800447c;
  case '\x05':
    param_1[0x10] = 0xbfff;
    param_1[0x11] = 0xaaaa;
    param_1[0x12] = 0x96c1;
    param_1[0x13] = 0xbe93;
    param_1[0x14] = 0xd555;
    uVar4 = 0xe93e;
LAB_0800447c:
    param_1[0x15] = uVar4;
    break;
  case '\x06':
    param_1[0x10] = 0xeaaa;
    param_1[0x11] = 0xd555;
    param_1[0x12] = 0xc16c;
    param_1[0x13] = 0xe93e;
    param_1[0x14] = 0xffff;
    param_1[0x15] = 0x13e9;
  }
  uVar4 = param_1[0x11];
  uVar1 = param_1[0xd];
LAB_08004598:
  param_1[0xe] = uVar4 - uVar1;
  if ((*(uint *)(param_1 + 4) < 0x3f6) && ((char)param_1[10] != '\0')) {
    param_1[0xf] = param_1[0x15];
    if (*(char *)((int)param_1 + 0x3b) == '\0') {
      if (cVar2 != '\x06') goto LAB_080045cc;
      if ((char)param_1[0x1c] == '\0') goto LAB_080045f2;
LAB_080045c8:
      uVar4 = param_1[0xd];
LAB_080045d4:
      if (uVar4 < param_1[0x12]) {
LAB_080045da:
        param_1[0xd] = param_1[0x11];
        goto LAB_080045de;
      }
    }
    else {
      if (cVar2 != '\x01') {
LAB_080045cc:
        uVar4 = param_1[0xd];
        if (uVar4 <= param_1[0x13]) goto LAB_080045d4;
        goto LAB_080045da;
      }
      if ((char)param_1[0x1c] == '\0') goto LAB_080045c8;
LAB_080045f2:
      if (param_1[0x13] < param_1[0xd]) goto LAB_080045da;
    }
  }
  else {
    param_1[0xd] = param_1[0x11];
    param_1[0xf] = param_1[0x14];
LAB_080045de:
    param_1[0xe] = 0;
    *(undefined1 *)((int)param_1 + 0x39) = 0;
  }
LAB_08004606:
  uVar3 = *(uint *)(param_1 + 4);
  if (uVar3 < 0x3f6) {
    iVar6 = uVar3 - *(int *)(param_1 + 2);
  }
  else {
    iVar6 = 0;
  }
  *param_1 = (ushort)(((int)(short)param_1[0xe] + (iVar6 + uVar3 >> 1) + 0xffff) / (iVar6 + uVar3));
  *(undefined1 *)(param_1 + 0x1c) = 0;
  *(uint *)(param_1 + 2) = uVar3;
LAB_08004630:
  bVar8 = (char)param_1[0xb] != '\0';
  if (bVar8) {
    param_1[0xd] = param_1[0x10];
  }
  uVar4 = param_1[0xd];
  param_1[0xc] = uVar4;
  if (bVar8) {
    uVar4 = uVar4 + 0x127c;
  }
  else if (*(char *)((int)param_1 + 0x3b) == '\0') {
    uVar4 = uVar4 + 0xe38;
  }
  else {
    uVar4 = uVar4 + 0x16c1;
  }
  param_1[0xc] = uVar4;
  return;
}



/* ----------------------------------------
 * FUN_08004664 @ 0x8004664
 * Motor control / FOC algorithm
 * ---------------------------------------- */

void FUN_08004664(ushort *param_1)

{
  ushort uVar1;
  char cVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  
  if (param_1[1] < 0xafc) {
    param_1[1] = param_1[1] + 1;
  }
  uVar3 = (uint)param_1[1];
  if (uVar3 < 0xafc) {
    if ((0x3f5 < *(uint *)(param_1 + 4)) || (0x3f4 < uVar3 * 5)) goto LAB_080046a6;
  }
  else {
    param_1[4] = 0x41e8;
    param_1[5] = 0;
    *(undefined1 *)((int)param_1 + 0x13) = 0;
    *(undefined1 *)(param_1 + 10) = 0;
    *(undefined1 *)(param_1 + 0x1d) = 0;
LAB_080046a6:
    param_1[0xf] = param_1[0x14];
  }
  if ((*(uint *)(param_1 + 4) < 0x547) && (uVar3 * 6 < 0x547)) {
    if (5 < *(byte *)((int)param_1 + 0x17)) {
      *(undefined1 *)(param_1 + 0xb) = 0;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0xb) = 1;
    *(undefined1 *)((int)param_1 + 0x17) = 0;
  }
  uVar4 = *param_1;
  uVar3 = (uint)uVar4;
  uVar5 = (uint)param_1[0xd];
  if (*(char *)((int)param_1 + 0x3b) == '\0') {
    if (*(char *)((int)param_1 + 0x15) != '\x01') {
      if (*(char *)((int)param_1 + 0x39) == '\0') {
        uVar7 = (uint)param_1[0xf];
LAB_0800473c:
        if (uVar5 <= uVar7 + uVar3) goto LAB_0800476c;
      }
      else {
LAB_0800474a:
        if (uVar5 < uVar3) {
          *(undefined1 *)((int)param_1 + 0x39) = 0;
        }
      }
LAB_08004762:
      uVar4 = -uVar4;
      goto LAB_08004764;
    }
    uVar7 = (uint)param_1[0xf];
    if (uVar7 != 0) {
      if ((char)param_1[0x1c] != '\0') goto LAB_0800473c;
      if (uVar5 < uVar3) {
        *(undefined1 *)(param_1 + 0x1c) = 1;
      }
      goto LAB_08004762;
    }
    if (*(char *)((int)param_1 + 0x39) != '\0') goto LAB_0800474a;
    if (uVar3 < uVar5) goto LAB_08004762;
LAB_0800476c:
    param_1[0xd] = (ushort)uVar7;
  }
  else {
    if (*(char *)((int)param_1 + 0x15) == '\x06') {
      uVar7 = (uint)param_1[0xf];
      if (uVar7 == 0xffff) {
        if (*(char *)((int)param_1 + 0x39) != '\0') goto LAB_080046e8;
      }
      else if ((char)param_1[0x1c] == '\0') {
        if (0xffff - uVar3 < uVar5) {
          *(undefined1 *)(param_1 + 0x1c) = 1;
        }
        goto LAB_08004764;
      }
    }
    else {
      if (*(char *)((int)param_1 + 0x39) != '\0') {
LAB_080046e8:
        if (0xffff - uVar3 < uVar5) {
          *(undefined1 *)((int)param_1 + 0x39) = 0;
        }
        goto LAB_08004764;
      }
      uVar7 = (uint)param_1[0xf];
    }
    if ((int)(uVar7 - uVar3) <= (int)uVar5) goto LAB_0800476c;
LAB_08004764:
    param_1[0xd] = uVar4 + param_1[0xd];
  }
  cVar2 = hall_read_state();
  *(char *)(param_1 + 8) = cVar2;
  if ((cVar2 == '\0') || (cVar2 == '\a')) {
    if ((byte)param_1[9] < 0x1e) {
      *(byte *)(param_1 + 9) = (byte)param_1[9] + 1;
      *(undefined1 *)(param_1 + 8) = *(undefined1 *)((int)param_1 + 0x11);
    }
  }
  else {
    *(undefined1 *)(param_1 + 9) = 0;
  }
  if ((uint)(byte)param_1[8] == (uint)*(byte *)((int)param_1 + 0x11)) goto LAB_08004ad8;
  *(undefined1 *)((int)param_1 + 0x39) = 0;
  iVar6 = DAT_08004b04;
  *(undefined1 *)((int)param_1 + 0x13) = 1;
  uVar4 = *(short *)(iVar6 + (uint)(byte)param_1[8] * 2) - (ushort)*(byte *)((int)param_1 + 0x15);
  param_1[7] = uVar4;
  if ((uVar4 == 1) || (uVar4 == 0xfffb)) {
    *(undefined1 *)((int)param_1 + 0x3b) = 1;
  }
  else if ((uVar4 == 0xffff) || (uVar4 == 5)) {
    *(undefined1 *)((int)param_1 + 0x3b) = 0;
  }
  if ((char)param_1[0x1e] != *(char *)((int)param_1 + 0x3b)) {
    param_1[4] = 0x41e8;
    param_1[5] = 0;
    *(undefined1 *)((int)param_1 + 0x13) = 0;
    *(undefined1 *)(param_1 + 10) = 0;
    *(undefined1 *)(param_1 + 0x1d) = 0;
  }
  *(char *)(param_1 + 0x1e) = *(char *)((int)param_1 + 0x3b);
  if (*(byte *)((int)param_1 + 0x17) < 6) {
    *(byte *)((int)param_1 + 0x17) = *(byte *)((int)param_1 + 0x17) + 1;
  }
  param_1[(byte)param_1[0x1d] + 0x16] = param_1[1];
  param_1[1] = 0;
  if ((char)param_1[10] == '\0') {
    if (*(char *)((int)param_1 + 0x13) == '\0') {
      param_1[4] = 0x41e8;
      param_1[5] = 0;
      *(undefined1 *)(param_1 + 0xb) = 1;
    }
    else {
      *(uint *)(param_1 + 4) = (uint)param_1[(byte)param_1[0x1d] + 0x16] * 6;
    }
    if ((char)param_1[0x1d] != '\x05') goto LAB_08004844;
    *(undefined1 *)(param_1 + 10) = 1;
LAB_0800484c:
    *(undefined1 *)(param_1 + 0x1d) = 0;
  }
  else {
    *(uint *)(param_1 + 4) =
         (uint)param_1[0x16] + (uint)param_1[0x17] + (uint)param_1[0x18] + (uint)param_1[0x19] +
         (uint)param_1[0x1a] + (uint)param_1[0x1b];
LAB_08004844:
    if (4 < (byte)param_1[0x1d]) goto LAB_0800484c;
    *(byte *)(param_1 + 0x1d) = (byte)param_1[0x1d] + 1;
  }
  if (*(uint *)(param_1 + 4) < 0x2e) {
    param_1[4] = 0x2e;
    param_1[5] = 0;
  }
  cVar2 = *(char *)(iVar6 + (uint)(byte)param_1[8] * 2);
  *(char *)((int)param_1 + 0x15) = cVar2;
  *(byte *)((int)param_1 + 0x11) = (byte)param_1[8];
  if (cVar2 == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    FUN_08002df8(DAT_08004b08,0);
    goto LAB_08004aae;
  }
  if (*(char *)((int)param_1 + 0x3b) == '\0') {
    switch(cVar2) {
    default:
      goto switchD_08004974_caseD_0;
    case '\x01':
      param_1[0x10] = 0x1555;
      param_1[0x11] = 0x2aaa;
      param_1[0x12] = 0x16c1;
      param_1[0x13] = 0x3e93;
      param_1[0x14] = 0;
      uVar4 = 0xec16;
      break;
    case '\x02':
      param_1[0x10] = 0x3fff;
      param_1[0x11] = 0x5555;
      param_1[0x12] = 0x416c;
      param_1[0x13] = 0x693e;
      param_1[0x14] = 0x2aaa;
      param_1[0x15] = 0x16c1;
      goto switchD_08004974_caseD_0;
    case '\x03':
      param_1[0x10] = 0x6aaa;
      param_1[0x11] = 0x8000;
      param_1[0x12] = 0x6c17;
      param_1[0x13] = 0x93e9;
      param_1[0x14] = 0x5555;
      uVar4 = 0x416c;
      break;
    case '\x04':
      param_1[0x10] = 0x9555;
      param_1[0x11] = 0xaaaa;
      param_1[0x12] = 0x96c1;
      param_1[0x13] = 0xbe93;
      param_1[0x14] = 0x8000;
      uVar4 = 0x6c17;
      break;
    case '\x05':
      param_1[0x10] = 0xbfff;
      param_1[0x11] = 0xd555;
      param_1[0x12] = 0xc16c;
      param_1[0x13] = 0xe93e;
      param_1[0x14] = 0xaaaa;
      uVar4 = 0x96c1;
      break;
    case '\x06':
      param_1[0x10] = 0xeaaa;
      param_1[0x11] = 0xffff;
      param_1[0x12] = 0xec16;
      param_1[0x13] = 0x13e9;
      param_1[0x14] = 0xd555;
      param_1[0x15] = 0xc16c;
      if ((char)param_1[0x1c] == '\0') {
        *(undefined1 *)((int)param_1 + 0x39) = 1;
      }
      goto switchD_08004974_caseD_0;
    }
    param_1[0x15] = uVar4;
switchD_08004974_caseD_0:
    uVar4 = param_1[0xd];
    uVar1 = param_1[0x11];
    goto LAB_08004a40;
  }
  switch(cVar2) {
  case '\x01':
    param_1[0x10] = 0x1555;
    param_1[0x11] = 0;
    param_1[0x12] = 0xec16;
    param_1[0x13] = 0x13e9;
    param_1[0x14] = 0x2aaa;
    param_1[0x15] = 0x3e93;
    if ((char)param_1[0x1c] == '\0') {
      *(undefined1 *)((int)param_1 + 0x39) = 1;
    }
    break;
  case '\x02':
    param_1[0x10] = 0x3fff;
    param_1[0x11] = 0x2aaa;
    param_1[0x12] = 0x16c1;
    param_1[0x13] = 0x3e93;
    param_1[0x14] = 0x5555;
    param_1[0x15] = 0x693e;
    break;
  case '\x03':
    param_1[0x10] = 0x6aaa;
    param_1[0x11] = 0x5555;
    param_1[0x12] = 0x416c;
    param_1[0x13] = 0x693e;
    param_1[0x14] = 0x8000;
    uVar4 = 0x93e9;
    goto LAB_08004924;
  case '\x04':
    param_1[0x10] = 0x9555;
    param_1[0x11] = 0x8000;
    param_1[0x12] = 0x6c17;
    param_1[0x13] = 0x93e9;
    param_1[0x14] = 0xaaaa;
    uVar4 = 0xbe93;
    goto LAB_08004924;
  case '\x05':
    param_1[0x10] = 0xbfff;
    param_1[0x11] = 0xaaaa;
    param_1[0x12] = 0x96c1;
    param_1[0x13] = 0xbe93;
    param_1[0x14] = 0xd555;
    uVar4 = 0xe93e;
LAB_08004924:
    param_1[0x15] = uVar4;
    break;
  case '\x06':
    param_1[0x10] = 0xeaaa;
    param_1[0x11] = 0xd555;
    param_1[0x12] = 0xc16c;
    param_1[0x13] = 0xe93e;
    param_1[0x14] = 0xffff;
    param_1[0x15] = 0x13e9;
  }
  uVar4 = param_1[0x11];
  uVar1 = param_1[0xd];
LAB_08004a40:
  param_1[0xe] = uVar4 - uVar1;
  if ((*(uint *)(param_1 + 4) < 0x3f6) && ((char)param_1[10] != '\0')) {
    param_1[0xf] = param_1[0x15];
    if (*(char *)((int)param_1 + 0x3b) == '\0') {
      if (cVar2 != '\x06') goto LAB_08004a74;
      if ((char)param_1[0x1c] == '\0') goto LAB_08004a9a;
LAB_08004a70:
      uVar4 = param_1[0xd];
LAB_08004a7c:
      if (uVar4 < param_1[0x12]) {
LAB_08004a82:
        param_1[0xd] = param_1[0x11];
        goto LAB_08004a86;
      }
    }
    else {
      if (cVar2 != '\x01') {
LAB_08004a74:
        uVar4 = param_1[0xd];
        if (uVar4 <= param_1[0x13]) goto LAB_08004a7c;
        goto LAB_08004a82;
      }
      if ((char)param_1[0x1c] == '\0') goto LAB_08004a70;
LAB_08004a9a:
      if (param_1[0x13] < param_1[0xd]) goto LAB_08004a82;
    }
  }
  else {
    param_1[0xd] = param_1[0x11];
    param_1[0xf] = param_1[0x14];
LAB_08004a86:
    param_1[0xe] = 0;
    *(undefined1 *)((int)param_1 + 0x39) = 0;
  }
LAB_08004aae:
  uVar3 = *(uint *)(param_1 + 4);
  if (uVar3 < 0x3f6) {
    iVar6 = uVar3 - *(int *)(param_1 + 2);
  }
  else {
    iVar6 = 0;
  }
  *param_1 = (ushort)(((int)(short)param_1[0xe] + (iVar6 + uVar3 >> 1) + 0xffff) / (iVar6 + uVar3));
  *(undefined1 *)(param_1 + 0x1c) = 0;
  *(uint *)(param_1 + 2) = uVar3;
LAB_08004ad8:
  bVar8 = (char)param_1[0xb] != '\0';
  if (bVar8) {
    param_1[0xd] = param_1[0x10];
  }
  uVar4 = param_1[0xd];
  param_1[0xc] = uVar4;
  if (bVar8) {
    uVar4 = uVar4 + 0x127c;
  }
  else if (*(char *)((int)param_1 + 0x3b) == '\0') {
    uVar4 = uVar4 + 0xe38;
  }
  else {
    uVar4 = uVar4 + 0x16c1;
  }
  param_1[0xc] = uVar4;
  return;
}



/* ----------------------------------------
 * clarke_transform @ 0x8004b0c
 * Clarke transform: 3-phase to alpha-beta
 * ---------------------------------------- */

void clarke_transform(short *param_1,undefined2 *param_2,short *param_3)

{
  *param_2 = (short)((uint)(((int)param_3[1] * (int)*param_1 - (int)param_1[1] * (int)*param_3) * 2)
                    >> 0x10);
  param_2[1] = (short)((uint)(((int)*param_1 * (int)*param_3 + (int)param_3[1] * (int)param_1[1]) *
                             2) >> 0x10);
  return;
}



/* ----------------------------------------
 * pi_controller @ 0x8004b48
 * PI controller for current/speed regulation
 * ---------------------------------------- */

void pi_controller(short *param_1,short *param_2,short *param_3)

{
  int iVar1;
  
  iVar1 = (((int)((int)param_3[1] * (int)*param_1 +
                 ((uint)((int)param_3[1] * (int)*param_1 >> 0x1f) >> 0x11)) >> 0xf) +
          ((int)((int)*param_3 * (int)param_1[1] +
                ((uint)((int)*param_3 * (int)param_1[1] >> 0x1f) >> 0x11)) >> 0xf)) * 0x30a3;
  *param_2 = (short)((int)(*param_2 * 0x4f5d + ((uint)(*param_2 * 0x4f5d >> 0x1f) >> 0x11)) >> 0xf)
             + (short)((int)(iVar1 + ((uint)(iVar1 >> 0x1f) >> 0x11)) >> 0xf);
  return;
}



/* ----------------------------------------
 * svpwm_calculate @ 0x8004b96
 * Space Vector PWM - calculates 3-phase duty cycles
 * ---------------------------------------- */

void svpwm_calculate(short *param_1,undefined2 *param_2,int param_3)

{
  int iVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  int unaff_r4;
  undefined2 uVar8;
  int unaff_r5;
  int iVar9;
  char cVar10;
  
  iVar6 = (int)param_1[1];
  iVar9 = (int)(*param_1 * 0xddb + ((uint)(*param_1 * 0xddb >> 0x1f) >> 0x15)) >> 0xb;
  iVar5 = iVar9 - iVar6;
  iVar9 = iVar6 + iVar9;
  iVar1 = -iVar9;
  cVar10 = 0 < iVar6;
  if (0 < iVar5) {
    cVar10 = cVar10 + '\x02';
  }
  if (iVar9 != 0 && -1 < iVar1) {
    cVar10 = cVar10 + '\x04';
  }
  iVar9 = (iVar1 >> 1) * -0xff;
  iVar1 = (iVar5 >> 1) * -0xff;
  sVar3 = (short)((int)(iVar6 * 0xff + ((uint)(iVar6 * 0xff >> 0x1f) >> 0x16)) >> 10);
  sVar2 = (short)((int)(iVar1 + ((uint)(iVar1 >> 0x1f) >> 0x16)) >> 10);
  sVar4 = (short)((int)(iVar9 + ((uint)(iVar9 >> 0x1f) >> 0x16)) >> 10);
  switch(cVar10) {
  case '\0':
    uVar8 = 0xff;
    uVar7 = 0xff;
    param_3 = 0xff;
    goto LAB_08004c88;
  case '\x01':
  case '\x06':
    unaff_r5 = (int)(short)((0xff - sVar2) + sVar4);
    unaff_r4 = (int)(short)(sVar2 + sVar4 + 0xff);
    sVar4 = (0xff - sVar2) - sVar4;
    break;
  case '\x02':
  case '\x05':
    unaff_r5 = (int)(short)((sVar4 - sVar3) + 0xff);
    unaff_r4 = (int)(short)((0xff - sVar4) + sVar3);
    sVar4 = (0xff - sVar4) - sVar3;
    break;
  case '\x03':
  case '\x04':
    unaff_r5 = (int)(short)((0xff - sVar2) + sVar3);
    unaff_r4 = (int)(short)(sVar2 + sVar3 + 0xff);
    sVar4 = (sVar2 - sVar3) + 0xff;
    break;
  default:
    goto switchD_08004c0c_default;
  }
  param_3 = (int)sVar4;
switchD_08004c0c_default:
  if (unaff_r5 < 0) {
    unaff_r5 = 0;
  }
  else if (0x1ff < unaff_r5) {
    unaff_r5 = 0x200;
  }
  uVar8 = (undefined2)unaff_r5;
  if (unaff_r4 < 0) {
    unaff_r4 = 0;
  }
  else if (0x1ff < unaff_r4) {
    unaff_r4 = 0x200;
  }
  uVar7 = (undefined2)unaff_r4;
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0x1ff < param_3) {
    param_3 = 0x200;
  }
LAB_08004c88:
  *param_2 = uVar8;
  param_2[1] = uVar7;
  param_2[2] = (short)param_3;
  return;
}



/* ----------------------------------------
 * FUN_08004c90 @ 0x8004c90
 * Motor control / FOC algorithm
 * ---------------------------------------- */

uint FUN_08004c90(uint param_1,uint param_2)

{
  uint extraout_r1;
  uint uVar1;
  bool bVar2;
  
  uVar1 = (param_2 & 0x7fffffff) + 0xc8000000;
  bVar2 = uVar1 == 0x100000;
  if (0xfffff < uVar1) {
    bVar2 = uVar1 == 0xff00000;
  }
  if ((0xfffff >= uVar1 || 0xff00000 < uVar1) || bVar2) {
    if (0xfffff < (int)uVar1) {
      if (0xffdfffff < param_2 << 1) {
        FUN_08005278(param_1);
        param_2 = extraout_r1;
      }
      return (param_2 >> 0x17 | 0xff) << 0x17;
    }
    return param_2 & 0x80000000;
  }
  bVar2 = (param_1 & 0x10000000) != 0;
  uVar1 = (param_2 & 0x80000000 | uVar1 * 8) + (param_1 >> 0x1d) + (uint)bVar2;
  if ((param_1 & 0xfffffff) == 0) {
    if (bVar2) {
      uVar1 = uVar1 & 0xfffffffe;
    }
    return uVar1;
  }
  return uVar1;
}



/* ----------------------------------------
 * motor_commutation @ 0x8004cf4
 * 6-step BLDC motor commutation state machine
 * ---------------------------------------- */

/* WARNING: Control flow encountered bad instruction data */

ulonglong motor_commutation(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  byte bVar13;
  
  if ((int)(param_2 ^ param_4) < 0) {
    param_4 = param_4 ^ 0x80000000;
    bVar11 = param_3 <= param_1;
    uVar6 = param_1 - param_3;
    if (param_2 <= param_4 && (uint)bVar11 <= param_2 - param_4) {
      bVar12 = CARRY4(param_3,uVar6);
      param_3 = param_3 + uVar6;
      uVar7 = (param_2 - param_4) - (uint)!bVar11 ^ 0x80000000;
      param_4 = param_4 + uVar7 + bVar12;
      bVar11 = param_1 < uVar6;
      param_1 = param_1 - uVar6;
      param_2 = (param_2 - uVar7) - (uint)bVar11;
    }
    uVar7 = param_2 >> 0x14;
    uVar6 = uVar7 - (param_4 >> 0x14);
    if ((DAT_080054f0 & param_4 << 1) == 0 || DAT_080054f0 == uVar7 << 0x15) {
      if (DAT_080054f0 != uVar7 << 0x15) {
        if ((param_2 & DAT_080054f0 >> 1) == 0) {
          param_2 = 0;
          param_1 = 0;
        }
        return CONCAT44(param_2,param_1);
      }
      FUN_08005278();
      do {
        software_interrupt(0x40);
      } while( true );
    }
    uVar5 = -param_3;
    uVar1 = param_2 & ~(uVar7 << 0x14);
    iVar8 = ((int)DAT_080054f0 >> 1) - (param_4 & ~((int)DAT_080054f0 >> 1));
    if (param_3 != 0) {
      iVar8 = iVar8 + -1;
    }
    if (uVar6 < 0x21) {
      uVar2 = uVar5 >> (uVar6 & 0xff);
      uVar9 = param_1 + uVar2;
      uVar1 = uVar1 + (iVar8 >> (uVar6 & 0xff)) + (uint)CARRY4(param_1,uVar2);
      uVar10 = iVar8 << (0x20 - uVar6 & 0xff);
      uVar2 = uVar9 + uVar10;
      bVar11 = CARRY4(uVar1,(uint)CARRY4(uVar9,uVar10));
      iVar8 = uVar1 + CARRY4(uVar9,uVar10);
      uVar6 = 0x20 - uVar6;
    }
    else {
      uVar5 = (uint)(param_3 * -2 != 0) | (iVar8 * 2 + (uint)CARRY4(uVar5,uVar5)) * 2;
      uVar6 = uVar6 - 0x20;
      if (0x1d < uVar6) {
        return CONCAT44(uVar1 + uVar7 * 0x100000,param_1);
      }
      uVar9 = iVar8 >> (uVar6 & 0xff);
      uVar2 = param_1 + uVar9;
      bVar11 = uVar1 != 0 || CARRY4(uVar1 - 1,(uint)CARRY4(param_1,uVar9));
      iVar8 = (uVar1 - 1) + (uint)CARRY4(param_1,uVar9);
      uVar6 = 0x1e - uVar6;
    }
    if (-1 < iVar8) {
      iVar4 = uVar5 << (uVar6 & 0xff);
      iVar8 = iVar8 + uVar7 * 0x100000;
      if (-1 < iVar4) {
        return CONCAT44(iVar8,uVar2);
      }
      uVar2 = uVar2 + 1;
      if (uVar2 != 0 && iVar4 != -0x80000000) {
        return CONCAT44(iVar8,uVar2);
      }
      if (uVar2 == 0) {
        iVar8 = iVar8 + 1;
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 & 0xfffffffe;
      }
      return CONCAT44(iVar8,uVar2);
    }
    uVar1 = uVar6 + 1 & 0xff;
    bVar11 = uVar1 == 0 && bVar11 || uVar1 != 0 && (uVar5 << uVar1 - 1 & 0x80000000) != 0;
    uVar9 = uVar2 * 2 + (uint)bVar11;
    uVar6 = iVar8 * 2 + (uint)(CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)bVar11));
    uVar2 = uVar6 + uVar7 * 0x200000;
    bVar11 = (uVar2 >> 0x14 & 1) != 0;
    if (bVar11 && uVar2 >> 0x15 != 0) {
      uVar2 = -((int)(uVar5 << uVar1) >> 0x1f);
      uVar10 = uVar9 + uVar2;
      bVar11 = uVar10 == 0;
      iVar8 = uVar6 + uVar7 * 0x100000;
      if (!CARRY4(uVar9,uVar2)) {
        bVar11 = uVar5 << uVar1 == -0x80000000;
      }
      if (!bVar11) {
        return CONCAT44(iVar8,uVar10);
      }
      if (uVar10 == 0) {
        iVar8 = iVar8 + 1;
        uVar10 = 0;
      }
      else {
        uVar10 = uVar10 & 0xfffffffe;
      }
      return CONCAT44(iVar8,uVar10);
    }
    if (!bVar11) {
      iVar8 = uVar6 + 0x200000;
      if (iVar8 == 0) {
        uVar6 = uVar9 << LZCOUNT(uVar9);
        if (uVar6 == 0) {
          return (ulonglong)uVar9;
        }
        iVar4 = ((uVar7 & 0xfffff7ff) - LZCOUNT(uVar9)) + -0x17;
        iVar8 = uVar6 << 0x15;
        uVar6 = uVar6 >> 0xb;
      }
      else {
        uVar5 = LZCOUNT(iVar8) - 0xb;
        iVar4 = ((uVar7 & 0xfffff7ff) - uVar5) + -2;
        uVar6 = iVar8 << (uVar5 & 0xff) | uVar9 >> (0x20 - uVar5 & 0xff);
        iVar8 = uVar9 << (uVar5 & 0xff);
      }
      iVar3 = uVar6 + (param_2 & 0x80000000) + iVar4 * 0x100000;
      if (-1 < iVar4) {
        return CONCAT44(iVar3,iVar8);
      }
      return (ulonglong)(iVar3 + 0x60000000U & 0x80000000) << 0x20;
    }
    uVar7 = ((int)uVar6 >> 1) + uVar7 * 0x100000;
    uVar6 = (uint)((uVar6 & 1) != 0) << 0x1f | uVar9 >> 1;
    if (uVar7 * 2 == 0 && uVar6 == 0) {
      return (ulonglong)uVar6;
    }
    if (0x1fffff < uVar7 * 2) {
      return CONCAT44(uVar7,uVar6);
    }
    return (ulonglong)(uVar7 & 0x80000000) << 0x20;
  }
  uVar6 = param_1 - param_3;
  iVar8 = (param_2 - param_4) - (uint)(param_3 > param_1);
  if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
    bVar11 = CARRY4(param_3,uVar6);
    param_3 = param_3 + uVar6;
    param_4 = param_4 + iVar8 + (uint)bVar11;
    bVar11 = param_1 < uVar6;
    param_1 = param_1 - uVar6;
    param_2 = (param_2 - iVar8) - (uint)bVar11;
  }
  uVar7 = param_2 >> 0x14;
  uVar6 = uVar7 - (param_4 >> 0x14);
  if ((DAT_08004e40 & param_4 << 1) == 0 || DAT_08004e40 == uVar7 << 0x15) {
    if (DAT_08004e40 != uVar7 << 0x15) {
      if ((param_2 & DAT_08004e40 >> 1) == 0) {
        param_2 = param_2 & 0x80000000;
        param_1 = 0;
      }
      return CONCAT44(param_2,param_1);
    }
    FUN_08005278();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  param_2 = param_2 & ~(uVar7 << 0x14);
  uVar5 = param_4 & ~DAT_08004e40 | 0x100000;
  if (uVar6 < 0x21) {
    uVar9 = param_3 >> (uVar6 & 0xff);
    uVar1 = param_1 + uVar9;
    uVar10 = uVar5 << (0x20 - uVar6 & 0xff);
    uVar2 = uVar1 + uVar10;
    param_2 = param_2 + (uVar5 >> (uVar6 & 0xff)) + (uint)CARRY4(param_1,uVar9) +
              (uint)CARRY4(uVar1,uVar10);
    uVar6 = 0x20 - uVar6;
    if (param_2 < 0x100000) {
      param_2 = param_2 + uVar7 * 0x100000;
      goto LAB_08004d70;
    }
LAB_08004dd2:
    bVar13 = (byte)uVar2 & 1;
    uVar5 = (uint)((param_2 + 0x100000 & 1) != 0) << 0x1f | uVar2 >> 1;
    param_2 = (param_2 + 0x100000 >> 1) + uVar7 * 0x100000;
    if ((uVar2 & 1) == 0) {
LAB_08004e00:
      if (param_2 * 2 < 0xffe00000) {
        return CONCAT44(param_2,uVar5);
      }
      goto LAB_08005314;
    }
    bVar11 = CARRY4(uVar5,(uint)bVar13);
    uVar5 = uVar5 + bVar13;
    uVar7 = uVar5;
    if (!bVar11) {
      uVar7 = param_3 << (uVar6 & 0xff);
    }
    if (uVar7 != 0) goto LAB_08004e00;
  }
  else {
    param_3 = uVar5 * 2 + (uint)(param_3 != 0);
    uVar1 = uVar6 - 0x20;
    uVar6 = 0x1f - uVar1;
    if (uVar1 < 0x20) {
      uVar5 = uVar5 >> (uVar1 & 0xff);
      uVar2 = param_1 + uVar5;
    }
    else {
      uVar6 = 0;
      uVar2 = param_1;
    }
    param_2 = param_2 + uVar7 * 0x100000 + (uint)(uVar1 < 0x20 && CARRY4(param_1,uVar5));
    if (uVar7 != param_2 >> 0x14) {
      param_2 = param_2 + uVar7 * -0x100000;
      goto LAB_08004dd2;
    }
LAB_08004d70:
    param_3 = param_3 << (uVar6 & 0xff);
    if (-1 < (int)param_3) {
      return CONCAT44(param_2,uVar2);
    }
    uVar5 = uVar2 + 1;
    uVar6 = uVar5;
    if (uVar2 != 0xffffffff) {
      uVar6 = param_3 & 0x7fffffff;
    }
    if (uVar6 != 0) {
      return CONCAT44(param_2,uVar5);
    }
  }
  if (uVar5 == 0) {
    param_2 = param_2 + 1;
    uVar5 = 0;
  }
  else {
    uVar5 = uVar5 & 0xfffffffe;
  }
  if (param_2 << 1 < 0xffe00000) {
    return CONCAT44(param_2,uVar5);
  }
LAB_08005314:
  return (ulonglong)((uint)((int)(param_2 + 0xa0000000) < 0) << 0x1f | 0x7ff00000) << 0x20;
}



/* ----------------------------------------
 * FUN_08004e44 @ 0x8004e44
 * Motor control / FOC algorithm
 * ---------------------------------------- */

longlong FUN_08004e44(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  uint extraout_r3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint unaff_lr;
  uint uVar12;
  bool bVar13;
  
  if ((DAT_080050ec & ~(param_2 >> 4)) == 0 || (DAT_080050ec & ~(param_4 >> 4)) == 0) {
    FUN_08005278();
    param_2 = extraout_r3;
  }
  else {
    uVar7 = param_2 ^ param_4;
    uVar4 = DAT_080050ec & param_2 >> 4;
    bVar13 = uVar4 == 0;
    uVar6 = uVar7 >> 0x1f;
    if (!bVar13) {
      uVar7 = DAT_080050ec & param_4 >> 4;
      bVar13 = uVar7 == 0;
    }
    if (bVar13) {
      if ((param_2 & DAT_080050ec << 4) == 0) {
        if ((param_4 & DAT_080050ec << 4) == 0) {
          return (ulonglong)DAT_080050f0 << 0x20;
        }
        return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
      }
      param_2 = param_2 ^ param_4;
    }
    else {
      iVar5 = (uVar4 | uVar6) - uVar7;
      uVar7 = param_4 << 0xb | 0x80000000;
      uVar4 = param_2 << 0xb | 0x80000000 | param_1 >> 0x15;
      uVar3 = uVar7 | param_3 >> 0x15;
      uVar6 = iVar5 + 0x3fe0000;
      if (uVar4 == uVar3 && param_1 * 0x800 == param_3 * 0x800) {
        uVar3 = 0x100000;
        uVar4 = 0;
      }
      else {
        uVar9 = (uint)*(byte *)((uVar7 >> 0x18) + 0x8004fec);
        uVar9 = uVar9 * (0x1000000 - uVar9 * (uVar7 >> 0x10)) >> 0xf;
        iVar10 = (int)((ulonglong)uVar9 * (ulonglong)uVar3);
        iVar8 = -(int)((ulonglong)uVar9 * (ulonglong)uVar3 >> 0x20);
        iVar11 = iVar8 + 0x10000;
        if (iVar10 != 0) {
          iVar11 = iVar8 + 0xffff;
        }
        uVar9 = uVar9 * iVar11 + (int)((ulonglong)uVar9 * (ulonglong)(uint)-iVar10 >> 0x20);
        lVar1 = (ulonglong)uVar9 * (ulonglong)uVar3 +
                ((ulonglong)uVar9 * (ulonglong)(param_3 * 0x800) >> 0x20);
        iVar10 = (int)lVar1;
        iVar8 = -(int)((ulonglong)lVar1 >> 0x20);
        uVar3 = iVar8 + 0x80000000;
        if (iVar10 != 0) {
          uVar3 = iVar8 + 0x7fffffff;
        }
        uVar2 = (ulonglong)uVar9 * (ulonglong)uVar3 +
                ((ulonglong)uVar9 * (ulonglong)(uint)-iVar10 >> 0x20);
        uVar9 = (uint)(uVar2 >> 0x20);
        uVar3 = (uint)((ulonglong)uVar4 * (uVar2 & 0xffffffff) >> 0x20);
        uVar12 = (uint)((ulonglong)(param_1 * 0x800) * (ulonglong)uVar9 >> 0x20);
        uVar2 = (ulonglong)uVar4 * (ulonglong)uVar9 +
                (ulonglong)CONCAT14(CARRY4(uVar3,uVar12),uVar3 + uVar12);
        iVar8 = (int)(uVar2 >> 0x20);
        unaff_lr = iVar8 + 0x70000000;
        if (!SCARRY4(iVar8,0x70000000)) {
          uVar6 = iVar5 + 0x3fd0000;
          uVar2 = CONCAT44(iVar8 * 2 + (uint)((uVar2 & 0x80000000) != 0),(int)uVar2 << 1);
        }
        uVar3 = (uint)(uVar2 + 0x80 >> 0x20);
        uVar4 = (uint)(uVar2 + 0x80) >> 8 | uVar3 * 0x1000000;
        uVar3 = uVar3 >> 8;
        if ((int)uVar2 * 0x1000000 + 0x91000000U < 0x10000001) {
          uVar9 = param_3 & 0x1fffff | (param_3 >> 0x15) << 0x15;
          iVar5 = uVar3 * uVar9 +
                  uVar4 * (uVar7 >> 0xb) + (int)((ulonglong)uVar4 * (ulonglong)uVar9 >> 0x20);
          if (-1 < (int)unaff_lr) {
            iVar5 = iVar5 + (param_1 & 0x1fffff) * -0x100000;
          }
          unaff_lr = iVar5 + (param_1 & 0x1fffff) * -0x100000 +
                     (uVar7 >> 0xc) +
                     (uint)CARRY4((uint)((ulonglong)uVar4 * (ulonglong)uVar9),
                                  uVar9 >> 1 | (uVar7 >> 0xb) << 0x1f);
          if ((int)unaff_lr < 0) {
            bVar13 = 0xfffffffe < uVar4;
            uVar4 = uVar4 + 1;
            uVar3 = uVar3 + bVar13;
          }
        }
      }
      iVar5 = uVar3 + uVar6 * -0x80000000 + (uVar6 & 0xfffffffe) * 0x10;
      if ((uVar6 & 0xfffffffe) < 0x7f00001) {
        return CONCAT44(iVar5,uVar4);
      }
      if (-1 < (int)uVar6) {
        unaff_lr = iVar5 + 0x100000;
      }
      if (-1 < (int)uVar6 && -1 < (int)(unaff_lr ^ uVar6 << 0x1f)) {
        return CONCAT44(iVar5,uVar4);
      }
      if ((int)uVar6 < 0) {
        return (ulonglong)(iVar5 + 0x60000000U & 0x80000000) << 0x20;
      }
      param_2 = iVar5 + 0xa0000000;
    }
  }
  return (ulonglong)((uint)((int)param_2 < 0) << 0x1f | 0x7ff00000) << 0x20;
}



/* ----------------------------------------
 * FUN_080050f4 @ 0x80050f4
 * Unknown function
 * ---------------------------------------- */

undefined8 FUN_080050f4(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 0x80000000;
  if ((int)uVar2 < 0) {
    param_1 = -param_1;
  }
  uVar1 = param_1 << LZCOUNT(param_1);
  if (uVar1 != 0) {
    return CONCAT44(uVar2 + (0x41d - LZCOUNT(param_1)) * 0x100000 + (uVar1 >> 0xb),uVar1 << 0x15);
  }
  return 0;
}



/* ----------------------------------------
 * FUN_08005124 @ 0x8005124
 * Unknown function
 * ---------------------------------------- */

longlong FUN_08005124(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  int extraout_r1;
  int iVar7;
  uint uVar8;
  uint extraout_r3;
  uint unaff_r5;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  bool bVar16;
  
  uVar13 = DAT_08005270 & param_2 >> 4;
  bVar16 = uVar13 == 0;
  if (!bVar16) {
    unaff_r5 = DAT_08005270 & param_4 >> 4;
    bVar16 = unaff_r5 == 0;
  }
  if (!bVar16) {
    bVar16 = uVar13 == DAT_08005270;
  }
  if (!bVar16) {
    bVar16 = unaff_r5 == DAT_08005270;
  }
  if (bVar16) {
    if (uVar13 != DAT_08005270 && (DAT_08005270 & param_4 >> 4) != DAT_08005270) {
      return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
    }
    FUN_08005278();
    uVar13 = extraout_r1 << 2 ^ extraout_r3;
  }
  else {
    uVar6 = param_2 & ~(DAT_08005270 << 5) | 0x100000;
    uVar8 = param_4 & ~(DAT_08005270 << 5) | 0x100000;
    iVar14 = (uVar13 | (param_2 ^ param_4) >> 0x1f) + unaff_r5;
    lVar1 = (ulonglong)uVar6 * (ulonglong)param_3;
    uVar11 = (uint)((ulonglong)lVar1 >> 0x20);
    lVar2 = (ulonglong)param_1 * (ulonglong)uVar8;
    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
    iVar15 = iVar14 + -0x3fc0000;
    lVar4 = lVar1 + lVar2;
    uVar10 = (uint)((ulonglong)lVar4 >> 0x20);
    lVar3 = (ulonglong)uVar6 * (ulonglong)uVar8;
    uVar13 = (uint)lVar3;
    uVar12 = (uint)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20);
    lVar5 = lVar4 + CONCAT44(uVar13,uVar12);
    uVar8 = (uint)lVar5;
    uVar6 = (uint)((ulonglong)lVar5 >> 0x20);
    uVar13 = (int)((ulonglong)lVar3 >> 0x20) +
             (uint)(CARRY4(uVar9,uVar11) ||
                   CARRY4(uVar9 + uVar11,(uint)CARRY4((uint)lVar2,(uint)lVar1))) +
             (uint)(CARRY4(uVar10,uVar13) ||
                   CARRY4(uVar10 + uVar13,(uint)CARRY4((uint)lVar4,uVar12)));
    if ((int)((ulonglong)param_1 * (ulonglong)param_3) != 0) {
      uVar8 = uVar8 | 1;
    }
    if ((uVar13 & 0x200) == 0) {
      uVar9 = uVar8 << 0xc;
      uVar13 = uVar13 * 0x1000 | uVar6 >> 0x14;
      uVar6 = uVar6 << 0xc | uVar8 >> 0x14;
      iVar7 = -4;
    }
    else {
      uVar9 = uVar8 << 0xb;
      uVar13 = uVar13 * 0x800 | uVar6 >> 0x15;
      uVar6 = uVar6 << 0xb | uVar8 >> 0x15;
      iVar7 = -3;
    }
    uVar8 = iVar7 + (iVar15 >> 0x10);
    uVar13 = uVar13 + uVar8 * 0x100000 ^ iVar14 * -0x80000000;
    if (uVar9 != 0) {
      bVar16 = (uVar9 & 0x80000000) != 0;
      if ((uVar9 & 0x7fffffff) != 0) {
        uVar9 = 0;
      }
      uVar13 = uVar13 + CARRY4(uVar6,(uint)bVar16);
      uVar6 = uVar6 + bVar16 & ~(uVar9 >> 0x1f);
    }
    if (uVar8 < 0x7fe) {
      return CONCAT44(uVar13,uVar6);
    }
    if (iVar15 < 0x4000000) {
      return (ulonglong)(uVar13 + 0x60000000 & 0x80000000) << 0x20;
    }
    uVar13 = uVar13 + 0xa0000000;
  }
  return (ulonglong)((uint)((int)uVar13 < 0) << 0x1f | 0x7ff00000) << 0x20;
}



/* ----------------------------------------
 * FUN_08005278 @ 0x8005278
 * Unknown function
 * ---------------------------------------- */

int FUN_08005278(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint unaff_r5;
  uint uVar2;
  uint uVar3;
  int unaff_lr;
  uint *puVar4;
  bool bVar5;
  
  puVar4 = (uint *)(unaff_lr + 2U & 0xfffffffc);
  uVar2 = *puVar4;
  if ((((int)uVar2 < 0) || (unaff_r5 = param_4 * 2 + (uint)(param_3 != 0), unaff_r5 < 0xffe00001))
     && (uVar3 = param_2 * 2 + (uint)(param_1 != 0), uVar3 < 0xffe00001)) {
    if (uVar3 == 0xffe00000) {
      uVar3 = ((int)param_2 >> 0x1f) * -3 + 2;
      if (unaff_r5 == 0xffe00000) {
        uVar3 = uVar3 + (1 - ((int)param_4 >> 0x1f));
      }
    }
    else {
      uVar3 = param_4 >> 0x1f;
    }
  }
  else {
    uVar3 = 8;
  }
  uVar2 = uVar2 >> (uVar3 * 3 & 0xff) & 7;
  switch(uVar2) {
  case 4:
    param_1 = param_3;
    param_2 = param_4;
switchD_080052e4_caseD_5:
    bVar5 = CARRY4(param_2,param_2) || CARRY4(param_2 * 2,(uint)(param_1 != 0));
    uVar2 = param_2 * 2 + (uint)(param_1 != 0);
    if (uVar2 != 0) {
      bVar5 = uVar2 < 0x200001;
    }
    if (bVar5 && (uVar2 != 0 && uVar2 != 0x200000)) {
      param_1 = 0;
    }
    return param_1;
  case 5:
    goto switchD_080052e4_caseD_5;
  case 6:
  case 7:
    return 0;
  default:
                    /* WARNING: Could not recover jumptable at 0x080052e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)(puVar4 + uVar2 + 1))();
    return iVar1;
  }
}



/* ----------------------------------------
 * FUN_08005320 @ 0x8005320
 * Unknown function
 * ---------------------------------------- */

/* WARNING: Control flow encountered bad instruction data */

ulonglong FUN_08005320(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  byte bVar13;
  
  if (-1 < (int)(param_2 ^ param_4)) {
    bVar11 = param_3 <= param_1;
    uVar7 = param_1 - param_3;
    if (param_2 <= param_4 && (uint)bVar11 <= param_2 - param_4) {
      bVar12 = CARRY4(param_3,uVar7);
      param_3 = param_3 + uVar7;
      uVar8 = (param_2 - param_4) - (uint)!bVar11 ^ 0x80000000;
      param_4 = param_4 + uVar8 + bVar12;
      bVar11 = param_1 < uVar7;
      param_1 = param_1 - uVar7;
      param_2 = (param_2 - uVar8) - (uint)bVar11;
    }
    uVar8 = param_2 >> 0x14;
    uVar7 = uVar8 - (param_4 >> 0x14);
    if ((DAT_080054f0 & param_4 << 1) == 0 || DAT_080054f0 == uVar8 << 0x15) {
      if (DAT_080054f0 != uVar8 << 0x15) {
        if ((param_2 & DAT_080054f0 >> 1) == 0) {
          param_2 = 0;
          param_1 = 0;
        }
        return CONCAT44(param_2,param_1);
      }
      FUN_08005278();
      do {
        software_interrupt(0x40);
      } while( true );
    }
    uVar5 = -param_3;
    uVar2 = param_2 & ~(uVar8 << 0x14);
    iVar6 = ((int)DAT_080054f0 >> 1) - (param_4 & ~((int)DAT_080054f0 >> 1));
    if (param_3 != 0) {
      iVar6 = iVar6 + -1;
    }
    if (uVar7 < 0x21) {
      uVar9 = uVar5 >> (uVar7 & 0xff);
      uVar1 = param_1 + uVar9;
      uVar2 = uVar2 + (iVar6 >> (uVar7 & 0xff)) + (uint)CARRY4(param_1,uVar9);
      uVar10 = iVar6 << (0x20 - uVar7 & 0xff);
      uVar9 = uVar1 + uVar10;
      bVar11 = CARRY4(uVar2,(uint)CARRY4(uVar1,uVar10));
      iVar6 = uVar2 + CARRY4(uVar1,uVar10);
      uVar7 = 0x20 - uVar7;
    }
    else {
      uVar5 = (uint)(param_3 * -2 != 0) | (iVar6 * 2 + (uint)CARRY4(uVar5,uVar5)) * 2;
      uVar7 = uVar7 - 0x20;
      if (0x1d < uVar7) {
        return CONCAT44(uVar2 + uVar8 * 0x100000,param_1);
      }
      uVar1 = iVar6 >> (uVar7 & 0xff);
      uVar9 = param_1 + uVar1;
      bVar11 = uVar2 != 0 || CARRY4(uVar2 - 1,(uint)CARRY4(param_1,uVar1));
      iVar6 = (uVar2 - 1) + (uint)CARRY4(param_1,uVar1);
      uVar7 = 0x1e - uVar7;
    }
    if (-1 < iVar6) {
      iVar4 = uVar5 << (uVar7 & 0xff);
      iVar6 = iVar6 + uVar8 * 0x100000;
      if (-1 < iVar4) {
        return CONCAT44(iVar6,uVar9);
      }
      uVar9 = uVar9 + 1;
      if (uVar9 != 0 && iVar4 != -0x80000000) {
        return CONCAT44(iVar6,uVar9);
      }
      if (uVar9 == 0) {
        iVar6 = iVar6 + 1;
        uVar9 = 0;
      }
      else {
        uVar9 = uVar9 & 0xfffffffe;
      }
      return CONCAT44(iVar6,uVar9);
    }
    uVar2 = uVar7 + 1 & 0xff;
    bVar11 = uVar2 == 0 && bVar11 || uVar2 != 0 && (uVar5 << uVar2 - 1 & 0x80000000) != 0;
    uVar1 = uVar9 * 2 + (uint)bVar11;
    uVar7 = iVar6 * 2 + (uint)(CARRY4(uVar9,uVar9) || CARRY4(uVar9 * 2,(uint)bVar11));
    uVar9 = uVar7 + uVar8 * 0x200000;
    bVar11 = (uVar9 >> 0x14 & 1) != 0;
    if (bVar11 && uVar9 >> 0x15 != 0) {
      uVar9 = -((int)(uVar5 << uVar2) >> 0x1f);
      uVar10 = uVar1 + uVar9;
      bVar11 = uVar10 == 0;
      iVar6 = uVar7 + uVar8 * 0x100000;
      if (!CARRY4(uVar1,uVar9)) {
        bVar11 = uVar5 << uVar2 == -0x80000000;
      }
      if (!bVar11) {
        return CONCAT44(iVar6,uVar10);
      }
      if (uVar10 == 0) {
        iVar6 = iVar6 + 1;
        uVar10 = 0;
      }
      else {
        uVar10 = uVar10 & 0xfffffffe;
      }
      return CONCAT44(iVar6,uVar10);
    }
    if (!bVar11) {
      iVar6 = uVar7 + 0x200000;
      if (iVar6 == 0) {
        uVar7 = uVar1 << LZCOUNT(uVar1);
        if (uVar7 == 0) {
          return (ulonglong)uVar1;
        }
        iVar4 = ((uVar8 & 0xfffff7ff) - LZCOUNT(uVar1)) + -0x17;
        iVar6 = uVar7 << 0x15;
        uVar7 = uVar7 >> 0xb;
      }
      else {
        uVar5 = LZCOUNT(iVar6) - 0xb;
        iVar4 = ((uVar8 & 0xfffff7ff) - uVar5) + -2;
        uVar7 = iVar6 << (uVar5 & 0xff) | uVar1 >> (0x20 - uVar5 & 0xff);
        iVar6 = uVar1 << (uVar5 & 0xff);
      }
      iVar3 = uVar7 + (param_2 & 0x80000000) + iVar4 * 0x100000;
      if (-1 < iVar4) {
        return CONCAT44(iVar3,iVar6);
      }
      return (ulonglong)(iVar3 + 0x60000000U & 0x80000000) << 0x20;
    }
    uVar8 = ((int)uVar7 >> 1) + uVar8 * 0x100000;
    uVar7 = (uint)((uVar7 & 1) != 0) << 0x1f | uVar1 >> 1;
    if (uVar8 * 2 == 0 && uVar7 == 0) {
      return (ulonglong)uVar7;
    }
    if (0x1fffff < uVar8 * 2) {
      return CONCAT44(uVar8,uVar7);
    }
    return (ulonglong)(uVar8 & 0x80000000) << 0x20;
  }
  param_4 = param_4 ^ 0x80000000;
  uVar7 = param_1 - param_3;
  iVar6 = (param_2 - param_4) - (uint)(param_3 > param_1);
  if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
    bVar11 = CARRY4(param_3,uVar7);
    param_3 = param_3 + uVar7;
    param_4 = param_4 + iVar6 + (uint)bVar11;
    bVar11 = param_1 < uVar7;
    param_1 = param_1 - uVar7;
    param_2 = (param_2 - iVar6) - (uint)bVar11;
  }
  uVar8 = param_2 >> 0x14;
  uVar7 = uVar8 - (param_4 >> 0x14);
  if ((DAT_08004e40 & param_4 << 1) == 0 || DAT_08004e40 == uVar8 << 0x15) {
    if (DAT_08004e40 != uVar8 << 0x15) {
      if ((param_2 & DAT_08004e40 >> 1) == 0) {
        param_2 = param_2 & 0x80000000;
        param_1 = 0;
      }
      return CONCAT44(param_2,param_1);
    }
    FUN_08005278();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  param_2 = param_2 & ~(uVar8 << 0x14);
  uVar5 = param_4 & ~DAT_08004e40 | 0x100000;
  if (uVar7 < 0x21) {
    uVar1 = param_3 >> (uVar7 & 0xff);
    uVar2 = param_1 + uVar1;
    uVar10 = uVar5 << (0x20 - uVar7 & 0xff);
    uVar9 = uVar2 + uVar10;
    param_2 = param_2 + (uVar5 >> (uVar7 & 0xff)) + (uint)CARRY4(param_1,uVar1) +
              (uint)CARRY4(uVar2,uVar10);
    uVar7 = 0x20 - uVar7;
    if (param_2 < 0x100000) {
      param_2 = param_2 + uVar8 * 0x100000;
      goto LAB_08004d70;
    }
LAB_08004dd2:
    bVar13 = (byte)uVar9 & 1;
    uVar5 = (uint)((param_2 + 0x100000 & 1) != 0) << 0x1f | uVar9 >> 1;
    param_2 = (param_2 + 0x100000 >> 1) + uVar8 * 0x100000;
    if ((uVar9 & 1) == 0) {
LAB_08004e00:
      if (param_2 * 2 < 0xffe00000) {
        return CONCAT44(param_2,uVar5);
      }
      goto LAB_08005314;
    }
    bVar11 = CARRY4(uVar5,(uint)bVar13);
    uVar5 = uVar5 + bVar13;
    uVar8 = uVar5;
    if (!bVar11) {
      uVar8 = param_3 << (uVar7 & 0xff);
    }
    if (uVar8 != 0) goto LAB_08004e00;
  }
  else {
    param_3 = uVar5 * 2 + (uint)(param_3 != 0);
    uVar2 = uVar7 - 0x20;
    uVar7 = 0x1f - uVar2;
    if (uVar2 < 0x20) {
      uVar5 = uVar5 >> (uVar2 & 0xff);
      uVar9 = param_1 + uVar5;
    }
    else {
      uVar7 = 0;
      uVar9 = param_1;
    }
    param_2 = param_2 + uVar8 * 0x100000 + (uint)(uVar2 < 0x20 && CARRY4(param_1,uVar5));
    if (uVar8 != param_2 >> 0x14) {
      param_2 = param_2 + uVar8 * -0x100000;
      goto LAB_08004dd2;
    }
LAB_08004d70:
    param_3 = param_3 << (uVar7 & 0xff);
    if (-1 < (int)param_3) {
      return CONCAT44(param_2,uVar9);
    }
    uVar5 = uVar9 + 1;
    uVar7 = uVar5;
    if (uVar9 != 0xffffffff) {
      uVar7 = param_3 & 0x7fffffff;
    }
    if (uVar7 != 0) {
      return CONCAT44(param_2,uVar5);
    }
  }
  if (uVar5 == 0) {
    param_2 = param_2 + 1;
    uVar5 = 0;
  }
  else {
    uVar5 = uVar5 & 0xfffffffe;
  }
  if (param_2 << 1 < 0xffe00000) {
    return CONCAT44(param_2,uVar5);
  }
LAB_08005314:
  return (ulonglong)((uint)((int)(param_2 + 0xa0000000) < 0) << 0x1f | 0x7ff00000) << 0x20;
}



/* ----------------------------------------
 * FUN_080054f4 @ 0x80054f4
 * Unknown function
 * ---------------------------------------- */

longlong FUN_080054f4(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = (uint)((param_1 & 0x80000000) != 0) << 0x1f;
  uVar2 = (param_1 << 1) >> 4;
  uVar4 = param_1 << 1 ^ param_1;
  if (uVar4 != 0) {
    param_1 = param_1 << 0x1d;
    param_2 = (uVar1 | uVar2) + 0x38000000;
  }
  if (uVar4 == 0 || (uVar4 & 0x7f000000) == 0) {
    if ((uVar2 & 0x8000000) != 0) {
      iVar3 = FUN_080059b2(uVar1 | param_1 >> 0x1d | uVar2 << 3,param_2);
      return (ulonglong)((uint)(iVar3 < 0) << 0x1f | 0x7ff00000) << 0x20;
    }
    return (ulonglong)uVar1 << 0x20;
  }
  return CONCAT44(param_2,param_1);
}



/* ----------------------------------------
 * FUN_0800554c @ 0x800554c
 * Unknown function
 * ---------------------------------------- */

/* WARNING: Control flow encountered bad instruction data */

uint FUN_0800554c(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  if ((int)(param_1 ^ param_2) < 0) {
    param_2 = param_2 ^ 0x80000000;
    if (param_1 < param_2 || param_1 - param_2 == 0) {
      uVar4 = param_1 - param_2 ^ 0x80000000;
      param_1 = param_1 - uVar4;
      param_2 = param_2 + uVar4;
    }
    uVar4 = param_1 >> 0x17;
    uVar5 = uVar4 - (param_2 >> 0x17);
    if ((param_2 & 0x7f800000) == 0 || (uVar4 & 0xff) == 0xff) {
      if ((uVar4 & 0xff) != 0xff) {
        if ((param_1 & 0x7f800000) == 0) {
          param_1 = 0;
        }
        return param_1;
      }
      FUN_080059b2();
      do {
        software_interrupt(0x40);
      } while( true );
    }
    uVar1 = param_2 << 8 | 0x80000000;
    uVar2 = (param_1 << 8 | 0x80000000) - (uVar1 >> (uVar5 & 0xff));
    if (-1 < (int)uVar2) {
      if ((uVar4 & 0xfe) == 0) {
        if (uVar2 >> 7 == 0) {
          return 0;
        }
      }
      else {
        uVar6 = uVar2 * 2;
        if ((int)uVar6 < 0) {
          bVar8 = ((int)uVar6 >> 7 & 1U) != 0;
          uVar4 = ((int)uVar6 >> 8) + uVar4 * 0x800000 + (uint)bVar8;
          if (!bVar8) {
            return uVar4;
          }
          if ((uVar2 & 0x3f) != 0) {
            return uVar4;
          }
          goto LAB_08005b2e;
        }
        uVar6 = uVar6 >> 2;
        if (uVar6 == 0) {
          return 0;
        }
        uVar1 = uVar4 - LZCOUNT(uVar6);
        uVar5 = 0x28U - LZCOUNT(uVar6) & 0x1f;
        if ((uVar4 ^ uVar1) >> 8 == 0) {
          return (uVar6 >> uVar5 | uVar6 << 0x20 - uVar5) + uVar1 * 0x800000;
        }
      }
      return param_1 & 0x80000000;
    }
    bVar8 = (uVar2 >> 7 & 1) != 0;
    uVar4 = (uVar2 >> 8) + (uVar4 - 1) * 0x800000 + (uint)bVar8;
    if (!bVar8) {
      return uVar4;
    }
    if ((uVar2 & 0x7f) != 0) {
      return uVar4;
    }
LAB_08005b2e:
    if (uVar1 << (0x20 - uVar5 & 0xff) == 0) {
      uVar4 = uVar4 & 0xfffffffe;
    }
    else {
      uVar4 = uVar4 - 1;
    }
    return uVar4;
  }
  iVar3 = param_1 - param_2;
  if (param_1 < param_2) {
    param_1 = param_1 - iVar3;
    param_2 = param_2 + iVar3;
  }
  uVar4 = param_1 >> 0x17;
  uVar5 = uVar4 - (param_2 >> 0x17);
  if ((param_2 & 0x7f800000) == 0 || (uVar4 & 0xff) == 0xff) {
    if ((uVar4 & 0xff) != 0xff) {
      if ((param_1 & 0x7f800000) == 0) {
        param_1 = param_1 & 0x80000000;
      }
      return param_1;
    }
    FUN_080059b2();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar1 = param_1 << 8 | 0x80000000;
  uVar2 = param_2 << 8 | 0x80000000;
  uVar6 = uVar2 >> (uVar5 & 0xff);
  uVar7 = uVar1 + uVar6;
  if (CARRY4(uVar1,uVar6)) {
    bVar8 = (uVar7 >> 1 & 0x80) != 0;
    uVar1 = (uVar7 >> 1 | 0x80000000) >> 8;
    uVar4 = uVar1 + uVar4 * 0x800000 + (uint)bVar8;
    if (bVar8) {
      uVar1 = uVar7 & 0xff;
    }
    uVar6 = uVar4 * 2;
    if (uVar1 != 0) {
      if (uVar6 < 0xff000000) {
        return uVar4;
      }
      goto LAB_080055c8;
    }
  }
  else {
    bVar8 = (uVar7 >> 7 & 1) != 0;
    uVar4 = (uVar7 >> 8) + (uVar4 - 1) * 0x800000 + (uint)bVar8;
    if (!bVar8) {
      return uVar4;
    }
    uVar6 = uVar4 * 2;
    if ((uVar7 & 0x7f) != 0) {
      bVar8 = 0xfeffffff < uVar6;
    }
    if (!bVar8) {
      return uVar4;
    }
  }
  if (uVar2 << (0x20 - uVar5 & 0xff) == 0) {
    uVar4 = uVar4 & 0xfffffffe;
  }
  if (uVar6 < 0xff000000) {
    return uVar4;
  }
LAB_080055c8:
  return (uVar4 + 0xa0000000 >> 0x17 | 0xff) << 0x17;
}



/* ----------------------------------------
 * FUN_08005634 @ 0x8005634
 * Unknown function
 * ---------------------------------------- */

ulonglong FUN_08005634(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  
  uVar3 = param_1 >> 7 & 0xff0000;
  bVar8 = uVar3 == 0;
  if (!bVar8) {
    param_4 = param_2 >> 7 & 0xff0000;
    bVar8 = param_4 == 0;
  }
  if (!bVar8) {
    bVar8 = uVar3 == 0xff0000;
  }
  if (!bVar8) {
    bVar8 = param_4 == 0xff0000;
  }
  if (bVar8) {
    uVar6 = param_2 >> 7 & 0xff0000;
    if ((int)(param_1 ^ param_2) < 0) {
      uVar3 = uVar3 | 0x100;
    }
    if (uVar3 < 0xff0000 && uVar6 < 0xff0000) {
      if (uVar6 != 0) {
        return CONCAT44(param_2,param_1 ^ param_2) & 0xffffffff80000000;
      }
      if ((uVar3 & 0xff0000) == 0) {
        return CONCAT44(param_2,DAT_080057b4);
      }
      param_1 = param_1 ^ param_2;
    }
    else {
      param_1 = FUN_080059b2();
      param_1 = param_1 & 0x80000000;
    }
  }
  else {
    if ((int)(param_1 ^ param_2) < 0) {
      uVar3 = uVar3 | 0x100;
    }
    uVar2 = param_1 & 0xffffff | 0x800000;
    uVar1 = param_2 & 0xffffff | 0x800000;
    bVar8 = uVar1 <= uVar2;
    uVar6 = -uVar1;
    uVar1 = (uint)*(byte *)(0x800577c - (uVar1 >> 0x11));
    iVar7 = uVar1 * 2;
    if (!bVar8) {
      uVar2 = uVar2 << 1;
    }
    iVar4 = (uVar3 - param_4) + 0x7d0000;
    iVar7 = uVar1 * 0x100 + (((int)(uVar6 * iVar7) >> 4) * iVar7 >> 0x15);
    uVar1 = iVar4 + (iVar4 >> 0x10) + (uint)bVar8;
    uVar5 = iVar7 * (uVar2 >> 8) >> 0x14;
    uVar3 = uVar6 * uVar5 + uVar2 * 0x800;
    uVar2 = iVar7 * (uVar3 >> 8) >> 0x13;
    uVar3 = uVar6 * uVar2 + uVar3 * 0x1000;
    bVar8 = CARRY4(uVar3,uVar6);
    if (bVar8) {
      uVar3 = uVar3 + uVar6;
    }
    iVar7 = uVar6 + uVar3 * 2;
    param_1 = uVar2 + uVar5 * 0x1000 + (uint)bVar8 +
              uVar1 * 0x800000 + (uint)CARRY4(uVar6,uVar3 * 2);
    if (uVar1 < 0xfc0000) {
      return CONCAT44(iVar7,param_1);
    }
    if ((int)(uVar1 - 0xfc0000) < 0) {
      if ((uVar1 & 0xf0) != 0) {
        param_1 = param_1 + 0x60000000 & 0x80000000;
      }
      return CONCAT44(iVar7,param_1);
    }
    if (0xfdffffff < param_1 * 2 + 0x1000000) {
      return CONCAT44(iVar7,param_1);
    }
    param_1 = param_1 + 0xa0000000;
  }
  return CONCAT44(0xff,(param_1 >> 0x17 | 0xff) << 0x17);
}



/* ----------------------------------------
 * FUN_080057b8 @ 0x80057b8
 * Unknown function
 * ---------------------------------------- */

uint FUN_080057b8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 *unaff_r4;
  
  uVar2 = (param_1 << 1) >> 0x18;
  uVar1 = 0x9e - uVar2;
  if (0x9e < uVar2 || uVar1 == 0) {
    FUN_080059b2();
    do {
      *unaff_r4 = (short)unaff_r4;
    } while( true );
  }
  uVar1 = ((param_1 | 0x800000) << 8) >> (uVar1 & 0xff);
  if ((int)(param_1 | 0x800000) < 0) {
    uVar1 = -uVar1;
  }
  return uVar1;
}



/* ----------------------------------------
 * FUN_080057f0 @ 0x80057f0
 * Unknown function
 * ---------------------------------------- */

uint FUN_080057f0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 & 0x80000000;
  if ((int)uVar1 < 0) {
    param_1 = -param_1;
  }
  uVar2 = param_1 << LZCOUNT(param_1);
  if (uVar2 != 0) {
    param_1 = (uVar1 | (0x9d - LZCOUNT(param_1)) * 0x800000) + (uVar2 >> 8);
    if ((uVar2 & 0x80) == 0) {
      return param_1;
    }
    param_1 = param_1 + 1;
    if ((uVar2 & 0x7f) == 0) {
      param_1 = param_1 & 0xfffffffe;
    }
  }
  return param_1;
}



/* ----------------------------------------
 * FUN_08005820 @ 0x8005820
 * Unknown function
 * ---------------------------------------- */

uint FUN_08005820(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 << LZCOUNT(param_1);
  if (uVar1 != 0) {
    param_1 = (0x9d - LZCOUNT(param_1)) * 0x800000 + (uVar1 >> 8);
    if ((uVar1 & 0x80) == 0) {
      return param_1;
    }
    param_1 = param_1 + 1;
    if ((uVar1 & 0x7f) == 0) {
      param_1 = param_1 & 0xfffffffe;
    }
  }
  return param_1;
}



/* ----------------------------------------
 * FUN_08005848 @ 0x8005848
 * Unknown function
 * ---------------------------------------- */

void FUN_08005848(uint param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  
  uVar1 = param_1 | param_2;
  if ((int)uVar1 < 0) {
    if ((int)(uVar1 + 0x800000) < 0) {
      if (-1 < (int)(uVar1 - 0x800000)) {
        return;
      }
      return;
    }
    if (param_1 << 1 < 0xff000000 && param_2 << 1 < 0xff000000) {
      return;
    }
  }
  else {
    bVar3 = SCARRY4(uVar1,0x800000);
    bVar2 = -1 < (int)(uVar1 + 0x800000);
    if (bVar2) {
      bVar3 = SBORROW4(uVar1,0x800000);
    }
    if (bVar2 && -1 < (int)(uVar1 - 0x800000)) {
      return;
    }
    if (!bVar3) {
      return;
    }
    if (-1 < (int)(param_1 + 0x800000) && -1 < (int)(param_2 + 0x800000)) {
      return;
    }
  }
  FUN_080059b2();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ----------------------------------------
 * FUN_080058b0 @ 0x80058b0
 * Unknown function
 * ---------------------------------------- */

uint FUN_080058b0(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  undefined8 uVar7;
  
  uVar2 = param_1 >> 7 & 0xff0000;
  bVar6 = uVar2 == 0;
  if (!bVar6) {
    param_4 = param_2 >> 7 & 0xff0000;
    bVar6 = param_4 == 0;
  }
  if (!bVar6) {
    bVar6 = uVar2 == 0xff0000;
  }
  if (!bVar6) {
    bVar6 = param_4 == 0xff0000;
  }
  if (bVar6) {
    if ((int)(param_1 ^ param_2) < 0) {
      uVar2 = uVar2 | 0x100;
    }
    if (uVar2 < 0xff0000 && (param_2 >> 7 & 0xff0000) < 0xff0000) {
      return (param_1 ^ param_2) & 0x80000000;
    }
    uVar7 = FUN_080059b2();
    uVar2 = (uint)uVar7 ^ (int)((ulonglong)uVar7 >> 0x20) << 2;
  }
  else {
    if ((int)(param_1 ^ param_2) < 0) {
      uVar2 = uVar2 | 0x100;
    }
    lVar1 = (ulonglong)(param_1 << 8 | 0x80000000) * (ulonglong)(param_2 << 8 | 0x80000000);
    uVar4 = (uint)((ulonglong)lVar1 >> 0x20);
    iVar3 = uVar2 + param_4 + -0x800000;
    if ((int)lVar1 != 0) {
      uVar4 = uVar4 | 1;
    }
    bVar6 = (uVar4 & 0x80000000) != 0;
    uVar5 = uVar4 << 1;
    if (bVar6) {
      uVar5 = uVar4 & 0x7fffffff | 0x80000000;
    }
    uVar4 = iVar3 + (iVar3 >> 0x10) + (uint)bVar6;
    bVar6 = (uVar5 >> 7 & 1) != 0;
    uVar2 = (uVar5 >> 8) + uVar4 * 0x800000 + (uint)bVar6;
    if ((!bVar6 || uVar5 >> 8 < uVar5 << 0x19) && uVar4 < 0xfc0000) {
      return uVar2;
    }
    if ((uVar5 & 0xff) == 0x80) {
      uVar2 = uVar2 & 0xfffffffe;
    }
    if (uVar4 < 0xfc0000) {
      return uVar2;
    }
    if ((int)(uVar4 - 0xfc0000) < 0) {
      if (-0x10000 < (int)(uVar4 ^ 0xff)) {
        return uVar2;
      }
      uVar2 = uVar2 + 0x60000000;
      if ((int)(uVar4 ^ 0xff) < -0xffff) {
        uVar2 = uVar2 & 0x80000000;
      }
      return uVar2;
    }
    if ((int)((uVar2 + 0x800000) * 2) < 0) {
      return uVar2;
    }
    uVar2 = uVar2 + 0xa0000000;
  }
  return (uVar2 >> 0x17 | 0xff) << 0x17;
}



/* ----------------------------------------
 * FUN_080059b2 @ 0x80059b2
 * Unknown function
 * ---------------------------------------- */

uint FUN_080059b2(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int unaff_lr;
  uint *puVar3;
  bool bVar4;
  
  puVar3 = (uint *)(unaff_lr + 2U & 0xfffffffc);
  uVar1 = *puVar3;
  if ((((int)uVar1 < 0) || (param_3 = param_2 * 2, param_3 < 0xff000001)) &&
     (param_1 * 2 < 0xff000001)) {
    if (param_1 * 2 == 0xff000000) {
      uVar2 = ((int)param_1 >> 0x1f) * -3 + 2;
      if (param_3 == 0xff000000) {
        uVar2 = uVar2 + (1 - ((int)param_2 >> 0x1f));
      }
    }
    else {
      uVar2 = param_2 >> 0x1f;
    }
  }
  else {
    uVar2 = 8;
  }
  uVar1 = uVar1 >> (uVar2 * 3 & 0xff) & 7;
  switch(uVar1) {
  case 4:
    param_1 = param_2;
switchD_08005a1a_caseD_5:
    bVar4 = (param_1 & 0x80000000) != 0;
    uVar1 = param_1 * 2;
    if (uVar1 != 0) {
      bVar4 = uVar1 < 0x1000001;
    }
    if (bVar4 && (uVar1 != 0 && uVar1 != 0x1000000)) {
      param_1 = param_1 & 0x80000000;
    }
    return param_1;
  case 5:
    goto switchD_08005a1a_caseD_5;
  case 6:
  case 7:
    return 0x7fc00000;
  default:
                    /* WARNING: Could not recover jumptable at 0x08005a18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(puVar3 + uVar1 + 1))();
    return uVar1;
  }
}



/* ----------------------------------------
 * FUN_08005a48 @ 0x8005a48
 * Unknown function
 * ---------------------------------------- */

void FUN_08005a48(uint param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  
  uVar1 = param_2 | param_1;
  if ((int)uVar1 < 0) {
    if ((int)(uVar1 + 0x800000) < 0) {
      if (-1 < (int)(uVar1 - 0x800000)) {
        return;
      }
      return;
    }
    if (param_2 << 1 < 0xff000000 && param_1 << 1 < 0xff000000) {
      return;
    }
  }
  else {
    bVar3 = SCARRY4(uVar1,0x800000);
    bVar2 = -1 < (int)(uVar1 + 0x800000);
    if (bVar2) {
      bVar3 = SBORROW4(uVar1,0x800000);
    }
    if (bVar2 && -1 < (int)(uVar1 - 0x800000)) {
      return;
    }
    if (!bVar3) {
      return;
    }
    if (-1 < (int)(param_2 + 0x800000) && -1 < (int)(param_1 + 0x800000)) {
      return;
    }
  }
  FUN_080059b2(param_2);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ----------------------------------------
 * FUN_08005aac @ 0x8005aac
 * Unknown function
 * ---------------------------------------- */

/* WARNING: Control flow encountered bad instruction data */

uint FUN_08005aac(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  if (-1 < (int)(param_1 ^ param_2)) {
    if (param_1 < param_2 || param_1 - param_2 == 0) {
      uVar4 = param_1 - param_2 ^ 0x80000000;
      param_1 = param_1 - uVar4;
      param_2 = param_2 + uVar4;
    }
    uVar4 = param_1 >> 0x17;
    uVar5 = uVar4 - (param_2 >> 0x17);
    if ((param_2 & 0x7f800000) == 0 || (uVar4 & 0xff) == 0xff) {
      if ((uVar4 & 0xff) != 0xff) {
        if ((param_1 & 0x7f800000) == 0) {
          param_1 = 0;
        }
        return param_1;
      }
      FUN_080059b2();
      do {
        software_interrupt(0x40);
      } while( true );
    }
    uVar2 = param_2 << 8 | 0x80000000;
    uVar7 = (param_1 << 8 | 0x80000000) - (uVar2 >> (uVar5 & 0xff));
    if (-1 < (int)uVar7) {
      if ((uVar4 & 0xfe) == 0) {
        if (uVar7 >> 7 == 0) {
          return 0;
        }
      }
      else {
        uVar1 = uVar7 * 2;
        if ((int)uVar1 < 0) {
          bVar8 = ((int)uVar1 >> 7 & 1U) != 0;
          uVar4 = ((int)uVar1 >> 8) + uVar4 * 0x800000 + (uint)bVar8;
          if (!bVar8) {
            return uVar4;
          }
          if ((uVar7 & 0x3f) != 0) {
            return uVar4;
          }
          goto LAB_08005b2e;
        }
        uVar1 = uVar1 >> 2;
        if (uVar1 == 0) {
          return 0;
        }
        uVar2 = uVar4 - LZCOUNT(uVar1);
        uVar5 = 0x28U - LZCOUNT(uVar1) & 0x1f;
        if ((uVar4 ^ uVar2) >> 8 == 0) {
          return (uVar1 >> uVar5 | uVar1 << 0x20 - uVar5) + uVar2 * 0x800000;
        }
      }
      return param_1 & 0x80000000;
    }
    bVar8 = (uVar7 >> 7 & 1) != 0;
    uVar4 = (uVar7 >> 8) + (uVar4 - 1) * 0x800000 + (uint)bVar8;
    if (!bVar8) {
      return uVar4;
    }
    if ((uVar7 & 0x7f) != 0) {
      return uVar4;
    }
LAB_08005b2e:
    if (uVar2 << (0x20 - uVar5 & 0xff) == 0) {
      uVar4 = uVar4 & 0xfffffffe;
    }
    else {
      uVar4 = uVar4 - 1;
    }
    return uVar4;
  }
  param_2 = param_2 ^ 0x80000000;
  iVar3 = param_1 - param_2;
  if (param_1 < param_2) {
    param_1 = param_1 - iVar3;
    param_2 = param_2 + iVar3;
  }
  uVar4 = param_1 >> 0x17;
  uVar5 = uVar4 - (param_2 >> 0x17);
  if ((param_2 & 0x7f800000) == 0 || (uVar4 & 0xff) == 0xff) {
    if ((uVar4 & 0xff) != 0xff) {
      if ((param_1 & 0x7f800000) == 0) {
        param_1 = param_1 & 0x80000000;
      }
      return param_1;
    }
    FUN_080059b2();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar2 = param_1 << 8 | 0x80000000;
  uVar7 = param_2 << 8 | 0x80000000;
  uVar1 = uVar7 >> (uVar5 & 0xff);
  uVar6 = uVar2 + uVar1;
  if (CARRY4(uVar2,uVar1)) {
    bVar8 = (uVar6 >> 1 & 0x80) != 0;
    uVar2 = (uVar6 >> 1 | 0x80000000) >> 8;
    uVar4 = uVar2 + uVar4 * 0x800000 + (uint)bVar8;
    if (bVar8) {
      uVar2 = uVar6 & 0xff;
    }
    uVar1 = uVar4 * 2;
    if (uVar2 != 0) {
      if (uVar1 < 0xff000000) {
        return uVar4;
      }
      goto LAB_080055c8;
    }
  }
  else {
    bVar8 = (uVar6 >> 7 & 1) != 0;
    uVar4 = (uVar6 >> 8) + (uVar4 - 1) * 0x800000 + (uint)bVar8;
    if (!bVar8) {
      return uVar4;
    }
    uVar1 = uVar4 * 2;
    if ((uVar6 & 0x7f) != 0) {
      bVar8 = 0xfeffffff < uVar1;
    }
    if (!bVar8) {
      return uVar4;
    }
  }
  if (uVar7 << (0x20 - uVar5 & 0xff) == 0) {
    uVar4 = uVar4 & 0xfffffffe;
  }
  if (uVar1 < 0xff000000) {
    return uVar4;
  }
LAB_080055c8:
  return (uVar4 + 0xa0000000 >> 0x17 | 0xff) << 0x17;
}



/* ----------------------------------------
 * FUN_08005bfa @ 0x8005bfa
 * Unknown function
 * ---------------------------------------- */

/* WARNING: Removing unreachable block (ram,0x08005c4c) */
/* WARNING: Removing unreachable block (ram,0x08005c5a) */
/* WARNING: Removing unreachable block (ram,0x08005bd2) */
/* WARNING: Removing unreachable block (ram,0x08005bc6) */
/* WARNING: Removing unreachable block (ram,0x08005c52) */
/* WARNING: Removing unreachable block (ram,0x08005bb6) */
/* WARNING: Removing unreachable block (ram,0x08005bae) */
/* WARNING: Removing unreachable block (ram,0x08005bb0) */
/* WARNING: Removing unreachable block (ram,0x08005bc0) */
/* WARNING: Removing unreachable block (ram,0x08005b9e) */

ulonglong FUN_08005bfa(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  char in_OV;
  bool bVar2;
  bool bVar3;
  
  uVar1 = param_1 >> 0x17 & 0xff;
  bVar2 = uVar1 == 0;
  if (!bVar2) {
    param_4 = uVar1 ^ 0xff;
    bVar2 = param_4 == 0;
  }
  bVar3 = bVar2;
  if (!bVar2) {
    in_OV = SBORROW4(param_4,param_2);
    bVar3 = param_4 == param_2;
  }
  bVar2 = !bVar2 && (int)(param_4 - param_2) < 0;
  if (!bVar3 && bVar2 == (bool)in_OV) {
    in_OV = SCARRY4(param_2,uVar1);
    bVar2 = (int)(param_2 + uVar1) < 0;
    bVar3 = param_2 + uVar1 == 0;
  }
  if (!bVar3 && bVar2 == (bool)in_OV) {
    return CONCAT44(param_2,param_1 + param_2 * 0x800000);
  }
  if (uVar1 == 0) {
    return CONCAT44(param_2,param_1) & 0xffffffff80000000;
  }
  if (param_4 == 0) {
    if ((param_1 & 0x7fffff) != 0) {
      return CONCAT44(param_2,DAT_08005618);
    }
    return CONCAT44(param_2,param_1);
  }
  param_1 = param_1 & 0x80000000;
  if (-1 < (int)param_2) {
    param_1 = param_1 | 0x7f800000;
  }
  return CONCAT44(param_2,param_1);
}



