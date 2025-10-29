#!/bin/bash

# Script para compilar e testar questões
# Uso: ./run.sh lista-02/04

if [ $# -ne 1 ]; then
    echo "Uso: $0 lista-XX/YY"
    exit 1
fi

INPUT=$1
LISTA=$(echo $INPUT | cut -d'/' -f1)   # Ex: lista-02
QUESTAO=$(echo $INPUT | cut -d'/' -f2) # Ex: 04

SRC_FILE="$LISTA/$QUESTAO.cpp"
BIN_DIR="bin/$LISTA/$QUESTAO"
TEST_DIR="test/$LISTA/$QUESTAO/"

# Cria pasta binária se não existir
mkdir -p "$BIN_DIR"

# Compila
g++ -std=c++17 -Wall "$SRC_FILE" -o "$BIN_DIR/bin"
if [ $? -ne 0 ]; then
    echo "Erro na compilação!"
    exit 1
fi

echo "Compilação concluída: $BIN_DIR//bin"

# Executa testes
if [ -d "$TEST_DIR" ]; then
    for TEST_FILE in "$TEST_DIR"/*; do
        if [ -f "$TEST_FILE" ]; then
            echo "Rodando teste: $TEST_FILE"
            "$BIN_DIR/bin" < "$TEST_FILE"
            echo "-----------------------------"
        fi
    done
else
    echo "Nenhum teste encontrado em $TEST_DIR"
fi
