#include <gtk/gtk.h>
#include <stdbool.h>  
#include <glib/gtypes.h>



/* 

TODO: 
    + Que solo acepte números en las entradas

COMANDO PARA CORRER:
gcc -o interface interface.c -lm -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic ; ./interface
*/


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
void onClickRadioTareas1(){ onClickRadioTareas(1); }
void onClickRadioTareas2(){ onClickRadioTareas(2); }
void onClickRadioTareas3(){ onClickRadioTareas(3); }
void onClickRadioTareas4(){ onClickRadioTareas(4); }
void onClickRadioTareas5(){ onClickRadioTareas(5); }
void onClickRadioTareas6(){ onClickRadioTareas(6); }


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