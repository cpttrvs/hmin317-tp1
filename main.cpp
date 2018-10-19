/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QApplication>
#include <QLabel>
#include <QSurfaceFormat>

#ifndef QT_NO_OPENGL
#include "mainwidget.h"
#include "calendar.h"
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    QSurfaceFormat::setDefaultFormat(format);

    app.setApplicationName("cube");
    app.setApplicationVersion("0.1");
#ifndef QT_NO_OPENGL
    Calendar calendar(5);

    MainWidget widget1; widget1.setSeason(0);
    widget1.show();
    MainWidget widget2; widget2.setSeason(1);
    widget2.show();
    MainWidget widget3; widget3.setSeason(2);
    widget3.show();
    MainWidget widget4; widget4.setSeason(3);
    widget4.show();

    //calendar to widgets
    QObject::connect(&calendar, SIGNAL(seasonChanged()),
                     &widget1, SLOT(changeSeason()));
    QObject::connect(&calendar, SIGNAL(seasonChanged()),
                     &widget2, SLOT(changeSeason()));
    QObject::connect(&calendar, SIGNAL(seasonChanged()),
                     &widget3, SLOT(changeSeason()));
    QObject::connect(&calendar, SIGNAL(seasonChanged()),
                     &widget4, SLOT(changeSeason()));

    //widgets to calendar
    QObject::connect(&widget1, SIGNAL(seasonChanged(int)),
                     &calendar, SLOT(season(int)));
    QObject::connect(&widget2, SIGNAL(seasonChanged(int)),
                     &calendar, SLOT(season(int)));
    QObject::connect(&widget3, SIGNAL(seasonChanged(int)),
                     &calendar, SLOT(season(int)));
    QObject::connect(&widget4, SIGNAL(seasonChanged(int)),
                     &calendar, SLOT(season(int)));

    calendar.startCalendar();

    /*
    MainWidget widget10(10);
    widget10.show();
    MainWidget widget100(100);
    widget100.show();
    MainWidget widget1000(1000);
    widget1000.show();
    */

#else
    QLabel note("OpenGL Support required");
    note.show();
#endif
    return app.exec();
}
