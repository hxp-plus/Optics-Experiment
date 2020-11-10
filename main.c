#include "main.h"
#include "generate_document.h"
#include "generate_table.h"

const char *WORKDIR = "../output/";
const char *TEX_FILE_NAME = "optics-experiment.tex";
const char *PDF_FILE_NAME = "optics-experiment.pdf";
const char *PLOT_SCRIPT_PATH = "../gnuplot_scripts/";


int main() {
    char *tex_filename = malloc(sizeof(char) * 128);
    char *pdf_filename = malloc(sizeof(char) * 128);
    sprintf(tex_filename, "%s%s", WORKDIR, TEX_FILE_NAME);
    sprintf(pdf_filename, "%s%s", WORKDIR, PDF_FILE_NAME);
    generate_header(tex_filename);

    create_table_analyzer_angle_light_intensity(tex_filename);
    fill_table_analyzer_angle_light_intensity("../data/analyzer_angle_light_intensity_1.csv", tex_filename);
    insert_plot(PLOT_SCRIPT_PATH, "analyzer-angle-light-intensity-1.gnuplot", tex_filename);

    generate_footer(tex_filename);
    xelatex_compile(tex_filename, pdf_filename);

    return 0;
}
