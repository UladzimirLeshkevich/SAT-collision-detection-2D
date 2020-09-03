#include "collision_detector.hxx"

int sat_collision_detector_2d::check_collision(figure& in_figure_one,
                                               figure& in_figure_two)
{
    if (in_figure_one.get_number_of_vertex() <= 2 ||
        in_figure_two.get_number_of_vertex() <= 2)
    {
        return -1;
    }

    // Step 1
    // build normals to all edges of the figure_one
    // make projections of all figures onto the normals of figure_one
    // and check the gap...
    build_normals(in_figure_one, normals_of_figure_one);
    if (!check_coll(in_figure_one, in_figure_two, normals_of_figure_one))
        return 0;

    
    // ...if there is no gap, repeat Step 1 for normals of figure_two
    build_normals(in_figure_two, normals_of_figure_two);
    if (!check_coll(in_figure_one, in_figure_two, normals_of_figure_two))
        return 0;

    return 1;
}

void sat_collision_detector_2d::build_normals(figure&          in_figure,
                                              fiugur_sections& save_to)
{
    fiugur_sections edges = convert_vertices_to_edges(in_figure.get_vertices());

    for (const auto& it : edges)
    {
        point tmp_result_a;
        point tmp_result_b;
        get_normal_coordinates(it.first, it.second, tmp_result_a, tmp_result_b);

        save_to.push_back(std::make_pair(tmp_result_a, tmp_result_b));
    }
}

void sat_collision_detector_2d::project_figure_to_normal(
    figure& in_figure, const section& in_normal, points& result)
{
    for (const auto& it : in_figure.get_vertices())
    {
        result.push_back(point_projection_to_normal(in_normal, it));
    }
}

point sat_collision_detector_2d::point_projection_to_normal(
    const section in_normal, const point& pt_from)
{
    point pt_result;
    point pta = in_normal.first;
    point ptb = in_normal.second;
    float b1  = pt_from.x * (pta.x - ptb.x) + pt_from.y * (pta.y - ptb.y);
    float b2  = pta.x * ptb.y - pta.y * ptb.x;

    pt_result.y =
        (pta.x - ptb.x) * (pta.x - ptb.x) + (pta.y - ptb.y) * (pta.y - ptb.y);
    float det_k = b1 * (pta.x - ptb.x) - b2 * (pta.y - ptb.y);

    pt_result.x = det_k / pt_result.y;
    det_k       = (pta.x - ptb.x) * b2 + (pta.y - ptb.y) * b1;
    pt_result.y = det_k / pt_result.y;

    return pt_result;
}

void sat_collision_detector_2d::get_normal_coordinates(const point& pta,
                                                       const point& ptb,
                                                       point&       pt_rezult_a,
                                                       point&       pt_rezult_b)
{
    float dx = pta.y - ptb.y;
    float dy = ptb.x - pta.x;

    pt_rezult_a.x = pta.x;
    pt_rezult_a.y = pta.y;

    pt_rezult_b.x = pta.x + dx;
    pt_rezult_b.y = pta.y + dy;
}

sat_collision_detector_2d::min_max_x_value
sat_collision_detector_2d::build_min_max_projection(points& figure_projection)
{
    std::sort(figure_projection.begin(), figure_projection.end());

    float point_min = figure_projection[0].x;

    size_t last_element = figure_projection.size() - 1;
    float  point_max    = figure_projection[last_element].x;

    return std::make_pair(point_min, point_max);
}

bool sat_collision_detector_2d::check_collision_between_projections(
    const min_max_x_value& in_figuir_one, const min_max_x_value& in_figuir_two)
{
    return (in_figuir_one.second >= in_figuir_two.first) &&
           (in_figuir_one.first <= in_figuir_two.second);
}

bool sat_collision_detector_2d::check_coll(
    figure& in_figure_a, figure& in_figure_b,
    const fiugur_sections& normals_of_figure)
{
    for (const auto& normal : normals_of_figure)
    {
        figure_one_projection.clear();
        figure_two_projection.clear();

        project_figure_to_normal(in_figure_a, normal, figure_one_projection);
        project_figure_to_normal(in_figure_b, normal, figure_two_projection);

        auto figuir_one = build_min_max_projection(figure_one_projection);
        auto figuir_two = build_min_max_projection(figure_two_projection);

        bool collision =
            check_collision_between_projections(figuir_one, figuir_two);

        if (!collision)
            return false;
    }
    return true;
}

//====== debug functions =====

void sat_collision_detector_2d::print_normals_of_figure(
    const fiugur_sections& normals_of_figure)
{
    std::cout << " normals_of_figure: " << std::endl;

    for (const auto& it : normals_of_figure)
    {
        std::cout << " normal.first.x = " << it.first.x
                  << " normal.first.y = " << it.first.y << std::endl;
        std::cout << " normal.second.x = " << it.second.x
                  << " normal.second.y = " << it.second.y << std::endl;
        std::cout << " ================== " << std::endl;
    }
    std::cout << std::endl;
}

void sat_collision_detector_2d::print_projections(const points& in_projection)
{
    std::cout << " print_projections " << std::endl;

    for (const auto& it : in_projection)
    {
        {
            std::cout << " projection.x = " << it.x
                      << " projection.y = " << it.y << std::endl;
            std::cout << " ================== " << std::endl;
        }
    }
    std::cout << std::endl;
}
