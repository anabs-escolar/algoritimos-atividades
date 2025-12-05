import os
import subprocess
import csv
import matplotlib.pyplot as plt

TEST_DIR = "tests/lista-08"
TEST_FILES = [f"teste-{i:02d}.txt" for i in range(1, 11)]
MODES = ["100", "1000", "10000", "dup"]


def main():
    resultados = {}

    with open("resultados.csv", "w", newline="") as csvfile:
        writer = csv.writer(csvfile)

        # Cabeçalho
        header = ["Modo"] + [f"teste-{i:02d}" for i in range(1, 11)]
        writer.writerow(header)

        # Executar para cada modo
        for mode in MODES:
            row = [mode]
            resultados[mode] = []
            print(f"=== Executando modo: {mode} ===")

            for test in TEST_FILES:
                test_path = os.path.join(TEST_DIR, test)
                print(f" Rodando {test_path}...")

                proc = subprocess.run(
                    ["./app", mode],
                    stdin=open(test_path, "r"),
                    stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE,
                    text=True,
                )

                tempo = None
                for line in proc.stderr.splitlines():
                    if "ExecTime:" in line:
                        tempo = line.split(":")[1]
                        break

                if tempo is None:
                    tempo = "0"

                tempo_float = float(tempo)
                resultados[mode].append(tempo_float)
                row.append(tempo)

            writer.writerow(row)

    plt.figure(figsize=(10, 6))

    for mode in MODES:
        plt.plot(TEST_FILES, resultados[mode], marker="o", label=mode)

    plt.xlabel("Arquivos de teste")
    plt.ylabel("Tempo (ms)")
    plt.title("Tempo de execução por modo")
    plt.legend()
    plt.xticks(rotation=45)
    plt.tight_layout()

    plt.savefig("grafico.png")


if __name__ == "__main__":
    main()
