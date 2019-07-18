#ifndef SPACIALFREEZE_FRAMEBUFFER_H
#define SPACIALFREEZE_FRAMEBUFFER_H

#include <string>
#include <exception>

class Framebuffer {
public:
    /**
     * Sets up a framebuffer
     * @param width Width of Framebuffer
     * @param height Height of Framebuffer
     * @param rw Whether to read and write to colour buffer or depth only
     *
     * @throws framebufferException if failed to create
     */
    Framebuffer(int width, int height, bool rw);
    ~Framebuffer();
    /**
     * Causes all operations to act on the given framebuffer
     */
    void startWrite();
    /**
     * Ends writing to any active framebuffer switching to default buffer
     * @param SCR_WIDTH Default screen width
     * @param SCR_HEIGHT Default screen height
     */
    void endWrite(int SCR_WIDTH, int SCR_HEIGHT);
    /**
     * Updates the framebuffer to reflect the new size
     * @param width New width
     * @param height New height
     */
    void updateSize(int width, int height);

    unsigned int texture;

private:
    unsigned int FBO;
    int width;
    int height;
    bool rw;
};

/**
 * Indicated an error occurred in the framebuffer
 */
struct framebufferException : public std::exception {
    std::string s;

    explicit framebufferException(const std::string &string) {
        s = string;
    }

    const char *what() const noexcept(true) override {
        return s.c_str();
    }
};

#endif //SPACIALFREEZE_FRAMEBUFFER_H