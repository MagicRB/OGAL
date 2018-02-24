#ifndef VBO_HPP
#define VBO_HPP

#include <vector>

#include <GL/glew.h>
#include <GL/gl.h>

namespace OGAL {
    class vbo {
        public:
            vbo();
            ~vbo();

            void bind();

            void set_data(std::vector<GLfloat> data);

            GLuint vbo_id;
            GLuint size;

        protected:

        private:
    };
}

#endif //VbO_HPP
