//! \file widget.h
//! \author Alexander Nassian <nassian@bitshift-dynamics.com>
//!         Copyright (c) 2014 bitshift dynamics GmbH

#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QWidget>


class Widget : public QWidget
{
	Q_OBJECT

public:
	explicit Widget(QWidget* parent = nullptr);

protected:
	bool event(QEvent* ev);
	void mousePressEvent(QMouseEvent* ev);
	void mouseMoveEvent(QMouseEvent* ev);
	void mouseReleaseEvent(QMouseEvent* ev);
};

#endif // WIDGET_H
