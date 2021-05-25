#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/*
ANTES DE USAR, 
SE NECESITAN LAS SIGUIENTES LIBRERÍAS EN LINUX:

+ pdflatex
  Se usa para convertir fuentes de latex a pdf
  Peso approx de descarga: 1500Mb.
  Tutorial para instalar: https://gist.github.com/rain1024/98dd5e2c6c8c28f9ea9d (todos los paquetes extras pueden llegar a ser necesarios, mejor instalarlos).
*/

// Command to compile: 
// gcc -o latex latex.c 

// #ifndef _LATEX_H_
// #define _LATEX_H_

#define NAME_OF_TEX_FILE "LATEX.tex"
#define NAME_OF_PDF_FILE "LATEX.pdf"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define BCK  "\x1B[0m"

FILE * tex_file;


// Funciones reutilizables
// 
#define PRINT(x) (printf("%s", x))

void Latex_Write(char * text){
    fputs(text, tex_file);
}
void Latex_WriteS(char * text, char * string){
    fprintf(tex_file, text, string);
}
void Latex_WriteI(char * text, int numero){
    fprintf(tex_file, text, numero);
}


void Latex_InicializarVariable(){
    tex_file = fopen(NAME_OF_TEX_FILE, "w");
}
void Latex_FinalizarVariable(){
    fclose(tex_file);
}

void Latex_ComentariosIniciales(){
    fputs("% Tecnológico de Costa Rica \n", tex_file);
    fputs("% Sistemas Operativos Avanzados \n", tex_file);
    fputs("% 3er proyecto \n", tex_file);
    fputs("% Scheduling en Tiempo Real \n", tex_file);
    fputs(" \n", tex_file);
}

void Latex_WriteHeader(){
    Latex_Write("\\documentclass{beamer} \n");
    Latex_Write("\\usetheme[progressbar=frametitle]{metropolis} \n");
    Latex_Write("\\setbeamertemplate{frame numbering}[fraction] \n");
    Latex_Write("\\useoutertheme{metropolis} \n");
    Latex_Write("\\useinnertheme{metropolis} \n");
    Latex_Write("\\usefonttheme{metropolis} \n");
    Latex_Write("\\usecolortheme{metropolis} \n");
    Latex_Write("\\usepackage[utf8]{inputenc} \n");
    Latex_Write("\\usepackage{lmodern} \n");
    Latex_Write("\\usepackage[T1]{fontenc} \n");
    Latex_Write("\\usepackage[spanish]{babel} \n");
    Latex_Write("\\usepackage{tikz} \n");
    Latex_Write("\\usepackage{natbib} \n");
    Latex_Write("\\usepackage{hyperref} \n");
    Latex_Write("\\usepackage{multirow} \n");
    Latex_Write("\\usepackage{colortbl} \n");
    Latex_Write("\\usepackage{helvet} \n");
    Latex_Write("\\usepackage[export]{adjustbox} % loads also graphicx \n");
    Latex_Write("\\usepackage{lipsum} \n");
    Latex_Write("%Definiciones \n");
    Latex_Write("\\definecolor{color_columna_candidata}{rgb}{0, 0.424, 0.455} \n");
    Latex_Write("\\definecolor{color_pivote}{rgb}{0.973, 0.80, 0.341} \n");
    Latex_Write("\\definecolor{color_blanco}{rgb}{1,1,1} \n");
    Latex_Write("% Commands \n");
    Latex_Write("\\newcommand\\tab[1][1cm]{\\hspace*{#1}}  \n");
    Latex_Write("\\newcommand\\minitab[1][0.5cm]{\\hspace*{#1}}  \n");
    Latex_Write("% Tittle information \n");
    Latex_Write("\\title{Scheduling en Tiempo Real} \n");
    Latex_Write("\\subtitle{Sistemas Operativos Avanzados} \n");
    Latex_Write("\\author[A. \\& D. \\& E.]{% \n");
      Latex_Write("\\texorpdfstring{% \n");
        Latex_Write("\\begin{columns} \n");
          Latex_Write("\\column{.33\\linewidth} \n");
          Latex_Write("\\centering \n");
          Latex_Write("\\\\  Nicole Carvajal \\\\ \n");
          Latex_Write("\\column{.33\\linewidth} \n");
          Latex_Write("\\centering \n");
          Latex_Write("\\\\  Rubén González \\\\ \n");
          Latex_Write("\\column{.33\\linewidth} \n");
          Latex_Write("\\centering \n");
          Latex_Write("\\\\ Edisson López \\\\ \n");
        Latex_Write("\\end{columns} \n");
        Latex_Write("\\begin{columns} \n");
          Latex_Write("\\column{.2\\linewidth} \n");
          Latex_Write("\\centering \n");
          Latex_Write("\\\\  Otto Mena \\\\ \n");
          Latex_Write("\\column{.2\\linewidth} \n");
          Latex_Write("\\centering \n");
          Latex_Write("\\\\  Cristina Soto  \\\\ \n");
        Latex_Write("\\end{columns} \n");
     Latex_Write("} \n");
     Latex_Write("{Author 1, Author 2, Author 3} \n");
    Latex_Write("} \n");
    Latex_Write("\\date{} \n");
    Latex_Write("\\institute{% \n");
      Latex_Write("\\texorpdfstring{% \n");
        Latex_Write("\\begin{columns} \n");
          Latex_Write("\\column{.9\\linewidth} \n");
          Latex_Write("\\centering \n");
          Latex_Write("\\\\ \n");
          Latex_Write("Tecnológico de Costa Rica \\\\ \n");
          Latex_Write("Maestría de Ciencias de la Computación \\\\ \n");
          Latex_Write("Semestre 1, 2021 \n");
        Latex_Write("\\end{columns} \n");
     Latex_Write("} \n");
    Latex_Write("} \n");
}

void Latex_WriteCover(){
    Latex_Write("\n");
    Latex_Write("% - - 1st Slide - - ; \n");
    Latex_Write("% - - Cover - - - - ; \n");
    Latex_Write("\\begin{frame}[plain,t] \n");
    Latex_Write("\\maketitle \n");
    Latex_Write("\\end{frame} \n");
    Latex_Write("\n");
}
void Latex_WriteSection2(){
    Latex_Write("\n");
    Latex_Write("% - - - - - - - - - ;\n");
    Latex_Write("% - - - - 2 - - - - ;\n");
    Latex_Write("% Breve introducción del proyecto \n");
    Latex_Write("\\section{Scheduling en Tiempo Real}\n");
    Latex_Write("\\begin{frame}\n");
    Latex_Write("Simulación del comportamiento de varios algoritmos de scheduling clásicos para Sistemas Operativos de Tiempo Real (RTOS). Con una interaz gráfica hecha con GTK y generación de una presentación Beamer como salida.\n");
    Latex_Write("\\end{frame}\n");
    Latex_Write("\n");
}

void Latex_WriteDocument(){
    Latex_Write("%Inicio del documento \n");
    Latex_Write("\\begin{document} \n");
    Latex_WriteCover();
    Latex_WriteSection2();
}

void IniciarLatex(){
    Latex_InicializarVariable();
    Latex_ComentariosIniciales();
    Latex_WriteHeader();
    Latex_WriteDocument();
}




void Latex_ComandosFinales(){
    fputs("\\end{document}\n", tex_file);
    fputs("% } DOCUMENT \n", tex_file);
    fputs("% Última línea del documento", tex_file);
}

void GeneratePDF(){
    char command[] = "pdflatex ";
    strcat(command, NAME_OF_TEX_FILE);
    system(command);
}

void OpenPDF(){
    char command[] = "xdg-open ";
    strcat(command, NAME_OF_PDF_FILE);
    system(command);
}

void MoveFiles(){
    system("mv -v ./LATEX.pdf ./Salida/LATEX.pdf");
    system("mv -v ./LATEX.tex ./Salida/LATEX.tex");
    system("mv -v ./LATEX.log ./Salida/LATEX.log");
    system("mv -v ./LATEX.aux ./Salida/LATEX.aux");
    system("mv -v ./LATEX.nav ./Salida/LATEX.nav");
    system("mv -v ./LATEX.out ./Salida/LATEX.out");
    system("mv -v ./LATEX.snm ./Salida/LATEX.snm");
    system("mv -v ./LATEX.toc ./Salida/LATEX.toc");
}

void TerminarLatex(){
    Latex_ComandosFinales();
    Latex_FinalizarVariable();
    GeneratePDF();
    OpenPDF();
    printf("\nPress Enter to close the program.");
    getchar();
    MoveFiles();
}


int main(int argc, char** argv) {
    PRINT("Inicio \n\n");

    IniciarLatex();
    TerminarLatex();
    
    printf("\n\nFinal \n\n");

    return (EXIT_SUCCESS);
}