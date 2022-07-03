#include <iostream>
#include <vector>
#include "histogram.h"

const auto image_width = 400;
const auto block_width = 15;

using namespace std;

struct Input {
    vector<double> numbers;
    size_t bin_count;
};

vector<double> input_numbers(istream& in, size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        in >> result[i];
    }
    return result;
}

Input
read_input(istream& in) {
    Input data;

    cerr << "Enter number count: ";
    size_t number_count;
    in >> number_count;

    cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);

    cerr << "Enter bin count ";
    in >> data.bin_count;

    return data;
}

vector<size_t> make_histogramm(const vector<double>& numbers, size_t bin_count){
    double min, max;
    find_minmax(numbers, min, max);
    vector<size_t> bins(bin_count,0);
    double bin_size = (max-min)/bin_count;
    for (size_t i=0;i<numbers.size();i++)
    {
        bool found = false;
        for (size_t j=0;j<(bin_count - 1) && !found;j++)
        {
            auto lo = min + j * bin_size;
            auto hi = min + (j+1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi)){
                bins[j]++;
                found = true;
            }
        }
        if (!found)
        {
            bins[bin_count - 1]++;
        }
    }
    return bins;
}

void show_histogramm_text(const vector<size_t>& bins){
    size_t SCREEN_WIDTH = 80;
    const size_t max_asterix = SCREEN_WIDTH - 3 - 1;

    size_t max_bin = bins[0];
    for (size_t bin: bins)
    {
        if (max_bin < bin)
        {
            max_bin = bin;
        }
    }

    for(size_t bin: bins)
    {
    size_t height = bin;

    //Проверка, нужно ли масштабировать столбцы
    if (max_bin > max_asterix)
    {
        height = max_asterix * (static_cast<double>(bin) / max_bin);
    }

    if (bin < 100)
    {
        cout << ' ';
    }
    if (bin < 10)
    {
        cout << ' ';
    }
    cout << bin << "|";
        for (size_t i = 0; i < height; i++)
        {
            cout << "*";
        }
    cout << endl;
    }
}


int main()
{
    //ввод
    //size_t number_count;
    //cerr << "Enter number count ";
    //cin >> number_count;

    //const auto numbers = input_numbers(cin , number_count);
    //size_t bin_count;
    //cerr << "Enter bin count ";
    //cin >> bin_count;

    const auto input = read_input(cin);
    //var 9
    //const size_t MAX_TRIES = 100;
    //size_t try_counter = 0;
    //bool passed_test = false;
    //size_t block_width;
    //cerr << "Enter block width: ";
    //do
    //{
    //    cin >> block_width;
    //    passed_test = input_check_block_width(block_width, numbers.size());

    //    if(!passed_test)
    //    {
    //        cerr << "Block width should be in range of 3 and 30";
    //    }
    //    try_counter++;
    //} while(!passed_test && try_counter < MAX_TRIES);

    //расчет гистограммы
    const auto bins = make_histogramm(input.numbers, input.bin_count);
    //вывод гистограммы
    show_histogramm_svg(bins, image_width);
    return 0;
}
