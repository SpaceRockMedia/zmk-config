
#pragma once

//
// Layers
//
#define LY_DEF 0
#define LY_GAM 1
#define LY_NAV 2
#define LY_FUN 3
#define LY_SYM 4
#define LY_DIG 5
#define LY_CNF 6

//
// Custom Keys
//
#define Undo   LC(Z)
#define Cut    LC(X)
#define Copy   LC(C)
#define Paste  LC(V)
#define Redo   LC(Y)

//
// Custom Keys
//
#define ___ &trans
#define XXX &none

// HYPER

// HYP/MEH could work well with sticky keys $sk
// https://zmk.dev/docs/behaviors/sticky-key
// global shortcuts, as it uses GUI
#define HYP LS(LC(LA(LGUI)))
#define HY(keycode) LS(LC(LA(LG(keycode))))

// in app shortcuts
#define MEH LS(LC(LALT))
#define ME(keycode)  LS(LC(LA(keycode)))

//
// KEEB LAYOUTS
//

// FN row
#define _______________LAY_L_FUN_01_05_______________ &kp F1 &kp F2 &kp F3 &kp F4 &kp F5
#define _______________LAY_R_FUN_06_10_______________ &kp F6 &kp F7 &kp F8 &kp F9 &kp F10

// COLEMAK-DH
#define ________________COLEMAK_DH_LT________________ &kp Q &kp W &kp F &kp P &kp B
#define ________________COLEMAK_DH_LM________________ &kp A &kp R &kp S &kp T &kp G
#define ________________COLEMAK_DH_LB________________ &kp Z &kp X &kp C &kp D &kp V

#define ________________COLEMAK_DH_RT________________ &kp J &kp L &kp U     &kp Y   &kp SEMI
#define ________________COLEMAK_DH_RM________________ &kp M &kp N &kp E     &kp I   &kp O
#define ________________COLEMAK_DH_RB________________ &kp K &kp H &kp COMMA &kp DOT &kp FSLH

// QWERTY
#define __________________QWERTY_LT__________________ &kp Q &kp W &kp E &kp R &kp T
#define __________________QWERTY_LM__________________ &kp A &kp S &kp D &kp F &kp G
#define __________________QWERTY_LB__________________ &kp Z &kp X &kp C &kp V &kp B

#define __________________QWERTY_RT__________________ &kp Y &kp U  &kp I     &kp O   &kp P
#define __________________QWERTY_RM__________________ &kp H &kp J  &kp K     &kp L   &kp SEMI
#define __________________QWERTY_RB__________________ &kp N &kp M  &kp COMMA &kp DOT &kp FSLH

// Encoders
#define __ENC_L_ROT__ &inc_dec_kp DOWN UP
#define __ENC_R_ROT__ &inc_dec_kp C_VOL_UP C_VOL_DN
