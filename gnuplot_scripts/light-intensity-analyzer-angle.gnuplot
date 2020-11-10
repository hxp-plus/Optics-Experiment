set datafile separator ',';
set term eps;
set output "../output/light-intensity-analyzer-angle.gnuplot.eps";
set ylabel "Faraday Angle (Degree)";
set xlabel "Current (Ampere)";
set grid;
plot '../data/light_intensity_analyzer_angle.csv' using 1:3 with linespoints notitle;
