#ifndef TRAB1_POINT2D_H
#define TRAB1_POINT2D_H

#include <cmath>

template <typename T>
struct point
{
  T x, y;
  
  point(T x, T y) noexcept :
      x(x),
      y(y)
  { }
  
  // Formula to change coordinates for OpenGL
  point<T> change_coordinates(T dim_x, T dim_y)
  {
    return point((2. * x) / dim_x - 1., -(2. * y) / dim_y + 1.);
  }
  
  // Some operator overloads
  point<T>& operator+=(const point<T>& other)
  {
    x += other.x;
    y += other.y;
    
    return *this;
  }
  
  point<T>& operator-=(const point<T>& other)
  {
    x -= other.x;
    y -= other.y;
    
    return *this;
  }
  
  point<T>& operator*=(double scalar)
  {
    x *= scalar;
    y *= scalar;
    
    return *this;
  }
  
  point<T>& operator/=(double scalar)
  {
    x /= scalar;
    y /= scalar;
    
    return *this;
  }
  
  // Adding points
  point<T> operator+(const point<T>& other) const
  {
    return point<T>(x + other.x, y + other.y);
  }
  
  // Subtracting points
  point<T> operator-(const point<T>& other) const
  {
    return point<T>(x - other.x, y - other.y);
  }
  
  // Multiply by scalar
  point<T> operator*(double scalar) const
  {
    return point<T>(x * scalar, y * scalar);
  }
  
  // Division by scalar
  point<T> operator/(double scalar) const
  {
    return point<T>(x / scalar, y / scalar);
  }
  
  // Check if 2 points are close enough to be considered equals
  bool operator!=(const point<T>& other) const
  {
    return std::abs(x - other.x) > 0.001 && std::abs(y - other.y) > 0.001;
  }
  
  bool operator==(const point<T>& other) const
  {
    return !(*this != other);
  }
  
  // Dor product
  T dot(const point<T>& other) const
  {
    return x * other.x + y * other.y;
  }
  
  // Vector's norm
  T norm() const
  {
    return std::sqrt(x * x + y * y);
  }
  
  // Cross product
  T cross(const point<T>& other) const
  {
    return x * other.y - y * other.x;
  }
  
  // Angle between 2 points
  double theta(const point<T>& other) const
  {
    return std::acos(this->dot(other) / (this->norm() * other.norm()));
  }
  
  // Rotation matrix
  void rotate(T theta)
  {
    T x_rot = x * cos(theta) + y * sin(theta);
    T y_rot = -x * sin(theta) + y * cos(theta);
    
    x = x_rot;
    y = y_rot;
  }
};

#endif //TRAB1_POINT2D_H
