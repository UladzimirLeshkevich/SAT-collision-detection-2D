#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
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
    void add_vertex(const float x, const float y);

    inline const std::vector<point>& get_vertices() const { return vertices; }

    inline size_t get_number_of_vertex() const { return vertices.size(); }

    bool read_geometry_from_file(const std::string& in_file);

    void print_vertices() const;

private:
    std::vector<point> vertices;

    void parsing_and_save_coordinates(const std::string& str);
};
