//
// Created by hxp on 2020-11-10.
//

#ifndef OPTICS_EXPERIMENT_GENERATE_DOCUMENT_H
#define OPTICS_EXPERIMENT_GENERATE_DOCUMENT_H

void generate_header(char *filename);

void generate_footer(char *filename);

void xelatex_compile(char *tex_filename, char* pdf_filename);

#endif //OPTICS_EXPERIMENT_GENERATE_DOCUMENT_H
