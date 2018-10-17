#include "Floor_Renderer.h"

#include "../Maths/Matrix.h"

namespace Renderer
{
    void Floor_Renderer::draw(const Floor& floor)
    {
        m_floors.push_back(&floor);
    }

    void Floor_Renderer::update(const Camera& camera, Vector3 lightPos)
    {
        m_shader.bind();
        m_shader.setViewMatrix(camera.getViewMatrix());
        m_shader.setProjMatrix(camera.getProjectionMatrix());
        m_shader.setLightPos(lightPos);
        m_shader.setViewPos(camera.position);

        for(auto& floor : m_floors)
        {
            floor->bind();
            m_shader.setModelMatrix(Maths::createModelMatrix(*floor));

            glDrawElements(GL_TRIANGLES, floor->getIndicesCount(), GL_UNSIGNED_INT, nullptr);

            floor->unbind();
        }
        m_shader.unbind();
        m_floors.clear();
    }
}
