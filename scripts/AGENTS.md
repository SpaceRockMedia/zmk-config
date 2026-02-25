# Scripts Folder Guide

This folder contains local build orchestration scripts for ZMK firmware builds.

## What lives here
- `build.sh`: primary local entry point
- `_build.sh`: shared command-generation/build functions
- `build_fingerpunch.sh`: fingerpunch-specific module wrapper
- `build_docker.sh`: docker-based build path (currently appears partially stale)
- `.bashrc`: shell customization for container/dev environments

## Why this folder exists
- It standardizes local build invocations and artifact output paths.
- It centralizes module and snippet wiring used by local workflows.

## Editing rules
- Preserve the `config/<shield>_build.env` contract expected by `build.sh`.
- Keep `_build.sh` as the single source for west command composition when possible.
- Validate script changes against at least one real shield target and artifact copy path.
- If changing script interfaces, update `.vscode/tasks.json` in the same change.
