
#pragma once

#include <dt-bindings/zmk/keys.h>
#include "aliases.h"

// NUM row
#define __X_LEFT_NUM_ROW__ &kp N1 &kp N2 &kp N3 &kp N4 &kp N5
#define __X_RIGHT_NUM_ROW__ &kp N8 &kp N9 &kp N0 &kp N0 &kp N0

// FUN row
#define _______________LAY_L_FUN_01_05_______________ &kp F1 &kp F2 &kp F3 &kp F4 &kp F5
#define _______________LAY_R_FUN_06_10_______________ &kp F6 &kp F7 &kp F8 &kp F9 &kp F10

// Blank row
#define ______________________________________________________ ___ ___ ___ ___ ___
#define ________________________________                       ___ ___ ___

//
// HRM
//
#define _____________HRM__QWERTY__GACS_____________ &hm LGUI A  &hm LALT S  &hm LCTRL D &hs LSHFT F
#define _____________HRM__QWERTY__SCAG_____________ &hs RSHFT J &hm RCTRL K &hm LALT L  &hm RGUI SEMI
#define _____________HRM__QWERTY__CSAG_____________ &hm LCTRL A &hm LSHFT S &hs LALT D  &hm LGUI F
#define _____________HRM__QWERTY__GASC_____________ &hs RGUI J  &hs RALT K  &hm LSHFT L &hm RCTRL SEMI
#define _____________HRM__QWERTY__CASG_____________ &hm LCTRL A &hm LALT S  &hs LSHFT D &hm LGUI F
#define _____________HRM__QWERTY__GSAC_____________ &hs RGUI J  &hs RSHFT K &hm LALT L  &hm RCTRL SEMI

#define _____________HRM__COLEMAK__GACS____________ &hm LGUI A  &hm LALT R  &hm LCTRL S &hs LSHFT T
#define _____________HRM__COLEMAK__SCAG____________ &hs RSHFT N &hm RCTRL I &hm LALT I  &hm RGUI O

//
// MODS
//
#define _________________MOD__GACS_________________ &kp LGUI  &kp LALT  &kp LCTRL &kp LSHFT
#define _________________MOD__SCAG_________________ &kp LSHFT &kp LCTRL &kp LALT  &kp LGUI


//
// NAVS
//
#define _______________________NAVS_TOP_______________________ &kp PG_UP &kp PG_UP &kp UP   &kp PG_UP &kp PG_UP
#define _______________________NAVS_MID_______________________ &kp PG_DN &kp LEFT     &kp DOWN &kp RIGHT     &kp PG_UP

//
// NUMS
//
#define _______________________NUMS_TOP_______________________ &kp EQUAL  &kp N7     &kp N8     &kp N9     &kp MINUS
#define _______________________NUMS_MID_______________________ &kp ASTRK  &kp N4     &kp N5     &kp N6     &kp PLUS
#define _______________________NUMS_BOT_______________________ &kp N0     &kp N1     &kp N2     &kp N3     &kp FSLH
