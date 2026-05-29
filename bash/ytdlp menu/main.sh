#!/bin/bash

read -p "Coloca el link: " link
echo ""
echo -e "\e[34mElije una opcion\e[0m"
echo "[01] Descargar video            [04] Descargar metadatos"
echo "[02] Descargar audio            [05] Descargar todo (audio unido al video)"
echo "[03] Descargar la miniatura     [06] Descargar todo (audio separado)"
echo ""
read -p "Escoje una opcion: " opcion
echo ""
echo -e "\e[34mQue navegador utilizas? (Para tomar las cookies y evitar CAPTCHAs)\e[0m"
echo ""
echo "[01] Google Chrome              [05] Opera"
echo "[02] Chromium                   [06] Brave"
echo "[03] Firefox                    [07] Vivaldi"
echo "[04] Edge"
echo ""
read -p "Escoje tu navegador: " navegadorOpcion

if [ $navegadorOpcion = 01 ]; then
  navegador="chrome"
elif [ $navegadorOpcion = 02 ]; then
  navegador="chromium"
elif [ $navegadorOpcion = 03 ]; then
  navegador="firefox"
elif [ $navegadorOpcion = 04 ]; then
  navegador="edge"
elif [ $navegadorOpcion = 05 ]; then
  navegador="opera"
elif [ $navegadorOpcion = 06 ]; then
  navegador="brave"
elif [ $navegadorOpcion = 07 ]; then
  navegador="vivaldi"
fi

if [ $opcion = 01 ]; then
  yt-dlp -f "bv*+ba/b" --ignore-config "$link" --cookies-from-browser $navegador
elif [ $opcion = 02 ]; then
  yt-dlp -f "ba" -x --ignore-config --audio-format best "$link" --cookies-from-browser $navegador
elif [ $opcion = 03 ]; then
  yt-dlp --ignore-config --write-thumbnail --skip-download "$link" --cookies-from-browser $navegador
elif [ $opcion = 04 ]; then
  yt-dlp --ignore-config --write-info-json --skip-download "$link" --cookies-from-browser $navegador
elif [ $opcion = 05 ]; then
  yt-dlp -f "bv*+ba/b" --ignore-config --merge-output-format mp4 "$link" --write-thumbnail --write-info-json --cookies-from-browser $navegador
elif [ $opcion = 06 ]; then
  yt-dlp -f "bv,ba" --ignore-config --merge-output-format mp4 --write-thumbnail --write-info-json "$link" --cookies-from-browser $navegador
fi
