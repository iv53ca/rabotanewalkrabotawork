#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

double stringToDouble(const std::string& str) {
    try {
        return std::stod(str);
    } catch (const std::invalid_argument& ia) {
        throw std::runtime_error("Невозможно преобразовать строку в число: " + str);
    } catch (const std::out_of_range& oor) {
        throw std::runtime_error("Число вне диапазона: " + str);
    }
}


std::vector<std::vector<std::string>> parseCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: unable to open file '" << filename << "'\n";
        exit(1); // or throw an exception
    }

    std::vector<std::vector<std::string>> data;

    std::string line;
    int lineNumber = 0;
    while (std::getline(file, line))
    {
        ++lineNumber;
        std::vector<std::string> row;
        std::string cell;
        for (char c : line)
        {
            if (c == ',')
            {
                row.push_back(cell);
                cell.clear();
            }
            else
            {
                cell += c;
            }
        }
        row.push_back(cell);

        std::vector<std::string> subRow;
        for (const auto& elem : row) {
            if (elem.find_first_not_of(" \t") != std::string::npos) { // Проверка является ли элемент строкой
                std::istringstream iss(elem);
                std::string subCell;
                while (iss >> subCell) {
                    subRow.push_back(subCell);
                }
            } else {
                subRow.push_back(elem); // Если элемент пустой, то добавить его как есть
            }
        }

        data.push_back(subRow);
    }
    data.erase(data.begin(), data.begin() + 3);
    return data;
}

std::vector<std::vector<double>> raw_signal_information(const std::string& filename){
    std::vector<std::vector<std::string>> data = parseCSV(filename);
    int strings = data.size();
    int columns = data[0].size();
    std::vector<std::vector<double>> feedbackValues (columns ,std::vector<double>(strings));
    for(int i = 0; i < 41; i++){
        feedbackValues[0][i] = stringToDouble(data[i][0]);
        feedbackValues[1][i] = stringToDouble(data[i][1]);
        feedbackValues[2][i] = stringToDouble(data[i][2]);
    }
    return feedbackValues;
}

std::vector<std::vector<double>> back_information(const std::string& filename, const std::string& plottype){
    std::vector<std::vector<std::string>> data = parseCSV(filename);
    int number_of_plot = 2;
    int strings = data.size();
    int columns = data[0].size();
    int plots = columns / 4;

    std::string plot_name = plottype;

    std::vector<std::vector<double>> feedbackValues (2 ,std::vector<double>(41));

    if(plot_name == "АЧХ"){
        for(int i = 0; i < 41; i++){
//            std::cout << stringToDouble(data[i][(number_of_plot - 1) * 4 + 1]) << " ";
//            std::cout << data[i][(number_of_plot - 1) * 4 + 2] << " ";
//            std::cout << data[i][(number_of_plot - 1) * 4 + 3] << std::endl;
            feedbackValues[0][i] = stringToDouble(data[i][(number_of_plot - 1) * 4 + 1]);
            feedbackValues[1][i] = stringToDouble(data[i][(number_of_plot - 1) * 4 + 2]);
       }
    }

    if(plot_name == "ФЧХ"){
        for(int i = 0; i < 41; i++){
            feedbackValues[0][i] = stringToDouble(data[i][(number_of_plot - 1) * 4 + 1]);
            feedbackValues[1][i] = stringToDouble(data[i][(number_of_plot - 1) * 4 + 3]);
        }
    }
    return feedbackValues;
}