//
// Created by lenovo on 23-10-2025.
//

#include <App.h>
#include <Window.h>
#include <memory>
#include <InputManager.h>
#include <Object.h>\

void App::Initialize() {
    window =  std::make_unique<Window>(1920,1080,"RayMarching Engine");
    inputManager = std::make_unique<InputManager>(*window);

    // Create triangle and push to objects vector
    auto triangle = std::make_unique<Triangle>();
    triangle->Init();
    objects.push_back(std::move(triangle));
}

void App::Run() {

    while (!window->ShouldClose()) {
        Update();
    }
}

void App::Update() {
    inputManager->Update();

    // Begin frame - clear screen
    window->BeginFrame();

    // Update and render all objects
    for (auto& obj : objects) {
        obj->Update();
        obj->Render();
    }

    // End frame - present to screen
    window->EndFrame();
}