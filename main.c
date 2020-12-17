#include <gtk/gtk.h>

void on_show_button_clicked(GtkWidget *show_button, GtkWidget *hello_display) {
    gtk_label_set_markup(GTK_LABEL(hello_display), "<span font='Italic 30'>Hello, World!</span>");
}

void on_clear_button_clicked(GtkWidget *clear_button, GtkWidget *hello_display) {
    gtk_label_set_text(GTK_LABEL(hello_display), "");
}

void build_window(void) {
    GtkWidget *hello_window, *layout;
    GtkWidget *hello_display, *show_button, *clear_button;

    hello_display = gtk_label_new(NULL);

    show_button = gtk_button_new();

    gtk_button_set_label(GTK_BUTTON(show_button), "Display Hello");

    clear_button = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(clear_button), "Clear");

    g_signal_connect(show_button,
                     "clicked",
                     G_CALLBACK(on_show_button_clicked),
                     hello_display);

    g_signal_connect(clear_button,
                     "clicked",
                     G_CALLBACK(on_clear_button_clicked),
                     hello_display);


    layout = gtk_grid_new();

    gtk_grid_attach(GTK_GRID(layout), hello_display, 0, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(layout), show_button, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(layout), clear_button, 1, 1, 1, 1);

    gtk_grid_set_row_homogeneous(GTK_GRID(layout), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(layout), TRUE);

    gtk_grid_set_row_spacing(GTK_GRID(layout), 8);
    gtk_grid_set_column_spacing(GTK_GRID(layout), 32);

    gtk_widget_set_margin_start(layout, 20);
    gtk_widget_set_margin_end(layout, 20);

    gtk_widget_set_margin_top(layout, 20);
    gtk_widget_set_margin_bottom(layout, 20);


    hello_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(hello_window), "Graphical Hello");
    gtk_window_set_default_size(GTK_WINDOW(hello_window), 400, 300);
    gtk_container_add(GTK_CONTAINER(hello_window), layout);
    gtk_widget_show_all(hello_window);

    g_signal_connect(hello_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    build_window();
    gtk_main();
    return 0;
}
