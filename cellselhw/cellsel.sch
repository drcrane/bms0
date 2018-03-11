EESchema Schematic File Version 2
LIBS:power
LIBS:device
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
LIBS:vreg
LIBS:msp430
LIBS:powerswitchics
LIBS:ioexpanders
LIBS:adcanddac
LIBS:ti
LIBS:transientsuppressor
LIBS:cellsel-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MSP430G2553 U4
U 1 1 5A75D36B
P 1900 3900
F 0 "U4" H 1900 4000 60  0000 C CNN
F 1 "MSP430G2553" H 1900 3800 60  0000 C CNN
F 2 "Housings_SSOP:TSSOP-28_4.4x9.7mm_Pitch0.65mm" H 1900 3900 60  0001 C CNN
F 3 "" H 1900 3900 60  0001 C CNN
	1    1900 3900
	1    0    0    -1  
$EndComp
$Comp
L MCP1703-3302E/DB U1
U 1 1 5A75D436
P 2450 950
F 0 "U1" H 2150 1250 60  0000 C CNN
F 1 "MCP1703-5002E/DB" H 2950 850 60  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-223" H 2450 950 60  0001 C CNN
F 3 "" H 2450 950 60  0001 C CNN
	1    2450 950 
	1    0    0    -1  
$EndComp
$Comp
L MCP1703-3302E/DB U3
U 1 1 5A75D50B
P 2450 1850
F 0 "U3" H 2150 2150 60  0000 C CNN
F 1 "MCP1703-3302E/DB" H 2950 1750 60  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-223" H 2450 1850 60  0001 C CNN
F 3 "" H 2450 1850 60  0001 C CNN
	1    2450 1850
	1    0    0    -1  
$EndComp
$Comp
L MCP23017 U6
U 1 1 5A75D5A7
P 7600 4750
F 0 "U6" H 7600 5250 60  0000 C CNN
F 1 "MCP23017" H 7600 4750 60  0000 C CNN
F 2 "Housings_SOIC:SOIC-28W_7.5x17.9mm_Pitch1.27mm" H 7600 4550 60  0001 C CNN
F 3 "" H 7600 4550 60  0001 C CNN
	1    7600 4750
	1    0    0    -1  
$EndComp
$Comp
L CP1 C2
U 1 1 5A75D6C8
P 1400 1050
F 0 "C2" H 1425 1150 50  0000 L CNN
F 1 "100uF" H 1425 950 50  0000 L CNN
F 2 "Capacitors_SMD:C_1210" H 1400 1050 50  0001 C CNN
F 3 "" H 1400 1050 50  0000 C CNN
	1    1400 1050
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 5A75D779
P 1700 1050
F 0 "C3" H 1725 1150 50  0000 L CNN
F 1 "10uF" H 1725 950 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206" H 1738 900 50  0001 C CNN
F 3 "" H 1700 1050 50  0000 C CNN
	1    1700 1050
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 5A75DA58
P 1700 1950
F 0 "C6" H 1725 2050 50  0000 L CNN
F 1 "10uF" H 1725 1850 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206" H 1738 1800 50  0001 C CNN
F 3 "" H 1700 1950 50  0000 C CNN
	1    1700 1950
	1    0    0    -1  
$EndComp
$Comp
L C C7
U 1 1 5A75DA85
P 3600 1950
F 0 "C7" H 3625 2050 50  0000 L CNN
F 1 "10uF" H 3625 1850 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206" H 3638 1800 50  0001 C CNN
F 3 "" H 3600 1950 50  0000 C CNN
	1    3600 1950
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 5A75DAAE
P 3600 1050
F 0 "C4" H 3625 1150 50  0000 L CNN
F 1 "10uF" H 3625 950 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206" H 3638 900 50  0001 C CNN
F 3 "" H 3600 1050 50  0000 C CNN
	1    3600 1050
	1    0    0    -1  
$EndComp
$Comp
L Q_NMOS_GDSD Q3
U 1 1 5A75DF9A
P 6200 1900
F 0 "Q3" H 6500 1950 50  0000 R CNN
F 1 "FQT4N20L" H 6700 1800 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-223" H 6400 2000 50  0001 C CNN
F 3 "" H 6200 1900 50  0000 C CNN
	1    6200 1900
	1    0    0    -1  
$EndComp
$Comp
L Q_PMOS_GDSD Q1
U 1 1 5A75DFF3
P 6200 1200
F 0 "Q1" H 6500 1250 50  0000 R CNN
F 1 "ZXMP10A18G" H 6900 1150 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-223" H 6400 1300 50  0001 C CNN
F 3 "" H 6200 1200 50  0000 C CNN
	1    6200 1200
	1    0    0    1   
$EndComp
$Comp
L R R7
U 1 1 5A75E08E
P 6650 1500
F 0 "R7" V 6730 1500 50  0000 C CNN
F 1 "10R" V 6650 1500 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 6580 1500 50  0001 C CNN
F 3 "" H 6650 1500 50  0000 C CNN
	1    6650 1500
	0    1    1    0   
$EndComp
$Comp
L R R14
U 1 1 5A75E1B5
P 5900 2150
F 0 "R14" V 5980 2150 50  0000 C CNN
F 1 "10k" V 5900 2150 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 5830 2150 50  0001 C CNN
F 3 "" H 5900 2150 50  0000 C CNN
	1    5900 2150
	1    0    0    -1  
$EndComp
$Comp
L R R10
U 1 1 5A75E20E
P 5200 1750
F 0 "R10" V 5280 1750 50  0000 C CNN
F 1 "10k" V 5200 1750 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 5130 1750 50  0001 C CNN
F 3 "" H 5200 1750 50  0000 C CNN
	1    5200 1750
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 5A75E25F
P 5350 1200
F 0 "R3" V 5430 1200 50  0000 C CNN
F 1 "10k" V 5350 1200 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 5280 1200 50  0001 C CNN
F 3 "" H 5350 1200 50  0000 C CNN
	1    5350 1200
	0    1    1    0   
$EndComp
$Comp
L R R11
U 1 1 5A75E604
P 4950 2000
F 0 "R11" V 5030 2000 50  0000 C CNN
F 1 "180R" V 4950 2000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4880 2000 50  0001 C CNN
F 3 "" H 4950 2000 50  0000 C CNN
	1    4950 2000
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 5A75E66F
P 4950 1500
F 0 "R6" V 5030 1500 50  0000 C CNN
F 1 "180R" V 4950 1500 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4880 1500 50  0001 C CNN
F 3 "" H 4950 1500 50  0000 C CNN
	1    4950 1500
	0    1    1    0   
$EndComp
Text GLabel 4600 1500 0    60   Input ~ 0
SW5VEN
Text GLabel 4600 2000 0    60   Input ~ 0
SWGNDEN
Text Notes 4900 750  0    60   ~ 0
Switch for Relay 0 Fuzed Detection
$Comp
L ULN2803A U7
U 1 1 5A75EB98
P 9200 5350
F 0 "U7" H 9200 5000 60  0000 C CNN
F 1 "ULN2803A" H 9200 5800 60  0000 C CNN
F 2 "Housings_DIP:DIP-18_W7.62mm" H 9200 5190 60  0001 C CNN
F 3 "" H 9200 5190 60  0001 C CNN
	1    9200 5350
	1    0    0    -1  
$EndComp
$Comp
L ULN2803A U5
U 1 1 5A75ECB5
P 9200 4350
F 0 "U5" H 9200 4000 60  0000 C CNN
F 1 "ULN2803A" H 9200 4800 60  0000 C CNN
F 2 "Housings_DIP:DIP-18_W7.62mm" H 9200 4190 60  0001 C CNN
F 3 "" H 9200 4190 60  0001 C CNN
	1    9200 4350
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P1
U 1 1 5A75EE22
P 7650 800
F 0 "P1" H 7650 1050 50  0000 C CNN
F 1 "CONN_01X04" V 7750 800 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-04_04x2.54mm_Straight" H 7650 800 50  0001 C CNN
F 3 "" H 7650 800 50  0000 C CNN
	1    7650 800 
	0    -1   -1   0   
$EndComp
$Comp
L MCP3422 U2
U 1 1 5A75EF10
P 9750 1700
F 0 "U2" H 9750 1400 60  0000 C CNN
F 1 "MCP3422" H 9750 2000 60  0000 C CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 9750 1700 60  0001 C CNN
F 3 "" H 9750 1700 60  0001 C CNN
	1    9750 1700
	0    -1   -1   0   
$EndComp
$Comp
L C C8
U 1 1 5A75EFED
P 9550 2500
F 0 "C8" H 9575 2600 50  0000 L CNN
F 1 "100nF" H 9575 2400 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 9588 2350 50  0001 C CNN
F 3 "" H 9550 2500 50  0000 C CNN
	1    9550 2500
	0    -1   -1   0   
$EndComp
$Comp
L C C1
U 1 1 5A75F074
P 9550 900
F 0 "C1" H 9575 1000 50  0000 L CNN
F 1 "100nF" H 9575 800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 9588 750 50  0001 C CNN
F 3 "" H 9550 900 50  0000 C CNN
	1    9550 900 
	0    -1   -1   0   
$EndComp
$Comp
L C C5
U 1 1 5A75F0EF
P 10200 1700
F 0 "C5" H 10225 1800 50  0000 L CNN
F 1 "1uF" H 10225 1600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 10238 1550 50  0001 C CNN
F 3 "" H 10200 1700 50  0000 C CNN
	1    10200 1700
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 5A75F2B5
P 8200 1450
F 0 "R4" V 8280 1450 50  0000 C CNN
F 1 "500k" V 8200 1450 50  0000 C CNN
F 2 "RES_TH:PRECISION_RESISTOR_5MM" V 8130 1450 50  0001 C CNN
F 3 "" H 8200 1450 50  0000 C CNN
	1    8200 1450
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 5A75F3B0
P 8500 1450
F 0 "R5" V 8580 1450 50  0000 C CNN
F 1 "500k" V 8500 1450 50  0000 C CNN
F 2 "RES_TH:PRECISION_RESISTOR_5MM" V 8430 1450 50  0001 C CNN
F 3 "" H 8500 1450 50  0000 C CNN
	1    8500 1450
	1    0    0    -1  
$EndComp
$Comp
L R R12
U 1 1 5A75F515
P 8200 2050
F 0 "R12" V 8280 2050 50  0000 C CNN
F 1 "10k" V 8200 2050 50  0000 C CNN
F 2 "RES_TH:PRECISION_RESISTOR_5MM" V 8130 2050 50  0001 C CNN
F 3 "" H 8200 2050 50  0000 C CNN
	1    8200 2050
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 5A75F564
P 8500 2050
F 0 "R13" V 8580 2050 50  0000 C CNN
F 1 "10k" V 8500 2050 50  0000 C CNN
F 2 "RES_TH:PRECISION_RESISTOR_5MM" V 8430 2050 50  0001 C CNN
F 3 "" H 8500 2050 50  0000 C CNN
	1    8500 2050
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 5A75FBB8
P 9150 1100
F 0 "R2" V 9230 1100 50  0000 C CNN
F 1 "10k" V 9150 1100 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 9080 1100 50  0001 C CNN
F 3 "" H 9150 1100 50  0000 C CNN
	1    9150 1100
	0    1    1    0   
$EndComp
$Comp
L R R15
U 1 1 5A75FCD2
P 9150 2400
F 0 "R15" V 9230 2400 50  0000 C CNN
F 1 "10k" V 9150 2400 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 9080 2400 50  0001 C CNN
F 3 "" H 9150 2400 50  0000 C CNN
	1    9150 2400
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 5A75FE75
P 9150 700
F 0 "R1" V 9230 700 50  0000 C CNN
F 1 "10k" V 9150 700 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 9080 700 50  0001 C CNN
F 3 "" H 9150 700 50  0000 C CNN
	1    9150 700 
	0    1    1    0   
$EndComp
$Comp
L R R16
U 1 1 5A75FF3A
P 9150 2700
F 0 "R16" V 9230 2700 50  0000 C CNN
F 1 "10k" V 9150 2700 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 9080 2700 50  0001 C CNN
F 3 "" H 9150 2700 50  0000 C CNN
	1    9150 2700
	0    1    1    0   
$EndComp
Text Notes 8000 600  0    60   ~ 0
Bus Voltage and Fused Relay Detect
Text GLabel 10500 1100 2    60   Input ~ 0
UCB0SCL
Text GLabel 10500 2300 2    60   Input ~ 0
UCB0SDA
$Comp
L R R18
U 1 1 5A761551
P 3900 3350
F 0 "R18" V 3980 3350 50  0000 C CNN
F 1 "4k7" V 3900 3350 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 3830 3350 50  0001 C CNN
F 3 "" H 3900 3350 50  0000 C CNN
	1    3900 3350
	1    0    0    -1  
$EndComp
$Comp
L R R19
U 1 1 5A76161A
P 4100 3350
F 0 "R19" V 4180 3350 50  0000 C CNN
F 1 "4k7" V 4100 3350 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4030 3350 50  0001 C CNN
F 3 "" H 4100 3350 50  0000 C CNN
	1    4100 3350
	1    0    0    -1  
$EndComp
Text GLabel 3800 1700 2    60   Input ~ 0
3V3
Text GLabel 3800 800  2    60   Input ~ 0
5V
$Comp
L C C10
U 1 1 5A761A8A
P 1850 2950
F 0 "C10" H 1875 3050 50  0000 L CNN
F 1 "100nF" H 1875 2850 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 1888 2800 50  0001 C CNN
F 3 "" H 1850 2950 50  0000 C CNN
	1    1850 2950
	0    1    1    0   
$EndComp
$Comp
L C C9
U 1 1 5A761B07
P 1850 2700
F 0 "C9" H 1875 2800 50  0000 L CNN
F 1 "1uF" H 1875 2600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 1888 2550 50  0001 C CNN
F 3 "" H 1850 2700 50  0000 C CNN
	1    1850 2700
	0    1    1    0   
$EndComp
Text GLabel 4300 3800 2    60   Input ~ 0
UCB0SDA
Text GLabel 4300 3900 2    60   Input ~ 0
UCB0SCL
$Comp
L CONN_01X08 P5
U 1 1 5A7623A2
P 10400 4250
F 0 "P5" H 10400 4700 50  0000 C CNN
F 1 "CONN_01X08" V 10500 4250 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-08_08x2.54mm_Straight" H 10400 4250 50  0001 C CNN
F 3 "" H 10400 4250 50  0000 C CNN
	1    10400 4250
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X08 P6
U 1 1 5A76241D
P 10400 5250
F 0 "P6" H 10400 5700 50  0000 C CNN
F 1 "CONN_01X08" V 10500 5250 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-08_08x2.54mm_Straight" H 10400 5250 50  0001 C CNN
F 3 "" H 10400 5250 50  0000 C CNN
	1    10400 5250
	1    0    0    -1  
$EndComp
$Comp
L R R22
U 1 1 5A762503
P 6800 5350
F 0 "R22" V 6880 5350 50  0000 C CNN
F 1 "33k" V 6800 5350 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 6730 5350 50  0001 C CNN
F 3 "" H 6800 5350 50  0000 C CNN
	1    6800 5350
	-1   0    0    1   
$EndComp
NoConn ~ 7000 4300
NoConn ~ 7000 4400
Text GLabel 6800 3900 0    60   Input ~ 0
UCB0SCL
Text GLabel 6800 4000 0    60   Input ~ 0
UCB0SDA
Text GLabel 9800 3600 0    60   Input ~ 0
12V
$Comp
L GND #PWR7
U 1 1 5A764632
P 7600 6100
F 0 "#PWR7" H 7600 5850 50  0001 C CNN
F 1 "GND" H 7600 5950 50  0000 C CNN
F 2 "" H 7600 6100 50  0000 C CNN
F 3 "" H 7600 6100 50  0000 C CNN
	1    7600 6100
	1    0    0    -1  
$EndComp
$Comp
L ISO3082 U8
U 1 1 5A76485E
P 2150 6700
F 0 "U8" H 2150 6850 60  0000 C CNN
F 1 "ISO3082" H 2150 6600 60  0000 C CNN
F 2 "Housings_SOIC:SOIC-16W_7.5x10.3mm_Pitch1.27mm" H 2150 6500 60  0001 C CNN
F 3 "" H 2150 6500 60  0001 C CNN
	1    2150 6700
	-1   0    0    -1  
$EndComp
$Comp
L R R21
U 1 1 5A7649E6
P 6500 5350
F 0 "R21" V 6580 5350 50  0000 C CNN
F 1 "33k" V 6500 5350 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 6430 5350 50  0001 C CNN
F 3 "" H 6500 5350 50  0000 C CNN
	1    6500 5350
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P4
U 1 1 5A764EDE
P 10400 3350
F 0 "P4" H 10400 3600 50  0000 C CNN
F 1 "CONN_01X04" V 10500 3350 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-04_04x2.54mm_Straight" H 10400 3350 50  0001 C CNN
F 3 "" H 10400 3350 50  0000 C CNN
	1    10400 3350
	1    0    0    -1  
$EndComp
Text GLabel 4300 3000 2    60   Input ~ 0
3V3
$Comp
L C C14
U 1 1 5A7654E0
P 1250 6100
F 0 "C14" H 1275 6200 50  0000 L CNN
F 1 "1uF" H 1275 6000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 1288 5950 50  0001 C CNN
F 3 "" H 1250 6100 50  0000 C CNN
	1    1250 6100
	0    -1   1    0   
$EndComp
$Comp
L C C15
U 1 1 5A7655E7
P 3150 6100
F 0 "C15" H 3175 6200 50  0000 L CNN
F 1 "1uF" H 3175 6000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 3188 5950 50  0001 C CNN
F 3 "" H 3150 6100 50  0000 C CNN
	1    3150 6100
	0    -1   1    0   
$EndComp
$Comp
L C C12
U 1 1 5A765698
P 8400 3550
F 0 "C12" H 8425 3650 50  0000 L CNN
F 1 "1uF" H 8425 3450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 8438 3400 50  0001 C CNN
F 3 "" H 8400 3550 50  0000 C CNN
	1    8400 3550
	1    0    0    -1  
$EndComp
$Comp
L PSM712 D1
U 1 1 5A765A3E
P 1100 7100
F 0 "D1" H 1100 7100 50  0000 C CNN
F 1 "PSM712" H 1100 6900 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 1180 7000 50  0001 C CNN
F 3 "" H 1180 7000 50  0000 C CNN
	1    1100 7100
	0    -1   1    0   
$EndComp
$Comp
L CONN_01X04 P8
U 1 1 5A765C68
P 700 6650
F 0 "P8" H 700 6900 50  0000 C CNN
F 1 "CONN_01X04" V 800 6650 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-04_04x2.54mm_Straight" H 700 6650 50  0001 C CNN
F 3 "" H 700 6650 50  0000 C CNN
	1    700  6650
	-1   0    0    -1  
$EndComp
Text Notes 1500 7300 0    60   ~ 0
Power for isolator provided from RS485 bus
Text GLabel 3100 6800 2    60   Input ~ 0
UCA0TXD
Text GLabel 3100 6500 2    60   Input ~ 0
UCA0RXD
Text GLabel 1100 3500 0    60   Input ~ 0
UCA0RXD
Text GLabel 1100 3600 0    60   Input ~ 0
UCA0TXD
Text GLabel 1100 3400 0    60   Input ~ 0
RS485TXEN
Text GLabel 1100 3700 0    60   Input ~ 0
RS485RXEN
Text GLabel 3100 6700 2    60   Input ~ 0
RS485TXEN
Text GLabel 3100 6600 2    60   Input ~ 0
RS485RXEN
Text GLabel 6400 4500 0    60   Input ~ 0
IOEXRST
Text GLabel 3150 4000 2    60   Input ~ 0
IOEXRST
$Comp
L CONN_01X04 P3
U 1 1 5A76DB15
P 3800 2650
F 0 "P3" H 3800 2900 50  0000 C CNN
F 1 "CONN_01X04" V 3900 2650 50  0000 C CNN
F 2 "Custom_Descretes:MINICON_01X04" H 3800 2650 50  0001 C CNN
F 3 "" H 3800 2650 50  0000 C CNN
	1    3800 2650
	1    0    0    -1  
$EndComp
Text GLabel 1000 2500 0    60   Input ~ 0
3V3
$Comp
L R R17
U 1 1 5A76E286
P 3700 3350
F 0 "R17" V 3780 3350 50  0000 C CNN
F 1 "10k" V 3700 3350 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 3630 3350 50  0001 C CNN
F 3 "" H 3700 3350 50  0000 C CNN
	1    3700 3350
	-1   0    0    1   
$EndComp
$Comp
L C C11
U 1 1 5A76E7F7
P 3400 3350
F 0 "C11" H 3425 3450 50  0000 L CNN
F 1 "10nF" H 3425 3250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3438 3200 50  0001 C CNN
F 3 "" H 3400 3350 50  0000 C CNN
	1    3400 3350
	1    0    0    -1  
$EndComp
Text GLabel 1100 4000 0    60   Input ~ 0
SW5VEN
Text GLabel 1100 4100 0    60   Input ~ 0
SWGNDEN
Text GLabel 5000 900  0    60   Input ~ 0
5V
Text GLabel 800  800  0    60   Input ~ 0
12V
$Comp
L GND #PWR2
U 1 1 5A77F477
P 1700 2300
F 0 "#PWR2" H 1700 2050 50  0001 C CNN
F 1 "GND" H 1700 2150 50  0000 C CNN
F 2 "" H 1700 2300 50  0000 C CNN
F 3 "" H 1700 2300 50  0000 C CNN
	1    1700 2300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR1
U 1 1 5A77F4F1
P 1700 1400
F 0 "#PWR1" H 1700 1150 50  0001 C CNN
F 1 "GND" H 1700 1250 50  0000 C CNN
F 2 "" H 1700 1400 50  0000 C CNN
F 3 "" H 1700 1400 50  0000 C CNN
	1    1700 1400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR6
U 1 1 5A781864
P 6450 2500
F 0 "#PWR6" H 6450 2250 50  0001 C CNN
F 1 "GND" H 6450 2350 50  0000 C CNN
F 2 "" H 6450 2500 50  0000 C CNN
F 3 "" H 6450 2500 50  0000 C CNN
	1    6450 2500
	1    0    0    -1  
$EndComp
Text GLabel 10300 700  2    60   Input ~ 0
3V3
$Comp
L GND #PWR8
U 1 1 5A782C52
P 10300 2550
F 0 "#PWR8" H 10300 2300 50  0001 C CNN
F 1 "GND" H 10300 2400 50  0000 C CNN
F 2 "" H 10300 2550 50  0000 C CNN
F 3 "" H 10300 2550 50  0000 C CNN
	1    10300 2550
	1    0    0    -1  
$EndComp
Text GLabel 7500 3300 0    60   Input ~ 0
3V3
Text Notes 8450 6450 0    60   ~ 0
COM is diode protection to +V\nShould already be present on relay
Text GLabel 2800 6100 0    60   Input ~ 0
3V3
$Comp
L GND #PWR5
U 1 1 5A7872C8
P 3600 6200
F 0 "#PWR5" H 3600 5950 50  0001 C CNN
F 1 "GND" H 3600 6050 50  0000 C CNN
F 2 "" H 3600 6200 50  0000 C CNN
F 3 "" H 3600 6200 50  0000 C CNN
	1    3600 6200
	1    0    0    -1  
$EndComp
Text Notes 4900 2550 0    60   ~ 0
SOT223 >= 200V MOSFET
$Comp
L Q_NMOS_GDSD Q4
U 1 1 5A7CCD8E
P 7100 2100
F 0 "Q4" H 7050 2250 50  0000 R CNN
F 1 "FQT4N20L" H 6800 1950 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-223" H 7300 2200 50  0001 C CNN
F 3 "" H 7100 2100 50  0000 C CNN
	1    7100 2100
	1    0    0    -1  
$EndComp
$Comp
L Q_NMOS_GDSD Q5
U 1 1 5A7CCEBF
P 7700 2100
F 0 "Q5" H 8000 2150 50  0000 R CNN
F 1 "FQT4N20L" H 8200 2000 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-223" H 7900 2200 50  0001 C CNN
F 3 "" H 7700 2100 50  0000 C CNN
	1    7700 2100
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 5A7CD1F0
P 7800 1550
F 0 "R9" V 7880 1550 50  0000 C CNN
F 1 "1k" V 7800 1550 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 7730 1550 50  0001 C CNN
F 3 "" H 7800 1550 50  0000 C CNN
	1    7800 1550
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 5A7CD273
P 7200 1550
F 0 "R8" V 7280 1550 50  0000 C CNN
F 1 "1k" V 7200 1550 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 7130 1550 50  0001 C CNN
F 3 "" H 7200 1550 50  0000 C CNN
	1    7200 1550
	1    0    0    -1  
$EndComp
Text GLabel 7950 2900 2    60   Input ~ 0
DISCH_BUSA
Text GLabel 6700 2900 0    60   Input ~ 0
DISCH_BUSB
Text Notes 3250 7700 0    60   ~ 0
NCH SOT223 FET: IRLL110BPF (100V) / STN4NF20L (200V) / FQT4N20L (200V)\nPCH SOT223 FET: BSP220,115 (-220V) / ZXMP10A18G (-100V)
Text GLabel 3150 4300 2    60   Input ~ 0
DISCH_BUSA
Text GLabel 3150 4400 2    60   Input ~ 0
DISCH_BUSB
$Comp
L CONN_01X03 P7
U 1 1 5A7EFECB
P 2400 5400
F 0 "P7" H 2400 5600 50  0000 C CNN
F 1 "CONN_01X03" V 2500 5400 50  0000 C CNN
F 2 "Custom_Descretes:DS18B20" H 2400 5400 50  0001 C CNN
F 3 "" H 2400 5400 50  0000 C CNN
	1    2400 5400
	-1   0    0    -1  
$EndComp
Text GLabel 2600 4900 0    60   Input ~ 0
3V3
$Comp
L GND #PWR3
U 1 1 5A7F06B7
P 2700 5600
F 0 "#PWR3" H 2700 5350 50  0001 C CNN
F 1 "GND" H 2700 5450 50  0000 C CNN
F 2 "" H 2700 5600 50  0000 C CNN
F 3 "" H 2700 5600 50  0000 C CNN
	1    2700 5600
	1    0    0    -1  
$EndComp
Text Notes 1800 5450 0    60   ~ 0
DS18B20
$Comp
L R R20
U 1 1 5A7F2DD5
P 2800 5150
F 0 "R20" V 2880 5150 50  0000 C CNN
F 1 "4k7" V 2800 5150 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 2730 5150 50  0001 C CNN
F 3 "" H 2800 5150 50  0000 C CNN
	1    2800 5150
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P2
U 1 1 5A7F7711
P 700 1450
F 0 "P2" H 700 1700 50  0000 C CNN
F 1 "CONN_01X04" V 800 1450 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-04_04x2.54mm_Straight" H 700 1450 50  0001 C CNN
F 3 "" H 700 1450 50  0000 C CNN
	1    700  1450
	-1   0    0    -1  
$EndComp
$Comp
L CP1 C13
U 1 1 5A7F883C
P 10000 5950
F 0 "C13" H 10025 6050 50  0000 L CNN
F 1 "100uF" H 10025 5850 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206" H 10000 5950 50  0001 C CNN
F 3 "" H 10000 5950 50  0000 C CNN
	1    10000 5950
	1    0    0    -1  
$EndComp
Text Notes 4550 2650 0    60   ~ 0
ZXMP10A18G is -100V (required -85V)
Text Notes 4350 6400 0    60   ~ 0
ULN2803A Inputs will float (because MCP23017 is in reset mode)\nuntil the MSP430G2553 has initialised. The ULN2803A has internal\npull-down resistors so this short-lived condition is ok.
$Comp
L R R23
U 1 1 5AA3F5FA
P 7200 2650
F 0 "R23" V 7280 2650 50  0000 C CNN
F 1 "33k" V 7200 2650 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 7130 2650 50  0001 C CNN
F 3 "" H 7200 2650 50  0000 C CNN
	1    7200 2650
	1    0    0    -1  
$EndComp
$Comp
L R R24
U 1 1 5AA3F6C7
P 7800 2650
F 0 "R24" V 7880 2650 50  0000 C CNN
F 1 "33k" V 7800 2650 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 7730 2650 50  0001 C CNN
F 3 "" H 7800 2650 50  0000 C CNN
	1    7800 2650
	1    0    0    -1  
$EndComp
$Comp
L Q_NMOS_GSD Q2
U 1 1 5AA418B4
P 5500 1500
F 0 "Q2" H 5800 1550 50  0000 R CNN
F 1 "FDV303N" H 6000 1450 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 5700 1600 50  0001 C CNN
F 3 "" H 5500 1500 50  0000 C CNN
	1    5500 1500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR4
U 1 1 5AA42C4C
P 2800 3100
F 0 "#PWR4" H 2800 2850 50  0001 C CNN
F 1 "GND" H 2800 2950 50  0000 C CNN
F 2 "" H 2800 3100 50  0000 C CNN
F 3 "" H 2800 3100 50  0000 C CNN
	1    2800 3100
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P9
U 1 1 5AA4F344
P 4300 2650
F 0 "P9" H 4300 2900 50  0000 C CNN
F 1 "CONN_01X04" V 4400 2650 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-04_04x2.54mm_Straight" H 4300 2650 50  0001 C CNN
F 3 "" H 4300 2650 50  0000 C CNN
	1    4300 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 2100 1700 2300
Wire Wire Line
	1000 2200 3600 2200
Wire Wire Line
	3600 2200 3600 2100
Wire Wire Line
	2400 2100 2400 2200
Connection ~ 2400 2200
Wire Wire Line
	2500 2100 2500 2200
Connection ~ 2500 2200
Wire Wire Line
	3000 1700 3800 1700
Wire Wire Line
	3600 1700 3600 1800
Wire Wire Line
	1200 1700 1900 1700
Wire Wire Line
	1700 1700 1700 1800
Wire Wire Line
	800  800  1900 800 
Wire Wire Line
	1700 800  1700 900 
Wire Wire Line
	1400 800  1400 900 
Connection ~ 1700 800 
Wire Wire Line
	1400 1200 1400 1300
Wire Wire Line
	1400 1300 3600 1300
Wire Wire Line
	1700 1200 1700 1400
Wire Wire Line
	2400 1300 2400 1200
Connection ~ 1700 1300
Wire Wire Line
	2500 1300 2500 1200
Connection ~ 2400 1300
Wire Wire Line
	3600 1300 3600 1200
Connection ~ 2500 1300
Wire Wire Line
	3600 900  3600 800 
Wire Wire Line
	3000 800  3800 800 
Wire Wire Line
	5600 1300 5600 1200
Wire Wire Line
	5500 1200 6000 1200
Connection ~ 5600 1200
Wire Wire Line
	6300 900  6300 1000
Wire Wire Line
	5000 900  6300 900 
Wire Wire Line
	5100 900  5100 1200
Wire Wire Line
	5100 1200 5200 1200
Wire Wire Line
	5100 1500 5300 1500
Wire Wire Line
	5200 1500 5200 1600
Wire Wire Line
	5200 1900 5200 2400
Wire Wire Line
	5900 2400 5900 2300
Wire Wire Line
	6300 2400 6300 2100
Connection ~ 5900 2400
Wire Wire Line
	5500 1900 6000 1900
Wire Wire Line
	5900 1900 5900 2000
Wire Wire Line
	6300 1700 6300 1400
Wire Wire Line
	6400 1400 6400 1700
Wire Wire Line
	6300 1500 6500 1500
Connection ~ 6400 1500
Connection ~ 6300 1500
Wire Wire Line
	5600 1700 5600 2400
Connection ~ 5600 2400
Connection ~ 5200 1500
Wire Wire Line
	4600 1500 4800 1500
Wire Wire Line
	4600 2000 4800 2000
Wire Wire Line
	9600 1100 9600 1200
Wire Wire Line
	9300 1100 9600 1100
Wire Wire Line
	9400 1100 9400 900 
Wire Wire Line
	9700 700  9700 1200
Wire Wire Line
	9700 2200 9700 2700
Wire Wire Line
	9600 2300 9600 2200
Wire Wire Line
	7800 1100 8500 1100
Wire Wire Line
	7800 1000 7800 1400
Connection ~ 6300 2400
Connection ~ 9400 1100
Wire Wire Line
	9700 700  9300 700 
Connection ~ 9700 900 
Wire Wire Line
	9700 2700 9300 2700
Connection ~ 9700 2500
Wire Wire Line
	9800 2200 9800 2700
Wire Wire Line
	9800 2700 10200 2700
Wire Wire Line
	10200 2700 10200 1850
Wire Wire Line
	9900 1200 9900 1100
Wire Wire Line
	9900 1100 10500 1100
Wire Wire Line
	10500 2300 9900 2300
Wire Wire Line
	9900 2300 9900 2200
Wire Wire Line
	3900 3500 3900 3800
Wire Wire Line
	4100 3500 4100 3900
Connection ~ 3600 800 
Connection ~ 3600 1700
Wire Wire Line
	2600 3800 4300 3800
Wire Wire Line
	2600 3900 4300 3900
Connection ~ 4100 3900
Connection ~ 3900 3800
Wire Wire Line
	3900 3200 3900 3000
Wire Wire Line
	4100 3000 4100 3200
Wire Wire Line
	7600 5900 7600 6100
Wire Wire Line
	8400 6000 6500 6000
Wire Wire Line
	6800 6000 6800 5500
Wire Wire Line
	6800 4900 6800 5200
Wire Wire Line
	6800 5100 7000 5100
Wire Wire Line
	6800 4900 7000 4900
Connection ~ 6800 5100
Wire Wire Line
	7000 5000 6800 5000
Connection ~ 6800 5000
Wire Wire Line
	7000 3900 6800 3900
Wire Wire Line
	6800 4000 7000 4000
Wire Wire Line
	8200 3900 8600 3900
Wire Wire Line
	8200 4000 8600 4000
Wire Wire Line
	8200 4100 8600 4100
Wire Wire Line
	8200 4200 8600 4200
Wire Wire Line
	8200 4300 8600 4300
Wire Wire Line
	8200 4400 8600 4400
Wire Wire Line
	8200 4500 8600 4500
Wire Wire Line
	8200 4600 8600 4600
Wire Wire Line
	8200 4900 8600 4900
Wire Wire Line
	8200 5000 8600 5000
Wire Wire Line
	8200 5100 8600 5100
Wire Wire Line
	8200 5200 8600 5200
Wire Wire Line
	8200 5300 8600 5300
Wire Wire Line
	8200 5400 8600 5400
Wire Wire Line
	8200 5500 8600 5500
Wire Wire Line
	8200 5600 8600 5600
Wire Wire Line
	10000 5700 9800 5700
Wire Wire Line
	10000 3200 10000 5800
Wire Wire Line
	10000 3600 9800 3600
Wire Wire Line
	9800 4700 10000 4700
Connection ~ 10000 4700
Wire Wire Line
	9800 3900 10200 3900
Wire Wire Line
	9800 4000 10200 4000
Wire Wire Line
	9800 4100 10200 4100
Wire Wire Line
	9800 4200 10200 4200
Wire Wire Line
	9800 4300 10200 4300
Wire Wire Line
	9800 4400 10200 4400
Wire Wire Line
	9800 4500 10200 4500
Wire Wire Line
	9800 4600 10200 4600
Wire Wire Line
	9800 4900 10200 4900
Wire Wire Line
	9800 5000 10200 5000
Wire Wire Line
	9800 5100 10200 5100
Wire Wire Line
	9800 5200 10200 5200
Wire Wire Line
	9800 5300 10200 5300
Wire Wire Line
	9800 5400 10200 5400
Wire Wire Line
	9800 5500 10200 5500
Wire Wire Line
	9800 5600 10200 5600
Wire Wire Line
	8600 4700 8400 4700
Wire Wire Line
	8400 3700 8400 6200
Wire Wire Line
	8400 5700 8600 5700
Connection ~ 8400 5700
Wire Wire Line
	6500 5200 6500 4500
Wire Wire Line
	6400 4500 7000 4500
Wire Wire Line
	6500 6000 6500 5500
Connection ~ 6800 6000
Connection ~ 7600 6000
Wire Wire Line
	10200 3200 10000 3200
Connection ~ 10000 3600
Wire Wire Line
	10200 3300 10000 3300
Connection ~ 10000 3300
Wire Wire Line
	10200 3400 10000 3400
Connection ~ 10000 3400
Wire Wire Line
	10200 3500 10000 3500
Connection ~ 10000 3500
Wire Wire Line
	1500 6900 1400 6900
Wire Wire Line
	1400 6400 1400 7500
Wire Wire Line
	1400 7000 1500 7000
Wire Wire Line
	1500 6700 900  6700
Wire Wire Line
	900  6600 1500 6600
Wire Wire Line
	1500 6300 1100 6300
Wire Wire Line
	1100 6300 1100 6500
Wire Wire Line
	1100 6500 900  6500
Wire Wire Line
	900  6800 1400 6800
Connection ~ 1400 6900
Wire Wire Line
	1000 6400 1500 6400
Connection ~ 1400 6800
Wire Wire Line
	1000 6900 1000 6600
Connection ~ 1000 6600
Wire Wire Line
	1200 6900 1200 6700
Connection ~ 1200 6700
Wire Wire Line
	1400 7500 1100 7500
Wire Wire Line
	1100 7500 1100 7400
Connection ~ 1400 7000
Wire Wire Line
	1000 6400 1000 6100
Wire Wire Line
	1000 6100 1100 6100
Connection ~ 1400 6400
Wire Wire Line
	1400 6100 1500 6100
Wire Wire Line
	1500 6100 1500 6300
Connection ~ 1500 6300
Wire Wire Line
	2800 6400 3400 6400
Wire Wire Line
	2800 6500 3100 6500
Wire Wire Line
	3100 6800 2800 6800
Wire Wire Line
	2800 6900 2900 6900
Wire Wire Line
	2900 6900 2900 7000
Wire Wire Line
	2800 7000 3000 7000
Wire Wire Line
	3000 7000 3000 6400
Connection ~ 3000 6400
Connection ~ 2900 7000
Wire Wire Line
	2700 2700 2700 3300
Wire Wire Line
	2700 3300 2600 3300
Wire Wire Line
	2700 2700 2000 2700
Wire Wire Line
	1700 2700 1100 2700
Wire Wire Line
	1100 2500 1100 3300
Wire Wire Line
	1100 3300 1200 3300
Wire Wire Line
	3100 6600 2800 6600
Wire Wire Line
	2800 6700 3100 6700
Wire Wire Line
	1100 3500 1200 3500
Wire Wire Line
	1100 3600 1200 3600
Connection ~ 6500 4500
Wire Wire Line
	2600 4000 3150 4000
Wire Wire Line
	3100 2600 3100 3700
Wire Wire Line
	2600 3600 3000 3600
Wire Wire Line
	1000 2500 4100 2500
Connection ~ 1100 2700
Wire Wire Line
	2700 2800 4100 2800
Connection ~ 2700 2800
Wire Wire Line
	3700 3200 3700 3000
Wire Wire Line
	3700 3000 4300 3000
Connection ~ 3900 3000
Connection ~ 4100 3000
Wire Wire Line
	3700 3700 3700 3500
Wire Wire Line
	2600 3700 3700 3700
Connection ~ 3100 3700
Wire Wire Line
	3400 3500 3400 3700
Connection ~ 3400 3700
Wire Wire Line
	3400 3200 3400 2800
Connection ~ 3400 2800
Connection ~ 1100 2500
Connection ~ 1400 800 
Connection ~ 1700 1700
Connection ~ 1700 2200
Wire Wire Line
	6450 2400 6450 2500
Connection ~ 6450 2400
Connection ~ 5100 900 
Wire Wire Line
	10300 2550 10300 2500
Wire Wire Line
	10300 2500 10200 2500
Connection ~ 10200 2500
Wire Wire Line
	9800 700  10300 700 
Connection ~ 10200 700 
Wire Wire Line
	8400 3300 8400 3400
Wire Wire Line
	7500 3300 8400 3300
Wire Wire Line
	7600 3300 7600 3600
Connection ~ 8400 4700
Connection ~ 7600 3300
Wire Wire Line
	2800 6300 2900 6300
Wire Wire Line
	2900 6300 2900 6100
Wire Wire Line
	2800 6100 3000 6100
Wire Wire Line
	3300 6100 3600 6100
Wire Wire Line
	3400 6400 3400 6100
Connection ~ 2900 6100
Wire Wire Line
	3600 6100 3600 6200
Connection ~ 3400 6100
Wire Wire Line
	2000 2950 2700 2950
Connection ~ 2700 2950
Wire Wire Line
	1700 2950 1100 2950
Connection ~ 1100 2950
Wire Wire Line
	5500 1900 5500 2000
Wire Wire Line
	5500 2000 5100 2000
Connection ~ 5900 1900
Wire Wire Line
	7700 1000 7700 1300
Wire Wire Line
	7700 1200 8200 1200
Connection ~ 7800 1100
Wire Wire Line
	7800 1700 7800 1900
Wire Wire Line
	7900 1900 7900 1800
Wire Wire Line
	7900 1800 7800 1800
Connection ~ 7800 1800
Wire Wire Line
	7800 2300 7800 2500
Wire Wire Line
	5200 2400 8500 2400
Wire Wire Line
	7200 2300 7200 2500
Connection ~ 7200 2400
Connection ~ 7800 2400
Wire Wire Line
	7700 1300 7200 1300
Wire Wire Line
	7200 1300 7200 1400
Connection ~ 7700 1200
Wire Wire Line
	7200 1700 7200 1900
Wire Wire Line
	7200 1800 7300 1800
Wire Wire Line
	7300 1800 7300 1900
Connection ~ 7200 1800
Wire Wire Line
	7500 2100 7400 2100
Wire Wire Line
	6800 2100 6800 2900
Wire Wire Line
	6800 2100 6900 2100
Wire Wire Line
	8200 2200 8200 2400
Connection ~ 8200 2400
Wire Wire Line
	8200 2300 8350 2300
Wire Wire Line
	8350 2300 8350 2700
Wire Wire Line
	8350 2700 9000 2700
Connection ~ 8200 2300
Wire Wire Line
	8500 2400 8500 2200
Wire Wire Line
	8500 1900 8500 1600
Wire Wire Line
	8200 1600 8200 1900
Wire Wire Line
	8500 1100 8500 1300
Wire Wire Line
	8200 1200 8200 1300
Wire Wire Line
	8700 1800 8200 1800
Connection ~ 8200 1800
Wire Wire Line
	8500 1700 8700 1700
Wire Wire Line
	8700 1700 8700 700 
Wire Wire Line
	8700 700  9000 700 
Connection ~ 8500 1700
Wire Wire Line
	8500 2300 8800 2300
Wire Wire Line
	8800 2300 8800 1100
Wire Wire Line
	8800 1100 9000 1100
Connection ~ 8500 2300
Wire Wire Line
	8700 1800 8700 2400
Wire Wire Line
	8700 2400 9000 2400
Wire Wire Line
	9400 2300 9400 2500
Wire Wire Line
	9400 2400 9300 2400
Wire Wire Line
	9400 2300 9600 2300
Connection ~ 9400 2400
Wire Wire Line
	9800 1200 9800 700 
Wire Wire Line
	10200 700  10200 1550
Wire Wire Line
	3150 4300 2600 4300
Wire Wire Line
	2600 4400 3150 4400
Wire Wire Line
	2600 5500 2700 5500
Wire Wire Line
	2700 5500 2700 5600
Wire Wire Line
	2600 4500 3000 4500
Wire Wire Line
	2600 5300 2700 5300
Wire Wire Line
	2700 5300 2700 4900
Wire Wire Line
	2600 4900 2800 4900
Wire Wire Line
	2800 4900 2800 5000
Connection ~ 2700 4900
Wire Wire Line
	2600 5400 3000 5400
Wire Wire Line
	3000 5400 3000 4500
Wire Wire Line
	2800 5300 2800 5400
Connection ~ 2800 5400
Wire Wire Line
	7600 1000 7600 1100
Wire Wire Line
	7600 1100 7000 1100
Wire Wire Line
	7000 1100 7000 1500
Wire Wire Line
	7000 1500 6800 1500
Wire Wire Line
	7500 1000 7500 1100
Connection ~ 7500 1100
Wire Wire Line
	1000 1500 1000 2200
Wire Wire Line
	1000 1600 900  1600
Wire Wire Line
	1200 1700 1200 800 
Connection ~ 1200 800 
Wire Wire Line
	900  1300 1200 1300
Connection ~ 1200 1300
Wire Wire Line
	900  1400 1000 1400
Wire Wire Line
	1000 1400 1000 1300
Connection ~ 1000 1300
Wire Wire Line
	900  1500 1000 1500
Connection ~ 1000 1600
Wire Wire Line
	8400 6200 10000 6200
Wire Wire Line
	10000 6200 10000 6100
Connection ~ 8400 6000
Connection ~ 10000 5700
Wire Wire Line
	6700 2900 7200 2900
Wire Wire Line
	7400 2100 7400 2900
Wire Wire Line
	7400 2900 7950 2900
Wire Wire Line
	7800 2800 7800 2900
Connection ~ 7800 2900
Wire Wire Line
	7200 2900 7200 2800
Connection ~ 6800 2900
Wire Wire Line
	1100 4000 1200 4000
Wire Wire Line
	1100 4100 1200 4100
Wire Wire Line
	1100 3700 1200 3700
Wire Wire Line
	1100 3400 1200 3400
Wire Wire Line
	3100 2600 3600 2600
Wire Wire Line
	3600 2700 3000 2700
Wire Wire Line
	3000 2700 3000 3600
Wire Wire Line
	2700 3000 2800 3000
Wire Wire Line
	2800 3000 2800 3100
Connection ~ 2700 3000
Connection ~ 3600 2500
Connection ~ 3600 2800
$EndSCHEMATC
