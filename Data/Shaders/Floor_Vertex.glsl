#version 330

layout (location = 0) in vec3 inVertexPosition;

out vec3 normals;
out vec3 fragPos;

uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
uniform mat4 projMatrix;

void main()
{
    gl_Position = projMatrix * viewMatrix * modelMatrix *
                   vec4(inVertexPosition.x,
                        inVertexPosition.y,
                        inVertexPosition.z,
                        1.0);
    fragPos = vec3(modelMatrix * vec4(inVertexPosition, 1.0));
    normals = mat3(transpose(inverse(modelMatrix))) * vec3(0.0, 1.0, 0.0);
}
