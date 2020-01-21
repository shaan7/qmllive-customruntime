#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <qmllive/livenodeengine.h>
#include <qmllive/remotereceiver.h>
#include <qmllive/qmllive.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load("qrc:/main.qml");

#if defined(QT_NO_DEBUG)
    qWarning() << "QML Live support was disabled at compile time";
#else
    LiveNodeEngine node;

    // Let QML Live know your runtime
    node.setQmlEngine(&engine);

    // Allow it to display QML components with non-QQuickWindow root object
    QQuickView fallbackView(&engine, 0);
    node.setFallbackView(&fallbackView);

    // Tell it where file updates should be stored relative to
    node.setWorkspace(app.applicationDirPath(),
                      LiveNodeEngine::AllowUpdates | LiveNodeEngine::UpdatesAsOverlay);

    // Listen to IPC call from remote QML Live Bench
    RemoteReceiver receiver;
    receiver.registerNode(&node);
    receiver.listen(10234);

    // Advanced use: let it know the initially loaded QML component (do this
    // only after registering to receiver!)
    auto window = qobject_cast<QQuickWindow *>(engine.rootObjects().first());
    QList<QQmlError> warnings;
    node.usePreloadedDocument("qml/main.qml", window, warnings);
#endif

    return app.exec();
}
