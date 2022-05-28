#include <c3dpch.h>

#include "RenderMatrix.h"

Console3D::RenderMatrix::RenderMatrix(type::c_size _w, type::c_size _h) : width(_w), height(_h), buffer(new type::ubyte[_w * _h])
{
	ZeroMemory(buffer, sizeof(type::ubyte) * _w * _h);
}

Console3D::RenderMatrix::RenderMatrix(const RenderMatrix & other) {
	operator=(other);
}

Console3D::RenderMatrix::RenderMatrix(const RenderMatrix&& other) noexcept {
	operator=(other);
}

Console3D::RenderMatrix::~RenderMatrix() {
	if (buffer != nullptr) delete[] buffer;
}

void Console3D::RenderMatrix::operator=(const RenderMatrix& other) {
	width = other.width;
	height = other.height;
	if (buffer != nullptr) delete[] buffer;
	buffer = new type::ubyte[width * height];
	memcpy(buffer, other.buffer, sizeof(type::ubyte) * width * height);
}

void Console3D::RenderMatrix::operator=(const RenderMatrix&& other) noexcept {
	width = other.width;
	height = other.height;
	if (buffer != nullptr) delete[] buffer;
	buffer = new type::ubyte[width * height];
	memcpy(buffer, other.buffer, sizeof(type::ubyte) * width * height);
}

Console3D::type::c_size Console3D::RenderMatrix::getWidth() const {
	return width;
}

Console3D::type::c_size Console3D::RenderMatrix::getHeight() const {
	return height;
}

void Console3D::RenderMatrix::setPixel(type::c_size x, type::c_size y, type::c_ubyte p) {
	if (buffer != nullptr && x >= 0 && x < width && y >= 0 && y < height) buffer[y * width + x] = p;
}

Console3D::type::ubyte Console3D::RenderMatrix::getPixel(type::c_size x, type::c_size y) const {
	return (buffer != nullptr && x >= 0 && x < width && y >= 0 && y < height) ? buffer[y * width + x] : 0;
}
