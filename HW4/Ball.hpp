#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {
public:
    Ball() = default;
    Ball(double x, double y,
         double vx, double vy,
         double red, double green, double blue,
         double radius,
         bool isCollidable);

    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;

private:
    Point center;
    Velocity velocity;
    double radius = 0.0;
    double red = 0.0;
    double green = 0.0;
    double blue = 0.0;
    bool collidable = false;
};
