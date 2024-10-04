import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("measurementOutput.csv")

# Mapping for data types and sorting algorithms
data_type_names = {
    0: "Reverse Set",
    1: "Sorted Set",
    2: "Random Set",
    3: "Duplicate Set",
}

sort_type_names = {
    0: "Selection Sort",
    1: "Insertion Sort",
    2: "Exchange Sort",
    3: "Bubble Sort",
    4: "Merge Sort",
    5: "Quick Sort",
    6: "Heap Sort",
    7: "Alexa's Heap Sort",
}

# Get unique combinations of data_type and input_size
data_types = df["data_type"].unique()

# Create separate plots for each data_type
for data_type in data_types:
    plt.figure()
    subset = df[df["data_type"] == data_type].sort_values(by='input_size')  # Filter for the current data type

    # Plot each sort_type for the current data type
    for sort_type in subset["sort_type"].unique():
        sort_subset = subset[subset["sort_type"] == sort_type]
        label = f"{sort_type_names[sort_type]}"
        plt.plot(
            sort_subset["input_size"],
            sort_subset["time_microsec"],
            marker="o",
            label=label,
        )

    # Configure the plot
    plt.title(f"Performance of Sorting Algorithms on {data_type_names[data_type]}")
    plt.xlabel("Input Size")
    plt.ylabel("Time (microseconds)")
    plt.grid(True)
    plt.legend()
    plt.show()
