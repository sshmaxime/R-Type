//
// Created by chennetier on 14/01/18.
//

#ifndef R_TYPE_VECTOR2_HPP
#define R_TYPE_VECTOR2_HPP

namespace TacosEngine {

    class Vector2 {
    private:
        float   _x;
        float   _y;

    public:
        Vector2(float x = 0, float y = 0);
        ~Vector2() = default;

        float get_x() const;

        void set_x(float _x);

        float get_y() const;

        void set_y(float _y);

		Vector2	&operator=(const Vector2 &other);
		Vector2	&operator+(const Vector2 &other);
		Vector2	&operator-(const Vector2 &other);
		Vector2	&operator*(const Vector2 &other);
    };
}


#endif //R_TYPE_VECTOR2_HPP
