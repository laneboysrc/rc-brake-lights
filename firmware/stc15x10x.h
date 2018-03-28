#ifndef	_STC15X10X_H
#define	_STC15X10X_H

#include "compiler.h"

#define NOP()  __asm__("nop")


#define _P0 0x80
#define _SP 0x81
#define _DPL 0x82
#define _DPH 0x83
#define _S4CON 0x84
#define _S4BUF 0x85
#define _PCON 0x87

#define _TCON 0x88
#define _TMOD 0x89
#define _TL0 0x8a
#define _TL1 0x8b
#define _TH0 0x8c
#define _TH1 0x8d
#define _AUXR 0x8e
#define _WAKE_CLKO 0x8f
#define _INT_CLKO 0x8f
#define _AUXR2 0x8f

#define _P1 0x90
#define _P1M1 0x91
#define _P1M0 0x92
#define _P0M1 0x93
#define _P0M0 0x94
#define _P2M1 0x95
#define _P2M0 0x96
#define _CLK_DIV 0x97
#define _PCON2 0x97

#define _SCON 0x98
#define _SBUF 0x99
#define _S2CON 0x9a
#define _S2BUF 0x9b
#define _P1ASF 0x9d

#define _P2 0xa0
#define _BUS_SPEED 0xa1
#define _AUXR1 0xa2
#define _P_SW1 0xa2

#define _IE 0xa8
#define _SADDR 0xa9
#define _WKTCL 0xaa
#define _WKTCH 0xab
#define _S3CON 0xac
#define _S3BUF 0xad
#define _IE2 0xaf

#define _P3 0xb0
#define _P3M1 0xb1
#define _P3M0 0xb2
#define _P4M1 0xb3
#define _P4M0 0xb4
#define _IP2 0xb5
#define _IPH2 0xb6
#define _IPH 0xb7

#define _IP 0xb8
#define _SADEN 0xb9
#define _P_SW2 0xba
#define _ADC_CONTR 0xbc
#define _ADC_RES 0xbd
#define _ADC_RESL 0xbe

#define _P4 0xc0
#define _WDT_CONTR 0xc1
#define _IAP_DATA 0xc2
#define _IAP_ADDRH 0xc3
#define _IAP_ADDRL 0xc4
#define _IAP_CMD 0xc5
#define _IAP_TRIG 0xc6
#define _IAP_CONTR 0xc7

#define _ISP_DATA 0xc2
#define _ISP_ADDRH 0xc3
#define _ISP_ADDRL 0xc4
#define _ISP_CMD 0xc5
#define _ISP_TRIG 0xc6
#define _ISP_CONTR 0xc7

#define _P5 0xc8
#define _P5M1 0xc9
#define _P5M0 0xca
#define _P6M1 0xcb
#define _P6M0 0xcc
#define _SPSTAT 0xcd
#define _SPCTL 0xce
#define _SPDAT 0xcf

#define _PSW 0xd0
#define _T4T3M 0xd1
#define _T4H 0xd2
#define _T4L 0xd3
#define _T3H 0xd4
#define _T3L 0xd5
#define _T2H 0xd6
#define _T2L 0xd7

#define _TH4 0xd2
#define _TL4 0xd3
#define _TH3 0xd4
#define _TL3 0xd5
#define _TH2 0xd6
#define _TL2 0xd7

#define _RL_T4H 0xd2
#define _RL_T4L 0xd3
#define _RL_T3H 0xd4
#define _RL_T3L 0xd5
#define _RL_T2H 0xd6
#define _RL_T2L 0xd7

#define _CCON 0xd8
#define _CMOD 0xd9
#define _CCAPM0 0xda
#define _CCAPM1 0xdb
#define _CCAPM2 0xdc

#define _ACC 0xe0
#define _P7M1 0xe1
#define _P7M0 0xe2
#define _CMPCR1 0xe6
#define _CMPCR2 0xe7

#define _P6 0xe8
#define _CL 0xe9
#define _CCAP0L 0xea
#define _CCAP1L 0xeb
#define _CCAP2L 0xec

#define _B 0xf0
#define _PCA_PWM0 0xf2
#define _PCA_PWM1 0xf3
#define _PCA_PWM2 0xf4

#define _P7 0xf8
#define _CH 0xf9
#define _CCAP0H 0xfa
#define _CCAP1H 0xfb
#define _CCAP2H 0xfc


SFR(P0, _P0);
SFR(SP, _SP);
SFR(DPL, _DPL);
SFR(DPH, _DPH);
SFR(S4CON, _S4CON);
SFR(S4BUF, _S4BUF);
SFR(PCON, _PCON);

SFR(TCON, _TCON);
SFR(TMOD, _TMOD);
SFR(TL0, _TL0);
SFR(TL1, _TL1);
SFR(TH0, _TH0);
SFR(TH1, _TH1);
SFR(AUXR, _AUXR);
SFR(WAKE_CLKO, _WAKE_CLKO);
SFR(INT_CLKO, _INT_CLKO);
SFR(AUXR2, _AUXR2);

SFR(P1, _P1);
SFR(P1M1, _P1M1);
SFR(P1M0, _P1M0);
SFR(P0M1, _P0M1);
SFR(P0M0, _P0M0);
SFR(P2M1, _P2M1);
SFR(P2M0, _P2M0);
SFR(CLK_DIV, _CLK_DIV);
SFR(PCON2, _PCON2);

SFR(SCON, _SCON);
SFR(SBUF, _SBUF);
SFR(S2CON, _S2CON);
SFR(S2BUF, _S2BUF);
SFR(P1ASF, _P1ASF);

SFR(P2, _P2);
SFR(BUS_SPEED, _BUS_SPEED);
SFR(AUXR1, _AUXR1);
SFR(P_SW1, _P_SW1);

SFR(IE, _IE);
SFR(SADDR, _SADDR);
SFR(WKTCL, _WKTCL);
SFR(WKTCH, _WKTCH);
SFR(S3CON, _S3CON);
SFR(S3BUF, _S3BUF);
SFR(IE2, _IE2);

SFR(P3, _P3);
SFR(P3M1, _P3M1);
SFR(P3M0, _P3M0);
SFR(P4M1, _P4M1);
SFR(P4M0, _P4M0);
SFR(IP2, _IP2);
SFR(IPH2, _IPH2);
SFR(IPH, _IPH);

SFR(IP, _IP);
SFR(SADEN, _SADEN);
SFR(P_SW2, _P_SW2);
SFR(ADC_CONTR, _ADC_CONTR);
SFR(ADC_RES, _ADC_RES);
SFR(ADC_RESL, _ADC_RESL);

SFR(P4, _P4);
SFR(WDT_CONTR, _WDT_CONTR);
SFR(IAP_DATA, _IAP_DATA);
SFR(IAP_ADDRH, _IAP_ADDRH);
SFR(IAP_ADDRL, _IAP_ADDRL);
SFR(IAP_CMD, _IAP_CMD);
SFR(IAP_TRIG, _IAP_TRIG);
SFR(IAP_CONTR, _IAP_CONTR);

SFR(ISP_DATA, _ISP_DATA);
SFR(ISP_ADDRH, _ISP_ADDRH);
SFR(ISP_ADDRL, _ISP_ADDRL);
SFR(ISP_CMD, _ISP_CMD);
SFR(ISP_TRIG, _ISP_TRIG);
SFR(ISP_CONTR, _ISP_CONTR);

SFR(P5, _P5);
SFR(P5M1, _P5M1);
SFR(P5M0, _P5M0);
SFR(P6M1, _P6M1);
SFR(P6M0, _P6M0);
SFR(SPSTAT, _SPSTAT);
SFR(SPCTL, _SPCTL);
SFR(SPDAT, _SPDAT);

SFR(PSW, _PSW);
SFR(T4T3M, _T4T3M);
SFR(T4H, _T4H);
SFR(T4L, _T4L);
SFR(T3H, _T3H);
SFR(T3L, _T3L);
SFR(T2H, _T2H);
SFR(T2L, _T2L);

SFR(TH4, _TH4);
SFR(TL4, _TL4);
SFR(TH3, _TH3);
SFR(TL3, _TL3);
SFR(TH2, _TH2);
SFR(TL2, _TL2);

SFR(RL_T4H, _RL_T4H);
SFR(RL_T4L, _RL_T4L);
SFR(RL_T3H, _RL_T3H);
SFR(RL_T3L, _RL_T3L);
SFR(RL_T2H, _RL_T2H);
SFR(RL_T2L, _RL_T2L);

SFR(CCON, _CCON);
SFR(CMOD, _CMOD);
SFR(CCAPM0, _CCAPM0);
SFR(CCAPM1, _CCAPM1);
SFR(CCAPM2, _CCAPM2);

SFR(ACC, _ACC);
SFR(P7M1, _P7M1);
SFR(P7M0, _P7M0);
SFR(CMPCR1, _CMPCR1);
SFR(CMPCR2, _CMPCR2);

SFR(P6, _P6);
SFR(CL, _CL);
SFR(CCAP0L, _CCAP0L);
SFR(CCAP1L, _CCAP1L);
SFR(CCAP2L, _CCAP2L);

SFR(B, _B);
SFR(PCA_PWM0, _PCA_PWM0);
SFR(PCA_PWM1, _PCA_PWM1);
SFR(PCA_PWM2, _PCA_PWM2);

SFR(P7, _P7);
SFR(CH, _CH);
SFR(CCAP0H, _CCAP0H);
SFR(CCAP1H, _CCAP1H);
SFR(CCAP2H, _CCAP2H);



SBIT(CY, _PSW, 7);
SBIT(AC, _PSW, 6);
SBIT(F0, _PSW, 5);
SBIT(RS1, _PSW, 4);
SBIT(RS0, _PSW, 3);
SBIT(OV, _PSW, 2);
SBIT(F1, _PSW, 1);
SBIT(P, _PSW, 0);

SBIT(TF1, _TCON, 7);
SBIT(TR1, _TCON, 6);
SBIT(TF0, _TCON, 5);
SBIT(TR0, _TCON, 4);
SBIT(IE1, _TCON, 3);
SBIT(IT1, _TCON, 2);
SBIT(IE0, _TCON, 1);
SBIT(IT0, _TCON, 0);

SBIT(P00, _P0, 0);
SBIT(P01, _P0, 1);
SBIT(P02, _P0, 2);
SBIT(P03, _P0, 3);
SBIT(P04, _P0, 4);
SBIT(P05, _P0, 5);
SBIT(P06, _P0, 6);
SBIT(P07, _P0, 7);

SBIT(P10, _P1, 0);
SBIT(P11, _P1, 1);
SBIT(P12, _P1, 2);
SBIT(P13, _P1, 3);
SBIT(P14, _P1, 4);
SBIT(P15, _P1, 5);
SBIT(P16, _P1, 6);
SBIT(P17, _P1, 7);

SBIT(RXD2, _P1, 0);
SBIT(TXD2, _P1, 1);
SBIT(CCP1, _P1, 0);
SBIT(CCP0, _P1, 1);
SBIT(SPI_SS, _P1, 2);
SBIT(SPI_MOSI, _P1, 3);
SBIT(SPI_MISO, _P1, 4);
SBIT(SPI_SCLK, _P1, 5);

SBIT(P20, _P2, 0);
SBIT(P21, _P2, 1);
SBIT(P22, _P2, 2);
SBIT(P23, _P2, 3);
SBIT(P24, _P2, 4);
SBIT(P25, _P2, 5);
SBIT(P26, _P2, 6);
SBIT(P27, _P2, 7);

SBIT(P30, _P3, 0);
SBIT(P31, _P3, 1);
SBIT(P32, _P3, 2);
SBIT(P33, _P3, 3);
SBIT(P34, _P3, 4);
SBIT(P35, _P3, 5);
SBIT(P36, _P3, 6);
SBIT(P37, _P3, 7);

SBIT(RXD, _P3, 0);
SBIT(TXD, _P3, 1);
SBIT(INT0, _P3, 2);
SBIT(INT1, _P3, 3);
SBIT(T0, _P3, 4);
SBIT(T1, _P3, 5);
SBIT(WR, _P3, 6);
SBIT(RD, _P3, 7);
SBIT(CCP2, _P3, 7);

SBIT(CLKOUT0, _P3, 5);
SBIT(CLKOUT1, _P3, 4);

SBIT(P40, _P4, 0);
SBIT(P41, _P4, 1);
SBIT(P42, _P4, 2);
SBIT(P43, _P4, 3);
SBIT(P44, _P4, 4);
SBIT(P45, _P4, 5);
SBIT(P46, _P4, 6);
SBIT(P47, _P4, 7);

SBIT(P50, _P5, 0);
SBIT(P51, _P5, 1);
SBIT(P52, _P5, 2);
SBIT(P53, _P5, 3);
SBIT(P54, _P5, 4);
SBIT(P55, _P5, 5);
SBIT(P56, _P5, 6);
SBIT(P57, _P5, 7);

SBIT(SM0, _SCON, 7);
SBIT(SM1, _SCON, 6);
SBIT(SM2, _SCON, 5);
SBIT(REN, _SCON, 4);
SBIT(TB8, _SCON, 3);
SBIT(RB8, _SCON, 2);
SBIT(TI, _SCON, 1);
SBIT(RI, _SCON, 0);

SBIT(EA, _IE, 7);
SBIT(ELVD, _IE, 6);
SBIT(EADC, _IE, 5);
SBIT(ES, _IE, 4);
SBIT(ET1, _IE, 3);
SBIT(EX1, _IE, 2);
SBIT(ET0, _IE, 1);
SBIT(EX0, _IE, 0);

SBIT(ACC0, _ACC, 0);
SBIT(ACC1, _ACC, 1);
SBIT(ACC2, _ACC, 2);
SBIT(ACC3, _ACC, 3);
SBIT(ACC4, _ACC, 4);
SBIT(ACC5, _ACC, 5);
SBIT(ACC6, _ACC, 6);
SBIT(ACC7, _ACC, 7);

SBIT(B0, _B, 0);
SBIT(B1, _B, 1);
SBIT(B2, _B, 2);
SBIT(B3, _B, 3);
SBIT(B4, _B, 4);
SBIT(B5, _B, 5);
SBIT(B6, _B, 6);
SBIT(B7, _B, 7);

SBIT(PPCA, _IP, 7);
SBIT(PLVD, _IP, 6);
SBIT(PADC, _IP, 5);
SBIT(PS, _IP, 4);
SBIT(PT1, _IP, 3);
SBIT(PX1, _IP, 2);
SBIT(PT0, _IP, 1);
SBIT(PX0, _IP, 0);

SBIT(CCF1, _CCON, 1);
SBIT(CCF2, _CCON, 2);
SBIT(CCF0, _CCON, 0);
SBIT(CR, _CCON, 6);
SBIT(CF, _CCON, 7);

#endif // _STC15X10X_H
