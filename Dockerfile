FROM docker.io/zmkfirmware/zmk-dev-arm:3.5 AS zmkdev

EXPOSE 3000

USER ubuntu

COPY --chown=ubuntu:ubuntu --chmod=644 scripts/.bashrc /tmp
RUN mv /tmp/.bashrc ~/.bashrc

FROM zmkdev AS zmkbuild

WORKDIR /workspaces/zmk/app

COPY zmk/ /workspaces/zmk/

# RUN west init -l app || true
RUN git config --global safe.directory '*'
RUN west update

FROM zmkbuild AS zmk

CMD [ "bash" ]
