/* SPDX-License-Identifier: GPL-2.0-or-later */

#ifndef IPTSD_MATH_VEC2_HPP
#define IPTSD_MATH_VEC2_HPP

#include "num.hpp"

#include <cmath>
#include <iostream>

namespace iptsd::math {

template <class T> struct Vec2 {
public:
	T x, y;

public:
	using value_type = T;

public:
	constexpr auto operator+=(Vec2<T> const &v) -> Vec2<T> &;
	constexpr auto operator+=(T const &s) -> Vec2<T> &;

	constexpr auto operator-=(Vec2<T> const &v) -> Vec2<T> &;
	constexpr auto operator-=(T const &s) -> Vec2<T> &;

	constexpr auto operator*=(T const &s) -> Vec2<T> &;
	constexpr auto operator/=(T const &s) -> Vec2<T> &;

	[[nodiscard]] constexpr auto dot(Vec2<T> const &v) const -> T;
	[[nodiscard]] constexpr auto norm_l2() const -> T;

	template <class S> constexpr auto cast() const -> Vec2<S>;
};

template <class T> inline constexpr auto Vec2<T>::operator+=(Vec2<T> const &v) -> Vec2<T> &
{
	this->x += v.x;
	this->y += v.y;
	return *this;
}

template <class T> inline constexpr auto Vec2<T>::operator+=(T const &s) -> Vec2<T> &
{
	this->x += s;
	this->y += s;
	return *this;
}

template <class T> inline constexpr auto Vec2<T>::operator-=(Vec2<T> const &v) -> Vec2<T> &
{
	this->x -= v.x;
	this->y -= v.y;
	return *this;
}

template <class T> inline constexpr auto Vec2<T>::operator-=(T const &s) -> Vec2<T> &
{
	this->x -= s;
	this->y -= s;
	return *this;
}

template <class T> inline constexpr auto Vec2<T>::operator*=(T const &s) -> Vec2<T> &
{
	this->x *= s;
	this->y *= s;
	return *this;
}

template <class T> inline constexpr auto Vec2<T>::operator/=(T const &s) -> Vec2<T> &
{
	this->x /= s;
	this->y /= s;
	return *this;
}

template <class T> inline constexpr auto Vec2<T>::dot(Vec2<T> const &v) const -> T
{
	return this->x * v.x + this->y * v.y;
}

template <class T> inline constexpr auto Vec2<T>::norm_l2() const -> T
{
	using std::hypot;

	return hypot(this->x, this->y);
}

template <class T>
template <class S>
[[nodiscard]] inline constexpr auto Vec2<T>::cast() const -> Vec2<S>
{
	return {static_cast<S>(this->x), static_cast<S>(this->y)};
}

template <class T> inline auto operator<<(std::ostream &os, Vec2<T> const &v) -> std::ostream &
{
	return os << "[" << v.x << ", " << v.y << "]";
}

template <class T> inline constexpr auto operator==(Vec2<T> const &a, Vec2<T> const &b) -> bool
{
	return a.x == b.x && a.y == b.y;
}

template <class T> inline constexpr auto operator!=(Vec2<T> const &a, Vec2<T> const &b) -> bool
{
	return !(a == b);
}

template <class T> inline constexpr auto operator+(Vec2<T> const &a, Vec2<T> const &b) -> Vec2<T>
{
	return {a.x + b.x, a.y + b.y};
}

template <class T> inline constexpr auto operator+(Vec2<T> const &v, T const &s) -> Vec2<T>
{
	return {v.x + s, v.y + s};
}

template <class T> inline constexpr auto operator+(T const &s, Vec2<T> const &v) -> Vec2<T>
{
	return {s + v.x, s + v.y};
}

template <class T> inline constexpr auto operator-(Vec2<T> const &a, Vec2<T> const &b) -> Vec2<T>
{
	return {a.x - b.x, a.y - b.y};
}

template <class T> inline constexpr auto operator-(Vec2<T> const &v, T const &s) -> Vec2<T>
{
	return {v.x - s, v.y - s};
}

template <class T> inline constexpr auto operator-(T const &s, Vec2<T> const &v) -> Vec2<T>
{
	return {s - v.x, s - v.y};
}

template <class T> inline constexpr auto operator*(Vec2<T> const &v, T const &s) -> Vec2<T>
{
	return {v.x * s, v.y * s};
}

template <class T> inline constexpr auto operator*(T const &s, Vec2<T> const &v) -> Vec2<T>
{
	return {s * v.x, s * v.y};
}

template <class T> inline constexpr auto operator/(Vec2<T> const &v, T const &s) -> Vec2<T>
{
	return {v.x / s, v.y / s};
}

template <class T> inline constexpr auto operator/(T const &s, Vec2<T> const &v) -> Vec2<T>
{
	return {s / v.x, s / v.y};
}

template <class T> struct num<Vec2<T>> {
	static inline constexpr Vec2<T> zero = {num<T>::zero, num<T>::zero};
};

} /* namespace iptsd::math */

#endif /* IPTSD_MATH_VEC2_HPP */
