#include "Renderer.h"
#include <iostream>

void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line) {
	while (GLenum error = glGetError()) {
		std::cout << "ERROR " << error << function << " "
			<< file << ":" << line << '\n';
		return false;
	}
	return true;
}

void Renderer::Draw(const VertexArray & va, const IndexBuffer & ib, const Shader & shader) const {
	shader.Bind();
	va.Bind();
	ib.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, ib.getCount() , GL_UNSIGNED_INT, nullptr));
}
