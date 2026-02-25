# Zephyr Folder Guide

This folder contains Zephyr module metadata for this config repository.

## What lives here
- `module.yml`: module definition used by build tooling to discover board roots and module settings.

## Why this folder exists
- It allows this repository to be consumed as a Zephyr module during builds.
- It is the bridge between repo layout and Zephyr’s module-discovery mechanism.

## Editing rules
- Keep `module.yml` minimal and deterministic.
- Only update build settings here when repo-level board/module discovery needs to change.
- Validate any change by running at least one local build and one CI matrix entry.
