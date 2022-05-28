#include <c3dpch.h>

#include "Objects.h"

bool Console3D::Object::Object3D::intersect(type::c_vector3d point) const {
	return false;
}

Console3D::Object::Sphere::Sphere(type::c_vector3d center, type::c_double radius) :
	center(center), radius(radius)
{}

bool Console3D::Object::Sphere::intersect(type::c_vector3d point) const {
	return length(center - point) <= radius;
}