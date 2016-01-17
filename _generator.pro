TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    SimulationInputDataGenerator.cpp \
    OutputsLimits.cpp

HEADERS += \
    SimulationData.h \
    myTypes.h \
    Element.h \
    SimulationInputDataGenerator.h \
    OutputsLimits.h \
    MinMaxBoundLimitError.h

