//
// Created by 47230 on 2025/3/6.
//
#include "LunaPch.h"
#include "WindowsWindow.h"

#include "Luna/Events/ApplicationEvent.h"

#include "Luna/Log.h"
#include "Luna/Events//MouseEvent.h"
#include "Luna/Events/KeyEvent.h"
#include <glad/glad.h>

namespace Luna{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description) {
		LUNA_CORE_ERROR("GLFW Error ({0}) : {1}", error, description  );
	}

    Window* Window::Create(const WindowProps& props)
    {
      	return new WindowsWindow(props);
    }

    WindowsWindow::WindowsWindow(const WindowProps& props)
    {
      	Init(props);
    }

    WindowsWindow::~WindowsWindow()
    {
      	Shutdown();
    }

    void WindowsWindow::Init(const WindowProps& props)
    {
      	m_Data.Title = props.Title;
      	m_Data.Width = props.Width;
      	m_Data.Height = props.Height;

        LUNA_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (!s_GLFWInitialized)
        {
          // TODO: glfwTerminate on system shutdown
            int success = glfwInit();
            LUNA_CORE_ASSERT(success, "Could not intialize GLFW!");
        	glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		LUNA_CORE_ASSERT(status, "Fail to initialize GLAD!");
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

		//ImGui_ImplGlfw_InitForOpenGL(m_Window, false);
    	//Set GLFW callbacks
    	//Size Change Callback
    	glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
    		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
    		data.Width = width;
			data.Height = height;

    		WindowResizeEvent event(width, height);
    		data.EventCallback(event);
    	});
		//Close Callback
    	glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
    		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
    		data.EventCallback(event);
    	});

    	//Key Callback
    	glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
    		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

    		switch (action) {
				case GLFW_PRESS: {
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}

    			case GLFW_RELEASE: {
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}

    			case GLFW_REPEAT: {
					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}

    		}

    		//change keycode from glfw to imguiKeycode
    		//ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);
    	});

		//Key Character
		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			KeyTypedEvent event(keycode);
			data.EventCallback(event);
		});

    	//Mouse Callback
    	glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
    		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

    		switch (action) {
    			case GLFW_PRESS: {
    				MouseButtonPressedEvent event(button);
    				data.EventCallback(event);
    				break;
    			}

    			case GLFW_RELEASE: {
    				MouseButtonReleasedEvent event(button);
    				data.EventCallback(event);
    				break;
    			}
    		}
    	});

    	//Mouse Scroll Callback
    	glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset) {
    		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event((float)xoffset, (float)yoffset);
    		data.EventCallback(event);
    	});

    	//Mouse Position Callback
    	glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos) {
    		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

    		MouseMovedEvent event((float)xpos, (float)ypos);
    		data.EventCallback(event);
    	});
    }

    void WindowsWindow::Shutdown()
    {
      	glfwDestroyWindow(m_Window);
    }

    void WindowsWindow::OnUpdate()
    {
      	glfwPollEvents();
      	glfwSwapBuffers(m_Window);
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        if (enabled)
        {
            glfwSwapInterval(1);
        }
        else
        {
            glfwSwapInterval(0);
        }

        m_Data.VSync = enabled;
    }

    bool WindowsWindow::IsVSync() const
    {
      	return m_Data.VSync;
    }
}