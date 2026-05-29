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

if [ "$navegadorOpcion" = "01" ]; then
  navegador="chrome"
elif [ "$navegadorOpcion" = "02" ]; then
  navegador="chromium"
elif [ "$navegadorOpcion" = "03" ]; then
  navegador="firefox"
elif [ "$navegadorOpcion" = "04" ]; then
  navegador="edge"
elif [ "$navegadorOpcion" = "05" ]; then
  navegador="opera"
elif [ "$navegadorOpcion" = "06" ]; then
  navegador="brave"
elif [ "$navegadorOpcion" = "07" ]; then
  navegador="vivaldi"
fi

echo ""

# Menús de selección de formatos según la opción principal
if [ "$opcion" = "01" ] || [ "$opcion" = "05" ]; then
  echo -e "\e[34mEscoje un formato de video\e[0m"
  echo "[01] MP4        [04] FLV"
  echo "[02] WEBM       [05] 3GP"
  echo "[03] MKV"
  read -p "Coloque su opcion: " formatoVideoOpcion
elif [ "$opcion" = "02" ]; then
  echo -e "\e[34mEscoje un formato de audio\e[0m"
  echo "[01] M4A        [04] OPUS"
  echo "[02] WEBM       [05] AAC"
  echo "[03] MP3"
  read -p "Coloque su opcion: " formatoAudioOpcion
elif [ "$opcion" = "03" ]; then
  echo -e "\e[34mEscoje un formato de miniatura\e[0m"
  echo "[01] JPG        [03] PNG"
  echo "[02] WEBP"
  read -p "Coloque su opcion: " formatoMiniaturaOpcion
elif [ "$opcion" = "06" ]; then
  echo -e "\e[34mEscoje un formato de video\e[0m"
  echo "[01] MP4        [04] FLV"
  echo "[02] WEBM       [05] 3GP"
  echo "[03] MKV"
  read -p "Coloque su opcion: " formatoVideoOpcion
  echo ""
  echo -e "\e[34mEscoje un formato de audio\e[0m"
  echo "[01] M4A        [04] OPUS"
  echo "[02] WEBM       [05] AAC"
  echo "[03] MP3"
  read -p "Coloque su opcion: " formatoAudioOpcion
  echo ""
  echo -e "\e[34mEscoje un formato de miniatura\e[0m"
  echo "[01] JPG        [03] PNG"
  echo "[02] WEBP"
  read -p "Coloque su opcion: " formatoMiniaturaOpcion
fi

# Asignación de variables de formato (con comillas para evitar errores si están vacías)
if [ "$formatoVideoOpcion" = "01" ]; then
  formatoVideo="mp4"
elif [ "$formatoVideoOpcion" = "02" ]; then
  formatoVideo="webm"
elif [ "$formatoVideoOpcion" = "03" ]; then
  formatoVideo="mkv"
elif [ "$formatoVideoOpcion" = "04" ]; then
  formatoVideo="flv"
elif [ "$formatoVideoOpcion" = "05" ]; then
  formatoVideo="3gp"
fi

if [ "$formatoAudioOpcion" = "01" ]; then
  formatoAudio="m4a"
elif [ "$formatoAudioOpcion" = "02" ]; then
  formatoAudio="webm"
elif [ "$formatoAudioOpcion" = "03" ]; then
  formatoAudio="mp3"
elif [ "$formatoAudioOpcion" = "04" ]; then
  formatoAudio="opus"
elif [ "$formatoAudioOpcion" = "05" ]; then
  formatoAudio="aac"
fi

if [ "$formatoMiniaturaOpcion" = "01" ]; then
  formatoMiniatura="jpg"
elif [ "$formatoMiniaturaOpcion" = "02" ]; then
  formatoMiniatura="webp"
elif [ "$formatoMiniaturaOpcion" = "03" ]; then
  formatoMiniatura="png"
fi

# Ejecución de yt-dlp
if [ "$opcion" = "01" ]; then
  yt-dlp -f "bv*+ba/b" --ignore-config "$link" --cookies-from-browser "$navegador" --merge-output-format "$formatoVideo"
elif [ "$opcion" = "02" ]; then
  yt-dlp -f "ba" --ignore-config "$link" --audio-format "$formatoAudio" --cookies-from-browser "$navegador"
elif [ "$opcion" = "03" ]; then
  yt-dlp --ignore-config --write-thumbnail --skip-download "$link" --cookies-from-browser "$navegador" --convert-thumbnails "$formatoMiniatura"
elif [ "$opcion" = "04" ]; then
  yt-dlp --ignore-config --write-info-json --skip-download "$link" --cookies-from-browser "$navegador"
elif [ "$opcion" = "05" ]; then
  yt-dlp -f "bv*+ba/b" --ignore-config --merge-output-format "$formatoVideo" "$link" --cookies-from-browser "$navegador"
elif [ "$opcion" = "06" ]; then
  yt-dlp -f "bv*+ba/b" --ignore-config --merge-output-format "$formatoVideo" --write-thumbnail "$link" --convert-thumbnails "$formatoMiniatura" --cookies-from-browser "$navegador" && yt-dlp -f "bestaudio" -x --audio-format "$formatoAudio" "$link" --cookies-from-browser "$navegador"
fi
