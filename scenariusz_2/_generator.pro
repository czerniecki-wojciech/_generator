TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += \
    Adaptive.cpp \
    BruteForce.cpp \
    Conservator.cpp \
    Evolution.cpp \
    main.cpp \
    OutputsLimits.cpp \
    PermutationGenerator.cpp \
    PermutationIterator.cpp \
    RepairKit.cpp \
    RepairKitSet.cpp \
    Simulation.cpp \
    SimulationData.cpp \
    SimulationInputDataGenerator.cpp \
    SimulationResult.cpp

HEADERS += \
    Adaptive.h \
    BruteForce.h \
    Conservator.h \
    Element.h \
    Evolution.h \
    MinMaxBoundLimitError.h \
    myTypes.h \
    OutputsLimits.h \
    PermutationGenerator.h \
    PermutationIterator.h \
    RepairKit.h \
    RepairKitSet.h \
    Simulation.h \
    SimulationData.h \
    SimulationInputData.h \
    SimulationInputDataGenerator.h \
    SimulationResult.h

