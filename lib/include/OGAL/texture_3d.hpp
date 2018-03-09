//
// Created by Magic_RB on 3/8/2018.
//

#ifndef OGAL_TEXTURE_3D_HPP
#define OGAL_TEXTURE_3D_HPP

#include <GL/glew.h>

namespace OGAL {
    class Texture3D {
    public:
        Texture3D();
        
        ~Texture3D();
        
        /// Binds this Texture as the current one
        void bind();
        
        /// Sets data of this Texture2D, data should be in the RGBA format
        void set_data(unsigned char* data, int width, int height, int layer);
        
        GLuint texture_id_;
    protected:
    
    private:
    };
}

#endif //OGAL_TEXTURE_3D_HPP
