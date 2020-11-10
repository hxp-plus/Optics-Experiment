set datafile separator ',';
set term eps;
set output "../output/current-mfield.gnuplot.eps";
set xlabel "Analyzer Angle (Degree)";
set ylabel "Light Intensity (Ampere)";
set grid;
plot '../data/current_mfield.csv' using 1:2 with linespoints notitle;
