#!/bin/bash

for i in {1..4}; do
  cat >"analyzer-angle-light-intensity-$i.gnuplot" <<EOF
set datafile separator ',';
set term eps;
set output "../output/analyzer-angle-light-intensity-$i.gnuplot.eps";
set xlabel "Analyzer Angle (Degree)";
set ylabel "Light Intensity (10^{-7} Ampere)";
set grid;
plot '../data/analyzer_angle_light_intensity_$i.csv' using 2:3 with linespoints notitle;
set terminal png size 640,480;
set output "../output/analyzer-angle-light-intensity-$i.gnuplot.png";
set xlabel "Analyzer Angle (Degree)";
set ylabel "Light Intensity (10^{-7} Ampere)";
set grid;
plot '../data/analyzer_angle_light_intensity_$i.csv' using 2:3 with linespoints notitle;
EOF
done

for i in {1..8}; do
  cat >"led-$i.gnuplot" <<EOF
set datafile separator ',';
set term eps;
set output "../output/led-vc-$i.gnuplot.eps";
set ylabel "Current (Milli Ampere)";
set xlabel "Voltage (Volt)";
set grid;
plot '../data/led_$i.csv' using 3:2 with linespoints notitle;
set output "../output/led-pc-$i.gnuplot.eps";
set ylabel "Current (Milli Ampere)";
set xlabel "Power (Watt)";
set grid;
plot '../data/led_$i.csv' using 4:2 with linespoints notitle;
set terminal png size 640,480;
set output "../output/led-vc-$i.gnuplot.png";
set ylabel "Current (Milli Ampere)";
set xlabel "Voltage (Volt)";
set grid;
plot '../data/led_$i.csv' using 3:2 with linespoints notitle;
set output "../output/led-pc-$i.gnuplot.png";
set ylabel "Current (Milli Ampere)";
set xlabel "Power (Watt)";
set grid;
plot '../data/led_$i.csv' using 4:2 with linespoints notitle;

EOF
done

cat >"current-mfield.gnuplot" <<EOF
set datafile separator ',';
set term eps;
set output "../output/current-mfield.gnuplot.eps";
set xlabel "Current (Ampere)";
set ylabel "Magnetic induction (Milli Tesla)";
set grid;
plot '../data/current_mfield.csv' using 1:2 with linespoints notitle;
set terminal png size 640,480;
set output "../output/current-mfield.gnuplot.png";
set xlabel "Current (Ampere)";
set ylabel "Magnetic induction (Milli Tesla)";
set grid;
plot '../data/current_mfield.csv' using 1:2 with linespoints notitle;
EOF

cat >"light-intensity-analyzer-angle.gnuplot" <<EOF
set datafile separator ',';
set term eps;
set output "../output/light-intensity-analyzer-angle.gnuplot.eps";
set ylabel "Analyzer Angle (Degree)";
set xlabel "Current (Ampere)";
set grid;
plot '../data/light_intensity_analyzer_angle.csv' using 1:3 with linespoints notitle;
set terminal png size 640,480;
set output "../output/light-intensity-analyzer-angle.gnuplot.png";
set ylabel "Analyzer Angle (Degree)";
set xlabel "Current (Ampere)";
set grid;
plot '../data/light_intensity_analyzer_angle.csv' using 1:3 with linespoints notitle;
EOF
