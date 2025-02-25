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
