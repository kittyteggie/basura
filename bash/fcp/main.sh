#!/bin/bash

if ! command -v xclip >/dev/null 2>&1; then
  echo "xclip no esta instalado, desearia instalarlo?"
  echo "[1] Si  [2] No"
  read -p "Escoja una opcion: " opcion
  if [ $opcion = 1 ]; then
    sudo apt install xclip -y
  else
    exit 1
  fi
fi

if [ $# -ne 1 ]; then
  echo "Uso: $0 <archivo>"
  exit 1
fi

archivo="$1"
xclip -sel clip <$1
echo "$1 copiado al portapapeles correctamente"
