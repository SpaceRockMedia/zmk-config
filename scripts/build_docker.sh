#!/usr/bin/env bash

# shellcheck source=scripts/_build.sh
source ./_build.sh $1 $2 ${3:-}

docker compose run --rm \
  --security-opt label=disable \
  -v zmk-modules:/workspaces/zmk-modules \
  -3000:3000 \
  zmkbuild ${buildcmd} \
  && echo "### moving uf2 builds" \
  && mv \
    ${APPDIR}/build/${SHIELD}/zephyr/zmk.uf2 \
    ${CFGDIR}/build/${BOARD}.uf2

build_keeb
