#ifndef FLOOR_RENDERER_H_INCLUDED
#define FLOOR_RENDERER_H_INCLUDED

#include <vector>

#include "../World/Floor.h"
#include "../Camera.h"
#include "../Shaders/Floor_Shader.h"
#include "../Glm_Common.h"

namespace Renderer
{
    class Floor_Renderer
    {
    public:
        void draw(const Floor& floor);
        void update(const Camera& camera, Vector3 lightPos);
    private:
        std::vector<const Floor*> m_floors;
        Shader::Floor_Shader m_shader;
    };
}

#endif // FLOOR_RENDERER_H_INCLUDED
