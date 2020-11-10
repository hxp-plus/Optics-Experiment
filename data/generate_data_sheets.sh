#!/bin/bash

for i in {1..2}; do
  if [[ ! -e "analyzer_angle_light_intensity_$i.csv" ]]; then
    cp "analyzer_angle_light_intensity_template.csv" "analyzer_angle_light_intensity_$i.csv"
  fi
done

for i in {1..1}; do
  if [[ ! -e "current_mfield_$i.csv" ]]; then
    cp "current_mfield_template.csv" "current_mfield_$i.csv"
  fi
done

for i in {1..6}; do
  if [[ ! -e "led_$i.csv" ]]; then
    cp "led_template.csv" "led_$i.csv"
  fi
done
