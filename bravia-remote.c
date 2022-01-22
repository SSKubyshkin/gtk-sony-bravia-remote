#include <gtk/gtk.h>

char* concat(const char *s1, const char *s2) {
  char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
  strcpy(result, s1);
  strcat(result, s2);
  return result;
}

void send_command(GtkWidget *widget, gpointer data) {
  const char *ircc_codes[3] = {
    " AAAAAQAAAAEAAAASAw==",
    " AAAAAQAAAAEAAAATAw==",
    " AAAAAQAAAAEAAAAUAw=="
  };

  char *shell = "./send-command.sh";
  char *ip = " 192.168.0.10";
  int code = GPOINTER_TO_INT(data);
  system(concat(concat(shell, ip), ircc_codes[code]));  
}

static void activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *button;

  // Create a new window and set its title
  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Main Interface");

  // Construct a grid (container)
  grid = gtk_grid_new();

  // Pack the container in the window
  gtk_window_set_child(GTK_WINDOW(window), grid);

  button = gtk_button_new_with_label("Volume Up");
  g_signal_connect(button, "clicked", G_CALLBACK(send_command), GINT_TO_POINTER(0));
  gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);

  button = gtk_button_new_with_label("Volume Down");
  g_signal_connect(button, "clicked", G_CALLBACK(send_command), GINT_TO_POINTER(1));
  gtk_grid_attach(GTK_GRID(grid), button, 1, 0, 1, 1);

  button = gtk_button_new_with_label("Mute");
  g_signal_connect(button, "clicked", G_CALLBACK(send_command), GINT_TO_POINTER(2));
  gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 2, 1);

  button = gtk_button_new_with_label("Quit");
  g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), window);
  gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 2, 1);

  gtk_widget_show(window);
}

int main (int argc, char **argv) {
  GtkApplication *app;

  app = gtk_application_new("com.sskubyshkin.braviaremote", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  int status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
