#!/usr/bin/env bash

ZMKDIR=/workspaces/zmk
APPDIR=$ZMKDIR/app

CFGDIR=/workspaces/zmk-config
BUILDDIR=${CFGDIR}/build
MODDIR=${CFGDIR}/modules
MODULES="\
  ${MODDIR}/zmk-num-word;\
  ${MODDIR}/zmk-tri-state\
"

BOARD=nice_nano_v2
SHIELD=ffkb_lite_v1
UF2=${APPDIR}/build/${SHIELD}/zephyr/zmk.uf2

cd ${APPDIR} \
  && west build -p \
    -d build/${SHIELD} \
    -b ${BOARD} \
    -- \
      -DSHIELD=${SHIELD} \
      -DZMK_CONFIG="${CFGDIR}/config" \
      -DZMK_EXTRA_MODULES=${MODULES} \
  && mv ${UF2} ${BUILDDIR}/${SHIELD}.uf2
