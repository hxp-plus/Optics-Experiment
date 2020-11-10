#!/bin/bash

for i in {1..2}; do
  cat >"analyzer-angle-light-intensity-$i.gnuplot" <<EOF
set datafile separator ',';
set term eps;
set output "../output/analyzer-angle-light-intensity-$i.gnuplot.eps";
set xlabel "Analyzer Angle (Degree)";
set ylabel "Light Intensity (Ampere)";
plot '../data/analyzer_angle_light_intensity_$i.csv' using 2:3 with line notitle;
EOF
done

for i in {1..6}; do
  cat >"led-$i.gnuplot" <<EOF
set datafile separator ',';
set term eps;
set output "../output/led-vc-$i.gnuplot.eps";
set xlabel "Current (Ampere)";
set ylabel "Voltage (Volt)";
plot '../data/led_$i.csv' using 2:3 with line notitle;
set output "../output/led-pc-$i.gnuplot.eps";
set xlabel "Current (Ampere)";
set ylabel "Power (Watt)";
plot '../data/led_$i.csv' using 2:4 with line notitle;
EOF
done
