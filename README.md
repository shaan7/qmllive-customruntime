# Example to demonstrate Custom Runtime in QML Live

## Build and install QML Live:
* Get the source code from https://github.com/qtproject/qt-apps-qmllive
* cd qt-apps-qmllive && mkdir build && cd build
* qmake .. && make
* make install

## Use Custom Runtime
* Build and run customruntime.pro either from the command line or Qt Creator
* Once the customruntime executable is running, run the bench tool from QML Live
* Click "Open Workspace" in bench and select the source dir for customruntime (this project)
* Add a host in bench by going to Preferences (localhost:10234)
* The host should show Online, hit the Publish button and it should reload
* Any changes made to main.qml (or other QML files) will automatically reload if bench is running
