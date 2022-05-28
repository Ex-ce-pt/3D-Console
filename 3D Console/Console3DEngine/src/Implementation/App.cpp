#include <c3dpch.h>

#include "App.h"
#include "RenderMatrix.h"
#include "Camera.h"

Console3D::App::App() :
	running(false), renderer(std::make_unique<AppRenderer>())
{}

void Console3D::App::Begin() {
	running = true;
}

void Console3D::App::Update() {

	renderer->render();

}

void Console3D::App::End() {
	running = false;
}

bool Console3D::App::IsRunning() const {
	return running;
}

Console3D::App::CameraPtr Console3D::App::createNewCamera(type::c_uint _w, type::c_uint _h) {
	mainCamera = std::make_shared<Camera>(_w, _h);
	renderer->setCamera(mainCamera);
	return mainCamera;
}

void Console3D::App::setMainCamera(Camera* camera) {
	mainCamera = std::shared_ptr<Camera>(camera);
	renderer->setCamera(mainCamera);
}

Console3D::App::CameraPtr Console3D::App::getMainCamera() const {
	return mainCamera;
}

void Console3D::App::AppRenderer::render() {
	std::shared_ptr<Camera> tempCam = camera.lock();

	RenderMatrix matrix = tempCam->render();

	for (size_t y = 0; y < matrix.getHeight(); y++) {
		char* const line = new char[matrix.getWidth() + 1];
		for (size_t x = 0; x < matrix.getWidth(); x++) {
			type::ubyte pixel = matrix.getPixel(x, y);
			char ch = PIXELS[min(pixel, PIXELS_COUNT - 1)];
			line[x] = ch;
		}
		line[matrix.getWidth()] = '\0';
		memcpy(frame.get() + matrix.getWidth() * y, line, matrix.getWidth());
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, (short) y });
		std::cout << line;
	}

}
