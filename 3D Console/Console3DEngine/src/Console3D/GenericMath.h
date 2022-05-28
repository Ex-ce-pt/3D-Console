#pragma once

#include <c3dpch.h>

namespace Console3D {

#define PI 3.14159
#define DEGREES_TO_RADIANS(deg) (deg * PI / 180)
#define RADIANS_TO_DEGREES(rad) (rad * 180 / PI)

	template<typename T>
	struct Vector2 {
		using Ref = const T&;

		T x;
		T y;

		Vector2() : x(0), y(0) {}
		Vector2(Ref value) : x(value), y(value) {}
		Vector2(Ref x, Ref y) : x(x), y(y) {}
	};

	template<typename T>
	struct Vector3 {
		using Ref = const T&;

		T x;
		T y;
		T z;

		Vector3() : x(0), y(0), z(0) {}
		Vector3(Ref value) : x(value), y(value), z(value) {}
		Vector3(Ref x, Ref y, Ref z) : x(x), y(y), z(z) {}
	};

	template<typename Type, type::uint rows, type::uint columns>
	struct Matrix {

		Type data[columns][rows];

	};
	
	typedef Vector2<int> Vector2i;
	typedef Vector2<float> Vector2f;
	typedef Vector2<double> Vector2d;
	
	typedef Vector3<int> Vector3i;
	typedef Vector3<float> Vector3f;
	typedef Vector3<double> Vector3d;

	typedef Matrix<float, 2, 2> Matrix2x2f;
	typedef Matrix<float, 3, 3> Matrix3x3f;

	template<typename T>
	Vector2<T> operator+(const Vector2<T>& one, const Vector2<T>& two) {
		return Vector2<T>(one.x + two.x, one.y + two.y);
	}

	template<typename T>
	Vector2<T> operator-(const Vector2<T>& one, const Vector2<T>& two) {
		return Vector2<T>(one.x - two.x, one.y - two.y);
	}

	template<typename T>
	Vector2<T> operator*(const Vector2<T>& one, const Vector2<T>& two) {
		return Vector2<T>(one.x * two.x, one.y * two.y);
	}

	template<typename T>
	Vector2<T> operator/(const Vector2<T>& one, const Vector2<T>& two) {
		return Vector2<T>(one.x / two.x, one.y / two.y);
	}

	template<typename T>
	Vector2<T> operator%(const Vector2<T>& one, const Vector2<T>& two) {
		return Vector2<T>(one.x % two.x, one.y % two.y);
	}

	template<typename T>
	Vector3<T> operator+(const Vector3<T>& one, const Vector3<T>& two) {
		return Vector3<T>(one.x + two.x, one.y + two.y, one.z + two.z);
	}

	template<typename T>
	Vector3<T> operator-(const Vector3<T>& one, const Vector3<T>& two) {
		return Vector3<T>(one.x - two.x, one.y - two.y, one.z - two.z);
	}

	template<typename T>
	Vector3<T> operator*(const Vector3<T>& one, const Vector3<T>& two) {
		return Vector3<T>(one.x * two.x, one.y * two.y, one.z * two.z);
	}

	template<typename T>
	Vector3<T> operator/(const Vector3<T>& one, const Vector3<T>& two) {
		return Vector3<T>(one.x / two.x, one.y / two.y, one.z / two.z);
	}

	template<typename T>
	Vector3<T> operator%(const Vector3<T>& one, const Vector3<T>& two) {
		return Vector3<T>(one.x % two.x, one.y % two.y);
	}

	template<typename T, type::uint Col>
	Vector2<T> operator*(const Vector2<T>& vec, const Matrix<T, 2, Col>& mat) {
		Vector2<T> res = { 0, 0 };
		for (size_t i = 0; i < Col; i++) {
			res.x += vec.x * mat.data[0][i];
			res.y += vec.y * mat.data[1][i];
		}
		return res;
	}

	template<typename T, type::uint Col>
	Vector3<T> operator*(const Vector3<T>& vec, const Matrix<T, 3, Col>& mat) {
		Vector3<T> res = { 0, 0 };
		for (size_t i = 0; i < Col; i++) {
			res.x += vec.x * mat.data[0][i];
			res.y += vec.y * mat.data[1][i];
			res.z += vec.z * mat.data[2][i];
		}
		return res;
	}

	template<typename T, type::uint Col>
	void operator*=(Vector2<T>& vec, const Matrix<T, 2, Col>& mat) {
		vec = vec * mat;
	}

	template<typename T, type::uint Col>
	void operator*=(Vector3<T>& vec, const Matrix<T, 3, Col>& mat) {
		vec = vec * mat;
	}

	template<typename T>
	void operator+=(Vector2<T>& one, const Vector2<T>& two)  {
		one = one + two;
	}

	template<typename T>
	void operator-=(Vector2<T>& one, const Vector2<T>& two) {
		one = one - two;
	}

	template<typename T>
	void operator*=(Vector2<T>& one, const Vector2<T>& two) {
		one = one * two;
	}

	template<typename T>
	void operator/=(Vector2<T>& one, const Vector2<T>& two) {
		one = one / two;
	}

	template<typename T>
	void operator%=(Vector2<T>& one, const Vector2<T>& two) {
		one = one % two;
	}

	template<typename T>
	void operator+=(Vector3<T>& one, const Vector3<T>& two) {
		one = one + two;
	}

	template<typename T>
	void operator-=(Vector3<T>& one, const Vector3<T>& two) {
		one = one - two;
	}

	template<typename T>
	void operator*=(Vector3<T>& one, const Vector3<T>& two) {
		one = one * two;
	}

	template<typename T>
	void operator/=(Vector3<T>& one, const Vector3<T>& two) {
		one = one / two;
	}

	template<typename T>
	void operator%=(Vector3<T>& one, const Vector3<T>& two) {
		one = one % two;
	}

	template<typename T>
	Vector2<T> abs(const Vector2<T>& vec) {
		return Vector2<T>(abs(vec.x), abs(vec.y));
	}

	template<typename T>
	Vector3<T> abs(const Vector3<T>& vec) {
		return Vector3<T>(std::abs(vec.x), std::abs(vec.y), std::abs(vec.z));
	}

	template<typename T>
	Vector2<T> rotate(const Vector2<T>& vec, const T& angle) {
		double rad = (double) DEGREES_TO_RADIANS(angle);
		Matrix<T, 2, 2> matrix;
		matrix.data[0][0] = cos(rad); matrix.data[1][0] = -sin(rad);
		matrix.data[0][1] = sin(rad); matrix.data[1][1] = cos(rad);
		return vec * matrix;
	}

	//TODO: rotate 3D vector

	template<typename T>
	inline T length(const Vector2<T>& vec) {
		return (T) sqrt((double) (vec.x * vec.x + vec.y * vec.y));
	}

	template<typename T>
	inline T length(const Vector3<T>& vec) {
		return (T) sqrt((double) (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
	}

	template<typename T>
	inline Vector2<T> normalize(const Vector2<T>& vec) {
		return vec / length(vec);
	}


	namespace type {

		using c_vector2f = const Vector2f&;
		using c_vector2d = const Vector2d&;

		using c_vector3f = const Vector3f&;
		using c_vector3d = const Vector3d&;

	}

}