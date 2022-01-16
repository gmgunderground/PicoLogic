#include <Arduino.h>

// PIN Definition for virtual logic ports

// AND Device
#define AND_A   0
#define AND_B   1
#define AND_Y   28

// OR Device
#define OR_A   2
#define OR_B   3
#define OR_Y   27

// XOR Device
#define XOR_A   4
#define XOR_B   5
#define XOR_Y   26

// NOT Device
#define NOT_A   6
#define NOT_Y   22

// NAND Device (Chaining of AND and NOT)
#define NAND_Y  21

byte And(byte pa, byte pb);
byte Or(byte pa, byte pb);
byte Xor(byte pa, byte pb);
byte Not(byte pa);

void setup() 
{
    pinMode(AND_A, INPUT_PULLDOWN);
    pinMode(AND_B, INPUT_PULLDOWN);
    pinMode(AND_Y, OUTPUT);

    pinMode(OR_A, INPUT_PULLDOWN);
    pinMode(OR_B, INPUT_PULLDOWN);
    pinMode(OR_Y, OUTPUT);

    pinMode(XOR_A, INPUT_PULLDOWN);
    pinMode(XOR_B, INPUT_PULLDOWN);
    pinMode(XOR_Y, OUTPUT);

    pinMode(NOT_A, INPUT_PULLDOWN);
    pinMode(NOT_Y, OUTPUT);
}

void loop() 
{
    // AND
    digitalWrite(AND_Y, And(digitalRead(AND_A), digitalRead(AND_B)));
    
    // OR
    digitalWrite(OR_Y, Or(digitalRead(OR_A), digitalRead(OR_B)));

    // XOR
    digitalWrite(XOR_Y, Xor(digitalRead(XOR_A), digitalRead(XOR_B)));

    // NOT
    digitalWrite(NOT_Y, Not(digitalRead(NOT_A)));

    // Easily chain to create new logic
    // NAND (AND + NOT)
    digitalWrite(NAND_Y, Not(And(digitalRead(AND_A), digitalRead(AND_B))));
}

// INPUT   OUTPUT
// A | B    Y
// --|-------------
// 0 | 0    0
// 0 | 1    0
// 1 | 0    0
// 1 | 1    1
byte And(byte pa, byte pb)
{
    byte a = pa & 0x01;
    byte b = pb & 0x01;
    byte y = 0;

    if (a == 0 && b == 0) y = 0;
    else if (a == 0 && b == 1) y = 0;
    else if (a == 1 && b == 0) y = 0;
    else if (a == 1 && b == 1) y = 1;    

    return (y & 1);
}

// INPUT   OUTPUT
// A | B    Y
// --|-------------
// 0 | 0    0
// 0 | 1    1
// 1 | 0    1
// 1 | 1    1
byte Or(byte pa, byte pb)
{
    byte a = pa & 0x01;
    byte b = pb & 0x01;
    byte y = 0;

    if (a == 0 && b == 0) y = 0;
    else if (a == 0 && b == 1) y = 1;
    else if (a == 1 && b == 0) y = 1;
    else if (a == 1 && b == 1) y = 1;

    return (y & 1);
}

// INPUT   OUTPUT
// A | B    Y
// --|-------------
// 0 | 0    0
// 0 | 1    1
// 1 | 0    1
// 1 | 1    0
byte Xor(byte pa, byte pb)
{
    byte a = pa & 0x01;
    byte b = pb & 0x01;
    byte y = 0;

    if (a == 0 && b == 0) y = 0;
    else if (a == 0 && b == 1) y = 1;
    else if (a == 1 && b == 0) y = 1;
    else if (a == 1 && b == 1) y = 0;

    return (y & 1);
}

// INPUT   OUTPUT
// A       Y
// ----------------
// 0       1
// 1       0
byte Not(byte pa)
{
    byte a = pa & 0x01;
    byte y = 0;

    if (a == 0) y = 1;
    else if (a == 1) y = 0;

    return (y & 1);
}
