#include "Floor_Shader.h"

namespace Shader
{
    Floor_Shader::Floor_Shader()
    :   Shader_Program("Floor_Vertex", "Floor_Fragment")
    {
        getUniformLocations();
    }

    void Floor_Shader::setViewMatrix(const Matrix4& matrix)
    {
        loadMatrix4(m_locationViewMatrix, matrix);
    }

    void Floor_Shader::setModelMatrix(const Matrix4& matrix)
    {
        loadMatrix4(m_locationModelMatrix, matrix);
    }

    void Floor_Shader::setProjMatrix(const Matrix4& matrix)
    {
        loadMatrix4(m_locationProjMatrix, matrix);
    }

    void Floor_Shader::setLightPos(const Vector3& vec)
    {
        loadVector3(m_locationLightPos, vec);
    }

    void Floor_Shader::setViewPos(const Vector3& vec)
    {
        loadVector3(m_locationViewPos, vec);
    }

    void Floor_Shader::getUniformLocations()
    {
        m_locationViewMatrix = glGetUniformLocation(getID(), "viewMatrix");
        m_locationModelMatrix = glGetUniformLocation(getID(), "modelMatrix");
        m_locationProjMatrix = glGetUniformLocation(getID(), "projMatrix");
        m_locationLightPos = glGetUniformLocation(getID(), "lightPos");
        m_locationViewPos = glGetUniformLocation(getID(), "viewPos");
    }
}
