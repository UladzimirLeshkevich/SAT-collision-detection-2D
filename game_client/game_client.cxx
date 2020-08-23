#include "../collision_detector/collision_detector.hxx"
#include "../figure/figure.hxx"

#include <iostream>

void print_check_result(const int result)
{
    switch (result)
    {
        case -1:
            std::cout
                << "  !! can't check collision, invalid figure geometry !!"
                << std::endl;
            break;
        case 0:
            std::cout << "  !! there is NO collision !! " << std::endl;
            break;
        case 1:
            std::cout << "  !! there is collision !! " << std::endl;
            break;
    }
    std::cout << " ========================= " << std::endl;
}

int main(int /*argc*/, char* /*argv*/[])
{
    figure fig_0;
    fig_0.add_vertex(1, 2);
    fig_0.add_vertex(4, 3);

    figure fig_A;
    fig_A.read_geometry_from_file("./coordinates_files/fig_A.txt");

    figure fig_B;
    fig_B.read_geometry_from_file("./coordinates_files/fig_B.txt");

    figure fig_C;
    fig_C.read_geometry_from_file("./coordinates_files/fig_C.txt");

    figure fig_D;
    fig_D.read_geometry_from_file("./coordinates_files/fig_D.txt");

    figure fig_E;
    fig_E.read_geometry_from_file("./coordinates_files/fig_E.txt");

    figure fig_F;
    fig_F.read_geometry_from_file("./coordinates_files/fig_F.txt");

    figure fig_G;
    fig_G.read_geometry_from_file("./coordinates_files/fig_G.txt");

    figure fig_J;
    fig_J.read_geometry_from_file("./coordinates_files/fig_J.txt");

    figure fig_H;
    fig_H.read_geometry_from_file("./coordinates_files/fig_H.txt");

    sat_collision_detector_2d coll_det;

    // some test cases
    std::cout << "1. check collision between fig_A and fig_B :" << std::endl;
    print_check_result(coll_det.check_collision(fig_A, fig_B));

    std::cout << "2. check collision between fig_0 and fig_A :" << std::endl;
    print_check_result(coll_det.check_collision(fig_0, fig_A));

    std::cout << "3. check collision between fig_G and fig_A :" << std::endl;
    print_check_result(coll_det.check_collision(fig_G, fig_A));

    std::cout << "4. check collision between fig_A and fig_G :" << std::endl;
    print_check_result(coll_det.check_collision(fig_A, fig_G));

    std::cout << "5. check collision between fig_C and fig_B :" << std::endl;
    print_check_result(coll_det.check_collision(fig_C, fig_B));

    std::cout << "6. check collision between fig_C and fig_A :" << std::endl;
    print_check_result(coll_det.check_collision(fig_C, fig_A));

    std::cout << "7. check collision between fig_A and fig_J :" << std::endl;
    print_check_result(coll_det.check_collision(fig_A, fig_J));

    std::cout << "8. check collision between fig_J and fig_F :" << std::endl;
    print_check_result(coll_det.check_collision(fig_J, fig_F));

    std::cout << "9. check collision between fig_D and fig_H :" << std::endl;
    print_check_result(coll_det.check_collision(fig_D, fig_H));

    std::cout << "10. check collision between fig_H and fig_A :" << std::endl;
    print_check_result(coll_det.check_collision(fig_H, fig_A));

    return EXIT_SUCCESS;
}
