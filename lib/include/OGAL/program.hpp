#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <GL/glew.h>
#include <GL/gl.h>

namespace OGAL {
    class Program {
    public:
        Program();
        
        ~Program();
        
        /// ID of this shader program
        GLuint program_id_;
        
        /// Creates a new program, with the two speciefied shaders
        void load_program(GLuint vertex_shader, GLuint fragment_shader);
    
    protected:
        GLint result_;
        int log_lenght_;
    private:
    
    };
}
#endif //PROGRAM_HPP
