import subprocess
import re
import pathlib
import csv
import matplotlib.pyplot as plt
from collections import defaultdict

EXEC = "./teste_ordenacao"
TESTES_DIR = pathlib.Path("testes")

METODOS = {"-s": "Seleção", "-i": "Inserção", "-m": "Merge"}

padrao_tempo = re.compile(r"(\d+)\s+Tempo de ordenação:\s+(\d+)")

dados = defaultdict(lambda: defaultdict(list))

arquivos_teste = sorted(TESTES_DIR.glob("caso*/exemplo-*.txt"))

total = len(arquivos_teste) * len(METODOS)
contador = 0

print(f"Total de execuções: {total}\n")

for flag, metodo in METODOS.items():
    print(f"=== Método: {metodo} ===")

    for arquivo in arquivos_teste:
        contador += 1
        caso = arquivo.parent.name

        print(
            f"[{contador}/{total}] {caso} | {arquivo.name} | {metodo} ... ",
            end="",
            flush=True,
        )

        proc = subprocess.run(
            [EXEC, flag],
            stdin=open(arquivo),
            stdout=subprocess.DEVNULL,
            stderr=subprocess.PIPE,
            text=True,
        )

        match = padrao_tempo.search(proc.stderr)
        if not match:
            print("ERRO")
            continue

        n = int(match.group(1))
        tempo = int(match.group(2))
        dados[caso][metodo].append((n, tempo))

        print(f"OK → n={n}, {tempo} µs")

    print()

# CSV

with open("graficos/teste_por_caso.csv", "w", newline="") as f:
    writer = csv.writer(f)
    writer.writerow(["caso", "metodo", "n", "tempo_us"])
    for caso, metodos in dados.items():
        for metodo, valores in metodos.items():
            for n, tempo in valores:
                writer.writerow([caso, metodo, n, tempo])

print("CSV salvo em: benchmark_por_caso.csv")

# Graficos

for caso, metodos in dados.items():
    plt.figure()

    for metodo, valores in metodos.items():
        valores.sort()
        x = [n for n, _ in valores]
        y = [t for _, t in valores]
        plt.plot(x, y, marker="o", label=metodo)

    plt.xlabel("Tamanho do vetor (n)")
    plt.ylabel("Tempo (microsegundos)")
    plt.title(f"Comparação de Algoritmos – {caso}")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()

    nome_arquivo = f"graficos/{caso}.png"
    plt.savefig(nome_arquivo, dpi=150)
    plt.close()

    print(f"Gráfico gerado: {nome_arquivo}")
