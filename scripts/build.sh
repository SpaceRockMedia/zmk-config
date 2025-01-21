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
"
# ${MODDIR}/zmk-tri-state;\

BUILDFLAGS=""

if [[ $SHIELD == *"flake"* ]]; then
  MODULES="${MODULES}${MODDIR}/flake-zmk-module;"
  BUILDFLAGS="${BUILDFLAGS} -S studio-rpc-usb-uart "
fi

if [[ $SHIELD == *"adept"* ]]; then
  MODULES="${MODULES}${MODDIR}/zmk-keyboards-adept;"
fi

MODULES="${MODULES}'"

source ${ZMKDIR}/.venv/bin/activate

buildcmd="${ZMKDIR}/.venv/bin/west \
  build \
  -d build/${SHIELD} \
  -b ${BOARD} \
  ${BUILDFLAGS} \
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
  && cp -f \
    ${APPDIR}/build/${SHIELD}/zephyr/zmk.uf2 \
    ${CFGDIR}/build/${SHIELD}.uf2
