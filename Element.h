#ifndef ELEMENT_H
#define ELEMENT_H

#include "myTypes.h"
#include <iostream>

class Element {
private:
    float shape;
    float scale;
    uint price;

    friend std::ostream& operator<<(std::ostream& ostream, const Element& e) {
        ostream << "Element (shape: " << e.shape << ", scale: " << e.scale << ", price: " << e.price << std::endl;
        return ostream;
    }

public:
    Element() {}
    Element(float shape, float scale, uint price)
        :shape(shape)
        ,scale(scale)
        ,price(price)
    {}

    float getScale() const
    {
        return scale;
    }

    float getShape() const
    {
        return shape;
    }

    uint getPrice() const
    {
        return price;
    }
};

#endif // ELEMENT_H
