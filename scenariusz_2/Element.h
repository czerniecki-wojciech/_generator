#ifndef ELEMENT_H
#define ELEMENT_H

#include "myTypes.h"
#include <iostream>

class Element 
{
private:
    friend std::ostream& operator<<(std::ostream& ostream, const Element& e) 
	{
        ostream << "Element (shape: " << e.shape << ", scale: " << e.scale << ", price: " << e.price << ")" << std::endl;
        return ostream;
    }
protected:
    float shape;
    float scale;
    uint price;

public:
    Element()
        :shape(0.0f)
        ,scale(0.0f)
        ,price(0)
    {}

    Element(float shape, float scale, uint price)
        :shape(shape)
        ,scale(scale)
        ,price(price)
    {}
    Element(const Element& element)
    {
        this->scale = element.scale;
        this->shape = element.shape;
        this->price = element.price;
    }

    Element& operator= (const Element& element)
    {
        this->scale = element.scale;
        this->shape = element.shape;
        this->price = element.price;
		return *this;
    }

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
