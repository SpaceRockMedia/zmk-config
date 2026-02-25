# Keymap Drawer Folder Guide

This folder stores keymap-drawer inputs and rendered artifacts for visual keymap documentation.

## What lives here
- `config.yaml`: styling and rendering configuration
- `*.yaml`: parsed/curated keymap representation
- `*.svg`: generated visual output

## Why this folder exists
- It provides human-readable keymap documentation separate from firmware source.
- It supports quick visual diff/review of layout behavior.

## Editing rules
- Keep rendered SVGs synchronized with their YAML sources after layout changes.
- Treat this folder as documentation output/input, not firmware execution logic.
- Do not move core firmware logic here; update key behavior in `config` or `spacerock`.
