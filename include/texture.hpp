#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <GL/gl.h>

namespace OGAL {
    class texture {
        public:
            texture();
            ~texture();

            void bind();

            void set_data(unsigned char* data, GLuint width, GLuint height);

            GLuint texture_id;
        protected:

        private:

    };
}

#endif //TEXTURE_H
