//
// Created by hxp on 2020-11-09.
//

#ifndef OPTICS_EXPERIMENT_GENERATE_TABLE_H
#define OPTICS_EXPERIMENT_GENERATE_TABLE_H

void create_table_analyzer_angle_light_intensity(char *filename);
void fill_table_analyzer_angle_light_intensity(char *data_filename, char* tex_filename);
void insert_plot(char* plot_script_path, char* plot_script_name, char* tex_filename);
void create_table_current_mfield(char *filename);
void fill_table_current_mfield(char *data_filename, char *tex_filename);


#endif //OPTICS_EXPERIMENT_GENERATE_TABLE_H
