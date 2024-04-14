#include "Application.h"
#include <fstream>
#include <iostream>

Application::Application(){
    clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
}

void Application::Run(){    
    ImGui::Begin("NDD");                          // Create a window called "Hello, world!" and append into it.
    // ImGui::ShowDemoWindow();
    ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
    ImGui::SameLine();
    if(ImGui::Button("upload"))
        upload();
    if(ImGui::Button("pin 2")){
        add(2);
    }
    ImGui::SameLine();
    if(ImGui::Button("pin 3"))
        add(3);
    ImGui::SameLine();
    if(ImGui::Button("pin 4"))
        add(4);
    ImGui::SameLine();
    if(ImGui::Button("pin 5"))
        add(5);
    ImGui::SameLine();
    if(ImGui::Button("pin 6"))
        add(6);
    ImGui::SameLine();
    if(ImGui::Button("pin 7"))
        add(7);
    ImGui::SameLine();
    if(ImGui::Button("pin 8"))
        add(8);
    ImGui::SameLine();
    if(ImGui::Button("pin 9"))
        add(9);
    ImGui::SameLine();
    if(ImGui::Button("pin 10"))
        add(10);
    ImGui::SameLine();
    if(ImGui::Button("pin 11"))
        add(11);
    ImGui::SameLine();
    if(ImGui::Button("pin 12"))
        add(12);
    ImGui::SameLine();
    if(ImGui::Button("pin 13"))
        add(13);
    // ImGui::InputInt("no of pins", &counter);
    ImGui::End();
}

void Application::upload(){
    std::string code= R"(#include <Arduino.h>
                    int pins[12]= {2,3,4,5,6,7,8,9,10,11,12,13}; 

                    void setup() {
                        for(int i = 0; 12>i; i++){
                            pinMode(pins[i],OUTPUT); 
                        }
                    }

                    void loop() {)" + strip + R"(
                    })";
    std::ofstream arduinoCode("led.cpp", std::ios::out);
    arduinoCode<<code<<std::endl;
    system(command.c_str());
}

void Application::add(int pinNum){
    strip += R"(digitalWrite()" + std::to_string(pinNum) + R"(, HIGH);
                )";
}