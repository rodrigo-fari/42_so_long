#!/bin/bash

NAME="so_long"

# Verifica se o programa foi compilado
if [ ! -f "./$NAME" ]; then
    echo "O programa $NAME não foi encontrado. Certifique-se de que ele foi compilado."
    exit 1
fi

# Caminho para a pasta de mapas inválidos
MAP_DIR="maps/invalid_map/"

# Itera sobre todos os arquivos na pasta de mapas inválidos
for MAP_FILE in "$MAP_DIR"*; do
    if [ -f "$MAP_FILE" ]; then
        echo "Executando Valgrind no arquivo $MAP_FILE"
        valgrind --leak-check=full --show-leak-kinds=all "./$NAME" "$MAP_FILE"

	else
        echo "Nenhum arquivo encontrado na pasta $MAP_DIR"
    fi
done