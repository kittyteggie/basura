#!/bin/bash

if [ $# -ne 1 ]; then
  echo "Uso: $0 <archivo>"
  exit 1
fi

archivo="$1"

if [ ! -f "$archivo" ]; then
  echo "Error: '$archivo' no existe o no es un archivo regular."
  exit 1
fi

backup="${archivo}.bak"
contador=2

while [ -e "$backup" ]; do
  backup="${archivo}.bak${contador}"
  ((contador++))
done

cp -- "$archivo" "$backup"

echo "Backup creado: $backup"
