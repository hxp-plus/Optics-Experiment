set datafile separator ',';
set term eps;
set output "../output/led-vc-6.gnuplot.eps";
set xlabel "Current (Ampere)";
set ylabel "Voltage (Volt)";
plot '../data/led_6.csv' using 2:3 with line notitle;
set output "../output/led-pc-6.gnuplot.eps";
set xlabel "Current (Ampere)";
set ylabel "Power (Watt)";
plot '../data/led_6.csv' using 2:4 with line notitle;
