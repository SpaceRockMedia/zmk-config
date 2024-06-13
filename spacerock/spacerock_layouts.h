
#pragma once

#include <dt-bindings/zmk/keys.h>


// FN row
#define _______________LAY_L_FUN_01_05_______________ &kp F1 &kp F2 &kp F3 &kp F4 &kp F5
#define _______________LAY_R_FUN_06_10_______________ &kp F6 &kp F7 &kp F8 &kp F9 &kp F10

// Blank row
#define ______________________________________________________ ___ ___ ___ ___ ___
#define ________________________________                       ___ ___ ___

// COLEMAK-DH
#define ____________________COLEMAK_DH__LT____________________ &kp Q &kp W &kp F &kp P &kp B
#define ____________________COLEMAK_DH__LM____________________ &kp A &kp R &kp S &kp T &kp G
#define ____________________COLEMAK_DH__LB____________________ &kp Z &kp X &kp C &kp D &kp V

#define ____________________COLEMAK_DH__RT____________________ &kp J &kp L &kp U     &lt WIN Y &kp SEMI
#define ____________________COLEMAK_DH__RM____________________ &kp M &kp N &kp E     &kp I     &kp O
#define ____________________COLEMAK_DH__RB____________________ &kp K &kp H &kp COMMA &kp DOT   &kp FSLH

// QWERTY
#define ______________________QWERTY__LT______________________ &kp Q &kp W &kp E &kp R &kp T
#define ______________________QWERTY__LM______________________ &kp A &kp S &kp D &kp F &kp G
#define ______________________QWERTY__LB______________________ &kp Z &kp X &kp C &kp V &kp B

#define ______________________QWERTY__RT______________________ &kp Y &kp U  &kp I     &kp O   &kp P
#define ______________________QWERTY__RM______________________ &kp H &kp J  &kp K     &kp L   &kp SEMI
#define ______________________QWERTY__RB______________________ &kp N &kp M  &kp COMMA &kp DOT &kp FSLH

//
// MODS
//
#define ______________________HRM__GASC_______________________ &kp LGUI  &kp LALT  &kp LSHFT &kp LCTRL
#define ______________________HRM__CSAG_______________________ &kp LCTRL &kp LSHFT &kp LALT &kp LGUI


//
// NAVS
//
#define _______________________NAVS_TOP_______________________ &kp PG_UP &kp ME(LEFT) &kp UP   &kp ME(RIGHT) &kp ME(UP)
#define _______________________NAVS_MID_______________________ &kp PG_DN &kp LEFT     &kp DOWN &kp RIGHT     &kp ME(DOWN)

//
// NUMS
//
#define ________________________NUMS_TOP_______________________ &kp EQUAL  &kp N7     &kp N8     &kp N9     &kp MINUS
#define ________________________NUMS_MID_______________________ &kp ASTRK  &kp N4     &kp N5     &kp N6     &kp PLUS
#define ________________________NUMS_BOT_______________________ &kp N0     &kp N1     &kp N2     &kp N3     &kp FSLH


