//! \file main.cpp
//! \author Alexander Nassian <nassian@bitshift-dynamics.com>
//!         Copyright (c) 2014 bitshift dynamics GmbH
//!
//! \brief This is a sample application to verify sufficient multitouch
//!        gesture support using Qt's default API.
//!
//! This application creates a fullscreen window. Any mouse input and
//! recognized touch gestures will be printed to stdout.
//!
//! This application may be also useful when testing custom gesture
//! recognizer modules.

#include <QtWidgets/QApplication>

#include "widget.h"


int main(int argc, char** argv)
{
	QApplication a(argc, argv);

	Widget w;
	w.showFullScreen();

	return a.exec();
}
