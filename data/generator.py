import random
import os
# from ortools.linear_solver import pywraplp

def instance_generator(filename, count):
    filepath = os.path.join("./data", filename)
    with open(filepath, 'w') as file:
        capacity = random.randint(1000, 2000)
        file.write(f"{count} {capacity}\n")
        L = [random.randint(1, capacity) for _ in range(count)]
        for i in range(count):
            file.write(f"{L[i]} ")
    # data = {}
    # data["weights"] = L
    # data["items"] = list(range(count))
    # data["bins"] = data["items"]
    # data["bin_capacity"] = capacity
    # solver = pywraplp.Solver.CreateSolver("SCIP")
    # x = {}
    # for i in data["items"]:
    #     for j in data["bins"]:
    #         x[(i, j)] = solver.IntVar(0, 1, "x_%i_%i" % (i, j))
    # y = {}
    # for j in data["bins"]:
    #     y[j] = solver.IntVar(0, 1, "y[%i]" % j)
    # for i in data["items"]:
    #     solver.Add(sum(x[i, j] for j in data["bins"]) == 1)
    # for j in data["bins"]:
    #     solver.Add(
    #         sum(x[(i, j)] * data["weights"][i] for i in data["items"])
    #         <= y[j] * data["bin_capacity"]
    #     )
    # solver.Minimize(solver.Sum(y[j] for j in data["bins"]))
    # status = solver.Solve()
    # if status == pywraplp.Solver.OPTIMAL:
    #     cnt = 0
    #     for j in data["bins"]:
    #         if y[j].solution_value() == 1:
    #             cnt += 1
    #     with open(filepath.replace(".in", ".opt"), 'w') as file:
    #         file.write(f"{cnt}")
    

if __name__ == "__main__":
    l = [200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000]
    for i in l:
        for j in range(10):
            instance_generator(f"instance_{i}_{j}.in", i)
    