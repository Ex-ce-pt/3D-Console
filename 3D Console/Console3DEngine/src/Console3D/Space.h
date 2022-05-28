#pragma once

#include <c3dpch.h>

#include "Objects.h"

namespace Console3D {
	namespace Space {

		using ObjectRegistry = std::vector<std::shared_ptr<Object::Object3D>>;
			
		static ObjectRegistry objectRegistry;

		void addObject(const std::shared_ptr<Object::Object3D>& obj);
		void reserveMemory(type::c_uint count);
		const ObjectRegistry& getRegistry();

	}
}