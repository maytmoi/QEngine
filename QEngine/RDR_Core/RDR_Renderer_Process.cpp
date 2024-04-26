#include <thread>
#include <chrono>

#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>
#include <vec2.hpp>
#include <vec3.hpp>

#include "QE_Core\QE_Logger_Manager.h"

#include "RDR_Core\RDR_Renderer_Process.h"
#include "RDR_Core\RDR_Camera_Struct.h"

#define WIDTH 1920
#define HEIGHT 1080

namespace RDR
{
	int RendererProcess::Entrypoint()
	{
        GLFWwindow* wWindow;

        if (!glfwInit())
            return -1;
        
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        wWindow = glfwCreateWindow(WIDTH, HEIGHT, "Hello World", NULL, NULL);
        if (!wWindow)
        {
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(wWindow);

        if (glewInit() != GLEW_OK)
            return -1;

        Camera wCamera(
        glm::vec3(0, 0, 0),
            glm::radians(0.0f),
            glm::radians(0.0f),
            glm::radians(0.0f),
            glm::radians(90.0f),
            glm::uvec2(WIDTH, HEIGHT));

        // Texture creation
        GLuint wTextureID;
        glGenTextures(1, &wTextureID);
        glBindTexture(GL_TEXTURE_2D, wTextureID);
        
        // FBO Creation
        GLuint wFramebufferID;
        glGenFramebuffers(1, &wFramebufferID);
        glBindFramebuffer(GL_FRAMEBUFFER, wFramebufferID);

        // Attaching texture to the frambuffer
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, wTextureID, 0);
        
        // Binding once READ and DRAW
        glBindFramebuffer(GL_READ_FRAMEBUFFER, wFramebufferID);
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);

        while (!glfwWindowShouldClose(wWindow))
        {
            // Clear
            glClear(GL_COLOR_BUFFER_BIT);

            // Copying data to the texture 
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WIDTH, HEIGHT, 0, GL_RGB, GL_FLOAT, wCamera.Render());
            
            // Copying the framebuffer to the default one
            glBlitFramebuffer(0, 0, WIDTH, HEIGHT, 0, 0, WIDTH, HEIGHT, GL_COLOR_BUFFER_BIT, GL_NEAREST);
            
            glfwSwapBuffers(wWindow);
            glfwPollEvents();
        }

        glfwTerminate();

        return 0;
	}
}