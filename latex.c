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

#define NAME_OF_TEX_FILE "./data/LATEX.tex"
#define NAME_OF_PDF_FILE "./data/LATEX.pdf"
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
  //  Latex_Write("\\usepackage[spanish]{babel} \n");
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
    Latex_Write("\\definecolor{C0}{HTML}{34FF34} \n");
    Latex_Write("\\definecolor{C1}{HTML}{FE0000} \n");
    Latex_Write("\\definecolor{C2}{HTML}{3531FF} \n");
    Latex_Write("\\definecolor{C3}{HTML}{FF8202} \n");
    Latex_Write("\\definecolor{C4}{HTML}{D122B9} \n");
    Latex_Write("\\definecolor{C5}{HTML}{680100} \n");
    Latex_Write("\\definecolor{C6}{HTML}{FAFAFA} \n");
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
    Latex_Write("\\begin{frame}{Scheduling en Tiempo Real}\n");
    Latex_Write("Simulación del comportamiento de varios algoritmos de scheduling clásicos para Sistemas Operativos de Tiempo Real (RTOS). Con una interfaz gráfica hecha con GTK y generación de una presentación Beamer como salida.\n");
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

void Escribir_Tabla( int n, int m, int result[n][m], int type, int periodos[]){
  if (type == 0) {
    Latex_Write("\\begin{frame}{Ejecución RM} \n");
  }
  else if (type == 1) {
    Latex_Write("\\begin{frame}{Ejecución EDF} \n");
  }
  else if (type == 2) {
    Latex_Write("\\begin{frame}{Ejecución LLF} \n");
  }
  else{
    Latex_Write("\\begin{frame}{} \n");
  }

  const char *color[7]= {"\\cellcolor[HTML]{34FF34}","\\cellcolor[HTML]{FE0000}",
                          "\\cellcolor[HTML]{3531FF}","\\cellcolor[HTML]{FF8202}",
                          "\\cellcolor[HTML]{D122B9}","\\cellcolor[HTML]{680100}",
                          "\\cellcolor[HTML]{000000}"};

  Latex_Write("\\begin{center} \n");
  Latex_Write("\\begin{tabular}{");
  for (size_t i = 0; i < m; i++) {
    Latex_Write("c");
  }
    Latex_Write("} \n");

printf("Entro antes de flechas\n" );
char c_t[2];

for (int i = 0; i < m; i++) {
    if (i != 0) {
      Latex_Write("&");
   }
    Latex_Write("\\multicolumn{1}{l}{");
    Latex_Write("\\shortstack{");
  for(int j = 0; j < n; j++){
    printf("Antes if periodos\n" );

    if (i % periodos[j] == 0) {
    printf("Entro if periodos\n" );

    Latex_Write(" $\\color{C");
    snprintf(c_t, 2, "%d", j);
    Latex_Write(c_t);
    Latex_Write("}{\\swarrow}$  \\\\");
    }
    else {
    Latex_Write(" $\\color{C6}{\\swarrow}$  \\\\");
    }
  }
  Latex_Write("}} ");
}

Latex_Write("\\\\");

Latex_Write("\\hline \n");
printf("n: %d  m: %d\n",n,m );

int deadline_p = -1;

for (int i = 0; i < m; i++) {
    if(result[n][i]== -1){
      deadline_p = i;
  }
}
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {

        printf("%d ", result[i][j]);
        Latex_Write("\\multicolumn{1}{|l|}{");

        if (deadline_p == j) {
            Latex_Write(color[6]);
        }

        if (1 == result[i][j]) {
          Latex_Write(color[i]);
        }
        if (j != m-1) {
          Latex_Write("} &");
        }
        if (j == m - 1)
        {
          Latex_Write("} ");
          Latex_Write("\\\\ \\hline \n");

            printf("\n");
        }
    }
}

Latex_Write("\\end{tabular}% \n");
Latex_Write("\\end{center} \n");
Latex_Write("\\end{frame}\n");


}

void Abrir_Frame() {
  Latex_Write("\\begin{frame}{Ejecución de Algoritmos RM - EDF - LLF} \n");

}

void Escribir_Tablas( int n, int m, int result[n][m], int type, int periodos[],int orden){

  const char *color[7]= {"\\cellcolor[HTML]{34FF34}","\\cellcolor[HTML]{FE0000}",
                          "\\cellcolor[HTML]{3531FF}","\\cellcolor[HTML]{FF8202}",
                          "\\cellcolor[HTML]{D122B9}","\\cellcolor[HTML]{680100}",
                          "\\cellcolor[HTML]{000000}"};

  Latex_Write("\\begin{center} \n");
  Latex_Write("\\renewcommand{\\arraystretch}{0.2}");
  Latex_Write("\\begin{tabular}{");
  for (size_t i = 0; i < m; i++) {
    Latex_Write("c");
  }
    Latex_Write("} \n");

char c_t[2];

if(orden == 0){
for (int i = 0; i < m; i++) {
    if (i != 0) {
      Latex_Write("&");
   }
   Latex_Write("\\multicolumn{1}{l}{\\begin{tiny}");
    Latex_Write("\\shortstack{");
  for(int j = 0; j < n; j++){

    if (i % periodos[j] == 0) {
    Latex_Write(" $\\color{C");
    snprintf(c_t, 2, "%d", j);
    Latex_Write(c_t);
    Latex_Write("}{\\swarrow}$  \\\\");
    }
    else {
    Latex_Write(" $\\color{C6}{\\swarrow}$  \\\\");
    }
  }
  Latex_Write("}\\end{tiny}} ");
}
Latex_Write("\\\\");
}
else{
  for (int i = 0; i < m; i++) {
      if (i != 0) {
        Latex_Write("&");
     }
      Latex_Write("\\multicolumn{1}{l}{\\begin{tiny}");
      Latex_Write("\\shortstack{");
      Latex_Write(" $\\color{C6}{\\swarrow}$  \\\\");
      Latex_Write("}\\end{tiny}} ");
  }
  Latex_Write("\\\\");

}

Latex_Write("\\hline \n");
printf("n: %d  m: %d\n",n,m );

int deadline_p = -1;

for (int i = 0; i < m; i++) {
    if(result[n][i]== -1){
      deadline_p = i;
  }
}
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {

        printf("%d ", result[i][j]);
        Latex_Write("\\multicolumn{1}{|l|}{");

        if (deadline_p == j) {
            Latex_Write(color[6]);
        }

        if (1 == result[i][j]) {
          Latex_Write(color[i]);
        }
        if (j != m-1) {
          Latex_Write("} &");
        }
        if (j == m - 1)
        {
          Latex_Write("} ");
          Latex_Write("\\\\ \\hline \n");

            printf("\n");
        }
    }
}

Latex_Write("\\end{tabular}\\\\ \n");
if (orden == 0) {
  Latex_Write("\\caption{RM} \n");
}
else if (orden == 1) {
  Latex_Write("\\caption{EDF} \n");
}
else{
  Latex_Write("\\caption{LLF} \n");

}
Latex_Write("\\end{center} \n");

}

void Cerrar_Frame() {
  Latex_Write("\\end{frame}\n");
}


void Escribir_AlgoritmoRM(){

Latex_Write("\\begin{frame}{Algoritmo: Rate Monotonic} \n");
Latex_Write("\\begin{itemize} \n");
Latex_Write("   \\item Propuesto por Liu y Layland (1973) \n");
Latex_Write("   \\item Scheduling de tiempo dinámico  \n");
Latex_Write("   \\item Es óptimo. \n");
Latex_Write("   \\item Expropiativo, de mayor prioridad primero \n");
Latex_Write("   \\item La prioridad de una tarea es inversamente proporcional a su periodo \n");
Latex_Write("\\end{itemize} \n");
Latex_Write("\\end{frame} \n");
}


void Escribir_AlgoritmoEDF() {
Latex_Write("\\begin{frame}{Algoritmo: Earliest Deadline First} \n");
Latex_Write("\\begin{itemize} \n");
Latex_Write("   \\item Propuesto por Liu y Layland (1973) \n");
Latex_Write("   \\item Scheduling dinámico de tiempo real \n");
Latex_Write("   \\item Es óptimo. \n");
Latex_Write("   \\item Expropiativo, de mayor prioridad primero \n");
Latex_Write("   \\item La prioridad de una tarea es inversamente proporcional al tiempo pendiente para que se dé su deadline \n");
Latex_Write("\\end{itemize} \n");
Latex_Write("\\end{frame} \n");
}

void Escribir_AlgoritmoLLF(){
Latex_Write("\\begin{frame}{Algoritmo: Least Laxity First} \n");
Latex_Write("\\begin{itemize} \n");
Latex_Write("   \\item Propuesto por Leung (1989) \n");
Latex_Write("   \\item Scheduling dinámico de tiempo real \n");
Latex_Write("   \\item Es óptimo. \n");
Latex_Write("   \\item Expropiativo, de mayor prioridad primero \n");
Latex_Write("   \\item La prioridad de una tarea es inversamente proporcional a su laxity. El laxity de la tarea i, d es el deadline, c es el tiempo de computación y t es el momento en el tiempo, se calcula: $( L_{i} = d_{i} - t_{i} - c_{i} )$  \n");
Latex_Write("\\end{itemize} \n");
Latex_Write("\\end{frame} \n");
}


void Escribir_Test(double mu, double bini,double un) {
  char mu_t[5];
  snprintf(mu_t, 5, "%.2f", mu);
  char bini_t[5];
  snprintf(bini_t, 5, "%.2f", bini);
  char un_t[5];
  snprintf(un_t, 5, "%.2f", un);

printf("Entro a Escribir_Test\n");
Latex_Write("\\begin{frame}{Tests de Schedulability} \n");
Latex_Write("\\begin{small} \n");
Latex_Write("\\textbf{Test de Liu y Layland} \n");

Latex_Write("\\begin{itemize} \n");
Latex_Write("\\item Fórmula: $( \\mu = \\sum{ c_{i} / p_{i}}  \\leq U(n) =  n(2^{1/n} - 1)  )$ \n");
Latex_Write("\\item Resultado del test RM: $( \\mu = ");
double min = (((mu) < (un)) ? (mu) : (un));
if(min == mu){
  Latex_Write(mu_t);
  Latex_Write("\\leq U(n) = ");
  Latex_Write(un_t);
  Latex_Write(")$, ");
  Latex_Write("\\textbf{aprobada}. \n");
  Latex_Write("\\item Este conjunto de tareas definitivamente sí correrán con el algoritmo RM.\n");
}
else{
  Latex_Write(mu_t);
  Latex_Write(" > U(n) = ");
  Latex_Write(un_t);
  Latex_Write(" )$, ");
  Latex_Write("\\textbf{rechazada}. \n");
  Latex_Write("\\item Usando RM, puede que para este conjunto de tareas ocurra un incumplimiento del deadline o puede que no.\n");
}
Latex_Write("\\item Resultado del test EDF: ( \\mu = ");
if(mu <= 1){
  Latex_Write(mu_t);
  Latex_Write("\\leq 1 ");
  Latex_Write(")$, ");
  Latex_Write("\\textbf{aprobada}. \n");
  Latex_Write("\\item Este conjunto de tareas definitivamente sí correrán con el algoritmo EDF.\n");
}
else{
  Latex_Write(mu_t);
  Latex_Write(" > 1 ");
  Latex_Write(")$, ");
  Latex_Write("\\textbf{rechazada}. \n");
  Latex_Write("\\item Usando EDF, puede que para este conjunto de tareas ocurra un incumplimiento del deadline o puede que no.\n");
}
Latex_Write("\\end{itemize} \n");
Latex_Write("\\textbf{Test de Bini} \n");
Latex_Write("\\begin{itemize} \n");
Latex_Write("\\item Fórmula: $( \\mu = \\prod{ (c_{i} / p_{i}} + 1 ) \\leq 2 )$ \n");
Latex_Write("\\item Resultado del test: $( \\mu =");
  if(bini <= 2){
    Latex_Write(bini_t);
    Latex_Write("\\leq 2 ");
    Latex_Write(")$, ");
    Latex_Write("\\textbf{aprobada}. \n");
    Latex_Write("\\item Este conjunto de tareas definitivamente sí correrán con el algoritmo de scheduling dado.\n");
  }
  else{
    Latex_Write(bini_t);
    Latex_Write(" > 2 ");
    Latex_Write(")$, ");
    Latex_Write("\\textbf{rechazada}. \n");
    Latex_Write("\\item Puede que para este conjunto de tareas ocurra un incumplimiento del deadline o puede que no.\n");
  }
Latex_Write("\\end{itemize} \n");
Latex_Write("\\end{small} \n");
Latex_Write("\\end{frame} \n");
}


void Latex_ComandosFinales(){
    fputs("\\end{document}\n", tex_file);
    fputs("% } DOCUMENT \n", tex_file);
    fputs("% Última línea del documento", tex_file);
}

void GeneratePDF(){
    system("pdflatex --interaction=nonstopmode --output-directory=data ./data/LATEX.tex");
}

void OpenPDF(){
    system("xdg-open ./data/LATEX.pdf");
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
}

/*
int main(int argc, char** argv) {
    PRINT("Inicio \n\n");

    IniciarLatex();

    TerminarLatex();

    printf("\n\nFinal \n\n");

    return (EXIT_SUCCESS);
}
*/
