#ifndef FLOOR_H_INCLUDED
#define FLOOR_H_INCLUDED

#include <vector>
#include <GL/glew.h>

#include "../Entity.h"
#include "../Glm_Common.h"

class Floor : public Entity
{
public:
    Floor(float width, float height, Vector3 pos);
    ~Floor();

    void bind() const;
    void unbind() const;
    GLuint getIndicesCount() const;
private:
    void addVBO(int dim, const std::vector<GLfloat>& data);
    void addEBO(const std::vector<GLuint>& indices);

    std::vector<GLuint> m_buffers;
    std::vector<GLfloat> m_vertexPositions;
    std::vector<GLuint> m_indices;
    GLuint m_vao;
    GLuint m_vboCount = 0;
    GLuint m_indicesCount = 0;
};

#endif // FLOOR_H_INCLUDED
