//
// Created by maxwe on 12/23/2024.
//

#ifndef TUPLE3_H
#define TUPLE3_H
#include <math.h>
#include <ostream>
#include <cassert>


template <template <typename> class Child, typename T>
class Tuple3 {
    public:

        Tuple3() = default;
        Tuple3(T x, T y, T z) : x(x), y(y), z(z) {
            assert(x != NAN);
            assert(y != NAN);
            assert(z != NAN);
        };

        bool HasNaN() const { return IsNaN(x) || IsNaN(y) || IsNaN(z);}

        T operator[](int i) const {
            if (i == 0) return x;
            if (i == 1) return y;
            return z;
        }

        T &operator[](int i) {
            if (i == 0) return x;
            if (i == 1) return y;
            return z;
        }

        bool operator==(Child<T> c) {
            return x == c.x && y == c.y && z == c.z;
        }

        bool operator!=(Child<T> c) {
            return x != c.x || y != c.y || z != c.z;
        }

        // This function returns a new Tuple of type Child with an inner type
        // That is decided by C++'s type promotion rules (purpose for decltype)
        template <typename U>
        auto operator+(Child<U> c) const -> Child<decltype(T{} + U{})> {
            return {x+c.x, y+c.y, z+c.z};
        }

        template <typename U>
        auto operator-(Child<U> c) const -> Child<decltype(T{} + U{})> {
            return {x-c.x, y-c.y, z-c.z};
        }

        Child<T> operator-() const{
            return {-x,-y,-z};
        }

        // Do we need to do type matching here?
        template <typename U>
        Child<T> &operator+=(Child <U> c){
            x+=c.x;
            y+=c.y;
            z+=c.z;
            return static_cast<Child<T> &>(*this);
        }


        template <typename U>
        auto operator*(U c) const -> Child<decltype(T{} * U{})> {
            return {x*c, y*c, z*c};
        }

        template <typename U>
        Child<T> &operator*=(U c){
            x*=c;
            y*=c;
            z*=c;
            return static_cast<Child<T> &>(*this);
        }


        template <typename U>
        auto operator/(U c) const -> Child<decltype(T{} + U{})>{
            return {x/c, y/c, z/c};
        }

        template <typename U>
        Child<T> &operator/=(U c){
            x/=c;
            y/=c;
            z/=c;
            return static_cast<Child<T> &>(*this);
        }

        static Child<T> Min(Child<T> a, Child<T> b) {
            return Child<T>{std::min(a.x,b.x),std::min(a.y,b.y),std::min(a.z,b.z)};
        }

        static Child<T> Max(Child<T> a, Child<T> b) {
            return Child<T>{std::max(a.x,b.x),std::max(a.y,b.y),std::max(a.z,b.z)};
        }


        friend std::ostream & operator<<(std::ostream &os, const Tuple3 &obj) {
            return os
                   << "x: " << obj.x
                   << " y: " << obj.y
                   << " z: " << obj.z;
        }

        T x{}, y{}, z{};

};

// Tuple3 Inline Functions
template <template <class> class C, typename T, typename U>
inline auto operator*(U s, Tuple3<C, T> t) -> C<decltype(T{} * U{})> {
    return t * s;
}





#endif //TUPLE3_H
