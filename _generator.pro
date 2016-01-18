TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    SimulationInputDataGenerator.cpp \
    OutputsLimits.cpp \
    SimulationData.cpp \
    RepairKitSet.cpp \
    RepairKit.cpp \
    PermutationIterator.cpp \
    Simulation.cpp

HEADERS += \
    myTypes.h \
    Element.h \
    SimulationInputDataGenerator.h \
    OutputsLimits.h \
    MinMaxBoundLimitError.h \
    SimulationInputData.h \
    SimulationData.h \
    RepairKitSet.h \
    RepairKit.h \
    PermutationIterator.h \
    Simulation.h

