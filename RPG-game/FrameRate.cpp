#include "FrameRate.h"
#include<iostream>

FrameRate::FrameRate() : FPScounter(font)
{
    timer = 0;
    FPSdisplay = 0;
}

void FrameRate::Initialize() {
    
}

void FrameRate::Load() {
    if (font.openFromFile("Assets/Fonts/minecraft_font.ttf")) {
        std::cout << "font loaded" << std::endl;
    }
    else {
        std::cout << "font did not load" << std::endl;
    }
    FPScounter.setFont(font);
}

void FrameRate::Update(double deltatime) {
    timer += deltatime;
    FPSdisplay++;
    if (timer >= 250.0f){
        //std::string FPSstring = "FPS ::" + std::to_string(int(1000.0f / deltatime));
        std::string FPSstring = "FPS ::" + std::to_string(FPSdisplay*4);
        FPScounter.setString(FPSstring);
        FPSdisplay = 0;
        timer = 0;
    }
    }


void FrameRate::Draw(sf::RenderWindow& window) {
    window.draw(FPScounter);
}