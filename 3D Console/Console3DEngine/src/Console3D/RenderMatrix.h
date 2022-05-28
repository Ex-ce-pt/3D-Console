#pragma once

#include <c3dpch.h>

namespace Console3D {

	class RenderMatrix {
	private:
		size_t width;
		size_t height;
		type::ubyte* buffer;

	public:
		RenderMatrix(type::c_size _w, type::c_size _h);
		RenderMatrix(const RenderMatrix& other);
		RenderMatrix(const RenderMatrix&& other) noexcept;
		~RenderMatrix();

		void operator=(const RenderMatrix& other);
		void operator=(const RenderMatrix&& other) noexcept;

		type::c_size getWidth() const;
		type::c_size getHeight() const;
		void setPixel(type::c_size x, type::c_size y, type::c_ubyte p);
		type::ubyte getPixel(type::c_size x, type::c_size y) const;
	};

}