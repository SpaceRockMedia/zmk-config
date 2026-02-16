#!/usr/bin/env bash

SHIELD=${1:-ffkb_v3}

# shellcheck source=boards/shields/build.env
source "config/${SHIELD}_build.env"

FP_MODULES=(
  zmk-fingerpunch-controllers
  zmk-fingerpunch-vik
  zmk-fingerpunch-keyboards
)

MODULES=( "${FP_MODULES[@]}" "${BUILD_MODULES[@]}" )

# shellcheck source=scripts/_build.sh
source scripts/_build.sh

build_keeb $SHIELD $BUILD_BOARD "${MODULES[@]}"
