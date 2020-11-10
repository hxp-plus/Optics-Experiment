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


void fill_table_current_mfield(char *data_filename, char *tex_filename) {
    char *cmd = malloc(sizeof(char) * 256);
    double current = read_lines(data_filename, 2, 2, 2)[0];
    const double *light_intensity = read_lines(data_filename, 2, 17, 3);
    sprintf(cmd, "sed -i s/p00/%.2f/ %s", current, tex_filename);
    system(cmd);
    for (int i = 0; i < 36; i++) {
        sprintf(cmd, "sed -i s/p%d/%.2f/ %s", i + 11, light_intensity[i], tex_filename);
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
    const double *current = read_lines(data_filename, 2, 8, 2);
    const double *voltage = read_lines(data_filename, 2, 8, 3);
    const double *power = read_lines(data_filename, 2, 8, 4);
    sprintf(cmd, "sed -i s/p000/%.2f/ %s", temperature, tex_filename);
    system(cmd);
    for (int i = 0; i < 7; i++) {
        sprintf(cmd, "sed -i s/p1%d/%.2f/ %s", i + 11, current[i], tex_filename);
        system(cmd);
    }
    for (int i = 0; i < 7; i++) {
        sprintf(cmd, "sed -i s/p2%d/%.2f/ %s", i + 11, voltage[i], tex_filename);
        system(cmd);
    }
    for (int i = 0; i < 7; i++) {
        sprintf(cmd, "sed -i s/p3%d/%.2f/ %s", i + 11, power[i], tex_filename);
        system(cmd);
    }
}

void insert_plot(char *plot_script_path, char *plot_script_name, char *tex_filename) {
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
            plot_script_name,
            tex_filename);
    system(cmd);
}