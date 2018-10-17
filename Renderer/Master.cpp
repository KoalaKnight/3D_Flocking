#include "Master.h"

#include "../Display.h"

namespace Renderer
{
    void Master::clear()
    {
        Display::clear();
    }

    void Master::update(const Camera& camera, Vector3 lightPos)
    {
        m_modelRenderer.update(camera, lightPos);
        m_multiModelRenderer.update(camera, lightPos);
        m_floorRenderer.update(camera, lightPos);

        Display::update();
    }

    void Master::draw(const Model& model)
    {
        m_modelRenderer.draw(model);
    }

    void Master::draw(Multiple_Models& model)
    {
        m_multiModelRenderer.draw(model);
    }

    void Master::draw(const Floor& model)
    {
        m_floorRenderer.draw(model);
    }
}
