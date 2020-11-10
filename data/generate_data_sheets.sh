#!/bin/bash

for i in {1..8};do
	if [[ ! -e "analyzer_angle_light_intensity_$i.csv" ]];then
		cp "analyzer_angle_light_intensity_template.csv" "analyzer_angle_light_intensity_$i.csv"
	fi
done

for i in {1..1};do
	if [[ ! -e "current_mfield_$i.csv" ]];then
		cp "current_mfield_template.csv" "current_mfield_$i.csv"
	fi
done
