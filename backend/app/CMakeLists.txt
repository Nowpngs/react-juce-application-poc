cmake_minimum_required(VERSION 3.22)

project(ReactJuceGUIApplication VERSION 0.1.0)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/ReactJuceGUIApplication")

juce_add_gui_app(${PROJECT_NAME}
    PRODUCT_NAME "ReactJuceGUIApplication"
)

target_sources(${PROJECT_NAME} PRIVATE
    src/Main.cpp
    src/MainComponent.cpp
    ${INCLUDE_DIR}/MainComponent.h
    ${INCLUDE_DIR}/Util.h
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    juce::juce_gui_extra
    juce::juce_audio_utils
    juce::juce_dsp
    PUBLIC
    juce::juce_recommended_config_flags
    juce::juce_recommended_lto_flags
    juce::juce_recommended_warning_flags
)

target_compile_definitions(${PROJECT_NAME}
    PUBLIC
    JUCE_WEB_BROWSER=1
    JUCE_USE_CURL=0
    JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:ReactJuceGUIApplication,JUCE_PRODUCT_NAME>"
    JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:ReactJuceGUIApplication,JUCE_VERSION>")
