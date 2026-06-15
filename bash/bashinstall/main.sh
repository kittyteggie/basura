#!/bin/bash

if [ $# -ne 2 ]; then
  echo "Uso: $0 <archivo> <nombre>"
  exit 1
fi

archivo="$1"
nombre="$2"
cp $1 $2
chmod +x $2
mv $2 ~/.local/bin
