set datafile separator ',';
set term eps;
set output "../output/led-vc-1.gnuplot.eps";
set ylabel "Current (Milli Ampere)";
set xlabel "Voltage (Volt)";
set grid;
plot '../data/led_1.csv' using 3:2 with linespoints notitle;
set output "../output/led-pc-1.gnuplot.eps";
set ylabel "Current (Milli Ampere)";
set xlabel "Power (Watt)";
set grid;
plot '../data/led_1.csv' using 4:2 with linespoints notitle;
set terminal png size 640,480;
set output "../output/led-vc-1.gnuplot.png";
set ylabel "Current (Milli Ampere)";
set xlabel "Voltage (Volt)";
set grid;
plot '../data/led_1.csv' using 3:2 with linespoints notitle;
set output "../output/led-pc-1.gnuplot.png";
set ylabel "Current (Milli Ampere)";
set xlabel "Power (Watt)";
set grid;
plot '../data/led_1.csv' using 4:2 with linespoints notitle;

