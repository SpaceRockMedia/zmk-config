
#pragma once

#define QUICK_TAP_MS 75
#define GLOBAL_QUICK_TAP_MS 75

//
// MOD MORPHs
//
#define SPACEROCK_MOD_SHIFT(NAME, BINDING, SHIFT_BINDING) \
  ZMK_BEHAVIOR(NAME, mod_morph, \
    bindings = <BINDING>, <SHIFT_BINDING>; \
    mods = <(MOD_LSFT|MOD_RSFT)>; \
  )

#define SPACEROCK_MOD_CTRL(NAME, BINDING, CTRL_BINDING) \
  ZMK_BEHAVIOR(NAME, mod_morph, \
    bindings = <BINDING>, <CTRL_BINDING>; \
    mods = <(MOD_LCTL|MOD_RCTL)>; \
  )

#define SPACEROCK_MOD_ALT(NAME, BINDING, ALT_BINDING) \
  ZMK_BEHAVIOR(NAME, mod_morph, \
    bindings = <BINDING>, <ALT_BINDING>; \
    mods = <(MOD_LALT|MOD_RALT)>; \
  )

#define SPACEROCK_MOD_GUI(NAME, BINDING, GUI_BINDING) \
  ZMK_BEHAVIOR(NAME, mod_morph, \
    bindings = <BINDING>, <GUI_BINDING>; \
    mods = <(MOD_LGUI|MOD_RGUI)>; \
  )


//
// MOD TAPs (&mt)
//
#define MT_CORE \
    flavor = "tap-preferred"; \
    tapping-term-ms = <150>; \
    quick-tap-ms = <QUICK_TAP_MS>; \
    retro-tap; \
    hold-trigger-key-positions = <0>;

&mt { MT_CORE };
#define U_BSPC &mt LC(BSPC) BSPC    // tap: bspc  | long-tap: delete word backward
#define U_DEL  &mt LC(DEL)  DEL     // tap: del   | long-tap: delete word forward

//
// Hold Taps
//
#define MAKE_HOLD_TAP(NAME, HOLD, TAP) \
  ZMK_BEHAVIOR(NAME, hold_tap, \
        global-quick-tap-ms = <GLOBAL_QUICK_TAP_MS>; \
        bindings = <HOLD>, <TAP>; \
        hold-trigger-on-release; \
        MT_CORE \
  )

MAKE_HOLD_TAP(hold_tap_ctl_esc, &kp, &kp)
#define HT_CTL_ESC &hold_tap_ctl_esc LCTRL ESC

MAKE_HOLD_TAP(hold_tap_ctl_quote, &kp, &kp)
#define HT_CTL_SQT &hold_tap_ctl_quote RCTRL SQT

MAKE_HOLD_TAP(hold_tap_meh_spc, &kp, &kp)
#define HT_MEH_SPC &hold_tap_meh_spc MEH SPACE

MAKE_HOLD_TAP(hold_tap_meh_ent, &kp, &kp)
#define HT_MEH_ENT &hold_tap_meh_ent MEH ENTER

MAKE_HOLD_TAP(hold_tap_tog_nav, &mo, &to)
#define HT_TOG_NAV &hold_tap_tog_nav NAV NAV

MAKE_HOLD_TAP(hold_tap_tog_num, &mo, &to)
#define HT_TOG_NUM &hold_tap_tog_num NUM NUM

MAKE_HOLD_TAP(hold_tap_ctl_def, &kp, &to)
#define HT_CTL_DEF &hold_tap_ctl_def LCTRL DEF

MAKE_HOLD_TAP(hold_tap_ctl_gam, &kp, &to)
#define HT_CTL_GAM &hold_tap_ctl_gam LCTRL COL

//
// Sticky Keys
//
&sk {
    release-after-ms = <600>;  // release after 0.6s
    quick-release;             // no double capitalization when rolling keys
};

//
// Sticky Layers
//
&sl {
    ignore-modifiers;          // allow chording sticky mods & layers
};

//
// layer taps
//
&lt {
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <QUICK_TAP_MS>;
};

//
// Bluetooth
//
#define BT0 &bt BT_SEL 0
#define BT1 &bt BT_SEL 1
#define BT2 &bt BT_SEL 2
#define BT3 &bt BT_SEL 3
#define BT4 &bt BT_SEL 4
