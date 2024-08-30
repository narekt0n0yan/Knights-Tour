// KnightTour.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include <map>
#include <iostream>
#include <vector>


using step_vector = std::vector<std::pair<int, int>>;

void print_vector(std::vector<int> v)
{
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

void print_pair_vector(step_vector v) 
{
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << "[" << v[i].first << " " << v[i].second << "]" << ", ";
    }
    std::cout << std::endl;
}

bool is_equal(std::pair<int, int> f, std::pair<int, int> s)
{
    return ((f.first == s.first) && (f.second == s.second));
}

void print_map(std::map < std::pair<int, int>, step_vector> m) 
{
    for (std::pair<std::pair<int, int>, step_vector> elem : m) 
    {
        std::pair<int, int> temp = elem.first;
     
        std::cout << "[" << temp.first << ", " << temp.second << "]: ";
        print_pair_vector(elem.second);
        std::cout << "\n";

        
    }
}

int index(std::pair<int, int> value, const step_vector& vctsh)
{
     int index_value = 0;
     for (int i = 0; i < vctsh.size(); ++i)
     {
         if (is_equal(value, vctsh[i]))
         {
             return index_value;
         }
         else
         {
             ++index_value;
         }
     }
     return -1;
}


class ChessBoard
{
public:
    int m_n;
    step_vector m_R = { {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2} };
    std::map < std::pair<int, int>, step_vector> m_chessboard;
    step_vector m_path;


    ChessBoard(int n)
    {
        m_n = n;

        for (int x = 1; x <= m_n; ++x)
        {
            for (int y = 1; y <= m_n; ++y)
            {
                m_chessboard[std::make_pair(x, y)] = step_vector();
            }
        }
#if 1
        for (std::pair < std::pair<int, int>, step_vector> elem : m_chessboard)
        {
            std::pair<int, int> key_map = elem.first;
            step_vector& value_map = m_chessboard[elem.first];
            for (int i = 0; i < m_R.size(); ++i)
            {
                std::pair<int, int> new_dot = { key_map.first + m_R[i].first, key_map.second + m_R[i].second };
                if (!(m_chessboard.find(new_dot) == m_chessboard.end()))
                {
                    value_map.push_back(new_dot);

                }
            }
        }
    }
#endif

    step_vector horse_step(std::pair<int, int> start_dot)
    {
        std::pair<int, int> tried = { -1, -1 };
        std::pair< int, int> current = start_dot;
        m_path.push_back(current);
        int start = 0;
        while (m_chessboard.size() != m_path.size())
        {
            bool move_found = false;
            if (is_equal(tried, {-1, -1}))
            {
                start = 0;
            }
            else
            {
                start = index(tried, m_chessboard[current]) + 1;
            }

            for (int dot = start; dot < m_chessboard[current].size(); ++dot)
            {
                if ((index(m_chessboard[current][dot], m_path) == -1) && (!is_equal(m_chessboard[current][dot], tried)))
                {
                    tried = { -1, -1 };
                    m_path.push_back(m_chessboard[current][dot]);
                    current = m_chessboard[current][dot];
                    move_found = true;
                    break;
                }
            }
            if (!move_found)
            {
                tried = current;
                m_path.pop_back();
                current = m_path.back();
            }
        }
        return m_path;
    }
};

int main()
{
    ChessBoard board(5);
    print_pair_vector(board.horse_step({1, 1}));
   
}