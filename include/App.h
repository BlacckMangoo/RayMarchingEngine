#pragma once
#include "Window.h"
#include <memory>
#include <vector>

#include "InputManager.h"
#include "Triangle.h"
#include "Object.h"
#include "Object.h"
#include <vector>

class App {

    public:

    void Initialize();
    void Run();
    void Update();


private:
    std::unique_ptr<Window> window  = nullptr;
    std::unique_ptr<InputManager> inputManager = nullptr;
    std::vector<std::unique_ptr<Object>> objects;

};
