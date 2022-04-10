#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuickControls2/QQuickStyle>

#include "treeitem.h"
#include "treemodel.h"

#include "eventmodel.h"
#include "proxymodel.h"
#include "cellmodel.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<TreeModel>("TreeModel", 1, 0, "TreeModel");
    //qmlRegisterType<TreeItem>("TreeItem", 1, 0, "TreeItem");


    qmlRegisterType<ProxyModel>("ProxyModel", 1, 0, "ProxyModel");
    qmlRegisterType<EventModel>("EventModel", 1, 0, "EventModel");
    qmlRegisterType<CellModel>("CellModel", 1, 0, "CellModel");

    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
