#include <iostream>
#include <cstdio>
#include <cmath>
#include <fstream>

constexpr double bsortA = 0.00000000142749;
constexpr double bsortB = -0.0000183622;
constexpr double bsortC = 0.121269;

constexpr double ssortA = 0.000000000388254;
constexpr double ssortB = -0.0000029734;
constexpr double ssortC = 0.0419276;

constexpr double isortA = 0.0000000000917404;
constexpr double isortB = -0.000000386196;
constexpr double isortC = 0.00605793;

double bubbleSortDetrmining(const double& x)
{
    return bsortA*pow(x, 2) + bsortB * x + bsortC;
}

double selectionSortDetrmining(const double& x)
{
    return ssortA*pow(x, 2) + ssortB * x + ssortC;
}

double insertionSortDetrmining(const double& x)
{
    return isortA*pow(x, 2) + isortB * x + isortC;
}

int main() {
    FILE *gnuplotPipe;
    const char *plotCmd = "plot 'BubbleSortData' with points, 'SelectionSortData' with point, 'InsertionSortData' with points, 'DeterminedBubbleSort' with lines, 'DeterminedSelectionSort' with lines, 'DeterminedInsertionSort' with lines"; // Gnuplot command to plot data

    // Open a pipe to Gnuplot
    gnuplotPipe = popen("gnuplot -persist", "w");

    if (!gnuplotPipe) {
        std::cout << "Gnuplot not found!" << std::endl;
        return -1;
    }

    // Creating Determined Quadratic formulas for sorting algorithms
    std::ofstream output("DeterminedBubbleSort");
    if (!output.is_open())
	{
		std::cout << "Could not open DeterminedBubbleSort" << std::endl;
		exit(EXIT_FAILURE);
	}

    for (double x = 0; x <= 250000; x += 1500)
        output << x << "\t" << bubbleSortDetrmining(x) << std::endl;
    output.close();

    output.open("DeterminedSelectionSort");
    if (!output.is_open())
	{
		std::cout << "Could not open DeterminedSelectionSort" << std::endl;
		exit(EXIT_FAILURE);
	}

    for (double x = 0; x <= 250000; x += 1500)
        output << x << "\t" << selectionSortDetrmining(x) << std::endl;
    output.close();

    output.open("DeterminedInsertionSort");
    if (!output.is_open())
	{
		std::cout << "Could not open DeterminedInsertionSort" << std::endl;
		exit(EXIT_FAILURE);
	}

    for (double x = 0; x <= 250000; x += 1500)
        output << x << "\t" << insertionSortDetrmining(x) << std::endl;
    output.close();

    fprintf(gnuplotPipe, "set xlabel 'Number Of elements'\n");
    fprintf(gnuplotPipe, "set ylabel 'Time (s)'\n");

    fprintf(gnuplotPipe, "set yrange [0:115]\n"); // Set Y-axis range
    fprintf(gnuplotPipe, "set xrange [0:280000]\n"); // Set X-axis range

    // Send plot command to Gnuplot
    fprintf(gnuplotPipe, "%s\n", plotCmd);
    fflush(gnuplotPipe);

    // Close the pipe
    pclose(gnuplotPipe);

    return 0;
}