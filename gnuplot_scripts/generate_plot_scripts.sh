#!/bin/bash

for i in {1..16}; do
  cat >"analyzer-angle-light-intensity-$i.gnuplot" <<EOF
set datafile separator ',';
set term eps;
set output "../output/analyzer-angle-light-intensity-$i.gnuplot.eps";
set xlabel "Analyzer Angle (Degree)";
set ylabel "Light Intensity (Ampere)";
plot '../data/analyzer_angle_light_intensity_$i.csv' using 2:3 with line notitle;
EOF
done
