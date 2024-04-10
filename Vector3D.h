#include <array>
#include <cmath>

#ifndef __VECTOR3D_H__
#define __VECTOR3D_H__

template<class T>
struct Vector3D : public std::array<T,3>{
    void normalize(){
        float norm = getNorm();
        for(auto &it:*this){
            it /= norm;
        }
    }

    constexpr float getNorm(){
        float norm = 0;
        for(auto &it:*this){
            norm += square(it);
        }
        return std::sqrt(norm);
    }
private:
    inline T square(T arg){
        return arg * arg;
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& o, Vector3D<T>& obj){
	o << obj[0] << ", ";
	o << obj[1] << ", ";
	o << obj[2];
	return o;
}

#endif /*__VECTOR3D_H__*/