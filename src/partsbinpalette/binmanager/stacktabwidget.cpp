/*******************************************************************

Part of the Fritzing project - http://fritzing.org
Copyright (c) 2007-2010 Fachhochschule Potsdam - http://fh-potsdam.de

Fritzing is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Fritzing is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Fritzing.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************

$Revision: 5571 $:
$Author: cohen@irascible.com $:
$Date: 2011-10-30 13:03:29 -0700 (Sun, 30 Oct 2011) $

********************************************************************/

#include <QMouseEvent>

#include "stacktabwidget.h"
#include "stacktabbar.h"
#include "../../debugdialog.h"

StackTabWidget::StackTabWidget(QWidget *parent) : QTabWidget(parent) {
	setElideMode(Qt::ElideRight);

	setTabBar(new StackTabBar(this));

	connect(
		this, SIGNAL(currentChanged(int)),
		this, SLOT(informCurrentChanged(int))
	);
	connect(
		this, SIGNAL(tabCloseRequested(int)),
		this, SLOT(informTabCloseRequested(int))
	);
}

StackTabBar *StackTabWidget::stackTabBar() {
	return qobject_cast<StackTabBar*>(tabBar());
}

void StackTabWidget::informCurrentChanged(int index) {
	emit currentChanged(this,index);
}

void StackTabWidget::informTabCloseRequested(int index) {
	emit tabCloseRequested(this, index);
}

