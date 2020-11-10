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

void fill_table_analyzer_angle_light_intensity(char *data_filename, char *tex_filename) {
    char *cmd = malloc(sizeof(char) * 256);
    double current = read_lines(data_filename, 2, 2, 2)[0];
    const double *light_intensity = read_lines(data_filename, 2, 37, 3);
    sprintf(cmd, "sed -i s/p00/%.2f/ %s", current, tex_filename);
    system(cmd);
    for (int i = 0; i < 36; i++) {
        sprintf(cmd, "sed -i s/p%d/%.2f/ %s", i + 11, light_intensity[i], tex_filename);
        system(cmd);
    }
}

void insert_plot(char* plot_script_path, char* plot_script_name, char* tex_filename) {
    char *cmd = malloc(sizeof(char) * 256);
    sprintf(cmd, "gnuplot -p %s/%s",
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