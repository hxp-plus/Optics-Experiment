set datafile separator ',';
set term eps;
set output "../output/analyzer-angle-light-intensity-3.gnuplot.eps";
plot '../data/analyzer_angle_light_intensity_3.csv' using 2:3 with line notitle;