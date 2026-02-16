#!/usr/bin/env bash

shopt -s extglob nullglob

SHIELD=${1:-anywhy_flake}

# shellcheck source=boards/shields/build.env
source "config/${SHIELD}_build.env"

# shellcheck source=scripts/_build.sh
source scripts/_build.sh

build_keeb $SHIELD $BUILD_BOARD "${BUILD_MODULES[@]}"
