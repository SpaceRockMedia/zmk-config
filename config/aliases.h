#pragma once

#define DEF 0
#define ALT 1
#define NAV 2
#define FUN 3
#define NUM 4
#define SYS 5
#define PNT 6
#define WIN 7

#define LY_BASE DEF ALT

//
// Custom Keys
//
#define ___ &trans
#define XXX &none

// clipboard
#define UUNDO LC(Z)
#define UREDO LC(LS(Y))
#define UCUT  LC(X)
#define UCOPY LC(C)
#define UPSTE LC(V)
// MAC
#define MUNDO LG(Z)
#define MCUT  LG(X)
#define MCOPY LG(C)
#define MPSTE LG(V)
#define MREDO LG(LS(Y))

// HYPER

// HYP/MEH could work well with sticky keys $sk
// https://zmk.dev/docs/behaviors/sticky-key
// global shortcuts, as it uses GUI
#define HYP LS(LC(LA(LGUI)))
#define HY(keycode) LS(LC(LA(LG(keycode))))

// in app shortcuts
#define MEH LS(LC(LALT))
#define ME(keycode)  LS(LC(LA(keycode)))

// Media
#define H_LIKE &kp HY(PG_UP)
#define H_SKIP &kp HY(PG_DN)
#define VOL_UP &kp C_VOL_UP
#define VOL_DN &kp C_VOL_DOWN

// misc aliases
#define CANCEL      &kp K_CANCEL             // cancel caps-word, num-word and smart-mouse
#define DSK_PREV    &hmr LCTRL LG(LC(LEFT))  // previous desktop
#define DSK_NEXT    &hmr LALT LG(LC(RIGHT))  // next     desktop
#define PIN_WIN     &kp LG(LC(LS(Q)))        // pin window across desktops
#define PIN_APP     &kp LG(LC(LS(A)))        // pin application across desktops
#define DSK_MGR     &kp LA(GRAVE)            // desktop manager
#define VOL_DOWN    &hmr RSHFT C_VOL_DN

#if !defined KEYS_L
    #define KEYS_L LT0 LT1 LT2 LT3 LT4 LT5 LM0 LM1 LM2 LM3 LM4 LM5 LB0 LB1 LB2 LB3 LB4 LB5  // left hand
#endif
#if !defined KEYS_R  // top row, middle
    #define KEYS_R RT0 RT1 RT2 RT3 RT4 RT5 RM0 RM1 RM2 RM3 RM4 RM5 RB0 RB1 RB2 RB3 RB4 RB5  // right hand
#endif
// only use 3 inner thumb keys for combos
#if !defined THUMBS  // top row, middle
    #ifndef LH2
        #define THUMBS LH1 LH0 RH0 RH1         // Thumbs on 34 keys.
    #else
        #define THUMBS LH2 LH1 LH0 RH0 RH1 RH2 // Thumbs on 36+ keys.
    #endif                                                 // thumbs
#endif
