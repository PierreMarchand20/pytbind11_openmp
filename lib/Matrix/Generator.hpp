#ifndef HTOOL_GENERATOR_HPP
#define HTOOL_GENERATOR_HPP


class IGenerator {
public:
    virtual int compute(int i) = 0;
    virtual ~IGenerator() {};
};

#endif