#pragma once

#include <c3dpch.h>

#include "GenericMath.h"

namespace Console3D {
	namespace Object {

		class Object3D {
		public:
			Object3D() = default;

			virtual bool intersect(type::c_vector3d point) const;
		};

		class Sphere : public Object3D {
		private:
			Vector3d center;
			double radius;

		public:
			Sphere(type::c_vector3d center, type::c_double radius);

			bool intersect(type::c_vector3d point) const override;
		};

	}
}