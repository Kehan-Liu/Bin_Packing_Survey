import matplotlib.pyplot as plt

def plot_results():
    input_sizes = []
    ratios = [[] for _ in range(6)]
    times = [[] for _ in range(6)]
    algorithm_names = [
        "Next Fit",
        "First Fit",
        "Best Fit",
        "Harmonic_6",
        "Harmonic_12",
        "Refined Harmonic"
    ]

    with open("./eval/results", "r") as f:
        lines = f.read().splitlines()

    idx = 0
    while idx < len(lines):
        size = int(lines[idx])
        input_sizes.append(size)
        idx += 1
        for i in range(6):
            ratio_str, time_str = lines[idx].split()
            ratios[i].append(float(ratio_str))
            times[i].append(float(time_str))
            idx += 1

    plt.figure(figsize=(10, 5))
    for i in range(6):
        plt.plot(input_sizes, ratios[i], label=algorithm_names[i])
    plt.title("Relative Performance Ratio vs Input Size")
    plt.xlabel("Input Size")
    plt.ylabel("Relative Performance Ratio")
    plt.legend()
    plt.savefig("./eval/performance_ratio.png")

    plt.figure(figsize=(10, 5))
    for i in range(6):
        plt.plot(input_sizes, times[i], label=algorithm_names[i])
    plt.title("Running Time vs Input Size")
    plt.xlabel("Input Size")
    plt.ylabel("Running Time (microseconds)")
    plt.legend()
    plt.savefig("./eval/running_time.png")

if __name__ == "__main__":
    plot_results()
