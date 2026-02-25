# Config Folder Guide

This folder is the active user-config layer consumed by local builds and CI.

## What lives here
- Primary keymaps and board configs (`*.keymap`, `*.conf`, `*.dtsi`, `*.json`, `*.zmk.yml`)
- Build-env descriptors (`*_build.env`) used by local scripts
- West manifest (`west.yml`) for module/dependency declarations

## Why this folder exists
- It is the main source of truth for per-keyboard behavior, layer mappings, and build options.
- Local scripts read this folder directly (`config/<shield>_build.env`).

## Editing rules
- Keep `*_build.env` aligned with script expectations:
  - `BUILD_BOARD`
  - `BUILD_MODULES`
  - `BUILD_SNIPPETS`
  - `SHIELD_VARIANTS` (if split)
- Prefer shared behavior/macro edits in `spacerock`; only keep board-specific overrides in this folder.
- If you add or rename a shield config, also update `build.yaml` and relevant VS Code tasks.
