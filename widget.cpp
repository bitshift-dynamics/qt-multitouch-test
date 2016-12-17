//! \file widget.cpp
//! \author Alexander Nassian <nassian@bitshift-dynamics.com>
//!         Copyright (c) 2014 bitshift dynamics GmbH

#include "widget.h"

#include <QtWidgets/QGesture>
#include <QtWidgets/QGestureEvent>
#include <QtCore/QDebug>


Widget::Widget(QWidget* parent) :
	QWidget(parent)
{
	// Grab all currently supported gestures in this widget.
	QList<Qt::GestureType> gestures;
	gestures << Qt::TapGesture
		 << Qt::TapAndHoldGesture
		 << Qt::PanGesture
		 << Qt::PinchGesture
		 << Qt::SwipeGesture;

	foreach (Qt::GestureType gesture, gestures)
	    grabGesture(gesture);
}

bool Widget::event(QEvent* ev)
{
	if (ev->type() != QEvent::Gesture)
		return QWidget::event(ev);

	QGestureEvent* gestureEvent = static_cast<QGestureEvent*>(ev);
	if (gestureEvent == nullptr)
		return QWidget::event(ev);

	// Do some information output for all recognized gestures.
	foreach (QGesture* gesture, gestureEvent->gestures()) {
		switch (gesture->gestureType()) {
		case Qt::TapGesture: {
			qDebug() << "Tap gesture";

			QTapGesture* tap =
					qobject_cast<QTapGesture*>(gesture);
			qDebug() << "Position:" << tap->position();
			qDebug() << "";
			break;
		}

		case Qt::TapAndHoldGesture: {
			qDebug() << "Tap and Hold gesture";

			QTapAndHoldGesture* tapAndHold =
					qobject_cast<QTapAndHoldGesture*>(
						gesture);
			qDebug() << "Position:" << tapAndHold->position();
			qDebug() << "";
			break;
		}

		case Qt::PanGesture: {
			qDebug() << "Pan gesture";

			QPanGesture* pan =
					qobject_cast<QPanGesture*>(gesture);
			qDebug() << "Delta:" << pan->delta();
			qDebug() << "Offset:" << pan->offset();
			qDebug() << "Acceleration:" << pan->acceleration();
			qDebug() << "";
			break;
		}

		case Qt::PinchGesture: {
			qDebug() << "Pinch gesture";

			QPinchGesture* pinch =
					qobject_cast<QPinchGesture*>(gesture);
			qDebug() << "Center point:" << pinch->centerPoint();
			qDebug() << "Rotation angle:"
				 << pinch->rotationAngle();
			qDebug() << "Scale factor:" << pinch->scaleFactor();
			qDebug() << "";
			break;
		}

		case Qt::SwipeGesture: {
			qDebug() << "Swipe gesture";

			QSwipeGesture* swipe =
					qobject_cast<QSwipeGesture*>(gesture);
			qDebug() << "Angle:" << swipe->swipeAngle();
			qDebug() << "Horizontal direction:"
				 << swipe->horizontalDirection();
			qDebug() << "Vertical direction:"
				 << swipe->verticalDirection();
			qDebug() << "";
			break;
		}

		default:
			qDebug() << "Unknown gesture";
			qDebug() << "";
			break;
		}
	}
}

void Widget::mousePressEvent(QMouseEvent* ev)
{
	qDebug() << "Mouse press";
	qDebug() << "Local position:" << ev->pos();
	qDebug() << "Global position:" << ev->globalPos();
	qDebug() << "Buttons:" << ev->buttons();
	qDebug() << "";
}

void Widget::mouseMoveEvent(QMouseEvent* ev)
{
	qDebug() << "Mouse move";
	qDebug() << "Local position:" << ev->pos();
	qDebug() << "Global position:" << ev->globalPos();
	qDebug() << "Buttons:" << ev->buttons();
	qDebug() << "";
}

void Widget::mouseReleaseEvent(QMouseEvent* ev)
{
	qDebug() << "Mouse release";
	qDebug() << "Local position:" << ev->pos();
	qDebug() << "Global position:" << ev->globalPos();
	qDebug() << "Buttons:" << ev->buttons();
	qDebug() << "";
}
