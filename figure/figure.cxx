#include "figure.hxx"

void figure::add_vertex(const float x, const float y)
{
    vertices.emplace_back(x, y);
}

bool figure::read_geometry_from_file(const std::string& in_file)
{
    std::string tmp_string_from_file;

    std::ifstream input_file(in_file);
    if (!input_file)
    {
        std::cerr << "\nfrom read_file():\ncan't open file " << in_file << "\n";
        return EXIT_FAILURE;
    }

    while (getline(input_file, tmp_string_from_file))
    {
        parsing_and_save_coordinates(tmp_string_from_file);
    }

    input_file.close();

    return EXIT_SUCCESS;
}

void figure::print_vertices() const
{
    std::cout << " vertices of figure: " << std::endl;
    size_t i = 0;
    for (const auto& it : vertices)
    {
        std::cout << " vertex[" << i << "].x = " << it.x << " vertex[" << i
                  << "].y = " << it.y << std::endl;
        ++i;
    }
    std::cout << std::endl;
}

void figure::parsing_and_save_coordinates(const std::string& str)
{
    std::string tmp_x;
    std::string tmp_y;

    std::stringstream stream(str);

    stream >> tmp_x >> tmp_y;

    this->add_vertex(std::stof(tmp_x), std::stof(tmp_y));
}
