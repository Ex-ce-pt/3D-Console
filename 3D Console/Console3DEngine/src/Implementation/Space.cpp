#include <c3dpch.h>

#include "Space.h"

void Console3D::Space::addObject(const std::shared_ptr<Object::Object3D>& obj) {
	objectRegistry.push_back(obj);
}

void Console3D::Space::reserveMemory(type::c_uint count) {
	objectRegistry.reserve(count);
}

const Console3D::Space::ObjectRegistry& Console3D::Space::getRegistry() {
	return objectRegistry;
}
