/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 11/14/2017
LAB: 09
FILE NAME: VIDEOGAME.CPP
FILE CONTENTS: IMPLEMENTATION FILE FOR VIDEOGAME.H
*/

#include "VideoGame.h"

VideoGame::VideoGame() {
    m_name = "";
    m_platform = "";
    m_year = "";
    m_genre = "";
    m_publisher = "";
    m_na_sales = "";
    m_eu_sales = "";
    m_jp_sales = "";
    m_other_sales = "";
    m_global_sales = "";
    m_total_sales = "";
    m_rank = "";
}

VideoGame::VideoGame(std::string t_name, std::string t_platform, std::string t_year,
                std::string t_genre, std::string t_publisher, std::string t_na_sales,
                std::string t_eu_sales, std::string t_jp_sales, std::string t_other_sales,
                std::string t_global_sales, std::string t_total_sales, std::string t_rank) 
{
    m_name = t_name;
    m_platform = t_platform;
    m_year = t_year;
    m_genre = t_genre;
    m_publisher = t_publisher;
    m_na_sales = t_na_sales;
    m_eu_sales = t_eu_sales;
    m_jp_sales = t_jp_sales;
    m_other_sales = t_other_sales;
    m_global_sales = t_global_sales;
    m_total_sales = t_total_sales;
    m_rank = t_rank;
}

VideoGame::~VideoGame() {
    
}