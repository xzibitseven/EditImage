TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt


INCLUDEPATH += /usr/local/include/opencv4/

LIBS += -lopencv_core \
        -lopencv_imgproc \
        -lopencv_imgcodecs \
        # -lopencv_highgui \
        #-lopencv_objdetect

LIBS += -lstdc++fs

SOURCES += \
        main.cpp \
        image.cpp

HEADERS += \
    image.hpp \
    smoothing.hpp \
    medianblurring.hpp \
    averaging.hpp \
    gaussianblurring.hpp \
    bilateralfiltering.hpp

