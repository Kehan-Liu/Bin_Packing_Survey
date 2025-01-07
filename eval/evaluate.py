import subprocess

def run_algorithms(input_data):
    process = subprocess.Popen(
        ["./eval/algos"],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )
    stdout, stderr = process.communicate(input_data.encode())
    if stderr:
        raise Exception(stderr.decode())
    return stdout.decode()

if __name__ == "__main__":
    for i in [200, 500, 1000, 2000, 5000, 10000, 20000, 30000, 40000, 50000]:
        tot_res = [0] * 6
        tot_time = [0] * 6
        for j in range(10):
            with open(f"./data/instance_{i}_{j}.in") as file:
                input_data = file.read()
            output = run_algorithms(input_data)
            res = list(int(x) for x in output.split())
            for k in range(6):
                tot_res[k] += res[2 * k] / res[0]
                tot_time[k] += res[2 * k + 1]
        with open(f"./eval/results", "a") as file:
            file.write(f"{i}\n")
            for k in range(6):
                file.write(f"{tot_res[k] / 10.0} {tot_time[k] / 10.0}\n")
