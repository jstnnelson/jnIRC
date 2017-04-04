/*
 * mainwindow.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: justin
 */


#include "mainwindow.h"
#include <gtkmm/paned.h>
#include <gtkmm.h>

MainWindow::MainWindow() : a("Justin"), chat_pane(Gtk::ORIENTATION_VERTICAL){
	set_border_width(10);
	add(main_pane);
	set_default_size(600,400);
	main_pane.pack1(chat_pane, true, false);
	//main_pane.add2(user_list);
	main_pane.pack2(a, false, false);
	chat_pane.pack1(chat_text, true, false);
	chat_text.set_editable(false);
	chat_pane.pack2(msg_entry_box, false, true);
	Glib::RefPtr<Gtk::TextBuffer> p_buffer = chat_text.get_buffer();
	//p_buffer = chat_text.get_buffer();
	//p_buffer->set_text("Lorem Ipsum");

	show_all_children(true);
}

MainWindow::~MainWindow(){

}

