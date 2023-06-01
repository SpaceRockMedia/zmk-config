# ZMK Config Optimized for Sofle Keyboards

This is a zmk config that uses a [zmk fork that is optimized for the sofle keyboard](https://github.com/infused-kim/zmk/tree/sofle). It improves encoder, display and underglow support of zmk.

While it's been optimized for and tested with a sofle choc keyboard, it can be benificial for and should work with any split keyboard that is using encoders and displays.

## It adds the following features and fixes:

* Adds underglow (used for backlight) support to Sofle shield ([PR #1188](https://github.com/zmkfirmware/zmk/pull/1188))
* Fixes split side encoder not working ([PR #728](https://github.com/zmkfirmware/zmk/pull/728))
* Fixes display not working if you toggle external power off and then on again ([Issue #674](https://github.com/zmkfirmware/zmk/issues/674))
* Adds automatic disabling and enabling of external power when USB is disconnected or connected ([PR #1184](https://github.com/zmkfirmware/zmk/pull/1184))
* Adds automatic disabling of backlight if the keyboard is idle ([PR #1179](https://github.com/zmkfirmware/zmk/pull/1179))

Most of these fixes and features have not made it into the official zmk yet, because they don't meet the (very resaonable and completely understandable) code standards of the zmk maintainers.

However, while these fixes and features may not meet the quality standards of the official project, they work well enough to be used until these features get properly implemented in the official zmk.

## How to use

1. Fork this repo
2. Clone the repo to your computer
3. Edit the config and keymap files
4. Push your changes to github
5. Download the firmware from the actions tab

Alternatively, you could probably even use github's built-in editor to edit the keymap and config file after forking.

# NOTES

- MEH to open apps
- Make the num row F keys always, hold for number, and use vertical combos for symbols?
- MEHM as a hold version?
- CAPSWORD on double tap space?
- double tap layer to make it sticky
- &to ? or sticky layers?
- other layers should keep ESC to always reactivate $mo DEF
- If sticky layers are active, make it possible to still sticky other layers in case the
wrong layer was stickied
- Hold num keys for F keys, or keep them as shift for symbol? Maybe hold top row?
- vertical combos for nmber symbols
- top row numbers should always allow for AS() shifting for symbol access. and TAB
- programming layer for things like == != <= >= => -> <- |>
- Should nav keys (HJKL) be on both sides with a layer key in case i need to do nav with
that hand, and to allow for nav with mouse?
- more use of combos to allow for better use of layers
- Look into COLEMAK-dh digraph combos? Th, tion, ese, Sh, Ch, etc
- maybe also something like a combo for TH -> the, WH -> where.
- or maybe they should be developer based. IF -> `if :\n` and placing cursor before :
    - this might be better as a vscode keymap?
    - maybe a devmode toggle to enable things like this?
- Combos on number layer for equation/time/currency symbols reduce layer switches.
- any key rolled into "-" sends a macro (sort if like inverse of cli switches.)
- leader keys? would this be a rolling maneuver and conflict with things?
- key combos for killing apps!
- Semantic keys. avoid os specific shortcuts like ctrl+c/cmd+c and use combos or keys
tied to some mod key like alt, meh, hyp, etc.
- Define custom keycodes (like how QMK does it), but in ZMK I think I need a `#define` ?
- https://www.reddit.com/r/ErgoMechKeyboards/comments/zfomr0/comment/iziinp0/?context=3
-
- can features/mods/combos/etc be enabled or disabled based on app focused?
maybe we just have a toggle for them as a single layer so only one can be focused at a time?
- macro to enable CAPS_WORD and replace SHFT with "_"
- layer to output common strings like emails
- Hold BSPC for layer rather than LC(BSPC) or DEL actions?
- Maybe tap+hold does word backspace, or double tap
- home, end, pg up/down on bottom row so top row still works with combos?
- alt+tab key. Hold tab? or tap+hold?
- tap dance/tap hold rather than &kp ) for number layer?
- Game mode where only needing left half for gaming with mouse. WASD/WARS for nav.
