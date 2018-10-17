#ifndef FLOOR_SHADER_H_INCLUDED
#define FLOOR_SHADER_H_INCLUDED

#include "Shader_Program.h"

namespace Shader
{
    class Floor_Shader : public Shader_Program
    {
    public:
        Floor_Shader();

        void setViewMatrix(const Matrix4& matrix);
        void setModelMatrix(const Matrix4& matrix);
        void setProjMatrix(const Matrix4& matrix);
        void setLightPos(const Vector3& vec);
        void setViewPos(const Vector3& vec);
    private:
        virtual void getUniformLocations() override;

        GLuint m_locationViewMatrix = 0;
        GLuint m_locationModelMatrix = 0;
        GLuint m_locationProjMatrix = 0;
        GLuint m_locationLightPos = 0;
        GLuint m_locationViewPos = 0;
    };
}

#endif // FLOOR_SHADER_H_INCLUDED
