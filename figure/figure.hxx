#pragma once
#include <iostream>
#include <utility>
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
    typedef std::vector<std::pair<point, point>> fiugur_edges;

    void add_vertex(const float x, const float y)
    {
        vertices.emplace_back(point(x, y));
    }

    std::vector<point>& get_vertices() { return vertices; }

    fiugur_edges& get_edges()
    {
        convert_vertices_to_edges();
        return edges;
    }

    size_t get_number_of_vertex() const { return vertices.size(); }

    // lvi just for degub
    void print_edges()
    {
        convert_vertices_to_edges();
        std::cout << " edges of figuir " << std::endl;
        for (const auto& it : edges)
        {
            std::cout << " it.first.x = " << it.first.x
                      << " it.first.y = " << it.first.y << std::endl;
            std::cout << " it.second.x = " << it.second.x
                      << " it.second.y = " << it.second.y << std::endl;
            std::cout << " ================== " << std::endl;
        }
        std::cout << std::endl;
    }

    //================================================================
    // void convert_edges() { convert_vertices_to_edges(); } // lvi debug

private:
    std::vector<point>                   vertices;
    std::vector<std::pair<point, point>> edges;

    void convert_vertices_to_edges()
    {
        edges.clear();
        size_t last_vertex_index = vertices.size() - 1;
        for (size_t i = 0; i < last_vertex_index; ++i)
        {
            edges.emplace_back(
                std::make_pair(point(vertices[i].x, vertices[i].y),
                               point(vertices[i + 1].x, vertices[i + 1].y)));
        }
        edges.emplace_back(std::make_pair(
            point(vertices[last_vertex_index].x, vertices[last_vertex_index].y),
            point(vertices[0].x, vertices[0].y)));
    }
};
