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

- Josh - Insertion
- Kevin - Merge
- Graham - Bubble
- Isaac - Heap
- Jimi - Compile all other sorts into project

## 2. Design Project Structure & Flow - TODO - Next time we meet

### How can this be used?

### How will we present?

- Show code?
- Show results?

### What is the most important part of the code to focus on?

Measurement accuracy and amount - structure of main function bringing the algorithms together

## 3. Dataset Building - TODO - Next time we meet

- What datasets? (need 4)

- [x] Almost sorted
- [x] Randomly distributed
- [x] Reverse sorted
- [x] Many Duplicates

We wanted to find a dataset library that has already been set up for us so we could focus on  sample amount, measurement implementation, and presentation. We found and downloaded a [Benchmark Dataset for Sorting Algorithms](https://www.kaggle.com/datasets/bekiremirhanakay/benchmark-dataset-for-sorting-algorithms?select=ordered) from Kaggle that was free and legal to use under the license provided at the link.

We sifted through the data and picked a few sample sizes that fit our needs:

- TODO Describe sample size choices here
- talk about how the data was in floating point format and how we got around that

## 4. Questions To Answer In Presentation

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
