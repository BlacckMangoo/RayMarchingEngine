#pragma once

#include <Object.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Triangle : public Object {
public:
    Triangle();
    ~Triangle() override;

    void Init() override;
    void Update() override;
    void Render() override;

private:
    unsigned int VAO, VBO, shaderProgram;
    float rotationAngle;
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;

    void setupShaders();
    void setupGeometry();
};
