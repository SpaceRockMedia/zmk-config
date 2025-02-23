#!/usr/bin/env bash

shopt -s extglob nullglob

SHIELD=${1:-ffkb_lite_v1}
BOARD=${2:-nice_nano_v2}
MODULES=${3:-}

# HOST builds
WORKSPACE_DIR=$HOME/projects/spacerockmedia
ZMKDIR=$WORKSPACE_DIR/zmk
CFGDIR=$WORKSPACE_DIR/zmk-config
MODDIR=$WORKSPACE_DIR/zmk-modules
APPDIR=$ZMKDIR/app

BUILDFLAGS=""
BUILDARGS=""

# Define the replacement string: a semicolon followed by the prefix and a trailing slash.
replacement=";${MODDIR}/"

# Replace each comma with the replacement string.
MODULES="${MODULES//,/$replacement}"

# Prepend the prefix to the beginning for the first item.
MODULES="${MODDIR}/${MODULES}"

# modules always to load
MODULES="${CFGDIR};${MODULES}"

echo "modules: ${MODULES}"

if [[ $SHIELD == *"flake"* ]]; then
  BUILDFLAGS="${BUILDFLAGS} -S studio-rpc-usb-uart "
fi

if [[ $SHIELD == *"adept"* ]]; then
  BUILDFLAGS="${BUILDFLAGS} -S studio-rpc-usb-uart "
fi

source ${ZMKDIR}/.venv/bin/activate

# assemble the zmk build command
buildcmd="${ZMKDIR}/.venv/bin/west \
  build \
  -d build/${SHIELD} \
  -b ${BOARD} \
  ${BUILDFLAGS} \
  -- \
    -DSHIELD=${SHIELD} \
    -DZMK_CONFIG=\"${CFGDIR}/config\" \
    -DZMK_EXTRA_MODULES=\"${MODULES}\""

echo "### building with:"
echo "${buildcmd}"

mkdir -p ${CFGDIR}/build

cd ${APPDIR} \
  && eval $buildcmd \
  && echo "### moving uf2 builds to" \
  && echo "${CFGDIR}/build/" \
  && echo "" \
  && cp -f \
    ${APPDIR}/build/${SHIELD}/zephyr/zmk.uf2 \
    ${CFGDIR}/build/${SHIELD}_${BOARD}.uf2
  # && west flash -dbuild/${SHIELD} --skip-rebuild
