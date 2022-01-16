# PicoLogic
Logic port implementation using Raspberry Pi Pico RP2040 using Arduino Framework

This is an educational project to show you haow to implementa a logic port using RP2040, all logic functions are implemented by hand

AND Device
------------------------------
Input A  -> GPIO0  -> Pin 1
Input B  -> GPIO1  -> Pin 2
Output Y -> GPIO28 -> Pin 34

OR Device
------------------------------
Input A  -> GPIO2  -> Pin 4
Input B  -> GPIO3  -> Pin 5
Output Y -> GPIO27 -> Pin 32

XOR Device
------------------------------
Input A  -> GPIO4  -> Pin 6
Input B  -> GPIO5  -> Pin 7
Output Y -> GPIO26 -> Pin 31

NOT Device
------------------------------
Input A  -> GPIO6  -> Pin 9
Output Y -> GPIO22 -> Pin 29