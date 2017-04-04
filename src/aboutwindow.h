/*
 * aboutwindow.h
 *
 *  Created on: Apr 3, 2017
 *      Author: justin
 */

#ifndef ABOUTWINDOW_H_
#define ABOUTWINDOW_H_

#include <gtkmm.h>
class AboutWindow : public Gtk::AboutDialog {
public:
	AboutWindow();
	~AboutWindow();
};


#endif /* ABOUTWINDOW_H_ */
