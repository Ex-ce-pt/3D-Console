#include <c3dpch.h>

#include "Renderer.h"
#include "Camera.h"

void Console3D::Renderer::makeCompatibleFrame() {
	if (!camera.expired()) {
		std::shared_ptr<Camera> tempCam = camera.lock();
		currentWidth = tempCam->getWidth();
		currentHeight = tempCam->getHeight();
		frame = std::make_unique<char[]>(currentWidth * currentHeight);
	}
}

Console3D::Renderer::Renderer(const std::shared_ptr<Camera>& camera) :
	camera(camera), frame(nullptr), currentWidth(0), currentHeight(0)
{
	makeCompatibleFrame();
}

Console3D::Renderer::Renderer(const std::weak_ptr<Camera>& camera) :
	camera(camera), frame(nullptr), currentWidth(0), currentHeight(0)
{
	makeCompatibleFrame();
}

void Console3D::Renderer::setCamera(const std::shared_ptr<Camera>& camera) {
	this->camera = camera;
	makeCompatibleFrame();
}

void Console3D::Renderer::setCamera(const std::weak_ptr<Camera>& camera) {
	this->camera = camera;
	makeCompatibleFrame();
}

const char* const Console3D::Renderer::getPreviousFrame() const {
	return frame.get();
}
