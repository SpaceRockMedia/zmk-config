
#pragma once

// clipboard
#define UUNDO LC(Z)
#define UREDO LC(kpLS(Y))
#define UCUT  LC(X)
#define UCOPY LC(C)
#define UPSTE LC(V)
// MAC
#define MUNDO LG(Z)
#define MCUT  LG(X)
#define MCOPY LG(C)
#define MPSTE LG(V)
#define MREDO LG(LS(Y))

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

// Hold taps
