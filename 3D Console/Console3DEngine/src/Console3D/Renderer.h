#pragma once

#include <c3dpch.h>

#include "Camera.h"

namespace Console3D {

	const size_t PIXELS_COUNT = 2;
	const char PIXELS[PIXELS_COUNT] = { ' ', '#' };

	class Renderer {
	protected:
		std::weak_ptr<Camera> camera;
		std::unique_ptr<char[]> frame;

		size_t currentWidth;
		size_t currentHeight;

		void makeCompatibleFrame();

	public:
		Renderer() = default;
		explicit Renderer(const std::shared_ptr<Camera>& camera);
		explicit Renderer(const std::weak_ptr<Camera>& camera);

		virtual void render() = 0;

		void setCamera(const std::shared_ptr<Camera>& camera);
		void setCamera(const std::weak_ptr<Camera>& camera);

		const char* const getPreviousFrame() const;
	};

}