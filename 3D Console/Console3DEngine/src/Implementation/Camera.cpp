#include <c3dpch.h>

#include "Camera.h"
#include "Space.h"
#include "Renderer.h"

Console3D::Camera::Camera(type::c_uint _w, type::c_uint _h, c_projection _p) :
	width(_w), height(_h), projection(_p)
{}

Console3D::RenderMatrix Console3D::Camera::render() const {
	RenderMatrix matrix(width, height);

	if (projection == ProjectionType::PERSPECTIVE) {

		for (type::uint y = 0; y < height; y++) {
			for (type::uint x = 0; x < width; x++) {
				Vector3d ray(x, y, 0);
				Vector3d step(0, 0, 1);

				double rayLen = length(ray);

				while (rayLen < 100) {
					ray = ray + step;
					rayLen = length(ray);
					bool out = false;
					for (auto& i : Space::getRegistry()) {
						if (i->intersect(ray)) {
							out = true;
							break;
						}
					}
					if (out) break;
				}

				//if (rayLen < PIXELS_COUNT) matrix.setPixel(x, y, PIXELS[(size_t) rayLen]);
				if (rayLen < 100) matrix.setPixel(x, y, 1);
				
			}
		}
		
		
	} else if (projection == ProjectionType::ORTHOGRAPHIC) {

	}

	return matrix;
}

Console3D::type::uint Console3D::Camera::getWidth() const {
	return width;
}

Console3D::type::uint Console3D::Camera::getHeight() const {
	return height;
}


