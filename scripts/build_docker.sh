#!/usr/bin/env bash

# Docker builds
ZMKDIR=/workspaces/zmk
CFGDIR=/workspaces/zmk-config
MODDIR=/workspaces/zmk-modules

BOARD=${1:-ffkb_lite_v1}
SHIELD=${2:-nice_nano_v2}

APPDIR=$ZMKDIR/app

MODULES="'\
${MODDIR}/cirque-input-module;\
${MODDIR}/zmk-auto-layer;\
${MODDIR}/zmk-fingerpunch-controllers;\
${MODDIR}/zmk-fingerpunch-keyboards;\
${MODDIR}/zmk-fingerpunch-vik;\
${MODDIR}/zmk-helpers;\
${MODDIR}/zmk-tri-state;\
'"

buildcmd="west \
  build -p \
  -d build/${SHIELD} \
  -b ${BOARD} \
  -- \
    -DSHIELD=${SHIELD} \
    -DZMK_CONFIG=\"${CFGDIR}/config\" \
    -DZMK_EXTRA_MODULES=${MODULES}"

echo "### building with:"
echo "${buildcmd}"
echo ""

mkdir -p ${CFGDIR}/build


cd ${APPDIR} \
  && eval $buildcmd \
  && echo "### moving uf2 builds" \
  && mv \
    ${APPDIR}/build/${SHIELD}/zephyr/zmk.uf2 \
    ${CFGDIR}/build/${BOARD}.uf2
