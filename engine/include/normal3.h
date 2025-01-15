//
// Created by Maxwell Kozlov on 12/27/24.
//

#ifndef NORMAL3_H
#define NORMAL3_H

#include "tuple3.h"
#include "tuplelength.h"
#include "util.h"
template <typename T>
class Vector3;

template <typename T>
class Normal3 : public Tuple3<Normal3, T> {
    public:
        using Tuple3<Normal3, T>::x;
        using Tuple3<Normal3, T>::y;
        using Tuple3<Normal3, T>::z;

        Normal3(): Tuple3<Normal3, T>(){};
        Normal3(T x, T y, T z): Tuple3<Normal3,T>(x,y,z){};

        template <typename U>
        explicit Normal3(Vector3<U> v) : Tuple3<Normal3, T>(T(v.x),T(v.y),T(v.z)) {};

        template <typename U>
        static T Dot(Normal3<T> n, Vector3<U> v) {
            return (v.x * n.x) + (v.y * n.y) + (v.z * n.z);
        }

        static T Dot(Normal3<T> n1, Normal3<T> n2) {
            return (n1.x * n2.x) + (n1.y * n2.y) + (n1.z * n2.z);
        }

        template <typename U>
        static T AbsDot(Normal3<T> n, Vector3<U> v) {
            return std::abs(Dot(n,v));
        }

        template <typename U>
        static T AbsDot(Normal3<T> n1, Normal3<U> n2) {
            return std::abs(Dot(n1,n2));
        }


        static T CrossProduct(Normal3<T> n1, Normal3<T> n2) {
            return { DifferenceOfProducts(n1.y,n2.z,n1.z,n2.y),
                    DifferenceOfProducts(n1.z,n2.x,n1.x,n2.z),
                    DifferenceOfProducts(n1.x,n2.y,n1.y,n2.x)
            };            
        }

        static T CrossProduct(Normal3<T> n, Vector3<T> v) {
            return { DifferenceOfProducts(v.y,v.z,v.z,v.y),
                    DifferenceOfProducts(v.z,v.x,v.x,v.z),
                    DifferenceOfProducts(v.x,v.y,v.y,v.x)
            };
        }

        static T LengthSquared(Normal3<T> n) {
            return (n.x*n.x) + (n.y*n.y) + (n.z*n.z);
        }


        static auto Length(const Normal3<T> n) -> typename TupleLength<T>::type {
            return std::sqrt(LengthSquared(n));
        }

        static auto Normalize(const Normal3<T> n) {
            return n / Length(n);
        }


        static T CalculateAngleBetween(Normal3<T> n1, Normal3<T> n2) {
            if (Dot(n1,n2) < 0) {
                return M_PI - 2 * util::SafeASin(Length(n1 + n2) / 2);
            } else {
                return 2 * util::SafeASin(Length(n2 - n1) / 2);
            }
        }

        static Normal3<T> FaceForward(Normal3<T> n, Vector3<T> v) {
            return (Dot(n,v) < 0.f) ? -n : n;
        }




};


using Normal3f = Normal3<float>;
using Normal3i = Normal3<int>;



#endif //NORMAL3_H
