#pragma once
#include <glm/glm.hpp>

#include "Window.h"
#include "GLFW/glfw3.h"
#include <unordered_map>


class InputManager {

public:

    explicit InputManager(const Window& wind ) {

        window = wind.GetGLFWWindow();


    };

    std::unordered_map<int, bool> keyPrevStates;
    std::unordered_map<int, bool> mousePrevStates;

    void Update() {
        // Store current states as previous states for next frame
        for (auto& [key, state] : keyPrevStates) {
            state = glfwGetKey(window, key) == GLFW_PRESS;
        }

        for (auto& [button, state] : mousePrevStates) {
            state = glfwGetMouseButton(window, button) == GLFW_PRESS;
        }
    }


    [[nodiscard]] bool IsKeyDown(int key) const {
        return glfwGetKey(window, key) == GLFW_PRESS;
    }

    bool IsKeyPressed(const int key) {
        const bool currentState = glfwGetKey(window, key) == GLFW_PRESS;
        const auto it = keyPrevStates.find(key);
        const bool prevState = it != keyPrevStates.end() ? it->second : false;

        // If this is the first time checking this key, add it to the map
        if (it == keyPrevStates.end()) {
            keyPrevStates[key] = false;
        }

        return currentState && !prevState;
    }

    bool IsKeyReleased(const int key) {
        const bool currentState = glfwGetKey(window, key) == GLFW_PRESS;
        const auto it = keyPrevStates.find(key);
        const bool prevState = it != keyPrevStates.end() ? it->second : false;

        // If this is the first time checking this key, add it to the map
        if (it == keyPrevStates.end()) {
            keyPrevStates[key] = false;
        }

        return !currentState && prevState;
    }

    // Mouse
    [[nodiscard]] bool IsMouseButtonDown(const int button) const {
        return glfwGetMouseButton(window, button) == GLFW_PRESS;
    }

    bool IsMouseButtonPressed(const int button) {
        const bool currentState = glfwGetMouseButton(window, button) == GLFW_PRESS;
        const auto it = mousePrevStates.find(button);
        const bool prevState = it != mousePrevStates.end() ? it->second : false;

        if (it == mousePrevStates.end()) {
            mousePrevStates[button] = false;
        }

        return currentState && !prevState;
    }

    [[nodiscard]] glm::vec2 GetMousePosition() const {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        return glm::vec2(static_cast<float>(xpos), static_cast<float>(ypos));
    }


private:
     GLFWwindow* window ;

};
