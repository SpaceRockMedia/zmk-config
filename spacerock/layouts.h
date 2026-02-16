
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
#define _________________________HRM__QWERTY__GACS_________________________ &hml LGUI A  &hml LALT S  &hml LCTRL D &hml LSHFT F
#define _________________________HRM__QWERTY__SCAG_________________________ &hmr RSHFT J &hmr RCTRL K &hmr LALT L  &hmr RGUI SEMI
#define _________________________HRM__QWERTY__GSAC_________________________ &hml LGUI A  &hml LSHFT S &hml LALT D  &hml LCTRL F
#define _________________________HRM__QWERTY__CASG_________________________ &hmr RCTRL J &hmr LALT K  &hmr LSHFT L &hmr RGUI SEMI
#define _________________________HRM__QWERTY__CSAG_________________________ &hml LCTRL A &hml LSHFT S &hml LALT D  &hml LGUI F
#define _________________________HRM__QWERTY__GASC_________________________ &hmr RGUI J  &hmr RALT K  &hmr LSHFT L &hmr RCTRL SEMI
// #define _________________________HRM__QWERTY__CASG_________________________ &hml LCTRL A &hml LALT S  &hml LSHFT D &hml LGUI F
// #define _________________________HRM__QWERTY__GSAC_________________________ &hmr RGUI J  &hmr RSHFT K &hmr LALT L  &hmr RCTRL SEMI

#define _____________HRM__COLEMAK__GACS____________ &hml LGUI A  &hml LALT R  &hml LCTRL S &hml LSHFT T
#define _____________HRM__COLEMAK__SCAG____________ &hmr RSHFT N &hmr RCTRL I &hmr LALT I  &hmr RGUI O

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
