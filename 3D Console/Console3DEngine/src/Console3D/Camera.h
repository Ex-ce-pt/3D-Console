#pragma once

#include <c3dpch.h>

#include "RenderMatrix.h"

namespace Console3D {

	class Camera {
	public:
		enum ProjectionType { PERSPECTIVE, ORTHOGRAPHIC };

	private:
		using c_projection = const ProjectionType&;

		type::uint width;
		type::uint height;
		ProjectionType projection;

	public:
		Camera(type::c_uint _w = 10, type::c_uint _h = 5, c_projection _p = PERSPECTIVE);

		RenderMatrix render() const;

		type::uint getWidth() const;
		type::uint getHeight() const;
	};

}