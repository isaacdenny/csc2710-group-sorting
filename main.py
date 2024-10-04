import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

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

# Create a color palette for the sorting algorithms
colors = plt.cm.viridis(np.linspace(0, 1, len(sort_type_names)))

# Create a single figure for all data types

# Store handles for legend
handles = []

# Iterate through each data_type
for data_type in data_types:
    fig, axs = plt.subplots(
        3, figsize=(12, 18)
    )  # Increased figure size for better spacing
    subset = df[df["data_type"] == data_type].sort_values(
        by="input_size"
    )  # Filter for the current data type

    # Plot each sort_type for the current data type
    for sort_type in subset["sort_type"].unique():
        sort_subset = subset[subset["sort_type"] == sort_type]
        label = f"{sort_type_names[sort_type]}"
        color = colors[sort_type]  # Use the consistent color from the palette

        axs[0].plot(
            sort_subset["input_size"],
            sort_subset["time_microsec"],
            marker="o",
            label=label,
            color=color,
        )
        axs[1].plot(
            sort_subset["input_size"],
            sort_subset["compares"],
            marker="o",
            label=label,
            color=color,
        )
        axs[2].plot(
            sort_subset["input_size"],
            sort_subset["swaps"],
            marker="o",
            label=label,
            color=color,
        )

        # Collect handles for the legend
        if sort_type not in [h.get_label() for h in handles]:
            handles.append(axs[0].lines[-1])

    # Configure the plots for each data type
    axs[0].set_title(f"Time (us) - {data_type_names[data_type]}")
    axs[1].set_title(f"Compares - {data_type_names[data_type]}")
    axs[2].set_title(f"Swaps - {data_type_names[data_type]}")

    # Set labels for all axes
    for ax in axs.flat:
        ax.set(xlabel="Input Size")
        ax.grid(True)

    # Set y-labels for each subplot
    axs[0].set(ylabel="Time (us)")
    axs[1].set(ylabel="Compares")
    axs[2].set(ylabel="Swaps")

    # Add a single legend outside the plots
    fig.legend(
        handles[: len(sort_type_names)],
        [h.get_label() for h in handles],
        loc="upper right",
        bbox_to_anchor=(1.02, 1),
        fontsize="medium",
    )

    fig.suptitle(f"Performance on {data_type_names[data_type]}")
    # Adjust layout to prevent overlap
    plt.subplots_adjust(
        top=0.9, bottom=0.1, left=0.1, right=0.85, hspace=0.35, wspace=0.2
    )
    plt.show()
