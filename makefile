.PHONY = gen eval clean plot

gen:
	@echo "generating data..."
	@python3 ./data/generator.py

eval: gen
	@echo "compiling..."
	@g++ -std=c++11 -O0 -o ./eval/algos ./src/datastructures.cpp ./src/algorithms.cpp ./src/evaluation.cpp
	@echo "running evaluation..."
	@python3 ./eval/evaluate.py

plot: ./eval/results
	@echo "plotting..."
	@python3 ./eval/plot.py

clean:
	@echo "cleaning..."
	@rm -f ./data/*.in
	@rm -f ./eval/algos
	@rm -f ./eval/results
	@rm -f ./eval/*.png