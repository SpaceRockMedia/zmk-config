#!/usr/bin/env bash

# HOST builds
# ZMKDIR=${1:-$HOME/projects/spacerockmedia/zmk}
# CFGDIR=${2:-$ZMKDIR/../zmk-config}
# MODDIR=${3:-$ZMKDIR/../zmk-modules}

# Docker builds
ZMKDIR=/workspaces/zmk
CFGDIR=/workspaces/zmk-config
MODDIR=/workspaces/zmk-modules

SHIELD=${4:-ffkb_lite_v1}
BOARD=${5:-nice_nano_v2}

APPDIR=$ZMKDIR/app

MODULES="'\
${MODDIR}/zmk-helpers;\
${MODDIR}/zmk-fingerpunch-controllers;\
${MODDIR}/zmk-fingerpunch-vik;\
${MODDIR}/cirque-input-module;\
${MODDIR}/zmk-tri-state;\
${MODDIR}/zmk-auto-layer;\
'"
# ${MODDIR}/zmk-fingerpunch-keyboards;\

source ${ZMKDIR}/.venv/bin/activate

buildcmd="${ZMKDIR}/.venv/bin/west \
  build -p \
  -d build/${SHIELD} \
  -b ${BOARD} \
  -- \
    -DSHIELD=${SHIELD} \
    -DZMK_CONFIG=\"${CFGDIR}/config\" \
    -DZMK_EXTRA_MODULES=${MODULES}"

echo "### building with:"
echo "${buildcmd}"

mkdir -p ${CFGDIR}/build

cd ${APPDIR} \
  && eval $buildcmd \
  && echo "### moving uf2 builds" \
  && mv \
    ${APPDIR}/build/${SHIELD}/zephyr/zmk.uf2 \
    ${CFGDIR}/build/${SHIELD}.uf2
