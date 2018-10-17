#ifndef MULTIPLE_MODELS_H_INCLUDED
#define MULTIPLE_MODELS_H_INCLUDED

#include <vector>
#include <string>

#include "Model.h"

class Multiple_Models
{
public:
    Multiple_Models(std::string fileName, float scale);

    std::vector<Vector3> m_positions;
    std::vector<Vector3> m_rotations;
    Model model;
};

#endif // MULTIPLE_MODELS_H_INCLUDED
