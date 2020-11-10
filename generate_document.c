//
// Created by hxp on 2020-11-10.
//
#include "main.h"
#include "generate_document.h"

void generate_header(char *filename) {
    char *cmd = malloc(sizeof(char) * 256);
    sprintf(cmd, "%s %s %s", "cp -f", "../tex-templates/new_document_head.tex", filename);
    system(cmd);
}

void generate_footer(char *filename) {
    char *cmd = malloc(sizeof(char) * 256);
    sprintf(cmd, "cat %s >> %s",
            "../tex-templates/new_document_tail.tex",
            filename);
    system(cmd);
}

void xelatex_compile(char *tex_filename, char *pdf_filename) {
    char *cmd = malloc(sizeof(char) * 256);
    sprintf(cmd, "xelatex %s",
            tex_filename);
    system(cmd);
    sprintf(cmd, "cp *.pdf %s",
            pdf_filename);
    system(cmd);
}