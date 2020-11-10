#include "main.h"
#include "generate_document.h"
#include "generate_table.h"

const char *WORKDIR = "../output/";
const char *TEX_FILE_NAME = "optics-experiment.tex";
const char *PDF_FILE_NAME = "optics-experiment.pdf";
const char *PLOT_SCRIPT_PATH = "../gnuplot_scripts/";

void current_mfield(char *tex_filename) {
    create_table_current_mfield(tex_filename);
    fill_table_current_mfield("../data/current_mfield.csv", tex_filename);
    insert_plot(PLOT_SCRIPT_PATH, "current-mfield.gnuplot",
                tex_filename, "current-mfield.gnuplot");
}

void analyzer_angle_light_intensity(char *tex_filename, int num) {
    create_table_analyzer_angle_light_intensity(tex_filename);
    char *data_filename = malloc(sizeof(char) * 128);
    char *plot_script_name = malloc(sizeof(char) * 128);
    sprintf(data_filename, "../data/analyzer_angle_light_intensity_%d.csv", num);
    sprintf(plot_script_name, "analyzer-angle-light-intensity-%d.gnuplot", num);
    fill_table_analyzer_angle_light_intensity(data_filename, tex_filename);
    insert_plot(PLOT_SCRIPT_PATH, plot_script_name, tex_filename, plot_script_name);
}

void light_intensity_analyzer_angle(char *tex_filename) {
    create_table_light_intensity_analyzer_angle(tex_filename);
    fill_table_light_intensity_analyzer_angle("../data/light_intensity_analyzer_angle.csv", tex_filename);
    insert_plot(PLOT_SCRIPT_PATH, "light-intensity-analyzer-angle.gnuplot",
                tex_filename, "light-intensity-analyzer-angle.gnuplot");
}

void led(char *tex_filename, int num) {
    create_table_led(tex_filename);
    char *data_filename = malloc(sizeof(char) * 128);
    char *plot_script_name = malloc(sizeof(char) * 128);
    char *figure_vc_name = malloc(sizeof(char) * 128);
    char *figure_pc_name = malloc(sizeof(char) * 128);
    sprintf(data_filename, "../data/led_%d.csv", num);
    sprintf(plot_script_name, "led-%d.gnuplot", num);
    sprintf(figure_vc_name, "led-vc-%d.gnuplot", num);
    sprintf(figure_pc_name, "led-pc-%d.gnuplot", num);
    fill_table_led(data_filename, tex_filename);
    insert_plot(PLOT_SCRIPT_PATH, plot_script_name, tex_filename, figure_vc_name);
    insert_plot(PLOT_SCRIPT_PATH, plot_script_name, tex_filename, figure_pc_name);
}

int main() {
    char *tex_filename = malloc(sizeof(char) * 128);
    char *pdf_filename = malloc(sizeof(char) * 128);
    sprintf(tex_filename, "%s%s", WORKDIR, TEX_FILE_NAME);
    sprintf(pdf_filename, "%s%s", WORKDIR, PDF_FILE_NAME);

    generate_header(tex_filename);

    current_mfield(tex_filename);
    for (int i = 1; i <= 4; i++) {
        analyzer_angle_light_intensity(tex_filename, i);
    }

    light_intensity_analyzer_angle(tex_filename);

    for (int i = 1; i <= 8; i++) {
        led(tex_filename, i);
    }

    generate_footer(tex_filename);
    xelatex_compile(tex_filename, pdf_filename);

    return 0;
}
