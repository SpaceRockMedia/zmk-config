#!/usr/bin/env bash

# Docker builds
CFGDIR="$(realpath $PWD)"
echo "zmk-config path: $CFGDIR"
ZMKDIR="${CFGDIR}/zmk"
APPDIR="${ZMKDIR}/app"
MODDIR="${CFGDIR}/modules/"

get_mods(){
  MODS=$1

  # modules always to load
  MODULES=(
    zmk-helpers
    zmk-auto-layer
    zmk-leader-key
    "${@}"
  )

  PMODULES=("$CFGDIR" "${MODULES[@]/#/${MODDIR}}")
  MODSTR=$(IFS=';' ; echo "${PMODULES[*]}")

  echo "${MODSTR}"
}

get_cmd(){
  SHIELD=${1}
  BOARD=${2}
  MODSTR="$(get_mods ${@:3})"

  echo "$ZMKDIR/.venv/bin/west \
    build -p \
    -d build/${SHIELD} \
    -b ${BOARD} \
    -- \
      ${BUILD_SNIPPETS} \
      -DSHIELD=${SHIELD} \
      -DZMK_CONFIG=\"${CFGDIR}/config\" \
      -DZMK_EXTRA_MODULES=\"${MODSTR}\""
}

has_variants(){
  SHIELD_VARIANTS=${1:-()}
  if declare -p SHIELD_VARIANTS 2>/dev/null | grep -q '^declare -a' && [ ${#SHIELD_VARIANTS[@]} -gt 0 ]; then
    exit 0
  else
    exit 1
  fi

}

_build(){
  local SHIELD=${1:-ffkb_v3}
  local BOARD=${2:-nice_nano_v2}
  local MODS="${@:3}"

  buildcmd="$(get_cmd ${@})"
  echo "### generated build cmd:"
  echo "${buildcmd}"
  echo ""

  cd "${APPDIR}" \
    && eval "$buildcmd" \
    && echo "### moving uf2 builds to" \
    && echo "${CFGDIR}/build/${SHIELD}_${BOARD}.uf2" \
    && echo "" \
    && cp -f \
      "${APPDIR}/build/${SHIELD}/zephyr/zmk.uf2" \
      "${CFGDIR}/build/${SHIELD}_${BOARD}.uf2"

}

build_keeb(){
  echo "BUILD_KEEB: ${@}"

  local SHIELD=${1:-ffkb_v3}
  echo "SHIELD: $SHIELD"
  local BOARD=${2:-nice_nano_v2}
  echo "BOARD: $BOARD"
  local MODS="${@:3}"
  echo "MODS: ${MODS[@]}"

  mkdir -p ${CFGDIR}/build

  # --- The Test ---
  # shellcheck disable=SC2068
  # shellcheck disable=SC2091
  if $(has_variants ${SHIELD_VARIANTS[@]:-()}); then
    for variant in "${SHIELD_VARIANTS[@]}"
    do
      echo "shield variant: _${variant}"
      _build "${SHIELD}_${variant}" "$BOARD" "$MODS"
    done
  else
    echo "no variants"
    _build "${@}"
  fi

}
