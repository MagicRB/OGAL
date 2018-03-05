#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <GL/gl.h>

namespace OGAL {
    class Texture {
        public:
            Texture();
            ~Texture();

            /// Binds this Texture as the current one
            void bind();

            /// Sets data of this Texture2D, data should be in the RGBA format
            void set_data(unsigned char* data, GLuint width, GLuint height);

            GLuint texture_id_;
        protected:

        private:

    };
}

#endif //TEXTURE_H
