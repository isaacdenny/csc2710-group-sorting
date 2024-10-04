# csc2710-group-sorting
The group sorting project for CSC2710

## 1. Delegation - Get sorts done for next lab

- Bubble*
- Merge*
- Selection 
- Insertion*
- Exchange
- Heap*
- Quick

---

- (Josh)[https://github.com/joshsw2005] - Insertion
- (Kevin)[https://github.com/kdogmixtape] - Merge
- (Graham)[https://github.com/gmccabe21212] - Bubble
- (Isaac)[https://github.com/isaacdenny] - Heap
- (Jimi)[https://github.com/baners123] - Compile all other sorts into project

## 2. Design Project Structure & Flow

1. Read Data to memory
2. Measure each sort/dataset pair
3. Record measurements to csv file
4. Display with Python and R

### What is the most important part of the code to focus on in Presentation?

- [x] Structure of main function bringing the algorithms together
- [x] Measurement results and meaning

## 3. Dataset Building

### What dataset? (need 4)

- [x] Almost sorted
- [x] Reverse sorted
- [x] Randomly distributed
- [x] Many Duplicates

We wanted to find a dataset library that has already been set up for us so we could focus on  sample amount, measurement implementation, and presentation. We found and downloaded a [Benchmark Dataset for Sorting Algorithms](https://www.kaggle.com/datasets/bekiremirhanakay/benchmark-dataset-for-sorting-algorithms?select=ordered) from Kaggle that was free and legal to use under the license provided at the link.

### Data Size

We sifted through the data and picked a few sample sizes that fit our needs:

1. Sorted - 1000, 10000, 20000
2. Reverse sorted - 1000, 10000, 20000
3. Random - 1000, 10000, 50000, 100000
4. Duplicates - 1000, 10000, 50000, 100000

The textbook's Quicksort implementation uses the first element of each recursed subarray as the pivot, which hinders the algorithm's performance on Sorted and Reverse Sorted data. When running on a sorted set of only 50000 elements, we encountered a stack overflow and needed to drop the element size to 20000.

### Reading The Dataset To Memory

We needed to make sure our program handled the dataset in memory correctly:

- [x] The dataset files use floating point values on each line, so we read them to memory as doubles and then truncated them by casting to ints
- [x] The application measures one sort/dataset pair at a time so we can deallocate the memory used and be ready for the next measurement
- [x] In the larger datasets, our swap and compare counters began to overflow, so we transitioned to using unsigned 64-bit integers in each measurement

## 4. Results

![Sorted Dataset Results](https://github.com/isaacdenny/csc2710-group-sorting/blob/main/results/SORTED-ALL.png?raw=true)
![Sorted Dataset Table](https://github.com/isaacdenny/csc2710-group-sorting/blob/main/results/SORTED-TABLE.png?raw=true)

---

![Reverse Sorted Dataset Results](https://github.com/isaacdenny/csc2710-group-sorting/blob/main/results/REVERSE-ALL.png?raw=true)
![Reverse Sorted Dataset Table](https://github.com/isaacdenny/csc2710-group-sorting/blob/main/results/REVERSE-TABLE.png?raw=true)

--- 

![Random Dataset Results](https://github.com/isaacdenny/csc2710-group-sorting/blob/main/results/RANDOM-ALL.png?raw=true)
![Random Dataset Table](https://github.com/isaacdenny/csc2710-group-sorting/blob/main/results/RANDOM-TABLE.png?raw=true)

---

![Duplicates Dataset Results](https://github.com/isaacdenny/csc2710-group-sorting/blob/main/results/DUPLICATE-ALL.png?raw=true)
![Duplicates Dataset Table](https://github.com/isaacdenny/csc2710-group-sorting/blob/main/results/DUPLICATES-TABLE.png?raw=true)

## 5. Questions To Answer In Presentation

1. A description of your teams’ approach to the assignment. Your presentation should present your
results and summarize what your team learned about the various sorting.
2. A presentation and walkthrough of the code that was written by the team.
3. A final analysis of the success of the team’s approach and results. If the team’s program failed why did
it do so. In computer science, it is quite normal for an attempted solution to fail to fully achieved the
targeted goals. Some of the most successful software ever created has been built on the foundation of a
few previous failed attempts where teams tried a solution and failed, but they gained valuable knowledge
into why a certain approach will not work

## 5. Running The Project Locally

### C++ Code
1. Ensure g++ is installed and configured
2. In the project root directory, compile the src folder `g++ ./src/*.cpp`
3. Run the output file
4. See console for progress and results, check written data output `measurementOutput` for all measurement data

### Python Graphs Using Matplotlib
1. Ensure python and pip are installed and configured
2. Navigate to project root directory
3. Create a python virtual environment: `python -m venv ./venv`
4. Install dependencies: `pip install -r ./requirements.txt`
5. After running the C++ application and aquiring measurementOutput.csv, run the python app: `python main.py`
