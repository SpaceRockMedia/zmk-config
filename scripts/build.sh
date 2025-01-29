#!/usr/bin/env bash

shopt -s extglob nullglob

# HOST builds
WORKSPACE_DIR=$HOME/projects/spacerockmedia
ZMKDIR=$WORKSPACE_DIR/zmk
CFGDIR=$WORKSPACE_DIR/zmk-config
MODDIR=$WORKSPACE_DIR/zmk-modules

SHIELD=${1:-ffkb_lite_v1}
BOARD=${2:-nice_nano_v2}

APPDIR=$ZMKDIR/app

MODULES=""

# You may omit the following subdirectories
# the syntax is that of extended globs, e.g.,
# omitdir="cmmdm|not_this_+([[:digit:]])|keep_away*"
# If you don't want to omit any subdirectories, leave empty: omitdir=
omitdir=zmk-tri-state

# Create array
if [[ -z $omitdir ]]; then
   modarray=( "$MODDIR"/*/ )
else
   modarray=( "$MODDIR"/!($omitdir)/ )
fi
# remove trailing backslash
modarray=( "${modarray[@]%/}" )

# At this point you have a nice array modarray, indexed from 0 (for Exit)
# that contains Exit and all the subdirectories of $MODDIR
# (except the omitted ones)
# You should check that you have at least one directory in there:
if ((${#modarray[@]}<=1)); then
    printf 'No modules found. \n'
else
  # join modules to a string
  MODULES=$(IFS=\; ; echo "${modarray[*]}")
fi

BUILDFLAGS=""

if [[ $SHIELD == *"flake"* ]]; then
  BUILDFLAGS="${BUILDFLAGS} -S studio-rpc-usb-uart "
fi

source ${ZMKDIR}/.venv/bin/activate

buildcmd="${ZMKDIR}/.venv/bin/west \
  build -p \
  -d build/${SHIELD} \
  -b ${BOARD} \
  ${BUILDFLAGS} \
  -- \
    -DSHIELD=${SHIELD} \
    -DZMK_CONFIG=\"${CFGDIR}/config\" \
    -DZMK_EXTRA_MODULES='${MODULES}'"

echo "### building with:"
echo "${buildcmd}"

mkdir -p ${CFGDIR}/build

cd ${APPDIR} \
  && eval $buildcmd \
  && echo "### moving uf2 builds" \
  && cp -f \
    ${APPDIR}/build/${SHIELD}/zephyr/zmk.uf2 \
    ${CFGDIR}/build/${SHIELD}.uf2
  # && west flash -dbuild/${SHIELD} --skip-rebuild
