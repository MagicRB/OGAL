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

            /// Just binds this VBO as the current one
            void bind();

            /// Sets data of explicitly this VBO, the bind function is executed automaticly,
            /// no need to bind this VBO manually
            void set_data(std::vector<GLfloat> data);


            /// ID of this VBO
            GLuint vbo_id_;

            /// Size of this VBO
            GLuint size_;

        protected:

        private:
    };
}

#endif //VbO_HPP
