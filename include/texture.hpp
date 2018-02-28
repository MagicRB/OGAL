#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <GL/gl.h>

namespace OGAL {
    class Texture {
        public:
            Texture();
            ~Texture();

            void bind();

            void set_data(unsigned char* data, GLuint width, GLuint height);

            GLuint texture_id_;
        protected:

        private:

    };
}

#endif //TEXTURE_H
