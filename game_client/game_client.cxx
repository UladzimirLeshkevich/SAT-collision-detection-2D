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
    fig_A.add_vertex(1, 2);
    fig_A.add_vertex(4, 3);
    fig_A.add_vertex(2, 4);

    figure fig_B;
    fig_B.add_vertex(8, 7);
    fig_B.add_vertex(5.61f, 7.18f);
    fig_B.add_vertex(4.39f, 6.12f);
    fig_B.add_vertex(4.76f, 4.8f);
    fig_B.add_vertex(6.67f, 4.98f);

    figure fig_B_b;
    fig_B_b.add_vertex(4.39f, 6.12f);
    fig_B_b.add_vertex(8, 7);
    fig_B_b.add_vertex(5.61f, 7.18f);
    fig_B_b.add_vertex(4.76f, 4.8f);
    fig_B_b.add_vertex(6.67f, 4.98f);

    figure fig_C;

    fig_C.add_vertex(5.79f, 5.28f);
    fig_C.add_vertex(3.4f, 5.47f);
    fig_C.add_vertex(2.17f, 4.4f);
    fig_C.add_vertex(2.55f, 3.08f);
    fig_C.add_vertex(4.45f, 3.26f);

    figure fig_D;

    fig_D.add_vertex(-1.06f, 5.28f);
    fig_D.add_vertex(-3.45f, 5.47f);
    fig_D.add_vertex(-4.67f, 4.4f);
    fig_D.add_vertex(-4.3f, 3.08f);
    fig_D.add_vertex(-2.39f, 3.26f);

    figure fig_E;

    fig_E.add_vertex(-1.06f, -1.83f);
    fig_E.add_vertex(-3.45f, -1.64f);
    fig_E.add_vertex(-4.67f, -2.71f);
    fig_E.add_vertex(-4.3f, -4.02f);
    fig_E.add_vertex(-2.39f, -3.85f);

    figure fig_F;

    fig_F.add_vertex(5.09f, -1.83f);
    fig_F.add_vertex(2.07f, -1.64f);
    fig_F.add_vertex(1.48f, -2.71f);
    fig_F.add_vertex(1.85f, -4.02f);
    fig_F.add_vertex(3.76f, -3.85f);

    figure fig_G;
    fig_G.add_vertex(3.2f, 2.1f);
    fig_G.add_vertex(-0.24f, 2.28f);
    fig_G.add_vertex(-2.f, 0.73f);
    fig_G.add_vertex(-1.46f, -1.16f);
    fig_G.add_vertex(1.28f, -0.91f);

    figure fig_J;
    fig_J.add_vertex(8.06f, 1.64f);
    fig_J.add_vertex(4.f, 3.f);
    fig_J.add_vertex(5.09f, -1.83f);
    fig_J.add_vertex(7.72f, -1.27f);

    figure fig_J_b;
    fig_J_b.add_vertex(5.09f, -1.83f);
    fig_J_b.add_vertex(8.06f, 1.64f);
    fig_J_b.add_vertex(4.f, 3.f);
    fig_J_b.add_vertex(7.72f, -1.27f);

    figure fig_H;
    fig_H.add_vertex(2.45f, -3.98f);
    fig_H.add_vertex(0.89f, -5.32f);
    fig_H.add_vertex(-4.16f, 3.73f);
    fig_H.add_vertex(-5.73f, 2.39f);

    figure fig_H_b;
    fig_H_b.add_vertex(-4.16f, 3.73f);
    fig_H_b.add_vertex(2.45f, -3.98f);
    fig_H_b.add_vertex(0.89f, -5.32f);
    fig_H_b.add_vertex(-5.73f, 2.39f);

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

    std::cout << "7. check collision between fig_A and fig_B_b :" << std::endl;
    print_check_result(coll_det.check_collision(fig_A, fig_B_b));

    std::cout << "8. check collision between fig_C and fig_B_b :" << std::endl;
    print_check_result(coll_det.check_collision(fig_C, fig_B_b));

    std::cout << "9. check collision between fig_A and fig_J :" << std::endl;
    print_check_result(coll_det.check_collision(fig_A, fig_J));

    std::cout << "10. check collision between fig_A and fig_J_b :" << std::endl;
    print_check_result(coll_det.check_collision(fig_A, fig_J_b));

    std::cout << "11. check collision between fig_J and fig_F :" << std::endl;
    print_check_result(coll_det.check_collision(fig_J, fig_F));

    std::cout << "12. check collision between fig_D and fig_H :" << std::endl;
    print_check_result(coll_det.check_collision(fig_D, fig_H));

    std::cout << "13. check collision between fig_H and fig_A :" << std::endl;
    print_check_result(coll_det.check_collision(fig_H, fig_A));

    std::cout << "14. check collision between fig_D and fig_H_b :" << std::endl;
    print_check_result(coll_det.check_collision(fig_D, fig_H_b));

    return EXIT_SUCCESS;
}
