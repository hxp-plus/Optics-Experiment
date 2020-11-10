set datafile separator ',';
set term eps;
set output "../output/light-intensity-analyzer-angle.gnuplot.eps";
set xlabel "Analyzer Angle (Degree)";
set ylabel "Light Intensity (Ampere)";
set grid;
plot '../data/light_intensity_analyzer_angle.csv' using 1:2 with linespoints notitle;
