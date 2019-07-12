#include "data.cpp"

/**
 * Methods used in Pre-Initialisation
 */

namespace core {

    /**
     * Initializes the program, creating a basic window
     * @throws initialisationException If it fails to successfully initialise the program
     */
    void preInit(unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT, std::string &title);
    /**
     * DO NOT CALL
     * Called every time the viewport is updated
     * @param window Window for viewport to affect
     * @param width New viewport width
     * @param height New viewport height
     */
    void framebuffer_size_callback(GLFWwindow *window, int width, int height);
    /**
     * DO NOT CALL
     * Called every time the mouse moves
     * @param window Window for mouse to move in
     * @param xpos X-Coordinate of mouse
     * @param ypos Y-Coordinate of mouse
     */
    void mouse_callback(GLFWwindow *window, double xpos, double ypos);
    /**
     * DO NOT CALL
     * Called every time the mouse scrolls
     * @param window Window for mouse to scroll in
     * @param xpos X-Offset of mouse
     * @param ypos Y-Offset of mouse
     */
    void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
    /**
     * DO NOT CALL
     * Called every time the mouse is clicked
     * @param window Window for mouse to scroll in
     * @param button Button Pressed - e.g. GLFW_MOUSE_BUTTON_RIGHT
     * @param action Action - e.g. GLFW_PRESS
     * @param mods Modifier bits (E.g. Shift Pressed)
     */
    void click_callback(GLFWwindow *window, int button, int action, int mods);

    void preInit(const unsigned int SCR_WIDTH, const unsigned int SCR_HEIGHT, const std::string &title) {
        Data.SCR_WIDTH = SCR_WIDTH;
        Data.SCR_HEIGHT = SCR_HEIGHT;

        // Sets all the window settings
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Creates a window object and checks it actually works
        GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, title.c_str(), nullptr, nullptr);
        if (window == nullptr) {
            glfwTerminate();
            throw initialisationException("Failed to create Window");
        }

        // Tells it what window to apply OpenGL operations to
        glfwMakeContextCurrent(window);
        // Tells OpenGL to use this function when resizing
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
        glfwSetCursorPosCallback(window, mouse_callback);
        glfwSetScrollCallback(window, scroll_callback);
        glfwSetMouseButtonCallback(window, click_callback);

        // Sets up GLAD
        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            throw initialisationException("Failed to initialize GLAD");
        }

        Data.window = window;
    }

    void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
        // Simply makes the viewport in the whole screen - bottom left to top right
        glViewport(0, 0, width, height);
    }

    void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
        // Sets default values if first time
        if (Mouse.first) {
            Mouse.lastX = xpos;
            Mouse.lastY = ypos;
            Mouse.first = false;
        }

        // Offset is distance moved
        float xoffset = xpos - Mouse.lastX;
        float yoffset = Mouse.lastY - ypos; // reversed since y-coordinates range from bottom to top
        Mouse.lastX = xpos;
        Mouse.lastY = ypos;

        // Movement sensitivity
        float sensitivity = 0.05f;
        xoffset *= sensitivity;
        yoffset *= sensitivity;

        // Adjusts the yaw and pitch according to the mouse movement
        Data.camera->rotate(YAW, xoffset);
        Data.camera->rotate(PITCH, yoffset);
    }

    void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {}

    void click_callback(GLFWwindow *window, int button, int action, int mods) {}
}