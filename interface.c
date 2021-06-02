#include <gtk/gtk.h>
#include <stdbool.h>  
#include <glib/gtypes.h>
#include <stdio.h>
#include <math.h>






//Compilar: gcc EDF.c -o edf -lm

//Máximo Común Divisor
int MCD(int x, int y)
{
    while (y != 0)
    {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

//Mínimo Común Múltiplo
int MCM(int x, int y)
{
    return (x * y) / MCD(x, y);
}

//Parte Izquierda de Schedulable
double U(int n, int c[], int p[])
{
    double result = 0;
    for (int i = 0; i < n; i++)
    {
        result += (double)c[i] / (double)p[i];
    }
    return result;
}

//Parte Derecha de Schedulable
double schedulable(double n)
{
    return 1;
}

void insertionSort(int arr[], int indx[], int n,  int actual )
{
    /* - arr es el arreglo con los datos que se usan como criterio para el ordenamiento
       - indx es un arreglo de enteros consecutivos de tamaño n (ej: {0,1,2})
       - actual es el proceso en ejecución. Se usa para desempates 
    	    (actual tiene prioridad) (si actual = -1, no se toma en cuenta)
    */
    
    //Orden arr y, al mismo tiempo, indx    
    int i, key, j, keyIndx;
    for(i = 1; i< n; i++){
    	key = arr[i];
    	keyIndx = indx[i];
    	j = i - 1;
    	
    	while(j >= 0 && (arr[j] > key || (arr[j] == key && i == actual))){
    	    
    	    arr[j + 1] = arr[j];
    	    indx[j + 1] = indx[j];
    	    j = j - 1;
    	}
    	arr[j + 1] = key;
    	indx[j + 1] = keyIndx;
    }
}

//Retorna deadline
int edf(int p, int j){
    return p - j % p;
}


//Retorna laxity
int llf(int p, int j, int c){
    return (p - j % p) - j - c;
}


void schedulingAlgorithm(int n, int m, int c[], int p[], int result[n][m], int type)
{
    //Initialize Configuration
    int progress[n];
    int indx[n];
    int actual = -1;
    int arr[n];    
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i][j] = 0;
        }
        progress[i] = 0;
    }

    //EDF
    int stop = 0;
    for (int j = 0; j < m && stop == 0; j++)
    {
        //Increase Progress and Check Error
        for (int i = 0; i < n; i++)
        {
            if (j % p[i] == 0)
            {
                //Check ERROR
                if (progress[i] > 0)
                {
                    result[n][j] = -1;
                    stop = 1;
                    break;
                }
                //Increase C in Progress
                progress[i] += c[i];
            }
        }
        
        //Set priorities
        for(int i=0; i< n; i++){
            indx[i] = i;
            if(type == 0) arr[i] = p[i];
            else if(type==1) arr[i] = edf(p[i], j);
            else if(type == 2) arr[i] = llf(p[i], j, c[i]); 
        }
        
        insertionSort(arr, indx, n, actual);
        
        //Simulate Execution: cambiar orden para que sea el de EDF
        for (int i = 0; i < n && stop == 0; i++)
        {
            if (progress[indx[i]] > 0)
            {
                result[indx[i]][j] = 1;
                progress[indx[i]]--;
                actual = progress[indx[i]] == 0 ? -1 : indx[i];
                break;
            }
        }
    }    
    
}




/*
TODO: 
    + Validaciones:
        2. Que escoja el menos un algoritmo.
        3. Que solo acepte números en las entradas

DONE:
    + Validaciones:
        1. Tiempo de ejecución más peque que el período

    + Variables para guardado de las entradas.
        1. INT: [n] Cantidad de tareas 
        2. Array de INT: [tiempos] de c (tiempos)
        3. Array de INT: [periodos] de p (períodos)
        4. Array de INT: [algoritmosUsados]
        5. Bool: [sonSlidesPorSepado] ¿son slides por separado? 


COMANDO PARA CORRER:
gcc -o interface interface.c -lm -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic ; ./interface

*/


// Constantes
int cantidadTareasSeleccionadas = 1;
int sonSlidesPorSepado = 1; 
int algoritmosUsados[3] = {0,0,0};
int tiempos[6] = {0,0,0,0,0,0};
int periodos[6] = {0,0,0,0,0,0};



int ALGORITMO_GENERAL()
{
    int n = cantidadTareasSeleccionadas;

    //Calculate MCM
    int m = 1;
    for (int i = 0; i < n; i++)
    {
        m = MCM(periodos[i], m);
    }

    //Calculate Rate Monotonic
    int result[n + 1][m];
    for (int i = 0; i<3 ; i++ ){
        if (algoritmosUsados[i]){
            schedulingAlgorithm(cantidadTareasSeleccionadas, m, tiempos, periodos, result, i);
            //Print Result
            for (int i = 0; i < n + 1; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    printf("%d ", result[i][j]);
                    if (j == m - 1)
                    {
                        printf("\n");
                    }
                }
            }
            printf("\n\n");
        }
    }

    

    return 0;
}





//Inicialización de los componentes en Interfaz
GtkBuilder *builder;
GtkWidget *window;
GtkWidget *g_lbl_nombreBuffer;
GtkWidget *g_radio_tareas_1;
GtkWidget *g_radio_tareas_2;
GtkWidget *g_radio_tareas_3;
GtkWidget *g_radio_tareas_4;
GtkWidget *g_radio_tareas_5;
GtkWidget *g_radio_tareas_6;
GtkWidget *g_entry_tarea_tiempo_1;
GtkWidget *g_entry_tarea_tiempo_2;
GtkWidget *g_entry_tarea_tiempo_3;
GtkWidget *g_entry_tarea_tiempo_4;
GtkWidget *g_entry_tarea_tiempo_5;
GtkWidget *g_entry_tarea_tiempo_6;
GtkWidget *g_entry_tarea_periodo_1;
GtkWidget *g_entry_tarea_periodo_2;
GtkWidget *g_entry_tarea_periodo_3;
GtkWidget *g_entry_tarea_periodo_4;
GtkWidget *g_entry_tarea_periodo_5;
GtkWidget *g_entry_tarea_periodo_6;
GtkWidget *g_check_algoritmo_1;
GtkWidget *g_check_algoritmo_2;
GtkWidget *g_check_algoritmo_3;
GtkWidget *g_radio_slides_separados;
GtkWidget *g_radio_slides_juntos;
GtkWidget *g_btn_iniciar;
GtkWidget *g_msj_error_1;
GtkWidget *g_msj_error_2;
GtkWidget *g_msj_error_3;
GtkWidget *g_msj_error_4;
GtkWidget *g_msj_error_5;
GtkWidget *g_msj_error_6;

void PrintInt(int value){
    char stringValue[100];
    sprintf(stringValue, "%d", value);
    printf("%s", stringValue);
}

// Valida si al menos un checkbox de los algoritmos está marcado.
int ValidarAlgoritmosSeleccionados(){ 
    if (algoritmosUsados[0]==0 && 
        algoritmosUsados[1]==0 && 
        algoritmosUsados[2]==0 
    ){
        printf(" > Debe tener al menos un algoritmo seleccionado. \n");
        return false;
    }else{
        return true;
    }
}

// Valida por cada tarea si el tiempo es menor al período
int ValidarCongruenciaTiemposConPeriodos(){ 
    
    if (tiempos[0] >= periodos[0]  &&  gtk_widget_get_child_visible(g_entry_tarea_tiempo_1)==1 ){
        gtk_widget_set_child_visible(g_msj_error_1, true);
    }else{
        gtk_widget_set_child_visible(g_msj_error_1, false);
    }

    if (tiempos[1] >= periodos[1]  &&  gtk_widget_get_child_visible(g_entry_tarea_tiempo_2)==1 ){
        gtk_widget_set_child_visible(g_msj_error_2, true);
    }else{
        gtk_widget_set_child_visible(g_msj_error_2, false);
    }

    if (tiempos[2] >= periodos[2]  &&  gtk_widget_get_child_visible(g_entry_tarea_tiempo_3)==1 ){
        gtk_widget_set_child_visible(g_msj_error_3, true);
    }else{
        gtk_widget_set_child_visible(g_msj_error_3, false);
    }
    
    if (tiempos[3] >= periodos[3]  &&  gtk_widget_get_child_visible(g_entry_tarea_tiempo_4)==1 ){
        gtk_widget_set_child_visible(g_msj_error_4, true);
    }else{
        gtk_widget_set_child_visible(g_msj_error_4, false);
    }
    
    if (tiempos[4] >= periodos[4]  &&  gtk_widget_get_child_visible(g_entry_tarea_tiempo_5)==1 ){
        gtk_widget_set_child_visible(g_msj_error_5, true);
    }else{
        gtk_widget_set_child_visible(g_msj_error_5, false);
    }
    
    if (tiempos[5] >= periodos[5]  &&  gtk_widget_get_child_visible(g_entry_tarea_tiempo_6)==1 ){
        gtk_widget_set_child_visible(g_msj_error_6, true);
    }else{
        gtk_widget_set_child_visible(g_msj_error_6, false);
    }
    
    if ( (tiempos[0] >= periodos[0] && gtk_widget_get_child_visible(g_entry_tarea_tiempo_1)==1) || 
         (tiempos[1] >= periodos[1] && gtk_widget_get_child_visible(g_entry_tarea_tiempo_2)==1) || 
         (tiempos[2] >= periodos[2] && gtk_widget_get_child_visible(g_entry_tarea_tiempo_3)==1) || 
         (tiempos[3] >= periodos[3] && gtk_widget_get_child_visible(g_entry_tarea_tiempo_4)==1) || 
         (tiempos[4] >= periodos[4] && gtk_widget_get_child_visible(g_entry_tarea_tiempo_5)==1) || 
         (tiempos[5] >= periodos[5] && gtk_widget_get_child_visible(g_entry_tarea_tiempo_6)==1) 
    ){
        printf(" > Formato inválido, el tiempo debe ser menor al período. \n");
        return 0;
    }else{
        return 1;
    }
}

void IniciarEjecucion(){ 
    // Definición de los parámetros en variables
    tiempos[0] = atoi(gtk_entry_get_text(GTK_ENTRY(g_entry_tarea_tiempo_1)));
    tiempos[1] = atoi(gtk_entry_get_text(GTK_ENTRY(g_entry_tarea_tiempo_2)));
    tiempos[2] = atoi(gtk_entry_get_text(GTK_ENTRY(g_entry_tarea_tiempo_3)));
    tiempos[3] = atoi(gtk_entry_get_text(GTK_ENTRY(g_entry_tarea_tiempo_4)));
    tiempos[4] = atoi(gtk_entry_get_text(GTK_ENTRY(g_entry_tarea_tiempo_5)));
    tiempos[5] = atoi(gtk_entry_get_text(GTK_ENTRY(g_entry_tarea_tiempo_6)));
    periodos[0] = atoi(gtk_entry_get_text(GTK_ENTRY(g_entry_tarea_periodo_1)));
    periodos[1] = atoi(gtk_entry_get_text(GTK_ENTRY(g_entry_tarea_periodo_2)));
    periodos[2] = atoi(gtk_entry_get_text(GTK_ENTRY(g_entry_tarea_periodo_3)));
    periodos[3] = atoi(gtk_entry_get_text(GTK_ENTRY(g_entry_tarea_periodo_4)));
    periodos[4] = atoi(gtk_entry_get_text(GTK_ENTRY(g_entry_tarea_periodo_5)));
    periodos[5] = atoi(gtk_entry_get_text(GTK_ENTRY(g_entry_tarea_periodo_6)));

    int esValido = ValidarCongruenciaTiemposConPeriodos();
    esValido = ValidarAlgoritmosSeleccionados() && esValido;
    
    if (esValido){
        printf("\n\n--------------------\nParámetros recibidos: \n");
        printf("Cantidad de tareas: %d \n", cantidadTareasSeleccionadas);
        printf("Tiempos por cada tarea: \n");
        for (int i=0; i<cantidadTareasSeleccionadas ; i++){
            printf("\t Tarea %d: %d\n", i+1, tiempos[i]);
        }
        printf("Períodos por cada tarea: \n");
        for (int i=0; i<cantidadTareasSeleccionadas ; i++){
            printf("\t Tarea %d: %d\n", i+1, periodos[i]);
        }
        printf("Algoritmos usados: \n");
        printf("\t + 1. RM: Rate Monothonic: %s \n", algoritmosUsados[0]==1 ? "Sí" : "No");
        printf("\t + 2. EDF: Earliest Deadline First: %s \n", algoritmosUsados[1]==1 ? "Sí" : "No");
        printf("\t + 3. LLF: Least Laxity First: %s \n", algoritmosUsados[2]==1 ? "Sí" : "No");

        printf("\n Algoritmos a mostrar %s \n", sonSlidesPorSepado==1 ? "en slides separados" : "juntos en un solo slide");
        printf("\n-------------------- \n\n");

        ALGORITMO_GENERAL();

        // VARIABLES PARA USAR EN LA INTEGRACIÓN: 
        // cantidadTareasSeleccionadas          // Es el n
        // tiempos                              // Es el c
        // periodos                             // Es el p
        // sonSlidesPorSepado                   // Su valor puede ser 1 o 0.
        // algoritmosUsados[3] = {0,0,0}        // Ceros(0) si no se está usando, unos(1) si sí.
    }
}


// Revisa si algún evento está pendiente de actualizar y lo actualiza.
// Éste se usa para actualizar cambios en el UI e invocar timeouts en interfaz.
// Mientras o luego de hacer algún cambio de la interfaz (como el set_text).
void RefrescarInterfaz(){
    while (gtk_events_pending ())
        gtk_main_iteration ();
}

void onClickRadioTareas(int numeroDeTareas)
{
    if (numeroDeTareas==1){
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_2, false);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_3, false);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_4, false);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_5, false);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_6, false);
    }else if (numeroDeTareas==2){
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_2, true);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_3, false);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_4, false);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_5, false);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_6, false);
    }else if (numeroDeTareas==3){
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_2, true);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_3, true);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_4, false);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_5, false);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_6, false);
    }else if (numeroDeTareas==4){
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_2, true);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_3, true);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_4, true);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_5, false);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_6, false);
    }else if (numeroDeTareas==5){
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_2, true);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_3, true);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_4, true);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_5, true);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_6, false);
    }else if (numeroDeTareas==6){
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_2, true);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_3, true);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_4, true);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_5, true);
        gtk_widget_set_child_visible(g_entry_tarea_tiempo_6, true);
    }
    if (numeroDeTareas==1){
        gtk_widget_set_child_visible(g_entry_tarea_periodo_2, false);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_3, false);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_4, false);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_5, false);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_6, false);
    }else if (numeroDeTareas==2){
        gtk_widget_set_child_visible(g_entry_tarea_periodo_2, true);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_3, false);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_4, false);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_5, false);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_6, false);
    }else if (numeroDeTareas==3){
        gtk_widget_set_child_visible(g_entry_tarea_periodo_2, true);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_3, true);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_4, false);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_5, false);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_6, false);
    }else if (numeroDeTareas==4){
        gtk_widget_set_child_visible(g_entry_tarea_periodo_2, true);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_3, true);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_4, true);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_5, false);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_6, false);
    }else if (numeroDeTareas==5){
        gtk_widget_set_child_visible(g_entry_tarea_periodo_2, true);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_3, true);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_4, true);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_5, true);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_6, false);
    }else if (numeroDeTareas==6){
        gtk_widget_set_child_visible(g_entry_tarea_periodo_2, true);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_3, true);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_4, true);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_5, true);
        gtk_widget_set_child_visible(g_entry_tarea_periodo_6, true);
    }
    RefrescarInterfaz();
}

void onClickRadioTareas1(){ cantidadTareasSeleccionadas = 1; onClickRadioTareas(1); }
void onClickRadioTareas2(){ cantidadTareasSeleccionadas = 2; onClickRadioTareas(2); }
void onClickRadioTareas3(){ cantidadTareasSeleccionadas = 3; onClickRadioTareas(3); }
void onClickRadioTareas4(){ cantidadTareasSeleccionadas = 4; onClickRadioTareas(4); }
void onClickRadioTareas5(){ cantidadTareasSeleccionadas = 5; onClickRadioTareas(5); }
void onClickRadioTareas6(){ cantidadTareasSeleccionadas = 6; onClickRadioTareas(6); }

void onClickRadioAlgoritmosPorSeparado(){ sonSlidesPorSepado = 1; }
void onClickRadioAlgoritmosJuntos(){ sonSlidesPorSepado = 0; }

void onClickCheckboxAlg1(){ algoritmosUsados[0] = algoritmosUsados[0]==0 ? 1 : 0; }
void onClickCheckboxAlg2(){ algoritmosUsados[1] = algoritmosUsados[1]==0 ? 1 : 0; }
void onClickCheckboxAlg3(){ algoritmosUsados[2] = algoritmosUsados[2]==0 ? 1 : 0; }



// Creación de la interfaz
void IniciarInterfaz(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "interface.glade", NULL);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "interface"));
    gtk_builder_connect_signals(builder, NULL);

    // Estilos
    GtkCssProvider *cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "style.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
        GTK_STYLE_PROVIDER(cssProvider),
        GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Instancia de los componentes en interfaz que se ocupan manejar con código
    g_radio_tareas_1 = GTK_WIDGET(gtk_builder_get_object(builder, "radio_tareas_1"));
    g_radio_tareas_2 = GTK_WIDGET(gtk_builder_get_object(builder, "radio_tareas_2"));
    g_radio_tareas_3 = GTK_WIDGET(gtk_builder_get_object(builder, "radio_tareas_3"));
    g_radio_tareas_4 = GTK_WIDGET(gtk_builder_get_object(builder, "radio_tareas_4"));
    g_radio_tareas_5 = GTK_WIDGET(gtk_builder_get_object(builder, "radio_tareas_5"));
    g_radio_tareas_6 = GTK_WIDGET(gtk_builder_get_object(builder, "radio_tareas_6"));
    g_entry_tarea_tiempo_1 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_tarea_tiempo_1"));
    g_entry_tarea_tiempo_2 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_tarea_tiempo_2"));
    g_entry_tarea_tiempo_3 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_tarea_tiempo_3"));
    g_entry_tarea_tiempo_4 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_tarea_tiempo_4"));
    g_entry_tarea_tiempo_5 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_tarea_tiempo_5"));
    g_entry_tarea_tiempo_6 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_tarea_tiempo_6"));
    g_entry_tarea_periodo_1 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_tarea_periodo_1"));
    g_entry_tarea_periodo_2 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_tarea_periodo_2"));
    g_entry_tarea_periodo_3 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_tarea_periodo_3"));
    g_entry_tarea_periodo_4 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_tarea_periodo_4"));
    g_entry_tarea_periodo_5 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_tarea_periodo_5"));
    g_entry_tarea_periodo_6 = GTK_WIDGET(gtk_builder_get_object(builder, "entry_tarea_periodo_6"));
    g_check_algoritmo_1 = GTK_WIDGET(gtk_builder_get_object(builder, "check_algoritmo_1"));
    g_check_algoritmo_2 = GTK_WIDGET(gtk_builder_get_object(builder, "check_algoritmo_2"));
    g_check_algoritmo_3 = GTK_WIDGET(gtk_builder_get_object(builder, "check_algoritmo_3"));
    g_radio_slides_separados = GTK_WIDGET(gtk_builder_get_object(builder, "radio_slides_separados"));
    g_radio_slides_juntos = GTK_WIDGET(gtk_builder_get_object(builder, "radio_slides_juntos"));
    g_btn_iniciar = GTK_WIDGET(gtk_builder_get_object(builder, "btn_iniciar"));
    g_msj_error_1 = GTK_WIDGET(gtk_builder_get_object(builder, "msj_error_1"));
    g_msj_error_2 = GTK_WIDGET(gtk_builder_get_object(builder, "msj_error_2"));
    g_msj_error_3 = GTK_WIDGET(gtk_builder_get_object(builder, "msj_error_3"));
    g_msj_error_4 = GTK_WIDGET(gtk_builder_get_object(builder, "msj_error_4"));
    g_msj_error_5 = GTK_WIDGET(gtk_builder_get_object(builder, "msj_error_5"));
    g_msj_error_6 = GTK_WIDGET(gtk_builder_get_object(builder, "msj_error_6"));

    

    // Funciones a llamar al iniciar la interfaz
    onClickRadioTareas1();
    // Ocultar los mensajes de errores
    gtk_widget_set_child_visible(g_msj_error_1, false);
    gtk_widget_set_child_visible(g_msj_error_2, false);
    gtk_widget_set_child_visible(g_msj_error_3, false);
    gtk_widget_set_child_visible(g_msj_error_4, false);
    gtk_widget_set_child_visible(g_msj_error_5, false);
    gtk_widget_set_child_visible(g_msj_error_6, false);
    

    g_object_unref(builder);
    gtk_widget_show(window);
    gtk_main();
}


// Se llama cuando la interfaz es cerrada
void on_window_main_destroy()
{
    gtk_main_quit();
    exit(0);
}

int main(int argc, char **argv)
{
    IniciarInterfaz(argc, argv);

    return 0;
}