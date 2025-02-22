// The default layout has 34 keys. Additional keys can be added by pre-setting any of
// the macros defined in this file to one or more keys before sourcing this file.

#pragma once


/* left of left half */
#if !defined X_LN  // top row, left
    #define X_LN
#endif
#if !defined X_LT  // top row, left
    #define X_LT
#endif
#if !defined X_LM  // middle row, left
    #define X_LM
#endif
#if !defined X_LB  // bottom row, left
    #define X_LB
#endif
#if !defined X_LH  // thumb row, left
    #define X_LH
#endif

/* inner left column */
#if !defined X_MLN  // top row, middle left
    #define X_MLN
#endif
#if !defined X_MLT  // top row, middle left
    #define X_MLT
#endif
#if !defined X_MLM  // middle row, middle left
    #define X_MLM
#endif
#if !defined X_MLB  // bottom row, middle left
    #define X_MLB
#endif
#if !defined X_MLH  // thumb row, middle
    #define X_MLH
#endif

/* between left and right half */
#if !defined X_MN  // top row, middle
    #define X_MN
#endif
#if !defined X_MT  // top row, middle
    #define X_MT
#endif
#if !defined X_MM  // middle row, middle
    #define X_MM
#endif
#if !defined X_MB  // bottom row, middle
    #define X_MB
#endif
#if !defined X_MH  // thumb row, middle
    #define X_MH
#endif

/* inner right column */
#if !defined X_MRN  // top row, middle right
    #define X_MRN
#endif
#if !defined X_MRT  // top row, middle right
    #define X_MRT
#endif
#if !defined X_MRM  // middle row, middle right
    #define X_MRM
#endif
#if !defined X_MRB  // bottom row, middle right
    #define X_MRB
#endif
#if !defined X_MRH  // thumb row, middle right
    #define X_MRH
#endif

/* right of right half */
#if !defined X_RN  // top row, right
    #define X_RN
#endif
#if !defined X_RT  // top row, right
    #define X_RT
#endif
#if !defined X_RM  // middle row, right
    #define X_RM
#endif
#if !defined X_RB  // bottom row, right
    #define X_RB
#endif
#if !defined X_RH  // thumb row, right
    #define X_RH
#endif

/* top num rows left */
#if !defined ________________________X_LEFT_ROW_________________________________ // base layer
    #define ________________________X_LEFT_ROW_________________________________
#endif
#if !defined ________________________X_LEFT_NAV_________________________________ // nav layer
    #define ________________________X_LEFT_NAV_________________________________
#endif
#if !defined ________________________X_LEFT_FUN_________________________________ // fun layer
    #define ________________________X_LEFT_FUN_________________________________
#endif
#if !defined ________________________X_LEFT_NUM_________________________________ // num layer
    #define ________________________X_LEFT_NUM_________________________________
#endif
#if !defined ________________________X_LEFT_SYS_________________________________ // sys layer
    #define ________________________X_LEFT_SYS_________________________________
#endif
#if !defined ________________________X_LEFT_PNT_________________________________ // pointer layer
    #define ________________________X_LEFT_PNT_________________________________
#endif
#if !defined ________________________X_LEFT_WIN_________________________________ // window layer
    #define ________________________X_LEFT_WIN_________________________________
#endif

/* top num rows right */
#if !defined ________________________X_RIGHT_ROW________________________________ // base layer
    #define ________________________X_RIGHT_ROW________________________________
#endif
#if !defined ________________________X_RIGHT_NAV________________________________ // nav layer
    #define ________________________X_RIGHT_NAV________________________________
#endif
#if !defined ________________________X_RIGHT_FUN________________________________ // fun layer
    #define ________________________X_RIGHT_FUN________________________________
#endif
#if !defined ________________________X_RIGHT_NUM________________________________ // num layer
    #define ________________________X_RIGHT_NUM________________________________
#endif
#if !defined ________________________X_RIGHT_SYS________________________________ // sys layer
    #define ________________________X_RIGHT_SYS________________________________
#endif
#if !defined ________________________X_RIGHT_PNT________________________________ // pointer layer
    #define ________________________X_RIGHT_PNT________________________________
#endif
#if !defined ________________________X_RIGHT_WIN________________________________ // window layer
    #define ________________________X_RIGHT_WIN________________________________
#endif

/* sensors/encoders */
#if !defined X_SENSORS_BASE // base layer
    #define X_SENSORS_BASE
#endif
#if !defined X_SENSORS_NAV // base layer
    #define X_SENSORS_NAV
#endif
#if !defined X_SENSORS_FUN // base layer
    #define X_SENSORS_FUN
#endif
#if !defined X_SENSORS_NUM // base layer
    #define X_SENSORS_NUM
#endif
#if !defined X_SENSORS_SYS // base layer
    #define X_SENSORS_SYS
#endif
#if !defined X_SENSORS_PNT // base layer
    #define X_SENSORS_PNT
#endif
#if !defined X_SENSORS_WIN // base layer
    #define X_SENSORS_WIN
#endif

#if !defined thumb_base_left
    #define thumb_base_left  &mt MEH BSPC  DSPACE      &kp LSHIFT
#endif
#if !defined thumb_base_right
    #define thumb_base_right &kp RSHIFT    &lt NAV RET &mt MEH DEL
#endif
#if !defined thumb_nav_left
    #define thumb_nav_left   &kp MEH       &to 0       ___
#endif
#if !defined thumb_nav_right
    #define thumb_nav_right  ___           ___         CANCEL
#endif
#if !defined thumb_fun_left
    #define thumb_fun_left   &kp MEH       &to 0       ___
#endif
#if !defined thumb_fun_right
    #define thumb_fun_right  ___           &kp C_MUTE  &kp C_PP
#endif
#if !defined thumb_num_left
    #define thumb_num_left   &kp MEH       &to 0       ___
#endif
#if !defined thumb_num_right
    #define thumb_num_right  ___           ___         ___
#endif
#if !defined thumb_sys_left
    #define thumb_sys_left   &kp MEH       &to 0       ___
#endif
#if !defined thumb_sys_right
    #define thumb_sys_right  ___           ___         ___
#endif
#if !defined thumb_pnt_left
    #define thumb_pnt_left   &kp MEH       &to 0       ___
#endif
#if !defined thumb_pnt_right
    #define thumb_pnt_right  ___           &mkp LCLK   &mkp RCLK
#endif
#if !defined thumb_win_left
    #define thumb_win_left   &kp MEH       &to 0       ___
#endif
#if !defined thumb_win_right
    #define thumb_win_right  ___           ___         ___
#endif
