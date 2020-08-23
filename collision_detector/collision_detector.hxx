#pragma once
#include "../figure/figure.hxx"
#include <algorithm>
#include <iostream>
#include <vector>

class sat_collision_detector_2d
{
public:
    int check_collision(figure& in_figure_one, figure& in_figure_two);

private:
    typedef std::pair<point, point> section;
    typedef std::pair<float, float> min_max_x_value;
    typedef std::vector<section>    fiugur_sections;
    typedef std::vector<point>      points;

    fiugur_sections normals_of_figure_one;
    fiugur_sections normals_of_figure_two;

    points figure_one_projection;
    points figure_two_projection;

    void build_normals(figure& in_figure, fiugur_sections& save_to);

    void project_figure_to_normal(figure& in_figure, const section& in_normal,
                                  points& result);

    point point_projection_to_normal(const section in_normal,
                                     const point&  pt_from);

    void get_normal_coordinates(const point& pta, const point& ptb,
                                point& pt_rezult_a, point& pt_rezult_b);

    min_max_x_value build_min_max_projection(points& figure_projection);

    bool check_collision_between_projections(
        const min_max_x_value& in_figuir_one,
        const min_max_x_value& in_figuir_two);

    bool check_coll(figure& in_figure_a, figure& in_figure_b,
                    const fiugur_sections& normals_of_figure);

    //====== debug functions =====
    void print_normals_of_figure(const fiugur_sections& normals_of_figure);

    void print_projections(const points& in_projection);
};
