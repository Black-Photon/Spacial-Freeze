namespace framebuffer {
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

    /**
     * Sets up a framebuffer
     * @param width Width of Framebuffer
     * @param height Height of Framebuffer
     * @param rw Whether to read and write to colour buffer or depth only
     * @param FBO Pointer to FBO result
     * @param texture Pointer to texture result
     *
     * @throws
     */
    void setup(int width, int height, bool rw, unsigned int* FBO, unsigned int* texture) {
        glGenFramebuffers(1, FBO);
        glBindFramebuffer(GL_FRAMEBUFFER, *FBO);

        glGenTextures(1, texture);
        glBindTexture(GL_TEXTURE_2D, *texture);
        if(rw) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                         width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, *texture, 0);
            unsigned int rbo;
            glGenRenderbuffers(1, &rbo);
            glBindRenderbuffer(GL_RENDERBUFFER, rbo);
            glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
            glBindRenderbuffer(GL_RENDERBUFFER, 0);
        } else {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,
                         width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, *texture, 0);
            glDrawBuffer(GL_NONE);
            glReadBuffer(GL_NONE);
        }
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);

        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
            throw framebufferException("Could not generate Framebuffer");
        }
    }

    /**
     * Causes all operations to act on the given framebuffer
     * @param width Width of framebuffer
     * @param height Height of framebuffer
     * @param FBO Framebuffer to start
     */
    void startWrite(int width, int height, int FBO) {
        glViewport(0, 0, width, height);
        glBindFramebuffer(GL_FRAMEBUFFER, FBO);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); // NOLINT(hicpp-signed-bitwise)
    }

    /**
     * Ends writing to any active framebuffer switching to default buffer
     */
    void endWrite() {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glViewport(0, 0, core::Data.SCR_WIDTH, core::Data.SCR_HEIGHT);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); // NOLINT(hicpp-signed-bitwise)
    }
}