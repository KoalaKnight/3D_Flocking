#include "Flock.h"

#include <math.h>

#include "../Util/Random.h"

Flock::Flock(std::string fileName, float scale, int number, Vector3 boxPos, float boxWidth_x, float boxHeight_y, float boxLength_z)
:   m_multiModels(fileName, scale)
,   m_boxPos(boxPos)
,   m_boxDimensions(boxWidth_x, boxHeight_y, boxLength_z)
{
    initPositions(number);
}

void Flock::update(float dt)
{
    updateVelocities(dt);

    for(int i = 0; i < m_positions.size(); i++)
    {
        m_positions[i].x += m_velocities[i].x * dt * m_speed;
        m_positions[i].z += m_velocities[i].y * dt * m_speed;
    }
    m_multiModels.m_positions = m_positions;
    for(int i = 0; i < m_velocities.size(); i++)
    {
        m_multiModels.m_rotations[i].y = getRotation(m_velocities[i].x, m_velocities[i].y);
    }
}

void Flock::updateVelocities(float dt)
{
    for(int i = 0; i < m_positions.size(); i++)
    {
        //If outside bounds
        if(m_positions[i].x > m_boxPos.x + m_boxDimensions.x ||
           m_positions[i].x < m_boxPos.x ||
           m_positions[i].z > m_boxPos.z + m_boxDimensions.z ||
           m_positions[i].z < m_boxPos.z)
        {
            if(m_positions[i].x > m_boxPos.x + m_boxDimensions.x)
            {
                m_positions[i].x = m_boxPos.x + m_boxDimensions.x;
                m_velocities[i].x *= -1.0;
            }
            else if(m_positions[i].x < m_boxPos.x)
            {
                m_positions[i].x = m_boxPos.x;
                m_velocities[i].x *= -1.0;
            }
            if(m_positions[i].z > m_boxPos.z + m_boxDimensions.z)
            {
                m_positions[i].z = m_boxPos.z + m_boxDimensions.z;
                m_velocities[i].y *= -1.0;
            }
            else if(m_positions[i].z < m_boxPos.z)
            {
                m_positions[i].z = m_boxPos.z;
                m_velocities[i].y *= -1.0;
            }
        }
        else
        {
            std::vector<int> indices = getCloseBoids(i);
            if(indices.size() > 0)
            {
                //Cohesion
                Vector2 v = Vector2(0.0, 0.0);
                for(int j = 0; j < indices.size(); j++)
                {
                    v.x += m_positions[indices[j]].x;
                    v.y += m_positions[indices[j]].z;
                }
                v *= (1.0f / (float)indices.size());
                v.x = v.x - m_positions[i].x;
                v.y = v.y - m_positions[i].z;
                v *= m_cohesionWeight * dt;
                m_velocities[i] += v;
                //Separation
                v = Vector2(0.0, 0.0);
                for(int j = 0; j < indices.size(); j++)
                {
                    v.x += m_positions[i].x - m_positions[indices[j]].x;
                    v.y += m_positions[i].z - m_positions[indices[j]].z;
                }
                v *= (1.0f / (float)indices.size());
                v *= m_separationWeight * dt;
                m_velocities[i] += v;
                //Alignment
                v = Vector2(0.0, 0.0);
                for(int j = 0; j < indices.size(); j++)
                {
                    v.x += m_velocities[indices[j]].x;
                    v.y += m_velocities[indices[j]].y;
                }
                v *= (1.0f / (float)indices.size());
                v *= m_alignmentWeight * dt;
                m_velocities[i] += v;

                m_velocities[i] = glm::normalize(m_velocities[i]);
            }
        }
    }
}

void Flock::initPositions(int number)
{
    Random::init();
    for(int i = 0; i < number; i++)
    {
        m_positions.push_back(Vector3(Random::floatInRange(m_boxPos.x, m_boxPos.x + m_boxDimensions.x),
                                      (m_boxDimensions.y / 2.0) + m_boxPos.y,
                                      Random::floatInRange(m_boxPos.z, m_boxPos.z + m_boxDimensions.z)));
        m_velocities.push_back(glm::normalize(Vector2(Random::floatInRange(-1.0, 1.0),
                                                      Random::floatInRange(-1.0, 1.0))));
        m_multiModels.m_rotations.push_back(Vector3(0.0, getRotation(m_velocities[i].x, m_velocities[i].y), 0.0));
    }
}

std::vector<int> Flock::getCloseBoids(int index)
{
    std::vector<int> result;
    for(int i = 0; i < m_positions.size(); i++)
    {
        if(i != index)
        {
            if(fabs(m_positions[index].x - m_positions[i].x) <= m_radiusOfInfluence &&
               //fabs(m_positions[index].y - m_positions[i].y) <= m_radiusOfInfluence &&
               fabs(m_positions[index].z - m_positions[i].z) <= m_radiusOfInfluence)
               {
                   result.push_back(i);
               }
        }
    }
    return result;
}

float Flock::getRotation(float x, float y)
{
    float result = 0;
    if(x > 0 && y > 0)
    {
        result = atan(x / y) * 180.0 / 3.14159265;
        result += 180;
    }
    else if(x > 0 && y < 0)
    {
        result = atan(x / y) * 180.0 / 3.14159265;
    }
    else if(x < 0 && y > 0)
    {
        result = atan(x / y) * 180.0 / 3.14159265;
        result += 180;
    }
    else if(x < 0 && y < 0)
    {
        result = atan(x / y) * 180.0 / 3.14159265;
    }
    else if(x == 0)
    {
        if(y > 0)
        {
            result = 180.0;
        }
        else
        {
            result = 0.0;
        }
    }
    else
    {
        if(x > 0)
        {
            result = 270.0;
        }
        else
        {
            result = 90.0;
        }
    }
    result += 360.0;

    return result;
}
