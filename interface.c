/*
 * author: wide288
 * copyleft
 * for you YangQi and my mom Happy every day!
 */

/*#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

/*#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)
*/
GtkWidget *textview1;
GtkWidget *textview2;
GtkTextBuffer *buffer1;
GtkTextBuffer *buffer2;

GtkWidget*
create_window1 (void)
{
  GtkWidget *window1;
  GtkWidget *fixed1;

  GtkWidget *label1;
  GtkWidget *label2;
  GtkWidget *label3;
  GtkWidget *label4;
  GtkWidget *button6;
  GtkWidget *button8;
  GtkWidget *button7;
  GtkWidget *button5;
  GtkWidget *button4;
  GtkWidget *button1;
  GtkWidget *button3;
  GtkWidget *button2;
  GtkWidget *checkbutton4;
  GtkWidget *checkbutton3;
  GtkWidget *checkbutton2;
  GtkWidget *comboboxentry4;
  GtkWidget *comboboxentry3;
  GtkWidget *comboboxentry2;
  GtkWidget *comboboxentry1;
  GtkWidget *checkbutton1;

  window1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window1), _("\344\270\262\345\217\243\347\262\276\347\201\265"));

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (window1), fixed1);

  textview1 = gtk_text_view_new ();
	buffer1 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview1));
  gtk_widget_show (textview1);
  gtk_fixed_put (GTK_FIXED (fixed1), textview1, 288, 16);
  gtk_widget_set_size_request (textview1, 352, 176);
  gtk_container_set_border_width (GTK_CONTAINER (textview1), 2);
  gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (textview1), GTK_WRAP_CHAR);

  textview2 = gtk_text_view_new ();
	buffer2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview2));
  gtk_widget_show (textview2);
  gtk_fixed_put (GTK_FIXED (fixed1), textview2, 288, 240);
  gtk_widget_set_size_request (textview2, 352, 120);
  gtk_container_set_border_width (GTK_CONTAINER (textview2), 2);
  gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (textview2), GTK_WRAP_CHAR);
  gtk_text_buffer_set_text (gtk_text_view_get_buffer (GTK_TEXT_VIEW (textview2)),
	_(" http://211.92.88.40/~wide288"), -1);

  label1 = gtk_label_new (_("杨琦，祝你快乐每一天!\n\351\200\211\346\213\251 COM \347\253\257\345\217\243"));
  gtk_widget_show (label1);
  gtk_fixed_put (GTK_FIXED (fixed1), label1, 40, 22);
  gtk_widget_set_size_request (label1, 150, 32);

  label2 = gtk_label_new (_("\346\225\260\346\215\256\344\275\215"));
  gtk_widget_show (label2);
  gtk_fixed_put (GTK_FIXED (fixed1), label2, 32, 88);
  gtk_widget_set_size_request (label2, 72, 24);

  label3 = gtk_label_new (_("\345\201\234\346\255\242\344\275\215"));
  gtk_widget_show (label3);
  gtk_fixed_put (GTK_FIXED (fixed1), label3, 40, 144);
  gtk_widget_set_size_request (label3, 64, 24);

  label4 = gtk_label_new (_("\346\240\241\351\252\214\344\275\215"));
  gtk_widget_show (label4);
  gtk_fixed_put (GTK_FIXED (fixed1), label4, 40, 200);
  gtk_widget_set_size_request (label4, 56, 24);

  button6 = gtk_button_new_with_mnemonic (_("\346\211\223\345\274\200\344\270\262\345\217\243"));
  gtk_widget_show (button6);
  gtk_fixed_put (GTK_FIXED (fixed1), button6, 40, 272);
  gtk_widget_set_size_request (button6, 80, 32);

  button8 = gtk_button_new_with_mnemonic (_("\351\200\200\345\207\272"));
  gtk_widget_show (button8);
  gtk_fixed_put (GTK_FIXED (fixed1), button8, 40, 352);
  gtk_widget_set_size_request (button8, 80, 32);

  button7 = gtk_button_new_with_mnemonic (_("\345\205\263\351\227\255\344\270\262\345\217\243"));
  gtk_widget_show (button7);
  gtk_fixed_put (GTK_FIXED (fixed1), button7, 40, 312);
  gtk_widget_set_size_request (button7, 80, 32);

  button5 = gtk_button_new_with_mnemonic (_("\350\277\233\345\210\266\350\275\254\346\215\242"));
  gtk_widget_show (button5);
  gtk_fixed_put (GTK_FIXED (fixed1), button5, 552, 200);
  gtk_widget_set_size_request (button5, 80, 32);

  button4 = gtk_button_new_with_mnemonic (_("\346\270\205\347\251\272"));
  gtk_widget_show (button4);
  gtk_fixed_put (GTK_FIXED (fixed1), button4, 464, 200);
  gtk_widget_set_size_request (button4, 82, 32);

  button1 = gtk_button_new_with_mnemonic (_("\346\270\205\347\251\272"));
  gtk_widget_show (button1);
  gtk_fixed_put (GTK_FIXED (fixed1), button1, 464, 368);
  gtk_widget_set_size_request (button1, 82, 32);

  button3 = gtk_button_new_with_mnemonic (_("\350\277\233\345\210\266\350\275\254\346\215\242"));
  gtk_widget_show (button3);
  gtk_fixed_put (GTK_FIXED (fixed1), button3, 552, 368);
  gtk_widget_set_size_request (button3, 80, 32);

  button2 = gtk_button_new_with_mnemonic (_("\345\217\221\351\200\201"));
  gtk_widget_show (button2);
  gtk_fixed_put (GTK_FIXED (fixed1), button2, 376, 368);
  gtk_widget_set_size_request (button2, 80, 32);

  checkbutton4 = gtk_check_button_new_with_mnemonic (_("\345\215\201\350\277\233\345\210\2664"));
  gtk_widget_show (checkbutton4);
  gtk_fixed_put (GTK_FIXED (fixed1), checkbutton4, 288, 376);
  gtk_widget_set_size_request (checkbutton4, 80, 24);

  checkbutton3 = gtk_check_button_new_with_mnemonic (_("\345\215\201\345\205\255\350\277\233\345\210\2663"));
  gtk_widget_show (checkbutton3);
  gtk_fixed_put (GTK_FIXED (fixed1), checkbutton3, 192, 376);
  gtk_widget_set_size_request (checkbutton3, 96, 24);

  checkbutton2 = gtk_check_button_new_with_mnemonic (_("\345\215\201\350\277\233\345\210\2662"));
  gtk_widget_show (checkbutton2);
  gtk_fixed_put (GTK_FIXED (fixed1), checkbutton2, 376, 208);
  gtk_widget_set_size_request (checkbutton2, 80, 24);

  comboboxentry4 = gtk_combo_box_entry_new_text ();
  gtk_widget_show (comboboxentry4);
  gtk_fixed_put (GTK_FIXED (fixed1), comboboxentry4, 40, 224);
  gtk_widget_set_size_request (comboboxentry4, 183, 25);
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry4), _("None"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry4), _("\345\245\207\346\240\241\351\252\214"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry4), _("\345\201\266\346\240\241\351\252\214"));

  comboboxentry3 = gtk_combo_box_entry_new_text ();
  gtk_widget_show (comboboxentry3);
  gtk_fixed_put (GTK_FIXED (fixed1), comboboxentry3, 40, 168);
  gtk_widget_set_size_request (comboboxentry3, 183, 25);
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry3), _("1"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry3), _("2"));

  comboboxentry2 = gtk_combo_box_entry_new_text ();
  gtk_widget_show (comboboxentry2);
  gtk_fixed_put (GTK_FIXED (fixed1), comboboxentry2, 40, 112);
  gtk_widget_set_size_request (comboboxentry2, 183, 25);
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry2), _("7"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry2), _("8"));

  comboboxentry1 = gtk_combo_box_entry_new_text ();
  gtk_widget_show (comboboxentry1);
  gtk_fixed_put (GTK_FIXED (fixed1), comboboxentry1, 40, 56);
  gtk_widget_set_size_request (comboboxentry1, 183, 25);
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry1), _("COM1"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxentry1), _("COM2"));

  checkbutton1 = gtk_check_button_new_with_mnemonic (_("\345\215\201\345\205\255\350\277\233\345\210\2661"));
  gtk_widget_show (checkbutton1);
  gtk_fixed_put (GTK_FIXED (fixed1), checkbutton1, 280, 208);
  gtk_widget_set_size_request (checkbutton1, 96, 24);

  g_signal_connect (G_OBJECT(window1), "delete_event",
                    G_CALLBACK (gtk_main_quit),
                    NULL);
  g_signal_connect ((gpointer) button6, "clicked",
                    G_CALLBACK (on_button6_clicked),
                    NULL);
  g_signal_connect ((gpointer) button8, "clicked",
                    G_CALLBACK (on_button8_clicked),
                    NULL);
  g_signal_connect ((gpointer) button7, "clicked",
                    G_CALLBACK (on_button7_clicked),
                    NULL);
  g_signal_connect ((gpointer) button5, "clicked",
                    G_CALLBACK (on_button5_clicked),
                    NULL);
  g_signal_connect ((gpointer) button4, "clicked",
                    G_CALLBACK (on_button4_clicked),
                    NULL);
  g_signal_connect ((gpointer) button1, "clicked",
                    G_CALLBACK (on_button1_clicked),
                    NULL);
  g_signal_connect ((gpointer) button3, "clicked",
                    G_CALLBACK (on_button3_clicked),
                    NULL);
  g_signal_connect ((gpointer) button2, "clicked",
                    G_CALLBACK (on_button2_clicked),
                    NULL);
  g_signal_connect ((gpointer) comboboxentry4, "changed",
                    G_CALLBACK (on_comboboxentry4_changed),
                    NULL);
  g_signal_connect ((gpointer) comboboxentry3, "changed",
                    G_CALLBACK (on_comboboxentry3_changed),
                    NULL);
  g_signal_connect ((gpointer) comboboxentry2, "changed",
                    G_CALLBACK (on_comboboxentry2_changed),
                    NULL);
  g_signal_connect ((gpointer) comboboxentry1, "changed",
                    G_CALLBACK (on_comboboxentry1_changed),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
/*  GLADE_HOOKUP_OBJECT_NO_REF (window1, window1, "window1");
  GLADE_HOOKUP_OBJECT (window1, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (window1, textview1, "textview1");
  GLADE_HOOKUP_OBJECT (window1, textview2, "textview2");
  GLADE_HOOKUP_OBJECT (window1, label1, "label1");
  GLADE_HOOKUP_OBJECT (window1, label2, "label2");
  GLADE_HOOKUP_OBJECT (window1, label3, "label3");
  GLADE_HOOKUP_OBJECT (window1, label4, "label4");
  GLADE_HOOKUP_OBJECT (window1, button6, "button6");
  GLADE_HOOKUP_OBJECT (window1, button8, "button8");
  GLADE_HOOKUP_OBJECT (window1, button7, "button7");
  GLADE_HOOKUP_OBJECT (window1, button5, "button5");
  GLADE_HOOKUP_OBJECT (window1, button4, "button4");
  GLADE_HOOKUP_OBJECT (window1, button1, "button1");
  GLADE_HOOKUP_OBJECT (window1, button3, "button3");
  GLADE_HOOKUP_OBJECT (window1, button2, "button2");
  GLADE_HOOKUP_OBJECT (window1, checkbutton4, "checkbutton4");
  GLADE_HOOKUP_OBJECT (window1, checkbutton3, "checkbutton3");
  GLADE_HOOKUP_OBJECT (window1, checkbutton2, "checkbutton2");
  GLADE_HOOKUP_OBJECT (window1, comboboxentry4, "comboboxentry4");
  GLADE_HOOKUP_OBJECT (window1, comboboxentry3, "comboboxentry3");
  GLADE_HOOKUP_OBJECT (window1, comboboxentry2, "comboboxentry2");
  GLADE_HOOKUP_OBJECT (window1, comboboxentry1, "comboboxentry1");
  GLADE_HOOKUP_OBJECT (window1, checkbutton1, "checkbutton1");
*/
  return window1;
}

