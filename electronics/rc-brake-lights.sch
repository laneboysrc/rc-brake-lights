EESchema Schematic File Version 2
LIBS:WLA-STC
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:rc-brake-lights-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "RC Brake & Reversing Light Controller"
Date "2018-03-28"
Rev "1"
Comp "LANE Boys RC"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L STC15x10x U1
U 1 1 5AB9DFB5
P 5950 4500
F 0 "U1" H 6900 3900 60  0000 C CNN
F 1 "STC15W104" H 5050 3900 60  0000 C CNN
F 2 "SMD_Packages:SOIC-8-N" H 5950 4500 60  0001 C CNN
F 3 "" H 5950 4500 60  0001 C CNN
	1    5950 4500
	1    0    0    -1  
$EndComp
$Comp
L D D1
U 1 1 5AB9E032
P 2950 2700
F 0 "D1" H 2950 2800 50  0000 C CNN
F 1 "1N4148" H 2950 2600 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-323_HandSoldering" H 2950 2700 50  0001 C CNN
F 3 "" H 2950 2700 50  0001 C CNN
	1    2950 2700
	-1   0    0    1   
$EndComp
$Comp
L Conn_01x03 J2
U 1 1 5AB9E10B
P 9600 4700
F 0 "J2" H 9600 4900 50  0000 C CNN
F 1 "LED" H 9600 4500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x03_Pitch2.54mm" H 9600 4700 50  0001 C CNN
F 3 "" H 9600 4700 50  0001 C CNN
	1    9600 4700
	1    0    0    1   
$EndComp
$Comp
L C C1
U 1 1 5AB9E19F
P 6350 3600
F 0 "C1" H 6375 3700 50  0000 L CNN
F 1 "10u" H 6375 3500 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 6388 3450 50  0001 C CNN
F 3 "" H 6350 3600 50  0001 C CNN
	1    6350 3600
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 5AB9E1F6
P 7950 4600
F 0 "R2" V 8030 4600 50  0000 C CNN
F 1 "220" V 7950 4600 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7880 4600 50  0001 C CNN
F 3 "" H 7950 4600 50  0001 C CNN
	1    7950 4600
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 5AB9E26B
P 7950 4800
F 0 "R3" V 8030 4800 50  0000 C CNN
F 1 "220" V 7950 4800 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7880 4800 50  0001 C CNN
F 3 "" H 7950 4800 50  0001 C CNN
	1    7950 4800
	0    1    1    0   
$EndComp
$Comp
L GND #PWR01
U 1 1 5AB9E2B0
P 6650 3600
F 0 "#PWR01" H 6650 3350 50  0001 C CNN
F 1 "GND" H 6650 3450 50  0000 C CNN
F 2 "" H 6650 3600 50  0001 C CNN
F 3 "" H 6650 3600 50  0001 C CNN
	1    6650 3600
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR02
U 1 1 5AB9E2D7
P 2200 2900
F 0 "#PWR02" H 2200 2650 50  0001 C CNN
F 1 "GND" H 2200 2750 50  0000 C CNN
F 2 "" H 2200 2900 50  0001 C CNN
F 3 "" H 2200 2900 50  0001 C CNN
	1    2200 2900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 5AB9E2F7
P 5950 5400
F 0 "#PWR03" H 5950 5150 50  0001 C CNN
F 1 "GND" H 5950 5250 50  0000 C CNN
F 2 "" H 5950 5400 50  0001 C CNN
F 3 "" H 5950 5400 50  0001 C CNN
	1    5950 5400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5AB9E317
P 9400 4950
F 0 "#PWR04" H 9400 4700 50  0001 C CNN
F 1 "GND" H 9400 4800 50  0000 C CNN
F 2 "" H 9400 4950 50  0001 C CNN
F 3 "" H 9400 4950 50  0001 C CNN
	1    9400 4950
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG05
U 1 1 5AB9E332
P 3550 2350
F 0 "#FLG05" H 3550 2425 50  0001 C CNN
F 1 "PWR_FLAG" H 3550 2500 50  0000 C CNN
F 2 "" H 3550 2350 50  0001 C CNN
F 3 "" H 3550 2350 50  0001 C CNN
	1    3550 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 2800 2200 2800
Wire Wire Line
	2200 2800 2200 2900
$Comp
L VCC #PWR06
U 1 1 5AB9E533
P 3200 2350
F 0 "#PWR06" H 3200 2200 50  0001 C CNN
F 1 "VCC" H 3200 2500 50  0000 C CNN
F 2 "" H 3200 2350 50  0001 C CNN
F 3 "" H 3200 2350 50  0001 C CNN
	1    3200 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 3600 5950 3600
Wire Wire Line
	5950 3450 5950 3800
$Comp
L VCC #PWR07
U 1 1 5AB9E6A6
P 5950 3450
F 0 "#PWR07" H 5950 3300 50  0001 C CNN
F 1 "VCC" H 5950 3600 50  0000 C CNN
F 2 "" H 5950 3450 50  0001 C CNN
F 3 "" H 5950 3450 50  0001 C CNN
	1    5950 3450
	1    0    0    -1  
$EndComp
Connection ~ 5950 3600
Wire Wire Line
	3200 2350 3200 2700
Wire Wire Line
	3100 2700 3550 2700
Wire Wire Line
	3550 2700 3550 2350
Connection ~ 3200 2700
$Comp
L R R1
U 1 1 5AB9E858
P 3950 3000
F 0 "R1" V 4030 3000 50  0000 C CNN
F 1 "1k" V 3950 3000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 3880 3000 50  0001 C CNN
F 3 "" H 3950 3000 50  0001 C CNN
	1    3950 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	2100 2700 2800 2700
Wire Wire Line
	7150 4800 7800 4800
Wire Wire Line
	9400 4600 8100 4600
Wire Wire Line
	9400 4700 9150 4700
Wire Wire Line
	9150 4700 9150 4800
Wire Wire Line
	9150 4800 8100 4800
Wire Wire Line
	9400 4800 9400 4950
Text Label 7300 4600 0    60   ~ 0
Reverse
Text Label 7300 4800 0    60   ~ 0
Brake
Text Label 8400 4600 0    60   ~ 0
Reverse_LED
Text Label 8400 4800 0    60   ~ 0
Brake_LED
Wire Wire Line
	2100 2600 2500 2600
Wire Wire Line
	2500 2400 2500 3000
Wire Wire Line
	2500 3000 3800 3000
Text Label 3500 3000 0    60   ~ 0
TH
Text Label 4200 3000 0    60   ~ 0
TH_R
Wire Wire Line
	5950 5200 5950 5400
Wire Wire Line
	6650 3600 6500 3600
$Comp
L GND #PWR08
U 1 1 5AB9F405
P 1450 2900
F 0 "#PWR08" H 1450 2650 50  0001 C CNN
F 1 "GND" H 1450 2750 50  0000 C CNN
F 2 "" H 1450 2900 50  0001 C CNN
F 3 "" H 1450 2900 50  0001 C CNN
	1    1450 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 2800 1450 2800
Wire Wire Line
	1450 2800 1450 2900
Wire Wire Line
	1600 2600 1500 2600
Wire Wire Line
	1500 2600 1500 2400
Wire Wire Line
	1500 2400 2500 2400
Connection ~ 2500 2600
Wire Wire Line
	1600 2700 1300 2700
Wire Wire Line
	1300 2700 1300 2300
Wire Wire Line
	1300 2300 2700 2300
Wire Wire Line
	2700 2300 2700 2700
Connection ~ 2700 2700
$Comp
L Conn_02x03_Odd_Even J1
U 1 1 5AB9F7A6
P 1900 2700
F 0 "J1" H 1950 2900 50  0000 C CNN
F 1 "TH" H 1950 2500 50  0000 C CNN
F 2 "WLA:Pin_header_02x03_board_edge" H 1900 2700 50  0001 C CNN
F 3 "" H 1900 2700 50  0001 C CNN
	1    1900 2700
	-1   0    0    1   
$EndComp
Text Notes 1200 4100 0    60   ~ 0
Two parallel connections for \nthe Throttle (TH) channel:\nOne to the receiver, and \nanother one to plug in the ESC.
Text Notes 8900 4150 0    60   ~ 0
Two red LED in series for brake lights,\ntwo white LED in parallel for reversing \nlights.\nThe MCU can drive at most 20 mA per \noutput.\n\nThe output pins are also used \nfor programming the MCU
Text Notes 2200 1950 0    60   ~ 0
The maximum voltage for the MCU is 5.5V.\nThe diode drops 0.5V+ at low loads so\nthat we can use the controller until up to\n6V. \nDo *not* use a Schottky diode!
Wire Wire Line
	4100 3000 7450 3000
Wire Wire Line
	7450 3000 7450 4400
Wire Wire Line
	7450 4400 7150 4400
NoConn ~ 4600 4400
Text Notes 5550 2800 0    60   ~ 0
INT0 is used so that we can use \nTimer0 in gate mode to measure\nthe pulse duration
Wire Wire Line
	7150 4600 7800 4600
Wire Wire Line
	3900 4600 4600 4600
$Comp
L GND #PWR09
U 1 1 5AC0AD67
P 3300 4750
F 0 "#PWR09" H 3300 4500 50  0001 C CNN
F 1 "GND" H 3300 4600 50  0000 C CNN
F 2 "" H 3300 4750 50  0001 C CNN
F 3 "" H 3300 4750 50  0001 C CNN
	1    3300 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 4600 3300 4600
$Comp
L SW_Push SW1
U 1 1 5AC0AC8B
P 3700 4600
F 0 "SW1" H 3750 4700 50  0000 L CNN
F 1 "Setup button" H 3700 4540 50  0000 C CNN
F 2 "WLA:Tact_switch_SMD_6x3_6x2_5" H 3700 4800 50  0001 C CNN
F 3 "" H 3700 4800 50  0001 C CNN
	1    3700 4600
	1    0    0    -1  
$EndComp
NoConn ~ 7150 4200
$Comp
L PWR_FLAG #FLG010
U 1 1 5AC0C3FE
P 4250 2350
F 0 "#FLG010" H 4250 2425 50  0001 C CNN
F 1 "PWR_FLAG" H 4250 2500 50  0000 C CNN
F 2 "" H 4250 2350 50  0001 C CNN
F 3 "" H 4250 2350 50  0001 C CNN
	1    4250 2350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 5AC0C424
P 4250 2450
F 0 "#PWR011" H 4250 2200 50  0001 C CNN
F 1 "GND" H 4250 2300 50  0000 C CNN
F 2 "" H 4250 2450 50  0001 C CNN
F 3 "" H 4250 2450 50  0001 C CNN
	1    4250 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 2350 4250 2450
Wire Wire Line
	3300 4600 3300 4750
$EndSCHEMATC
