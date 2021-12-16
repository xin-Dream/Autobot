#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/src/autobot_gui"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated/lib/python3/dist-packages:/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/build_isolated/autobot_gui/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/build_isolated/autobot_gui" \
    "/usr/bin/python3" \
    "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/src/autobot_gui/setup.py" \
     \
    build --build-base "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/build_isolated/autobot_gui" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated" --install-scripts="/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated/bin"
