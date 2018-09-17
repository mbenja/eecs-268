/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 11/14/2017
LAB: 09
FILE NAME: VIDEOGAME.H
FILE CONTENTS: HEADER FILE FOR VIDEOGAME.H
*/

#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <string>

class VideoGame {
    public:
    // @ pre-condition:
    // @ post-condition:
    // @ throw:
    VideoGame();

    // @ pre-condition: expects parameters for each of the member variables as string
    // @ post-condition: new instance of VideoGame has been created with given values
    // @ throw: none
    VideoGame(std::string t_name, std::string t_platform, std::string t_year,
            std::string t_genre, std::string t_publisher, std::string t_na_sales,
            std::string t_eu_sales, std::string t_jp_sales, std::string t_other_sales,
            std::string t_global_sales, std::string t_total_sales, std::string t_rank);

    // @ pre-condition: none
    // @ post-condition: all memory allocated to instance of videogame class has been deallocated
    // @ throw: none
    ~VideoGame();

    private:
    std::string m_name;
    std::string m_platform;
    std::string m_year;
    std::string m_genre;
    std::string m_publisher;
    std::string m_na_sales;
    std::string m_eu_sales;
    std::string m_jp_sales;
    std::string m_other_sales;
    std::string m_global_sales;
    std::string m_total_sales;
    std::string m_rank;
};
#endif