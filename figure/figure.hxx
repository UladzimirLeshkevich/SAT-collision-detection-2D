#pragma once
#include <vector>

struct point
{
    point(float in_x, float in_y)
        : x(in_x)
        , y(in_y)
    {
    }

    point()
        : x(0)
        , y(0)
    {
    }

    float x;
    float y;
};

bool operator<(point a, point b)
{
    return a.x < b.x;
}

class figure
{
public:
    inline void add_vertex(const float x, const float y)
    {
        vertices.emplace_back(point(x, y));
    }

    inline const std::vector<point>& get_vertices() const { return vertices; }
    inline size_t get_number_of_vertex() const { return vertices.size(); }

private:
    std::vector<point> vertices;
};
