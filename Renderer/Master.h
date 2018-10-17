#ifndef MASTER_H_INCLUDED
#define MASTER_H_INCLUDED

#include "Model_Renderer.h"
#include "Multiple_Models_Renderer.h"
#include "Floor_Renderer.h"
#include "../Glm_Common.h"

class Camera;
class Model;
class Floor;

namespace Renderer
{
    class Master
    {
        public:
            void clear();

            void update(const Camera& camera, Vector3 lightPos);

            void draw(const Model& model);
            void draw(Multiple_Models& model);
            void draw(const Floor& model);
        private:
            Model_Renderer m_modelRenderer;
            Multiple_Models_Renderer m_multiModelRenderer;
            Floor_Renderer m_floorRenderer;
    };
}

#endif // MASTER_H_INCLUDED
