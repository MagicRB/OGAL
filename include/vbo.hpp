#ifndef VBO_HPP
#define VBO_HPP

#include <vector>

#include <GL/glew.h>
#include <GL/gl.h>

namespace OGAL {
    class VBO {
        public:
            VBO();
            ~VBO();

            void bind();

            void set_data(std::vector<GLfloat> data);

            GLuint vbo_id_;
            GLuint size_;

        protected:

        private:
    };
}

#endif //VbO_HPP
