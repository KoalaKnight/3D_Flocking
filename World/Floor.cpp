#include "Floor.h"

Floor::Floor(float width, float height, Vector3 pos)
{
    this->position = pos;
    m_vertexPositions =
    {
        0.0, 0.0, 0.0,
        width, 0.0, 0.0,
        width, 0.0, height,
        0.0, 0.0, height
    };
    m_indices =
    {
        0, 1, 2,
        0, 3, 2
    };

    m_indicesCount = 6;

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);

    addVBO(3, m_vertexPositions);
    addEBO(m_indices);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Floor::~Floor()
{
    glDeleteVertexArrays(1, &m_vao);
    glDeleteBuffers(m_buffers.size(), m_buffers.data());
}

void Floor::bind() const
{
    glBindVertexArray(m_vao);
}

void Floor::unbind() const
{
    glBindVertexArray(0);
}

GLuint Floor::getIndicesCount() const
{
    return m_indicesCount;
}

void Floor::addVBO(int dim, const std::vector<GLfloat>& data)
{
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER,
                 data.size() * sizeof(data[0]),
                 data.data(),
                 GL_STATIC_DRAW);
    glVertexAttribPointer(m_vboCount,
                          dim,
                          GL_FLOAT,
                          GL_FALSE,
                          0,
                          (GLvoid*) 0);

    glEnableVertexAttribArray(m_vboCount++);

    m_buffers.push_back(vbo);
}

void Floor::addEBO(const std::vector<GLuint>& indices)
{
    GLuint ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 indices.size() * sizeof (indices[0]),
                 indices.data(),
                 GL_STATIC_DRAW);
    m_buffers.push_back(ebo);
}
