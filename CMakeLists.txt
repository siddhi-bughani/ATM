cmake_minimum_required(VERSION 3.19)
project(ATM LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(ATM
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

    balance.h balance.cpp balance.ui
    withdraw.h withdraw.cpp withdraw.ui
    deposit.h deposit.cpp deposit.ui
    account.h account.cpp
    menu.h menu.cpp menu.ui
    accountmanager.h accountmanager.cpp


)

target_link_libraries(ATM
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS ATM
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET ATM
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
