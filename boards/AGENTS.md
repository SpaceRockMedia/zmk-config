# Boards Folder Guide

This folder contains out-of-tree keyboard shield definitions and shield-local firmware assets.

## What lives here
- `boards/shields/<shield>/...` files such as:
  - `Kconfig.shield`, `Kconfig.defconfig`
  - `*.overlay`, `*.dtsi`
  - shield-local `*.conf`, `*.keymap`, `*.json`, `*.zmk.yml`
  - optional local `build.env`

## Why this folder exists
- It is the hardware-definition layer for custom or external shields that are not part of upstream defaults.
- It keeps shield topology, matrix, and low-level DTS/Kconfig details close to each shield.

## Editing rules
- Keep shield naming consistent across all files in a shield directory.
- Prefer hardware or shield-default concerns here; keep shared behavior logic in `spacerock`.
- If shield IDs change, sync dependent references in `config`, `build.yaml`, and `.vscode/tasks.json`.
