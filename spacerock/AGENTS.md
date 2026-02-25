# Spacerock Folder Guide

This folder is the shared behavior/layout library for this repo’s keymaps.

## What lives here
- `aliases.h`, `layouts.h`, `extra_keys.h`: shared layer/key macros and aliases
- `behaviors/`: reusable behavior definitions (`hold_tap`, `leader`, `macros`, etc.)
- `features/`: higher-level features (home-row mods, num-word, smart mouse, swapper, etc.)
- `hardware/`: hardware-oriented snippets (encoders, wireless, mouse tuning, RGB)
- `combos.dtsi`: shared combo definitions

## Why this folder exists
- It prevents per-keyboard duplication by centralizing common behavior logic.
- Most `config/*.keymap` files include this folder (directly or via `base.keymap`).

## Editing rules
- Prefer editing here for cross-keyboard behavior changes.
- Keep macros/layer aliases stable; changes can affect many keymaps at once.
- When modifying shared behavior timing/hold-tap logic, verify at least one split and one non-split target.
