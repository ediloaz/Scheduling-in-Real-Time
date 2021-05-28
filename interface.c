#include <gtk/gtk.h>
#include <stdbool.h>  
#include <glib/gtypes.h>



/*
TODO: 
    + Que solo acepte números en las entradas
    + Validaciones:
        1. Tiempo de ejecución más peque que el período
        2. Que escoja el menos un algoritmo.

DONE:
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

void PrintInt(int value){
    char stringValue[100];
    sprintf(stringValue, "%d", value);
    printf("%s", stringValue);
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

    // VARIABLES PARA USAR EN LA INTEGRACIÓN: 
    int n = cantidadTareasSeleccionadas;
    int c[6] = tiempos;
    int p[6] = periodos;
    
    // sonSlidesPorSepado                   // Su valor puede ser 1 o 0.
    // algoritmosUsados[3] = {0,0,0}        // Ceros(0) si no se está usando, unos(1) si sí.
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


// Revisa si algún evento está pendiente de actualizar y lo actualiza.
// Éste se usa para actualizar cambios en el UI e invocar timeouts en interfaz.
// Mientras o luego de hacer algún cambio de la interfaz (como el set_text).
void RefrescarInterfaz(){
    while (gtk_events_pending ())
        gtk_main_iteration ();
}

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
    

    

    // Funciones a llamar al iniciar la interfaz
    onClickRadioTareas1();
    

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