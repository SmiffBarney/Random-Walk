#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

int main(int argc, char* argv[]) {

    // command line arguments from python frontend

    // get the number of walkers for the simulation
    int numWalkers;
    if (argc > 1) {
        numWalkers = stoi(argv[1]);
    } else {
        numWalkers = 10; // default number of walkers = 10
    }

    // number of steps
    int numSteps;
    if (argc > 2) {
        numSteps = stoi(argv[2]);
    } else {
        numSteps = 50; // default number of steps = 50
    }

    // random number generation
    // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution.html
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> step(-1, 1); // step -1, or 1

    // initialize walkers
    // vector storing each walker and their x,y coords initialized at (0, 0)
    vector<vector<int>> walkers(numWalkers, vector<int>(2, 0));

    ofstream out("randomwalk.csv"); // initialize the output file
    out << "step,exp_squared_disp"; // step and expected squared displacement columns

    // add columns for the walkers
    for (int w = 0; w < numWalkers; w++ ) { // for every walker
        out << ",walker" << w << "_x,walker" << w << "_y"; // ex: walker0_x, walker0_y. x and y columns for each walker
    }
    out << "\n";

    // loop to add position data to the CSV for all steps and for all walkers
    for (int s = 0; s <= numSteps; s++) {

        // compute the expected squared displacement at each step
        double sumSquaredDisplacement = 0.0; // accumulator for the summation
        for (const auto& walker:walkers) {
            double squaredDisplacement = 0.0; // squared displacement for an individual walker
            for (int d = 0; d < 2; d++) {
                squaredDisplacement += walker[d] * walker[d]; // square the x and y components from position vector
            }
            sumSquaredDisplacement += squaredDisplacement; // add to the sum of the squared displacement
        }
        double expectedSquaredDisplacement = sumSquaredDisplacement / numWalkers; // expected displacement is the ensemble average

        // write the row to CSV
        out << s << "," << expectedSquaredDisplacement; // step, expected displacement
        for (const auto& walker:walkers) {
            out << "," << walker[0] << "," << walker[1]; // x and y coordinates
        }
        out << "\n";

        // update the walker's position
        if (s < numSteps) { // do not step if user-defined number of steps is reached
            for (auto& walker : walkers) { // loop through each walker
                for (int d = 0; d < 2; d++) { // update both x and y
                    walker[d] += step(gen); // random (-1 or 1) step for x and y
                }
            }
        }
    }

    return 0;
}