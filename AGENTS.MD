# ZMK Config Agent Guide

This repository is a personal ZMK firmware workspace with:
- User config and keymaps in `config/`
- Custom/out-of-tree shields in `boards/shields/`
- Shared behavior/keymap primitives in `spacerock/`
- Vendored module dependencies in `modules/` (git submodules)
- A vendored ZMK fork in `zmk/` (git submodule)

Use this guide as the operational baseline before editing anything.

## Repo Architecture

### Core ownership by directory
- `config/`: Active ZMK user config (`*.keymap`, `*.conf`, `*_build.env`, `west.yml`).
- `boards/`: Out-of-tree shield definitions/overlays and shield-local defaults.
- `spacerock/`: Shared macros, behaviors, combos, features, and hardware snippets reused across keymaps.
- `scripts/`: Local build orchestration for `west build`.
- `modules/`: External ZMK modules as git submodules.
- `zephyr/module.yml`: Zephyr module metadata declaring this repo as a board root.
- `build.yaml`: GitHub Actions matrix for this user config.
- `.github/workflows/build.yml`: Reuses `zmkfirmware/zmk` user-config build workflow.

### Keymap layering model
- Board-specific keymaps in `config/*.keymap` usually define macro overrides (`X_*`, thumbs, sensor bindings), then include `config/base.keymap`.
- `config/base.keymap` pulls in:
  - `spacerock/aliases.h`, `spacerock/layouts.h`, `spacerock/extra_keys.h`
  - behavior bundles from `spacerock/behaviors/*`
  - feature bundles from `spacerock/features/*`
  - shared combos from `spacerock/combos.dtsi`
- This means many behavior/layout changes should be made in `spacerock/`, not duplicated per keymap.

## Build System

### GitHub Actions / CI
- Workflow: `.github/workflows/build.yml`
- Matrix input: root `build.yaml`
- Build backend: `zmkfirmware/zmk/.github/workflows/build-user-config.yml@main`

When adding or renaming shields/boards, keep `build.yaml` in sync or CI will drift.

### Local builds
- VS Code entry point: `.vscode/tasks.json` (and `zmk/.vscode/tasks.json` for workspace-in-submodule flows).
- Script entry point: `scripts/build.sh <shield>`
- Script flow:
  1. `scripts/build.sh` sources `config/<shield>_build.env`
  2. `scripts/_build.sh` composes `west build` command
  3. `build_keeb` handles split variants via `SHIELD_VARIANTS`
  4. UF2 copied to `build/<shield>_<board>.uf2`

### Build env contract (`config/*_build.env`)
Each env file is expected to define:
- `BUILD_BOARD`
- `BUILD_MODULES` (string/array consumed by scripts)
- `BUILD_SNIPPETS` (for flags like `-S studio-rpc-usb-uart`)
- `SHIELD_VARIANTS` (optional array, usually `left right`)

## Dependency and Module Strategy

### `modules/` (submodules)
- `modules/*` are external dependencies, pinned as git submodules in `.gitmodules`.
- Commonly used modules in build scripts:
  - always included by `_build.sh`: `zmk-helpers`, `zmk-auto-layer`, `zmk-leader-key`
  - conditionally added by per-shield env files: e.g. `flake-zmk-module`, `zmk-pmw3610-driver`
  - fingerpunch flows: `zmk-fingerpunch-controllers`, `zmk-fingerpunch-vik`, `zmk-fingerpunch-keyboards`

Prefer updating module revisions at submodule level instead of copying code into this repo.

### `zmk/` submodule (all zmk-specific info stays here)
- `zmk/` is a git submodule pointing to `git@github.com:SpaceRockMedia/zmk.git`.
- It is pinned to a specific commit in this repo; treat it as vendored source.
- Useful locations:
  - docs content: `zmk/docs/docs`, `zmk/docs/blog`
  - docs dev server: run `npm run start` inside `zmk/docs`
  - VS Code task variants: `zmk/.vscode/tasks.json`
- Local zephyr ecosystem reference (outside this repo): `~/zephyrproject` and `~/zephyrproject/docs`.

When bumping `zmk/`, validate compatibility with:
- `modules/zmk-helpers`
- `modules/zmk-leader-key`
- pointer modules (for example `zmk-pmw3610-driver`)
- any custom behavior assumptions in `spacerock/`

## Code Review Context (Repo-Specific)

Use this checklist for review quality:
- Build wiring
  - Confirm shields in tasks/matrix are backed by valid env/config files.
  - Confirm `BUILD_SNIPPETS` and extra modules are still required.
- Keymap architecture
  - Check for duplicated behavior logic that belongs in `spacerock/`.
  - Validate layer aliases/macros remain consistent with `spacerock/aliases.h`.
- Module compatibility
  - Confirm module API/config names still match current ZMK and Zephyr expectations.
- Split/pointer boards
  - Verify left/right overlays/conf pairings and pointing-device Kconfig/DTS combinations.
- CI realism
  - Ensure any newly added board/shield is represented in `build.yaml`.

### Known drift to verify before relying on local automation
- `.vscode/tasks.json` references `scripts/build_reset.sh`, but that script is currently missing.
- Several VS Code tasks call `scripts/build.sh` with shield names that do not currently have matching `config/<shield>_build.env`.
- `scripts/build_docker.sh` appears stale (for example `-3000:3000` argument and flow assumptions).
- `main.py` currently executes `main()` unconditionally (`if __name__ == "__main__":` guard is not used).

Treat these as review hotspots; either reconcile them or avoid relying on those paths during validation.

## Working Rules for Agents

- Prefer modifying `spacerock/` for shared behavior changes; keep board files thin.
- Keep `config/` focused on board/profile-specific overrides and build manifests.
- Do not edit vendored code in `modules/` or `zmk/` unless the task explicitly requests submodule updates.
- If changing board/shield identifiers, update all of:
  - `config/*` references
  - `boards/shields/*` naming
  - `.vscode/tasks.json`
  - `build.yaml`
- For docs: keep root assumptions here and keep subdirectory-specific details in each folder’s `AGENTS.md`.
