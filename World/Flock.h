#ifndef FLOCK_H_INCLUDED
#define FLOCK_H_INCLUDED

#include <string>
#include <vector>

#include "../Models/Multiple_Models.h"
#include "../Glm_Common.h"

class Flock
{
public:
    Flock(std::string fileName, float scale, int number, Vector3 boxPos, float boxWidth_x, float boxHeight_y, float boxLength_z);

    void update(float dt);

    Multiple_Models m_multiModels;
private:
    void initPositions(int number);
    std::vector<int> getCloseBoids(int index);
    float getRotation(float x, float y);
    void updateVelocities(float dt);

    std::vector<Vector3> m_positions;
    std::vector<Vector2> m_velocities;
    Vector3 m_boxPos;
    Vector3 m_boxDimensions;
    const float m_radiusOfInfluence = 2.0;
    const float m_speed = 1.0;
    const float m_cohesionWeight = 2.0;
    const float m_separationWeight = 2.2;
    const float m_alignmentWeight = 1.0;
};

#endif // FLOCK_H_INCLUDED
