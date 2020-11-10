//
// Created by hxp on 2020-11-09.
//

#include "main.h"
#include "generate_table.h"
#include "readcsv.h"

void create_table_analyzer_angle_light_intensity(char *filename) {
    char *cmd = malloc(sizeof(char) * 256);
    sprintf(cmd, "cat %s >> %s",
            "../tex-templates/analyzer_angle_light_intensity.tex",
            filename);
    system(cmd);
}

void create_table_light_intensity_analyzer_angle(char *filename) {
    char *cmd = malloc(sizeof(char) * 256);
    sprintf(cmd, "cat %s >> %s",
            "../tex-templates/light_intensity_analyzer_angle.tex",
            filename);
    system(cmd);
}

void create_table_current_mfield(char *filename) {
    char *cmd = malloc(sizeof(char) * 256);
    sprintf(cmd, "cat %s >> %s",
            "../tex-templates/current_mfield.tex",
            filename);
    system(cmd);
}

void fill_table_analyzer_angle_light_intensity(char *data_filename, char *tex_filename) {
    char *cmd = malloc(sizeof(char) * 256);
    double current = read_lines(data_filename, 2, 2, 1)[0];
    const double *light_intensity = read_lines(data_filename, 2, 37, 3);
    sprintf(cmd, "sed -i s/p00/%.2f/ %s", current, tex_filename);
    system(cmd);
    for (int i = 0; i < 36; i++) {
        sprintf(cmd, "sed -i s/p%d/%.2f/ %s", i + 11, light_intensity[i], tex_filename);
        system(cmd);
    }
}

void fill_table_light_intensity_analyzer_angle(char *data_filename, char *tex_filename) {
    char *cmd = malloc(sizeof(char) * 256);
    const double *angle = read_lines(data_filename, 2, 16, 1);
    const double *light_intensity = read_lines(data_filename, 2, 16, 2);
    for (int i = 0; i < 15; i++) {
        sprintf(cmd, "sed -i s/p1%d/%.2f/ %s", i + 11, angle[i], tex_filename);
        system(cmd);
    }
    for (int i = 0; i < 15; i++) {
        sprintf(cmd, "sed -i s/p2%d/%.2f/ %s", i + 11, light_intensity[i], tex_filename);
        system(cmd);
    }
    for (int i = 0; i < 8; i++) {
        sprintf(cmd, "sed -i s/p3%d/%.2f/ %s", i + 11, (light_intensity[i] + light_intensity[14 - i]) / 2.0,
                tex_filename);
        system(cmd);
    }
}


void fill_table_current_mfield(char *data_filename, char *tex_filename) {
    char *cmd = malloc(sizeof(char) * 256);
    const double *current = read_lines(data_filename, 2, 16, 1);
    const double *light_intensity = read_lines(data_filename, 2, 16, 2);
    system(cmd);
    for (int i = 0; i < 15; i++) {
        sprintf(cmd, "sed -i s/p1%d/%.2f/ %s", i + 11, current[i], tex_filename);
        system(cmd);
        sprintf(cmd, "sed -i s/p2%d/%.2f/ %s", i + 11, light_intensity[i], tex_filename);
        system(cmd);
    }
}

void create_table_led(char *filename) {
    char *cmd = malloc(sizeof(char) * 256);
    sprintf(cmd, "cat %s >> %s",
            "../tex-templates/led.tex",
            filename);
    system(cmd);
}

void fill_table_led(char *data_filename, char *tex_filename) {
    char *cmd = malloc(sizeof(char) * 256);
    double temperature = read_lines(data_filename, 2, 2, 1)[0];
    const double *current = read_lines(data_filename, 2, 9, 2);
    const double *voltage = read_lines(data_filename, 2, 9, 3);
    const double *power = read_lines(data_filename, 2, 9, 4);
    char *color = read_lines_str(data_filename, 2, 5);
    sprintf(cmd, "sed -i s/p001/%s/ %s", color, tex_filename);
    system(cmd);
    sprintf(cmd, "sed -i s/p000/%.2f/ %s", temperature, tex_filename);
    system(cmd);
    for (int i = 0; i < 8; i++) {
        sprintf(cmd, "sed -i s/p1%d/%.2f/ %s", i + 11, current[i], tex_filename);
        system(cmd);
    }
    for (int i = 0; i < 8; i++) {
        sprintf(cmd, "sed -i s/p2%d/%.2f/ %s", i + 11, voltage[i], tex_filename);
        system(cmd);
    }
    for (int i = 0; i < 8; i++) {
        sprintf(cmd, "sed -i s/p3%d/%.2f/ %s", i + 11, power[i], tex_filename);
        system(cmd);
    }
}

void insert_plot(char *plot_script_path, char *plot_script_name, char *tex_filename, char *figure_name) {
    char *cmd = malloc(sizeof(char) * 256);
    sprintf(cmd, "gnuplot -p %s%s",
            plot_script_path,
            plot_script_name);
    system(cmd);
    sprintf(cmd, "cat %s >> %s",
            "../tex-templates/figure.tex",
            tex_filename);
    system(cmd);
    sprintf(cmd, "sed -i s/path.pdf/%s/ %s",
            figure_name,
            tex_filename);
    system(cmd);
}