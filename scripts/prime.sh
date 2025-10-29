#!/bin/bash

# Verifica se os 3 argumentos foram fornecidos
if [ "$#" -ne 4 ]; then
    echo "Uso: $0 <arquivo_cpp> <arquivo_testes> <executavel_destino> <arquivo_resultado>"
    exit 1
fi

SOURCE="$1"         # Arquivo C++ de entrada
TEST_FILE="$2"      # Arquivo de testes
EXEC="$3"           # Caminho/nome do executável a ser gerado
RESULT_FILE="$4"    # Arquivo de resultados

# Verifica se o arquivo C++ existe
if [ ! -f "$SOURCE" ]; then
    echo "❌ Arquivo C++ '$SOURCE' não encontrado!"
    exit 1
fi

# Verifica se o arquivo de testes existe
if [ ! -f "$TEST_FILE" ]; then
    echo "❌ Arquivo de testes '$TEST_FILE' não encontrado!"
    exit 1
fi

# Compilar
echo "Compilando $SOURCE..."
g++ -std=c++17 -O2 "$SOURCE" -o "$EXEC"
if [ $? -ne 0 ]; then
    echo "❌ Erro na compilação!"
    exit 1
fi
echo "✅ Compilação concluída!"

# Limpar arquivo de resultados
> "$RESULT_FILE"

# Executar testes
echo "🧪 Executando testes..."
while IFS= read -r TEST_INPUT; do
    TIME_MICRO=$(
        echo "$TEST_INPUT" | ./"$EXEC"
    )
    echo "$TIME_MICRO" >> "$RESULT_FILE"
done < "$TEST_FILE"

echo "🏁 Todos os testes concluídos! Resultados em '$RESULT_FILE'."
