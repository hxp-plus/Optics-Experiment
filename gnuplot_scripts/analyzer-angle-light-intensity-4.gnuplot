set datafile separator ',';
set term eps;
set output "../output/analyzer-angle-light-intensity-4.gnuplot.eps";
set xlabel "Analyzer Angle (Degree)";
set ylabel "Light Intensity (Ampere)";
set grid;
plot '../data/analyzer_angle_light_intensity_4.csv' using 2:3 with linespoints notitle;