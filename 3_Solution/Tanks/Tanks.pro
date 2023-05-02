 QT       += core gui \
          multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Base.cpp \
    BotTank.cpp \
    CamouflageObject.cpp \
    EnemyBullet.cpp \
    Game.cpp \
    GameOver.cpp \
    GamePaused.cpp \
    Health.cpp \
    IndestructibleObject.cpp \
    NormalObject.cpp \
    PlayerBullet.cpp \
    PlayerTank.cpp \
    Score.cpp \
    iBullet.cpp \
    iObject.cpp \
    iTank.cpp \
    main.cpp

HEADERS += \
    Base.h \
    BotTank.h \
    CamouflageObject.h \
    EnemyBullet.h \
    Game.h \
    GameOver.h \
    GamePaused.h \
    Health.h \
    IndestructibleObject.h \
    NormalObject.h \
    PlayerBullet.h \
    PlayerTank.h \
    Score.h \
    iBullet.h \
    iObject.h \
    iTank.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
