#include <vector>
#include <iostream>
using namespace std;

enum S
{
    A = 0,
    _2 = 1,
    _3 = 2,
    _4 = 3,
    _5 = 4,
    _6 = 5,
    _7 = 6,
    _8 = 7,
    _9 = 8,
    _10 = 9,
    _11 = 10,
    _12 = 11,
    _13 = 12,
    _14 = 13,
    _15 = 14,
    _16 = 15,
    _17 = 16,
    S12 = 17,
    S13 = 18,
    S14 = 19,
    S15 = 20,
    S16 = 21,
    _18 = 22,
    _19 = 23,
    _20 = 24,
    S17 = 25,
    S18 = 26,
    S19 = 27,
    S20 = 28,
    _21 = 29,
    B = 30
};

int main(int argc, char const *argv[])
{

    double p = 0.4;
    double q = (1 - p) / 9;
    vector<vector<int>> card_transitions{{S12, S13, S14, S15, S16, S17, S18, S19, S20, _21}, {S13, _4, _5, _6, _7, _8, _9, _10, _11, _12}, {S14, _5, _6, _7, _8, _9, _10, _11, _12, _13}, {S15, _6, _7, _8, _9, _10, _11, _12, _13, _14}, {S16, _7, _8, _9, _10, _11, _12, _13, _14, _15}, {S17, _8, _9, _10, _11, _12, _13, _14, _15, _16}, {S18, _9, _10, _11, _12, _13, _14, _15, _16, _17}, {S19, _10, _11, _12, _13, _14, _15, _16, _17, _18}, {S20, _11, _12, _13, _14, _15, _16, _17, _18, _19}, {_21, _12, _13, _14, _15, _16, _17, _18, _19, _20}, {_12, _13, _14, _15, _16, _17, _18, _19, _20, _21}, {_13, _14, _15, _16, _17, _18, _19, _20, _21, B}, {_14, _15, _16, _17, _18, _19, _20, _21, B, B}, {_15, _16, _17, _18, _19, _20, _21, B, B, B}, {_16, _17, _18, _19, _20, _21, B, B, B, B}, {_17, _18, _19, _20, _21, B, B, B, B, B}, {_18, _19, _20, _21, B, B, B, B, B, B}, {S13, S14, S15, S16, S17, S18, S19, S20, _21, _12}, {S14, S15, S16, S17, S18, S19, S20, _21, _12, _13}, {S15, S16, S17, S18, S19, S20, _21, _12, _13, _14}, {S16, S17, S18, S19, S20, _21, _12, _13, _14, _15}, {S17, S18, S19, S20, _21, _12, _13, _14, _15, _16}};

    vector<std::vector<double>> transition_probabilities(22, vector<double>(9));
    vector<std::vector<double>> new_transition_probabilities(22, vector<double>(9));

    double max_error;
    do
    {
        max_error = 0;

        for (int i = 0; i < transition_probabilities.size(); i++)
        {
            for (int j = 0; j < transition_probabilities[0].size(); j++)
            {
                double temp = 0;
                for (int k = 0; k < 10; k++)
                {
                    int new_score = card_transitions[i][k];
                    if (new_score > S16 && new_score - S16 - 1 == j)
                    {
                        if (k < 9)
                        {
                            temp += q;
                        }
                        else
                        {
                            temp += p;
                        }
                    }
                    else if (new_score <= S16)
                    {
                        if (k < 9)
                        {
                            temp += q * transition_probabilities[new_score][j];
                        }
                        else
                        {
                            temp += p * transition_probabilities[new_score][j];
                        }
                    }
                }
                new_transition_probabilities[i][j] = temp;
                max_error = max(max_error, abs(new_transition_probabilities[i][j] - transition_probabilities[i][j]));
            }
        }
        transition_probabilities = new_transition_probabilities;
    } while (max_error > 0.0001);

    return 0;
}
