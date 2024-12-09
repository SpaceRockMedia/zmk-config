#!/usr/bin/env bash

# HOST builds
WORKSPACE_DIR=$HOME/projects/spacerockmedia
ZMKDIR=$WORKSPACE_DIR/zmk
CFGDIR=$WORKSPACE_DIR/zmk-config
MODDIR=$WORKSPACE_DIR/zmk-modules

SHIELD=${1:-ffkb_lite_v1}
BOARD=${2:-nice_nano_v2}

APPDIR=$ZMKDIR/app

MODULES="'\
${MODDIR}/cirque-input-module;\
${MODDIR}/zmk-auto-layer;\
${MODDIR}/zmk-fingerpunch-controllers;\
${MODDIR}/zmk-fingerpunch-keyboards;\
${MODDIR}/zmk-fingerpunch-vik;\
${MODDIR}/zmk-helpers;\
'"
# ${MODDIR}/zmk-tri-state;\

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
