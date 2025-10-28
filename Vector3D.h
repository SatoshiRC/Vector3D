#ifndef __VECTOR3D_H__
#define __VECTOR3D_H__

#include <array>
#include <cmath>
#include <ostream>
#include <string>

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
    constexpr float norm(){
		float norm = 0;
		for(auto &it:*this){
			norm += square(it);
		}
		return std::sqrt(norm);
	}

    Vector3D<T> outerProduct(Vector3D<T> a, Vector3D<T> b){
    	Vector3D<T> res;

    	res[0] = a[1]*b[2] - a[2]*b[1];
    	res[1] = a[2]*b[0] - a[0]*b[2];
    	res[2] = a[0]*b[1] - a[1]*b[0];

    	return res;
    }

    Vector3D<T> outerProduct(Vector3D<T> arg){
    	Vector3D<T> res;

    	res[0] = this->at(1)*arg[2] - this->at(2)*arg[1];
    	res[1] = this->at(2)*arg[0] - this->at(0)*arg[2];
    	res[2] = this->at(0)*arg[1] - this->at(1)*arg[0];

    	return res;
    }

    Vector3D<double> operator/(double arg){
    	Vector3D<double> res;
    	for(uint8_t n=0; n<3; n++){
    		res[n] = this->at(n) / arg;
    	}
    	return res;
    }
    Vector3D<T> operator*(float arg){
		Vector3D<T> res;
		for(uint8_t n=0; n<3; n++){
			res[n] = this->at(n) * arg;
		}
		return res;
	}

    Vector3D<T> operator*(Vector3D<T> arg){
    	Vector3D<T> res;
    	for(uint8_t n=0; n<3; n++){
    		res[n] = this->at(n) * arg[n];
    	}
    	return res;
    }

    Vector3D<double> operator+(Vector3D<double> arg){
    	Vector3D<double> res;
    	for(uint8_t n=0; n<3; n++){
    		res[n] = this->at(n) + arg[n];
    	}
    	return res;
    }


    Vector3D<double> operator-(Vector3D<double> arg){
    	Vector3D<T> res;
    	for(uint8_t n=0; n<3; n++){
    		res[n] = this->at(n) - arg[n];
    	}
    	return res;
    }

    void operator=(std::array<T,3> arg){
    	for(uint8_t n=0; n<3; n++){
    		this->at(n) = arg[n];
    	}
    }

    template<typename __T>
    operator Vector3D<__T>(){
    	Vector3D<__T> res;
    	for(uint8_t n=0; n<3; n++){
    		res[n] = (__T)this->at(n);
    	}
    	return res;
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
